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
xlDeleteIdentifiers(XLstore *store, XLsizei n, const XLid *ids)
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

	xlDeleteIdentifiers(store, n, ids);
}

void
xlDeleteMetaDatas(XLsizei n, const XLid *ids)
{
	XLstore *store = xlGetStore(XL_METADATA);

	xlDeleteIdentifiers(store, n, ids);
}

void
xlDeleteMetas(XLsizei n, const XLid *mhids, const XLid *mdids)
{
	xlDeleteMetaHeaders(n, mhids);
	xlDeleteMetaDatas(n, mdids);
}

#define _xlDeleteIdentifiers(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xlDelete ## Identifiers (XLsizei n, XLid *ids) \
	{ \
		XLstore *store = xlGetStore(XL_ ## IDENTIFIER); \
 		\
		xlDeleteIdentifiers(store, n, ids); \
	}
		
xlIdForEach(_xlDeleteIdentifiers)

#undef _xlDeleteIdentifiers

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
