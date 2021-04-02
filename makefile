OBJECTS = main.o Instrument.o ./tones/basic.o ./tones/synthesizers.o ./envelopes/basic.o ./envelopes/arsd.o ./effects/VolumeControl.o ./effects/Vibrato.o

out: $(OBJECTS)
	g++ -o out $(OBJECTS)

main.o: main.cpp
Instrument.o: Instrument.cpp Instrument.hpp Note.hpp Tone.hpp Envelope.hpp

./tones/basic.o: ./tones/basic.cpp ./tones/basic.hpp Note.hpp Tone.hpp
./tones/synthesizers.o: ./tones/synthesizers.cpp ./tones/synthesizers.hpp Note.hpp Tone.hpp

./envelopes/basic.o: ./envelopes/basic.cpp ./envelopes/basic.hpp Note.hpp Envelope.hpp
./envelopes/arsd.o: ./envelopes/arsd.cpp ./envelopes/arsd.hpp Note.hpp Envelope.hpp

./effects/VolumeControl.o: ./effects/VolumeControl.cpp ./effects/VolumeControl.hpp
./effects/Vibrato.o: ./effects/Vibrato.cpp ./effects/Vibrato.hpp

andrun: out
	./out

git: out
	make clean
	git add .
	git commit
	git push

clean: 
	rm *.o
	rm ./*/*.o
