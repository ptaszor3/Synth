#pragma once

#include "../SingleSampleEffect.hpp"
#include "../Signal.hpp"
#include "../Note.hpp"

namespace effects {
	class Vibrato :public SingleSampleEffect {
	public:
		Signal *shape;
		double frequency{1.0};
		double max_frequency_deviation{1.0};
		double callback(Note note, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);

		Vibrato(Signal *c_shape, double c_frequency, double c_max_frequency_deviation);
	};
}
