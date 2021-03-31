#pragma once

#include "Note.hpp"

class Envelope {

public:
	virtual double callback(Note note, double actual_time) = 0;
	virtual ~Envelope() {}
};
