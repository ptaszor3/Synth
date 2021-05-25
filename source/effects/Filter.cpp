#include "../../include/effects/Filter.hpp"

#include <cmath>

namespace effects {
	Filter::Filter(
		double c_cutoff_value, 
		double c_cutoff_value_max_deviation, 
		Signal* c_cutoff_value_signal, 
		Frequency c_cutoff_value_signal_frequency, 
		SynchronizationType c_cutoff_value_signal_synchronization_type, 
		double c_steepness)

		:cutoff_value{c_cutoff_value}, 
		cutoff_value_max_deviation{c_cutoff_value_max_deviation}, 
		cutoff_value_signal{c_cutoff_value_signal}, 
		cutoff_value_signal_frequency{c_cutoff_value_signal_frequency}, 
		cutoff_value_signal_synchronization_type{c_cutoff_value_signal_synchronization_type}, 

		steepness{c_steepness}
	{}

	inline constexpr Sample Filter::helper_shape_function(Sample input, double steepness) {
		return -std::pow(input, steepness) / 2.0 + 1.0;
	}

	Sample Filter::callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) {
		Sample difference = instrument->callback_single_sample_effect_prior_to(note, sample_data, duration_from_start, effects_position) - sample_data.custom["last_sample"];

		Sample present_intensity = 1;
		if(difference < 0)
			present_intensity = -1;

		double actuall_cutoff_value  = cutoff_value_signal->callback(Note(cutoff_value_signal_frequency, cutoff_value_signal_synchronization_type == SynchronizationType::Synchronized ? note.begin_time : 0_ds, cutoff_value_signal_synchronization_type == SynchronizationType::Synchronized ? note.end_time : 0_ds, note.volume), duration_from_start) * cutoff_value_max_deviation + cutoff_value;

		difference = std::abs(difference);
		if(difference * 1 / actuall_cutoff_value <= 1)
			present_intensity *= helper_shape_function(difference * 1 / actuall_cutoff_value, steepness) * 0.9 + 0.1;
		else if(difference * 1 / actuall_cutoff_value <= 2)
			present_intensity *= (1 - helper_shape_function(-difference * 1 / actuall_cutoff_value + 2, steepness)) * 0.9 + 0.1;
		else
			present_intensity *= 0.1;

		sample_data.custom["last_sample"] += present_intensity * difference;

		return sample_data.custom["last_sample"];
	}
}
