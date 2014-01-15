#ifndef XL_GET_H
#define XL_GET_H

#include <XL/xlTypes.h>

XLerror *
xlGetError(void);

XLenum
xlGetLogLevel(void);

void
xlGetBooleanv(XLenum pname, XLboolean *params);

XLboolean
xlGetBoolean(XLenum pname);

void
xlGetIntegerv(XLenum pname, XLint *params);

XLint
xlGetInteger(XLenum pname);

void
xlGetStringv(XLenum name, XLstring *params);

XLwchar *
xlGetString(XLenum name);

void
xlGetPathv(XLenum name, XLpath *params);

XLchar *
xlGetPath(XLenum name);

void
xlGetDoublev(XLenum pname, XLdouble *params);

void
xlGetFloatv(XLenum pname, XLfloat *params);

void
xlGetRealv(XLenum pname, XLreal *params);

XLreal
xlGetReal(XLenum pname);

void
xlGetPairv(XLenum pname, XLpair **params);

XLpair *
xlGetPair(XLenum pname);

void
xlGetColorv(XLenum pname, XLcolor **params);

XLcolor *
xlGetColor(XLenum pname);

void
xlGetPointv(XLenum pname, XLpoint **params);

XLpoint *
xlGetPoint(XLenum pname);

void
xlGetVectorv(XLenum pname, XLvector **params);

XLvector *
xlGetVector(XLenum pname);

void
xlGetMatrixv(XLenum pname, XLmatrix **params);

XLmatrix *
xlGetMatrix(XLenum pname);

void
xlGetPointerv(XLenum pname, void **params);

void *
xlGetPointer(XLenum pname);

XLenum 
xlGetPathType(const XLpath path);

XLenum 
xlGetPathFormat(const XLpath path);

XLenum
xlGetMagic(XLstring type);

XLstore *
xlGetStore(XLenum pname);

XLmetaheader *
xlGetMetaHeader(void);

XLmetadata *
xlGetMetaData(void);

#define _xlGetIdentifier(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	XL ## identifier *\
	xlGet ## Identifier(void);

xlIdForEach(_xlGetIdentifier)

#undef _xlGetIdentifier

XLcolor *
xlGetImgPixels(void);

#endif
