#include "VolumeControl.hpp"

namespace effects {
	double VolumeControl::callback(Instrument *instrument, double actual_time, int effects_position) {
		return volume * instrument->callback_whole_sample_effect_prior_to(actual_time, effects_position);
	}
}
