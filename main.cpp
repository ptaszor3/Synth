#include <iostream>
#include <fstream>
#include <stdint.h>
#include <cmath>
#include <limits>

#include "Instrument.hpp"
#include "./tones/synthesizers.hpp"
#include "./tones/basic.hpp"
#include "./envelopes/basic.hpp"
#include "./envelopes/arsd.hpp"
#include "./effects/VolumeControl.hpp"
#include "./effects/Vibrato.hpp"
#include "double_seconds.hpp"

constexpr double pi{3.1415926535897932384626};

template <typename T>
void little_put(std::ostream& file, T toPut) {

        for(int i = 0; i < sizeof(toPut); i++) {

                file.put(static_cast<uint8_t>(toPut & 0xFF));
                toPut >>= 8;
        }
}

template <typename uintx_t>
void write_WAVE(std::ostream& file, uintx_t *data, uint32_t numberOfSamples , uint32_t sampleRate, uint16_t numberOfChannels) {

        uint32_t Subchunk2Size = numberOfSamples * numberOfChannels * sizeof(uintx_t);
        uint32_t Chunksize = Subchunk2Size + 36;
        file << "RIFF";
        little_put(file, static_cast<uint32_t>(Chunksize));
        file << "WAVE";
        file << "fmt ";
        little_put(file, static_cast<uint32_t>(16));
        little_put(file, static_cast<uint16_t>(1));
        little_put(file, numberOfChannels);
        little_put(file, sampleRate);
        little_put(file, static_cast<uint32_t>(sampleRate * numberOfChannels * sizeof(uintx_t)));
        little_put(file, static_cast<uint16_t>(numberOfChannels * sizeof(uintx_t)));
        little_put(file, static_cast<uint16_t>(sizeof(uintx_t) * 8));
        file << "data";
        little_put(file, static_cast<uint32_t>(numberOfSamples * numberOfChannels * sizeof(uintx_t)));
        
        for(int i = 0; i < numberOfSamples; i++)
                for(int j = 0; j < numberOfChannels; j++)
                        little_put(file, data[i][j]);
}

int main() {

	envelopes::arsd::Quadratic envelope;
	tones::basic::Sin tone;
	effects::VolumeControl volume_control;
	//effects::Vibrato vibrato{&tone, 1.0, 20.0};
	Instrument basic_instrument(&tone, &envelope);

	//basic_instrument.single_sample_effects.push_back(&vibrato);
	basic_instrument.whole_sample_effects.push_back(&volume_control);
	volume_control.volume = 0.2;

	envelope.arsd = {0.1_ds, 0.1_ds, 0.5, 5_ds};

        std::ofstream file("whatever.wav", std::ios::binary | std::ios::out);
        
        constexpr unsigned int size = 1000000;
        constexpr unsigned int channels = 1;
        uint16_t volatile  data[size][channels];
        
        for(int i = 0; i < size; i++)
                for(int j = 0; j < channels; j++) {
                        data[i][j] = basic_instrument.callback(double_seconds(i / 44100.0)) * std::numeric_limits<uint16_t>::max() / 2;

			Instrument::NoteId played_note[3];
			if(i == 200000)
				played_note[0] = basic_instrument.play(Note(440, double_seconds(i / 44100.0), 0_ds));
			//if(i == 210000)
				//played_note[1] = basic_instrument.play(Note(554.36, i / 44100.0, 0));
			//if(i == 220000) 
				//played_note[2] = basic_instrument.play(Note(659.225, i / 44100.0, 0));
			
			
			if(i == 300000)
				basic_instrument.stop_notes(double_seconds(i / 44100.0));
		}

        write_WAVE(file, data, size, 44100, channels);
}

