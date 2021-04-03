#include "RealTimeTimer.hpp"

namespace timers {
	RealTimeTimer::RealTimeTimer() {
		start = clock.now();
	}

	double_seconds RealTimeTimer::get_time_from_start() {
		return double_seconds(clock.now() - start);
	}
}
