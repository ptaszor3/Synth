#include "StepTimer.hpp"

namespace timers {
	StepTimer::StepTimer(double_seconds c_step) 
	:step{c_step}
	{}
	
	void StepTimer::operator++() {
		if(!step.count())
			throw StepTimer_ClockDoesntProgress_exception();
		duration_from_start += step;
	}
	
	void StepTimer::operator--() {
		if(!step.count())
			throw StepTimer_ClockDoesntProgress_exception();
		duration_from_start -= step;
	}

	double_seconds StepTimer::get_time_from_start() {
		return duration_from_start;
	}
}
