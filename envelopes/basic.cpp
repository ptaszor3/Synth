#include "basic.hpp"

namespace envelopes {
        namespace basic {
                double NoEnvelope::callback(Note note, DoubleSeconds duration_from_start) {
                        return 1;
                }
        }
}
