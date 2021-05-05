#include "../include/StandardNotes.hpp"

#include <cmath>

namespace standard_notes {

	const Frequency A4{440};

	Frequency get_note_from_A4(int distance_from_A4) { //for C0 it would be -57
		if(distance_from_A4)
			return A4 * std::pow(2.0, distance_from_A4 / 12.0);
		else 
			return A4;
	}

	#define FN(note_name, distance_from_A4) const Frequency note_name{get_note_from_A4(distance_from_A4)}
	#define SM(note_name, second_note_name) const Frequency note_name{second_note_name}

	#ifndef AMERICAN_NOTATION
		#ifndef EUROPEAN_NOTATION
			#define AMERICAN_NOTATION
		#endif
	#endif

	#ifdef AMERICAN_NOTATION

	FN(C0 , -57);
	FN(C0s, -56);
	FN(D0, -55);
	FN(D0s, -54);
	FN(E0, -53);
	FN(F0, -52);
	FN(F0s, -51);
	FN(G0, -50);
	FN(G0s, -49);
	FN(A0, -48);
	FN(A0s, -47);
	FN(B0, -46);
	
	FN(C1 , -45);
	FN(C1s, -44);
	FN(D1, -43);
	FN(D1s, -42);
	FN(E1, -41);
	FN(F1, -40);
	FN(F1s, -39);
	FN(G1, -38);
	FN(G1s, -37);
	FN(A1, -36);
	FN(A1s, -35);
	FN(B1, -34);

	FN(C2 , -33);
	FN(C2s, -32);
	FN(D2, -31);
	FN(D2s, -30);
	FN(E2, -29);
	FN(F2, -28);
	FN(F2s, -27);
	FN(G2, -26);
	FN(G2s, -25);
	FN(A2, -24);
	FN(A2s, -23);
	FN(B2, -22);

	FN(C3 , -21);
	FN(C3s, -20);
	FN(D3, -19);
	FN(D3s, -18);
	FN(E3, -17);
	FN(F3, -16);
	FN(F3s, -15);
	FN(G3, -14);
	FN(G3s, -13);
	FN(A3, -12);
	FN(A3s, -11);
	FN(B3, -10);

	FN(C4 , -9);
	FN(C4s, -8);
	FN(D4, -7);
	FN(D4s, -6);
	FN(E4, -5);
	FN(F4, -4);
	FN(F4s, -3);
	FN(G4, -2);
	FN(G4s, -1);
	FN(A4s, 1);
	FN(B4, 2);

	FN(C5 , 3);
	FN(C5s, 4);
	FN(D5, 5);
	FN(D5s, 6);
	FN(E5, 7);
	FN(F5, 8);
	FN(F5s, 9);
	FN(G5, 10);
	FN(G5s, 11);
	FN(A5, 12);
	FN(A5s, 13);
	FN(B5, 14);

	FN(C6 , 15);
	FN(C6s, 16);
	FN(D6, 17);
	FN(D6s, 18);
	FN(E6, 19);
	FN(F6, 20);
	FN(F6s, 21);
	FN(G6, 22);
	FN(G6s, 23);
	FN(A6, 24);
	FN(A6s, 25);
	FN(B6, 26);

	FN(C7 , 27);
	FN(C7s, 28);
	FN(D7, 29);
	FN(D7s, 30);
	FN(E7, 31);
	FN(F7, 32);
	FN(F7s, 33);
	FN(G7, 34);
	FN(G7s, 35);
	FN(A7, 36);
	FN(A7s, 37);
	FN(B7, 38);

	FN(C8 , 39);
	FN(C8s, 40);
	FN(D8, 41);
	FN(D8s, 42);
	FN(E8, 43);
	FN(F8, 44);
	FN(F8s, 45);
	FN(G8, 46);
	FN(G8s, 47);
	FN(A8, 48);
	FN(A8s, 49);
	FN(B8, 50);

	FN(C9 , 51);
	FN(C9s, 52);
	FN(D9, 53);
	FN(D9s, 54);
	FN(E9, 55);
	FN(F9, 56);
	FN(F9s, 57);
	FN(G9, 58);
	FN(G9s, 59);
	FN(A9, 60);
	FN(A9s, 61);
	FN(B9, 62);

	SM(D0b, C0s);
	SM(E0b, D0s);
	SM(E0s, F0);
	SM(G0b, F0s);
	SM(A0b, G0s);
	SM(B0b, A0s);
	SM(H0s, C1);

	SM(D1b, C1s);
	SM(E1b, D1s);
	SM(E1s, F1);
	SM(G1b, F1s);
	SM(A1b, G1s);
	SM(B1b, A1s);
	SM(H1s, C2);

	SM(D2b, C2s);
	SM(E2b, D2s);
	SM(E2s, F2);
	SM(G2b, F2s);
	SM(A2b, G2s);
	SM(B2b, A2s);
	SM(H2s, C3);

	SM(D3b, C3s);
	SM(E3b, D3s);
	SM(E3s, F3);
	SM(G3b, F3s);
	SM(A3b, G3s);
	SM(B3b, A3s);
	SM(H3s, C4);

	SM(D4b, C4s);
	SM(E4b, D4s);
	SM(E4s, F4);
	SM(G4b, F4s);
	SM(A4b, G4s);
	SM(B4b, A4s);
	SM(H4s, C5);

	SM(D5b, C5s);
	SM(E5b, D5s);
	SM(E5s, F5);
	SM(G5b, F5s);
	SM(A5b, G5s);
	SM(B5b, A5s);
	SM(H5s, C6);

	SM(D6b, C6s);
	SM(E6b, D6s);
	SM(E6s, F6);
	SM(G6b, F6s);
	SM(A6b, G6s);
	SM(B6b, A6s);
	SM(H6s, C7);

	SM(D7b, C7s);
	SM(E7b, D7s);
	SM(E7s, F7);
	SM(G7b, F7s);
	SM(A7b, G7s);
	SM(B7b, A7s);
	SM(H7s, C8);

	SM(D8b, C8s);
	SM(E8b, D8s);
	SM(E8s, F8);
	SM(G8b, F8s);
	SM(A8b, G8s);
	SM(B8b, A8s);
	SM(H8s, C9);

	SM(D9b, C9s);
	SM(E9b, D9s);
	SM(E9s, F9);
	SM(G9b, F9s);
	SM(A9b, G9s);
	SM(B9b, A9s);

	const Frequency midi_notation[128] {8.18, 8.66, 9.18, 9.72, 10.3, 10.91, 11.56, 12.25, 12.98, 13.75, 14.57, 15.43, C0, C0s, D0, D0s, E0, F0, F0s, G0, G0s, A0, A0s, B0, C1, C1s, D1, D1s, E1, F1, F1s, G1, G1s, A1, A1s, B1, C2, C2s, D2, D2s, E2, F2, F2s, G2, G2s, A2, A2s, B2, C3, C3s, D3, D3s, E3, F3, F3s, G3, G3s, A3, A3s, B3, C4, C4s, D4, D4s, E4, F4, F4s, G4, G4s, A4, A4s, B4, C5, C5s, D5, D5s, E5, F5, F5s, G5, G5s, A5, A5s, B5, C6, C6s, D6, D6s, E6, F6, F6s, G6, G6s, A6, A6s, B6, C7, C7s, D7, D7s, E7, F7, F7s, G7, G7s, A7, A7s, B7, C8, C8s, D8, D8s, E8, F8, F8s, G8, G8s, A8, A8s, B8, C9, C9s, D9, D9s, E9, F9, F9s, G9};
}
#endif

#ifdef EUROPEAN_NOTATION
namespace standard_notes {
	FN(C0 , -57);
	FN(C0s, -56);
	FN(D0, -55);
	FN(D0s, -54);
	FN(E0, -53);
	FN(F0, -52);
	FN(F0s, -51);
	FN(G0, -50);
	FN(G0s, -49);
	FN(A0, -48);
	FN(A0s, -47);
	FN(H0, -46);
	
	FN(C1 , -45);
	FN(C1s, -44);
	FN(D1, -43);
	FN(D1s, -42);
	FN(E1, -41);
	FN(F1, -40);
	FN(F1s, -39);
	FN(G1, -38);
	FN(G1s, -37);
	FN(A1, -36);
	FN(A1s, -35);
	FN(H1, -34);

	FN(C2 , -33);
	FN(C2s, -32);
	FN(D2, -31);
	FN(D2s, -30);
	FN(E2, -29);
	FN(F2, -28);
	FN(F2s, -27);
	FN(G2, -26);
	FN(G2s, -25);
	FN(A2, -24);
	FN(A2s, -23);
	FN(H2, -22);

	FN(C3 , -21);
	FN(C3s, -20);
	FN(D3, -19);
	FN(D3s, -18);
	FN(E3, -17);
	FN(F3, -16);
	FN(F3s, -15);
	FN(G3, -14);
	FN(G3s, -13);
	FN(A3, -12);
	FN(A3s, -11);
	FN(H3, -10);

	FN(C4 , -9);
	FN(C4s, -8);
	FN(D4, -7);
	FN(D4s, -6);
	FN(E4, -5);
	FN(F4, -4);
	FN(F4s, -3);
	FN(G4, -2);
	FN(G4s, -1);
	FN(A4s, 1);
	FN(H4, 2);

	FN(C5 , 3);
	FN(C5s, 4);
	FN(D5, 5);
	FN(D5s, 6);
	FN(E5, 7);
	FN(F5, 8);
	FN(F5s, 9);
	FN(G5, 10);
	FN(G5s, 11);
	FN(A5, 12);
	FN(A5s, 13);
	FN(H5, 14);

	FN(C6 , 15);
	FN(C6s, 16);
	FN(D6, 17);
	FN(D6s, 18);
	FN(E6, 19);
	FN(F6, 20);
	FN(F6s, 21);
	FN(G6, 22);
	FN(G6s, 23);
	FN(A6, 24);
	FN(A6s, 25);
	FN(H6, 26);

	FN(C7 , 27);
	FN(C7s, 28);
	FN(D7, 29);
	FN(D7s, 30);
	FN(E7, 31);
	FN(F7, 32);
	FN(F7s, 33);
	FN(G7, 34);
	FN(G7s, 35);
	FN(A7, 36);
	FN(A7s, 37);
	FN(H7, 38);

	FN(C8 , 39);
	FN(C8s, 40);
	FN(D8, 41);
	FN(D8s, 42);
	FN(E8, 43);
	FN(F8, 44);
	FN(F8s, 45);
	FN(G8, 46);
	FN(G8s, 47);
	FN(A8, 48);
	FN(A8s, 49);
	FN(H8, 50);

	FN(C9 , 51);
	FN(C9s, 52);
	FN(D9, 53);
	FN(D9s, 54);
	FN(E9, 55);
	FN(F9, 56);
	FN(F9s, 57);
	FN(G9, 58);
	FN(G9s, 59);
	FN(A9, 60);
	FN(A9s, 61);
	FN(H9, 62);

	SM(D0b, C0s);
	SM(E0b, D0s);
	SM(E0s, F);
	SM(G0b, F0s);
	SM(A0b, G0s);
	SM(B0, A0s);
	SM(B0s, C1);

	SM(D1b, C1s);
	SM(E1b, D1s);
	SM(E1s, F);
	SM(G1b, F1s);
	SM(A1b, G1s);
	SM(B1, A1s);
	SM(B1s, C2);

	SM(D2b, C2s);
	SM(E2b, D2s);
	SM(E2s, F);
	SM(G2b, F2s);
	SM(A2b, G2s);
	SM(B2, A2s);
	SM(B2s, C3);

	SM(D3b, C3s);
	SM(E3b, D3s);
	SM(E3s, F);
	SM(G3b, F3s);
	SM(A3b, G3s);
	SM(B3, A3s);
	SM(B3s, C4);

	SM(D4b, C4s);
	SM(E4b, D4s);
	SM(E4s, F);
	SM(G4b, F4s);
	SM(A4b, G4s);
	SM(B4, A4s);
	SM(B4s, C5);

	SM(D5b, C5s);
	SM(E5b, D5s);
	SM(E5s, F);
	SM(G5b, F5s);
	SM(A5b, G5s);
	SM(B5, A5s);
	SM(B5s, C6);

	SM(D6b, C6s);
	SM(E6b, D6s);
	SM(E6s, F);
	SM(G6b, F6s);
	SM(A6b, G6s);
	SM(B6, A6s);
	SM(B6s, C7);

	SM(D7b, C7s);
	SM(E7b, D7s);
	SM(E7s, F);
	SM(G7b, F7s);
	SM(A7b, G7s);
	SM(B7, A7s);
	SM(B7s, C8);

	SM(D8b, C8s);
	SM(E8b, D8s);
	SM(E8s, F);
	SM(G8b, F8s);
	SM(A8b, G8s);
	SM(B8, A8s);
	SM(B8s, C9);

	SM(D9b, C9s);
	SM(E9b, D9s);
	SM(E9s, F);
	SM(G9b, F9s);
	SM(A9b, G9s);
	SM(H9b, A9s);

	Frequency midi_notation[128] {8.18, 8.66, 9.18, 9.72, 10.3, 10.91, 11.56, 12.25, 12.98, 13.75, 14.57, 15.43, C0, C0s, D0, D0s, E0, F0, F0s, G0, G0s, A0, A0s, B0, C1, C1s, D1, D1s, E1, F1, F1s, G1, G1s, A1, A1s, B1, C2, C2s, D2, D2s, E2, F2, F2s, G2, G2s, A2, A2s, B2, C3, C3s, D3, D3s, E3, F3, F3s, G3, G3s, A3, A3s, B3, C4, C4s, D4, D4s, E4, F4, F4s, G4, G4s, A4, A4s, B4, C5, C5s, D5, D5s, E5, F5, F5s, G5, G5s, A5, A5s, B5, C6, C6s, D6, D6s, E6, F6, F6s, G6, G6s, A6, A6s, B6, C7, C7s, D7, D7s, E7, F7, F7s, G7, G7s, A7, A7s, B7, C8, C8s, D8, D8s, E8, F8, F8s, G8, G8s, A8, A8s, B8, C9, C9s, D9, D9s, E9, F9, F9s, G9};
}
#endif

