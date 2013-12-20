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

#define _xlIdDecompile(e, ts, tp, a) \
	case XL_ ## e ## _METAHEADER_MAGIC: \
	{ \
		XLid id; \
		xlGen ## tp(1, &id); \
		xlBind ## ts(id); \
		xlDataLoad(argv[1]); \
		xl ## a ## Decompile(argv[2]); \
		xl ## a ## Unload(); \
		xlDelete ## tp(1, &id); \
		break; \
	}
int
main(int argc, char **argv)
{
	xlLogBanner();

	xlRandSeed(xlTime(NULL));

	xlDataAdd("data/images/Textil.xl", myImgTextilXL);
	xlDataAdd("data/images/Wood.xl", myImgWoodXL);
	xlDataAdd("data/images/Grass.xl", myImgGrassXL);
	xlDataAdd("data/materials/Test.xl", myMatTestXL);
	xlDataAdd("data/surfaces/Test.xl", mySurfTestXL);
	xlDataAdd("data/objects/Cube.xl", myObjCubeXL);
	xlDataAdd("data/models/Cube.xl", myModCubeXL);

	if(argc == 3)
    	{
		XLenum type;
		XLid mh;

		type = xlGetPathType(argv[1]);
		if(type == XL_DATA_BINARY || type == XL_DATA_PROCESS || type == XL_DATA_EXTERNAL)
		{
			xlGenMetaHeaders(1, &mh);
			xlBindMetaHeader(mh);

			xlDataMetaHeader(argv[1]);

			switch(xlGetInteger(XL_METAHEADER_MAGIC))
			{
				xlIdForEach(_xlIdDecompile)

				default:
					xlSetError(XL_ERROR_VALUE_INVALID_DATA);
					break;
			}

			xlMetHeadUnload();

			xlDeleteMetaHeaders(1, &mh);
		}
		else
			xlSetError(XL_ERROR_VALUE_INVALID_PARAM);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PARAM);

	xlDatasRemove();

	xlDebug(__FILE__, __LINE__);

	return EXIT_SUCCESS;
}

#undef _xlIdDecompile
