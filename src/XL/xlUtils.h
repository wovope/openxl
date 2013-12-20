#ifndef XL_UTILS_H
#define XL_UTILS_H

#include <XL/xlTypes.h>

GLenum
xlGetBytesPerPixelFormat(XLuint bpp);

XLuint
xlGetFormatBytesPerPixel(GLenum format);

void
xlMagickWandReadProperty(XLstring string, const XLchar *property, MagickWand *mw);

void
xlMagickWandReadDate(XLstring string, const XLchar *property, MagickWand *mw);

void
xlMagickWandWriteProperty(XLstring string, const XLchar *property, MagickWand *mw);

void
xlMagickWandWriteDate(XLstring string, const XLchar *property, MagickWand *mw);

void
xlPathFileName(XLpath filename, const XLpath path);

void
xlRangeLoad(XLrange *range, XLuint start, XLuint count);

void
xlPixelLoad(XLpixel *c, XLreal r, XLreal g, XLreal b, XLreal a);

void
xlPixelsColors(XLcolor *colors, XLpixel *pixels, XLsize count, XLsizei bpp);

XLpixel *
xlGetPixelsColors(XLcolor *colors, XLsize count, XLsizei bpp);

void
xlPixelsImage(XLpixel *pixels);

XLpixel *
xlGetPixelsImage(void);

void
xlVerticesLoad(XLuint *vertices, XLuint a, XLuint b, XLuint c);

void
xlTexCoordsLoad(XLpair *texcoords, XLreal u1, XLreal v1, XLreal u2, XLreal v2, XLreal u3, XLreal v3);

/*
XLfile *
xlFileOpen(const XLchar *path, const XLchar *mode);

XLfile *
xlFileStringOpen(const XLwchar *path, const XLwchar *mode);
*/

#endif
