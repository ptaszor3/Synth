#pragma once

#include "../Tone.hpp"
#include "../Note.hpp"

#include <vector>

namespace tones {
	namespace synthesizers {
                class Additive :public Tone {
                        double max_volume{1};
                        std::vector<std::pair<double, double>> harmonics;
                public:
                        double callback(Note note, double_seconds duration_from_start);
                        void setHarmonic(double harmonic, double volume);
                        //void addToHarmonic(double harmonic, double volume);
                        void clearHarmonics();
                };
        }
}

