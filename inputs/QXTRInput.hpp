#pragma once

#include "../NoteInput.hpp"

#include <fstream>
#include <string>
#include <exception>

namespace inputs {
	class QXTRInput :public NoteInput, public std::ifstream {
	public:
		static Note ston(std::string);

		QXTRInput() = default;
		QXTRInput(std::string file_name, Instrument *c_instrument);

		void export_to_instrument();
	};

	class QXTRInput_FileIsIncomplete_exception :public std::exception {
	public:
		unsigned int number_of_missing_values;
		QXTRInput_FileIsIncomplete_exception(unsigned int c_number_of_missing_values)
		:number_of_missing_values{c_number_of_missing_values}
		{}

		const char* what() noexcept {
			std::string message{"The file has "};
			message += std::to_string(number_of_missing_values);
			message += " missing values";
			return message.c_str();
		}
	};

	class QXTRInput_ThereIsNoFile_exception :public std::exception {
		public:
			const char* what() noexcept {return "The file cannot be opened. Perhaps the file name hasn't been given, or the file with given name doesn't exist";}
	};

	class QXTRInput_FileIsCorrupted_exception :public std::exception {
		public:
			const char* what() noexcept {return "There are too many values in one line";}
	};
}

