#include "XL/xlParser.h"
#include "XL/xl.h"

void
xlFileScanAttributeu(XLwchar *buffer, XLwchar *name, XLuint *attribute)
{
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%i", attribute);
}

void
xlFileGetName(XLwchar *name, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
}

void
xlFilePrintName(XLfile *stream, XLwchar *name)
{
	xlFilePrintStringFormatted(stream, L"%ls\n", name);
}

void
xlFileGetAttributeu(XLwchar *name, XLuint *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%i", attribute);
}

void
xlFilePrintAttributeu(XLfile *stream, XLwchar *name, XLuint attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %i\n", name, attribute);
}

void
xlFileGetAttributef(XLwchar *name, XLreal *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%f", attribute);
}

void
xlFilePrintAttributef(XLfile *stream, XLwchar *name, XLreal attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %f\n", name, attribute);
}

void
xlFileGetAttributeuf(XLwchar *name, XLuint *attributeu, XLreal *attributef, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%i %f", attributeu, attributef);
}

void
xlFilePrintAttributeuf(XLfile *stream, XLwchar *name, XLuint attributeu, XLreal attributef)
{
	xlFilePrintStringFormatted(stream, L"%ls %i %f\n", name, attributeu, attributef);
}

void
xlFileGetAttribute3uv(XLwchar *name, XLuint *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%i %i %i", &attribute[0], &attribute[1], &attribute[2]);
}

void
xlFilePrintAttribute3uv(XLfile *stream, XLwchar *name, XLuint *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %i %i %i\n", name, attribute[0], attribute[1], attribute[2]);
}

void
xlFileGetAttribute3fv(XLwchar *name, XLreal *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%f %f %f", &attribute[0], &attribute[1], &attribute[2]);
}

void
xlFilePrintAttribute3fv(XLfile *stream, XLwchar *name, XLreal *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %f %f %f\n", name, attribute[0], attribute[1], attribute[2]);
}

void
xlFileGetAttribute4fv(XLwchar *name, XLreal *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%f %f %f %f", &attribute[0], &attribute[1], &attribute[2], &attribute[3]);
}

void
xlFilePrintAttribute4fv(XLfile *stream, XLwchar *name, XLreal *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %f %f %f %f\n", name, attribute[0], attribute[1], attribute[2], attribute[3]);
}

void
xlFileGetAttributeRange(XLwchar *name, XLrange *range, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1 , L"%i %i", &range->start, &range->count);
}

void
xlFilePrintAttributeRange(XLfile *stream, XLwchar *name, XLrange *range)
{
	xlFilePrintStringFormatted(stream, L"%ls %i %i\n", name, range->start, range->count);
}

void
xlFileGetAttributePair(XLwchar *name, XLpair *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%f %f", &XL_PAIR_X(attribute), &XL_PAIR_Y(attribute));
}

void
xlFilePrintAttributePair(XLfile *stream, XLwchar *name, XLpair *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %f %f\n", name, XL_PAIR_X(attribute), XL_PAIR_Y(attribute));
}

void
xlFileGetAttribute3Pair(XLwchar *name, XLpair attribute[3], XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%f %f %f %f %f %f", &XL_PAIR_X(&attribute[0]), &XL_PAIR_Y(&attribute[0]), &XL_PAIR_X(&attribute[1]), &XL_PAIR_Y(&attribute[1]), &XL_PAIR_X(&attribute[2]), &XL_PAIR_Y(&attribute[2]));
}

void
xlFilePrintAttribute3Pair(XLfile *stream, XLwchar *name, XLpair attribute[3])
{
	xlFilePrintStringFormatted(stream, L"%ls %f %f %f %f %f %f\n", name, XL_PAIR_X(&attribute[0]), XL_PAIR_Y(&attribute[0]), XL_PAIR_X(&attribute[1]), XL_PAIR_Y(&attribute[1]), XL_PAIR_X(&attribute[2]), XL_PAIR_Y(&attribute[2]));
}

void
xlFileGetAttributeColorRGBv(XLwchar *name, XLcolor *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%f %f %f", &XL_COLOR_R(attribute), &XL_COLOR_G(attribute), &XL_COLOR_B(attribute));
}

void
xlFilePrintAttributeColorRGBv(XLfile *stream, XLwchar *name, XLcolor *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %f %f %f\n", name, XL_COLOR_R(attribute), XL_COLOR_G(attribute), XL_COLOR_B(attribute));
}

void
xlFileGetAttributeColor(XLwchar *name, XLcolor *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%f %f %f %f", &XL_COLOR_R(attribute), &XL_COLOR_G(attribute), &XL_COLOR_B(attribute), &XL_COLOR_A(attribute)); 
}

void
xlFilePrintAttributeColor(XLfile *stream, XLwchar *name, XLcolor *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %f %f %f %f\n", name, XL_COLOR_R(attribute), XL_COLOR_G(attribute), XL_COLOR_B(attribute), XL_COLOR_A(attribute));
}

void
xlFileGetAttributeSample(XLwchar *name, XLsample *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%i", &attribute);
}

void
xlFilePrintAttributeSample(XLfile *stream, XLwchar *name, XLsample *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %f\n", name, attribute);
}

void
xlFileGetAttributePoint(XLwchar *name, XLpoint *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%f %f %f", &XL_POINT_X(attribute), &XL_POINT_Y(attribute), &XL_POINT_Z(attribute));
}

void
xlFilePrintAttributePoint(XLfile *stream, XLwchar *name, XLpoint *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %f %f %f\n", name, XL_POINT_X(attribute), XL_POINT_Y(attribute), XL_POINT_Z(attribute));
}

void
xlFileGetAttributeVector(XLwchar *name, XLvector *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%f %f %f", &XL_VECTOR_X(attribute), &XL_VECTOR_Y(attribute), &XL_VECTOR_Z(attribute));
}

void
xlFilePrintAttributeVector(XLfile *stream, XLwchar *name, XLvector *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %f %f %f\n", name, XL_VECTOR_X(attribute), XL_VECTOR_Y(attribute), XL_VECTOR_Z(attribute));
}

void
xlFileGetAttributeMatrix(XLwchar *name, XLmatrix *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlStringScanFormatted(buffer + xlStringLength(name) + 1, L"%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &XL_MATRIX_XX(attribute), &XL_MATRIX_YX(attribute), &XL_MATRIX_ZX(attribute), &XL_MATRIX_WX(attribute), &XL_MATRIX_XY(attribute), &XL_MATRIX_YY(attribute), &XL_MATRIX_ZY(attribute), &XL_MATRIX_WY(attribute), &XL_MATRIX_XZ(attribute), &XL_MATRIX_YZ(attribute), &XL_MATRIX_ZZ(attribute), &XL_MATRIX_WZ(attribute), &XL_MATRIX_XW(attribute), &XL_MATRIX_YW(attribute), &XL_MATRIX_ZW(attribute), &XL_MATRIX_WW(attribute));
}

void
xlFilePrintAttributeMatrix(XLfile *stream, XLwchar *name, XLmatrix *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", name, XL_MATRIX_XX(attribute), XL_MATRIX_YX(attribute), XL_MATRIX_ZX(attribute), XL_MATRIX_WX(attribute), XL_MATRIX_XY(attribute), XL_MATRIX_YY(attribute), XL_MATRIX_ZY(attribute), XL_MATRIX_WY(attribute), XL_MATRIX_XZ(attribute), XL_MATRIX_YZ(attribute), XL_MATRIX_ZZ(attribute), XL_MATRIX_WZ(attribute), XL_MATRIX_XW(attribute), XL_MATRIX_YW(attribute), XL_MATRIX_ZW(attribute), XL_MATRIX_WW(attribute));
}

void
xlFileGetAttributePath(XLwchar *name, XLchar *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlMemoryZero(attribute, XL_STRING_SIZE);
	xlPathFromString(attribute, buffer + xlStringLength(name) + 1, xlStringLength(buffer) - (xlStringLength(name) + 1) - 1);
	attribute[xlStringLength(buffer) - (xlStringLength(name) + 1) - 1] = '\0';
}

void
xlFilePrintAttributePath(XLfile *stream, XLwchar *name, XLchar *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %s\n", name, attribute);
}

void
xlFileGetAttributeString(XLwchar *name, XLwchar *attribute, XLfile *stream)
{
	XLstringbuffer buffer;

	xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
	xlMemoryZero(attribute, sizeof(XLwchar) * XL_STRING_SIZE);
	xlStringCappedCopy(attribute, buffer + xlStringLength(name) + 1, xlStringLength(buffer) - (xlStringLength(name) + 1) - 1);
	attribute[xlStringLength(buffer) - (xlStringLength(name) + 1) - 1] = L'\0';
}

void
xlFilePrintAttributeString(XLfile *stream, XLwchar *name, XLwchar *attribute)
{
	xlFilePrintStringFormatted(stream, L"%ls %ls\n", name, attribute);
}

void
xlMetaHeaderSet(XLmetaheader *metaheader, XLint magic, const XLpath path)
{
	metaheader->magic = magic;
	xlPathCopy(metaheader->path, path);
}

void
xlFileGetMetaHeader(XLmetaheader *metaheader, XLfile *stream)
{
	XLstring type;

	xlFileGetAttributeString(L"type", type, stream);
	metaheader->magic = xlGetMagic(type);
}

void
xlFilePrintMetaHeader(XLfile *stream, XLmetaheader *metaheader)
{
	xlFilePrintAttributeString(stream, L"type", xlGetString(metaheader->magic));
}

void
xlFileGetMetaData(XLmetadata *metadata, XLfile *stream)
{
	xlFileGetAttributeString(L"name", metadata->name, stream);
	xlFileGetAttributeString(L"version", metadata->version, stream);
	xlFileGetAttributeString(L"author", metadata->author, stream);
	xlFileGetAttributeString(L"date", metadata->date, stream);
	xlFileGetAttributeString(L"copyright", metadata->copyright, stream);
	xlFileGetAttributeString(L"license", metadata->license, stream);
	xlFileGetAttributeString(L"url", metadata->url, stream);
	xlFileGetAttributeString(L"email", metadata->email, stream);
	xlFileGetAttributeString(L"tool", metadata->tool, stream);
	xlFileGetAttributeString(L"comment", metadata->comment, stream);
	xlFileGetAttributeString(L"xl", metadata->xl, stream);
}

void
xlFilePrintMetaData(XLfile *stream, XLmetadata *metadata)
{
	xlFilePrintAttributeString(stream, L"name", metadata->name);
	xlFilePrintAttributeString(stream, L"version", metadata->version);
	xlFilePrintAttributeString(stream, L"author", metadata->author);
	xlFilePrintAttributeString(stream, L"date", metadata->date);
	xlFilePrintAttributeString(stream, L"copyright", metadata->copyright);
	xlFilePrintAttributeString(stream, L"license", metadata->license);
	xlFilePrintAttributeString(stream, L"url", metadata->url);
	xlFilePrintAttributeString(stream, L"email", metadata->email);
	xlFilePrintAttributeString(stream, L"tool", metadata->tool);
	xlFilePrintAttributeString(stream, L"comment", metadata->comment);
	xlFilePrintAttributeString(stream, L"xl", metadata->xl);
}
