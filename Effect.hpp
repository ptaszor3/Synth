#pragma once

#include "Tone.hpp"

class Instrument;

class Effect {
public:
	virtual double callback(Instrument* instrument, double actual_time, int effects_position) = 0;
	virtual ~Effect() {};
};

#include "Instrument.hpp"
