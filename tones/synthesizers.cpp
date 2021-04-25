#include "synthesizers.hpp"

#include <cmath>

namespace tones {
	namespace synthesizers {
                Sample Additive::callback(Note note, DoubleSeconds duration_from_start) {
                        double result{sin(note.frequency * 2 * 3.14159265358979323846 * duration_from_start.count())};
                        for(int i = 0; i < harmonics.size(); i++)
                                result += sin(harmonics[i].first * note.frequency * 2 * 3.14159265358979323846 * duration_from_start.count()) * harmonics[i].second;
                        
                        return result / max_volume;
                }
                void Additive::set_harmonic(double harmonic, double volume) {
                        max_volume = 1 + volume;
                        for(auto x : harmonics)
                                max_volume += x.second;
                        bool was_the_harmonic_already{false};
                        for(auto& x : harmonics) {
                                if(x.first == harmonic) {
                                        x.second = volume;
                                        was_the_harmonic_already = true;
                                        break;
                                }
                        }
                        if(!was_the_harmonic_already)
                                harmonics.push_back(std::pair<double, double>(harmonic, volume));
                }
                void Additive::clear_harmonics() {
                        harmonics.clear();
                }
        }
}

