#include "../../include/inputs/MIDIInput.hpp"
#include "../../include/StandardNotes.hpp"

namespace inputs {
	MIDIInput::MIDIInput(Instrument* c_instrument) 
	:instrument{c_instrument} {
		for(int i = 0; i < 128; i++)
			note_ids[i] = 0;

		if(snd_seq_open(&seq_handle, "hw", SND_SEQ_OPEN_DUPLEX, 0) < 0)
			exit(1);
		snd_seq_set_client_name(seq_handle, "Synth");
		if((snd_seq_create_simple_port(seq_handle, "Synth", SND_SEQ_PORT_CAP_WRITE | SND_SEQ_PORT_CAP_SUBS_WRITE, SND_SEQ_PORT_TYPE_APPLICATION)) < 0) 
			exit(1);

		npfd = snd_seq_poll_descriptors_count(seq_handle, POLLIN);
		pfd = (struct pollfd*)alloca(npfd * sizeof(struct pollfd));
		snd_seq_poll_descriptors(seq_handle, pfd, npfd, POLLIN);
	}

	MIDIInput::~MIDIInput() {
		snd_seq_close(seq_handle);
	}

	void MIDIInput::update() {
		if(poll(pfd, npfd, 100) > 0) {
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
				snd_seq_free_event(event);
			} while(snd_seq_event_input_pending(seq_handle, 0) > 0);
		}
	}
}
