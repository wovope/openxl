/*

**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  
 ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  
**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****

                   Open X Library: Multipurpose C Open Engine

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
