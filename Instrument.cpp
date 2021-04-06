#include "Instrument.hpp"
#include "Sample.hpp"

Instrument::Instrument(Tone* c_tone, Envelope* c_envelope, Timer* c_timer)
:tone{c_tone}, envelope{c_envelope}, timer{c_timer}
{}

Instrument::NoteId Instrument::play(Note note_to_be_played) {
	all_notes.push_back(note_to_be_played);
	if(!note_to_be_played.end_time.count())
		not_stopped_notes.push_back(std::pair<NoteId, unsigned int>(next_unused_id, all_notes.size() - 1));
	return next_unused_id++;
}

Instrument::NoteId Instrument::play(Frequency frequency_to_be_played) {
	return play(Note(frequency_to_be_played, timer->get_duration_from_start(), DoubleSeconds(0.0), 1.0));
}

void Instrument::stop(NoteId id_of_note_to_be_stopped, DoubleSeconds duration_from_start) {
	bool was_the_note_found{false};
	
	for(int i = 0; i < not_stopped_notes.size(); i++) {
		if(not_stopped_notes[i].first == id_of_note_to_be_stopped) {
			all_notes[not_stopped_notes[i].second].end_time = duration_from_start;
			not_stopped_notes.erase(not_stopped_notes.begin() + i);
			was_the_note_found = true; 
			break;
		}
	}
	
	if(!was_the_note_found) {
		throw(Instrument_BadNoteIdWhileStoppingNote_exception{});
	}
}

void Instrument::stop(NoteId id) {
	stop(id, timer->get_duration_from_start());
}

void Instrument::clear_notes() {
	all_notes.clear();
	not_stopped_notes.clear();
}

void Instrument::stop_notes(DoubleSeconds duration_from_start) {
	while(not_stopped_notes.size()) {
		all_notes[not_stopped_notes[0].second].end_time = duration_from_start;
		not_stopped_notes.erase(not_stopped_notes.begin());
	}
}

double Instrument::callback(DoubleSeconds duration_from_start) {
	return callback_whole_sample_effect_prior_to(duration_from_start, whole_sample_effects.size());
}

double Instrument::callback() {
	if(!timer)
		throw Instrument_MissingTimer_exception();
	
	return callback_whole_sample_effect_prior_to(timer->get_duration_from_start(), whole_sample_effects.size());
}

double Instrument::callback_whole_sample_effect_prior_to(DoubleSeconds duration_from_start, int effects_position) {
	effects_position--;
	if(effects_position < 0) {
		Sample sample{0};
		for(auto x : all_notes)
			sample += callback_single_sample_effect_prior_to(x, duration_from_start, single_sample_effects.size());
		return sample;
	}
	else
		return whole_sample_effects[effects_position]->callback(this, duration_from_start, effects_position);

	return 0;
}

double Instrument::callback_single_sample_effect_prior_to(Note note, DoubleSeconds duration_from_start, int effects_position) {
	effects_position--;

	if(effects_position < 0) {
		if(!tone)
			throw Instrument_MissingTone_exception();
		if(!envelope)
			throw Instrument_MissingEnvelope_exception();

		return tone->callback(note, duration_from_start) * envelope->callback(note, duration_from_start) * note.volume;
	}
	else
		return single_sample_effects[effects_position]->callback(note, this, duration_from_start, effects_position);
}

std::vector<Note>& Instrument::get_all_notes() {
	return all_notes;
}
