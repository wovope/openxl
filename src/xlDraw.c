#include "XL/xlFont.h"
#include "XL/xl.h"

void
xlTexGlyph2D(XLuint w, XLuint h, FT_GlyphSlot glyph)
{
	GLubyte *pixels;
	XLuint i, j;

	pixels = xlMemoryAlloc(w * h * 2 * sizeof(GLubyte));
	xlMemoryZero(pixels, w * h * 2 * sizeof(GLubyte));

	for(j = 0; j < (XLuint) glyph->bitmap.rows; j++)
		for(i = 0; i < (XLuint) glyph->bitmap.width; i++)
			pixels[(j * w + i) * 2] = pixels[(j * w + i) * 2 + 1] = glyph->bitmap.buffer[(glyph->bitmap.rows - j - 1) * glyph->bitmap.pitch + i];

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, pixels);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, w, h, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, pixels);
	xlFree(pixels);
}

void
xlGlyphDrawTexture(FT_GlyphSlot glyph)
{
	XLuint w, h;
	XLreal tw, th;

	w = xlRealNextTwoPower(XL_REAL(glyph->bitmap.width));
	h = xlRealNextTwoPower(XL_REAL(glyph->bitmap.rows));

	xlTexGlyph2D(w, h, glyph);

	tw = XL_REAL(glyph->bitmap.width) / XL_REAL(w);
	th = XL_REAL(glyph->bitmap.rows) / XL_REAL(h);

	w = glyph->metrics.width / XL_REAL(64);
	h = glyph->metrics.height / XL_REAL(64);

	glPushMatrix();
	//FIXME: ymin here?
	glTranslatef(XL_REAL(glyph->metrics.horiBearingX) / XL_REAL(64), - XL_REAL((glyph->metrics.height - glyph->metrics.horiBearingY)) / XL_REAL(64), XL_REAL(0));

	glBegin(GL_QUADS);
	glTexCoord2f(XL_REAL(0), XL_REAL(0)); glVertex2i(0, 0);
	glTexCoord2f(tw, XL_REAL(0)); glVertex2i(w, 0);
	glTexCoord2f(tw, th); glVertex2i(w, h);
	glTexCoord2f(XL_REAL(0), th); glVertex2i(0, h);
	glEnd();

	glPopMatrix();
}

void
xlGlyphDraw(XLenum mode, XLreal z, FT_GlyphSlot glyph)
{
	XLuint *vrts;
	XLdouble **ctours;
	GLUtesselator *tess = NULL;
	XLuint i, j;

	xlGlyphCreateContours(glyph, &vrts, &ctours);

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_FILL || mode == XL_RENDER_WIRE || mode == XL_RENDER_OUTLINES || mode == XL_RENDER_OUTLINE)
	{
		tess = gluNewTess();
		gluTessCallback(tess, GLU_TESS_VERTEX, (_GLUfuncptr) &glVertex3dv);
		gluTessCallback(tess, GLU_TESS_BEGIN, (_GLUfuncptr) &glBegin);
		gluTessCallback(tess, GLU_TESS_END, (_GLUfuncptr) &glEnd);

		if(mode == XL_RENDER_WIRE || mode == XL_RENDER_OUTLINES || mode == XL_RENDER_OUTLINE)
			gluTessProperty(tess, GLU_TESS_BOUNDARY_ONLY, GL_TRUE);
	}

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_WIRE || mode == XL_RENDER_OUTLINES)
	{
		glPushMatrix();
		glTranslatef(XL_REAL(0), XL_REAL(0), - XL_REAL(z));
		gluTessNormal(tess, 0.0, 0.0, -1.0);
		gluTessBeginPolygon(tess, NULL);
		for(j = 0; j < (XLuint) glyph->outline.n_contours; j++)
		{
			gluTessBeginContour(tess);
			for(i = 0; i < vrts[j]; i++)
				gluTessVertex(tess, &ctours[j][i * 3], &ctours[j][i * 3]);
			gluTessEndContour(tess);
		}
		gluTessEndPolygon(tess);
		glPopMatrix();
	}

	if(mode == XL_RENDER_MODERN || mode == XL_RENDER_SOLID || mode == XL_RENDER_WIRE)
	{
		for(j = 0; j < (XLuint) glyph->outline.n_contours; j++)
		{
			if(mode == XL_RENDER_MODERN || mode == XL_RENDER_SOLID)
				glBegin(GL_TRIANGLE_STRIP);
			else 
				glBegin(GL_LINES);
			for(i = 0; i < vrts[j]; i++)
			{
				glVertex3d(ctours[j][i * 3], ctours[j][i * 3 + 1], - (XLdouble) z);
				glVertex3d(ctours[j][i * 3], ctours[j][i * 3 + 1], 0.0);
			}
			if(mode == XL_RENDER_MODERN || mode == XL_RENDER_SOLID)
			{
				glVertex3d(ctours[j][0 * 3], ctours[j][0 * 3 + 1], - (XLdouble) z);
				glVertex3d(ctours[j][0 * 3], ctours[j][0 * 3 + 1], 0.0);
			}
			glEnd();
		}
	}

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_FILL || mode == XL_RENDER_WIRE || mode == XL_RENDER_OUTLINES || mode == XL_RENDER_OUTLINE)
	{
		gluTessNormal(tess, 0.0, 0.0, 1.0);
		gluTessBeginPolygon(tess, NULL);
		for(j = 0; j < (XLuint) glyph->outline.n_contours; j++)
		{
			gluTessBeginContour(tess);
			for(i = 0; i < vrts[j]; i++)
				gluTessVertex(tess, &ctours[j][i * 3], &ctours[j][i * 3]);
			gluTessEndContour(tess);
		}
		gluTessEndPolygon(tess);

	}

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_FILL || mode == XL_RENDER_WIRE || mode == XL_RENDER_OUTLINES || mode == XL_RENDER_OUTLINE)
	{
		gluDeleteTess(tess);
	}

	xlGlyphFreeContours(glyph, &vrts, &ctours);
}

void
xlStrDraw(XLenum mode, XLreal depth, const XLstring string)
{
	XLfont *font = xlGetFont();
	const XLwchar *wc;

	glPushMatrix();
	for(wc = string; *wc; wc++)
	{
		switch(mode)
		{
			case XL_RENDER_TEXTURE:
				FT_Load_Char(font->runtime.face, *wc, FT_LOAD_RENDER);
				xlGlyphDrawTexture(font->runtime.face->glyph);
				break;
			case XL_RENDER_OUTLINE:
			case XL_RENDER_OUTLINES:
			case XL_RENDER_WIRE:
			case XL_RENDER_FILL:
			case XL_RENDER_MODERN:
			case XL_RENDER_SOLID:
				FT_Load_Char(font->runtime.face, *wc, FT_LOAD_DEFAULT);
				xlGlyphDraw(mode, depth, font->runtime.face->glyph);
				break;
			default:
				FT_Load_Char(font->runtime.face, *wc, FT_LOAD_DEFAULT);
				break;
		}
		glTranslatef(XL_REAL(font->runtime.face->glyph->metrics.horiAdvance) / XL_REAL(64), XL_REAL(0), XL_REAL(0));
	}
	glPopMatrix();
}

void
xlObjBegin(void)
{
	XLobject *bind = xlGetObject();

	glPushMatrix();
	glMultMatrixf(XL_MATRIX_ARRAY(&bind->runtime.matrix));

	glDebug(__FILE__, __LINE__);
}

void
xlObjEnd(void)
{
	glPopMatrix();

	glDebug(__FILE__, __LINE__);
}

void
xlObjMaterialBegin(void)
{
	XLobject *bind = xlGetObject();
	XLObjectMaterial *material= &bind->body.materials[bind->runtime.material];

	xlObjMaterial();
	xlMatProperty();

	if(material->surface)
		xlSurfBegin();
	else
		xlMatBegin();
}

void
xlObjMaterialEnd(void)
{
	XLobject *bind = xlGetObject();
	XLObjectMaterial *material= &bind->body.materials[bind->runtime.material];

	if(material->surface)
		xlSurfEnd();
	else
		xlMatEnd();
}

void
xlObjDrawMaterialCoords(XLenum mode, XLpoint *coords)
{
	XLobject *bind = xlGetObject();

	XLObjectVertex *vertices = bind->body.vertices;
	XLObjectMaterial *material = &bind->body.materials[bind->runtime.material];
	XLObjectFace *faces = bind->body.faces;
	XLuint j, k;

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_WIRE || mode == XL_RENDER_POINTS)
	{
		switch(mode)
		{
			case XL_RENDER_SOLID: glBegin(GL_TRIANGLES); break;
			case XL_RENDER_POINTS: glBegin(GL_POINTS); break;
			case XL_RENDER_WIRE: break;
			default: xlSetError(XL_ERROR_VALUE_INVALID_ENUM); break;
		}

		for(j = material->faces.start; j < material->faces.start + material->faces.count; j++)
		{
			if(mode == XL_RENDER_WIRE)
				glBegin(GL_LINE_LOOP);

			//xlNormal(&faces[j].normal);
			for(k = 0; k < 3; k++)
			{
				xlTexCoord(&faces[j].texcoords[k]);
				xlNormal(&vertices[faces[j].vertices[k]].normal);
				xlVertex(coords ? &coords[faces[j].vertices[k]] : &vertices[faces[j].vertices[k]].coord);
			}

			if(mode == XL_RENDER_WIRE)
				glEnd();
		}

		switch(mode)
		{
			case XL_RENDER_SOLID: case XL_RENDER_POINTS: glEnd(); break;
			case XL_RENDER_WIRE: break;
			default: xlSetError(XL_ERROR_VALUE_INVALID_ENUM); break;
		}
	}
}

void
xlObjDrawMaterial(XLenum mode)
{
	xlObjDrawMaterialCoords(mode, NULL);
}

void
xlObjDrawCoords(XLenum mode, XLpoint *coords)
{
	XLobject *bind = xlGetObject();

	glPushMatrix();
	glMultMatrixf(XL_MATRIX_ARRAY(&bind->runtime.matrix));

	for(bind->runtime.material = 0; bind->runtime.material < bind->header.materials; bind->runtime.material++)
	{
		xlObjMaterialBegin();
		xlObjDrawMaterialCoords(mode, coords);
		xlObjMaterialEnd();
	}

	glPopMatrix();

	glDebug(__FILE__, __LINE__);
}

void
xlObjDraw(XLenum mode)
{
	xlObjDrawCoords(mode, NULL);
}

void
xlObjCullDrawMaterial(XLenum mode)
{
	XLreal sphere[4];

	xlGetObjMatrixBoundSphere(sphere);
	if(!xlCamFrustumCullSphere(sphere))
		xlObjDrawMaterialCoords(mode, NULL);
}

void
xlObjCullDrawCoords(XLenum mode, XLpoint *coords)
{
	XLreal sphere[4];

	xlGetObjMatrixBoundSphere(sphere);
	if(!xlCamFrustumCullSphere(sphere))
		xlObjDrawCoords(mode, coords);
}

void
xlObjCullDraw(XLenum mode)
{
	xlObjCullDrawCoords(mode, NULL);
}

void
xlObjDrawVerticesMaterial(XLenum mode)
{
	XLobject *bind = xlGetObject();

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_WIRE || mode == XL_RENDER_POINTS)
	{
		XLObjectMaterial *material = &bind->body.materials[bind->runtime.material];

		glPushAttrib(GL_POLYGON_BIT);

		switch(mode)
		{
			case XL_RENDER_SOLID: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
			case XL_RENDER_WIRE: glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
			case XL_RENDER_POINTS: glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); break;
			default: xlSetError(XL_ERROR_VALUE_INVALID_ENUM); break;
		}

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glDrawArrays(GL_TRIANGLES, material->faces.start * 3, material->faces.count * 3);
		
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		glPopAttrib();
	}
}

void
xlObjDrawVertices(XLenum mode)
{
	XLobject *bind = xlGetObject();

	glPushMatrix();
	glMultMatrixf(XL_MATRIX_ARRAY(&bind->runtime.matrix));

	for(bind->runtime.material = 0; bind->runtime.material < bind->header.materials; bind->runtime.material++)
	{
		xlObjMaterialBegin();
		xlObjDrawVerticesMaterial(mode);
		xlObjMaterialEnd();
	}

	glPopMatrix();

	glDebug(__FILE__, __LINE__);
}

void
xlObjCullDrawVerticesMaterial(XLenum mode)
{
	XLreal sphere[4];

	xlGetObjMatrixBoundSphere(sphere);
	if(!xlCamFrustumCullSphere(sphere))
		xlObjDrawVerticesMaterial(mode);
}

void
xlObjCullDrawVertices(XLenum mode)
{
	XLreal sphere[4];

	xlGetObjMatrixBoundSphere(sphere);
	if(!xlCamFrustumCullSphere(sphere))
		xlObjDrawVertices(mode);
}

void
xlModDraw(XLenum mode)
{
	XLmodel *bind = xlGetModel();

	xlBindObject(bind->runtime.object);
	xlObjDrawCoords(mode, bind->runtime.anim[2]);
}

void
xlModCullDraw(XLenum mode)
{
	XLmodel *bind = xlGetModel();

	xlBindObject(bind->runtime.object);
	xlObjCullDrawCoords(mode, bind->runtime.anim[2]);
}

void
xlModDrawVertices(XLenum mode)
{
	XLmodel *bind = xlGetModel();

	xlBindObject(bind->runtime.object);
	xlObjVerticesCoords(bind->runtime.anim[2]);
	xlObjDrawVertices(mode);
}

void
xlModCullDrawVertices(XLenum mode)
{
	XLmodel *bind = xlGetModel();

	xlBindObject(bind->runtime.object);
	xlObjVerticesCoords(bind->runtime.anim[2]);
	xlObjCullDrawVertices(mode);
}
