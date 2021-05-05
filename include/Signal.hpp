#pragma once 

#include "DoubleSeconds.hpp"
#include "Note.hpp"
#include "Sample.hpp"

class Signal {
public:
	virtual Sample callback(Note note, DoubleSeconds duration_from_start) = 0;
	virtual ~Signal() {}
};
