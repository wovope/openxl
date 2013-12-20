#ifndef XL_IMPORT_H
#define XL_IMPORT_H

#include "XL/xlTypes.h"

void
xlMetHeadImport(const XLpath filepath);

void
xlMetDatImport(const XLpath filepath);

void
xlMetImport(const XLpath filepath);

void
xlImgImport(const XLpath filepath);

void
xlFntImport(const XLpath filepath);

void
xlMatImport(const XLpath filepath);

void
xlSurfImport(const XLpath filepath);

void
xlObjImport(const XLpath filepath);

void
xlModImport(const XLpath filepath);

void
xlPartsImport(const XLpath filepath);

void
xlCamImport(const XLpath filepath);

void
xlOpImport(const XLpath filepath);

void
xlViewImport(const XLpath filepath);

void
xlWinImport(const XLpath filepath);

void
xlImgPixelGlyph(XLuint w, XLuint h, FT_GlyphSlot glyph);

void
xlImgGlyph(XLreal ymin, XLreal ymax, XLreal width, XLreal height, FT_GlyphSlot glyph);

void
xlImgString(XLenum mode, const XLstring string);

void
xlObjGlyph(XLenum mode, XLreal z, FT_GlyphSlot glyph);

void
xlObjString(XLenum mode, XLreal depth, const XLpath material, const XLstring string);

#endif
