#pragma once

#include "basic.hpp"

namespace envelopes {
        namespace basic {
                double NoEnvelope::callback(Note note, double actual_time) {
                        return 1;
                }
        }
}
