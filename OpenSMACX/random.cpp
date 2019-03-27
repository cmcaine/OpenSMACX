/*
 * OpenSMACX - an open source clone of Sid Meier's Alpha Centauri.
 * Copyright (C) 2013-2019 Brendan Casey
 *
 * OpenSMACX is free software: you can redistribute it and / or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenSMACX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenSMACX. If not, see <http://www.gnu.org/licenses/>.
 */
#include "stdafx.h"
#include "random.h"

 /*
 Purpose: Updates seed value. Original code after some convoluted XORs simplified to 'seed = param'. 
          Modified it to XOR old seed with new seed.
 Original Offset: 00625750 
 Return Value: n/a
 Status: Complete
 */
void Random::reseed(DWORD reseedValue) { seed ^= reseedValue; }

/*
Purpose: Get a random value between min and (max - 1)
Original Offset: 00625770
Return Value: Random DWORD value within bounds
Status: Complete
*/
DWORD Random::get(DWORD min, DWORD max) {
	if (min > max) {
		DWORD temp = min;
		min = max;
		max = temp;
	}
	seed = seed * 0x19660D + 0x3C6EF35F;
	return (((max - min) * LOWORD(seed)) >> 16) + min;
}

/*
Purpose: Get a random double value
Original Offset: 006257B0
Return Value: Random double value
Status: Complete
*/
double Random::get() {
	seed = seed * 0x19660D + 0x3C6EF35F;
	DWORD temp = seed & 0x7FFFFF | 0x3F800000; // FPU logic?
	return *reinterpret_cast<double *>(&temp) - 1.0;
}

// global
Random *Rand = (Random *)0x009BB568;

void __cdecl random_rand() { *Rand = *(new Random()); atexit(random_rand_exit); } // 00625700

void __cdecl random_rand_exit() { Rand->~Random(); } // 00625720

void __cdecl random_reseed(DWORD reseedValue) { Rand->reseed(reseedValue); } // 006257E0

DWORD __cdecl random_get() { return Rand->getSeed(); } // 00625800

DWORD __cdecl random(DWORD min, DWORD max) { return Rand->get(min, max); } // 00625810

double __cdecl random() { return Rand->get(); } // 00625850