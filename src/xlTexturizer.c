#include "XL/xlTexturizer.h"
#include "XL/xl.h"

XLreal
xlTexturizerNone(void)
{
	return XL_REAL(0);
}

XLreal
xlTexturizerFull(void)
{
	return XL_REAL(1);
}

XLreal
xlTexturizerMiddle(void)
{
	return XL_REAL(0.5);
}

XLreal
xlTexturizerVLine(XLint x, XLint y, XLint pad)
{
	return (x % pad) ? xlTexturizerNone() : xlTexturizerFull();
}

XLreal
xlTexturizerHLine(XLint x, XLint y, XLint pad)
{
	return (y % pad) ? xlTexturizerNone() : xlTexturizerFull();
}

XLreal
xlTexturizerHWideLine(XLint x, XLint y, XLint pad, XLint min, XLint max)
{
	return (min <= (x % pad) && (x % pad) <= max) ? xlTexturizerNone() : xlTexturizerFull();
}

XLreal
xlTexturizerDots(XLint x, XLint y, XLint pad)
{
	return (x % pad) && (y % pad) ? xlTexturizerNone() : xlTexturizerFull();
}

XLreal
xlTexturizerSquare(XLint x, XLint y, XLint pad)
{
	return (x % pad) || (y % pad) ? xlTexturizerNone() : xlTexturizerFull();
}

XLreal
xlTexturizerWideSquare(XLint x, XLint y, XLint pad, XLint min, XLint max)
{
	return ((min <= (x % pad) && (x % pad) <= max) || (min <= (y % pad) && (y % pad) <= max)) ? xlTexturizerNone() : xlTexturizerFull();
}


XLreal
xlFMin(XLint x)
{
	return XL_REAL(0);
}

XLreal 
xlFMax(XLint x)
{
	return XL_REAL(1);
}

XLreal
fc(XLint x, XLint y, XLint width)
{
	return (x % width) ? xlFMin(x) : xlFMax(x);
}

XLreal
fd(XLint x, XLint y, XLint width)
{
	return (x % width) && (y % width) ? xlFMin(x) : xlFMax(x);
}

XLreal
fe(XLint x, XLint y, XLint width, XLint min, XLint max)
{
	return (min <= (x % width) && (x % width) <= max) ? xlFMin(x) : xlFMax(x);
}

XLreal
ff(XLint x, XLint y, XLint width, XLint min, XLint max)
{
	return ((min <= (x % width) && (x % width) <= max) || (min <= (y % width) && (y % width) <= max)) ? xlFMin(x) : xlFMax(x);
}
