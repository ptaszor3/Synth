#include "basic.hpp"

#include <cmath>

namespace tones {
        namespace basic {
                double Sin::callback(Note note, double_seconds duration_from_start) {
                        return sin(duration_from_start.count() * note.frequency * 2.0 * 3.14159265358979323846);
                }
                double Tri::callback(Note note, double_seconds duration_from_start) {
                        double time_from_beggining_of_cycle = fmod(duration_from_start.count(), 1.0 / note.frequency);
                        if(time_from_beggining_of_cycle < (1.0 / note.frequency / 2.0))
                                return 4.0 * note.frequency * time_from_beggining_of_cycle - 1.0;
                        else
                                return -4.0 * note.frequency * (time_from_beggining_of_cycle - 1 / (2 * note.frequency)) + 1.0;
                }
                double Saw::callback(Note note, double_seconds duration_from_start) {
                        double time_from_beggining_of_cycle = fmod(duration_from_start.count(), 1.0 / note.frequency);
                        return 2.0 * note.frequency * time_from_beggining_of_cycle - 1.0;
                }
                double Sqr::callback(Note note, double_seconds duration_from_start) {
                        double time_from_beggining_of_cycle = fmod(duration_from_start.count(), 1.0 / note.frequency);
                        if(time_from_beggining_of_cycle < 1.0 / note.frequency / 2.0)
                                return 1.0;
                        else 
                                return -1.0;
                }
                double Silence::callback(Note note, double_seconds duration_from_start) {
                        return 0;
                }
                double Rect::callback(Note note, double_seconds duration_from_start) {
                        double time_from_beggining_of_cycle = fmod(duration_from_start.count(), 1.0 / note.frequency);
                        if(time_from_beggining_of_cycle < 1.0 / note.frequency * infill)
                                return 1.0;
                        else
                                return -1.0;
                }
        }
}
