#include "XL/xlLoad.h"
#include "XL/xl.h"

void
xlMetHeadLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");

	if(stream)
	{
		XLmetaheader *metaheader = xlGetMetaHeader();
		xlFileRead(metaheader, 1, sizeof(XLmetaheader), stream);

		xlPathCopy(metaheader->path, filepath);
		xlMetHeadLog();

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMetDatLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");

	if(stream)
	{
		XLmetadata *metadata = xlGetMetaData();
		xlFileRead(metadata, 1, sizeof(XLmetadata), stream);

		xlMetDatLog();

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMetLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");

	if(stream)
	{
		XLmetaheader *metaheader = xlGetMetaHeader();
		XLmetadata *metadata = xlGetMetaData();

		xlFileRead(metaheader, 1, sizeof(XLmetaheader), stream);
		xlFileRead(metadata, 1, sizeof(XLmetadata), stream);

		xlPathCopy(metaheader->path, filepath);
		xlMetLog();

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlImgLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");

	if(stream)
	{
		XLimage *bind = xlGetImage();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileRead(&bind->header, 1, xlImgS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: width: %i\n", filepath, bind->header.width);
		xlLog(L"%s: height: %i\n", filepath, bind->header.height);
		xlLog(L"%s: bpp: %i\n", filepath, bind->header.bpp);
		bind->body.pixels = xlAlloc(bind->header.width  * bind->header.height * sizeof(XLcolor));
		xlFileRead(bind->body.pixels, sizeof(XLcolor), bind->header.width  * bind->header.height, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlFntLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");

	if(stream)
	{
		XLfont *bind = xlGetFont();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileRead(&bind->header, 1, xlFntS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: properties: %i\n", filepath, bind->header.properties);
		bind->body.properties = xlAlloc(bind->header.properties * xlFntS(Property));
		xlFileRead(bind->body.properties, xlFntS(Property), bind->header.properties, stream);
		xlFileRead(bind->body.path, sizeof(XLpath), 1, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMatLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");

	if(stream)
	{
		XLmaterial *bind = xlGetMaterial();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileRead(&bind->header, 1, xlMatS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: properties: %i\n", filepath, bind->header.properties);
		bind->body.properties = xlAlloc(bind->header.properties * xlMatS(Property));
		xlFileRead(bind->body.properties, xlMatS(Property), bind->header.properties, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlSurfLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");

	if(stream)
	{
		XLsurface *bind = xlGetSurface();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileRead(&bind->header, 1, xlSurfS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: material\n", filepath);
		bind->body.material = xlAlloc(xlSurfS(Material));
		xlFileRead(bind->body.material, 1, xlSurfS(Material), stream);

		xlLog(L"%s: frames: %i\n", filepath, bind->header.frames);
		bind->body.frames = xlAlloc(bind->header.frames * xlSurfS(Frame));
		xlFileRead(bind->body.frames, xlSurfS(Frame), bind->header.frames, stream);

		xlLog(L"%s: actions: %i\n", filepath, bind->header.actions);
		bind->body.actions = xlAlloc(bind->header.actions * xlSurfS(Action));
		xlFileRead(bind->body.actions, xlSurfS(Action), bind->header.actions, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlObjLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");
	if(stream)
	{
		XLobject *bind = xlGetObject();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileRead(&bind->header, 1, xlObjS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: vertices: %i\n", filepath, bind->header.vertices);
		bind->body.vertices = xlAlloc(bind->header.vertices * xlObjS(Vertex));
		xlFileRead(bind->body.vertices, bind->header.vertices, xlObjS(Vertex), stream);

		xlLog(L"%s: materials: %i\n", filepath, bind->header.materials);
		bind->body.materials = xlAlloc(bind->header.materials * xlObjS(Material));
		xlFileRead(bind->body.materials, bind->header.materials, xlObjS(Material), stream);

		xlLog(L"%s: faces: %i\n", filepath, bind->header.faces);
		bind->body.faces = xlAlloc(bind->header.faces * xlObjS(Face));
		xlFileRead(bind->body.faces, bind->header.faces, xlObjS(Face), stream);

		xlLog(L"%s: tags: %i\n", filepath, bind->header.tags);
		bind->body.tags = xlAlloc(bind->header.tags * xlObjS(Tag));
		xlFileRead(bind->body.tags, bind->header.tags, xlObjS(Tag), stream);

		xlLog(L"%s: bound\n", filepath);
		bind->body.bound = xlAlloc(1 * xlObjS(Bound));
		xlFileRead(bind->body.bound, 1, xlObjS(Bound), stream);

		xlMatrixAssignIdentity(&bind->runtime.matrix);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlModLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");
	if(stream)
	{
		XLmodel *bind = xlGetModel();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLuint i;

		xlFileRead(&bind->header, 1, xlModS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: object\n", filepath);
		bind->body.object = xlAlloc(xlModS(Object));
		xlFileRead(bind->body.object, 1, xlModS(Object), stream);

		xlLog(L"%s: bones: %i\n", filepath, bind->header.bones);
		bind->body.bones = xlAlloc(bind->header.bones * xlModS(Bone));
		xlFileRead(bind->body.bones, bind->header.bones, xlModS(Bone), stream);

		xlLog(L"%s: parents: %i\n", filepath, bind->header.parents);
		bind->body.parents = xlAlloc(bind->header.parents * xlModS(Parent));
		xlFileRead(bind->body.parents, bind->header.parents, xlModS(Parent), stream);

		xlLog(L"%s: vertices: %i\n", filepath, bind->header.vertices);
		bind->body.vertices = xlAlloc(bind->header.vertices * xlModS(Vertex));
		xlFileRead(bind->body.vertices, bind->header.vertices, xlModS(Vertex), stream);

		xlLog(L"%s: tags: %i\n", filepath, bind->header.tags);
		bind->body.tags = xlAlloc(bind->header.tags * xlModS(Tag));
		xlFileRead(bind->body.tags, bind->header.tags, xlModS(Tag), stream);

		xlLog(L"%s: weights: %i\n", filepath, bind->header.weights);
		bind->body.weights = xlAlloc(bind->header.weights * xlModS(Weight));
		xlFileRead(bind->body.weights, bind->header.weights, xlModS(Weight), stream);

		xlLog(L"%s: frames: %i\n", filepath, bind->header.frames);
		bind->body.frames = xlAlloc(bind->header.frames * xlModS(Frame));
		for(i = 0; i < bind->header.frames; i++)
		{
			bind->body.frames[i].bones = xlAlloc(bind->header.bones * xlModS(BoneFrame));
			xlFileRead(bind->body.frames[i].bones, bind->header.bones, xlModS(BoneFrame), stream);
			xlFileRead(&bind->body.frames[i].matrix, 16, sizeof(XLreal), stream);
			xlFileRead(&bind->body.frames[i].time, 1, sizeof(XLreal), stream);
		}

		xlLog(L"%s: actions: %i\n", filepath, bind->header.actions);
		bind->body.actions = xlAlloc(bind->header.actions * xlModS(Action));
		xlFileRead(bind->body.actions, bind->header.actions, xlModS(Action), stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlPartsLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");

	if(stream)
	{
		XLparticles *bind = xlGetParticles();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileRead(&bind->header, 1, xlPartsS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: particles\n", filepath);
		xlFileRead(&bind->body, xlPartsS(Body), 1, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlCamLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");
	if(stream)
	{
		XLcamera *bind = xlGetCamera();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileRead(&bind->header, 1, xlCamS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: properties: %i\n", filepath, bind->header.properties);
		bind->body.properties = xlAlloc(bind->header.properties * xlCamS(Property));
		xlFileRead(bind->body.properties, xlCamS(Property), bind->header.properties, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlOpLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");

	if(stream)
	{
		XLoperator *bind = xlGetOperator();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileRead(&bind->header, 1, xlOpS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: camera\n", filepath);
		bind->body.camera = xlAlloc(xlOpS(Camera));
		xlFileRead(bind->body.camera, 1, xlOpS(Camera), stream);

		xlLog(L"%s: frames: %i\n", filepath, bind->header.frames);
		bind->body.frames = xlAlloc(bind->header.frames * xlOpS(Frame));
		xlFileRead(bind->body.frames, xlOpS(Frame), bind->header.frames, stream);

		xlLog(L"%s: actions: %i\n", filepath, bind->header.actions);
		bind->body.actions = xlAlloc(bind->header.actions * xlOpS(Action));
		xlFileRead(bind->body.actions, xlOpS(Action), bind->header.actions, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlViewLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");
	if(stream)
	{
		XLviewport *bind = xlGetViewport();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileRead(&bind->header, 1, xlViewS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: properties: %i\n", filepath, bind->header.properties);
		bind->body.properties = xlAlloc(bind->header.properties * xlViewS(Property));
		xlFileRead(bind->body.properties, xlViewS(Property), bind->header.properties, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlWinLoad(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");
	if(stream)
	{
		XLwindow *bind = xlGetWindow();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileRead(&bind->header, 1, xlWinS(Header), stream);

		xlPathCopy(metaheader->path, filepath);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: properties: %i\n", filepath, bind->header.properties);
		bind->body.properties = xlAlloc(bind->header.properties * xlWinS(Property));
		xlFileRead(bind->body.properties, xlWinS(Property), bind->header.properties, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}
