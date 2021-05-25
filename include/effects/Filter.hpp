#pragma once
#include "../SingleSampleEffect.hpp"
#include "../DoubleSeconds.hpp"
#include "../Frequency.hpp"
#include "SynchronizationType.hpp"

#include <exception>

namespace effects {
	class Filter :public SingleSampleEffect{
		static Sample filter_shape_callback(Sample first, Sample second, double steepness, double cutoff_value);
		static inline constexpr Sample helper_shape_function(Sample input, double steepness);
	public:
		double cutoff_value;
		double cutoff_value_max_deviation;
		Signal* cutoff_value_signal;
		Frequency cutoff_value_signal_frequency;
		SynchronizationType cutoff_value_signal_synchronization_type;
		double steepness;

		Filter(
			double c_cutoff_value, 
			double c_cutoff_value_max_deviation, 
			Signal* c_cutoff_value_signal, 
			Frequency c_cutoff_value_signal_frequency, 
			SynchronizationType c_cutoff_value_signal_synchronization_type, 
			double c_steepness);

		Sample callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) override;
	};
}
