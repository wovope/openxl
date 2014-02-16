#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Pivot.xlc";

XLid obj, mat;
XLreal fix = XL_REAL(0), num;
XLenum mode = XL_RENDER_SOLID;

void
demoKeyboard(unsigned char key, int x, int y)
{
	// FIXME: This breaks on non expected objects, 2 materials, 3 properties each.
	switch(key)
	{
		case 'z': mat = 0; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 0); break;
		case 'x': mat = 0; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 1); break;
		case 'c': mat = 0; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 2); break;
		case 'v': mat = 1; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 0); break;
		case 'b': mat = 1; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 1); break;
		case 'n': mat = 1; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 2); break;
		case 's': mode = XL_RENDER_SOLID; break;
		case 'w': mode = XL_RENDER_WIRE; break;
		case 'p': mode = XL_RENDER_POINTS; break;
		default: break;
	}
}

void
demoDisplay(void)
{
	XLint i;

	glPushMatrix();
	xlRotate(fix, xlVectorX);
	//xlObjCullDraw(mode);
	for(xlSetInteger(XL_OBJECT_MATERIAL, 0); xlGetInteger(XL_OBJECT_MATERIAL) < xlGetInteger(XL_OBJECT_MATERIALS); xlSetInteger(XL_OBJECT_MATERIAL, xlGetInteger(XL_OBJECT_MATERIAL) + 1))
	{
		xlObjMaterialBegin();
		for(i = 0; i < num; i++)
		{
			xlMatrixTranslate(xlGetMatrix(XL_OBJECT_MATRIX), xlPointAssignReals(xlPointTMP, (XL_REAL(i) - XL_REAL(num - 1) / XL_REAL(2)) * XL_REAL(20), XL_REAL(0), XL_REAL(0)));
			xlObjBegin();
			xlObjCullDrawVerticesMaterial(mode);
			xlObjEnd();
			xlMatrixAssignIdentity(xlGetMatrix(XL_OBJECT_MATRIX));
		}
		xlObjMaterialEnd();
	}
	glPopMatrix();
}

void
demoTimer(int value)
{
	xlObjSync();
}

void
demoLoad(int *argc, char **argv)
{
	//glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);

	xlGenObjects(1, &obj);
	xlBindObject(obj);
	if(*argc >= 2)
	{
		// FIXME: Mod was lost
		if(xlPathEqual(argv[1] + xlPathLength(argv[1]) - xlPathLength("Robot.xld"), "Robot.xld") ||
		   xlPathEqual(argv[1] + xlPathLength(argv[1]) - xlPathLength("Robot.xlc"), "Robot.xlc"))
			fix = XL_REAL(-90);
		xlDataLoad(argv[1]);
	}
	else xlDataLoad("data/objects/Cube.xlc");
	if(*argc >= 3) num = atof(argv[2]);
	else num = 1;

	xlObjGenMaterials("data/materials", "data/surfaces");
	xlObjGenImages("data/images");
	xlObjGenTextures();
	xlObjGenVertices();
	xlObjVertices();
}

void
demoUnload()
{
	xlObjDeleteVertices();
	xlObjDeleteTextures();
	xlObjDeleteMaterials();
	xlObjUnload();
	xlDeleteObjects(1, &obj);
}
