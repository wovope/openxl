#ifndef XL_DRAW_H
#define XL_DRAW_H

#include <XL/xlTypes.h>

//FIXME: move Cull variants to xlGetBoolean(XL_OBJ_CULL)

void
xlGlyphDrawTexture(FT_GlyphSlot glyph);

void
xlGlyphDraw(XLenum mode, XLreal z, FT_GlyphSlot glyph);

void
xlStrDraw(XLenum mode, float depth, const XLstring string);

void
xlObjBegin(void);

void
xlObjEnd(void);

void
xlObjMaterialBegin(void);

void
xlObjMaterialEnd(void);

void
xlObjDrawMaterialCoords(XLenum mode, XLpoint *coords);

void
xlObjDrawMaterial(XLenum mode);

void
xlObjDrawCoords(XLenum mode, XLpoint *coords);

void
xlObjDraw(XLenum mode);

void
xlObjCullDrawMaterial(XLenum mode);

void
xlObjCullDrawCoords(XLenum mode, XLpoint *coords);

void
xlObjCullDraw(XLenum mode);

void
xlObjDrawVerticesMaterial(XLenum mode);

void
xlObjDrawVertices(XLenum mode);

void
xlObjCullDrawVerticesMaterial(XLenum mode);

void
xlObjCullDrawVertices(XLenum mode);

void
xlModDraw(XLenum mode);

void
xlModCullDraw(XLenum mode);

void
xlModDrawVertices(XLenum mode);

void
xlModCullDrawVertices(XLenum mode);

#endif
