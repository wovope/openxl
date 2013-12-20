#ifndef XL_OBJ_PIPELINE_H
#define XL_OBJ_PIPELINE_H

#include "XL/xlTypes.h"

#include "XL/xl.h"

extern XLmatrix *xlMatrixModelView;
extern XLvector *xlVectorS, *xlVectorT;

void
xlObjPipelineBegin(void);

void
xlObjPipelineEnd(void);

void
xlObjPipelineCountEnd(void);

void
xlObjPrimitiveBegin(GLenum prim);

void
xlObjPrimitiveEnd(void);

void
xlObjPrimitiveCountVertexPoint(XLpoint *coord);

void
xlObjTessPrimitiveCountVertexdv(double *data);

void
xlObjPipelineFace(XLuint c, XLuint b, XLuint a);

void
xlObjPrimitiveVertexPoint(XLpoint *coord);

void
xlObjTessPrimitiveVertexdv(double *data);

void
xlPipelineInit(void);

void
xlPipelineFini(void);

#endif
