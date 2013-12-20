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

void
xlImgLog(void);

void
xlMatLog(void);

void
xlSurfLog(void);

void
xlObjLog(void);

void
xlModLog(void);

void
xlPartsLog(void);

void
xlCamLog(void);

void
xlOpLog(void);

void
xlViewLog(void);

void
xlWinLog(void);

#endif
