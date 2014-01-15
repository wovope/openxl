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

#ifndef XL_DEMO_H
#define XL_DEMO_H

#include <XL/xl.h>
#include "myImage.h"
#include "myMaterial.h"
#include "mySurface.h"
#include "myObject.h"
#include "myModel.h"

extern char xlDemoOperatorPath[];

extern
void
demoKeyboard(unsigned char key, int x, int y);

extern
void
demoDisplay();

extern
void
demoTimer(int value);

extern
void
demoLoad(int *argc, char **argv);

extern
void
demoUnload();

extern XLid xlDemoOperator;
extern XLreal xlDemoTicks;
extern XLuint xlDemoFrames;
extern XLstring xlDemoTitle;

void
xlDemoKeyboard(unsigned char key, int x, int y);

void
xlDemoReshape(int width, int height);

void
xlDemoDisplay(void);

void
xlDemoTimer(int value);

void
xlDemoLoad(int *argc, char **argv);

void
xlDemoUnload();

int
main(int argc, char **argv);

#endif
