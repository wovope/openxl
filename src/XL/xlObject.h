#ifndef XL_OBJECT_H
#define XL_OBJECT_H

#include <XL/xlTypes.h>

XLuint
xlGetObjMaterialId(const XLstring name);

const XLwchar * 
xlGetObjMaterialName(XLuint material);

XLuint
xlGetObjMaterialSurface(XLuint material);

XLuint
xlGetObjMaterial(XLuint material);

XLuint
xlGetObjTagId(const XLstring name);

const XLwchar * 
xlGetObjTagName(XLuint tag);

const XLmatrix *
xlGetObjTagMatrix(XLuint tag);

const XLreal *
xlGetObjBoundSphere(void);

const XLreal *
xlGetObjBoundDimensions(void);

void
xlGetObjMatrixBoundSphere(XLreal sphere[4]);

const XLmatrix *
xlGetObjMatrix(void);

void
xlObjMatrix(const XLmatrix *matrix);

void
xlObjVertices(void);

void
xlObjMaterial(void);

void
xlObjVerticesCoords(XLpoint *coords);

void
xlObjVertices(void);

#endif
