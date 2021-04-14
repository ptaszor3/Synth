#include "../Instruement.hpp"

#include <../include/asoundlib.h>
#include <exception>

namespace outputs {
	class ALSAOutputStream {
	private:
		snd_pcm_t* stream_handle{nullptr};
		snd_pcm_hw_parameters_t* hardware_parameters{nullptr};
		snd_pcm_sw_parameters_t* software_parameters{nullptr};

		void open();
		void close();
	public:
		snd_pcm_uframes_t buffer_size{1024};
		snd_pcm_uframes_t period_size{64}
		char device_name{"default"};
		int rate{44100};
		snd_pcm_format_t{SND_PCM_FORMAT_FLOAT64_LE};
		unsigned int channels{1};
		Instrument* instrument{nullptr};

		ALSAOutputStream() = default;
		~ALSAOutputStream();

		void start();
		void stop();
	};
}
