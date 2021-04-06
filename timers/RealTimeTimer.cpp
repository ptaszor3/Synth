#include "RealTimeTimer.hpp"

namespace timers {
	RealTimeTimer::RealTimeTimer() {
		start = clock.now();
	}

	void RealTimeTimer::restart() {
		start = clock.now();
	}

	DoubleSeconds RealTimeTimer::get_duration_from_start() {
		return DoubleSeconds(clock.now() - start);
	}
}
