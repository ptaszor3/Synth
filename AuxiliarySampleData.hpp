#pragma once

#include "DoubleSeconds.hpp"
#include "Sample.hpp"

struct AuxiliarySampleData {
	double volume;
	Sample value;
	DoubleSeconds time_offset;
};
