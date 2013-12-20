#ifndef XL_PARSER_H
#define XL_PARSER_H

#include <XL/xlTypes.h>

void
xlFileScanAttributeu(XLwchar *buffer, XLwchar *name, XLuint *attribute);

void
xlFileGetName(XLwchar *name, XLfile *stream);

void
xlFilePrintName(XLfile *stream, XLwchar *name);

void
xlFileGetAttributeu(XLwchar *name, XLuint *attribute, XLfile *stream);

void
xlFilePrintAttributeu(XLfile *stream, XLwchar *name, XLuint attribute);

void
xlFileGetAttributef(XLwchar *name, XLreal *attribute, XLfile *stream);

void
xlFilePrintAttributef(XLfile *stream, XLwchar *name, XLreal attribute);

void
xlFileGetAttributeuf(XLwchar *name, XLuint *attributeu, XLreal *attributef, XLfile *stream);

void
xlFilePrintAttributeuf(XLfile *stream, XLwchar *name, XLuint attributeu, XLreal attributef);

void
xlFileGetAttribute3uv(XLwchar *name, XLuint *attribute, XLfile *stream);

void
xlFilePrintAttribute3uv(XLfile *stream, XLwchar *name, XLuint *attribute);

void
xlFileGetAttribute3fv(XLwchar *name, XLreal *attribute, XLfile *stream);

void
xlFilePrintAttribute3fv(XLfile *stream, XLwchar *name, XLreal *attribute);

void
xlFileGetAttribute4fv(XLwchar *name, XLreal *attribute, XLfile *stream);

void
xlFilePrintAttribute4fv(XLfile *stream, XLwchar *name, XLreal *attribute);

void
xlFileGetAttributeRange(XLwchar *name, XLrange *range, XLfile *stream);

void
xlFilePrintAttributeRange(XLfile *stream, XLwchar *name, XLrange *range);

void
xlFileGetAttributeColorRGBv(XLwchar *name, XLcolor *attribute, XLfile *stream);

void
xlFilePrintAttributeColorRGBv(XLfile *stream, XLwchar *name, XLcolor *attribute);

void
xlFileGetAttributeColor(XLwchar *name, XLcolor *attribute, XLfile *stream);

void
xlFilePrintAttributeColor(XLfile *stream, XLwchar *name, XLcolor *attribute);

void
xlFileGetAttributePoint(XLwchar *name, XLpoint *attribute, XLfile *stream);

void
xlFilePrintAttributePoint(XLfile *stream, XLwchar *name, XLpoint *attribute);

void
xlFileGetAttributeVector(XLwchar *name, XLvector *attribute, XLfile *stream);

void
xlFilePrintAttributeVector(XLfile *stream, XLwchar *name, XLvector *attribute);

void
xlFileGetAttributePair(XLwchar *name, XLpair *attribute, XLfile *stream);

void
xlFilePrintAttributePair(XLfile *stream, XLwchar *name, XLpair *attribute);

void
xlFileGetAttribute3Pair(XLwchar *name, XLpair attribute[3], XLfile *stream);

void
xlFilePrintAttribute3Pair(XLfile *stream, XLwchar *name, XLpair attribute[3]);

void
xlFileGetAttributeMatrix(XLwchar *name, XLmatrix *attribute, XLfile *stream);

void
xlFilePrintAttributeMatrix(XLfile *stream, XLwchar *name, XLmatrix *attribute);

void
xlFileGetAttributePath(XLwchar *name, XLchar *attribute, XLfile *stream);

void
xlFilePrintAttributePath(XLfile *stream, XLwchar *name, XLchar *attribute);

void
xlFileGetAttributeString(XLwchar *name, XLwchar *attribute, XLfile *stream);

void
xlFilePrintAttributeString(XLfile *stream, XLwchar *name, XLwchar *attribute);

void
xlMetaHeaderSet(XLmetaheader *metaheader, XLint magic, const XLpath path);

void
xlFileGetMetaHeader(XLmetaheader *metaheader, XLfile *stream);

void
xlFilePrintMetaHeader(XLfile *stream, XLmetaheader *metaheader);

void
xlFileGetMetaData(XLmetadata *metadata, XLfile *stream);

void
xlFilePrintMetaData(XLfile *stream, XLmetadata *metadata);

#endif
