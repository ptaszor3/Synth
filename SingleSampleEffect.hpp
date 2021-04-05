#pragma once

#include "DoubleSeconds.hpp"
#include "Note.hpp"
#include "Sample.hpp"

class Instrument;

class SingleSampleEffect {
public:
	virtual Sample callback(Note note, Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) = 0;
	virtual ~SingleSampleEffect() {};
};

#include "Instrument.hpp"
