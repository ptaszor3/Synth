#include "Vibrato.hpp"

namespace effects {
	double Vibrato::callback(Note note, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) { 
		note.frequency += max_frequency_deviation * shape->callback(Note(frequency, 0_ds, 0_ds), duration_from_start);
		//note.frequency += 200;
	
		return instrument->callback_single_sample_effect_prior_to(note, duration_from_start, effects_position);
	}
	
	Vibrato::Vibrato(Signal *c_shape, double c_frequency, double c_max_frequency_deviation) 
	:shape{c_shape}, frequency{c_frequency}, max_frequency_deviation{c_max_frequency_deviation}
	{}
}
