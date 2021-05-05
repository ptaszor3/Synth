#include "../../include/outputs/ALSAOutputStream.hpp"

namespace outputs {
	void ALSAOutputStream::check_if_errorus(const int error_code) {
		if(error_code < 0)
			throw WriteError_exception(error_code);
	}

	void ALSAOutputStream::open() {
		check_if_errorus(snd_pcm_open(&stream_handle, device_name, SND_PCM_STREAM_PLAYBACK, 0));

		check_if_errorus(snd_pcm_hw_params_malloc(&hardware_parameters));
		check_if_errorus(snd_pcm_hw_params_any(stream_handle, hardware_parameters));
		check_if_errorus(snd_pcm_hw_params_set_access(stream_handle, hardware_parameters, SND_PCM_ACCESS_RW_INTERLEAVED));
		check_if_errorus(snd_pcm_hw_params_set_format(stream_handle, hardware_parameters, format));
		check_if_errorus(snd_pcm_hw_params_set_rate_near(stream_handle, hardware_parameters, &rate, NULL));
		check_if_errorus(snd_pcm_hw_params_set_channels(stream_handle, hardware_parameters, channels));
		check_if_errorus(snd_pcm_hw_params_set_buffer_size_near(stream_handle, hardware_parameters, &buffer_size));
		check_if_errorus(snd_pcm_hw_params_set_period_size_near(stream_handle, hardware_parameters, &period_size, NULL));
		check_if_errorus(snd_pcm_hw_params(stream_handle, hardware_parameters));

		check_if_errorus(snd_pcm_sw_params_malloc(&software_parameters));
		check_if_errorus(snd_pcm_sw_params_current(stream_handle, software_parameters));
		check_if_errorus(snd_pcm_sw_params_set_start_threshold(stream_handle, software_parameters, buffer_size - period_size));
		check_if_errorus(snd_pcm_sw_params(stream_handle, software_parameters));
		check_if_errorus(snd_pcm_prepare(stream_handle));

		float* initializing_buffer = new float[period_size * 2];
		for(int i = 0; i < period_size * 2; i++) {
			initializing_buffer[i] = 0.0;
		}
		check_if_errorus(snd_pcm_writei(stream_handle, initializing_buffer, period_size * 2 ));
		delete[] initializing_buffer;

		check_if_errorus(snd_pcm_start(stream_handle));

		duration_to_last_write = instrument->timer->get_duration_from_start();
	}

	void ALSAOutputStream::close() {
		check_if_errorus(snd_pcm_drop(stream_handle));
		check_if_errorus(snd_pcm_close(stream_handle));
	}

	void ALSAOutputStream::update() {
		if(std::abs(instrument->timer->get_duration_from_start().count() - duration_to_last_write.count()) > 0.010)
			duration_to_last_write = instrument->timer->get_duration_from_start();
		float* samples = new float[period_size];
		for(int i = 0; i < period_size; i++)
			samples[i] = static_cast<float>(instrument->callback(DoubleSeconds(duration_to_last_write.count() + i * (1.0 / rate))));

		unsigned int period_size_copy = period_size;
		while(period_size_copy > 0) {
			int error_code;
			error_code = snd_pcm_writei(stream_handle, samples, period_size);
			duration_to_last_write += DoubleSeconds(error_code * (1.0 / rate));

			if(error_code == -EAGAIN)
				continue;
			if(error_code < 0) {
				if(error_code == -EPIPE) {
					if(error_code = snd_pcm_prepare(stream_handle) < 0)
						throw WriteError_exception(error_code);
					else if(error_code == -ESTRPIPE) {
						while((error_code = snd_pcm_resume(stream_handle)) == -EAGAIN)
							sleep(1);
						if(error_code < 0) {
							error_code = snd_pcm_prepare(stream_handle);
							if(error_code < 0)
								throw WriteError_exception(error_code);
						}
						break;
					}
				}
				break;
			}

			samples += error_code * channels;
			period_size_copy -= error_code;
		}
	}

	ALSAOutputStream::~ALSAOutputStream() {
		close();
		snd_pcm_hw_params_free(hardware_parameters);
		snd_pcm_sw_params_free(software_parameters);
	}
}
