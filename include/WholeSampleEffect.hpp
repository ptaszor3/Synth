#pragma once

#include "DoubleSeconds.hpp"
#include "Tone.hpp"
#include "Sample.hpp"

class Instrument;

class WholeSampleEffect {
public:
	virtual Sample callback(Instrument* instrument, DoubleSeconds duration_from_start, int effects_position) = 0;
	virtual ~WholeSampleEffect() {};
};

#include "Instrument.hpp"
