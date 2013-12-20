#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Pivot.xlc";

XLid surf;

void
demoKeyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'z': xlSetInteger(XL_MATERIAL_PROPERTY, 0); xlMatProperty(); break;
		case 'x': xlSetInteger(XL_MATERIAL_PROPERTY, 1); xlMatProperty(); break;
		case 'c': xlSetInteger(XL_MATERIAL_PROPERTY, 2); xlMatProperty(); break;
		default: break;
	}
}

void
demoDisplay(void)
{
	xlSurfBegin();
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
	xlSurfEnd();
}

void
demoTimer(int value)
{
	xlSurfSync();
}

void
demoLoad(int *argc, char **argv)
{
	xlGenSurfaces(1, &surf);
	xlBindSurface(surf);
	if(*argc == 2) xlDataLoad(argv[1]);
	else xlDataLoad("data/surfaces/Test.xlc");
	xlSurfGenMaterial("data/materials");
	xlSurfMaterial();
	xlMatGenImages("data/images");
	xlMatGenTextures();
	xlMatProperty();
}

void
demoUnload()
{
	xlMatDeleteTextures();
	xlSurfDeleteMaterial();
	xlSurfUnload();
	xlDeleteSurfaces(1, &surf);
}
