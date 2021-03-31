OBJECTS = main.o Instrument.o ./tones/basic.o ./tones/synthesizers.o ./envelopes/basic.o ./envelopes/arsd.o

out: $(OBJECTS)
	g++ -o out $(OBJECTS)
main.o: main.cpp
Instrument.o: Instrument.cpp Note.hpp
/tones/basic.o: ./tones/basic.cpp ./tones/basic.hpp Note.hpp Tone.hpp
/tones/synthesizers.o: ./tones/synthesizers.cpp ./tones/synthesizers.hpp Note.hpp Tone.hpp
/envelopes/basic.o: ./envelopes/basic.cpp ./envelopes/basic.hpp Note.hpp Envelope.hpp
/envelopes/arsd.o: ./envelopes/arsd.cpp ./envelopes/arsd.hpp Note.hpp Envelope.hpp

CAR: out
	./out
clean: 
	rm *.o
	rm /*/*.o
