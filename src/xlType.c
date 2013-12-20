#include "XL/xlType.h"
#include "XL/xl.h"

void
xlMetHeadType(XLmetaheader *type)
{
	XLmetaheader *bind = xlGetMetaHeader();

	xlMemoryCopy(bind, type, sizeof(XLmetaheader));
	xlMetHeadLog();
}

void
xlMetDatType(XLmetadata *type)
{
	XLmetadata *bind = xlGetMetaData();

	xlMemoryCopy(bind, type, sizeof(XLmetadata));
	xlMetDatLog();
}

void
xlMetType(XLmetaheader *mhtype, XLmetadata *mdtype)
{
	XLmetaheader *mhbind = xlGetMetaHeader();
	XLmetadata *mdbind = xlGetMetaData();

	xlMemoryCopy(mhbind, mhtype, sizeof(XLmetaheader));
	xlMemoryCopy(mdbind, mdtype, sizeof(XLmetadata));
	xlMetLog();
}

void
xlImgType(XLimage *type)
{
	XLimage *bind = xlGetImage();

	xlMemoryCopy(bind, type, sizeof(XLimage));
	xlImgLog();
}

void
xlMatType(XLmaterial *type)
{
	XLmaterial *bind = xlGetMaterial();

	xlMemoryCopy(bind, type, sizeof(XLmaterial));
	xlMatLog();
}

void
xlSurfType(XLsurface *type)
{
	XLsurface *bind = xlGetSurface();

	xlMemoryCopy(bind, type, sizeof(XLsurface));
	xlSurfLog();
}

void
xlObjType(XLobject *type)
{
	XLobject *bind = xlGetObject();

	xlMemoryCopy(bind, type, sizeof(XLobject));
	xlObjLog();
}

void
xlModType(XLmodel *type)
{
	XLmodel *bind = xlGetModel();

	xlMemoryCopy(bind, type, sizeof(XLmodel));
	xlModLog();
}

void
xlPartsType(XLparticles *type)
{
	XLparticles *bind = xlGetParticles();

	xlMemoryCopy(bind, type, sizeof(XLparticles));
	xlPartsLog();
}

void
xlPartsTypeParticle(XLuint particle, XLparticle *type)
{
	XLparticles *particles = xlGetParticles();

	particles->runtime.particles[particle] = *type;
}

void
xlCamType(XLcamera *type)
{
	XLcamera *bind = xlGetCamera();

	xlMemoryCopy(bind, type, sizeof(XLcamera));
	xlCamLog();
}

void
xlOpType(XLoperator *type)
{
	XLoperator *bind = xlGetOperator();

	xlMemoryCopy(bind, type, sizeof(XLoperator));
	xlOpLog();
}

void
xlViewType(XLviewport *type)
{
	XLviewport *bind = xlGetViewport();

	xlMemoryCopy(bind, type, sizeof(XLviewport));
	xlViewLog();
}

void
xlWinType(XLwindow *type)
{
	XLwindow *bind = xlGetWindow();

	xlMemoryCopy(bind, type, sizeof(XLwindow));
	xlWinLog();
}
