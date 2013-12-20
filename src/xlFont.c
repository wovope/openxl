#include "XL/xlFont.h"
#include "XL/xl.h"

//FIXME: add xlTexString

#define gop(i) glyph->outline.points[i]
#define goc(i) glyph->outline.contours[i]
#define got(i) glyph->outline.tags[i]
#define FT_CT FT_CURVE_TAG
#define FT_CT_ON FT_CURVE_TAG_ON
#define FT_CT_CONIC FT_CURVE_TAG_CONIC
#define FT_CT_CUBIC FT_CURVE_TAG_CUBIC

void
xlFntGenFace(const XLpath path)
{
	XLfont *bind = xlGetFont();
	XLpathbuffer buffer;

	xlPathPrintFormatted(buffer, XL_PATH_BUFFER_SIZE, "%s" XL_PATH_SEPARATOR "%s", path, bind->body.path);

	if(FT_New_Face(xlFontLibrary, buffer, 0, &bind->runtime.face))
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlFntDeleteFace(void)
{
	XLfont *bind = xlGetFont();

	FT_Done_Face(bind->runtime.face);
}

void
xlFntProperty(void)
{
	XLfont *bind = xlGetFont();
	XLFontProperty *property = &bind->body.properties[bind->runtime.property];

	FT_Set_Pixel_Sizes(bind->runtime.face, property->width, property->height);
}

void
xlStrDetailedSize(const XLstring string, XLreal *ymin, XLreal *ymax, XLreal *width, XLreal *height)
{
	XLfont *bind = xlGetFont();
	const XLwchar *wc;

	for(wc = string, *ymin = *ymax = *width = XL_REAL(0); *wc; *ymin = xlRealMin(*ymin, XL_REAL(bind->runtime.face->glyph->metrics.horiBearingY - bind->runtime.face->glyph->metrics.height)), *ymax = xlRealMax(*ymax, XL_REAL(bind->runtime.face->glyph->metrics.horiBearingY)), *width += XL_REAL(bind->runtime.face->glyph->metrics.horiAdvance), wc++)
		FT_Load_Char(bind->runtime.face, *wc, FT_LOAD_DEFAULT);

	*ymin /= XL_REAL(64);
	*ymax /= XL_REAL(64);
	*width /= XL_REAL(64);
	*height = - xlRealMin(XL_REAL(0), *ymin) + *ymax;
}

void
xlStrSize(const XLstring string, XLreal *width, XLreal *height)
{
	XLreal ymin, ymax;
	xlStrDetailedSize(string, &ymin, &ymax, width, height);
}

void
xlGlyphConicBezier(const FT_Vector *p0, const FT_Vector *p1, const FT_Vector *p2, XLreal t, XLdouble *v) 
{
	v[0] = xlRealQuadBezier(p0->x, p1->x, p2->x, t) / XL_REAL(64);
	v[1] = xlRealQuadBezier(p0->y, p1->y, p2->y, t) / XL_REAL(64);
}

void
xlGlyphCubicBezier(const FT_Vector *p0, const FT_Vector *p1, const FT_Vector *p2, const FT_Vector *p3, XLreal t, XLdouble *v) 
{
	v[0] = xlRealCubicBezier(p0->x, p1->x, p2->x, p3->x, t) / XL_REAL(64);
	v[1] = xlRealCubicBezier(p0->y, p1->y, p2->y, p3->y, t) / XL_REAL(64);
}

//FIXME: add tesselation level here
XLuint
xlGlyphContourCountVertices(FT_GlyphSlot glyph, XLuint ctour)
{
	XLuint vrts, i;
	vrts = 0;
	for(i = (ctour ? goc(ctour - 1) + 1 : 0); i <= (XLuint) goc(ctour); i++)
	{
		if((i == 0 || (ctour && i - (goc(ctour - 1) + 1) == 0)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(goc(ctour))) == FT_CT_ON)
			vrts += 1;
		else if((i == 0 || (ctour && i - (goc(ctour - 1) + 1) == 0)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(goc(ctour))) == FT_CT_CONIC && FT_CT(got(goc(ctour) - 1)) == FT_CT_ON)
			//vrts += 3 + 1;
			vrts += 0 + 1;
		else if((i == 0 || (ctour && i - (goc(ctour - 1) + 1) == 0)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(goc(ctour))) == FT_CT_CONIC && FT_CT(got(goc(ctour) - 1)) == FT_CT_CONIC && FT_CT(got(goc(ctour) - 2)) == FT_CT_ON)
			//vrts += 3 + 1 + 3 + 1;
			vrts += 0 + 1 + 0 + 1;
		else if((i == 0 || (ctour && i - (goc(ctour - 1) + 1) == 0)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(goc(ctour))) == FT_CT_CUBIC && FT_CT(got(goc(ctour) - 1)) == FT_CT_CUBIC && FT_CT(got(goc(ctour) - 2)) == FT_CT_ON)
			//vrts += 4 + 1;
			vrts += 1 + 1;
		else if((i >= 1 || (ctour && i - (goc(ctour - 1) + 1) >= 1)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_ON)
			vrts += 1;
		else if((i == 1 || (ctour && i - (goc(ctour - 1) + 1) == 1)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CONIC && FT_CT(got(goc(ctour))) == FT_CT_ON)
			//vrts += 3 + 1;
			vrts += 0 + 1;
		else if((i == 1 || (ctour && i - (goc(ctour - 1) + 1) == 1)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CONIC && FT_CT(got(goc(ctour))) == FT_CT_CONIC && FT_CT(got(goc(ctour) - 1)) == FT_CT_ON)
			//vrts += 3 + 1 + 3 + 1;
			vrts += 0 + 1 + 0 + 1;
		else if((i == 1 || (ctour && i - (goc(ctour - 1) + 1) == 1)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CUBIC && FT_CT(got(goc(ctour))) == FT_CT_CUBIC && FT_CT(got(goc(ctour) - 1)) == FT_CT_ON)
			//vrts += 4 + 1;
			vrts += 1 + 1;
		else if((i >= 2 || (ctour && i - (goc(ctour - 1) + 1) >= 2)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CONIC && FT_CT(got(i - 2)) == FT_CT_ON)
			//vrts += 3 + 1;
			vrts += 0 + 1;
		else if((i == 2 || (ctour && i - (goc(ctour - 1) + 1) == 2)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CONIC && FT_CT(got(i - 2)) == FT_CT_CONIC && FT_CT(got(goc(ctour))) == FT_CT_ON)
			//vrts += 3 + 1 + 3 + 1;
			vrts += 0 + 1 + 0 + 1;
		else if((i == 2 || (ctour && i - (goc(ctour - 1) + 1) == 2)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CUBIC && FT_CT(got(i - 2)) == FT_CT_CUBIC && FT_CT(got(goc(ctour))) == FT_CT_ON)
			//vrts += 4 + 1;
			vrts += 1 + 1;
		else if((i >= 3 || (ctour && i - (goc(ctour - 1) + 1) >= 3)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CONIC && FT_CT(got(i - 2)) == FT_CT_CONIC && FT_CT(got(i - 3)) == FT_CT_ON)
			//vrts += 3 + 1 + 3 + 1;
			vrts += 0 + 1 + 0 + 1;
		else if((i >= 3 || (ctour && i - (goc(ctour - 1) + 1) >= 3)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CUBIC && FT_CT(got(i - 2)) == FT_CT_CUBIC && FT_CT(got(i - 3)) == FT_CT_ON)
			//vrts += 4 + 1;
			vrts += 1 + 1;
	}
	return vrts;
}

//FIXME: add tesselation level here
void
xlGlyphCreateContours(FT_GlyphSlot glyph, XLuint **vrts, XLdouble ***ctours)
{
	XLuint i, j, vrt;
	*vrts = xlMemoryAlloc(glyph->outline.n_contours * sizeof(XLuint));
	*ctours = xlMemoryAlloc(glyph->outline.n_contours * sizeof(XLdouble *));
	for(j = 0; j < (XLuint) glyph->outline.n_contours; j++)
	{
		(*vrts)[j] = xlGlyphContourCountVertices(glyph, j);
		(*ctours)[j] = xlMemoryAlloc(sizeof(XLdouble) * 3 * (*vrts)[j]);
		xlMemoryZero((*ctours)[j], sizeof(XLdouble) * 3 * (*vrts)[j]);
		vrt = 0;
		for(i = (j ? goc(j - 1) + 1 : 0); i <= (XLuint) goc(j); i++)
		{
			if((i == 0 || (j && i - (goc(j - 1) + 1) == 0)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(goc(j))) == FT_CT_ON)
			{
				// vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i == 0 || (j && i - (goc(j - 1) + 1) == 0)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(goc(j))) == FT_CT_CONIC && FT_CT(got(goc(j) - 1)) == FT_CT_ON)
			{
				// vrt += 3 + 1;
				//xlGlyphConicBezier(&gop(goc(j) - 1), &gop(goc(j)), &gop(i), XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(goc(j) - 1), &gop(goc(j)), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(goc(j) - 1), &gop(goc(j)), &gop(i), XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i == 0 || (j && i - (goc(j - 1) + 1) == 0)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(goc(j))) == FT_CT_CONIC && FT_CT(got(goc(j) - 1)) == FT_CT_CONIC && FT_CT(got(goc(j) - 2)) == FT_CT_ON)
			{
				// vrt += 3 + 1 + 3 + 1;
				FT_Vector mdl;
				mdl.x = (FT_Pos) (gop(goc(j) - 1).x + gop(goc(j)).x) / 2; mdl.y = (FT_Pos) (gop(goc(j) - 1).y + gop(goc(j)).y) / 2;
				//xlGlyphConicBezier(&gop(goc(j) - 2), &gop(goc(j) - 1), &mdl, XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(goc(j) - 2), &gop(goc(j) - 1), &mdl, XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(goc(j) - 2), &gop(goc(j) - 1), &mdl, XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(mdl.x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(mdl.y) / XL_REAL(64); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(goc(j)), &gop(i), XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(goc(j)), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(goc(j)), &gop(i), XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i == 0 || (j && i - (goc(j - 1) + 1) == 0)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(goc(j))) == FT_CT_CUBIC && FT_CT(got(goc(j) - 1)) == FT_CT_CUBIC && FT_CT(got(goc(j) - 2)) == FT_CT_ON)
			{
				// vrt += 4 + 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 2), &gop(goc(j) - 1), &gop(goc(j)), &gop(i), XL_REAL(0.2), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 2), &gop(goc(j) - 1), &gop(goc(j)), &gop(i), XL_REAL(0.3333), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 2), &gop(goc(j) - 1), &gop(goc(j)), &gop(i), XL_REAL(0.4), &(*ctours)[j][vrt * 3]); vrt += 1;
				xlGlyphCubicBezier(&gop(goc(j) - 2), &gop(goc(j) - 1), &gop(goc(j)), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 2), &gop(goc(j) - 1), &gop(goc(j)), &gop(i), XL_REAL(0.6), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 2), &gop(goc(j) - 1), &gop(goc(j)), &gop(i), XL_REAL(0.6666), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 2), &gop(goc(j) - 1), &gop(goc(j)), &gop(i), XL_REAL(0.8), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i >= 1 || (j && i - (goc(j - 1) + 1) >= 1)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_ON)
			{
				//vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i == 1 || (j && i - (goc(j - 1) + 1) == 1)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CONIC && FT_CT(got(goc(j))) == FT_CT_ON)
			{
				// vrt += 3 + 1;
				//xlGlyphConicBezier(&gop(goc(j)), &gop(i - 1), &gop(i), XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(goc(j)), &gop(i - 1), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(goc(j)), &gop(i - 1), &gop(i), XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i == 1 || (j && i - (goc(j - 1) + 1) == 1)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CONIC && FT_CT(got(goc(j))) == FT_CT_CONIC && FT_CT(got(goc(j) - 1)) == FT_CT_ON)
			{
				//vrt += 3 + 1 + 3 + 1;
				FT_Vector mdl;
				mdl.x = (FT_Pos) (gop(goc(j)).x + gop(i - 1).x) / 2; mdl.y = (FT_Pos) (gop(goc(j)).y + gop(i - 1).y) / 2;
				//xlGlyphConicBezier(&gop(goc(j) - 1), &gop(goc(j)), &mdl, XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(goc(j) - 1), &gop(goc(j)), &mdl, XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(goc(j) - 1), &gop(goc(j)), &mdl, XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(mdl.x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(mdl.y) / XL_REAL(64); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(i - 1), &gop(i), XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(i - 1), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(i - 1), &gop(i), XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i == 1 || (j && i - (goc(j - 1) + 1) == 1)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CUBIC && FT_CT(got(goc(j))) == FT_CT_CUBIC && FT_CT(got(goc(j) - 1)) == FT_CT_ON)
			{
				// vrt += 4 + 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 1), &gop(goc(j)), &gop(i - 1), &gop(i), XL_REAL(0.2), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 1), &gop(goc(j)), &gop(i - 1), &gop(i), XL_REAL(0.3333), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 1), &gop(goc(j)), &gop(i - 1), &gop(i), XL_REAL(0.4), &(*ctours)[j][vrt * 3]); vrt += 1;
				xlGlyphCubicBezier(&gop(goc(j) - 1), &gop(goc(j)), &gop(i - 1), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 1), &gop(goc(j)), &gop(i - 1), &gop(i), XL_REAL(0.6), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 1), &gop(goc(j)), &gop(i - 1), &gop(i), XL_REAL(0.6666), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j) - 1), &gop(goc(j)), &gop(i - 1), &gop(i), XL_REAL(0.8), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i >= 2 || (j && i - (goc(j - 1) + 1) >= 2)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CONIC && FT_CT(got(i - 2)) == FT_CT_ON)
			{
				//vrt += 3 + 1;
				//xlGlyphConicBezier(&gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i == 2 || (j && i - (goc(j - 1) + 1) == 2)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CONIC && FT_CT(got(i - 2)) == FT_CT_CONIC && FT_CT(got(goc(j))) == FT_CT_ON)
			{
				//vrt += 3 + 1 + 3 + 1;
				FT_Vector mdl;
				mdl.x = (FT_Pos) (gop(i - 2).x + gop(i - 1).x) / 2; mdl.y = (FT_Pos) (gop(i - 2).y + gop(i - 1).y) / 2;
				//xlGlyphConicBezier(&gop(goc(j)), &gop(i - 2), &mdl, XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(goc(j)), &gop(i - 2), &mdl, XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(goc(j)), &gop(i - 2), &mdl, XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(mdl.x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(mdl.y) / XL_REAL(64); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(i - 1), &gop(i), XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(i - 1), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(i - 1), &gop(i), XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i == 2 || (j && i - (goc(j - 1) + 1) == 2)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CUBIC && FT_CT(got(i - 2)) == FT_CT_CUBIC && FT_CT(got(goc(j))) == FT_CT_ON)
			{
				//vrt += 4 + 1;
				//xlGlyphCubicBezier(&gop(goc(j)), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.2), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j)), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.3333), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j)), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.4), &(*ctours)[j][vrt * 3]); vrt += 1;
				xlGlyphCubicBezier(&gop(goc(j)), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j)), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.6), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j)), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.6666), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(goc(j)), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.8), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i >= 3 || (j && i - (goc(j - 1) + 1) >= 3)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CONIC && FT_CT(got(i - 2)) == FT_CT_CONIC && FT_CT(got(i - 3)) == FT_CT_ON)
			{
				//vrt += 3 + 1 + 3 + 1;
				FT_Vector mdl;
				mdl.x = (FT_Pos) (gop(i - 2).x + gop(i - 1).x) / 2; mdl.y = (FT_Pos) (gop(i - 2).y + gop(i - 1).y) / 2;
				//xlGlyphConicBezier(&gop(i - 3), &gop(i - 2), &mdl, XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(i - 3), &gop(i - 2), &mdl, XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&gop(i - 3), &gop(i - 2), &mdl, XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(mdl.x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(mdl.y) / XL_REAL(64); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(i - 1), &gop(i), XL_REAL(0.25), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(i - 1), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphConicBezier(&mdl, &gop(i - 1), &gop(i), XL_REAL(0.75), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
			else if((i >= 3 || (j && i - (goc(j - 1) + 1) >= 3)) && FT_CT(got(i)) == FT_CT_ON && FT_CT(got(i - 1)) == FT_CT_CUBIC && FT_CT(got(i - 2)) == FT_CT_CUBIC && FT_CT(got(i - 3)) == FT_CT_ON)
			{
				//vrt += 4 + 1;
				//xlGlyphCubicBezier(&gop(i - 3), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.2), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(i - 3), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.3333), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(i - 3), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.4), &(*ctours)[j][vrt * 3]); vrt += 1;
				xlGlyphCubicBezier(&gop(i - 3), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.5), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(i - 3), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.6), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(i - 3), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.6666), &(*ctours)[j][vrt * 3]); vrt += 1;
				//xlGlyphCubicBezier(&gop(i - 3), &gop(i - 2), &gop(i - 1), &gop(i), XL_REAL(0.8), &(*ctours)[j][vrt * 3]); vrt += 1;
				(*ctours)[j][vrt * 3] = XL_REAL(gop(i).x) / XL_REAL(64); (*ctours)[j][vrt * 3 + 1] = XL_REAL(gop(i).y) / XL_REAL(64); vrt += 1;
			}
		}
	}
}

void
xlGlyphFreeContours(FT_GlyphSlot glyph, XLuint **vrts, XLdouble ***ctours)
{
	XLuint i;
	xlFree(*vrts);
	for(i = 0; i < (XLuint) glyph->outline.n_contours; i++)
		xlFree((*ctours)[i]);
	xlFree(*ctours);
}
