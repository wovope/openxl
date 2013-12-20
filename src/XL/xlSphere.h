#ifndef XL_SPHERE_H
#define XL_SPHERE_H

#include <XL/xlTypes.h>

typedef XLreal
XLsphere[4];

extern const XLreal
xlSphereZero[4], xlSphereUnit[4];

void
xlSphereLog(const XLreal *a);

void
xlSphereCopy(XLreal *result, const XLreal *a);

void
xlSphereLoad(XLreal *a, XLreal x, XLreal y, XLreal z, XLreal r);

void
xlSphereLoadZero(XLreal *a);

void
xlSphereLoadUnit(XLreal *a);

void
xlSphereMergeTo(XLreal *result, const XLreal *a, const XLreal *b);

void
xlSphereMerge(XLreal *a, const XLreal *b);

#endif
