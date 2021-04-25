#include "basic.hpp"

#include <cmath>

namespace tones {
        namespace basic {
                Sample Sin::callback(Note note, DoubleSeconds duration_from_start) {
                        return sin(duration_from_start.count() * note.frequency * 2.0 * 3.14159265358979323846);
                }
                Sample Tri::callback(Note note, DoubleSeconds duration_from_start) {
                        double time_from_beggining_of_cycle = fmod(duration_from_start.count(), 1.0 / note.frequency);
                        if(time_from_beggining_of_cycle < (1.0 / note.frequency / 2.0))
                                return 4.0 * note.frequency * time_from_beggining_of_cycle - 1.0;
                        else
                                return -4.0 * note.frequency * (time_from_beggining_of_cycle - 1 / (2 * note.frequency)) + 1.0;
                }
                Sample Saw::callback(Note note, DoubleSeconds duration_from_start) {
                        double time_from_beggining_of_cycle = fmod(duration_from_start.count(), 1.0 / note.frequency);
                        return 2.0 * note.frequency * time_from_beggining_of_cycle - 1.0;
                }
                Sample Sqr::callback(Note note, DoubleSeconds duration_from_start) {
                        double time_from_beggining_of_cycle = fmod(duration_from_start.count(), 1.0 / note.frequency);
                        if(time_from_beggining_of_cycle < 1.0 / note.frequency / 2.0)
                                return 1.0;
                        else 
                                return -1.0;
                }
                Sample Silence::callback(Note note, DoubleSeconds duration_from_start) {
                        return 0;
                }
                Sample Rect::callback(Note note, DoubleSeconds duration_from_start) {
                        double time_from_beggining_of_cycle = fmod(duration_from_start.count(), 1.0 / note.frequency);
                        if(time_from_beggining_of_cycle < 1.0 / note.frequency * infill)
                                return 1.0;
                        else
                                return -1.0;
                }
        }
}
