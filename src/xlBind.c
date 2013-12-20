#include "XL/xlBind.h"
#include "XL/xl.h"

void
xlBindStore(XLid id)
{
	xlStores.bind = id;
}

void
xlBindBind(XLid id)
{
	XLstore *store = xlStores.data[xlBinds];

	store->bind = id;
}

void
xlBindMetaHeader(XLid id)
{
	XLstore *store = xlGetStore(XL_METAHEADER);

	store->bind = id;
}

void
xlBindMetaData(XLid id)
{
	XLstore *store = xlGetStore(XL_METADATA);

	store->bind = id;
}

void
xlBindMeta(XLid mhid, XLid mdid)
{
	xlBindMetaHeader(mhid);
	xlBindMetaData(mdid);
}

void
xlBindImage(XLid id)
{
	XLstore *store = xlGetStore(XL_IMAGE);

	store->bind = id;
}

void
xlBindFont(XLid id)
{
	XLstore *store = xlGetStore(XL_FONT);

	store->bind = id;
}

void
xlBindMaterial(XLid id)
{
	XLstore *store = xlGetStore(XL_MATERIAL);

	store->bind = id;
}

void
xlBindSurface(XLid id)
{
	XLstore *store = xlGetStore(XL_SURFACE);

	store->bind = id;
}

void
xlBindObject(XLid id)
{
	XLstore *store = xlGetStore(XL_OBJECT);

	store->bind = id;
}

void
xlBindModel(XLid id)
{
	XLstore *store = xlGetStore(XL_MODEL);

	store->bind = id;
}

void
xlBindParticles(XLid id)
{
	XLstore *store = xlGetStore(XL_PARTICLES);

	store->bind = id;
}

void
xlBindCamera(XLid id)
{
	XLstore *store = xlGetStore(XL_CAMERA);

	store->bind = id;
}

void
xlBindOperator(XLid id)
{
	XLstore *store = xlGetStore(XL_OPERATOR);

	store->bind = id;
}

void
xlBindViewport(XLid id)
{
	XLstore *store = xlGetStore(XL_VIEWPORT);

	store->bind = id;
}

void
xlBindWindow(XLid id)
{
	XLstore *store = xlGetStore(XL_WINDOW);

	store->bind = id;
}
