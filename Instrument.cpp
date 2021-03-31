#pragma once

#include "Instrument.hpp"

Instrument::Instrument(Tone *c_tone, Envelope *c_envelope)
:tone{c_tone}, envelope{c_envelope}
{}

Id Instrument::play(Note note_to_be_played) {
	new_notes.push_back(std::pair<Note, Id>(note_to_be_played, next_unused_id));
	return next_unused_id++;
}

void Instrument::stop(Id id_of_note_to_be_stopped, double actual_time) {

	bool was_the_note_found{false};
	
	for(int i = 0; i < new_notes.size(); i++)
		if(new_notes[i].second == id_of_note_to_be_stopped) {
			new_notes[i].first.end_time = actual_time;
			old_notes.push_back(new_notes[i].first);
			new_notes.erase(new_notes.begin() + i);
			was_the_note_found = true; 
			break;
		}
	
	if(!was_the_note_found) {
		throw(Instrument_BadIdWhileStoppingNote_exception{});
	}
}

void Instrument::clear_notes() {
	new_notes.clear();
	old_notes.clear();
}

void Instrument::stop_notes(double actual_time) {
	
	while(new_notes.size()) {
		new_notes[0].first.end_time = actual_time;
		old_notes.push_back(new_notes[0].first);
		new_notes.erase(new_notes.begin() + 0);
	}
}

double Instrument::callback(double actual_time) {
	double sample{0};
	
	if(!tone)
		throw Instrument_MissingTone_exception();
	if(!envelope)
		throw Instrument_MissingEnvelope_exception();

	for(auto x : new_notes)
		sample += tone->callback(x.first, actual_time) * envelope->callback(x.first, actual_time);
	for(auto x : old_notes)
		sample += tone->callback()(x, actual_time) * envelope->callback()(x, actual_time);

	return sample * volume;
}
