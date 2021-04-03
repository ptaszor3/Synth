#include "basic.hpp"

namespace envelopes {
        namespace basic {
                double NoEnvelope::callback(Note note, double_seconds duration_from_start) {
                        return 1;
                }
        }
}
