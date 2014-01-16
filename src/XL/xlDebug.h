#ifndef XL_DEBUG_H
#define XL_DEBUG_H

#include <XL/xlTypes.h>

#ifdef XL_DEBUG

void
glDebug(const XLpath file, XLint line);

void
alDebug(const XLpath file, XLint line);

void
xlDebug(const XLpath file, XLint line);

#else

#define glDebug(a, b)
#define alDebug(a, b)
#define xlDebug(a, b)

#endif

#endif
