#pragma once

#include "../Effect.hpp"

namespace effects {
	class NoEffect : public Effects {
		double callback(Tone *tone, double actual_time) {
			return tone->callback(actual_time);
		}
	};
}
