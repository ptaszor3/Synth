#include "arsd.hpp"

namespace envelopes {
	namespace arsd {
                double Linear::callback(Note note, double_seconds duration_from_start) {
			if(note.begin_time > duration_from_start) {
				return 0.0;
			}
                        else if(note.end_time > duration_from_start) {
                                double_seconds time_from_begin = duration_from_start - note.begin_time;
                                
                                if(time_from_begin < arsd.attack)
                                        return 1 / arsd.attack.count() * time_from_begin.count();
                                else if(time_from_begin - arsd.attack < arsd.release)
                                        return (arsd.attack - time_from_begin).count() * (1 - arsd.sustain) / (arsd.release).count() + 1;
                                else 
                                        return arsd.sustain;
                        }
                        else {
                                double_seconds time_from_end = duration_from_start - note.end_time;

                                if(time_from_end < arsd.decay)
                                        return arsd.sustain - arsd.sustain / arsd.decay.count() * time_from_end.count();
                                else
                                        return 0.0;
                        }
                }
                double Quadratic::callback(Note note, double_seconds duration_from_start) {
			if(note.begin_time > duration_from_start)
				return 0.0;
                        else if(note.end_time > duration_from_start) {
                                double_seconds time_from_begin = duration_from_start - note.begin_time;
                        
                                if(time_from_begin < arsd.attack)
                                        return time_from_begin.count() * time_from_begin.count() / arsd.attack.count() / arsd.attack.count();
                                else if(time_from_begin - arsd.attack < arsd.release)
                                        return ((1.0 - (time_from_begin - arsd.attack).count() / arsd.release.count()) * (1.0 - (time_from_begin - arsd.attack).count() / arsd.release.count())) * (1.0 - arsd.sustain) + arsd.sustain;
                                else
                                        return arsd.sustain;
                        }
                        else {
                                double_seconds time_from_end = duration_from_start - note.end_time;
        
                                if(time_from_end < arsd.decay)
					return ((double_seconds(1.0).count() - time_from_end.count() / arsd.decay.count()) * (1.0 - time_from_end.count() / arsd.decay.count())) * arsd.sustain;
                                else 
                                        return 0;
                        }
                }
        }
}

