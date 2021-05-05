#include "../../include/effects/VolumeControl.hpp"

namespace effects {
	Sample VolumeControl::callback(Instrument *instrument, DoubleSeconds duration_from_start, int effects_position) {
		return instrument->callback_whole_sample_effect_prior_to(duration_from_start, effects_position) * volume;
	}
}
