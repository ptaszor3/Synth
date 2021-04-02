#pragma once

#include "Note.hpp"

class Instrument;

class SingleSampleEffect {
public:
	virtual double callback(Note note, Instrument *instrument, double actual_time, int effects_position) = 0;
	virtual ~SingleSampleEffect() {};
};

#include "Instrument.hpp"
