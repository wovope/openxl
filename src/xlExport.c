#include "XL/xlExport.h"
#include "XL/xl.h"

void
xlMetHeadExport(const XLpath filepath)
{
	xlSetError(XL_ERROR_VALUE_UNKNOWN);
}

void
xlMetDatExport(const XLpath filepath)
{
	xlSetError(XL_ERROR_VALUE_UNKNOWN);
}

void
xlMetExport(const XLpath filepath)
{
	xlSetError(XL_ERROR_VALUE_UNKNOWN);
}

void
xlImgExport(const XLpath filepath)
{
	// FIXME: RGBA hardcoded
	XLimage *image = xlGetImage();
	XLmetaheader *metaheader = &image->header.metaheader;
	XLmetadata *metadata = &image->header.metadata;
	MagickWand *mw;
	XLpixel *pixels = xlGetPixelsImage();

	mw = NewMagickWand();
	MagickConstituteImage(mw, image->header.width, image->header.height, "RGBA", Pixel, pixels);
	xlFree(pixels);

	xlMetaHeaderSet(metaheader, XL_IMAGE_METAHEADER_MAGIC, filepath);
	xlStringCopy(metadata->type, L"image");
	xlMagickWandWriteProperty(metadata->name, "name", mw);
	xlMagickWandWriteProperty(metadata->version, "version", mw);
	xlMagickWandWriteProperty(metadata->author, "author", mw);
	xlMagickWandWriteProperty(metadata->date, "date", mw);
	xlMagickWandWriteProperty(metadata->copyright, "copyright", mw);
	xlMagickWandWriteProperty(metadata->license, "license", mw);
	xlMagickWandWriteProperty(metadata->url, "url", mw);
	xlMagickWandWriteProperty(metadata->email, "email", mw);
	xlMagickWandWriteProperty(metadata->tool, "tool", mw);
	xlMagickWandWriteProperty(metadata->comment, "comment", mw);
	xlMagickWandWriteProperty(metadata->xl, "xl", mw);

	MagickWriteImage(mw, filepath);
	DestroyMagickWand(mw);
}

void
xlSndExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlFntExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlMatExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlSurfExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlObjExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlModExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlPartsExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlCamExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlOpExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlVptExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlWinExport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}
