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

#define _xlIdLog(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xl ## Id ## Log (void) \
	{ \
		XL ## identifier *bind = xlGet ## Identifier(); \
		\
		xlLogMeta(&bind->header.metaheader, &bind->header.metadata); \
		xlLogBind(XL_ ## IDENTIFIER); \
	}

xlIdForEach(_xlIdLog)

#undef _xlIdLog
