#pragma once

#include "double_seconds.hpp"
#include "Note.hpp"

class Instrument;

class SingleSampleEffect {
public:
	virtual double callback(Note note, Instrument *instrument, double_seconds duration_from_start, int effects_position) = 0;
	virtual ~SingleSampleEffect() {};
};

#include "Instrument.hpp"
