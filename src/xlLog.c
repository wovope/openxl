#include "XL/xlLog.h"
#include "XL/xl.h"

XLint
xlLog(const XLstring template, ...)
{
	XLint ret;
	va_list ap;

	va_start(ap, template);
	switch(xlLogLevel)
	{
		case XL_LOG_LEVEL_NULL: default: ret = 0; break;
		case XL_LOG_LEVEL_STDOUT: ret = xlFilePrintStringFormattedVariadic(XL_FILE_STANDARD_OUTPUT, template, ap); break;
		case XL_LOG_LEVEL_STDERR: ret = xlFilePrintStringFormattedVariadic(XL_FILE_STANDARD_ERROR, template, ap); break;
	}
	va_end(ap);

	xlLogFlush();

	return ret;
}

void
xlLogFlush(void)
{
	switch(xlLogLevel)
	{
		case XL_LOG_LEVEL_NULL: default: break;
		case XL_LOG_LEVEL_STDOUT: xlFileFlush(XL_FILE_STANDARD_OUTPUT); break;
		case XL_LOG_LEVEL_STDERR: xlFileFlush(XL_FILE_STANDARD_ERROR); break;
	}
}

XLint
xlLogOverride(XLenum level, const XLstring template, ...)
{
	XLint ret;
	va_list ap;

	va_start(ap, template);
	switch(level)
	{
		case XL_LOG_LEVEL_NULL: default: ret = 0; break;
		case XL_LOG_LEVEL_STDOUT: ret = xlFilePrintStringFormattedVariadic(XL_FILE_STANDARD_OUTPUT, template, ap); break;
		case XL_LOG_LEVEL_STDERR: ret = xlFilePrintStringFormattedVariadic(XL_FILE_STANDARD_ERROR, template, ap); break;
	}
	va_end(ap);

	xlLogOverrideFlush(level);

	return ret;
}

void
xlLogOverrideFlush(XLenum level)
{
	switch(level)
	{
		case XL_LOG_LEVEL_NULL: default: break;
		case XL_LOG_LEVEL_STDOUT: xlFileFlush(XL_FILE_STANDARD_OUTPUT); break;
		case XL_LOG_LEVEL_STDERR: xlFileFlush(XL_FILE_STANDARD_ERROR); break;
	}
}

void
xlMetHeadLog(void)
{
	xlLogBind(XL_METAHEADER);
}

void
xlMetDatLog(void)
{
	xlLogBind(XL_METADATA);
}

void
xlMetLog(void)
{
	xlLogBind(XL_METAHEADER);
	xlLogBind(XL_METADATA);
}

void
xlImgLog(void)
{
	XLimage *bind = xlGetImage();

	xlLogMeta(&bind->header.metaheader, &bind->header.metadata);
	xlLogBind(XL_IMAGE);
}

void
xlMatLog(void)
{
	XLmaterial *bind = xlGetMaterial();

	xlLogMeta(&bind->header.metaheader, &bind->header.metadata);
	xlLogBind(XL_MATERIAL);
}

void
xlSurfLog(void)
{
	XLsurface *bind = xlGetSurface();

	xlLogMeta(&bind->header.metaheader, &bind->header.metadata);
	xlLogBind(XL_SURFACE);
}

void
xlObjLog(void)
{
	XLobject *bind = xlGetObject();

	xlLogMeta(&bind->header.metaheader, &bind->header.metadata);
	xlLogBind(XL_OBJECT);
}

void
xlModLog(void)
{
	XLmodel *bind = xlGetModel();

	xlLogMeta(&bind->header.metaheader, &bind->header.metadata);
	xlLogBind(XL_MODEL);
}

void
xlPartsLog(void)
{
	XLparticles *bind = xlGetParticles();

	xlLogMeta(&bind->header.metaheader, &bind->header.metadata);
	xlLogBind(XL_PARTICLES);
}

void
xlCamLog(void)
{
	XLcamera *bind = xlGetCamera();

	xlLogMeta(&bind->header.metaheader, &bind->header.metadata);
	xlLogBind(XL_CAMERA);
}

void
xlOpLog(void)
{
	XLoperator *bind = xlGetOperator();

	xlLogMeta(&bind->header.metaheader, &bind->header.metadata);
	xlLogBind(XL_OPERATOR);
}

void
xlViewLog(void)
{
	XLviewport *bind = xlGetViewport();

	xlLogMeta(&bind->header.metaheader, &bind->header.metadata);
	xlLogBind(XL_VIEWPORT);
}

void
xlWinLog(void)
{
	XLwindow *bind = xlGetWindow();

	xlLogMeta(&bind->header.metaheader, &bind->header.metadata);
	xlLogBind(XL_WINDOW);
}
