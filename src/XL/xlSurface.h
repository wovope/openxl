#ifndef XL_SURFACE_H
#define XL_SURFACE_H

#include <XL/xlTypes.h>

XLuint
xlGetSurfActionId(const XLstring name);

const XLwchar *
xlGetSurfActionName(XLuint action);

void
xlGetSurfMatrix(XLmatrix *matrix);

void
xlGetSurfMaterial(void);

void
xlSurfBegin(void);

void
xlSurfEnd(void);

void
xlSurfMaterial(void);

void
xlSurfMaterialProperty(void);

#endif
