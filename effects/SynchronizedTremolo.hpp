#pragma once

#include "../SingleSampleEffect.hpp"
#include "../Signal.hpp"
#include "../Note.hpp"
#include "../Frequency.hpp"
#include "../Sample.hpp"

namespace effects {
	class SynchronizedTremolo :public SingleSampleEffect {
	public:
		Signal *shape;
		Frequency frequency;
		double max_volume_deviation;
		Sample callback(Note note, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);

		SynchronizedTremolo(Signal *c_shape, Frequency c_frequency, double c_max_volume_deviation);
	};
}
