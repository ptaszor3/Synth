#pragma once

#include "../Timer.hpp"

#include <chrono>

namespace timers {
	class RealTimeTimer :public Timer {
	private:
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock clock;
	public:
		RealTimeTimer();
	
		double_seconds get_time_from_start();
	};
}
