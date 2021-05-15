#pragma once
#include "../SingleSampleEffect.hpp"
#include "../DoubleSeconds.hpp"
#include "../Frequency.hpp"
#include "SynchronizationType.hpp"

namespace effects {
	class Vibrato :public SingleSampleEffect {
		Sample synchronized_callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);
		Sample unsynchronized_callback(Note note, AuxiliarySampleData& sample_data, Instrument* instrument, DoubleSeconds duration_from_start, int effects_position);
	public:
		DoubleSeconds maximal_time_deviation;
		Frequency frequency;
		Signal* shape;
		SynchronizationType synchronization_type;

		Vibrato(Signal* shape, Frequency frequency, SynchronizationType c_synchronization_type = SynchronizationType::Synchronized, DoubleSeconds c_maximal_time_deviation = 0.000001_ds);

		Sample callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);
	};
}
