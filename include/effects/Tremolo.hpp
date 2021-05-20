#pragma once
#include "../SingleSampleEffect.hpp"
#include "../DoubleSeconds.hpp"
#include "../Frequency.hpp"
#include "SynchronizationType.hpp"

namespace effects {
	class Tremolo : public SingleSampleEffect {
		Sample synchronized_callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);
		Sample unsynchronized_callback(Note note, AuxiliarySampleData& sample_data, Instrument* instrument, DoubleSeconds duration_from_start, int effects_position);
	public:
		double maximal_volume_deviation;
		Frequency frequency;
		Signal* shape;
		SynchronizationType synchronization_type;

		Tremolo(Signal* shape, Frequency frequency, SynchronizationType c_synchronization_type = SynchronizationType::Synchronized, double c_maximal_volume_deviation = 0.3);

		Sample callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);
	};
}
