#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Pivot.xlc";

XLid img; 
XLuint t;

void
demoKeyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case '0': t = 0;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case '1': t = 1;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case '2': t = 2;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case '3': t = 3;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case '4': t = 4;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case '5': t = 5;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case '6': t = 6;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case '7': t = 7;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case '8': t = 8;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case '9': t = 9;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case 't': t = (t + 1) % 10;
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
			xlImgGenTexture();
			break;
		case 'l':
			xlBindImage(img);
			xlImgDeleteTexture();
			xlImgUnload();
			xlImgImport("data/images/Tux.png");
			xlImgGenTexture();
			break;
		default: break;
	}
}

void
demoDisplay(void)
{
	glPushMatrix();
	xlScale(xlVectorAssignMultReal(xlVectorTMP, xlVectorOne, XL_REAL(15)));
	glBegin(GL_QUADS);

	xlTexCoord(xlPairCenter); xlVertex(xlPointFrontLeftUp);
	xlTexCoord(xlPairUp); xlVertex(xlPointFrontLeftDown);
	xlTexCoord(xlPairRightUp); xlVertex(xlPointFrontRightDown);
	xlTexCoord(xlPairRight); xlVertex(xlPointFrontRightUp);

	xlTexCoord(xlPairCenter); xlVertex(xlPointBackRightUp);
	xlTexCoord(xlPairUp); xlVertex(xlPointBackRightDown);
	xlTexCoord(xlPairRightUp); xlVertex(xlPointBackLeftDown);
	xlTexCoord(xlPairRight); xlVertex(xlPointBackLeftUp);

	xlTexCoord(xlPairCenter); xlVertex(xlPointFrontRightUp);
	xlTexCoord(xlPairUp); xlVertex(xlPointFrontRightDown);
	xlTexCoord(xlPairRightUp); xlVertex(xlPointBackRightDown);
	xlTexCoord(xlPairRight); xlVertex(xlPointBackRightUp);

	xlTexCoord(xlPairCenter); xlVertex(xlPointBackLeftUp);
	xlTexCoord(xlPairUp); xlVertex(xlPointBackLeftDown);
	xlTexCoord(xlPairRightUp); xlVertex(xlPointFrontLeftDown);
	xlTexCoord(xlPairRight); xlVertex(xlPointFrontLeftUp);

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
	xlGenImages(1, &img);
	xlBindImage(img);
	myImage(XL_DATA_LOAD, "/data/images/multit", 512, 512, t);
	xlImgGenTexture();
	t = 0;
}

void
demoUnload()
{
	xlBindImage(img);
	xlImgDeleteTexture();
	xlImgUnload();
	xlDeleteImages(1, &img);
}
