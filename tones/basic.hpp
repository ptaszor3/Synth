#pragma once

#include "../Tone.hpp"
#include "../Note.hpp"

namespace tones {
        namespace basic {
                class Sin :public Tone {
                        
                public:
                        double callback(Note note, double actual_time);
                };
                class Tri :public Tone {

                public:
                        double callback(Note note, double actual_time);
                };
                class Saw :public Tone {

                public:
                        double callback(Note note, double actual_time);
                };
                class Sqr :public Tone {

                public:
                        double callback(Note note, double actual_time);
                };
                class Silence :public Tone {

                public:
                        double callback(Note note, double actual_time);
                };
		class Rect :public Tone {

                public:
                        double infill{0.5};
                        double callback(Note note, double actual_time);
                };
        }
}
