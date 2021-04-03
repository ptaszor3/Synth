#pragma once

#include "../Envelope.hpp"

namespace envelopes {

	namespace arsd {
		struct Arsd {
			double_seconds attack{double_seconds(0.05)};
			double_seconds release{double_seconds(0.1)};
			double sustain{0.5};
			double_seconds decay{0.1};
		};

                class Linear :public Envelope {
                public:
			Arsd arsd;
                        double callback(Note note, double_seconds duration_from_start);
                };
                class Quadratic :public Envelope {
                public:
			Arsd arsd;
                        double callback(Note note, double_seconds duration_from_start);
                };
        }
}

