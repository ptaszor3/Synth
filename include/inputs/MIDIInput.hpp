#pragma once
#include "../Instrument.hpp"

#include <alsa/asoundlib.h>
#include <map>
#include <string>
#include <exception>
#include <thread>

namespace inputs {
	class MIDIInput {
	private:
		Instrument::NoteId note_ids[128];

		snd_seq_event_t* event;
		int npfd;
		struct pollfd* pfd;
		snd_seq_t* seq_handle;
		snd_seq_port_subscribe_t* subscription_handle;
		snd_seq_addr_t destination;

		std::thread* updating_thread;
		bool can_run{false};

		static void update_midi(MIDIInput&);
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

		class ErrorWhileConnecting_exception :public std::exception {
		public:
			const char* what() const noexcept {return "Couldn't subscribe input with output";}
		};
	};
}
