#ifndef XL_SET_H
#define XL_SET_H

#include <XL/xlTypes.h>

void
xlSetErrorPoint(const XLpath file, const XLpath function, XLuint line, XLenum error);

#define xlSetError(e) xlSetErrorPoint(__FILE__, __FUNCTION__, __LINE__, e);

void
xlSetLogLevel(XLenum level);

void
xlSetBooleanv(XLenum pname, XLboolean *params);

void
xlSetBoolean(XLenum pname, XLboolean param);

void
xlSetIntegerv(XLenum pname, XLint *params);

void
xlSetInteger(XLenum pname, XLint param);

void
xlSetStringv(XLenum name, XLstring *params);

void
xlSetString(XLenum pname, XLstring param);

void
xlSetPathv(XLenum name, XLpath *params);

void
xlSetPath(XLenum pname, XLpath param);

void
xlSetDoublev(XLenum pname, XLdouble *params);

void
xlSetFloatv(XLenum pname, XLfloat *params);

void
xlSetRealv(XLenum pname, XLreal *params);

void
xlSetReal(XLenum pname, XLreal param);

void
xlSetPairv(XLenum pname, XLpair **params);

void
xlSetPair(XLenum pname, XLpair *param);

void
xlSetColorv(XLenum pname, XLcolor **params);

void
xlSetColor(XLenum pname, XLcolor *param);

void
xlSetPointv(XLenum pname, XLpoint **params);

void
xlSetPoint(XLenum pname, XLpoint *param);

void
xlSetVectorv(XLenum pname, XLvector **params);

void
xlSetVector(XLenum pname, XLvector *param);

void
xlSetMatrixv(XLenum pname, XLmatrix **params);

void
xlSetMatrix(XLenum pname, XLmatrix *param);

void
xlSetPointerv(XLenum pname, void **params);

void
xlSetPointer(XLenum pname, void *param);

#endif
