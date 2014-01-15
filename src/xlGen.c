#include "XL/xlGen.h"
#include "XL/xl.h"

void
xlGenStores(XLsizei n, XLid *stores)
{
	XLsizei i, g;
	for(i = 1, g = 0; i < XL_STORE_SIZE && g < n; i++)
	{
		if(!xlStores.data[i])
		{
			xlStores.data[i] = xlAlloc(sizeof(XLstore));
			xlMemoryZero(xlStores.data[i], sizeof(XLstore));
			stores[g++] = i;
		}
	}
}

void
xlGenBinds(XLsizei n, XLid *binds)
{
	XLstore *store = xlStores.data[xlBinds];
	XLsizei i, g;
	for(i = 1, g = 0; i < XL_STORE_SIZE && g < n; i++)
	{
		if(!store->data[i]) 
		{
			store->data[i] = xlAlloc(sizeof(XLbind));
			xlMemoryZero(store->data[i], sizeof(XLbind));
			binds[g++] = i;
		}
	}
}

void
xlGenIdentifiers(XLstore *store, XLsizei size, XLsizei n, XLid *ids)
{
	XLsizei i, g;
	for(i = 1, g = 0; i < XL_STORE_SIZE && g < n; i++)
	{
		if(!store->data[i]) 
		{
			store->data[i] = xlAlloc(size);
			xlMemoryZero(store->data[i], size);
			ids[g++] = i;
		}
	}
}

void
xlGenMetaHeaders(XLsizei n, XLid *ids)
{
	XLstore *store = xlGetStore(XL_METAHEADER);

	xlGenIdentifiers(store, sizeof(XLmetaheader), n, ids);
}

void
xlGenMetaDatas(XLsizei n, XLid *ids)
{
	XLstore *store = xlGetStore(XL_METADATA);

	xlGenIdentifiers(store, sizeof(XLmetadata), n, ids);
}

void
xlGenMetas(XLsizei n, XLid *mhids, XLid *mdids)
{
	xlGenMetaHeaders(n, mhids);
	xlGenMetaDatas(n, mdids);
}

#define _xlGenIdentifiers(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xlGen ## Identifiers (XLsizei n, XLid *ids) \
	{ \
		XLstore *store = xlGetStore(XL_ ## IDENTIFIER); \
		\
		xlGenIdentifiers(store, sizeof(XL ## identifier), n, ids); \
	}
		
xlIdForEach(_xlGenIdentifiers)

#undef _xlGenIdentifiers

void
xlMatGenImages(const XLpath path)
{
	XLmaterial *bind = xlGetMaterial();
	XLuint i;

	bind->runtime.images = xlAlloc(bind->header.properties * sizeof(XLuint));
	xlGenImages(bind->header.properties, bind->runtime.images);
	for(i = 0; i < bind->header.properties; i++)
	{
		XLpathbuffer buffer;
		XLsize lbuffer;

		xlBindImage(bind->runtime.images[i]);

		lbuffer = xlPathPrintFormatted(buffer, XL_PATH_BUFFER_SIZE, "%s" XL_PATH_SEPARATOR "%s", path, bind->body.properties[i].image);
		if(lbuffer > 3 && xlPathEqual(buffer + lbuffer - 3, ".xl"))
			xlDataLoad(buffer);
		else if(lbuffer > 4 && xlPathEqual(buffer + lbuffer - 4, ".xlc"))
			xlImgLoad(buffer);
		else if(lbuffer > 4 && xlPathEqual(buffer + lbuffer - 4, ".xld"))
			xlImgCompile(buffer);
		else
			xlImgImport(buffer);
	}
}

void
xlMatGenTextures(void)
{
	XLmaterial *bind = xlGetMaterial();
	XLuint i;

	for(i = 0; i < bind->header.properties; i++)
	{
		xlBindImage(bind->runtime.images[i]);
		xlImgGenTexture();
	}
}

void
xlSurfGenMaterial(const XLchar *path)
{
	XLsurface *bind = xlGetSurface();
	XLpathbuffer buffer;
	XLsizei lbuffer;

	xlGenMaterials(1, &bind->runtime.material);
	xlSurfMaterial();

	lbuffer = xlPathPrintFormatted(buffer, XL_PATH_BUFFER_SIZE, "%s" XL_PATH_SEPARATOR "%s", path, bind->body.material->path);
	if(lbuffer > 3 && xlPathEqual(buffer + lbuffer - 3, ".xl"))
		xlDataLoad(buffer);
	else if(lbuffer > 4 && xlPathEqual(buffer + lbuffer - 4, ".xlc"))
		xlMatLoad(buffer);
	else if(lbuffer > 4 && xlPathEqual(buffer + lbuffer - 4, ".xld"))
		xlMatCompile(buffer);
	else
		xlMatLoad(buffer);
}

void
xlObjGenMaterials(const XLpath matpath, const XLpath animmatpath)
{
	XLobject *bind = xlGetObject();
	XLObjectMaterial *material;
	XLpathbuffer buffer;
	XLsizei lbuffer;

	bind->runtime.materials = xlAlloc(bind->header.materials * sizeof(XLuint));
	for(bind->runtime.material = 0; bind->runtime.material < bind->header.materials; bind->runtime.material++)
	{

		material = &bind->body.materials[bind->runtime.material];

		if(material->surface)
			xlGenSurfaces(1, &bind->runtime.materials[bind->runtime.material]);
		else
			xlGenMaterials(1, &bind->runtime.materials[bind->runtime.material]);
		xlObjMaterial();

		if(material->surface)
			lbuffer = xlPathPrintFormatted(buffer, XL_PATH_BUFFER_SIZE, "%s" XL_PATH_SEPARATOR "%s", animmatpath, material->path);
		else
			lbuffer = xlPathPrintFormatted(buffer, XL_PATH_BUFFER_SIZE, "%s" XL_PATH_SEPARATOR "%s", matpath, material->path);

		if(xlPathLength(buffer) > 3 && xlPathEqual(buffer + lbuffer - 3, ".xl"))
			xlDataLoad(buffer);
		else if(xlPathLength(buffer) > 4 && xlPathEqual(buffer + lbuffer - 4, ".xlc"))
		{
			if(material->surface)
				xlSurfLoad(buffer);
			else
				xlMatLoad(buffer);
		}
		else if(xlPathLength(buffer) > 4 && xlPathEqual(buffer + lbuffer - 4, ".xld"))
		{
			if(material->surface)
				xlSurfCompile(buffer);
			else
				xlMatCompile(buffer);
		}
		else
		{
			if(material->surface)
				xlSurfLoad(buffer);
			else
				xlMatLoad(buffer);
		}

		if(material->surface)
			xlSurfGenMaterial(matpath);
	}
}

void
xlObjGenImages(const XLpath path)
{
	XLobject *bind = xlGetObject();

	for(bind->runtime.material = 0; bind->runtime.material < bind->header.materials; bind->runtime.material++)
	{
		xlObjMaterial();
		xlMatGenImages(path);
	}
}

void
xlObjGenTextures(void)
{
	XLobject *bind = xlGetObject();

	for(bind->runtime.material = 0; bind->runtime.material < bind->header.materials; bind->runtime.material++)
	{
		xlObjMaterial();
		xlMatGenTextures();
	}
}

void
xlObjGenVertices(void)
{
	XLobject *bind = xlGetObject();

	bind->runtime.vertices = xlAlloc(bind->header.faces * 3 * sizeof(XLvertex));
}

void
xlModGenObject(const XLchar *path)
{
	XLmodel *bind = xlGetModel();
	XLpathbuffer buffer;
	XLsizei lbuffer;

	xlGenObjects(1, &bind->runtime.object);
	xlModObject();

	lbuffer = xlPathPrintFormatted(buffer, XL_PATH_BUFFER_SIZE, "%s" XL_PATH_SEPARATOR "%s", path, bind->body.object->path);
	if(lbuffer > 3 && xlPathEqual(buffer + lbuffer - 3, ".xl"))
		xlDataLoad(buffer);
	else if(lbuffer > 4 && xlPathEqual(buffer + lbuffer - 4, ".xlc"))
		xlObjLoad(buffer);
	else if(lbuffer > 4 && xlPathEqual(buffer + lbuffer - 4, ".xld"))
		xlObjCompile(buffer);
	else
		xlObjLoad(buffer);
}

void
xlModGenAnim(void)
{
	XLmodel *bind = xlGetModel();
	XLobject *object;
	
	xlModObject();
	object = xlGetObject();

	bind->runtime.anim[0] = xlAlloc(object->header.vertices * sizeof(XLpoint));
	bind->runtime.anim[1] = xlAlloc(object->header.vertices * sizeof(XLpoint));
	bind->runtime.anim[2] = xlAlloc(object->header.vertices * sizeof(XLpoint));
}

void
xlOpGenCamera(const XLpath path)
{
	XLoperator *bind = xlGetOperator();
	XLpathbuffer buffer;
	XLsizei lbuffer;

	xlGenCameras(1, &bind->runtime.camera);
	xlOpCamera();

	lbuffer = xlPathPrintFormatted(buffer, XL_PATH_BUFFER_SIZE, "%s" XL_PATH_SEPARATOR "%s", path, bind->body.camera->path);
	if(lbuffer > 3 && xlPathEqual(buffer + lbuffer - 3, ".xl"))
		xlDataLoad(buffer);
	else if(lbuffer > 4 && xlPathEqual(buffer + lbuffer - 4, ".xlc"))
		xlCamLoad(buffer);
	else if(lbuffer > 4 && xlPathEqual(buffer + lbuffer - 4, ".xld"))
		xlCamCompile(buffer);
	else
		xlCamLoad(buffer);
}
