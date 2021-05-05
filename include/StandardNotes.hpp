#pragma once

#include "Frequency.hpp"

namespace standard_notes {

	extern const Frequency midi_notation[128];

	#ifndef AMERICAN_NOTATION
		#ifndef EUROPEAN_NOTATION
			#define AMERICAN_NOTATION
		#endif
	#endif

	#ifdef AMERICAN_NOTATION

	extern const Frequency C0;
	extern const Frequency C0s;
	extern const Frequency D0b;
	extern const Frequency D0;
	extern const Frequency D0s;
	extern const Frequency E0b;
	extern const Frequency E0;
	extern const Frequency E0s;;
	extern const Frequency F0;
	extern const Frequency F0s;
	extern const Frequency G0b;
	extern const Frequency G0;
	extern const Frequency G0s;
	extern const Frequency A0b;
	extern const Frequency A0;
	extern const Frequency A0s;
	extern const Frequency B0b;
	extern const Frequency B0;

	extern const Frequency C1;
	extern const Frequency C1s;
	extern const Frequency D1b;
	extern const Frequency D1;
	extern const Frequency D1s;
	extern const Frequency E1b;
	extern const Frequency E1;
	extern const Frequency E1s;
	extern const Frequency F1;
	extern const Frequency F1s;
	extern const Frequency G1b;
	extern const Frequency G1;
	extern const Frequency G1s;
	extern const Frequency A1b;
	extern const Frequency A1;
	extern const Frequency A1s;
	extern const Frequency B1b;
	extern const Frequency B1;

	extern const Frequency C2;
	extern const Frequency C2s;
	extern const Frequency D2b;
	extern const Frequency D2;
	extern const Frequency D2s;
	extern const Frequency E2b;
	extern const Frequency E2;
	extern const Frequency E2s;
	extern const Frequency F2;
	extern const Frequency F2s;
	extern const Frequency G2b;
	extern const Frequency G2;
	extern const Frequency G2s;
	extern const Frequency A2b;
	extern const Frequency A2;
	extern const Frequency A2s;
	extern const Frequency B2b;
	extern const Frequency B2;

	extern const Frequency C3;
	extern const Frequency C3s;
	extern const Frequency D3b;
	extern const Frequency D3;
	extern const Frequency D3s;
	extern const Frequency E3b;
	extern const Frequency E3;
	extern const Frequency E3s;
	extern const Frequency F3;
	extern const Frequency F3s;
	extern const Frequency G3b;
	extern const Frequency G3;
	extern const Frequency G3s;
	extern const Frequency A3b;
	extern const Frequency A3;
	extern const Frequency A3s;
	extern const Frequency B3b;
	extern const Frequency B3;

	extern const Frequency C4;
	extern const Frequency C4s;
	extern const Frequency D4b;
	extern const Frequency D4;
	extern const Frequency D4s;
	extern const Frequency E4b;
	extern const Frequency E4;
	extern const Frequency E4s;
	extern const Frequency F4;
	extern const Frequency F4s;
	extern const Frequency G4b;
	extern const Frequency G4;
	extern const Frequency G4s;
	extern const Frequency A4b;
	extern const Frequency A4;
	extern const Frequency A4s;
	extern const Frequency B4b;
	extern const Frequency B4;

	extern const Frequency C5;
	extern const Frequency C5s;
	extern const Frequency D5b;
	extern const Frequency D5;
	extern const Frequency D5s;
	extern const Frequency E5b;
	extern const Frequency E5;
	extern const Frequency E5s;
	extern const Frequency F5;
	extern const Frequency F5s;
	extern const Frequency G5b;
	extern const Frequency G5;
	extern const Frequency G5s;
	extern const Frequency A5b;
	extern const Frequency A5;
	extern const Frequency A5s;
	extern const Frequency B5b;
	extern const Frequency B5;

	extern const Frequency C6;
	extern const Frequency C6s;
	extern const Frequency D6b;
	extern const Frequency D6;
	extern const Frequency D6s;
	extern const Frequency E6b;
	extern const Frequency E6;
	extern const Frequency E6s;
	extern const Frequency F6;
	extern const Frequency F6s;
	extern const Frequency G6b;
	extern const Frequency G6;
	extern const Frequency G6s;
	extern const Frequency A6b;
	extern const Frequency A6;
	extern const Frequency A6s;
	extern const Frequency B6b;
	extern const Frequency B6;

	extern const Frequency C7;
	extern const Frequency C7s;
	extern const Frequency D7b;
	extern const Frequency D7;
	extern const Frequency D7s;
	extern const Frequency E7b;
	extern const Frequency E7;
	extern const Frequency E7s;
	extern const Frequency F7;
	extern const Frequency F7s;
	extern const Frequency G7b;
	extern const Frequency G7;
	extern const Frequency G7s;
	extern const Frequency A7b;
	extern const Frequency A7;
	extern const Frequency A7s;
	extern const Frequency B7b;
	extern const Frequency B7;

	extern const Frequency C8;
	extern const Frequency C8s;
	extern const Frequency D8b;
	extern const Frequency D8;
	extern const Frequency D8s;
	extern const Frequency E8b;
	extern const Frequency E8;
	extern const Frequency E8s;
	extern const Frequency F8;
	extern const Frequency F8s;
	extern const Frequency G8b;
	extern const Frequency G8;
	extern const Frequency G8s;
	extern const Frequency A8b;
	extern const Frequency A8;
	extern const Frequency A8s;
	extern const Frequency B8b;
	extern const Frequency B8;

	extern const Frequency C9;
	extern const Frequency C9s;
	extern const Frequency D9b;
	extern const Frequency D9;
	extern const Frequency D9s;
	extern const Frequency E9b;
	extern const Frequency E9;
	extern const Frequency E9s;
	extern const Frequency F9;
	extern const Frequency F9s;
	extern const Frequency G9b;
	extern const Frequency G9;
	extern const Frequency G9s;
	extern const Frequency A9b;
	extern const Frequency A9;
	extern const Frequency A9s;
	extern const Frequency B9b;
	extern const Frequency B9;

	#endif
	#ifdef EUROPEAN_NOTATION

	extern const Frequency C0;
	extern const Frequency C0s;
	extern const Frequency D0b;
	extern const Frequency D0;
	extern const Frequency D0s;
	extern const Frequency E0b;
	extern const Frequency E0;
	extern const Frequency E0s;
	extern const Frequency F0;
	extern const Frequency F0s;
	extern const Frequency G0b;
	extern const Frequency G0;
	extern const Frequency G0s;
	extern const Frequency A0b;
	extern const Frequency A0;
	extern const Frequency A0s;
	extern const Frequency B0;
	extern const Frequency H0;

	extern const Frequency C1;
	extern const Frequency C1s;
	extern const Frequency D1b;
	extern const Frequency D1;
	extern const Frequency D1s;
	extern const Frequency E1b;
	extern const Frequency E1;
	extern const Frequency E1s;
	extern const Frequency F1;
	extern const Frequency F1s;
	extern const Frequency G1b;
	extern const Frequency G1;
	extern const Frequency G1s;
	extern const Frequency A1b;
	extern const Frequency A1;
	extern const Frequency A1s;
	extern const Frequency B1;
	extern const Frequency H1;

	extern const Frequency C2;
	extern const Frequency C2s;
	extern const Frequency D2b;
	extern const Frequency D2;
	extern const Frequency D2s;
	extern const Frequency E2b;
	extern const Frequency E2;
	extern const Frequency E2s;
	extern const Frequency F2;
	extern const Frequency F2s;
	extern const Frequency G2b;
	extern const Frequency G2;
	extern const Frequency G2s;
	extern const Frequency A2b;
	extern const Frequency A2;
	extern const Frequency A2s;
	extern const Frequency B2;
	extern const Frequency H2;

	extern const Frequency C3;
	extern const Frequency C3s;
	extern const Frequency D3b;
	extern const Frequency D3;
	extern const Frequency D3s;
	extern const Frequency E3b;
	extern const Frequency E3;
	extern const Frequency E3s;
	extern const Frequency F3;
	extern const Frequency F3s;
	extern const Frequency G3b;
	extern const Frequency G3;
	extern const Frequency G3s;
	extern const Frequency A3b;
	extern const Frequency A3;
	extern const Frequency A3s;
	extern const Frequency B3;
	extern const Frequency H3;

	extern const Frequency C4;
	extern const Frequency C4s;
	extern const Frequency D4b;
	extern const Frequency D4;
	extern const Frequency D4s;
	extern const Frequency E4b;
	extern const Frequency E4;
	extern const Frequency E4s;
	extern const Frequency F4;
	extern const Frequency F4s;
	extern const Frequency G4b;
	extern const Frequency G4;
	extern const Frequency G4s;
	extern const Frequency A4b;
	extern const Frequency A4;
	extern const Frequency A4s;
	extern const Frequency B4;
	extern const Frequency H4;

	extern const Frequency C5;
	extern const Frequency C5s;
	extern const Frequency D5b;
	extern const Frequency D5;
	extern const Frequency D5s;
	extern const Frequency E5b;
	extern const Frequency E5;
	extern const Frequency E5s;
	extern const Frequency F5;
	extern const Frequency F5s;
	extern const Frequency G5b;
	extern const Frequency G5;
	extern const Frequency G5s;
	extern const Frequency A5b;
	extern const Frequency A5;
	extern const Frequency A5s;
	extern const Frequency B5;
	extern const Frequency H5;

	extern const Frequency C6;
	extern const Frequency C6s;
	extern const Frequency D6b;
	extern const Frequency D6;
	extern const Frequency D6s;
	extern const Frequency E6b;
	extern const Frequency E6;
	extern const Frequency E6s;
	extern const Frequency F6;
	extern const Frequency F6s;
	extern const Frequency G6b;
	extern const Frequency G6;
	extern const Frequency G6s;
	extern const Frequency A6b;
	extern const Frequency A6;
	extern const Frequency A6s;
	extern const Frequency B6;
	extern const Frequency H6;

	extern const Frequency C7;
	extern const Frequency C7s;
	extern const Frequency D7b;
	extern const Frequency D7;
	extern const Frequency D7s;
	extern const Frequency E7b;
	extern const Frequency E7;
	extern const Frequency E7s;
	extern const Frequency F7;
	extern const Frequency F7s;
	extern const Frequency G7b;
	extern const Frequency G7;
	extern const Frequency G7s;
	extern const Frequency A7b;
	extern const Frequency A7;
	extern const Frequency A7s;
	extern const Frequency B7;
	extern const Frequency H7;
	
	extern const Frequency C8;
	extern const Frequency C8s;
	extern const Frequency D8b;
	extern const Frequency D8;
	extern const Frequency D8s;
	extern const Frequency E8b;
	extern const Frequency E8;
	extern const Frequency E8s;
	extern const Frequency F8;
	extern const Frequency F8s;
	extern const Frequency G8b;
	extern const Frequency G8;
	extern const Frequency G8s;
	extern const Frequency A8b;
	extern const Frequency A8;
	extern const Frequency A8s;
	extern const Frequency B8;
	extern const Frequency H8;

	extern const Frequency C9;
	extern const Frequency C9s;
	extern const Frequency D9b;
	extern const Frequency D9;
	extern const Frequency D9s;
	extern const Frequency E9b;
	extern const Frequency E9;
	extern const Frequency E9s;
	extern const Frequency F9;
	extern const Frequency F9s;
	extern const Frequency G9b;
	extern const Frequency G9;
	extern const Frequency G9s;
	extern const Frequency A9b;
	extern const Frequency A9;
	extern const Frequency A9s;
	extern const Frequency B9;
	extern const Frequency H9;

	#endif
}
