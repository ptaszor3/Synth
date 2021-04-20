#include "../Instrument.hpp"

#include <../include/asoundlib.h>
#include <exception>
#include <string>

namespace outputs {
	class ALSAOutputStream {
	private:
		snd_pcm_t* stream_handle{nullptr};
		snd_pcm_hw_params_t* hardware_parameters{nullptr};
		snd_pcm_sw_params_t* software_parameters{nullptr};

		static void check_if_errorus(int error_code);

		DoubleSeconds duration_to_last_write;
	public:
		snd_pcm_uframes_t buffer_size{1024};
		snd_pcm_uframes_t period_size{64};
		const char* device_name{"default"};
		unsigned int rate{44100};
		snd_pcm_format_t format{SND_PCM_FORMAT_FLOAT};
		unsigned int channels{1};
		Instrument* instrument{nullptr};

		ALSAOutputStream() = default;
		~ALSAOutputStream();

		void open();
		void close();
		void update();
		
		class WriteError_exception {
		public:
			const int error_code;

			WriteError_exception(const int c_error_code) :error_code(c_error_code) {}
			const char* what() noexcept {
				std::string buffer{"ALSA returned error code: "};
				buffer += std::to_string(error_code);
				buffer += snd_strerror(-error_code);
				return buffer.c_str();
			}
		};
	};
}
