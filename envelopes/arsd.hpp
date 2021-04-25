#pragma once

#include "../Envelope.hpp"

namespace envelopes {

	namespace arsd {
		struct Arsd {
			DoubleSeconds attack{DoubleSeconds(0.05)};
			DoubleSeconds release{DoubleSeconds(0.1)};
			double sustain{0.5};
			DoubleSeconds decay{0.1};
		};

                class Linear :public Envelope {
                public:
			Arsd arsd;
                        Sample callback(Note note, DoubleSeconds duration_from_start);
                };
                class Quadratic :public Envelope {
                public:
			Arsd arsd;
                        Sample callback(Note note, DoubleSeconds duration_from_start);
                };
        }
}

