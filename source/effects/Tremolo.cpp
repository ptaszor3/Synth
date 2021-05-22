#include "../../include/effects/Tremolo.hpp"

namespace effects {
	Sample Tremolo::synchronized_callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) {
		return instrument->callback_single_sample_effect_prior_to(note, sample_data,  duration_from_start, effects_position) * (shape->callback(Note(frequency, note.begin_time, note.end_time, 1.0), duration_from_start - note.begin_time) * maximal_volume_deviation + 1);
	}

	Sample Tremolo::unsynchronized_callback(Note note, AuxiliarySampleData& sample_data, Instrument* instrument, DoubleSeconds duration_from_start, int effects_position) {
		return instrument->callback_single_sample_effect_prior_to(note, sample_data, duration_from_start, effects_position) * (shape->callback(Note(frequency, 0_ds, 0_ds, 1.0), duration_from_start) * maximal_volume_deviation + 1);
	}

	Tremolo::Tremolo(Signal* c_shape, Frequency c_frequency, SynchronizationType c_synchronization_type, double c_maximal_volume_deviation)
	:shape{c_shape}, frequency{c_frequency}, maximal_volume_deviation{c_maximal_volume_deviation}, synchronization_type{c_synchronization_type} {}

	Sample Tremolo::callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) {
		if(synchronization_type == SynchronizationType::Synchronized)
			return synchronized_callback(note, sample_data, instrument, duration_from_start, effects_position);
		else if(synchronization_type == SynchronizationType::Unsynchronized)
			return unsynchronized_callback(note, sample_data, instrument, duration_from_start, effects_position);
	}
}
