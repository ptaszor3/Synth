#pragma once

#include "../WholeSampleEffect.hpp"

namespace effects {
	class VolumeControl :public WholeSampleEffect {
	public:
		double volume = 1.0;
		Sample callback(Instrument *instrument, DoubleSeconds duration_from_start, int effects_position);
	};
}
