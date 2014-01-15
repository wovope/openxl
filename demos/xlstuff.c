/*

                                  **  ** **  
                                   ****  **  
                                  **  ** ****

               Copyright (C) 2012 - 2014 Juan Manuel Borges Caño

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.

**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  
 ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  
**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****

*/

#include <XL/xl.h>

int
main(int argc, char *argv[])
{
	xlLogBanner();

	XLvector v;

	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(0.0), XL_REAL(0.0));
	xlLog(L"Center " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(0.0), XL_REAL(1));
	xlLog(L"Front " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(0.0), XL_REAL(-1));
	xlLog(L"Back " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(0.0), XL_REAL(0.0));
	xlLog(L"Right " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(0.0), XL_REAL(0.0));
	xlLog(L"Left " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(1), XL_REAL(0.0));
	xlLog(L"Up " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(-1), XL_REAL(0.0));
	xlLog(L"Down " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(0.0), XL_REAL(1));
	xlLog(L"FrontRight " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(0.0), XL_REAL(1));
	xlLog(L"FrontLeft " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(1), XL_REAL(1));
	xlLog(L"FrontUp " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(-1), XL_REAL(1));
	xlLog(L"FrontDown " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(0.0), XL_REAL(-1));
	xlLog(L"BackRight " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(0.0), XL_REAL(-1));
	xlLog(L"BackLeft " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(1), XL_REAL(-1));
	xlLog(L"BackUp " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(-1), XL_REAL(-1));
	xlLog(L"BackDown " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(1), XL_REAL(0.0));
	xlLog(L"RightUp " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(-1), XL_REAL(0.0));
	xlLog(L"RightDown " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(1), XL_REAL(0.0));
	xlLog(L"LeftUp " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(-1), XL_REAL(0.0));
	xlLog(L"LeftDown " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(1), XL_REAL(1));
	xlLog(L"FrontRightUp " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(-1), XL_REAL(1));
	xlLog(L"FrontRightDown " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(1), XL_REAL(1));
	xlLog(L"FrontLeftUp " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(-1), XL_REAL(1));
	xlLog(L"FrontLeftDown " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(1), XL_REAL(-1));
	xlLog(L"BackRightUp " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(-1), XL_REAL(-1));
	xlLog(L"BackRightDown " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(1), XL_REAL(-1));
	xlLog(L"BackLeftUp " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(-1), XL_REAL(-1));
	xlLog(L"BackLeftDown " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));


	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(0.0), XL_REAL(0.0));
	xlLog(L"Origin " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(0.0), XL_REAL(1));
	xlLog(L"North " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(0.0), XL_REAL(-1));
	xlLog(L"South " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(0.0), XL_REAL(0.0));
	xlLog(L"East " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(0.0), XL_REAL(0.0));
	xlLog(L"West " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(1), XL_REAL(0.0));
	xlLog(L"Sky " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(-1), XL_REAL(0.0));
	xlLog(L"Ground " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(0.0), XL_REAL(1));
	xlLog(L"NorthEast " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(0.0), XL_REAL(1));
	xlLog(L"NorthWest " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(1), XL_REAL(1));
	xlLog(L"NorthSky " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(-1), XL_REAL(1));
	xlLog(L"NorthGround " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(0.0), XL_REAL(-1));
	xlLog(L"SouthEast " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(0.0), XL_REAL(-1));
	xlLog(L"SouthWest " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(1), XL_REAL(-1));
	xlLog(L"SouthSky " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(0.0), XL_REAL(-1), XL_REAL(-1));
	xlLog(L"SouthGround " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(1), XL_REAL(0.0));
	xlLog(L"EastSky " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(-1), XL_REAL(0.0));
	xlLog(L"EastGround " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(1), XL_REAL(0.0));
	xlLog(L"WestSky " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(-1), XL_REAL(0.0));
	xlLog(L"WestGround " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(1), XL_REAL(1));
	xlLog(L"NorthEastSky " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(-1), XL_REAL(1));
	xlLog(L"NorthEastGround " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(1), XL_REAL(1));
	xlLog(L"NorthWestSky " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(-1), XL_REAL(1));
	xlLog(L"NorthWestGround " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(1), XL_REAL(-1));
	xlLog(L"SouthEastSky " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(1), XL_REAL(-1), XL_REAL(-1));
	xlLog(L"SouthEastGround " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(1.0), XL_REAL(-1));
	xlLog(L"SouthWestSky " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));
	xlVectorAssignReals(&v, XL_REAL(-1), XL_REAL(-1), XL_REAL(-1));
	xlLog(L"SouthWestGround " XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(&v));

	return EXIT_SUCCESS;
}
