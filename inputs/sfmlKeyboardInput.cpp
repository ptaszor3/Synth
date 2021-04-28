#include "sfmlKeyboardInput.hpp"
#include "../StandardNotes.hpp"
//#include "../Synth/outputs/QXTROutput.hpp"

#include <iostream>
#warning Iostream is included only temporarly

namespace inputs {
	sfmlKeyboardInput::sfmlKeyboardInput(Instrument* c_instrument) 
	:instrument{c_instrument}{
	}

	void sfmlKeyboardInput::update() {
		/*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
			outputs::QXTROutput output(instrument, "output.qxtr");
			output.export_to_file();
			std::cout << "File has been written to" << std::endl;
		}*/

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
			if(!Z)
				Z = instrument->play(standard_notes::C4);
		}
		else {
			if(Z) {
				instrument->stop(Z);
				Z = 0;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			if(!S)
				S = instrument->play(standard_notes::C4s);
		}
		else {
			if(S) {
				instrument->stop(S);
				S = 0;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
			if(!X)
				X = instrument->play(standard_notes::D4);
		}
		else {
			if(X) {
				instrument->stop(X);
				X = 0;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			if(!D)
				D = instrument->play(standard_notes::D4s);
		}
		else {
			if(D) {
				instrument->stop(D);
				D = 0;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
			if(!C)
				C = instrument->play(standard_notes::E4);
		}
		else {
			if(C) {
				instrument->stop(C);
				C = 0;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V)) {
			if(!V)
				V = instrument->play(standard_notes::F4);
		}
		else {
			if(V) {
				instrument->stop(V);
				V = 0;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)) {
			if(!G)
				G = instrument->play(standard_notes::F4s);
		}
		else {
			if(G) {
				instrument->stop(G);
				G = 0;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {
			if(!B)
				B = instrument->play(standard_notes::G4);
		}
		else {
			if(B) {
				instrument->stop(B);
				B = 0;
			}
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H)) {
			if(!H)
				H = instrument->play(standard_notes::G4s);
		}
		else {
			if(H) {
				instrument->stop(H);
				H = 0;
			}
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {
			if(!N)
				N = instrument->play(standard_notes::A4);
		}
		else {
			if(N) {
				instrument->stop(N);
				N = 0;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)) {
			if(!J)
				J = instrument->play(standard_notes::A4s);
		}
		else {
			if(J) {
				instrument->stop(J);
				J = 0;
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
			if(!M)
				M = instrument->play(standard_notes::B4);
		}
		else {
			if(M) {
				instrument->stop(M);
				M = 0;
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
			if(!Q)
				Q = instrument->play(standard_notes::C5);
		}
		else {
			if(Q) {
				instrument->stop(Q);
				Q = 0;
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
			if(!n2)
				n2 = instrument->play(standard_notes::C5s);
		}
		else {
			if(n2) {
				instrument->stop(n2);
				n2 = 0;
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			if(!W)
				W = instrument->play(standard_notes::D5);
		}
		else {
			if(W) {
				instrument->stop(W);
				W = 0;
			}
		}
				
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) {
			if(!n3)
				n3 = instrument->play(standard_notes::D5s);
		}
		else {
			if(n3) {
				instrument->stop(n3);
				n3 = 0;
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
			if(!E)
				E = instrument->play(standard_notes::E5);
		}
		else {
			if(E) {
				instrument->stop(E);
				E = 0;
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
			if(!R)
				R = instrument->play(standard_notes::F5);
		}
		else {
			if(R) {
				instrument->stop(R);
				R = 0;
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)) {
			if(!n5)
				n5 = instrument->play(standard_notes::F5s);
		}
		else {
			if(n5) {
				instrument->stop(n5);
				n5 = 0;
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) {
			if(!T)
				T = instrument->play(standard_notes::G5);
		}
		else {
			if(T) {
				instrument->stop(T);
				T = 0;
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6)) {
			if(!n6)
				n6 = instrument->play(standard_notes::G5s);
		}
		else {
			if(n6) {
				instrument->stop(n6);
				n6 = 0;
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y)) {
			if(!Y)
				Y = instrument->play(standard_notes::A5);
		}
		else {
			if(Y) {
				instrument->stop(Y);
				Y = 0;
			}
		}
				
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7)) {
			if(!n7)
				n7 = instrument->play(standard_notes::A5s);
		}
		else {
			if(n7) {
				instrument->stop(n7);
				n7 = 0;
			}
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U)) {
			if(!U)
				U = instrument->play(standard_notes::B5);
		}
		else {
			if(U) {
				instrument->stop(U);
				U = 0;
			}
		}

	}
}
