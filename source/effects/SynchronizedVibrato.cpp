#include "../../include/effects/SynchronizedVibrato.hpp"

namespace effects {
	Sample SynchronizedVibrato::callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) { 
		sample_data.time_offset += DoubleSeconds(shape->callback(Note(frequency, note.begin_time, note.end_time, 1), duration_from_start) * max_time_deviation);
		return instrument->callback_single_sample_effect_prior_to(note, sample_data, duration_from_start, effects_position);
	}
	
	SynchronizedVibrato::SynchronizedVibrato(Signal *c_shape, Frequency c_frequency, DoubleSeconds c_max_time_deviation) 
	:shape{c_shape}, frequency{c_frequency}, max_time_deviation{c_max_time_deviation}
	{}
}
