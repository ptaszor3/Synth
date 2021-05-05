#include "../include/Instrument.hpp"
#include "../include/Sample.hpp"

Instrument::Instrument(Tone* c_tone, Envelope* c_envelope, Timer* c_timer)
:tone{c_tone}, envelope{c_envelope}, timer{c_timer} {
}

Instrument::NoteId Instrument::play(Note note_to_be_played) {
	all_notes.push_back(note_to_be_played);
	hearable_notes.insert({all_notes.size() - 1, AuxiliarySampleData()});
	not_stopped_notes.insert({next_unused_id, all_notes.size() - 1});

	return next_unused_id++;
}

Instrument::NoteId Instrument::play(Frequency frequency_to_be_played) {
	return play(Note(frequency_to_be_played, timer->get_duration_from_start(), DoubleSeconds(0.0), 1.0));
}

void Instrument::stop(NoteId id_of_note_to_be_stopped, DoubleSeconds duration_from_start) {
	unsigned int buffer;
	try {
		buffer = not_stopped_notes.at(id_of_note_to_be_stopped);
	}
	catch(std::out_of_range) {
		throw(BadNoteIdWhileStoppingNote_exception{});
	}

	all_notes[buffer].end_time = duration_from_start;
	hearable_notes[buffer].duration_from_start_note_is_over = envelope->get_time_note_is_over(all_notes[buffer]);
	not_stopped_notes.erase(id_of_note_to_be_stopped);
}

void Instrument::stop(NoteId id) {
	stop(id, timer->get_duration_from_start());
}

void Instrument::clear_notes() {
	all_notes.clear();
	hearable_notes.clear();
	not_stopped_notes.clear();
	next_unused_id = 1;
}

void Instrument::stop_notes() {
	for(auto& not_stopped_note : not_stopped_notes) {
		stop(not_stopped_note.first);
	}
	not_stopped_notes.clear();	
}

void Instrument::reset() {
	if(not_stopped_notes.size())
		throw ResetWhileNotesNotStopped_exception();

	hearable_notes.clear();

	for(int i = 0; i < all_notes.size(); i++) {
		hearable_notes.insert({i, AuxiliarySampleData()});
	}
}

Sample Instrument::callback(DoubleSeconds duration_from_start) {
	return callback_whole_sample_effect_prior_to(duration_from_start, whole_sample_effects.size());
}

Sample Instrument::callback() {
	if(!timer)
		throw MissingTimer_exception();
	
	return callback_whole_sample_effect_prior_to(timer->get_duration_from_start(), whole_sample_effects.size());
}

Sample Instrument::callback_whole_sample_effect_prior_to(DoubleSeconds duration_from_start, int effects_position) {
	effects_position--;
	if(effects_position < 0) {
		Sample sample{0};
		std::vector<unsigned int> indexes_to_be_erased;
		for(auto& x : hearable_notes) {
			if(x.second.duration_from_start_note_is_over != 0_ds and x.second.duration_from_start_note_is_over < duration_from_start) {
				indexes_to_be_erased.push_back(x.first);
				continue;
			}

			sample += callback_single_sample_effect_prior_to(all_notes[x.first], x.second, duration_from_start, single_sample_effects.size());
		}
		for(auto index : indexes_to_be_erased) {
			hearable_notes.erase(index);
		}

		return sample;
	}
	else
		return whole_sample_effects[effects_position]->callback(this, duration_from_start, effects_position);

	return 0;
}

Sample Instrument::callback_single_sample_effect_prior_to(Note note, AuxiliarySampleData& sample_data, DoubleSeconds duration_from_start, int effects_position) {
	effects_position--;

	if(effects_position < 0) {
		if(!tone)
			throw MissingTone_exception();
		if(!envelope)
			throw MissingEnvelope_exception();

		return tone->callback(note, duration_from_start + sample_data.time_offset) * envelope->callback(note, duration_from_start) * note.volume;
	}
	else
		return single_sample_effects[effects_position]->callback(note, sample_data, this, duration_from_start, effects_position);
}

std::vector<Note> Instrument::get_all_notes() {
	return all_notes;
}
