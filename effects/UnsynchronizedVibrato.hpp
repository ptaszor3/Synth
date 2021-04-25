#pragma once

#include "../SingleSampleEffect.hpp"
#include "../Signal.hpp"
#include "../Note.hpp"
#include "../Frequency.hpp"
#include "../Sample.hpp"

namespace effects {
	class UnsynchronizedVibrato :public SingleSampleEffect {
	public:
		Signal *shape;
		Frequency frequency;
		DoubleSeconds max_time_deviation;
		Sample callback(Note note, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);

		UnsynchronizedVibrato(Signal *c_shape, Frequency c_frequency, DoubleSeconds c_max_time_deviation);
	};
}
