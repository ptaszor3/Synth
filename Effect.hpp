#pragma once

#include "Tone.hpp"

class Effect {

public:
	virtual double callback(Tone* tone, double actual_time) = 0;
	virtual ~Effect() {};
};
