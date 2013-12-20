#ifndef XL_TEXTURIZER_H
#define XL_TEXTURIZER_H

#include <XL/xlTypes.h>

XLreal
xlTexturizerNone(void);

XLreal
xlTexturizerFull(void);

XLreal
xlTexturizerMiddle(void);

XLreal
xlTexturizerVLine(XLint x, XLint y, XLint pad);

XLreal
xlTexturizerHLine(XLint x, XLint y, XLint pad);

XLreal
xlTexturizerHWideLine(XLint x, XLint y, XLint pad, XLint min, XLint max);

XLreal
xlTexturizerDots(XLint x, XLint y, XLint pad);

XLreal
xlTexturizerSquare(XLint x, XLint y, XLint pad);

XLreal
xlTexturizerWideSquare(XLint x, XLint y, XLint pad, XLint min, XLint max);


XLreal
xlFMin(XLint x);

XLreal 
xlFMax(XLint x);

XLreal
fc(XLint x, XLint y, XLint width);

XLreal
fd(XLint x, XLint y, XLint width);

XLreal
fe(XLint x, XLint y, XLint width, XLint min, XLint max);

XLreal
ff(XLint x, XLint y, XLint width, XLint min, XLint max);

#endif
