#pragma once

#include "DoubleSeconds.hpp"
#include "Sample.hpp"

#include <map>

struct AuxiliarySampleData {
	DoubleSeconds time_offset{0_ds};
	DoubleSeconds duration_from_start_note_is_over{0_ds};
	std::map<std::string, double> custom;
};
