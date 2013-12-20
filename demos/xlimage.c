#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Ortho.xlc";

XLid img;
XLuint t;

void
demoKeyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 't': t = (t + 1) % 10;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case 'd':
			xlBindImage(img);
			xlImgDecompile("Image.xld");
			break;
		case 'c':
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			xlImgCompile("Image.xld");
			xlImgGenTexture();
			break;
		case 's':
			xlBindImage(img);
			xlImgSave("Image.xlc");
			break;
		case 'r':
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			xlImgLoad("Image.xlc");
			xlImgGenTexture();
			break;
		case 'l':
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			xlImgImport("data/images/Tux.png");
			xlImgGenTexture();
			break;
		default:
			break;
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
	t = 5;
	xlGenImages(1, &img);
	xlBindImage(img);
	if(*argc == 2)
		xlDataLoadImage(argv[1]);
	else
		myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
	xlImgGenTexture();
}

void
demoUnload()
{
	xlBindImage(img);
	xlImgDeleteTexture();
	xlImgUnload();
	xlDeleteImages(1, &img);
}
