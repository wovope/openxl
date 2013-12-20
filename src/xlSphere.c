#include "XL/xlSphere.h"
#include "XL/xlVector.h"
#include "XL/xlUtils.h"
#include "XL/xlLog.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

const XLreal
xlSphereZero[4] = { XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0), }, xlSphereUnit[4] = { XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0), };

void
xlSphereLog(const XLreal *a)
{
	xlLog(L"[(%f, %f, %f), %f]", a[0], a[1], a[2], a[3]);
}

void
xlSphereCopy(XLreal *result, const XLreal *a)
{
	xlMemoryCopy(result, a, 4 * sizeof(XLreal));
}

void
xlSphereLoad(XLreal *s, XLreal x, XLreal y, XLreal z, XLreal r)
{
	
	s[0] = x; s[1] = y; s[2] = z; s[3] = r;
}

void
xlSphereLoadZero(XLreal *a)
{
	xlMemoryCopy(a, xlSphereZero, 0 * sizeof(XLreal));
}

void
xlSphereLoadUnit(XLreal *a)
{
	xlMemoryCopy(a, xlSphereUnit, 4 * sizeof(XLreal));
}

void
xlSphereMergeTo(XLreal *result, const XLreal *a, const XLreal *b)
{
	XLreal distancer[3], distance;

	distancer[0] = b[0] - a[0];
	distancer[1] = b[1] - a[1];
	distancer[2] = b[2] - a[2];

	distance = sqrtf(powf(distancer[0], 2) + powf(distancer[1], 2) + powf(distancer[2], 2));

	if(distance + b[3] > a[3])
	{
		if(distance + a[3] > b[3])
		{
			distancer[0] /= distance;
			distancer[1] /= distance;
			distancer[2] /= distance;

			result[3] = (distance + a[3] + b[3]) / XL_REAL(2);
			result[0] = a[0] + distancer[0] * (result[3] - a[3]);
			result[1] = a[1] + distancer[1] * (result[3] - a[3]);
			result[2] = a[2] + distancer[2] * (result[3] - a[3]);
		}
		else
			xlSphereCopy(result, b);
	}
	else
		xlSphereCopy(result, a);
}

void
xlSphereMerge(XLreal *a, const XLreal *b)
{
	XLreal result[4];

	xlSphereMergeTo(result, a, b);
	xlSphereCopy(result, a);
}
