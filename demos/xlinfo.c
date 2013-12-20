/*

                                  **  ** **  
                                   ****  **  
                                  **  ** ****

               Copyright (C) 2012, 2013 Juan Manuel Borges Caño

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
#include "myImage.h"
#include "myMaterial.h"
#include "mySurface.h"
#include "myObject.h"
#include "myModel.h"
#include <config.h>

int
main(int argc, char *argv[])
{
#ifndef XL_DEBUG
	xlSetLogLevel(XL_LOG_LEVEL_STDOUT);
#endif
	xlLogBanner();

	if(argc == 2)
	{
		XLid mh, md;

		xlRandSeed(xlTime(NULL));

		xlDataAdd("data/images/Textil.xl", myImgTextilXL);
		xlDataAdd("data/images/Wood.xl", myImgWoodXL);
		xlDataAdd("data/images/Grass.xl", myImgGrassXL);
		xlDataAdd("data/materials/Test.xl", myMatTestXL);
		xlDataAdd("data/surfaces/Test.xl", mySurfTestXL);
		xlDataAdd("data/objects/Cube.xl", myObjCubeXL);
		xlDataAdd("data/models/Cube.xl", myModCubeXL);

		xlGenMetas(1, &mh, &md);
		xlBindMeta(mh, md);
		xlDataMeta(argv[1]);
		xlMetUnload(),
		xlDeleteMetas(1, &mh, &md);

		xlDatasRemove();

		xlDebug(__FILE__, __LINE__);
	}

	return EXIT_SUCCESS;
}
