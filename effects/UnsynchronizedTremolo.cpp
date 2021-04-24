#include "UnsynchronizedTremolo.hpp"

namespace effects {
	double UnsynchronizedTremolo::callback(Note note, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) { 
		double sample_to_change = instrument->callback_single_sample_effect_prior_to(note, duration_from_start, effects_position); 
		return sample_to_change - sample_to_change * shape->callback(Note(frequency, duration_from_start - note.begin_time, duration_from_start - note.end_time, 1), duration_from_start - note.begin_time) * max_volume_deviation;
	}
	
	UnsynchronizedTremolo::UnsynchronizedTremolo(Signal *c_shape, double c_frequency, double c_max_volume_deviation) 
	:shape{c_shape}, frequency{c_frequency}, max_volume_deviation{c_max_volume_deviation}
	{}
}
