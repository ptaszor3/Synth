#pragma once

#include "Signal.hpp"

#include <exception>

class Envelope :public Signal{
public:
	virtual ~Envelope() {}
	virtual DoubleSeconds get_time_note_is_over(Note) = 0;

	class NoteDoesntEnd_exception {
	public:
		const char* what() const noexcept {return "get_time_note_is_done(Note) has been invoked with note, that doesn't have an end_time set";}
	};
};
