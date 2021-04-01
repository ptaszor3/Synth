#pragma once

#include "../Envelope.hpp"

namespace envelopes {

	namespace arsd {
		struct Arsd {
			double attack{0.05};
			double release{0.1};
			double sustain{0.5};
			double decay{0.1};
		};

                class Linear :public Envelope {
                public:
			Arsd arsd;
                        double callback(Note note, double actual_time);
                };
                class Quadratic :public Envelope {
                public:
			Arsd arsd;
                        double callback(Note note, double actual_time);
                };
        }
}

