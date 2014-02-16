#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Ortho.xlc";

XLid img[3];
XLimage *image[3];
XLstring str;
XLint size[2] = { XL_REAL(128), XL_REAL(128) };
XLboolean edit;
XLuint i;

void
myImgString(void)
{
	xlSetIntegerv(XL_IMAGE_SIZE, size);
	xlImgString(XL_RENDER_TEXTURE, str);
	for(i = 0; i < size[0] * size[1]; i++)
	{
		xlColorAssignLerp(&image[0]->body.pixels[i], &image[1]->body.pixels[i], &image[2]->body.pixels[i], XL_COLOR_A(&image[0]->body.pixels[i]));
	}
}

void
demoKeyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'l':
		{
			XLstring strtmp;

			if(!edit) { str[0] = L'\0'; edit = XL_TRUE; }
			xlStringCopy(strtmp, str);
			xlStringPrintFormatted(str, XL_STRING_SIZE, L"%ls%c", strtmp, key);
			xlBindImage(img[0]);
			xlImgDeleteTexture();
			xlImgUnload();
			xlImgImport("data/images/Tux.png");
			xlImgGenTexture();
			break;
		}
		case '\r':
			edit = XL_FALSE;
			xlStringPrintFormatted(str, XL_STRING_SIZE, L"%ls", xlName);
			xlBindImage(img[0]);
			xlImgDeleteTexture();
			xlImgUnload();
			myImgString();
			xlImgGenTexture();
			break;
		default:
		{
			XLstring strtmp;

			if(!edit) { str[0] = L'\0'; edit = XL_TRUE; }
			xlStringCopy(strtmp, str);
			xlStringPrintFormatted(str, XL_STRING_SIZE, L"%ls%c", strtmp, key);
			xlBindImage(img[0]);
			xlImgDeleteTexture();
			xlImgUnload();
			myImgString();
			xlImgGenTexture();
			break;
		}
	}
}

void
demoDisplay(void)
{
	glPushMatrix();
	xlImgTexture();
	glBegin(GL_QUADS);
	xlTexCoord(xlPairCenter); xlVertex2(xlPointLeftUp);
	xlTexCoord(xlPairUp); xlVertex2(xlPointLeftDown);
	xlTexCoord(xlPairRightUp); xlVertex2(xlPointRightDown);
	xlTexCoord(xlPairRight); xlVertex2(xlPointRightUp);
	glEnd();
	glPopMatrix();
}

void
demoTimer(int value)
{
}

void
demoLoad(int *argc, char **argv)
{
	if(*argc < 2) xlStringCopy(str, xlName);
	else xlStringPrintFormatted(str, XL_STRING_SIZE, L"%s", argv[1]);
	edit = XL_FALSE;

	xlGenImages(3, img);
	xlBindImage(img[2]);
	image[2] = xlGetImage();
	xlDataLoad("data/images/Grass.xlc");
	xlImgScale(size[0], size[1]);
	xlBindImage(img[1]);
	image[1] = xlGetImage();
	xlDataLoad("data/images/Textil.xlc");
	xlImgScale(size[0], size[1]);
	xlBindImage(img[0]);
	image[0] = xlGetImage();
	myImgString();
	//xlImgExport("String.png");
	xlImgGenTexture();
}

void
demoUnload()
{
	xlImgDeleteTexture();
	xlImgUnload();
	xlBindImage(img[1]);
	xlImgUnload();
	xlBindImage(img[2]);
	xlImgUnload();
	xlDeleteImages(3, img);
}
