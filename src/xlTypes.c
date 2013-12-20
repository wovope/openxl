#include "XL/xlTypes.h"
#include "XL/xl.h"

XLstring
	xlXL,
	xlVendor,
	xlRenderer,
	xlVersion,
	xlName,
	xlDescription,
	xlAuthor,
	xlDate,
	xlCopyright,
	xlLicense,
	xlUrl,
	xlEmail,
	xlTool;

XLerror
	xlError = { { 0, } , { 0, } , 0, XL_ERROR_VALUE_NONE};

XLenum
#ifdef XL_DEBUG
	xlLogLevel = XL_LOG_LEVEL_STDOUT;
#else
	xlLogLevel = XL_LOG_LEVEL_NULL;
#endif

XLreal
	xlTimeTotal = XL_REAL(0),
	xlTimeDelta = XL_REAL(0);

XLstore
	xlStores = { { NULL, }, {0, }, 0 };

XLid xlBinds;
XLid xlBuffers;

XLid
	xlMetaHeaders,
	xlMetaDatas,
	xlImages,
	xlFonts,
	xlMaterials,
	xlSurfaces,
	xlObjects,
	xlModels,
	xlParticles,
	xlCameras,
	xlOperators,
	xlViewports,
	xlWindows;

XLdata
	xlDatas[XL_STORE_SIZE];

FT_Library
	xlFontLibrary;

magic_t
	xlMagicCookie,
	xlMagicCompressCookie;
