#pragma once

#include "../Instrument.hpp"

#include <string>
#include <fstream>
#include <exception>

namespace outputs {
	class QXTROutput {
	public:
		Instrument* instrument;
		std::string file_name;

		void export_to_file();
		void export_to_file(std::string file_name);

		QXTROutput() = default;
		QXTROutput(Instrument* c_instrument, std::string c_file_name);
	};

	class QXTROutput_InstrumentMissing_exception :public std::exception {
	public:
		const char* what() const noexcept {return "Export function has been invoked without instrument pointer initialized";}
	};

	class QXTROutput_FileNameMissing_exception :public std::exception {
	public:	
		const char* what() const noexcept {return "Export function has been invoked without file name given";}
	};
}
