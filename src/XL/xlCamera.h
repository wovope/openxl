#ifndef XL_CAMERA_H
#define XL_CAMERA_H

#include <XL/xlTypes.h>

void
xlCamPerspective(void);

void
xlCamOrtho(void);

void
xlCamBegin(void);

void
xlCamEnd(void);

void
xlCamProperty(void);

void
xlCamCalcFrustum(void);

XLuint
xlCamFrustumCullPoint(const XLreal *point);

XLuint
xlCamFrustumCullSphere(const XLreal *sphere);

XLuint
xlcameraFrustumCullTriangle(const XLreal *triangle);

XLuint
xlCamFrustumCullCube(const XLreal *cube);

XLuint
xlCamFrustumCullPolygon(const XLreal *points, XLuint npoints);

#endif
