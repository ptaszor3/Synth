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
	
		void restart();
		DoubleSeconds get_duration_from_start();
	};
}
