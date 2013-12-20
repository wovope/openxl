#include "xlDemo.h"
char xlDemoOperatorPath[] = "data/operators/Perspective.xlc";

XLid mod, mat, prts[2];
XLreal fix = XL_REAL(0);

void
demoKeyboard(unsigned char key, int x, int y)
{
	// FIXME: This breaks on non expected animated objects, 3 actions. 
	// FIXME: This breaks on non expected objects, 2 materials, 3 properties each.
	switch(key)
	{
		case '0': xlSetInteger(XL_MODEL_ACTION, 0); break;
		case '1': xlSetInteger(XL_MODEL_ACTION, 1); break;
		case '2': xlSetInteger(XL_MODEL_ACTION, 2); break;
		case 'z': mat = 0; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 0); break;
		case 'x': mat = 0; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 1); break;
		case 'c': mat = 0; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 2); break;
		case 'v': mat = 1; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 0); break;
		case 'b': mat = 1; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 1); break;
		case 'n': mat = 1; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 2); break;
		default: break;
	}

	XLwchar wc;
	mbstowcs(&wc, (const char *) &key, 1);
	//xlPortSetKeyboard(prts[0], wc);
	//xlPortSetKeyboard(prts[1], wc);
}

void
demoDisplay(void)
{
	glPushMatrix();
	xlRotate(fix, xlVectorX);
	xlModCullDraw(XL_RENDER_SOLID);
	glPopMatrix();
}

void
demoTimer(int value)
{
	//xlPortPerform(prts[0]);
	//xlPortPerform(prts[1]);
	//xlPortSetKeyboard(prts[0], 0);
	//xlPortSetKeyboard(prts[1], 0);

	xlModSync();
}

void
demoLoad(int *argc, char **argv)
{
	xlGenModels(1, &mod);
	xlBindModel(mod);

	if(*argc >= 2)
	{
		// FIXME: Mod was lost
		if(xlPathEqual(argv[1] + xlPathLength(argv[1]) - xlPathLength("Robot.xld"), "Robot.xld") ||
		   xlPathEqual(argv[1] + xlPathLength(argv[1]) - xlPathLength("Robot.xlc"), "Robot.xlc"))
			fix = XL_REAL(-90);
		xlDataLoad(argv[1]);
	}
	else
	// NOTE: This should be the unique call.
	xlDataLoad("data/models/Cube.xlc");

	xlModGenObject("data/objects");
	xlObjGenMaterials("data/materials", "data/surfaces");
	xlObjGenImages("data/images");
	xlObjGenTextures();
	xlModGenAnim();
	xlModSync();

	//xlGenPorts(2, prts);
	//xlPortCompile(prts[0], "data/ports/Camera.xld");
	//xlPortCompile(prts[1], argv[2]);
	//xlPortSetOperator(prts[0], xlDemoCamera);
	//xlPortSetModel(prts[1], mod);
}

void
demoUnload()
{
	//xlPortsUnload(2, prts);
	//xlDeletePorts(2, prts);

	xlObjDeleteTextures();
	xlObjDeleteMaterials();
	xlModDeleteAnim();
	xlModDeleteObject();
	xlDeleteModels(1, &mod);
}
