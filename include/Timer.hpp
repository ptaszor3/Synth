#pragma once

#include "DoubleSeconds.hpp"

class Timer {
public:
	virtual DoubleSeconds get_duration_from_start() = 0;
	virtual ~Timer() {};
};
