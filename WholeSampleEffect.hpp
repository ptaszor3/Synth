#pragma once

#include "Tone.hpp"

class Instrument;

class WholeSampleEffect {
public:
	virtual double callback(Instrument* instrument, double actual_time, int effects_position) = 0;
	virtual ~WholeSampleEffect() {};
};

#include "Instrument.hpp"
