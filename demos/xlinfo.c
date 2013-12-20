/*

**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  
 ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  
**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****

		 Open X Library: Multiple Purpose C Open Engine

                                  **  ** **  
                                   ****  **  
                                  **  ** ****

                   Licensed GPLv3 by Juan Manuel Borges Caño
                  * Homepage <http://code.google.com/p/openxl>
                     * Mail <mailto:juanmabcmail@gmail.com>
                   * Blog <http://juanmabcblog.blogspot.com>
               Copyright (C) 2012 - 2013 Juan Manuel Borges Caño

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
