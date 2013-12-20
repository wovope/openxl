#include "XL/xlDelete.h"
#include "XL/xl.h"

void
xlDeleteStores(XLsizei n, const XLid *stores)
{
	XLsizei i;
	for(i = 1; i < n; i++)
	{
		xlFree(xlStores.data[stores[i]]);
		xlStores.data[stores[i]] = 0;
	}
}

void
xlDeleteBinds(XLsizei n, const XLid *binds)
{
	XLstore *store = xlStores.data[xlBinds];
	XLsizei i;
	for(i = 1; i < n; i++)
	{
		xlFree(store->data[binds[i]]);
		store->data[binds[i]] = NULL;
	}
}

void
xlDeleteIds(XLstore *store, XLsizei n, const XLid *ids)
{
	XLsizei i;
	for(i = 1; i < n; i++)
	{
		xlFree(store->data[ids[i]]);
		store->data[ids[i]] = NULL; 
	}
}

void
xlDeleteMetaHeaders(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_METAHEADER);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteMetaDatas(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_METADATA);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteMetas(XLsizei n, const XLid *mhids, const XLid *mdids)
{
	xlDeleteMetaHeaders(n, mhids);
	xlDeleteMetaDatas(n, mdids);
}

void
xlDeleteImages(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_IMAGE);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteFonts(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_FONT);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteMaterials(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_MATERIAL);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteSurfaces(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_SURFACE);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteObjects(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_OBJECT);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteModels(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_MODEL);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteParticles(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_PARTICLES);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteCameras(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_CAMERA);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteOperators(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_OPERATOR);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteViewports(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_VIEWPORT);

	xlDeleteIds(store, n, ids);
}

void
xlDeleteWindows(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_WINDOW);

	xlDeleteIds(store, n, ids);
}

void
xlMatDeleteImages(void)
{
	XLmaterial *bind = xlGetMaterial();
	XLuint i;

	for(i = 0; i < bind->header.properties; i++)
		xlImgUnload();
	xlDeleteImages(bind->header.properties, bind->runtime.images);
	xlFree(bind->runtime.images);
}

void
xlMatDeleteTextures(void)
{
	XLmaterial *bind = xlGetMaterial();
	XLuint i;

	for(i = 0; i < bind->header.properties; i++)
	{
		xlBindImage(bind->runtime.images[i]);
		xlImgDeleteTexture();
	}
}

void
xlSurfDeleteMaterial(void)
{
	XLsurface *bind = xlGetSurface();

	xlSurfMaterialProperty();
	xlMatUnload();
	xlDeleteMaterials(1, &bind->runtime.material);
}

void
xlObjDeleteMaterials(void)
{
	XLobject *bind = xlGetObject();
	XLObjectMaterial *material;

	for(bind->runtime.material = 0; bind->runtime.material < bind->header.materials; bind->runtime.material++)
	{
		xlObjMaterial();

		material = &bind->body.materials[bind->runtime.material];

		if(material->surface)
		{
			xlSurfDeleteMaterial();
			xlSurfUnload();
			xlDeleteSurfaces(1, &bind->runtime.materials[bind->runtime.material]);
		}
		else
		{
			xlMatUnload();
			xlDeleteMaterials(1, &bind->runtime.materials[bind->runtime.material]);
		}
	}
	xlFree(bind->runtime.materials);
}

void
xlObjDeleteImages(void)
{
	XLobject *bind = xlGetObject();

	for(bind->runtime.material = 0; bind->runtime.material < bind->header.materials; bind->runtime.material++)
	{
		xlObjMaterial();
		xlMatDeleteImages();
	}
}

void
xlObjDeleteTextures(void)
{
	XLobject *bind = xlGetObject();

	for(bind->runtime.material = 0; bind->runtime.material < bind->header.materials; bind->runtime.material++)
	{
		xlObjMaterial();
		xlMatDeleteTextures();
	}
}

void
xlObjDeleteVertices(void)
{
	XLobject *bind = xlGetObject();

	xlFree(bind->runtime.vertices);
}

void
xlModDeleteObject(void)
{
	XLmodel *bind = xlGetModel();

	xlModObject();
	xlObjUnload();
	xlDeleteObjects(1, &bind->runtime.object);
}

void
xlModDeleteAnim(void)
{
	XLmodel *bind = xlGetModel();

	xlFree(bind->runtime.anim[2]);
	xlFree(bind->runtime.anim[1]);
	xlFree(bind->runtime.anim[0]);
}

void
xlOpDeleteCamera(void)
{
	XLoperator *bind = xlGetOperator();

	xlOpCamera();
	xlCamUnload();
	xlDeleteCameras(1, &bind->runtime.camera);
}
