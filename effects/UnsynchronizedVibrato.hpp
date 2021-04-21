#pragma once

#include "../SingleSampleEffect.hpp"
#include "../Signal.hpp"
#include "../Note.hpp"

namespace effects {
	class UnsynchronizedVibrato :public SingleSampleEffect {
	public:
		Signal *shape;
		double frequency;
		DoubleSeconds max_time_deviation;
		double callback(Note note, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);

		UnsynchronizedVibrato(Signal *c_shape, double c_frequency, DoubleSeconds c_max_time_deviation);
	};
}
