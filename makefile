OBJECTS = main.o Instrument.o ./tones/basic.o ./tones/synthesizers.o ./envelopes/basic.o ./envelopes/arsd.o ./effects/VolumeControl.o ./effects/Vibrato.o double_seconds.o ./timers/StepTimer.o ./timers/RealTimeTimer.o ./inputs/QXTRInput.o

CPPFLAGS = -std=c++17

out: $(OBJECTS)
	g++ -o out $(OBJECTS)

main.o: main.cpp
Instrument.o: Instrument.cpp Instrument.hpp Note.hpp Tone.hpp Envelope.hpp
double_seconds.o: double_seconds.cpp double_seconds.hpp

./tones/basic.o: ./tones/basic.cpp ./tones/basic.hpp Note.hpp Tone.hpp
./tones/synthesizers.o: ./tones/synthesizers.cpp ./tones/synthesizers.hpp Note.hpp Tone.hpp

./envelopes/basic.o: ./envelopes/basic.cpp ./envelopes/basic.hpp Note.hpp Envelope.hpp
./envelopes/arsd.o: ./envelopes/arsd.cpp ./envelopes/arsd.hpp Note.hpp Envelope.hpp

./timers/StepTimer.o: ./timers/StepTimer.hpp ./timers/StepTimer.cpp Timer.hpp
./timers/RealTimeTimer.o: ./timers/RealTimeTimer.hpp ./timers/RealTimeTimer.cpp 

./effects/VolumeControl.o: ./effects/VolumeControl.cpp ./effects/VolumeControl.hpp
./effects/Vibrato.o: ./effects/Vibrato.cpp ./effects/Vibrato.hpp

./inputs/QXTRInput.o: ./inputs/QXTRInput.cpp ./inputs/QXTRInput.hpp NoteInput.hpp

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
