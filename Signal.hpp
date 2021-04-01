#pragma once 

#include "Note.hpp"

class Signal {
public:
	virtual double callback(Note note, double actual_time) = 0;
	virtual ~Signal() {}
};
