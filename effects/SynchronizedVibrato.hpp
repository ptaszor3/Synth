#pragma once

#include "../SingleSampleEffect.hpp"
#include "../Signal.hpp"
#include "../Note.hpp"
#include "../Frequency.hpp"
#include "../Sample.hpp"

namespace effects {
	class SynchronizedVibrato :public SingleSampleEffect {
	public:
		Signal *shape;
		Frequency frequency;
		DoubleSeconds max_time_deviation;
		Sample callback(Note note, AuxiliarySampleData sample_data, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);

		SynchronizedVibrato(Signal *c_shape, Frequency c_frequency, DoubleSeconds c_max_time_deviation);
	};
}
