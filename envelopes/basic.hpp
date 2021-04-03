#pragma once

#include "../Envelope.hpp"

namespace envelopes {
        namespace basic {
                class NoEnvelope :public Envelope {
                public:
                        double callback(Note note, double_seconds duration_from_start);
                };
        }
}
