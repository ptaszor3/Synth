#pragma once
#include "../Instrument.hpp"

#include <alsa/asoundlib.h>
#include <map>
#include <string>
#include <exception>

namespace inputs {
	class MIDIInput {
	private:
		int npfd;
		struct pollfd* pfd;
		snd_seq_event_t* event;
		Instrument::NoteId note_ids[128];
		snd_seq_t* seq_handle;
		snd_seq_port_subscribe_t* subscription_handle;
		snd_seq_addr_t destination;
	public:
		Instrument* instrument;
		Timer* timer;

		MIDIInput(Instrument* c_instrument = nullptr);
		~MIDIInput();

		void update();
		void connect(int source_id);
		void disconnect();

		static std::map<std::string, int> get_all_inputs();

		class CantOpenSequencer_exception :public std::exception {
		public:
			const char* what() const noexcept {return "ALSA Couldn't open sequencer";}
		};
	};
}
