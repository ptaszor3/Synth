#pragma once

#include "double_seconds.hpp"

class Note {
public:
	double frequency;
	double_seconds begin_time;
	double_seconds end_time;
	double volume;

	Note() = default;
	Note(double c_frequency, double_seconds c_begin_time, double_seconds c_end_time = double_seconds(0), double c_volume = 1.0) 
	:frequency{c_frequency}, begin_time{c_begin_time}, end_time{c_end_time}, volume{c_volume}
	{}
};

