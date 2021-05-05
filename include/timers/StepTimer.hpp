#pragma once 

#include "../Timer.hpp"

#include <exception>

namespace timers {
class StepTimer :public Timer{
	public:
		DoubleSeconds duration_from_start{0_ds};
		DoubleSeconds step;

		StepTimer(DoubleSeconds c_step = 0_ds);

		void operator++();
		void operator--();
		DoubleSeconds get_duration_from_start();
	};

	class StepTimer_ClockDoesntProgress_exception :public std::exception {
	public:
		virtual const char* what() noexcept {return "The step member variable is set to zero and thus the clock doesn't tick";};
	};

}
