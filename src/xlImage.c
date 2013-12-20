#include "XL/xlImage.h"
#include "XL/xl.h"

/*
void
xlImgGenPixels(const XLpath path)
{
}

void
xlImgDeletePixels(void)
{
}
*/

void
xlImgGenTexture(void)
{
	XLimage *bind = xlGetImage();
	XLpixel *pixels = xlGetPixelsImage();

	glGenTextures(1, &bind->runtime.texture);

	glBindTexture(GL_TEXTURE_2D, bind->runtime.texture);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexImage2D(GL_TEXTURE_2D, 0, xlGetBytesPerPixelFormat(bind->header.bpp), bind->header.width, bind->header.height, 0, xlGetBytesPerPixelFormat(bind->header.bpp), GL_PIXEL, pixels);
	gluBuild2DMipmaps(GL_TEXTURE_2D, xlGetBytesPerPixelFormat(bind->header.bpp), bind->header.width, bind->header.height, xlGetBytesPerPixelFormat(bind->header.bpp), GL_PIXEL, pixels);
	xlFree(pixels);

	glDebug(__FILE__, __LINE__);
}

void
xlImgDeleteTexture(void)
{
	XLimage *bind = xlGetImage();

	glDeleteTextures(1, &bind->runtime.texture);

	glDebug(__FILE__, __LINE__);
}

void
xlImgTexture(void)
{
	XLimage *bind = xlGetImage();

	glBindTexture(GL_TEXTURE_2D, bind->runtime.texture);

	glDebug(__FILE__, __LINE__);
}

void
xlImgTex2D(GLint level, GLenum internalformat, GLint border)
{
	XLimage *bind = xlGetImage();
	XLpixel *pixels = xlGetPixelsImage();

	glTexImage2D(GL_TEXTURE_2D, level, internalformat, bind->header.width, bind->header.height, border, xlGetBytesPerPixelFormat(bind->header.bpp), GL_PIXEL, pixels);
	xlFree(pixels);

	glDebug(__FILE__, __LINE__);
}

void
xlImgTexSub2D(GLint level, GLint xoffset, GLint yoffset)
{
	XLimage *bind = xlGetImage();
	XLpixel *pixels = xlGetPixelsImage();

	glTexSubImage2D(GL_TEXTURE_2D, level , xoffset, yoffset, bind->header.width, bind->header.height, xlGetBytesPerPixelFormat(bind->header.bpp), GL_PIXEL, pixels);
	xlFree(pixels);

	glDebug(__FILE__, __LINE__);
}

void
xlImgReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, const XLpath filepath)
{
	XLimage *bind = xlGetImage();
	XLmetaheader *metaheader = &bind->header.metaheader;
	XLmetadata *metadata = &bind->header.metadata;
	XLpixel *pixels;

	xlMemoryZero(bind, sizeof(XLimage));
	xlMetaHeaderSet(metaheader, XL_IMAGE_METAHEADER_MAGIC, filepath);
	xlStringCopy(metadata->type, L"bind");
	xlStringCopy(metadata->version, xlGetString(XL_VERSION));
	xlStringCopy(metadata->author, xlGetString(XL_AUTHOR));
	xlStringCopy(metadata->date, xlGetString(XL_DATE));
	xlStringCopy(metadata->copyright, xlGetString(XL_COPYRIGHT));
	xlStringCopy(metadata->license, xlGetString(XL_LICENSE));
	xlStringCopy(metadata->url, xlGetString(XL_URL));
	xlStringCopy(metadata->email, xlGetString(XL_EMAIL));
	xlStringCopy(metadata->tool, xlGetString(XL_TOOL));
	xlStringCopy(metadata->comment, L"Captured");
	xlStringCopy(metadata->xl, xlGetString(XL_VERSION));

	pixels = xlMemoryAlloc(bind->header.width * bind->header.height * bind->header.bpp * sizeof(XLpixel));
	glReadPixels(x, y, width, height, format, GL_PIXEL, pixels);
	xlPixelsImage(pixels);
	xlFree(pixels);
}

void
xlImgScale(XLuint width, XLuint height)
{
	XLimage *bind = xlGetImage();
	XLpixel *pixels;
	MagickWand *mw;
	
	mw = NewMagickWand();
	pixels = xlGetPixelsColors(bind->body.pixels, bind->header.width * bind->header.height, bind->header.bpp);
	MagickConstituteImage(mw, bind->header.width, bind->header.height, "RGBA", Pixel, pixels);
	xlFree(pixels);
	xlFree(bind->body.pixels);
	bind->header.width = width; bind->header.height = height;
	MagickScaleImage(mw, bind->header.width, bind->header.height);
	bind->body.pixels = xlAlloc(bind->header.width * bind->header.height * sizeof(XLcolor));
	pixels = xlAlloc(bind->header.width * bind->header.height * bind->header.bpp * sizeof(XLpixel));
	MagickExportImagePixels(mw, 0, 0, bind->header.width, bind->header.height, "RGBA", Pixel, pixels);
	xlPixelsColors(bind->body.pixels, pixels, bind->header.width * bind->header.height, bind->header.bpp);
	xlFree(pixels);
	DestroyMagickWand(mw);

	xlImgLog();
}
