#include "ALSAOutputStream.hpp"

namespace outputs {
	void ALSAOutputStream::open() {
		snd_pcm_open(&stream_handle, device_name, SND_PCM_STREAM_PLAYBACK, 0);

		snd_pcm_hw_params_malloc(&hardware_parameters);
		snd_pcm_hw_params_any(stream_handle, hardware_parameters);
		snd_pcm_hw_params_set_access(stream_handle, hardware_parameters, SND_PCM_ACCESS_RW_INTERLEAVED);
		snd_pcm_hw_params_set_format(stream_handle, hardware_parameters, format);
		snd_pcm_hw_rate_near(stream_handle, hardware_parameters, &rate, NULL);
		snd_pcm_hw_set_channels(stream_handle, hardware_parameters, channels)
		snd_pcm_hw_params(stream_handle, hardware_parameters);

		snd_pcm_sw_params_malloc(&software_parameters);
		snd_pcm_sw_params_current(stream_handle, software_parameters);
		snd_pcm_sw_params_set_start_treshold(handle, software_parameters, buffer_size - period_size);
		snd_pcm_sw_params_set_avail_min(stream_handle, software_parameters, period_size);
		snd_pcm_sw_params(stream_handle);
		snd_pcm_prepare(stream_handle);

		double* initializing_buffer = new double[buffer_size * 2];
		for(int i = 0; i < buffer_size * 2; i++) {
			initializing_buffer[i] = 0.0;
		}
		snd_pcm_writei(stream_handle, initializing_buffer);

		snd_pcm_start(stream_handle);
	}

	void ALSAOutputStream::close() {
		snd_pcm_drop(stream_handle);
		snd_pcm_close(stream_handle);
	}

	ALSAOutputStream::~ALSAOutputStream() {
		close();
		snd_pcm_hw_params_free(hardware_parameters);
		snd_pcm_sw_params_free(software_parameters);
	}

}
