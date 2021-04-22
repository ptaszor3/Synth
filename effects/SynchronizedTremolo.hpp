#pragma once

#include "../SingleSampleEffect.hpp"
#include "../Signal.hpp"
#include "../Note.hpp"

namespace effects {
	class SynchronizedTremolo :public SingleSampleEffect {
	public:
		Signal *shape;
		double frequency;
		double max_volume_deviation;
		double callback(Note note, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);

		SynchronizedTremolo(Signal *c_shape, double c_frequency, double c_max_volume_deviation);
	};
}
