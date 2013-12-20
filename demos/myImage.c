#include "myImage.h"

void
myImage(XLenum mode, const XLpath xlpath, XLint width, XLint height, XLint t)
{
	XLimage image;
	XLmetaheader *metaheader;
	XLmetadata *metadata;
	XLint x, y;
	XLcolor *a, *b, *c, *d;

	xlMemoryZero(&image, sizeof(XLimage));

	metaheader = &image.header.metaheader;
	metadata = &image.header.metadata;

	xlMetaHeaderSet(metaheader, XL_IMAGE_METAHEADER_MAGIC, xlpath);
	if(mode == XL_DATA_META || mode == XL_DATA_METAHEADER)
	{
		xlMetHeadType(metaheader);
		if(mode == XL_DATA_METAHEADER)
			return;
	}

	switch(t)
	{
		case 0: xlStringCopy(metadata->name, L"Textil"); break; 
		case 1: xlStringCopy(metadata->name, L"Wood"); break;
		case 2: xlStringCopy(metadata->name, L"Wood2"); break;
		case 3: xlStringCopy(metadata->name, L"Wood3"); break;
		case 4: xlStringCopy(metadata->name, L"Granite"); break;
		case 5: xlStringCopy(metadata->name, L"Grass"); break;
		case 6: xlStringCopy(metadata->name, L"Color"); break;
		case 7: xlStringCopy(metadata->name, L"Lerp"); break;
		case 8: xlStringCopy(metadata->name, L"QuadBezier"); break;
		case 9: xlStringCopy(metadata->name, L"CubicBezier"); break;
		default: xlSetError(XL_ERROR_VALUE_INVALID_PARAM); break;
	}
	xlStringCopy(metadata->version, xlGetString(XL_VERSION));
	xlStringCopy(metadata->author, xlGetString(XL_AUTHOR));
	xlStringCopy(metadata->date, xlGetString(XL_DATE));
	xlStringCopy(metadata->copyright, xlGetString(XL_COPYRIGHT));
	xlStringCopy(metadata->license, xlGetString(XL_LICENSE));
	xlStringCopy(metadata->url, xlGetString(XL_URL));
	xlStringCopy(metadata->email, xlGetString(XL_EMAIL));
	xlStringCopy(metadata->tool, xlGetString(XL_TOOL));
	xlStringCopy(metadata->comment, L"Proceduralized");
	xlStringCopy(metadata->xl, xlGetString(XL_VERSION));
	if(mode == XL_DATA_META || mode == XL_DATA_METADATA)
	{
		xlMetDatType(metadata);
		if(mode == XL_DATA_METADATA)
			return;
	}

	if(mode == XL_DATA_META)
		return;

	image.header.width = width;
	image.header.height = height;
	image.header.bpp = 4;

	image.body.pixels = xlAlloc(image.header.width * image.header.height * sizeof(XLcolor));

	a = xlGetColor(xlIntegerRandRange(XL_COLOR_FIRST, XL_COLOR_LAST));
	b = xlGetColor(xlIntegerRandRange(XL_COLOR_FIRST, XL_COLOR_LAST));
	c = xlGetColor(xlIntegerRandRange(XL_COLOR_FIRST, XL_COLOR_LAST));
	d = xlGetColor(xlIntegerRandRange(XL_COLOR_FIRST, XL_COLOR_LAST));

	for(y = 0; y < height; y++)
	{
		for(x = 0; x < width; x++)
		{
			switch(t)
			{
				case 0:
					xlColorAssignReals(image.body.pixels + (x + y * width), fd(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), 39), fd(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), 20), fd(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), 10 + 1), XL_REAL(1));
					break; 
				case 1:
					xlColorAssignReals(image.body.pixels + (x + y * width), fe(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), 100, 45, 55) ? fc(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), xlIntegerRandRange(0, 10) + 1) : xlRealRand() , fe(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), 100, 45, 55) ? fc(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), xlIntegerRandRange(1, 26)) : xlRealRand(), ~(int)fe(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), 100, 45, 55), XL_REAL(1));
					break;
				case 2:
					xlColorAssignReals(image.body.pixels + (x + y * width), fc(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), xlIntegerRandRange(0, 10) + 1), fe(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), 64, 30, 34) ? XL_REAL(0) : fc(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), xlIntegerRandRange(1, 6)), fe(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), 64, 30, 34) ? XL_REAL(0) : xlRealRand(), XL_REAL(1));
					break;
				case 3:
					xlColorAssignReals(image.body.pixels + (x + y * width), fc(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), xlIntegerRandRange(0, 10) + 1), fe(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), 100, 45, 55) ? xlRealRand() / XL_REAL(8) : fc(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), xlIntegerRandRange(1, 6)), fe(x + xlIntegerRandRange(0, 10), y + xlIntegerRandRange(0, 10), 100, 45, 55) ? XL_REAL(0) : xlRealRand(), XL_REAL(1));
					break;
				case 4:
					xlColorAssignRandRange(image.body.pixels + x + y * width, xlColorBlack, xlColorWhite);
					break;
				case 5:
					xlColorAssignReals(image.body.pixels + (x + y * width), XL_REAL(0), xlRealRand() / XL_REAL(2) + XL_REAL(0.5), XL_REAL(0), XL_REAL(1));
					break;
				case 6:
					xlColorAssignCopy(image.body.pixels + (x + y * width), a);
					break;
				case 7:
					xlColorAssignLerp(image.body.pixels + x + y *width, a, b, XL_REAL(x) / XL_REAL(width));
					break;
				case 8:
					xlColorAssignQuadBezier(image.body.pixels + x + y *width, a, b, c, XL_REAL(x) / XL_REAL(width));
					break;
				case 9:
					xlColorAssignCubicBezier(image.body.pixels + x + y *width, a, b, c, d, XL_REAL(x) / XL_REAL(width));
					break;
				default:
					xlSetError(XL_ERROR_VALUE_INVALID_PARAM);
					break;
			}
		}
	}

	if(
		t == 0 ||
		t == 2 ||
		t == 4 ||
		t == 5
	)
	{
		MagickWand *mw = NewMagickWand();
		XLpixel *pixels = xlGetPixelsColors(image.body.pixels, image.header.width * image.header.height, image.header.bpp);
		MagickConstituteImage(mw, image.header.width, image.header.height, "RGBA", Pixel, pixels);
//		MagickAddNoiseImage(mw, UniformNoise);
//		MagickAddNoiseImage(mw, GaussianNoise);
//		MagickAddNoiseImage(mw, MultiplicativeGaussianNoise);
//		MagickAddNoiseImage(mw, ImpulseNoise);
//		MagickAddNoiseImage(mw, LaplacianNoise);
//		MagickAddNoiseImage(mw, PoissonNoise);
//		MagickAddNoiseImage(mw, RandomNoise);
//		MagickAutoGammaImage(mw);
//		MagickAutoLevelImage(mw);
//		MagickBlueShiftImage(mw, 10);
		MagickGaussianBlurImage(mw, 2, 1);
		MagickEmbossImage(mw, 2, 1);
		MagickGaussianBlurImage(mw, 2, 1);
		MagickExportImagePixels(mw, 0, 0, image.header.width, image.header.height, "RGBA", Pixel, pixels);
		xlPixelsColors(image.body.pixels, pixels, image.header.width * image.header.height, image.header.bpp);
		xlFree(pixels);
		DestroyMagickWand(mw);
	}

	xlImgType(&image);
}

XLuint
myImgTextilXL(XLenum mode, const XLpath xlpath)
{
	myImage(mode, xlpath, 512, 512, 0);

	return 0;
}

XLuint
myImgWoodXL(XLenum mode, const XLpath xlpath)
{
	myImage(mode, xlpath, 512, 512, 2);

	return 0;
}

XLuint
myImgGrassXL(XLenum mode, const XLpath xlpath)
{
	myImage(mode, xlpath, 512, 512, 5);

	return 0;
}
