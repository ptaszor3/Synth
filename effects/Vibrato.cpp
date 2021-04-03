#include "Vibrato.hpp"

namespace effects {
	double Vibrato::callback(Note note, Instrument *instrument, double_seconds duration_from_start, int effects_position) { 
		note.frequency += max_frequency_deviation * shape->callback(Note(frequency, note.begin_time, note.end_time), duration_from_start);
	
		return instrument->callback_single_sample_effect_prior_to(note, duration_from_start, effects_position);
	}
	
	Vibrato::Vibrato(Signal *c_shape, double c_frequency, double c_max_frequency_deviation) 
	:shape{c_shape}, frequency{c_frequency}, max_frequency_deviation{c_max_frequency_deviation}
	{}
}
