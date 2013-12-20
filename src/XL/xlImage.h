#ifndef XL_IMAGE_H
#define XL_IMAGE_H

#include "XL/xlTypes.h"

void
xlImgGenTexture(void);

void
xlImgDeleteTexture(void);

void
xlImgTexture(void);

void
xlImgTex2D(GLint level, GLenum internalformat, GLint border);

void
xlImgTexSub2D(GLint level, GLint xoffset, GLint yoffset);

void
xlImgReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, const XLpath filepath);

void
xlImgScale(XLuint width, XLuint height);

#endif
