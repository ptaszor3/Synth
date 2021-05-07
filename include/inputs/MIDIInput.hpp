#pragma once
#include "../Instrument.hpp"

#include <alsa/asoundlib.h>

namespace inputs {
	class MIDIInput {
	private:
		int npfd;
		struct pollfd* pfd;
		snd_seq_event_t* event;
		Instrument::NoteId note_ids[128];
	public:
		Instrument* instrument;
		Timer* timer;
		snd_seq_t* seq_handle;

		MIDIInput(Instrument* c_instrument = nullptr);
		~MIDIInput();
		void update();
	};
}
