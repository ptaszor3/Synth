#pragma once 

#include "../Timer.hpp"

#include <exception>

namespace timers {
class StepTimer :public Timer{
	public:
		double_seconds duration_from_start{0_ds};
		double_seconds step;

		StepTimer(double_seconds c_step = 0_ds);

		void operator++();
		void operator--();
		double_seconds get_time_from_start();
	};

	class StepTimer_ClockDoesntProgress_exception :public std::exception {
	public:
		virtual const char* what() noexcept {return "The step member variable is set to zero and thus the clock doesn't tick";};
	};

}
