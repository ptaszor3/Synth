#pragma once

#include "../Tone.hpp"
#include "../Note.hpp"

namespace tones {
        namespace basic {
                class Sin :public Tone {
                public:
                        double callback(Note note, DoubleSeconds duration_from_start);
                };
                class Tri :public Tone {
                public:
                        double callback(Note note, DoubleSeconds duration_from_start);
                };
                class Saw :public Tone {
                public:
                        double callback(Note note, DoubleSeconds duration_from_start);
                };
                class Sqr :public Tone {
                public:
                        double callback(Note note, DoubleSeconds duration_from_start);
                };
                class Silence :public Tone {
                public:
                        double callback(Note note, DoubleSeconds duration_from_start);
                };
		class Rect :public Tone {
                public:
                        double infill{0.5};
                        double callback(Note note, DoubleSeconds duration_from_start);
                };
        }
}
