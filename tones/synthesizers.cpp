#include "synthesizers.hpp"

#include <cmath>

namespace tones {
	namespace synthesizers {
                double Additive::callback(Note note, double actual_time) {
                        double result{sin(note.frequency * 2 * 3.14159265358979323846 * actual_time)};
                        for(int i = 0; i < harmonics.size(); i++)
                                result += sin(harmonics[i].first * note.frequency * 2 * 3.14159265358979323846 * actual_time) * harmonics[i].second;
                        
                        return result / max_volume;
                }
                void Additive::setHarmonic(double harmonic, double volume) {
                        max_volume = 1 + volume;
                        for(auto x : harmonics)
                                max_volume += x.second;
                        bool wasTheHarmonicAlready{false};
                        for(auto& x : harmonics) {
                                if(x.first == harmonic) {
                                        x.second = volume;
                                        wasTheHarmonicAlready = true;
                                        break;
                                }
                        }
                        if(!wasTheHarmonicAlready)
                                harmonics.push_back(std::pair<double, double>(harmonic, volume));
                }
                void Additive::clearHarmonics() {
                        harmonics.clear();
                }
        }
}

