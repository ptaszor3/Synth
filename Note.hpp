#pragma once

class Note {

public:
	double frequency;
	double begin_time;
	double end_time{0};

	Note() = default;
	Note(double c_frequency, double c_begin_time, double c_end_time) 
	:frequency{c_frequency}, begin_time{c_begin_time}, end_time{c_end_time}
	{}
	
};

