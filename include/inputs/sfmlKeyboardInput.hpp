#pragma once
#include "../Instrument.hpp"

#include <SFML/Window.hpp>

namespace inputs {
	class sfmlKeyboardInput {
	public:
		Instrument::NoteId Z{0}, S{0}, X{0}, D{0}, C{0}, V{0}, G{0}, B{0}, H{0}, N{0}, J{0}, M{0}, Q{0}, n2{0}, W{0}, n3{0}, E{0}, R{0}, n5{0}, T{0}, n6{0}, Y{0}, n7{0}, U{0};
	public:
		Instrument* instrument;

		sfmlKeyboardInput(Instrument* c_instrument = nullptr);

		void update();
	};
}
