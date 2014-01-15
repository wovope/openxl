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
               Copyright (C) 2012 - 2014 Juan Manuel Borges Caño

**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  
 ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  
**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****

*/

#include "XL/xl.h"
#include "config.h"

static
void
xlInit()
__attribute__((constructor));

static
void
xlFini()
__attribute__((destructor));

void
xlInit()
{
	if(!xlLocaleSet(XL_LOCALE_ALL, "en_US.UTF-8"))
		xlLocaleSet(XL_LOCALE_ALL, "");

	xlStringPrintFormatted(xlVendor, XL_STRING_SIZE, L"%s", PACKAGE_BUGREPORT); 
	xlStringPrintFormatted(xlRenderer, XL_STRING_SIZE, L"%s", PACKAGE_URL); 
	xlStringPrintFormatted(xlVersion, XL_STRING_SIZE, L"%s", PACKAGE_VERSION); 
	xlStringPrintFormatted(xlName, XL_STRING_SIZE, L"%s", PACKAGE_NAME); 
	xlStringPrintFormatted(xlDescription, XL_STRING_SIZE, L"%s", PACKAGE_DESCRIPTION); 
	xlStringPrintFormatted(xlAuthor, XL_STRING_SIZE, L"%s", PACKAGE_AUTHOR); 
	xlStringPrintFormatted(xlDate, XL_STRING_SIZE, L"%s", PACKAGE_DATE); 
	xlStringPrintFormatted(xlCopyright, XL_STRING_SIZE, L"%s", PACKAGE_COPYRIGHT); 
	xlStringPrintFormatted(xlLicense, XL_STRING_SIZE, L"%s", PACKAGE_LICENSE); 
	xlStringPrintFormatted(xlUrl, XL_STRING_SIZE, L"%s", PACKAGE_URL); 
	xlStringPrintFormatted(xlEmail, XL_STRING_SIZE, L"%s", PACKAGE_BUGREPORT); 
	xlStringPrintFormatted(xlTool, XL_STRING_SIZE, L"%s", PACKAGE_TOOL); 
	xlStringCopy(xlXL, L"XL"); 

	xlColorInit();
	xlPairInit();
	xlPointInit();
	xlVectorInit();
	xlMatrixInit();
	xlPipelineInit();

	xlMagicCookie = magic_open(MAGIC_MIME_TYPE);
	magic_load(xlMagicCookie, NULL);
	xlMagicCompressCookie = magic_open(MAGIC_MIME_TYPE | MAGIC_COMPRESS);
	magic_load(xlMagicCompressCookie, NULL);

	xlDataInit();

	xlGenStores(1, &xlBinds);

	xlGenBinds(1, &xlBuffers);

	xlGenStores(1, &xlMetaHeaders);
	xlGenStores(1, &xlMetaDatas);

	MagickWandGenesis();
	xlGenStores(1, &xlImages);

	xlGenStores(1, &xlSounds);

	FT_Init_FreeType(&xlFontLibrary);
	xlGenStores(1, &xlFonts);

	xlGenStores(1, &xlMaterials);
	xlGenStores(1, &xlSurfaces);

	xlGenStores(1, &xlObjects);
	xlGenStores(1, &xlModels);

	xlGenStores(1, &xlParticles);

	xlGenStores(1, &xlCameras);
	xlGenStores(1, &xlOperators);

	xlGenStores(1, &xlViewports);
	xlGenStores(1, &xlWindows);
}

void
xlFini()
{
	xlDeleteStores(1, &xlWindows);
	xlDeleteStores(1, &xlViewports);

	xlDeleteStores(1, &xlOperators);
	xlDeleteStores(1, &xlCameras);

	xlDeleteStores(1, &xlParticles);

	xlDeleteStores(1, &xlModels);
	xlDeleteStores(1, &xlObjects);

	xlDeleteStores(1, &xlSurfaces);
	xlDeleteStores(1, &xlMaterials);

	xlDeleteStores(1, &xlFonts);
	FT_Done_FreeType(xlFontLibrary);

	xlDeleteStores(1, &xlSounds);

	xlDeleteStores(1, &xlImages);
	MagickWandTerminus();

	xlGenStores(1, &xlMetaDatas);
	xlGenStores(1, &xlMetaHeaders);

	xlDeleteBinds(1, &xlBuffers);

	xlDeleteStores(1, &xlBinds);

	xlDataFini();

	magic_close(xlMagicCompressCookie);
	magic_close(xlMagicCookie);

	xlPipelineFini();
	xlMatrixFini();
	xlVectorFini();
	xlPointFini();
	xlColorFini();
	xlPairFini();
}
