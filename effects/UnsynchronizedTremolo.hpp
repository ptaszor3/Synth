#pragma once

#include "../SingleSampleEffect.hpp"
#include "../Signal.hpp"
#include "../Note.hpp"
#include "../Sample.hpp"

namespace effects {
	class UnsynchronizedTremolo :public SingleSampleEffect {
	public:
		Signal *shape;
		Frequency frequency;
		double max_volume_deviation;
		Sample callback(Note note, AuxiliarySampleData& sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);

		UnsynchronizedTremolo(Signal *c_shape, Frequency c_frequency, double c_max_volume_deviation);
	};
}
