OBJECTS = ./build/DoubleSeconds.o ./build/Instrument.o ./build/StandardNotes.o ./build/tones/basic.o ./build/tones/synthesizers.o ./build/envelopes/basic.o ./build/envelopes/arsd.o ./build/effects/VolumeControl.o ./build/effects/SynchronizedVibrato.o ./build/effects/UnsynchronizedVibrato.o ./build/effects/SynchronizedTremolo.o ./build/effects/UnsynchronizedTremolo.o ./build/timers/StepTimer.o ./build/timers/RealTimeTimer.o ./build/inputs/QXTRInput.o ./build/inputs/sfmlKeyboardInput.o ./build/inputs/MIDIInput.o ./build/outputs/QXTROutput.o ./build/outputs/ALSAOutputStream.o ./build/outputs/WAVOutput.o

CPPFLAGS = -std=c++17

lib: $(OBJECTS)
	ar rvs libsynth.a $(OBJECTS)

./build/%.o: ./source/%.cpp ./include/%.hpp
	g++ $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

git: libsynth.a
	make clean
	git add .
	git commit
	git push

cc:
	clear
	make lib

clean: 
	rm ./build/*.o
	rm ./build/*/*.o
	rm libsynth.a
