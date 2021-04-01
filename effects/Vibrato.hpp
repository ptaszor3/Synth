#pragma once

#include "../Effect.hpp"
#include "../Signal.hpp"

class Vibrato :public Effect {
	Signal *shape;
	double max_frequency_deviation = 1;
public:
	double inner_callback(Instrument *instrument, double actual_time, int effects_position);
}
