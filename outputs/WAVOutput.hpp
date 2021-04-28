#pragma once

#include "../Instrument.hpp"

#include <fstream>
#include <limits>
#include <stdint.h>

namespace outputs {
	class WAVOutput {
	private:
		template<typename T>
		void little_endian_put(std::ostream& file, T to_be_put) {
			for(int i = 0; i < sizeof(to_be_put); i++) {
				file.put(static_cast<uint8_t>(to_be_put & 0xFF));
				to_be_put >>= 8;
			}
		}
	public:
		Instrument* instrument;
		std::string file_name;
		uint16_t number_of_channels;
		uint32_t sample_rate;

		void export_to_file();
		void export_to_file(Instrument* f_instrument, std::string f_file_name, uint16_t f_number_of_channels = 1, uint32_t f_sample_rate = 44100);

		WAVOutput() = default;
		WAVOutput(Instrument* c_instrument, std::string c_file_name, uint16_t c_number_of_channels = 1, uint32_t c_sample_rate = 44100);

		class InstrumentMissing_exception :public std::exception {
		public:
			const char* what() const noexcept {return "The instrument is missing while invoking \"export_to_file\" function.";}
		};
		class FileNameMissing_exception :public std::exception {
		public:
			const char* what() const noexcept {return "The file name is missing while invoking \"export_to_file\" function.";}
		};
	};
}
