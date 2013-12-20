#include "XL/xlUtils.h"
#include "XL/xl.h"

GLenum
xlGetBytesPerPixelFormat(XLuint bpp)
{
	GLenum format = GL_RGBA;

	switch(bpp)
	{
		case 3: format = GL_RGB; break;
		case 4: format = GL_RGBA; break;
		default: xlSetError(XL_ERROR_VALUE_INVALID_PARAM); break;
	}

	return format;
}

XLuint
xlGetFormatBytesPerPixel(GLenum format)
{
	XLuint bpp = 4;

	switch(format)
	{
		case GL_RGB: bpp = 3; break;
		case GL_RGBA: bpp = 4; break;
		default: xlSetError(XL_ERROR_VALUE_INVALID_PARAM); break;
	}

	return bpp;
}

void
xlMagickWandReadProperty(XLstring string, const XLchar *property, MagickWand *mw)
{
	XLchar *value;

	if((value = MagickGetImageProperty(mw, property)))
	{
		xlStringPrintFormatted(string, XL_STRING_SIZE, L"%s", value);
		MagickRelinquishMemory(value);
	}
}

void
xlMagickWandReadDate(XLstring string, const XLchar *property, MagickWand *mw)
{
	xlMagickWandReadProperty(string, property, mw);

	// FIXME: getting epoch 
/*
	XLchar *value;

	if((value = MagickGetImageProperty(mw, property)))
	{
		struct tm tm;
		XLpathbuffer buffer;

		xlMemoryZero(&tm, sizeof(struct tm));
		strptime(value, "%c", &tm);
		strftime(buffer, XL_PATH_BUFFER_SIZE, "%B %d, %Y", &tm);
		xlStringPrintFormatted(string, XL_STRING_SIZE, L"%s", buffer);
		MagickRelinquishMemory(value);
	}
*/
}

void
xlMagickWandWriteProperty(XLstring string, const XLchar *property, MagickWand *mw)
{
	XLpath value;

	if(xlPathPrintFormatted(value, XL_PATH_SIZE, "%ls", string))
		MagickSetImageProperty(mw, property, value);
}

void
xlMagickWandWriteDate(XLstring string, const XLchar *property, MagickWand *mw)
{
	xlMagickWandWriteProperty(string, property, mw);
}

void
xlPathFileName(XLpath filename, const XLpath path)
{
	//FIXME: no dots, no slash? ?

	XLchar *slash, *lastslash;
	XLchar *dot, *lastdot;
	XLpath slashpath, dotpath;
	XLuint length, lastslashlength, lastdotlength;

	length = xlPathLength(path);

	xlPathCopy(slashpath, path);
	for(slash = lastslash = strtok(slashpath, XL_PATH_SEPARATOR); slash; slash = strtok(NULL, XL_PATH_SEPARATOR))
		lastslash = slash;
	lastslashlength = xlPathLength(lastslash);

	xlPathCopy(dotpath, path);
	for(dot = lastdot = strtok(dotpath, XL_PATH_DOT); dot; dot = strtok(NULL, XL_PATH_DOT))
		lastdot = dot;
	lastdotlength = xlPathLength(lastdot);
	
	xlPathZero(filename);
	xlPathCappedCopy(filename, path + length - lastslashlength, lastslashlength - lastdotlength - 1);
}

void
xlRangeLoad(XLrange *range, XLuint start, XLuint count)
{
	range->start = start;
	range->count = count;
}

void
xlPixelLoad(XLpixel *c, XLreal r, XLreal g, XLreal b, XLreal a)
{
	c[0] = r; c[1] = g; c[2] = b; c[3] = a;
}

void
xlPixelsColors(XLcolor *colors, XLpixel *pixels, XLsize count, XLsizei bpp)
{
	XLint i;

	for(i = 0; i < count; i++)
		xlColorAssignArray(colors + i, pixels + i * bpp);
}

XLpixel *
xlGetPixelsColors(XLcolor *colors, XLsize count, XLsizei bpp)
{
	XLpixel *pixels;
	XLint i, j;
	
	pixels = xlMemoryAlloc(count * bpp * sizeof(XLpixel));
	for(i = 0; i < count; i++)
	{
		for(j = 0; j < bpp; j++)
			pixels[i * bpp + j] = XL_COLOR_ARRAY(colors + i)[j];
	}
	return pixels;
}

void
xlPixelsImage(XLpixel *pixels)
{
	XLimage *image = xlGetImage();

	xlPixelsColors(image->body.pixels, pixels, image->header.width * image->header.height, image->header.bpp);
}

XLpixel *
xlGetPixelsImage(void)
{
	XLimage *image = xlGetImage();

	return xlGetPixelsColors(image->body.pixels, image->header.width * image->header.height, image->header.bpp);
}

void
xlVerticesLoad(XLuint *vertices, XLuint a, XLuint b, XLuint c)
{
	vertices[0] = a;
	vertices[1] = b;
	vertices[2] = c;
}

void
xlTexCoordsLoad(XLpair *texcoords, XLreal u1, XLreal v1, XLreal u2, XLreal v2, XLreal u3, XLreal v3)
{
	xlPairAssignReals(&texcoords[0], u1, v1);
	xlPairAssignReals(&texcoords[1], u2, v2);
	xlPairAssignReals(&texcoords[2], u3, v3);
}

/*
XLfile *
xlFileOpen(const XLchar *filepath, const XLchar *mode)
{
	XLfile *stream = NULL;

	switch(xlGetPathFormat(filepath))
	{
		case XL_FILE_PLAIN:
			stream = fopen(filepath, mode);
			break;
		case XL_FILE_BZIP2:
		{
			//FIXME: only works for mode = r, implement mode = w case
			XLfile *istream, *ostream;
			BZFILE *bz2stream;
			int bz2error;

			if((istream = fopen(filepath, "rb")))
			{
				XLpath tmp = "/tmp/XL-XXXXXX";
				xlFileMakeTemporal(tmp);
				if((ostream = fopen(tmp, "wb")))
				{
					XLpathbuffer buffer;
					XLint bytes;

					bz2stream = BZ2_bzReadOpen(&bz2error, istream, 0, 0, NULL, 0);
					if(bz2error == BZ_OK)
					{
						while((bytes = BZ2_bzRead(&bz2error, bz2stream, buffer, XL_PATH_BUFFER_SIZE)) && bz2error == BZ_OK)
						{
							xlFileWrite(buffer, 1, bytes, ostream);
						}
						if(bz2error != BZ_IO_ERROR)
							stream = ostream;
						else
							xlSetError(XL_ERROR_FILE);

						BZ2_bzReadClose(&bz2error, bz2stream);
					}
					else
						xlSetError(XL_ERROR_FILE);

					xlFileClose(ostream);
				}
				else
					xlSetError(XL_ERROR_FILE);

				xlFileClose(istream);
				if(stream) stream = fopen(tmp, mode);
			}
			else
				xlSetError(XL_ERROR_VALUE_INVALID_PATH);
		}
			break;
		default:
			xlSetError(XL_ERROR_FILE);
			break;
	}
	return stream;
}

XLfile *
xlFileStringOpen(const XLwchar *path, const XLwchar *mode)
{
	XLuint lpath = xlStringLength(path), lmode = xlStringLength(mode);
	XLchar cpath[lpath], cmode[lmode]; 

	xlPathFromString(cpath, path, lpath);
	xlPathFromString(cmode, mode, lmode);
	return xlFileOpen(cpath, cmode);
}
*/
