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
#include "./timers/StepTimer.hpp"
#include "./timers/RealTimeTimer.hpp"
#include "./inputs/QXTRInput.hpp"
#include "./outputs/QXTROutput.hpp"
#include "./effects/VolumeControl.hpp"
#include "./effects/Vibrato.hpp"
#include "DoubleSeconds.hpp"

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
	tones::synthesizers::Additive tone;
	tones::basic::Saw tn;
	timers::StepTimer timer{DoubleSeconds{1.0 / 44100.0}};
	effects::VolumeControl volume_control;
	effects::Vibrato vibrato{new tones::basic::Sin, 3, 0.1};
	Instrument basic_instrument(&tn, &envelope, &timer);

	basic_instrument.single_sample_effects.push_back(&vibrato);
	basic_instrument.whole_sample_effects.push_back(&volume_control);
	volume_control.volume = 0.2;

	tone.set_harmonic(2, 0.3);
	tone.set_harmonic(3, 0.7);
	tone.set_harmonic(7, 0.8);
	
	envelope.arsd = {0.01_ds, 0.02_ds, 0.5, 0.2_ds};

	inputs::QXTRInput input("trt.qxtr", &basic_instrument);
	input.export_to_instrument();

        std::ofstream file("whatever.wav", std::ios::binary | std::ios::out);
        
        constexpr unsigned int size = 1000000;
        constexpr unsigned int channels = 1;
        uint16_t volatile  data[size][channels];

	//for(auto x : basic_instrument.get_all_notes()) 
	//	std::cout << x.frequency << ' ' << x.begin_time.count() << ' ' << x.end_time.count() << ' ' << x.volume << std::endl;
        
	//basic_instrument.play(Note(440, 2_ds, 3_ds, 1));
       	for(int i = 0; i < size; i++)
                for(int j = 0; j < channels; j++) {
			data[i][j] = basic_instrument.callback() * std::numeric_limits<uint16_t>::max() / 2;
			/*
			Instrument::NoteId played_note[3];
			if(i == 200000)
				played_note[0] = basic_instrument.play(Note(440, DoubleSeconds(i / 44100.0), 0_ds));
			if(i == 210000)
				played_note[1] = basic_instrument.play(Note(554.36, DoubleSeconds(i / 44100.0), 0_ds));
			if(i == 220000) 
				played_note[2] = basic_instrument.play(Note(659.225, DoubleSeconds(i / 44100.0), 0_ds));
			
			if(i == 300000)
				basic_instrument.stop_notes(DoubleSeconds(i / 44100.0));
			*/
			++timer;
		}

        write_WAVE(file, data, size, 44100, channels);
}
