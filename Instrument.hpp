#pragma once

#include "DoubleSeconds.hpp"
#include "Sample.hpp"
#include "Note.hpp"
#include "Tone.hpp"
#include "Envelope.hpp"
#include "Timer.hpp"
#include "WholeSampleEffect.hpp"
#include "SingleSampleEffect.hpp"
#include "AuxiliarySampleData.hpp"

#include <vector>
#include <map>
#include <string>
#include <utility>
#include <exception>
#include <chrono>

class Instrument {
public:
	using NoteId = unsigned int;
protected:
	std::vector<Note> all_notes;
	std::vector<std::pair<AuxiliarySampleData, unsigned int>> hearable_notes;
	std::map<NoteId, unsigned int> not_stopped_notes;
	NoteId next_unused_id{1};
public:
	Tone *tone;
	Envelope *envelope;
	Timer *timer;
	std::vector<WholeSampleEffect*> whole_sample_effects;
	std::vector<SingleSampleEffect*> single_sample_effects;

	Instrument(Tone* c_tone = nullptr, Envelope* c_envelope = nullptr, Timer* c_timer = nullptr);
	
	NoteId play(Note);
	NoteId play(Frequency);
	void stop(NoteId, DoubleSeconds duration_from_start);
	void stop(NoteId);
	void clear_notes();
	void stop_notes(DoubleSeconds duration_from_start);

	Sample callback(DoubleSeconds duration_from_start);
	Sample callback();
	Sample callback_whole_sample_effect_prior_to(DoubleSeconds duration_from_start, int effects_position); 
	Sample callback_single_sample_effect_prior_to(Note note, AuxiliarySampleData sample_data, DoubleSeconds duration_from_start, int effects_position);

	std::vector<Note> get_all_notes();

	friend WholeSampleEffect;
	friend SingleSampleEffect;
};

class Instrument_BadNoteIdWhileStoppingNote_exception :public std::exception {
public:
	const char* what() const noexcept {return "The NoteId given in \"stop_playing\()\" is inappropriate";}
};

class Instrument_MissingTone_exception :public std::exception {
public:
	const char* what() const noexcept {return "Sample is ordered with no tone specified";}
};

class Instrument_MissingEnvelope_exception :public std::exception {
public:
	const char* what() const noexcept {return "Sample is ordered with no envelope specified";}
};

class Instrument_MissingTimer_exception :public std::exception {
public:
	const char* what() const noexcept {return "Sample is ordered with no timer specified";}
};
