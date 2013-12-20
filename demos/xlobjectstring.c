#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Pivot.xlc";

XLid obj, mat;
XLobject *object;
XLObjectRuntime runtime;
XLchar *material;
XLstring str;
XLboolean edit;

void
myObjString(void)
{
	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	xlVectorAssignReals(xlVectorTMP, XL_REAL(100) / XL_REAL(8) / XL_REAL(xlGetInteger(XL_FONT_PROPERTY_WIDTH)), XL_REAL(100) / XL_REAL(8) / XL_REAL(xlGetInteger(XL_FONT_PROPERTY_HEIGHT)), XL_REAL(100) / XL_REAL(8) / XL_REAL(xlGetInteger(XL_FONT_PROPERTY_WIDTH)));
	xlScale(xlVectorTMP);
	glMatrixMode(GL_MODELVIEW);

	xlObjString(XL_RENDER_SOLID, XL_REAL(1), material, str);

	glMatrixMode(GL_TEXTURE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void
demoKeyboard(unsigned char key, int x, int y)
{
	// FIXME: This breaks on non expected objects, 2 materials, 3 properties each.
	switch(key)
	{
		case '1': mat = 0; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 0); break;
		case '2': mat = 0; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 1); break;
		case '3': mat = 0; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 2); break;
		case '4': mat = 1; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 0); break;
		case '5': mat = 1; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 1); break;
		case '6': mat = 1; xlSetInteger(XL_OBJECT_MATERIAL, mat); xlObjMaterial(); xlSetInteger(XL_MATERIAL_PROPERTY, 2); break;
		case '\r':
			edit = XL_FALSE;
			xlStringPrintFormatted(str, XL_STRING_SIZE, L"%ls", xlName);

			xlMemoryCopy(&runtime, &object->runtime, xlObjS(Runtime));
			xlObjUnload();
			myObjString();
			xlMemoryCopy(&object->runtime, &runtime, xlObjS(Runtime));
			break;
		default:
		{
			XLstring strtmp;

			if(!edit) { str[0] = L'\0'; edit = XL_TRUE; }
    			xlStringCopy(strtmp, str);
			xlStringPrintFormatted(str, XL_STRING_SIZE, L"%ls%c", strtmp, key);

			xlMemoryCopy(&runtime, &object->runtime, xlObjS(Runtime));
			xlObjUnload();
			myObjString();
			xlMemoryCopy(&object->runtime, &runtime, xlObjS(Runtime));
			break;
		}
	}
}

void
demoDisplay(void)
{
	XLvector scale;
	XLpoint translation;
	XLreal aspect;

	glPushMatrix();

	aspect = object->body.bound->dimensions[0] / object->body.bound->dimensions[1]; 
	xlVectorAssignReals(&scale, XL_REAL(50) / object->body.bound->dimensions[0], XL_REAL(50) / object->body.bound->dimensions[1] / aspect, XL_REAL(7.5) / aspect);
	xlScale(&scale);

	xlPointAssignArray(&translation, object->body.bound->dimensions);
	xlPointAssignReals(xlPointTMP, XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(0.5));
	xlPointMult(&translation, xlPointTMP);
	xlTranslate(&translation);

	xlObjCullDraw(XL_RENDER_SOLID);

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
	//glDisable(GL_LIGHT1);
	//glDisable(GL_LIGHT2);

	if(*argc < 2) xlStringCopy(str, xlName);
	else xlStringPrintFormatted(str, XL_STRING_SIZE, L"%s", argv[1]);
	if(*argc < 3) material = "Default.xlc";
	else material = argv[2];
	edit = XL_FALSE;

	xlGenObjects(1, &obj);
	xlBindObject(obj);
	object = xlGetObject();

	myObjString();
	xlObjGenMaterials("data/materials", "data/surfaces");
	xlObjGenImages("data/images");
	xlObjGenTextures();

	//xlObjDecompile("String.xld");

	xlMemoryCopy(&runtime, &object->runtime, xlObjS(Runtime));
}

void
demoUnload()
{
	xlObjDeleteTextures();
	xlObjDeleteImages();
	xlObjDeleteMaterials();
	xlObjUnload();
	xlDeleteObjects(1, &obj);
}
