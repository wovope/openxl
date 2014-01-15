#ifndef XL_LOAD_H
#define XL_LOAD_H

#include <XL/xlTypes.h>

void
xlMetHeadLoad(const XLpath filepath);

void
xlMetDatLoad(const XLpath filepath);

void
xlMetLoad(const XLpath filepath);

void
xlImgLoad(const XLpath filepath);

void
xlFntLoad(const XLpath filepath);

void
xlMatLoad(const XLpath filepath);

void
xlSurfLoad(const XLpath filepath);

void
xlObjLoad(const XLpath filepath);

void
xlModLoad(const XLpath filepath);

void
xlPartsLoad(const XLpath filepath);

void
xlCamLoad(const XLpath filepath);

void
xlOpLoad(const XLpath filepath);

void
xlVptLoad(const XLpath filepath);

void
xlWinLoad(const XLpath filepath);

#endif
