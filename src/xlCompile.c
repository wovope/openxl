#include "XL/xlCompile.h"
#include "XL/xl.h"

void
xlMetHeadCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLmetaheader *metaheader = xlGetMetaHeader();
		XLstring type;

		xlPathCopy(metaheader->path, filepath);
		xlLog(L"%s: path: %s\n", filepath, metaheader->path);

		xlFileGetAttributeString(L"type", type, stream);
		xlLog(L"%s: type: %ls\n", filepath, type);
		metaheader->magic = xlGetMagic(type);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMetDatCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLmetadata *metadata = xlGetMetaData();

		xlFileGetAttributeString(L"name", metadata->name, stream);
		xlLog(L"%s: name: %ls\n", filepath, metadata->name);

		xlFileGetAttributeString(L"version", metadata->version, stream);
		xlLog(L"%s: version: %ls\n", filepath, metadata->version);

		xlFileGetAttributeString(L"author", metadata->author, stream);
		xlLog(L"%s: author: %ls\n", filepath, metadata->author);

		xlFileGetAttributeString(L"date", metadata->date, stream);
		xlLog(L"%s: date: %ls\n", filepath, metadata->date);

		xlFileGetAttributeString(L"copyright", metadata->copyright, stream);
		xlLog(L"%s: copyright: %ls\n", filepath, metadata->copyright);

		xlFileGetAttributeString(L"license", metadata->license, stream);
		xlLog(L"%s: license: %ls\n", filepath, metadata->license);

		xlFileGetAttributeString(L"url", metadata->url, stream);
		xlLog(L"%s: url: %ls\n", filepath, metadata->url);

		xlFileGetAttributeString(L"email", metadata->email, stream);
		xlLog(L"%s: email: %ls\n", filepath, metadata->email);

		xlFileGetAttributeString(L"tool", metadata->tool, stream);
		xlLog(L"%s: tool: %ls\n", filepath, metadata->tool);

		xlFileGetAttributeString(L"comment", metadata->comment, stream);
		xlLog(L"%s: comment: %ls\n", filepath, metadata->comment);

		xlFileGetAttributeString(L"xl", metadata->xl, stream);
		xlLog(L"%s: xl: %ls\n", filepath, metadata->xl);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMetCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLmetaheader *metaheader = xlGetMetaHeader();
		XLmetadata *metadata = xlGetMetaData();
		XLstring type;

		xlPathCopy(metaheader->path, filepath);
		xlLog(L"%s: path: %s\n", filepath, metaheader->path);
		xlFileGetAttributeString(L"type", type, stream);
		xlLog(L"%s: type: %ls\n", filepath, type);
		metaheader->magic = xlGetMagic(type);

		xlFileGetAttributeString(L"name", metadata->name, stream);
		xlLog(L"%s: name: %ls\n", filepath, metadata->name);
		xlFileGetAttributeString(L"version", metadata->version, stream);
		xlLog(L"%s: version: %ls\n", filepath, metadata->version);
		xlFileGetAttributeString(L"author", metadata->author, stream);
		xlLog(L"%s: author: %ls\n", filepath, metadata->author);
		xlFileGetAttributeString(L"date", metadata->date, stream);
		xlLog(L"%s: date: %ls\n", filepath, metadata->date);
		xlFileGetAttributeString(L"copyright", metadata->copyright, stream);
		xlLog(L"%s: copyright: %ls\n", filepath, metadata->copyright);
		xlFileGetAttributeString(L"license", metadata->license, stream);
		xlLog(L"%s: license: %ls\n", filepath, metadata->license);
		xlFileGetAttributeString(L"url", metadata->url, stream);
		xlLog(L"%s: url: %ls\n", filepath, metadata->url);
		xlFileGetAttributeString(L"email", metadata->email, stream);
		xlLog(L"%s: email: %ls\n", filepath, metadata->email);
		xlFileGetAttributeString(L"tool", metadata->tool, stream);
		xlLog(L"%s: tool: %ls\n", filepath, metadata->tool);
		xlFileGetAttributeString(L"comment", metadata->comment, stream);
		xlLog(L"%s: comment: %ls\n", filepath, metadata->comment);
		xlFileGetAttributeString(L"xl", metadata->xl, stream);
		xlLog(L"%s: xl: %ls\n", filepath, metadata->xl);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlImgCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLimage *bind = xlGetImage();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLcolor *pixels;
		XLuint i;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlFileGetAttributeu(L"width", &bind->header.width, stream);
		xlLog(L"%s: width: %i\n", filepath, bind->header.width);
		xlFileGetAttributeu(L"height", &bind->header.height, stream);
		xlLog(L"%s: height: %i\n", filepath, bind->header.height);
		bind->header.bpp = 4;
		xlLog(L"%s: bpp: %i\n", filepath, bind->header.bpp);

		bind->body.pixels = xlAlloc(bind->header.width * bind->header.height * sizeof(XLcolor));
		pixels = bind->body.pixels;
		for(i = 0; i < bind->header.width * bind->header.height; i++)
			xlFileGetAttributeColor(L"pixel", &pixels[i], stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlFntCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLfont *bind = xlGetFont();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLFontProperty *properties;
		XLuint i;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlFileGetAttributeu(L"properties", &bind->header.properties, stream);
		xlLog(L"%s: properties: %i\n", filepath, bind->header.properties);
		bind->body.properties = xlAlloc(bind->header.properties * xlFntS(Property));
		properties = bind->body.properties;
		for(i = 0; i < bind->header.properties; i++)
		{
			xlFileGetAttributeString(L"name", properties[i].name, stream);
			xlFileGetAttributeu(L"width", &properties[i].width, stream);
			xlFileGetAttributeu(L"height", &properties[i].height, stream);
		}

		xlFileGetAttributePath(L"path", bind->body.path, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMatCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLmaterial *bind = xlGetMaterial();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLMaterialProperty *properties;
		XLuint i;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlFileGetAttributeu(L"properties", &bind->header.properties, stream);
		xlLog(L"%s: properties: %i\n", filepath, bind->header.properties);
		bind->body.properties = xlAlloc(bind->header.properties * xlMatS(Property));
		properties = bind->body.properties;
		for(i = 0; i < bind->header.properties; i++)
		{
			xlFileGetAttributeString(L"name", properties[i].name, stream);
			xlFileGetAttributePath(L"image", properties[i].image, stream);
			xlFileGetAttributef(L"alpha", &properties[i].alpha, stream);
			xlFileGetAttributeColorRGBv(L"ambient", &properties[i].ambient, stream);
			xlFileGetAttributeColorRGBv(L"diffuse", &properties[i].diffuse, stream);
			xlFileGetAttributeColorRGBv(L"specular", &properties[i].specular, stream);
			xlFileGetAttributeColorRGBv(L"emission", &properties[i].emission, stream);
			xlFileGetAttributef(L"shininess", &properties[i].shininess, stream);
			xlFileGetAttributeMatrix(L"matrix", &properties[i].matrix, stream);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlSurfCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLsurface *bind = xlGetSurface();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLSurfaceMaterial *material;
		XLSurfaceFrame *frames;
		XLSurfaceAction *actions;
		XLuint i;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: material\n", filepath);
		bind->body.material = xlAlloc(1 * xlSurfS(Material));
		material = bind->body.material;
		xlFileGetAttributePath(L"material", material->path, stream);

		xlFileGetAttributeu(L"frames", &bind->header.frames, stream);
		xlLog(L"%s: frames: %i\n", filepath, bind->header.frames);
		bind->body.frames = xlAlloc(bind->header.frames * xlSurfS(Frame));
		frames = bind->body.frames;
		for(i = 0; i < bind->header.frames; i++)
		{
			xlFileGetAttributeMatrix(L"matrix", &frames[i].matrix, stream);
			xlFileGetAttributef(L"time", &frames[i].time, stream);
		}

		xlFileGetAttributeu(L"actions", &bind->header.actions, stream);
		xlLog(L"%s: actions: %i\n", filepath, bind->header.actions);
		bind->body.actions = xlAlloc(bind->header.actions * xlSurfS(Action));
		actions = bind->body.actions;
		for(i = 0; i < bind->header.actions; i++)
		{
			xlFileGetAttributeString(L"name", actions[i].name, stream);
			xlFileGetAttributeRange(L"frames", &actions[i].frames, stream);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlObjCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLobject *bind = xlGetObject();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLObjectVertex *vertices;
		XLObjectMaterial *materials;
		XLObjectFace *faces;
		XLObjectTag *tags;
		XLObjectBound *bound;
		XLuint i;
		XLstring type;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlFileGetAttributeu(L"vertices", &bind->header.vertices, stream);
		xlLog(L"%s: vertices: %i\n", filepath, bind->header.vertices);
		bind->body.vertices = xlAlloc(bind->header.vertices * xlObjS(Vertex));
		vertices = bind->body.vertices;
		for(i = 0; i < bind->header.vertices; i++)
		{
			xlFileGetAttributePoint(L"coord", &vertices[i].coord, stream);
			xlFileGetAttributeVector(L"normal", &vertices[i].normal, stream);
		}

		xlFileGetAttributeu(L"materials", &bind->header.materials, stream);
		xlLog(L"%s: materials: %i\n", filepath, bind->header.materials);
		bind->body.materials = xlAlloc(bind->header.materials * xlObjS(Material));
		materials = bind->body.materials;
		for(i = 0; i < bind->header.materials; i++)
		{
			xlFileGetAttributeString(L"name", materials[i].name, stream);
			xlFileGetAttributeString(L"type", type, stream);
			materials[i].surface = xlStringEqual(type, L"surface");
			xlFileGetAttributePath(L"material", materials[i].path, stream);
			xlFileGetAttributeRange(L"faces", &materials[i].faces, stream);
		}

		xlFileGetAttributeu(L"faces", &bind->header.faces, stream);
		xlLog(L"%s: faces: %i\n", filepath, bind->header.faces);
		bind->body.faces = xlAlloc(bind->header.faces * xlObjS(Face));
		faces = bind->body.faces;
		for(i = 0; i < bind->header.faces; i++)
		{
			xlFileGetAttribute3uv(L"vertices", faces[i].vertices, stream);
			xlFileGetAttributeVector(L"normal", &faces[i].normal, stream);
			xlFileGetAttribute3Pair(L"texcoords", faces[i].texcoords, stream);
		}

		xlFileGetAttributeu(L"tags", &bind->header.tags, stream);
		xlLog(L"%s: tags: %i\n", filepath, bind->header.tags);
		bind->body.tags = xlAlloc(bind->header.tags * xlObjS(Tag));
		tags = bind->body.tags;
		for(i = 0; i < bind->header.tags; i++)
		{
			xlFileGetAttributeString(L"name", tags[i].name, stream);
			xlFileGetAttributeMatrix(L"matrix", &tags[i].matrix, stream);
		}

		xlFileGetName(L"bound", stream);
		xlLog(L"%s: bound\n", filepath);
		bind->body.bound = xlAlloc(1 * xlObjS(Bound));
		bound = bind->body.bound;
		xlFileGetAttribute4fv(L"sphere", bound->sphere, stream);
		xlFileGetAttribute3fv(L"dimensions", bound->dimensions, stream);

		xlMatrixAssignIdentity(&bind->runtime.matrix);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlModCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLmodel *bind = xlGetModel();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLModelObject *object;
		XLModelBone *bones;
		XLModelParent *parents;
		XLModelVertex *vertices;
		XLModelTag *tags;
		XLModelWeight *weights;
		XLModelFrame *frames;
		XLModelAction *actions;
		XLuint i, j;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: object\n", filepath);
		bind->body.object = xlAlloc(1 * xlModS(Object));
		object = bind->body.object;
		xlFileGetAttributePath(L"object", object->path, stream);

		xlFileGetAttributeu(L"bones", &bind->header.bones, stream);
		xlLog(L"%s: bones: %i\n", filepath, bind->header.bones);
		bind->body.bones = xlAlloc(bind->header.bones * xlModS(Bone));
		bones = bind->body.bones;
		for(i = 0; i < bind->header.bones; i++)
		{
			xlFileGetAttributeString(L"name", bones[i].name, stream);
			xlFileGetAttributeRange(L"parents", &bones[i].parents, stream);
		}

		xlFileGetAttributeu(L"parents", &bind->header.parents, stream);
		xlLog(L"%s: parents: %i\n", filepath, bind->header.parents);
		bind->body.parents = xlAlloc(bind->header.parents * xlModS(Parent));
		parents = bind->body.parents;
		for(i = 0; i < bind->header.parents; i++)
		{
			xlFileGetAttributeu(L"bone", &parents[i].bone, stream);
		}

		xlFileGetAttributeu(L"vertices", &bind->header.vertices, stream);
		xlLog(L"%s: vertices: %i\n", filepath, bind->header.vertices);
		bind->body.vertices = xlAlloc(bind->header.vertices * xlModS(Vertex));
		vertices = bind->body.vertices;
		for(i = 0; i < bind->header.vertices; i++)
		{
			xlFileGetAttributeRange(L"weights", &vertices[i].weights, stream);
		}

		xlFileGetAttributeu(L"tags", &bind->header.tags, stream);
		xlLog(L"%s: tags: %i\n", filepath, bind->header.tags);
		bind->body.tags = xlAlloc(bind->header.tags * xlModS(Tag));
		tags = bind->body.tags;
		for(i = 0; i < bind->header.tags; i++)
		{
			xlFileGetAttributeRange(L"weights", &tags[i].weights, stream);
		}

		xlFileGetAttributeu(L"weights", &bind->header.weights, stream);
		xlLog(L"%s: weights: %i\n", filepath, bind->header.weights);
		bind->body.weights = xlAlloc(bind->header.weights * xlModS(Weight));
		weights = bind->body.weights;
		for(i = 0; i < bind->header.weights; i++)
		{
			xlFileGetAttributeuf(L"weight", &weights[i].bone, &weights[i].value, stream);
		}

		xlFileGetAttributeu(L"frames", &bind->header.frames, stream);
		xlLog(L"%s: frames: %i\n", filepath, bind->header.frames);
		bind->body.frames = xlAlloc(bind->header.frames * xlModS(Frame));
		frames = bind->body.frames;
		for(i = 0; i < bind->header.frames; i++)
		{
			bind->body.frames[i].bones = xlAlloc(bind->header.bones * xlModS(BoneFrame));
			for(j = 0; j < bind->header.bones; j++)
			{
				xlFileGetAttributeMatrix(L"matrix", &frames[i].bones[j].matrix, stream);
			}
			xlFileGetAttributeMatrix(L"matrix", &frames[i].matrix, stream);
			xlFileGetAttributef(L"time", &frames[i].time, stream);
		}

		xlFileGetAttributeu(L"actions", &bind->header.actions, stream);
		xlLog(L"%s: actions: %i\n", filepath, bind->header.actions);
		bind->body.actions = xlAlloc(bind->header.actions * xlModS(Action));
		actions = bind->body.actions;
		for(i = 0; i < bind->header.actions; i++)
		{
			xlFileGetAttributeString(L"name", actions[i].name, stream);
			xlFileGetAttributeRange(L"frames", &actions[i].frames, stream);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlPartsCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLparticles *bind = xlGetParticles();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlFileGetAttributeu(L"count", &bind->body.count, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlCamCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLcamera *bind = xlGetCamera();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLCameraProperty *properties;
		XLuint i;
		XLstring buffer;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlFileGetAttributeu(L"properties", &bind->header.properties, stream);
		xlLog(L"%s: properties: %i\n", filepath, bind->header.properties);
		bind->body.properties = xlAlloc(bind->header.properties * xlCamS(Property));
		properties = bind->body.properties;
		for(i = 0; i < bind->header.properties; i++)
		{
			xlFileGetAttributeString(L"name", properties[i].name, stream);
			xlFileGetAttributeString(L"type", buffer, stream);
			if(xlStringEqual(buffer, L"orthogonal"))
			{
				properties[i].type = XL_CAMERA_PROPERTY_ORTHOGONAL;
				xlFileGetAttributef(L"left", &properties[i].details.orthogonal.left, stream);
				xlFileGetAttributef(L"right", &properties[i].details.orthogonal.right, stream);
				xlFileGetAttributef(L"bottom", &properties[i].details.orthogonal.bottom, stream);
				xlFileGetAttributef(L"top", &properties[i].details.orthogonal.top, stream);
			}
			else if(xlStringEqual(buffer, L"perspective"))
			{
				properties[i].type = XL_CAMERA_PROPERTY_PERSPECTIVE;
				xlFileGetAttributef(L"fovy", &properties[i].details.perspective.fovy, stream);
				xlFileGetAttributef(L"aspect", &properties[i].details.perspective.aspect, stream);
				xlFileGetAttributef(L"znear", &properties[i].details.perspective.znear, stream);
				xlFileGetAttributef(L"zfar", &properties[i].details.perspective.zfar, stream);
			}
			xlFileGetAttributeMatrix(L"matrix", &properties[i].matrix, stream);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlOpCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLoperator *bind = xlGetOperator();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLOperatorCamera *camera;
		XLOperatorFrame *frames;
		XLOperatorAction *actions;
		XLuint i;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlLog(L"%s: camera\n", filepath);
		bind->body.camera = xlAlloc(1 * xlOpS(Camera));
		camera = bind->body.camera;
		xlFileGetAttributePath(L"camera", camera->path, stream);

		xlFileGetAttributeu(L"frames", &bind->header.frames, stream);
		xlLog(L"%s: frames: %i\n", filepath, bind->header.frames);
		bind->body.frames = xlAlloc(bind->header.frames * xlOpS(Frame));
		frames = bind->body.frames;
		for(i = 0; i < bind->header.frames; i++)
		{
			xlFileGetAttributeMatrix(L"matrix", &frames[i].matrix, stream);
			xlFileGetAttributef(L"time", &frames[i].time, stream);
		}

		xlFileGetAttributeu(L"actions", &bind->header.actions, stream);
		xlLog(L"%s: actions: %i\n", filepath, bind->header.actions);
		bind->body.actions = xlAlloc(bind->header.actions * xlOpS(Action));
		actions = bind->body.actions;
		for(i = 0; i < bind->header.actions; i++)
		{
			xlFileGetAttributeString(L"name", actions[i].name, stream);
			xlFileGetAttributeRange(L"frames", &actions[i].frames, stream);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlVptCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLviewport *bind = xlGetViewport();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLViewportProperty *properties;
		XLuint i;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlFileGetAttributeu(L"properties", &bind->header.properties, stream);
		xlLog(L"%s: properties: %i\n", filepath, bind->header.properties);
		bind->body.properties = xlAlloc(bind->header.properties * xlViewS(Property));
		properties = bind->body.properties;
		for(i = 0; i < bind->header.properties; i++)
		{
			xlFileGetAttributeString(L"name", properties[i].name, stream);
			xlFileGetAttributePair(L"position", &properties[i].position, stream);
			xlFileGetAttributePair(L"size", &properties[i].size, stream);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlWinCompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLwindow *bind = xlGetWindow();
		XLmetaheader *metaheader = &bind->header.metaheader;
		XLmetadata *metadata = &bind->header.metadata;
		XLWindowProperty *properties;
		XLuint i;

		xlFileGetMetaHeader(metaheader, stream);
		xlPathCopy(metaheader->path, filepath);
		xlFileGetMetaData(metadata, stream);
		xlLogMeta(metaheader, metadata);

		xlFileGetAttributeu(L"properties", &bind->header.properties, stream);
		xlLog(L"%s: properties: %i\n", filepath, bind->header.properties);
		bind->body.properties = xlAlloc(bind->header.properties * xlWinS(Property));
		properties = bind->body.properties;
		for(i = 0; i < bind->header.properties; i++)
		{
			xlFileGetAttributeString(L"name", properties[i].name, stream);
			xlFileGetAttributeString(L"title", properties[i].title, stream);
			xlFileGetAttributePair(L"position", &properties[i].position, stream);
			xlFileGetAttributePair(L"size", &properties[i].size, stream);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}
