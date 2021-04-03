#pragma once 

#include "double_seconds.hpp"
#include "Note.hpp"

class Signal {
public:
	virtual double callback(Note note, double_seconds duration_from_start) = 0;
	virtual ~Signal() {}
};
