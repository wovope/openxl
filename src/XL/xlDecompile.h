#ifndef XL_DECOMPILE_H
#define XL_DECOMPILE_H

#include <XL/xlTypes.h>

void
xlMetDatDecompile(const XLpath filepath);

void
xlMetDecompile(const XLpath filepath);

void
xlImgDecompile(const XLpath filepath);

void
xlFntDecompile(const XLpath filepath);

void
xlMatDecompile(const XLpath filepath);

void
xlSurfDecompile(const XLpath filepath);

void
xlObjDecompile(const XLpath filepath);

void
xlModDecompile(const XLpath filepath);

void
xlPartsDecompile(const XLpath filepath);

void
xlCamDecompile(const XLpath filepath);

void
xlOpDecompile(const XLpath filepath);

void
xlVptDecompile(const XLpath filepath);

void
xlWinDecompile(const XLpath filepath);

#endif
