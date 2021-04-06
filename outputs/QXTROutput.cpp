#include "QXTROutput.hpp"

namespace outputs {
	void QXTROutput::export_to_file() {
		if(!(file_name == ""))
			throw QXTROutput_FileNameMissing_exception();
		if(!instrument)
			throw QXTROutput_InstrumentMissing_exception();

		std::ofstream file(file_name);

		for(auto x : instrument->get_all_notes())
			file << x.frequency << '\t' << x.begin_time.count() << '\t' << x.end_time.count() << '\t' << x.volume << std::endl;
	}

	void QXTROutput::export_to_file(std::string f_file_name) {
		file_name = f_file_name;
		export_to_file();
		file_name = "";
	}

	QXTROutput::QXTROutput(Instrument* c_instrument, std::string c_file_name)
	:instrument{c_instrument}, file_name{c_file_name} {}
}
