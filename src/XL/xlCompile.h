#ifndef XL_COMPILE_H
#define XL_COMPILE_H

#include <XL/xlTypes.h>

void
xlMetHeadCompile(const XLpath filepath);

void
xlMetDatCompile(const XLpath filepath);

void
xlMetCompile(const XLpath filepath);

void
xlImgCompile(const XLpath filepath);

void
xlFntCompile(const XLpath filepath);

void
xlMatCompile(const XLpath filepath);

void
xlSurfCompile(const XLpath filepath);

void
xlObjCompile(const XLpath filepath);

void
xlModCompile(const XLpath filepath);

void
xlPartsCompile(const XLpath filepath);

void
xlCamCompile(const XLpath filepath);

void
xlOpCompile(const XLpath filepath);

void
xlViewCompile(const XLpath filepath);

void
xlWinCompile(const XLpath filepath);

#endif
