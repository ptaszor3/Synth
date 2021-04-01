#pragma once

#include "Note.hpp"
#include "Tone.hpp"
#include "Envelope.hpp"
#include "Id.hpp"
#include "Effect.hpp"

#include <vector>
#include <string>
#include <utility>
#include <exception>

class Instrument {
	std::vector<std::pair<Note, Id>> new_notes;
	std::vector<Note> old_notes;
	Id next_unused_id;
public:
	Tone *tone{nullptr};
	Envelope *envelope{nullptr};
	std::vector<Effect*> effects;

	Instrument() = default;
	Instrument(Tone *c_tone, Envelope *c_envelope);
	
	Id play(Note);
	void stop(Id, double actual_time);
	void clear_notes();
	void stop_notes(double actual_time);
	double callback(double actual_time);
	double callback_effect_prior_to(double actual_time, int effects_position); 

	friend Effect;
};

class Instrument_BadIdWhileStoppingNote_exception :public std::exception {
public:
	const char* what() const noexcept {return "The Id given in \"stop_playing\()\" doesn't exist";}
};

class Instrument_MissingTone_exception :public std::exception {
public:
	const char* what() const noexcept {return "Sample is ordered without any tone specified for the instrument";}
};

class Instrument_MissingEnvelope_exception :public std::exception {
public:
	const char* what() const noexcept {return "Sample is ordered without any envelope specified for the instrument";}
};
