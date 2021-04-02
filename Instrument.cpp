#include "Instrument.hpp"

Instrument::Instrument(Tone *c_tone, Envelope *c_envelope)
:tone{c_tone}, envelope{c_envelope}
{}

Instrument::NoteId Instrument::play(Note note_to_be_played) {
	all_notes.push_back(note_to_be_played);
	not_stopped_notes.push_back(std::pair<NoteId, unsigned int>(next_unused_id, all_notes.size() - 1));
	return next_unused_id++;
}

void Instrument::stop(NoteId id_of_note_to_be_stopped, double actual_time) {
	bool was_the_note_found{false};
	
	for(int i = 0; i < not_stopped_notes.size(); i++)
		if(not_stopped_notes[i].first == id_of_note_to_be_stopped) {
			all_notes[not_stopped_notes[i].second].end_time = actual_time;
			not_stopped_notes.erase(not_stopped_notes.begin() + i);
			was_the_note_found = true; 
			break;
		}
	
	if(!was_the_note_found) {
		throw(Instrument_BadNoteIdWhileStoppingNote_exception{});
	}
}

void Instrument::clear_notes() {
	all_notes.clear();
	not_stopped_notes.clear();
}

void Instrument::stop_notes(double actual_time) {
	while(not_stopped_notes.size()) {
		all_notes[not_stopped_notes[0].second].end_time = actual_time;
		not_stopped_notes.erase(not_stopped_notes.begin());
	}
}

double Instrument::callback(double actual_time) {
	return callback_whole_sample_effect_prior_to(actual_time, whole_sample_effects.size());
}

double Instrument::callback_whole_sample_effect_prior_to(double actual_time, int effects_position) {
	effects_position--;
	if(effects_position < 0) {
		for(auto x : all_notes)
			return callback_single_sample_effect_prior_to(x, actual_time, single_sample_effects.size());
	}
	else
		return whole_sample_effects[effects_position]->callback(this, actual_time, effects_position);

	return 0;
}

double Instrument::callback_single_sample_effect_prior_to(Note note, double actual_time, int effects_position) {
	effects_position--;

	if(effects_position < 0) {
		if(!tone)
			throw Instrument_MissingTone_exception();
		if(!envelope)
			throw Instrument_MissingEnvelope_exception();

		return tone->callback(note, actual_time) * envelope->callback(note, actual_time);
	}
	else
		return single_sample_effects[effects_position]->callback(note, this, actual_time, effects_position);

}

std::vector<Note>& Instrument::get_all_notes() {
	return all_notes;
}
