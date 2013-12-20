#ifndef XL_FONT_H
#define XL_FONT_H

#include <XL/xlTypes.h>

void
xlFntGenFace(const XLpath path);

void
xlFntDeleteFace(void);

void
xlFntProperty(void);

void
xlStrSize(const XLstring string, XLreal *width, XLreal *height);

void
xlStrDetailedSize(const XLstring string, XLreal *ymin, XLreal *ymax, XLreal *width, XLreal *height);

void
xlGlyphConicBezier(const FT_Vector *p0, const FT_Vector *p1, const FT_Vector *p2, XLreal t, XLdouble *v);

void
xlGlyphCubicBezier(const FT_Vector *p0, const FT_Vector *p1, const FT_Vector *p2, const FT_Vector *p3, XLreal t, XLdouble *v);

XLuint
xlGlyphContourCountVertices(FT_GlyphSlot glyph, XLuint ctour);

void
xlGlyphCreateContours(FT_GlyphSlot glyph, XLuint **vrts, XLdouble ***ctours);

void
xlGlyphFreeContours(FT_GlyphSlot glyph, XLuint **vrts, XLdouble ***ctours);

void
xlStrDraw(XLenum mode, float depth, const XLstring string);

void
xlStrImage(XLenum mode, const XLstring string);

void
xlStrObject(XLenum mode, XLreal depth, const XLpath material, const XLstring string);

#endif
