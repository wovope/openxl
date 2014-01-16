#include "XL/xlImport.h"
#include "XL/xl.h"
#include "XL/FL/xlflut.h"

void
xlMetHeadImport(const XLpath filepath)
{
	const XLchar *mime;

	if((mime = magic_file(xlMagicCookie, filepath)))
	{
		XLmetaheader *metaheader = xlGetMetaHeader();;

		if(xlPathCappedEqual(mime, "application/x-bzip2", 19))
			mime = magic_file(xlMagicCompressCookie, filepath);
		if(xlPathCappedEqual(mime, "image", 5))
		{
			xlMetaHeaderSet(metaheader, XL_IMAGE_METAHEADER_MAGIC, filepath);
			xlMetHeadLog();
		}
		else if(xlPathCappedEqual(mime, "application/x-font", 18))
		{
			xlMetaHeaderSet(metaheader, XL_FONT_METAHEADER_MAGIC, filepath);
			xlMetHeadLog();
		}
		else if(
			xlPathCappedEqual(mime, "audio", 5) ||
			xlPathCappedEqual(mime, "application/ogg", 15))
		{
			xlMetaHeaderSet(metaheader, XL_SOUND_METAHEADER_MAGIC, filepath);
			xlMetHeadLog();
		}
		else
		{
			xlLog(L"mime is: %s\n", mime);
			xlSetError(XL_ERROR_VALUE_INVALID_PATH);
		}
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMetDatImport(const XLpath filepath)
{
	const XLchar *mime;

	if((mime = magic_file(xlMagicCookie, filepath)))
	{
		XLmetadata *metadata = xlGetMetaData();

		if(xlPathCappedEqual(mime, "application/x-bzip2", 19))
			mime = magic_file(xlMagicCompressCookie, filepath);
		if(xlPathCappedEqual(mime, "image", 5))
		{
			MagickWand *mw;
			XLpath filename;

			mw = NewMagickWand();
			MagickReadImage(mw, filepath);
			xlStringCopy(metadata->type, L"image");
			xlPathFileName(filename, filepath);
			xlStringPrintFormatted(metadata->name, XL_STRING_SIZE, L"%s", filename);
			xlMagickWandReadProperty(metadata->name, "name", mw);
			xlMagickWandReadProperty(metadata->version, "version", mw);
			xlMagickWandReadProperty(metadata->author, "author", mw);
			xlMagickWandReadDate(metadata->date, "date:modify", mw);
			xlMagickWandReadProperty(metadata->date, "date", mw);
			xlMagickWandReadDate(metadata->copyright, "date:create", mw);
			xlMagickWandReadProperty(metadata->copyright, "date", mw);
			xlMagickWandReadProperty(metadata->copyright, "copyright", mw);
			xlMagickWandReadProperty(metadata->license, "license", mw);
			xlMagickWandReadProperty(metadata->url, "url", mw);
			xlMagickWandReadProperty(metadata->email, "email", mw);
			xlMagickWandReadProperty(metadata->tool, "tool", mw);
			xlMagickWandReadProperty(metadata->comment, "comment", mw);
			xlStringCopy(metadata->xl, xlGetString(XL_VERSION));
			xlMagickWandReadProperty(metadata->xl, "xl", mw);
			DestroyMagickWand(mw);

			xlMetDatLog();
		}
		/*
		else if(xlPathCappedEqual(mime, "application/x-font", 18))
		{
			xlSetInteger(XL_METAHEADER_MAGIC, XL_FONT_METAHEADER_MAGIC);
			xlMetDatLog();
		}
		*/
		else
		{
			xlLog(L"mime is: %s\n", mime);
			xlSetError(XL_ERROR_VALUE_INVALID_PATH);
		}
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMetImport(const XLpath filepath)
{
	XLmetaheader *metaheader = xlGetMetaHeader();;
	XLmetadata *metadata = xlGetMetaData();

	xlMetHeadImport(filepath);
	switch(xlGetInteger(XL_METAHEADER_MAGIC))
	{
		case XL_IMAGE_METAHEADER_MAGIC:
		{
			MagickWand *mw;
			XLpath filename;

			mw = NewMagickWand();
			MagickReadImage(mw, filepath);
			xlMetaHeaderSet(metaheader, XL_IMAGE_METAHEADER_MAGIC, filepath);
			xlStringCopy(metadata->type, L"image");
			xlPathFileName(filename, filepath);
			xlStringPrintFormatted(metadata->name, XL_STRING_SIZE, L"%s", filename);
			xlMagickWandReadProperty(metadata->name, "name", mw);
			xlMagickWandReadProperty(metadata->version, "version", mw);
			xlMagickWandReadProperty(metadata->author, "author", mw);
			xlMagickWandReadDate(metadata->date, "date:modify", mw);
			xlMagickWandReadProperty(metadata->date, "date", mw);
			xlMagickWandReadDate(metadata->copyright, "date:create", mw);
			xlMagickWandReadProperty(metadata->copyright, "date", mw);
			xlMagickWandReadProperty(metadata->copyright, "copyright", mw);
			xlMagickWandReadProperty(metadata->license, "license", mw);
			xlMagickWandReadProperty(metadata->url, "url", mw);
			xlMagickWandReadProperty(metadata->email, "email", mw);
			xlMagickWandReadProperty(metadata->tool, "tool", mw);
			xlMagickWandReadProperty(metadata->comment, "comment", mw);
			xlStringCopy(metadata->xl, xlGetString(XL_VERSION));
			xlMagickWandReadProperty(metadata->xl, "xl", mw);
			DestroyMagickWand(mw);

			xlMetLog();
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

void
xlImgImport(const XLpath filepath)
{
	XLimage *image = xlGetImage();
	XLmetaheader *metaheader = &image->header.metaheader;
	XLmetadata *metadata = &image->header.metadata;
	MagickWand *mw;
	XLpixel *pixels;
	XLpath filename;

	xlMemoryZero(image, sizeof(XLimage));

	mw = NewMagickWand();

	MagickReadImage(mw, filepath);

	xlMetaHeaderSet(metaheader, XL_IMAGE_METAHEADER_MAGIC, filepath);
	xlStringCopy(metadata->type, L"image");
	xlPathFileName(filename, filepath);
	xlStringPrintFormatted(metadata->name, XL_STRING_SIZE, L"%s", filename);
	xlMagickWandReadProperty(metadata->name, "name", mw);
	xlMagickWandReadProperty(metadata->version, "version", mw);
	xlMagickWandReadProperty(metadata->author, "author", mw);
	xlMagickWandReadDate(metadata->date, "date:modify", mw);
	xlMagickWandReadProperty(metadata->date, "date", mw);
	xlMagickWandReadDate(metadata->copyright, "date:create", mw);
	xlMagickWandReadProperty(metadata->copyright, "date", mw);
	xlMagickWandReadProperty(metadata->copyright, "copyright", mw);
	xlMagickWandReadProperty(metadata->license, "license", mw);
	xlMagickWandReadProperty(metadata->url, "url", mw);
	xlMagickWandReadProperty(metadata->email, "email", mw);
	xlMagickWandReadProperty(metadata->tool, "tool", mw);
	xlMagickWandReadProperty(metadata->comment, "comment", mw);
	xlStringCopy(metadata->xl, xlGetString(XL_VERSION));
	xlMagickWandReadProperty(metadata->xl, "xl", mw);

	xlLogMeta(metaheader, metadata);

	image->header.width = MagickGetImageWidth(mw);
	image->header.width = xlRealNextTwoPower(image->header.width);
	xlLog(L"%s: width: %i\n", filepath, image->header.width);

	image->header.height = MagickGetImageHeight(mw);
	image->header.height = xlRealNextTwoPower(image->header.height);

	xlLog(L"%s: height: %i\n", filepath, image->header.height);

	if(image->header.width != MagickGetImageWidth(mw) || image->header.height != MagickGetImageHeight(mw))
		MagickScaleImage(mw, image->header.width, image->header.height);

	image->header.bpp = 4;
	xlLog(L"%s: bpp: %i\n", filepath, image->header.bpp);

	pixels = xlMemoryAlloc(image->header.width  * image->header.height * image->header.bpp * sizeof(XLpixel));

	// FIXME: RGBA hardcoded
	MagickExportImagePixels(mw, 0, 0, image->header.width, image->header.height, "RGBA", Pixel, pixels);

	image->body.pixels = xlAlloc(image->header.width  * image->header.height * sizeof(XLcolor));
	xlPixelsImage(pixels);
	xlFree(pixels);

	DestroyMagickWand(mw);
}

void
xlSndImport(const XLpath filepath)
{
	XLsound *sound = xlGetSound();
	XLmetaheader *metaheader = &sound->header.metaheader;
	XLmetadata *metadata = &sound->header.metadata;
	XLpath filename;
	FLsound fl;

	xlMemoryZero(sound, sizeof(XLsound));

	flSoundLoadDefault(&fl, filepath);

	xlMetaHeaderSet(metaheader, XL_SOUND_METAHEADER_MAGIC, filepath);
	xlStringCopy(metadata->type, L"sound");
	xlPathFileName(filename, filepath);
	xlStringPrintFormatted(metadata->name, XL_STRING_SIZE, L"%s", filename);
	/*
	xlMagickWandReadProperty(metadata->name, "name", mw);
	xlMagickWandReadProperty(metadata->version, "version", mw);
	xlMagickWandReadProperty(metadata->author, "author", mw);
	xlMagickWandReadDate(metadata->date, "date:modify", mw);
	xlMagickWandReadProperty(metadata->date, "date", mw);
	xlMagickWandReadDate(metadata->copyright, "date:create", mw);
	xlMagickWandReadProperty(metadata->copyright, "date", mw);
	xlMagickWandReadProperty(metadata->copyright, "copyright", mw);
	xlMagickWandReadProperty(metadata->license, "license", mw);
	xlMagickWandReadProperty(metadata->url, "url", mw);
	xlMagickWandReadProperty(metadata->email, "email", mw);
	xlMagickWandReadProperty(metadata->tool, "tool", mw);
	xlMagickWandReadProperty(metadata->comment, "comment", mw);
	*/
	xlStringCopy(metadata->xl, xlGetString(XL_VERSION));
	/*
	xlMagickWandReadProperty(metadata->xl, "xl", mw);
	*/

	xlLogMeta(metaheader, metadata);

	sound->header.channels = flSoundChannels(&fl);
	xlLog(L"%s: channels: %i\n", filepath, sound->header.channels);
	sound->header.frequency = flSoundFrequency(&fl);
	xlLog(L"%s: frequency: %i\n", filepath, sound->header.frequency);
	sound->header.length = flSoundSamples(&fl);
	xlLog(L"%s: length: %i\n", filepath, sound->header.length);
	sound->header.bps = flSoundSampleSize(&fl);
	xlLog(L"%s: bps: %i\n", filepath, sound->header.bps);

	sound->body.samples = xlMemoryAlloc(sound->header.length * sound->header.bps);
	flSoundReadSamples(&fl, sound->body.samples);

	flSoundUnload(&fl);
}

void
xlFntImport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlMatImport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlSurfImport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlObjImport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlModImport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlPartsImport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlCamImport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlOpImport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlVptImport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

void
xlWinImport(const XLpath filepath)
{
	xlLog(L"No library handler for supporting %s, consider suggesting one\n", filepath);
	xlSetError(XL_ERROR_VALUE_INVALID_OP);
}

static XLmatrix xlImgStringMatrix;
static unsigned char *ipixels;

void
xlImgPixelGlyph(XLuint w, XLuint h, FT_GlyphSlot glyph)
{
	XLuint i, j, x, y;
	XLpair p;
	xlPairAssignMultMatrix(&p, xlPairZero, &xlImgStringMatrix);
	for(j = 0; j < (XLuint) glyph->bitmap.rows; j++)
		for(i = 0; i < (XLuint) (glyph->bitmap.width); i++)
		{
			x = i + XL_INTEGER(XL_PAIR_X(&p));
			y = j + XL_INTEGER(XL_PAIR_Y(&p));
			if(xlIntegerInIndex(x, 0, w) && xlIntegerInIndex(y, 0, h))
				ipixels[(y * w + x) * 2] = ipixels[(y * w + x) * 2 + 1] = glyph->bitmap.buffer[j * glyph->bitmap.pitch + i];
		}
}

void
xlImgGlyph(XLreal ymin, XLreal ymax, XLreal width, XLreal height, FT_GlyphSlot glyph)
{
	XLpoint p;
	xlPointAssignReals(&p,
		XL_REAL(glyph->metrics.horiBearingX) / XL_REAL(64),
		height + ymin - XL_REAL(glyph->metrics.horiBearingY) / XL_REAL(64),
		XL_REAL(0));
	xlMatrixTranslate(&xlImgStringMatrix, &p);
	xlImgPixelGlyph(width, height, glyph);
	xlMatrixTranslate(&xlImgStringMatrix, xlPointNeg(&p));
}

void
xlImgString(XLenum mode, const XLstring string)
{
	XLfont *font = xlGetFont();
	XLimage *image = xlGetImage();
	XLmetaheader *metaheader = &image->header.metaheader;
	XLmetadata *metadata = &image->header.metadata;
	XLreal ymin, ymax, width, height;
	const XLwchar *wc;
	XLpixel *pixels;
	MagickWand *mw;
	XLpoint translation;

	width = image->header.width;
	height = image->header.height;

	xlMemoryZero(image, sizeof(XLimage));
	xlMetaHeaderSet(metaheader, XL_IMAGE_METAHEADER_MAGIC, font->header.metaheader.path);
	xlStringCopy(metadata->type, L"image");
	xlStringCopy(metadata->name, L"String");
	xlStringCopy(metadata->version, xlGetString(XL_VERSION));
	xlStringCopy(metadata->author, xlGetString(XL_AUTHOR));
	xlStringCopy(metadata->date, xlGetString(XL_DATE));
	xlStringCopy(metadata->copyright, xlGetString(XL_COPYRIGHT));
	xlStringCopy(metadata->license, xlGetString(XL_LICENSE));
	xlStringCopy(metadata->url, xlGetString(XL_URL));
	xlStringCopy(metadata->email, xlGetString(XL_EMAIL));
	xlStringCopy(metadata->tool, xlGetString(XL_TOOL));
	xlStringCopy(metadata->comment, L"Pixelized");
	xlStringCopy(metadata->xl, xlGetString(XL_VERSION));

	image->header.width = width;
	image->header.height = height;
	xlStrDetailedSize(string, &ymin, &ymax, &width, &height);
	if(!image->header.width || !image->header.height)
	{
		image->header.width = xlRealNextTwoPower(width);
		image->header.height = xlRealNextTwoPower(height);
	}
	image->header.bpp = 4;
	image->body.pixels = xlAlloc(image->header.width * image->header.height * sizeof(XLcolor));

	ipixels = xlMemoryAlloc(width * height * 2 * sizeof(XLpixel));
	xlMemoryZero(ipixels, width * height * 2 * sizeof(XLpixel));
	xlMatrixAssignIdentity(&xlImgStringMatrix);
	for(wc = string; *wc; wc++)
	{
		switch(mode)
		{
			case XL_RENDER_TEXTURE:
				FT_Load_Char(font->runtime.face, *wc, FT_LOAD_RENDER);
				xlImgGlyph(ymin, ymax, width, height, font->runtime.face->glyph);
				break;
			default:
				FT_Load_Char(font->runtime.face, *wc, FT_LOAD_DEFAULT);
				break;
		}
		xlMatrixTranslate(&xlImgStringMatrix, xlPointAssignReals(&translation, XL_REAL(font->runtime.face->glyph->metrics.horiAdvance) / XL_REAL(64), XL_REAL(0), XL_REAL(0)));
	}
	mw = NewMagickWand();
	//NOTE: "IO" could be interesting
	MagickConstituteImage(mw, width, height, "IA", CharPixel, ipixels);
	xlFree(ipixels);
	//MagickGaussianBlurImage(mw, 2, 1);
	if(image->header.width != MagickGetImageWidth(mw) || image->header.height != MagickGetImageHeight(mw))
		MagickScaleImage(mw, image->header.width, image->header.height);

	pixels = xlMemoryAlloc(image->header.width * image->header.height * image->header.bpp * sizeof(XLpixel));
	MagickExportImagePixels(mw, 0, 0, image->header.width, image->header.height, "RGBA", Pixel, pixels);
	xlPixelsColors(image->body.pixels, pixels, image->header.width * image->header.height, image->header.bpp);
	xlFree(pixels);
	DestroyMagickWand(mw);

	xlImgLog();
}

void
xlObjCountGlyph(XLenum mode, XLreal z, FT_GlyphSlot glyph)
{
	XLuint *vrts;
	XLdouble **ctours;
	GLUtesselator *tess;
	XLuint i, j;

	xlGlyphCreateContours(glyph, &vrts, &ctours);

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_FILL)
	{
		tess = gluNewTess();
		gluTessCallback(tess, GLU_TESS_VERTEX, (_GLUfuncptr) &xlObjTessPrimitiveCountVertexdv);
		gluTessCallback(tess, GLU_TESS_BEGIN, (_GLUfuncptr) &xlObjPrimitiveBegin);
		gluTessCallback(tess, GLU_TESS_END, (_GLUfuncptr) &xlObjPrimitiveEnd);
	}

	if(mode == XL_RENDER_SOLID)
	{
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
	}

	if(mode == XL_RENDER_MODERN || mode == XL_RENDER_SOLID)
	{
		for(j = 0; j < (XLuint) glyph->outline.n_contours; j++)
		{
			GLdouble data[3];
			xlObjPrimitiveBegin(GL_TRIANGLE_STRIP);
			for(i = 0; i < vrts[j]; i++)
			{
				data[0] = ctours[j][i * 3]; data[1] = ctours[j][i * 3 + 1]; data[2] = - (XLdouble) z;
				xlObjTessPrimitiveCountVertexdv(data);
				data[0] = ctours[j][i * 3]; data[1] = ctours[j][i * 3 + 1]; data[2] = 0.0;
				xlObjTessPrimitiveCountVertexdv(data);
			}
			data[0] = ctours[j][0 * 3]; data[1] = ctours[j][0 * 3 + 1]; data[2] = - (XLdouble) z;
			xlObjTessPrimitiveCountVertexdv(data);
			data[0] = ctours[j][0 * 3]; data[1] = ctours[j][0 * 3 + 1]; data[2] = 0.0;
			xlObjTessPrimitiveCountVertexdv(data);
			xlObjPrimitiveEnd();
		}
	}

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_FILL)
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

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_FILL)
	{
		gluDeleteTess(tess);
	}

	xlGlyphFreeContours(glyph, &vrts, &ctours);
}

void
xlObjGlyph(XLenum mode, XLreal z, FT_GlyphSlot glyph)
{
	XLuint *vrts;
	XLdouble **ctours;
	GLUtesselator *tess = NULL;
	XLuint i, j;
	XLpoint p;

	xlGlyphCreateContours(glyph, &vrts, &ctours);

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_FILL)
	{
		tess = gluNewTess();
		gluTessCallback(tess, GLU_TESS_VERTEX, (_GLUfuncptr) &xlObjTessPrimitiveVertexdv);
		gluTessCallback(tess, GLU_TESS_BEGIN, (_GLUfuncptr) &xlObjPrimitiveBegin);
		gluTessCallback(tess, GLU_TESS_END, (_GLUfuncptr) &xlObjPrimitiveEnd);
	}

	if(mode == XL_RENDER_SOLID)
	{
		//xlVectorAssignCopy(xlVectorT, xlVectorY);
		xlMatrixTranslate(xlMatrixModelView, xlPointAssignReals(&p, XL_REAL(0), XL_REAL(0), - XL_REAL(z)));
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
		xlMatrixTranslate(xlMatrixModelView, xlPointNeg(&p));
	}

	if(mode == XL_RENDER_MODERN || mode == XL_RENDER_SOLID)
	{
		for(j = 0; j < (XLuint) glyph->outline.n_contours; j++)
		{
			//xlVectorAssignCopy(xlVectorT, xlVectorZ);
			GLdouble data[3];
			xlObjPrimitiveBegin(GL_TRIANGLE_STRIP);
			for(i = 0; i < vrts[j]; i++)
			{
				data[0] = ctours[j][i * 3]; data[1] = ctours[j][i * 3 + 1]; data[2] = - (XLdouble) z;
				xlObjTessPrimitiveVertexdv(data);
				data[0] = ctours[j][i * 3]; data[1] = ctours[j][i * 3 + 1]; data[2] = 0.0;
				xlObjTessPrimitiveVertexdv(data);
			}
			data[0] = ctours[j][0 * 3]; data[1] = ctours[j][0 * 3 + 1]; data[2] = - (XLdouble) z;
			xlObjTessPrimitiveVertexdv(data);
			data[0] = ctours[j][0 * 3]; data[1] = ctours[j][0 * 3 + 1]; data[2] = 0.0;
			xlObjTessPrimitiveVertexdv(data);
			xlObjPrimitiveEnd();
		}
	}

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_FILL)
	{
		//xlVectorAssignCopy(xlVectorT, xlVectorY);
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

	if(mode == XL_RENDER_SOLID || mode == XL_RENDER_FILL)
	{
		gluDeleteTess(tess);
	}

	xlGlyphFreeContours(glyph, &vrts, &ctours);
}

void
xlObjString(XLenum mode, XLreal depth, const XLpath material, const XLstring string)
{
	XLfont *font = xlGetFont();
	XLobject *object = xlGetObject();
	XLmetaheader *metaheader = &object->header.metaheader;
	XLmetadata *metadata = &object->header.metadata;
	const XLwchar *wc;
	XLreal ymin, ymax, width, height;
	XLpoint translation;
	XLvector scalation;
	XLmatrix matrix;
	XLuint i;

	xlMemoryZero(object, sizeof(XLobject));
	xlMetaHeaderSet(metaheader, XL_OBJECT_METAHEADER_MAGIC, font->header.metaheader.path);
	xlStringCopy(metadata->type, L"object");
	xlStringCopy(metadata->name, L"String");
	xlStringCopy(metadata->version, xlGetString(XL_VERSION));
	xlStringCopy(metadata->author, xlGetString(XL_AUTHOR));
	xlStringCopy(metadata->date, xlGetString(XL_DATE));
	xlStringCopy(metadata->copyright, xlGetString(XL_COPYRIGHT));
	xlStringCopy(metadata->license, xlGetString(XL_LICENSE));
	xlStringCopy(metadata->url, xlGetString(XL_URL));
	xlStringCopy(metadata->email, xlGetString(XL_EMAIL));
	xlStringCopy(metadata->tool, xlGetString(XL_TOOL));
	xlStringCopy(metadata->comment, L"Tesselated");
	xlStringCopy(metadata->xl, xlGetString(XL_VERSION));

	xlObjPipelineBegin();
	for(wc = string, ymin = ymax = width = XL_REAL(0); *wc; ymin = xlRealMin(ymin, XL_REAL(font->runtime.face->glyph->metrics.horiBearingY - font->runtime.face->glyph->metrics.height)), ymax = xlRealMax(ymax, XL_REAL(font->runtime.face->glyph->metrics.horiBearingY)), width += XL_REAL(font->runtime.face->glyph->metrics.horiAdvance), wc++)
	{
		FT_Load_Char(font->runtime.face, *wc, FT_LOAD_DEFAULT);
		switch(mode)
		{
			case XL_RENDER_FILL:
			case XL_RENDER_MODERN:
			case XL_RENDER_SOLID:
				xlObjCountGlyph(mode, depth, font->runtime.face->glyph);
				break;
			default:
				break;
		}
	}
	ymin /= XL_REAL(64);
	ymax /= XL_REAL(64);
	width /= XL_REAL(64);
	height = - xlRealMin(XL_REAL(0), ymin) + ymax;
	xlObjPipelineCountEnd();
	object->header.materials = 1;
	object->header.tags = 0;

	object->body.vertices = xlAlloc(object->header.vertices * sizeof(XLObjectVertex));
	object->body.faces = xlAlloc(object->header.faces * sizeof(XLObjectFace));
	xlObjPipelineBegin();
	xlMatrixAssignIdentity(xlMatrixModelView);
	for(wc = string; *wc; wc++)
	{
		FT_Load_Char(font->runtime.face, *wc, FT_LOAD_DEFAULT);

		xlPointAssignReals(&translation,
			XL_REAL(0), //XL_REAL(font->runtime.face->glyph->metrics.horiBearingX) / XL_REAL(64),
			- ymin,
			XL_REAL(0));
		xlMatrixTranslate(xlMatrixModelView, &translation);
		switch(mode)
		{
			case XL_RENDER_FILL:
			case XL_RENDER_MODERN:
			case XL_RENDER_SOLID:
				xlObjGlyph(mode, depth, font->runtime.face->glyph);
				break;
			default:
				break;
		}
		xlMatrixTranslate(xlMatrixModelView, xlPointNeg(&translation));
		xlMatrixTranslate(xlMatrixModelView, xlPointAssignReals(&translation, XL_REAL(font->runtime.face->glyph->metrics.horiAdvance) / XL_REAL(64), XL_REAL(0), XL_REAL(0)));
	}
	xlObjPipelineEnd();

	object->body.materials = xlAlloc(object->header.materials * sizeof(XLObjectMaterial));
	xlStringZero(object->body.materials[0].name);
	xlStringCopy(object->body.materials[0].name, L"Material");
	xlPathZero(object->body.materials[0].path);
	xlPathCopy(object->body.materials[0].path, material);
	object->body.materials[0].surface = 0;
	xlRangeLoad(&object->body.materials[0].faces, 0, object->header.faces);

	glGetFloatv(GL_TEXTURE_MATRIX, XL_MATRIX_ARRAY(&matrix));
	xlMatrixScale(&matrix, xlVectorAssignReals(&scalation, XL_REAL(1) / XL_REAL(64), XL_REAL(1) / XL_REAL(64), XL_REAL(1) / XL_REAL(64)));
	for(i = 0; i < object->header.faces; i++)
	{
		xlPairMultMatrix(&object->body.faces[i].texcoords[0], &matrix);
		xlPairMultMatrix(&object->body.faces[i].texcoords[1], &matrix);
		xlPairMultMatrix(&object->body.faces[i].texcoords[2], &matrix);
	}

	object->body.bound = xlAlloc(1 * sizeof(XLObjectBound));
	xlSphereLoad(object->body.bound->sphere, XL_REAL(width) / XL_REAL(2),  XL_REAL(height) / XL_REAL(2), XL_REAL(depth) / XL_REAL(2), xlRealMax(XL_REAL(width), xlRealMax(XL_REAL(height), depth)) / XL_REAL(2));
	object->body.bound->dimensions[0] = width;
	object->body.bound->dimensions[1] = height;
	object->body.bound->dimensions[2] = depth;

	xlMatrixAssignIdentity(&object->runtime.matrix);

	xlObjLog();
}
