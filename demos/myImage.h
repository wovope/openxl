#ifndef MY_IMAGE_H
#define MY_IMAGE_H

#include <XL/xl.h>

void
myImage(XLenum mode, const XLpath xlpath, XLint width, XLint height, XLint t);

XLuint
myImgTextilXL(XLenum mode, const XLpath xlpath);

XLuint
myImgWoodXL(XLenum mode, const XLpath xlpath);

XLuint
myImgGrassXL(XLenum mode, const XLpath xlpath);

#endif
