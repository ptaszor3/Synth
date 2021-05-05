#include "../../include/inputs/QXTRInput.hpp"

namespace inputs {
	Note QXTRInput::ston(std::string input) {
		std::string words[4];
		int words_counter = -1;
		bool was_the_last_one_white = true;
		for(auto x : input) {
			if(x == ' ' or x == '\t') {
				was_the_last_one_white = true;
				continue;
			}
			else {
				if(was_the_last_one_white) {
					was_the_last_one_white = false;
					if(words_counter < 3)
						words_counter++;
					else
						throw (QXTRInput_FileIsCorrupted_exception());
				}
				words[words_counter] += x;
			}
		}

		if(words_counter < 3)
			throw QXTRInput_FileIsIncomplete_exception(3 - words_counter);

		return Note(std::stod(words[0]), DoubleSeconds(std::stod(words[1])), DoubleSeconds(std::stod(words[2])), std::stod(words[3]));
	}

	QXTRInput::QXTRInput(std::string file_name, Instrument *c_instrument) 
	:NoteInput{c_instrument} {
		open(file_name);
	}

	void QXTRInput::export_to_instrument() {
		if(good())
			while(peek() != EOF) {
				std::string buffer;
				std::getline(*this, buffer);
				instrument->play(QXTRInput::ston(buffer));
				while(peek() == ' ' or peek() == '\t' or peek() == '\n' or peek() == '\r')
					ignore(1);
			}
		else
			throw(QXTRInput_ThereIsNoFile_exception());
	}
}
