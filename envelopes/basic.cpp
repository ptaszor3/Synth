#include "basic.hpp"

namespace envelopes {
        namespace basic {
                Sample NoEnvelope::callback(Note note, DoubleSeconds duration_from_start) {
                        return 1;
                }
        }
}
