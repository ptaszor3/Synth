#include "../../include/inputs/MIDIInput.hpp"
#include "../../include/StandardNotes.hpp"

#include <functional>

namespace inputs {
	MIDIInput::MIDIInput(Instrument* c_instrument) 
	:instrument{c_instrument}, subscription_handle{nullptr} {
		for(int i = 0; i < 128; i++)
			note_ids[i] = 0;

		if(snd_seq_open(&seq_handle, "hw", SND_SEQ_OPEN_DUPLEX, 0) < 0)
			exit(1);
		snd_seq_set_client_name(seq_handle, "Synthall");
		if(snd_seq_create_simple_port(seq_handle, "Synthall", SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE, SND_SEQ_PORT_TYPE_APPLICATION) < 0) 
			exit(1);

		npfd = snd_seq_poll_descriptors_count(seq_handle, POLLIN);
		pfd = (struct pollfd*)alloca(npfd * sizeof(struct pollfd));
		snd_seq_poll_descriptors(seq_handle, pfd, npfd, POLLIN);

		destination.port = 0;
		destination.client = snd_seq_client_id(seq_handle);

		updating_thread = new std::thread(update_midi, std::ref(*this));
	}

	MIDIInput::~MIDIInput() {
		snd_seq_close(seq_handle);
		disconnect();
		delete updating_thread;
	}

	void MIDIInput::update() {
		do {
			snd_seq_event_input(seq_handle, &event);
			switch(event->type) {
				case SND_SEQ_EVENT_PITCHBEND:
				break;
				case SND_SEQ_EVENT_NOTEON:
					note_ids[event->data.note.note] = instrument->play(Note(standard_notes::midi_notation[event->data.note.note], instrument->timer->get_duration_from_start(), 0_ds, event->data.note.velocity / static_cast<double>(std::numeric_limits<unsigned char>::max())));
				break;
				case SND_SEQ_EVENT_NOTEOFF:
					instrument->stop(note_ids[event->data.note.note]);
				break;
			}
		} while(snd_seq_event_input_pending(seq_handle, 0) > 0);
	}

	void MIDIInput::update_midi(MIDIInput& that) {
		while(true)
			if(that.can_run)
				that.MIDIInput::update();
	}

	void MIDIInput::connect(int source_id) {
		disconnect();
		
		snd_seq_addr_t sender;
		sender.client = source_id;
		sender.port = 0;

		snd_seq_port_subscribe_malloc(&subscription_handle);
		snd_seq_port_subscribe_set_sender(subscription_handle, &sender);
		snd_seq_port_subscribe_set_dest(subscription_handle, &destination);
		snd_seq_port_subscribe_set_queue(subscription_handle, 1);
		snd_seq_port_subscribe_set_time_update(subscription_handle, 1);
		snd_seq_port_subscribe_set_time_real(subscription_handle, 1);
		if(snd_seq_subscribe_port(seq_handle, subscription_handle) < 0)
			throw ErrorWhileConnecting_exception();

		do {
			snd_seq_event_input(seq_handle, &event);
		} while(snd_seq_event_input_pending(seq_handle, 0) > 0);
		
		can_run = true;
	}

	void MIDIInput::disconnect() {
		can_run = false;

		if(subscription_handle) {
			snd_seq_unsubscribe_port(seq_handle, subscription_handle);
			snd_seq_port_subscribe_free(subscription_handle);
			subscription_handle = nullptr;
		}

	}

	std::map<std::string, int> MIDIInput::get_all_inputs() {
		snd_seq_client_info_t* client_info;
		
		snd_seq_client_info_alloca(&client_info);
		snd_seq_client_info_set_client(client_info, -1);

		snd_seq_t* sequencer_handle;
		if (snd_seq_open(&sequencer_handle, "default", SND_SEQ_OPEN_DUPLEX, 0) < 0) {
			throw CantOpenSequencer_exception();
		}
		
		std::map<std::string, int> result_buffer;

		while(snd_seq_query_next_client(sequencer_handle, client_info) >= 0)
			result_buffer.insert({snd_seq_client_info_get_name(client_info), snd_seq_client_info_get_client(client_info)});

		snd_seq_close(sequencer_handle);

		return result_buffer;
	}
}
