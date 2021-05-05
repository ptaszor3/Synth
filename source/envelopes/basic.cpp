#include "../../include/envelopes/basic.hpp"

namespace envelopes {
        namespace basic {
                Sample NoEnvelope::callback(Note note, DoubleSeconds duration_from_start) {
                        return 1;
                }
		DoubleSeconds get_time_note_is_done(Note note) {
			if(note.end_time == 0_ds)
				throw Envelope::NoteDoesntEnd_exception();
			return note.end_time;
		}
        }
}
