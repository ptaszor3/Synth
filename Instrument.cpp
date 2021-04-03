#include "Instrument.hpp"

Instrument::Instrument(Tone *c_tone, Envelope *c_envelope)
:tone{c_tone}, envelope{c_envelope}
{}

Instrument::NoteId Instrument::play(Note note_to_be_played) {
	all_notes.push_back(note_to_be_played);
	not_stopped_notes.push_back(std::pair<NoteId, unsigned int>(next_unused_id, all_notes.size() - 1));
	return next_unused_id++;
}

void Instrument::stop(NoteId id_of_note_to_be_stopped, double_seconds duration_from_start) {
	bool was_the_note_found{false};
	
	for(int i = 0; i < not_stopped_notes.size(); i++)
		if(not_stopped_notes[i].first == id_of_note_to_be_stopped) {
			all_notes[not_stopped_notes[i].second].end_time = duration_from_start;
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

void Instrument::stop_notes(double_seconds duration_from_start) {
	while(not_stopped_notes.size()) {
		all_notes[not_stopped_notes[0].second].end_time = duration_from_start;
		not_stopped_notes.erase(not_stopped_notes.begin());
	}
}

double Instrument::callback(double_seconds duration_from_start) {
	return callback_whole_sample_effect_prior_to(duration_from_start, whole_sample_effects.size());
}

double Instrument::callback_whole_sample_effect_prior_to(double_seconds duration_from_start, int effects_position) {
	effects_position--;
	if(effects_position < 0) {
		for(auto x : all_notes)
			return callback_single_sample_effect_prior_to(x, duration_from_start, single_sample_effects.size());
	}
	else
		return whole_sample_effects[effects_position]->callback(this, duration_from_start, effects_position);

	return 0;
}

double Instrument::callback_single_sample_effect_prior_to(Note note, double_seconds duration_from_start, int effects_position) {
	effects_position--;

	if(effects_position < 0) {
		if(!tone)
			throw Instrument_MissingTone_exception();
		if(!envelope)
			throw Instrument_MissingEnvelope_exception();

		return tone->callback(note, duration_from_start) * envelope->callback(note, duration_from_start);
	}
	else
		return single_sample_effects[effects_position]->callback(note, this, duration_from_start, effects_position);

}

std::vector<Note>& Instrument::get_all_notes() {
	return all_notes;
}
