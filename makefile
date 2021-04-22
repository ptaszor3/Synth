OBJECTS = main.o Instrument.o ./tones/basic.o ./tones/synthesizers.o ./envelopes/basic.o ./envelopes/arsd.o ./effects/VolumeControl.o ./effects/SynchronizedVibrato.o ./effects/UnsynchronizedVibrato.o ./effects/SynchronizedTremolo.o ./effects/UnsynchronizedTremolo.o DoubleSeconds.o ./timers/StepTimer.o ./timers/RealTimeTimer.o ./inputs/QXTRInput.o ./outputs/QXTROutput.o ./outputs/ALSAOutputStream.o

CPPFLAGS = -std=c++17

out: $(OBJECTS)
	g++ -o out $(OBJECTS) -lasound

main.o: main.cpp
Instrument.o: Instrument.cpp Instrument.hpp Note.hpp Tone.hpp Envelope.hpp
DoubleSeconds.o: DoubleSeconds.cpp DoubleSeconds.hpp

./tones/basic.o: ./tones/basic.cpp ./tones/basic.hpp Note.hpp Tone.hpp
./tones/synthesizers.o: ./tones/synthesizers.cpp ./tones/synthesizers.hpp Note.hpp Tone.hpp

./envelopes/basic.o: ./envelopes/basic.cpp ./envelopes/basic.hpp Note.hpp Envelope.hpp
./envelopes/arsd.o: ./envelopes/arsd.cpp ./envelopes/arsd.hpp Note.hpp Envelope.hpp

./timers/StepTimer.o: ./timers/StepTimer.hpp ./timers/StepTimer.cpp Timer.hpp
./timers/RealTimeTimer.o: ./timers/RealTimeTimer.hpp ./timers/RealTimeTimer.cpp 

./effects/VolumeControl.o: ./effects/VolumeControl.cpp ./effects/VolumeControl.hpp
./effects/SynchronizedVibrato.o: ./effects/SynchronizedVibrato.cpp ./effects/SynchronizedVibrato.hpp
./effects/UnsynchronizedVibrato.o: ./effects/UnsynchronizedVibrato.cpp ./effects/UnsynchronizedVibrato.hpp
./effects/SynchronizedTremolo.o: ./effects/SynchronizedTremolo.cpp ./effects/SynchronizedTremolo.hpp
./effects/UnsynchronizedTremolo.o: ./effects/UnsynchronizedTremolo.cpp ./effects/UnsynchronizedTremolo.hpp

./inputs/QXTRInput.o: ./inputs/QXTRInput.cpp ./inputs/QXTRInput.hpp
./outputs/QXTROutput.o: ./outputs/QXTROutput.cpp ./outputs/QXTROutput.hpp

./outputs/ALSAOutputStream.o: ./outputs/ALSAOutputStream.cpp ./outputs/ALSAOutputStream.hpp

ar: out
	./out

git: out
	make clean
	git add .
	git commit
	git push

cc:
	clear
	make out

clean: 
	rm *.o
	rm ./*/*.o
