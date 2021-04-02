#pragma once

#include "../WholeSampleEffect.hpp"

namespace effects {
	class VolumeControl :public WholeSampleEffect {
	public:
		double volume = 1.0;
		double callback(Instrument *instrument, double actual_time, int effects_position);
	};
}
