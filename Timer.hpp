#pragma once

class Timer {
public:
	virtual double get_time_from_start() = 0;
	virtual ~Timer() {};
}
