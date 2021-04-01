#pragma once

#include "../Effect.hpp"

namespace effects {
	class VolumeControl :public Effect {
	public:
		double volume = 1.0;
		double callback(Instrument *instrument, double actual_time, int effects_position);
	};
}
