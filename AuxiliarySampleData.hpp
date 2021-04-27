#pragma once

#include "DoubleSeconds.hpp"
#include "Sample.hpp"

struct AuxiliarySampleData {
	Sample value{0.0};
	DoubleSeconds time_offset{0_ds};
	DoubleSeconds duration_from_start_note_is_over{0_ds};
};
