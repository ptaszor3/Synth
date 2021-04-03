#pragma once

#include "../Timer.hpp"

#include <chrono>

namespace timers {
	class RealTimeTimer :public Timer {
	private:
		std::chrono::system_clock::time_point start;
		std::chrono::system_clock::duration offset;

		std::chrono::high_resolution_clock clock();
	public:
		double get_time_from_start();
		double start();
		double stop();
		double reset();
		double set_offset_to(double);
	}
}
