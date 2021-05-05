#include "../../include/timers/StepTimer.hpp"

namespace timers {
	StepTimer::StepTimer(DoubleSeconds c_step) 
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

	DoubleSeconds StepTimer::get_duration_from_start() {
		return duration_from_start;
	}
}
