#pragma once

#include "DoubleSeconds.hpp"
#include "Frequency.hpp"

class Note {
public:
	Frequency frequency;
	DoubleSeconds begin_time;
	DoubleSeconds end_time;
	double volume;

	Note() = default;
	Note(double c_frequency, DoubleSeconds c_begin_time, DoubleSeconds c_end_time = DoubleSeconds(0), double c_volume = 1.0) 
	:frequency{c_frequency}, begin_time{c_begin_time}, end_time{c_end_time}, volume{c_volume}
	{}
};

