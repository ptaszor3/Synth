#pragma once

#include "double_seconds.hpp"
#include "Tone.hpp"

class Instrument;

class WholeSampleEffect {
public:
	virtual double callback(Instrument* instrument, double_seconds duration_from_start, int effects_position) = 0;
	virtual ~WholeSampleEffect() {};
};

#include "Instrument.hpp"
