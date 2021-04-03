#pragma once

#include "double_seconds.hpp"
#include "Note.hpp"
#include "Tone.hpp"
#include "Envelope.hpp"
#include "WholeSampleEffect.hpp"
#include "SingleSampleEffect.hpp"

#include <vector>
#include <string>
#include <utility>
#include <exception>
#include <chrono>

class Instrument {
public:
	using NoteId = unsigned int;
protected:
	std::vector<Note> all_notes;
	std::vector<std::pair<NoteId, unsigned int>> not_stopped_notes;
	NoteId next_unused_id;
public:
	Tone *tone{nullptr};
	Envelope *envelope{nullptr};
	std::vector<WholeSampleEffect*> whole_sample_effects;
	std::vector<SingleSampleEffect*> single_sample_effects;

	Instrument() = default;
	Instrument(Tone *c_tone, Envelope *c_envelope);
	
	NoteId play(Note);
	void stop(NoteId, double_seconds duration_from_start);
	void clear_notes();
	void stop_notes(double_seconds duration_from_start);
	double callback(double_seconds duration_from_start);
	double callback_whole_sample_effect_prior_to(double_seconds duration_from_start, int effects_position); 
	double callback_single_sample_effect_prior_to(Note note, double_seconds duration_from_start, int effects_position);
	std::vector<Note>& get_all_notes();

	friend WholeSampleEffect;
	friend SingleSampleEffect;
};

class Instrument_BadNoteIdWhileStoppingNote_exception :public std::exception {
public:
	const char* what() const noexcept {return "The NoteId given in \"stop_playing\()\" doesn't exist";}
};

class Instrument_MissingTone_exception :public std::exception {
public:
	const char* what() const noexcept {return "Sample is ordered without any tone specified for the instrument";}
};

class Instrument_MissingEnvelope_exception :public std::exception {
public:
	const char* what() const noexcept {return "Sample is ordered without any envelope specified for the instrument";}
};
