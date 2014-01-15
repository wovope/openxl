#ifndef XL_LOG_H
#define XL_LOG_H

#include <XL/xl.h>

XLint
xlLog(const XLstring template, ...);

void
xlLogFlush(void);

XLint
xlLogOverride(XLenum level, const XLstring template, ...);

void
xlLogOverrideFlush(XLenum level);

void
xlMetHeadLog(void);

void
xlMetDatLog(void);

void
xlMetLog(void);

#define _xlIdLog(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xl ## Id ## Log(void);
		
xlIdForEach(_xlIdLog)

#undef _xlIdLog

#endif
