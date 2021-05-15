#include "../../include/effects/Vibrato.hpp"

namespace effects {
	Sample Vibrato::synchronized_callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) {
		sample_data.time_offset += DoubleSeconds(shape->callback(Note(frequency, note.begin_time, note.end_time, 1.0), duration_from_start) * maximal_time_deviation);
		return instrument->callback_single_sample_effect_prior_to(note, sample_data,  duration_from_start, effects_position);
	}

	Sample Vibrato::unsynchronized_callback(Note note, AuxiliarySampleData& sample_data, Instrument* instrument, DoubleSeconds duration_from_start, int effects_position) {
		sample_data.time_offset += DoubleSeconds(shape->callback(Note(frequency, 0_ds, 0_ds, 1.0), duration_from_start) * maximal_time_deviation);
		return instrument->callback_single_sample_effect_prior_to(note, sample_data, duration_from_start, effects_position);
	}

	Vibrato::Vibrato(Signal* c_shape, Frequency c_frequency, SynchronizationType c_synchronization_type, DoubleSeconds c_maximal_time_deviation)
	:shape{c_shape}, frequency{c_frequency}, maximal_time_deviation{c_maximal_time_deviation}, synchronization_type{c_synchronization_type} {}

	Sample Vibrato::callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) {
		if(synchronization_type == SynchronizationType::Synchronized)
			return synchronized_callback(note, sample_data, instrument, duration_from_start, effects_position);
		else if(synchronization_type == SynchronizationType::Unsynchronized)
			return unsynchronized_callback(note, sample_data, instrument, duration_from_start, effects_position);
	}
}
