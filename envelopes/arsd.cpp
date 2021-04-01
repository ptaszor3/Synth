#include "arsd.hpp"

namespace envelopes {
	namespace arsd {
                double Linear::callback(Note note, double actual_time) {
                        if(!note.end_time and note.end_time < actual_time) {
                                double time_from_begin = actual_time - note.begin_time;
                                
                                if(time_from_begin < arsd.attack)
                                        return 1 / arsd.attack * time_from_begin;
                                else if(time_from_begin - arsd.attack < arsd.release)
                                        return (arsd.attack - time_from_begin) * (1 - arsd.sustain) / arsd.release + 1;
                                else 
                                        return arsd.sustain;
                        }
                        else {
                                double time_from_end = actual_time - note.end_time;

                                if(time_from_end < arsd.decay)
                                        return arsd.sustain - arsd.sustain / arsd.decay * time_from_end;
                                else
                                        return 0.0;
                        }
                }
                double Quadratic::callback(Note note, double actual_time) {
                        if(!note.end_time and note.end_time < actual_time) {
                                double time_from_begin = actual_time - note.begin_time;
                        
                                if(time_from_begin < arsd.attack)
                                        return time_from_begin * time_from_begin / arsd.attack / arsd.attack;
                                else if(time_from_begin - arsd.attack < arsd.release)
                                        return ((1 - (time_from_begin - arsd.attack) / arsd.release) * (1 - (time_from_begin - arsd.attack) / arsd.release)) * (1 - arsd.sustain) + arsd.sustain;
                                else
                                        return arsd.sustain;
                        }
                        else {
                                double time_from_end = actual_time - note.end_time;
        
                                if(time_from_end < arsd.decay)
					return (1 - time_from_end / arsd.decay) * (1 - time_from_end / arsd.decay) * arsd.sustain;
                                else 
                                        return 0;
                        }
                }
        }
}

