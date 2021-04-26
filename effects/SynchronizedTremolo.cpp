#include "SynchronizedTremolo.hpp"

namespace effects {
	Sample SynchronizedTremolo::callback(Note note, AuxiliarySampleData sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) { 
		Sample sample_to_change = instrument->callback_single_sample_effect_prior_to(note, sample_data, duration_from_start, effects_position);
		return sample_to_change + sample_to_change * shape->callback(Note(frequency, note.begin_time, note.end_time, max_volume_deviation), duration_from_start) * max_volume_deviation;
	}
	
	SynchronizedTremolo::SynchronizedTremolo(Signal *c_shape, Frequency c_frequency, double c_max_volume_deviation) 
	:shape{c_shape}, frequency{c_frequency}, max_volume_deviation{c_max_volume_deviation}
	{}
}
