#include "XL/xlDecompile.h"
#include "XL/xl.h"

void
xlMetHeadDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLmetaheader *metaheader = xlGetMetaHeader();

		xlFilePrintAttributeString(stream, L"type", xlGetString(metaheader->magic));

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMetDatDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLmetadata *metadata = xlGetMetaData();

		xlFilePrintAttributeString(stream, L"name", metadata->name);

		xlFilePrintAttributeString(stream, L"version", metadata->version);

		xlFilePrintAttributeString(stream, L"author", metadata->author);

		xlFilePrintAttributeString(stream, L"date", metadata->date);

		xlFilePrintAttributeString(stream, L"copyright", metadata->copyright);

		xlFilePrintAttributeString(stream, L"license", metadata->license);

		xlFilePrintAttributeString(stream, L"url", metadata->url);

		xlFilePrintAttributeString(stream, L"email", metadata->email);

		xlFilePrintAttributeString(stream, L"tool", metadata->tool);

		xlFilePrintAttributeString(stream, L"comment", metadata->comment);

		xlFilePrintAttributeString(stream, L"xl", metadata->xl);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMetDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLmetaheader *metaheader = xlGetMetaHeader();
		XLmetadata *metadata = xlGetMetaData();

		xlFilePrintAttributeString(stream, L"type", xlGetString(metaheader->magic));

		xlFilePrintAttributeString(stream, L"name", metadata->name);
		xlFilePrintAttributeString(stream, L"version", metadata->version);
		xlFilePrintAttributeString(stream, L"author", metadata->author);
		xlFilePrintAttributeString(stream, L"date", metadata->date);
		xlFilePrintAttributeString(stream, L"copyright", metadata->copyright);
		xlFilePrintAttributeString(stream, L"license", metadata->license);
		xlFilePrintAttributeString(stream, L"url", metadata->url);
		xlFilePrintAttributeString(stream, L"email", metadata->email);
		xlFilePrintAttributeString(stream, L"tool", metadata->tool);
		xlFilePrintAttributeString(stream, L"comment", metadata->comment);
		xlFilePrintAttributeString(stream, L"xl", metadata->xl);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlImgDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLimage *bind = xlGetImage();
		XLcolor *pixels = bind->body.pixels;
		XLuint i;

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		xlFilePrintAttributeu(stream, L"width", bind->header.width);
		xlFilePrintAttributeu(stream, L"height", bind->header.height);

		for(i = 0; i < bind->header.width * bind->header.height; i++)
			xlFilePrintAttributeColor(stream, L"pixel", &pixels[i]);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlFntDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLfont *bind = xlGetFont();
		XLFontProperty *properties = bind->body.properties;
		XLuint i;

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		xlFilePrintAttributeu(stream, L"properties", bind->header.properties);
		for(i = 0; i < bind->header.properties; i++)
		{
			xlFilePrintAttributeString(stream, L"name", properties[i].name);
			xlFilePrintAttributeu(stream, L"width", properties[i].width);
			xlFilePrintAttributeu(stream, L"height", properties[i].height);
		}
		xlFilePrintAttributePath(stream, L"path", bind->body.path);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMatDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLmaterial *bind = xlGetMaterial();
		XLMaterialProperty *properties = bind->body.properties;
		XLuint i;

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		xlFilePrintAttributeu(stream, L"properties", bind->header.properties);
		for(i = 0; i < bind->header.properties; i++)
		{
			xlFilePrintAttributeString(stream, L"name", properties[i].name);
			xlFilePrintAttributePath(stream, L"image", properties[i].image);
			xlFilePrintAttributef(stream, L"alpha", properties[i].alpha);
			xlFilePrintAttributeColorRGBv(stream, L"ambient", &properties[i].ambient);
			xlFilePrintAttributeColorRGBv(stream, L"diffuse", &properties[i].diffuse);
			xlFilePrintAttributeColorRGBv(stream, L"specular", &properties[i].specular);
			xlFilePrintAttributeColorRGBv(stream, L"emission", &properties[i].emission);
			xlFilePrintAttributef(stream, L"shininess", properties[i].shininess);
			xlFilePrintAttributeMatrix(stream, L"matrix", &properties[i].matrix);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlSurfDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLsurface *bind = xlGetSurface();
		XLSurfaceMaterial *material;
		XLSurfaceFrame *frames;
		XLSurfaceAction *actions;
		XLuint i;

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		material = bind->body.material;
		xlFilePrintAttributePath(stream, L"material", material->path);

		frames = bind->body.frames;
		xlFilePrintAttributeu(stream, L"frames", bind->header.frames);
		for(i = 0; i < bind->header.frames; i++)
		{
			xlFilePrintAttributeMatrix(stream, L"matrix", &frames[i].matrix);
			xlFilePrintAttributef(stream, L"time", frames[i].time);
		}

		actions = bind->body.actions;
		xlFilePrintAttributeu(stream, L"actions", bind->header.actions);
		for(i = 0; i < bind->header.actions; i++)
		{
			xlFilePrintAttributeString(stream, L"name", actions[i].name);
			xlFilePrintAttributeRange(stream, L"frames", &actions[i].frames);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlObjDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLobject *bind = xlGetObject();
		XLObjectVertex *vertices;
		XLObjectMaterial *materials;
		XLObjectFace *faces;
		XLObjectTag *tags;
		XLObjectBound *bound;
		XLuint i;

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		vertices = bind->body.vertices;
		xlFilePrintAttributeu(stream, L"vertices", bind->header.vertices);
		for(i = 0; i < bind->header.vertices; i++)
		{
			xlFilePrintAttributePoint(stream, L"coord", &vertices[i].coord);
			xlFilePrintAttributeVector(stream, L"normal", &vertices[i].normal);
		}

		materials = bind->body.materials;
		xlFilePrintAttributeu(stream, L"materials", bind->header.materials);
		for(i = 0; i < bind->header.materials; i++)
		{
			xlFilePrintAttributeString(stream, L"name", materials[i].name);
			xlFilePrintAttributeString(stream, L"type", materials[i].surface ? L"surface" : L"material");
			xlFilePrintAttributePath(stream, L"material", materials[i].path);
			xlFilePrintAttributeRange(stream, L"faces", &materials[i].faces);
		}

		faces = bind->body.faces;
		xlFilePrintAttributeu(stream, L"faces", bind->header.faces);
		for(i = 0; i < bind->header.faces; i++)
		{
			xlFilePrintAttribute3uv(stream, L"vertices", faces[i].vertices);
			xlFilePrintAttributeVector(stream, L"normal", &faces[i].normal);
			xlFilePrintAttribute3Pair(stream, L"texcoords", faces[i].texcoords);
		}

		tags = bind->body.tags;
		xlFilePrintAttributeu(stream, L"tags", bind->header.tags);
		for(i = 0; i < bind->header.tags; i++)
		{
			xlFilePrintAttributeString(stream, L"name", tags[i].name);
			xlFilePrintAttributeMatrix(stream, L"matrix", &tags[i].matrix);
		}

		bound = bind->body.bound;
		xlFilePrintName(stream, L"bound");
		xlFilePrintAttribute4fv(stream, L"sphere", bound->sphere);
		xlFilePrintAttribute3fv(stream, L"dimensions", bound->dimensions);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlModDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLmodel *bind = xlGetModel();
		XLModelObject *object;
		XLModelBone *bones;
		XLModelParent *parents;
		XLModelVertex *vertices;
		XLModelTag *tags;
		XLModelWeight *weights;
		XLModelFrame *frames;
		XLModelAction *actions;
		XLuint i, j;

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		object = bind->body.object;
		xlFilePrintAttributePath(stream, L"object", object->path);

		bones = bind->body.bones;
		xlFilePrintAttributeu(stream, L"bones", bind->header.bones);
		for(i = 0; i < bind->header.bones; i++)
		{
			xlFilePrintAttributeString(stream, L"name", bones[i].name);
			xlFilePrintAttributeRange(stream, L"parents", &bones[i].parents);
		}

		parents = bind->body.parents;
		xlFilePrintAttributeu(stream, L"parents", bind->header.parents);
		for(i = 0; i < bind->header.parents; i++)
		{
			xlFilePrintAttributeu(stream, L"bone", parents[i].bone);
		}

		vertices = bind->body.vertices;
		xlFilePrintAttributeu(stream, L"vertices", bind->header.vertices);
		for(i = 0; i < bind->header.vertices; i++)
		{
			xlFilePrintAttributeRange(stream, L"weights", &vertices[i].weights);
		}

		tags = bind->body.tags;
		xlFilePrintAttributeu(stream, L"tags", bind->header.tags);
		for(i = 0; i < bind->header.tags; i++)
		{
			xlFilePrintAttributeRange(stream, L"weights", &tags[i].weights);
		}

		weights = bind->body.weights;
		xlFilePrintAttributeu(stream, L"weights", bind->header.weights);
		for(i = 0; i < bind->header.weights; i++)
		{
			xlFilePrintAttributeuf(stream, L"weights", weights[i].bone, weights[i].value);
		}

		frames = bind->body.frames;
		xlFilePrintAttributeu(stream, L"frames", bind->header.frames);
		for(i = 0; i < bind->header.frames; i++)
		{
			for(j = 0; j < bind->header.bones; j++)
			{
				xlFilePrintAttributeMatrix(stream, L"matrix", &frames[i].bones[j].matrix);
			}
			xlFilePrintAttributeMatrix(stream, L"matrix", &frames[i].matrix);
			xlFilePrintAttributef(stream, L"time", frames[i].time);
		}

		actions = bind->body.actions;
		xlFilePrintAttributeu(stream, L"actions", bind->header.actions);
		for(i = 0; i < bind->header.actions; i++)
		{
			xlFilePrintAttributeString(stream, L"name", actions[i].name);
			xlFilePrintAttributeRange(stream, L"frames", &actions[i].frames);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlPartsDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLparticles *bind = xlGetParticles();

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		xlFilePrintAttributeu(stream, L"count", bind->body.count);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlCamDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLcamera *bind = xlGetCamera();
		XLCameraProperty *properties;
		XLuint i;

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		properties = bind->body.properties;
		xlFilePrintAttributeu(stream, L"properties", bind->header.properties);
		for(i = 0; i < bind->header.properties; i++)
		{
			xlFilePrintAttributeString(stream, L"name", properties[i].name);
			switch(properties[i].type)
			{
				case XL_CAMERA_PROPERTY_ORTHOGONAL:
					xlFilePrintAttributeString(stream, L"type", L"orthogonal");
					xlFilePrintAttributef(stream, L"left", properties[i].details.orthogonal.left);
					xlFilePrintAttributef(stream, L"right", properties[i].details.orthogonal.right);
					xlFilePrintAttributef(stream, L"bottom", properties[i].details.orthogonal.bottom);
					xlFilePrintAttributef(stream, L"top", properties[i].details.orthogonal.top);
					break;
				case XL_CAMERA_PROPERTY_PERSPECTIVE:
					xlFilePrintAttributeString(stream, L"type", L"perspective");
					xlFilePrintAttributef(stream, L"fovy", properties[i].details.perspective.fovy);
					xlFilePrintAttributef(stream, L"aspect", properties[i].details.perspective.aspect);
					xlFilePrintAttributef(stream, L"znear", properties[i].details.perspective.znear);
					xlFilePrintAttributef(stream, L"zfar", properties[i].details.perspective.zfar);
					break;
				default:
					break;
			}
			xlFilePrintAttributeMatrix(stream, L"matrix", &properties[i].matrix);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlOpDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLoperator *bind = xlGetOperator();
		XLOperatorCamera *camera;
		XLOperatorFrame *frames;
		XLOperatorAction *actions;
		XLuint i;

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		camera = bind->body.camera;
		xlFilePrintAttributePath(stream, L"camera", camera->path);

		frames = bind->body.frames;
		xlFilePrintAttributeu(stream, L"frames", bind->header.frames);
		for(i = 0; i < bind->header.frames; i++)
		{
			xlFilePrintAttributeMatrix(stream, L"matrix", &frames[i].matrix);
			xlFilePrintAttributef(stream, L"time", frames[i].time);
		}

		actions = bind->body.actions;
		xlFilePrintAttributeu(stream, L"actions", bind->header.actions);
		for(i = 0; i < bind->header.actions; i++)
		{
			xlFilePrintAttributeString(stream, L"name", actions[i].name);
			xlFilePrintAttributeRange(stream, L"frames", &actions[i].frames);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlViewDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLviewport *bind = xlGetViewport();
		XLViewportProperty *properties;
		XLuint i;

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		properties = bind->body.properties;
		xlFilePrintAttributeu(stream, L"properties", bind->header.properties);
		for(i = 0; i < bind->header.properties; i++)
		{
			xlFilePrintAttributeString(stream, L"name", properties[i].name);
			xlFilePrintAttributePair(stream, L"position", &properties[i].position);
			xlFilePrintAttributePair(stream, L"size", &properties[i].size);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlWinDecompile(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLwindow *bind = xlGetWindow();
		XLWindowProperty *properties;
		XLuint i;

		xlFilePrintMetaHeader(stream, &bind->header.metaheader);
		xlFilePrintMetaData(stream, &bind->header.metadata);

		properties = bind->body.properties;
		xlFilePrintAttributeu(stream, L"properties", bind->header.properties);
		for(i = 0; i < bind->header.properties; i++)
		{
			xlFilePrintAttributeString(stream, L"name", properties[i].name);
			xlFilePrintAttributeString(stream, L"title", properties[i].title);
			xlFilePrintAttributePair(stream, L"position", &properties[i].position);
			xlFilePrintAttributePair(stream, L"size", &properties[i].size);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}
