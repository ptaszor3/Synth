#include "../../include/outputs/WAVOutput.hpp"
#include "../../include/DoubleSeconds.hpp"

namespace outputs {
	WAVOutput::WAVOutput(Instrument* c_instrument, std::string c_file_name, uint16_t c_number_of_channels, uint32_t c_sample_rate)
	:instrument{c_instrument}, file_name{c_file_name}, number_of_channels{c_number_of_channels}, sample_rate{c_sample_rate} {}

	void WAVOutput::export_to_file(Instrument* f_instrument, std::string f_file_name, uint16_t f_number_of_channels, uint32_t f_sample_rate) {
		instrument = f_instrument;
		file_name = f_file_name;
		number_of_channels = f_number_of_channels;
		sample_rate = f_sample_rate;

		export_to_file();
	}

	void WAVOutput::export_to_file() {
		if(!instrument)
			throw InstrumentMissing_exception();
		if(file_name == "")
			throw FileNameMissing_exception();

		DoubleSeconds duration_from_start_last_note_ends = 0_ds;

		std::vector<Note> notes_buffer = instrument->get_all_notes();
		for(auto x : notes_buffer)
			if(x.end_time > duration_from_start_last_note_ends)
				duration_from_start_last_note_ends = x.end_time;

		duration_from_start_last_note_ends += 5_ds;
		unsigned int number_of_samples = static_cast<unsigned int>(duration_from_start_last_note_ends.count() * sample_rate);

		uint32_t subchunk_2_size = number_of_samples * number_of_channels * sizeof(int16_t);
		uint32_t chunk_size = subchunk_2_size + 36;
		std::ofstream file(file_name);
		file << "RIFF";
		little_endian_put(file, static_cast<uint32_t>(chunk_size));
		file << "WAVE";
		file << "fmt ";
		little_endian_put(file, static_cast<uint32_t>(16));
		little_endian_put(file, static_cast<uint16_t>(1));
		little_endian_put(file, number_of_channels);
		little_endian_put(file, sample_rate);
		little_endian_put(file, static_cast<uint32_t>(sample_rate * number_of_channels * sizeof(int16_t)));
		little_endian_put(file, static_cast<uint16_t>(number_of_channels * sizeof(int16_t)));
		little_endian_put(file, static_cast<uint16_t>(sizeof(int16_t) * 8));
		file << "data";
		little_endian_put(file, static_cast<uint32_t>(number_of_samples * number_of_channels * sizeof(int16_t)));

		for(int i = 0; i < number_of_samples; i++)
			for(int j = 0; j < number_of_channels; j++)
				little_endian_put(file, static_cast<int16_t>(std::numeric_limits<int16_t>::max() * instrument->callback(DoubleSeconds(i / static_cast<double>(sample_rate)))));
	}
}
