#pragma once

#include "double_seconds.hpp"

class Timer {
public:
	virtual double_seconds get_time_from_start() = 0;
	virtual ~Timer() {};
};
