#include "Vibrato.hpp"

namespace effects {
	double Vibrato::callback(Note note, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) { 
		//note.frequency += max_time_deviation * shape->callback(Note(frequency, note.begin_time, note.end_time), duration_from_start);
		//note.frequency = note.frequency + max_time_deviation * shape->callback(Note(frequency, note.begin_time, note.end_time), duration_from_start);
	
		return instrument->callback_single_sample_effect_prior_to(note, duration_from_start + DoubleSeconds(shape->callback(Note(frequency, note.begin_time, note.end_time, 1), duration_from_start) * max_time_deviation), effects_position);
	}
	
	Vibrato::Vibrato(Signal *c_shape, double c_frequency, DoubleSeconds c_max_time_deviation) 
	:shape{c_shape}, frequency{c_frequency}, max_time_deviation{c_max_time_deviation}
	{}
}
