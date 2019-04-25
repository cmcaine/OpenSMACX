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
#pragma once
#include "graphicwin.h"
#include "spot.h"

 /*
  * Menu class
  */
class OPENSMACX_API Menu: GraphicWin {
	DWORD proc;
	DWORD field_A18;
	DWORD field_A1C;
	DWORD field_A20;
	DWORD field_A24;
	DWORD field_A28;
	Spot spot;
	DWORD array[15][5];

public:
	Menu() { ; }
	~Menu() { ; }
};