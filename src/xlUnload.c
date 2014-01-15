#include "XL/xlUnload.h"
#include "XL/xl.h"

void
xlMetHeadUnload(void)
{
}

void
xlMetDatUnload(void)
{
}

void
xlMetUnload(void)
{
}

void
xlImgUnload(void)
{
	XLimage *bind = xlGetImage();

	xlFree(bind->body.pixels);

	xlMemoryZero(bind, sizeof(XLimage));
}

void
xlFntUnload(void)
{
	XLfont *bind = xlGetFont();

	xlFree(bind->body.properties);

	xlMemoryZero(bind, sizeof(XLfont));
}

void
xlMatUnload(void)
{
	XLmaterial *bind = xlGetMaterial();

	xlFree(bind->body.properties);

	xlMemoryZero(bind, sizeof(XLmaterial));
}

void
xlSurfUnload(void)
{
	XLsurface *bind = xlGetSurface();

	xlFree(bind->body.actions);
	xlFree(bind->body.frames);
	xlFree(bind->body.material);

	xlMemoryZero(bind, sizeof(XLsurface));
}

void
xlObjUnload(void)
{
	XLobject *bind = xlGetObject();

	xlFree(bind->body.bound);
	xlFree(bind->body.tags);
	xlFree(bind->body.faces);
	xlFree(bind->body.materials);
	xlFree(bind->body.vertices);

	xlMemoryZero(bind, sizeof(XLobject));
}

void
xlModUnload(void)
{
	XLmodel *bind = xlGetModel();
	XLuint i;

	xlFree(bind->body.actions);
	for(i = 0; i < bind->header.frames; i++)
		xlFree(bind->body.frames[i].bones);
	xlFree(bind->body.frames);
	xlFree(bind->body.weights);
	xlFree(bind->body.tags);
	xlFree(bind->body.vertices);
	xlFree(bind->body.parents);
	xlFree(bind->body.bones);
	xlFree(bind->body.object);

	xlMemoryZero(bind, sizeof(XLmodel));
}

void
xlPartsUnload(void)
{
	XLparticles *bind = xlGetParticles();

	xlMemoryZero(bind, sizeof(XLparticles));
}

void
xlCamUnload(void)
{
	XLcamera *bind = xlGetCamera();

	xlFree(bind->body.properties);

	xlMemoryZero(bind, sizeof(XLcamera));
}

void
xlOpUnload(void)
{
	XLoperator *bind = xlGetOperator();

	xlFree(bind->body.actions);
	xlFree(bind->body.frames);
	xlFree(bind->body.camera);

	xlMemoryZero(bind, sizeof(XLoperator));
}

void
xlVptUnload(void)
{
	XLviewport *bind = xlGetViewport();

	xlFree(bind->body.properties);

	xlMemoryZero(bind, sizeof(XLviewport));
}


void
xlWinUnload(void)
{
	XLwindow *bind = xlGetWindow();

	xlFree(bind->body.properties);

	xlMemoryZero(bind, sizeof(XLwindow));
}
