#include "XL/xlTypes.h"
#include "XL/xl.h"

XLerror *
xlGetError(void)
{
	return &xlError;
}

XLenum
xlGetLogLevel(void)
{
	return xlLogLevel;
}

void
xlGetBooleanv(XLenum pname, XLboolean *params)
{
	switch(pname)
	{
		case XL_OBJECT_MATERIAL_SURFACE:
		{
			XLobject *bind = xlGetObject();
			*params = bind->body.materials[bind->runtime.material].surface;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

XLboolean
xlGetBoolean(XLenum pname)
{
	XLboolean params;
	xlGetBooleanv(pname, &params);
	return params;
}

void
xlGetIntegerv(XLenum pname, XLint *params)
{
	switch(pname)
	{
		case XL_ERROR_LINE:
		{
			XLerror *error = xlGetError();
			*params = error->line;
			break;
		}
		case XL_ERROR_VALUE:
		{
			XLerror *error = xlGetError();
			*params = error->value;
			break;
		}
		case XL_METAHEADER:
		{
			XLstore *metaheaders = xlGetStore(XL_METAHEADER);
			*params = metaheaders->bind;
			break;
		}
		case XL_METAHEADER_MAGIC:
		{
			XLmetaheader *metaheader = xlGetMetaHeader();
			*params = metaheader->magic;
			break;
		}
		case XL_METADATA:
		{
			XLstore *metadatas = xlGetStore(XL_METADATA);
			*params = metadatas->bind;
			break;
		}
		case XL_IMAGE:
		{
			XLstore *images = xlGetStore(XL_IMAGE);
			*params = images->bind;
			break;
		}
		case XL_IMAGE_WIDTH:
		{
			XLimage *bind = xlGetImage();
			*params = bind->header.width;
			break;
		}
		case XL_IMAGE_HEIGHT:
		{
			XLimage *bind = xlGetImage();
			*params = bind->header.height;
			break;
		}
		case XL_IMAGE_SIZE:
		{
			XLimage *bind = xlGetImage();
			params[0] = bind->header.width;
			params[1] = bind->header.height;
			break;
		}
		case XL_IMAGE_BYTES_PER_PIXEL:
		{
			XLimage *bind = xlGetImage();
			*params = bind->header.bpp;
			break;
		}
		case XL_IMAGE_TEXTURE:
		{
			XLimage *bind = xlGetImage();
			*params = bind->runtime.texture;
			break;
		}
		case XL_SOUND:
		{
			XLstore *sounds = xlGetStore(XL_SOUND);
			*params = sounds->bind;
			break;
		}
		case XL_SOUND_CHANNELS:
		{
			XLsound *bind = xlGetSound();
			*params = bind->header.channels;
			break;
		}
		case XL_SOUND_FREQUENCY:
		{
			XLsound *bind = xlGetSound();
			*params = bind->header.frequency;
			break;
		}
		case XL_SOUND_LENGTH:
		{
			XLsound *bind = xlGetSound();
			*params = bind->header.length;
			break;
		}
		case XL_SOUND_BYTES_PER_SAMPLE:
		{
			XLsound *bind = xlGetSound();
			*params = bind->header.bps;
			break;
		}
		case XL_SOUND_BUFFER:
		{
			XLsound *bind = xlGetSound();
			*params = bind->runtime.buffer;
			break;
		}
		case XL_SOUND_SOURCE:
		{
			XLsound *bind = xlGetSound();
			*params = bind->runtime.source;
			break;
		}
		case XL_FONT:
		{
			XLstore *fonts = xlGetStore(XL_FONT);
			*params = fonts->bind;
			break;
		}
		case XL_FONT_PROPERTIES:
		{
			XLfont *bind = xlGetFont();
			*params = bind->header.properties;
			break;
		}
		case XL_FONT_PROPERTY:
		{
			XLfont *bind = xlGetFont();
			*params = bind->runtime.property;
			break;
		}
		case XL_FONT_PROPERTY_WIDTH:
		{
			XLfont *bind = xlGetFont();
			XLFontProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->width;
			break;
		}
		case XL_FONT_PROPERTY_HEIGHT:
		{
			XLfont *bind = xlGetFont();
			XLFontProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->height;
			break;
		}
		case XL_FONT_PROPERTY_SIZE:
		{
			XLfont *bind = xlGetFont();
			XLFontProperty *property = &bind->body.properties[bind->runtime.property];
			params[0] = property->width;
			params[1] = property->height;
			break;
		}
		case XL_MATERIAL:
		{
			XLstore *materials = xlGetStore(XL_MATERIAL);
			*params = materials->bind;
			break;
		}
		case XL_MATERIAL_PROPERTIES:
		{
			XLmaterial *bind = xlGetMaterial();
			*params = bind->header.properties;
			break;
		}
		case XL_MATERIAL_PROPERTY:
		{
			XLmaterial *bind = xlGetMaterial();
			*params = bind->runtime.property;
			break;
		}
		case XL_MATERIAL_PROPERTY_IMAGE:
		{
			XLmaterial *bind = xlGetMaterial();
			*params = bind->runtime.images[bind->runtime.property];
			break;
		}
		case XL_SURFACE:
		{
			XLstore *surfaces = xlGetStore(XL_SURFACE);
			*params = surfaces->bind;
			break;
		}
		case XL_SURFACE_MATERIAL:
		{
			XLsurface *bind = xlGetSurface();
			*params = bind->runtime.material;
			break;
		}
		case XL_SURFACE_FRAMES:
		{
			XLsurface *bind = xlGetSurface();
			*params = bind->header.frames;
			break;
		}
		case XL_SURFACE_ACTIONS:
		{
			XLsurface *bind = xlGetSurface();
			*params = bind->header.actions;
			break;
		}
		case XL_SURFACE_ACTION_FRAMES:
		{
			XLsurface *bind = xlGetSurface();
			XLSurfaceAction *action = &bind->body.actions[bind->runtime.action];
			*params = action->frames.count;
			break;
		}
		case XL_SURFACE_ACTION:
		{
			XLsurface *bind = xlGetSurface();
			*params = bind->runtime.action;
			break;
		}
		case XL_SURFACE_ACTION_FRAME:
		{
			XLsurface *bind = xlGetSurface();
			*params = bind->runtime.frame;
			break;
		}
		case XL_OBJECT:
		{
			XLstore *objects = xlGetStore(XL_OBJECT);
			*params = objects->bind;
			break;
		}
		case XL_OBJECT_VERTICES:
		{
			XLobject *bind = xlGetObject();
			*params = bind->header.vertices;
			break;
		}
		case XL_OBJECT_MATERIALS:
		{
			XLobject *bind = xlGetObject();
			*params = bind->header.materials;
			break;
		}
		case XL_OBJECT_MATERIAL:
		{
			XLobject *bind = xlGetObject();
			*params = bind->runtime.material;
			break;
		}
		case XL_OBJECT_MATERIAL_MATERIAL:
		{
			XLobject *bind = xlGetObject();
			*params = bind->runtime.materials[bind->runtime.material];
			break;
		}
		case XL_OBJECT_TAG:
		{
			XLobject *bind = xlGetObject();
			*params = bind->runtime.tag;
			break;
		}
		case XL_OBJECT_FACES:
		{
			XLobject *bind = xlGetObject();
			*params = bind->header.faces;
			break;
		}
		case XL_OBJECT_TAGS:
		{
			XLobject *bind = xlGetObject();
			*params = bind->header.tags;
			break;
		}
		case XL_MODEL:
		{
			XLstore *models = xlGetStore(XL_MODEL);
			*params = models->bind;
			break;
		}
		case XL_MODEL_OBJECT:
		{
			XLmodel *bind = xlGetModel();
			*params = bind->runtime.object;
			break;
		}
		case XL_MODEL_BONES:
		{
			XLmodel *bind = xlGetModel();
			*params = bind->header.bones;
			break;
		}
		case XL_MODEL_PARENTS:
		{
			XLmodel *bind = xlGetModel();
			*params = bind->header.parents;
			break;
		}
		case XL_MODEL_VERTICES:
		{
			XLmodel *bind = xlGetModel();
			*params = bind->header.vertices;
			break;
		}
		case XL_MODEL_TAGS:
		{
			XLmodel *bind = xlGetModel();
			*params = bind->header.tags;
			break;
		}
		case XL_MODEL_WEIGHTS:
		{
			XLmodel *bind = xlGetModel();
			*params = bind->header.weights;
			break;
		}
		case XL_MODEL_FRAMES:
		{
			XLmodel *bind = xlGetModel();
			*params = bind->header.frames;
			break;
		}
		case XL_MODEL_ACTIONS:
		{
			XLmodel *bind = xlGetModel();
			*params = bind->header.actions;
			break;
		}
		case XL_MODEL_ACTION_FRAMES:
		{
			XLmodel *bind = xlGetModel();
			XLModelAction *action = &bind->body.actions[bind->runtime.action[1]];
			*params = action->frames.count;
			break;
		}
		case XL_MODEL_ACTION:
		{
			XLmodel *bind = xlGetModel();
			*params = bind->runtime.action[1];
			break;
		}
		case XL_MODEL_ACTION_FRAME:
		{
			XLmodel *bind = xlGetModel();
			*params = bind->runtime.frame[1];
			break;
		}
		case XL_PARTICLES:
		{
			XLstore *particles = xlGetStore(XL_PARTICLES);
			*params = particles->bind;
			break;
		}
		case XL_PARTICLES_PARTICLE:
		{
			XLparticles *bind = xlGetParticles();
			*params = bind->runtime.particle;
			break;
		}
		case XL_PARTICLES_PARTICLE_TYPE:
		{
			XLparticles *bind = xlGetParticles();
			*params = bind->runtime.particles[bind->runtime.particle].type;
			break;
		}
		case XL_PARTICLES_TYPE:
		{
			XLparticles *bind = xlGetParticles();
			*params = bind->runtime.global.type;
			break;
		}
		case XL_PARTICLES_COUNT:
		{
			XLparticles *bind = xlGetParticles();
			*params = bind->body.count;
			break;
		}
		case XL_CAMERA:
		{
			XLstore *cameras = xlGetStore(XL_CAMERA);
			*params = cameras->bind;
			break;
		}
		case XL_CAMERA_PROPERTIES:
		{
			XLcamera *bind = xlGetCamera();
			*params = bind->header.properties;
			break;
		}
		case XL_CAMERA_PROPERTY:
		{
			XLcamera *bind = xlGetCamera();
			*params = bind->runtime.property;
			break;
		}
		case XL_CAMERA_PROPERTY_TYPE:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->type;
			break;
		}
		case XL_OPERATOR:
		{
			XLstore *operators = xlGetStore(XL_OPERATOR);
			*params = operators->bind;
			break;
		}
		case XL_OPERATOR_CAMERA:
		{
			XLoperator *bind = xlGetOperator();
			*params = bind->runtime.camera;
			break;
		}
		case XL_OPERATOR_FRAMES:
		{
			XLoperator *bind = xlGetOperator();
			*params = bind->header.frames;
			break;
		}
		case XL_OPERATOR_ACTIONS:
		{
			XLoperator *bind = xlGetOperator();
			*params = bind->header.actions;
			break;
		}
		case XL_OPERATOR_ACTION_FRAMES:
		{
			XLoperator *bind = xlGetOperator();
			XLOperatorAction *action = &bind->body.actions[bind->runtime.action];
			*params = action->frames.count;
			break;
		}
		case XL_OPERATOR_ACTION:
		{
			XLoperator *bind = xlGetOperator();
			*params = bind->runtime.action;
			break;
		}
		case XL_OPERATOR_ACTION_FRAME:
		{
			XLoperator *bind = xlGetOperator();
			*params = bind->runtime.frame;
			break;
		}
		case XL_VIEWPORT:
		{
			XLstore *store = xlGetStore(XL_VIEWPORT);
			*params = store->bind;
			break;
		}
		case XL_VIEWPORT_PROPERTIES:
		{
			XLviewport *bind = xlGetViewport();
			*params = bind->header.properties;
			break;
		}
		case XL_VIEWPORT_PROPERTY:
		{
			XLviewport *bind = xlGetViewport();
			*params = bind->runtime.property;
			break;
		}
		case XL_VIEWPORT_PROPERTY_X:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			*params = XL_PAIR_X(&property->position);
			break;
		}
		case XL_VIEWPORT_PROPERTY_Y:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			*params = XL_PAIR_Y(&property->position);
			break;
		}
		case XL_VIEWPORT_PROPERTY_POSITION:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			params[0] = XL_PAIR_X(&property->position);
			params[1] = XL_PAIR_Y(&property->position);
			break;
		}
		case XL_VIEWPORT_PROPERTY_WIDTH:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			*params = XL_PAIR_X(&property->size);
			break;
		}
		case XL_VIEWPORT_PROPERTY_HEIGHT:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			*params = XL_PAIR_Y(&property->size);
			break;
		}
		case XL_VIEWPORT_PROPERTY_SIZE:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			params[0] = XL_PAIR_X(&property->size);
			params[1] = XL_PAIR_Y(&property->size);
			break;
		}
		case XL_WINDOW:
		{
			XLstore *store = xlGetStore(XL_WINDOW);
			*params = store->bind;
			break;
		}
		case XL_WINDOW_PROPERTIES:
		{
			XLwindow *bind = xlGetWindow();
			*params = bind->header.properties;
			break;
		}
		case XL_WINDOW_PROPERTY:
		{
			XLwindow *bind = xlGetWindow();
			*params = bind->runtime.property;
			break;
		}
		case XL_WINDOW_PROPERTY_X:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			*params = XL_PAIR_X(&property->position);
			break;
		}
		case XL_WINDOW_PROPERTY_Y:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			*params = XL_PAIR_Y(&property->position);
			break;
		}
		case XL_WINDOW_PROPERTY_POSITION:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			params[0] = XL_PAIR_X(&property->position);
			params[1] = XL_PAIR_Y(&property->position);
			break;
		}
		case XL_WINDOW_PROPERTY_WIDTH:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			*params = XL_PAIR_X(&property->size);
			break;
		}
		case XL_WINDOW_PROPERTY_HEIGHT:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			*params = XL_PAIR_Y(&property->size);
			break;
		}
		case XL_WINDOW_PROPERTY_SIZE:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			params[0] = XL_PAIR_X(&property->size);
			params[1] = XL_PAIR_Y(&property->size);
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

XLint
xlGetInteger(XLenum pname)
{
	XLint params;
	xlGetIntegerv(pname, &params);
	return params;
}

void
xlGetStringv(XLenum name, XLstring *params)
{
	switch(name)
	{
		case XL_ERROR_VALUE_NONE:
			xlStringCopy(*params, L"None, all correct");
			break;
		case XL_ERROR_VALUE_INVALID:
			xlStringCopy(*params, L"Invalid error");
			break;
		case XL_ERROR_VALUE_INVALID_ENUM:
			xlStringCopy(*params, L"Invalid enumerant");
			break;
		case XL_ERROR_VALUE_INVALID_VALUE:
			xlStringCopy(*params, L"Invalid value");
			break;
		case XL_ERROR_VALUE_INVALID_OP:
			xlStringCopy(*params, L"Invalid operation");
			break;
		case XL_ERROR_VALUE_INVALID_PARAM:
			xlStringCopy(*params, L"Invalid parameter");
			break;
		case XL_ERROR_VALUE_INVALID_PATH:
			xlStringCopy(*params, L"Invalid path");
			break;
		case XL_ERROR_VALUE_INVALID_DATA:
			xlStringCopy(*params, L"Invalid data");
			break;
		case XL_ERROR_VALUE_UNKNOWN:
			xlStringCopy(*params, L"Unknown error");
			break;
		case XL_VENDOR:
			xlStringCopy(*params, xlVendor);
			break;
		case XL_RENDERER:
			xlStringCopy(*params, xlRenderer);
			break;
		case XL_VERSION:
			xlStringCopy(*params, xlVersion);
			break;
		case XL_NAME:
			xlStringCopy(*params, xlName);
			break;
		case XL_DESCRIPTION:
			xlStringCopy(*params, xlDescription);
			break;
		case XL_AUTHOR:
			xlStringCopy(*params, xlAuthor);
			break;
		case XL_DATE:
			xlStringCopy(*params, xlDate);
			break;
		case XL_COPYRIGHT:
			xlStringCopy(*params, xlCopyright);
			break;
		case XL_LICENSE:
			xlStringCopy(*params, xlLicense);
			break;
		case XL_URL:
			xlStringCopy(*params, xlUrl);
			break;
		case XL_EMAIL:
			xlStringCopy(*params, xlEmail);
			break;
		case XL_TOOL:
			xlStringCopy(*params, xlTool);
			break;
		case XL_METAHEADER_TYPE:
		{
			XLmetaheader *metaheader = xlGetMetaHeader();
			xlStringCopy(*params, xlGetString(metaheader->magic));
			break;
		}
		case XL_IMAGE_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"image");
			break;
		}
		case XL_SOUND_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"sound");
			break;
		}
		case XL_FONT_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"font");
			break;
		}
		case XL_MATERIAL_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"material");
			break;
		}
		case XL_SURFACE_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"surface");
			break;
		}
		case XL_OBJECT_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"object");
			break;
		}
		case XL_MODEL_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"model");
			break;
		}
		case XL_PARTICLES_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"particles");
			break;
		}
		case XL_CAMERA_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"camera");
			break;
		}
		case XL_OPERATOR_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"operator");
			break;
		}
		case XL_VIEWPORT_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"viewport");
			break;
		}
		case XL_WINDOW_METAHEADER_MAGIC:
		{
			xlStringCopy(*params, L"window");
			break;
		}
		case XL_METADATA_NAME:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(*params, metadata->name);
			break;
		}
		case XL_METADATA_VERSION:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(*params, metadata->version);
			break;
		}
		case XL_METADATA_AUTHOR:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(*params, metadata->author);
			break;
		}
		case XL_METADATA_DATE:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(*params, metadata->date);
			break;
		}
		case XL_METADATA_COPYRIGHT:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(*params, metadata->copyright);
			break;
		}
		case XL_METADATA_LICENSE:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(metadata->license, *params);
			break;
		}
		case XL_METADATA_URL:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(*params, metadata->url);
			break;
		}
		case XL_METADATA_EMAIL:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(*params, metadata->email);
			break;
		}
		case XL_METADATA_TOOL:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(*params, metadata->tool);
			break;
		}
		case XL_METADATA_COMMENT:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(*params, metadata->comment);
			break;
		}
		case XL_METADATA_XL:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(*params, metadata->xl);
			break;
		}
		case XL_FONT_PROPERTY_NAME:
		{
			XLfont *bind = xlGetFont();
			XLFontProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(*params, property->name);
			break;
		}
		case XL_MATERIAL_PROPERTY_NAME:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(*params, property->name);
			break;
		}
		case XL_SURFACE_ACTION_NAME:
		{
			XLsurface *bind = xlGetSurface();
			XLSurfaceAction *action = &bind->body.actions[bind->runtime.action];
			xlStringCopy(*params, action->name);
			break;
		}
		case XL_OBJECT_MATERIAL_NAME:
		{
			XLobject *bind = xlGetObject();
			XLObjectMaterial *material = &bind->body.materials[bind->runtime.material];
			xlStringCopy(*params, material->name);
		}
		case XL_OBJECT_TAG_NAME:
		{
			XLobject *bind = xlGetObject();
			XLObjectTag *tag = &bind->body.tags[bind->runtime.tag];
			xlStringCopy(*params, tag->name);
		}
		case XL_CAMERA_PROPERTY_NAME:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(*params, property->name);
			break;
		}
		case XL_OPERATOR_ACTION_NAME:
		{
			XLoperator *bind = xlGetOperator();
			XLOperatorAction *action = &bind->body.actions[bind->runtime.action];
			xlStringCopy(*params, action->name);
			break;
		}
		case XL_VIEWPORT_PROPERTY_NAME:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(*params, property->name);
			break;
		}
		case XL_WINDOW_PROPERTY_NAME:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(*params, property->name);
			break;
		}
		case XL_WINDOW_PROPERTY_TITLE:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(*params, property->title);
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

XLwchar *
xlGetString(XLenum name)
{
	switch(name)
	{
		case XL_ERROR_VALUE_NONE:
			return L"None, all correct";
			break;
		case XL_ERROR_VALUE_INVALID:
			return L"Invalid error";
			break;
		case XL_ERROR_VALUE_INVALID_ENUM:
			return L"Invalid enumerant";
			break;
		case XL_ERROR_VALUE_INVALID_VALUE:
			return L"Invalid value";
			break;
		case XL_ERROR_VALUE_INVALID_OP:
			return L"Invalid operation";
			break;
		case XL_ERROR_VALUE_INVALID_PARAM:
			return L"Invalid parameter";
			break;
		case XL_ERROR_VALUE_INVALID_PATH:
			return L"Invalid path";
			break;
		case XL_ERROR_VALUE_INVALID_DATA:
			return L"Invalid data";
			break;
		case XL_ERROR_VALUE_UNKNOWN:
			return L"Unknown error";
			break;
		case XL_VENDOR:
			return xlVendor;
			break;
		case XL_RENDERER:
			return xlRenderer;
			break;
		case XL_VERSION:
			return xlVersion;
			break;
		case XL_NAME:
			return xlName;
			break;
		case XL_DESCRIPTION:
			return xlDescription;
			break;
		case XL_AUTHOR:
			return xlAuthor;
			break;
		case XL_DATE:
			return xlDate;
			break;
		case XL_COPYRIGHT:
			return xlCopyright;
			break;
		case XL_LICENSE:
			return xlLicense;
			break;
		case XL_URL:
			return xlUrl;
			break;
		case XL_EMAIL:
			return xlEmail;
			break;
		case XL_TOOL:
			return xlTool;
			break;
		case XL_METAHEADER_TYPE:
		{
			XLmetaheader *metaheader = xlGetMetaHeader();
			return xlGetString(metaheader->magic);
			break;
		}
		case XL_IMAGE_METAHEADER_MAGIC:
		{
			return L"image";
			break;
		}
		case XL_SOUND_METAHEADER_MAGIC:
		{
			return L"sound";
			break;
		}
		case XL_FONT_METAHEADER_MAGIC:
		{
			return L"font";
			break;
		}
		case XL_MATERIAL_METAHEADER_MAGIC:
		{
			return L"material";
			break;
		}
		case XL_SURFACE_METAHEADER_MAGIC:
		{
			return L"surface";
			break;
		}
		case XL_OBJECT_METAHEADER_MAGIC:
		{
			return L"object";
			break;
		}
		case XL_MODEL_METAHEADER_MAGIC:
		{
			return L"model";
			break;
		}
		case XL_PARTICLES_METAHEADER_MAGIC:
		{
			return L"particles";
			break;
		}
		case XL_CAMERA_METAHEADER_MAGIC:
		{
			return L"camera";
			break;
		}
		case XL_OPERATOR_METAHEADER_MAGIC:
		{
			return L"operator";
			break;
		}
		case XL_VIEWPORT_METAHEADER_MAGIC:
		{
			return L"viewport";
			break;
		}
		case XL_WINDOW_METAHEADER_MAGIC:
		{
			return L"window";
			break;
		}
		case XL_METADATA_NAME:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->name;
			break;
		}
		case XL_METADATA_VERSION:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->version;
			break;
		}
		case XL_METADATA_AUTHOR:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->author;
			break;
		}
		case XL_METADATA_DATE:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->date;
			break;
		}
		case XL_METADATA_COPYRIGHT:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->copyright;
			break;
		}
		case XL_METADATA_LICENSE:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->license;
			break;
		}
		case XL_METADATA_URL:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->url;
			break;
		}
		case XL_METADATA_EMAIL:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->email;
			break;
		}
		case XL_METADATA_TOOL:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->tool;
			break;
		}
		case XL_METADATA_COMMENT:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->comment;
			break;
		}
		case XL_METADATA_XL:
		{
			XLmetadata *metadata = xlGetMetaData();
			return metadata->xl;
			break;
		}
		case XL_FONT_PROPERTY_NAME:
		{
			XLfont *bind = xlGetFont();
			XLFontProperty *property = &bind->body.properties[bind->runtime.property];
			return property->name;
			break;
		}
		case XL_MATERIAL_PROPERTY_NAME:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			return property->name;
			break;
		}
		case XL_SURFACE_ACTION_NAME:
		{
			XLsurface *bind = xlGetSurface();
			XLSurfaceAction *action = &bind->body.actions[bind->runtime.action];
			return action->name;
			break;
		}
		case XL_CAMERA_PROPERTY_NAME:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			return property->name;
			break;
		}
		case XL_OPERATOR_ACTION_NAME:
		{
			XLoperator *bind = xlGetOperator();
			XLOperatorAction *action = &bind->body.actions[bind->runtime.action];
			return action->name;
			break;
		}
		case XL_VIEWPORT_PROPERTY_NAME:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			return property->name;
			break;
		}
		case XL_WINDOW_PROPERTY_NAME:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			return property->name;
			break;
		}
		case XL_WINDOW_PROPERTY_TITLE:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			return property->title;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			return NULL;
			break;
	}
}

void
xlGetPathv(XLenum name, XLpath *params)
{
	switch(name)
	{
		case XL_ERROR_FILE:
		{
			XLerror *error = xlGetError();
			xlPathCopy(*params, error->file);
			break;
		}
		case XL_ERROR_FUNCTION:
		{
			XLerror *error = xlGetError();
			xlPathCopy(*params, error->function);
			break;
		}
		case XL_METAHEADER_PATH:
		{
			XLmetaheader *metaheader = xlGetMetaHeader();
			xlPathCopy(*params, metaheader->path);
			break;
		}
		case XL_IMAGE_METAHEADER_PATH:
		{
			XLimage *bind = xlGetImage();
			xlPathCopy(*params, bind->header.metaheader.path);
			break;
		}
		case XL_SOUND_METAHEADER_PATH:
		{
			XLsound *bind = xlGetSound();
			xlPathCopy(*params, bind->header.metaheader.path);
			break;
		}
		case XL_FONT_METAHEADER_PATH:
		{
			XLfont *bind = xlGetFont();
			xlPathCopy(*params, bind->header.metaheader.path);
			break;
		}
		case XL_FONT_PATH:
		{
			XLfont *bind = xlGetFont();
			xlPathCopy(*params, bind->body.path);
			break;
		}
		case XL_MATERIAL_METAHEADER_PATH:
		{
			XLmaterial *bind = xlGetMaterial();
			xlPathCopy(*params, bind->header.metaheader.path);
			break;
		}
		case XL_MATERIAL_PROPERTY_IMAGE:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			xlPathCopy(*params, property->image);
			break;
		}
		case XL_SURFACE_METAHEADER_PATH:
		{
			XLsurface *bind = xlGetSurface();
			xlPathCopy(*params, bind->header.metaheader.path);
			break;
		}
		case XL_SURFACE_MATERIAL:
		{
			XLsurface *bind = xlGetSurface();
			xlPathCopy(*params, bind->body.material->path);
			break;
		}
		case XL_OBJECT_METAHEADER_PATH:
		{
			XLobject *bind = xlGetObject();
			xlPathCopy(*params, bind->header.metaheader.path);
			break;
		}
		case XL_MODEL_METAHEADER_PATH:
		{
			XLmodel *bind = xlGetModel();
			xlPathCopy(*params, bind->header.metaheader.path);
			break;
		}
		case XL_MODEL_OBJECT:
		{
			XLmodel *bind = xlGetModel();
			xlPathCopy(*params, bind->body.object->path);
			break;
		}
		case XL_PARTICLES_METAHEADER_PATH:
		{
			XLparticles *bind = xlGetParticles();
			xlPathCopy(*params, bind->header.metaheader.path);
			break;
		}
		case XL_CAMERA_METAHEADER_PATH:
		{
			XLcamera *bind = xlGetCamera();
			xlPathCopy(*params, bind->header.metaheader.path);
			break;
		}
		case XL_OPERATOR_METAHEADER_PATH:
		{
			XLoperator *bind = xlGetOperator();
			xlPathCopy(*params, bind->header.metaheader.path);
			break;
		}
		case XL_OPERATOR_CAMERA:
		{
			XLoperator *bind = xlGetOperator();
			xlPathCopy(*params, bind->body.camera->path);
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

XLchar *
xlGetPath(XLenum name)
{
	switch(name)
	{
		case XL_ERROR_FILE:
		{
			XLerror *error = xlGetError();
			return error->file;
			break;
		}
		case XL_ERROR_LINE:
		{
			XLerror *error = xlGetError();
			return error->function;
			break;
		}
		case XL_METAHEADER_PATH:
		{
			XLmetaheader *metaheader = xlGetMetaHeader();
			return metaheader->path;
			break;
		}
		case XL_IMAGE_METAHEADER_PATH:
		{
			XLimage *bind = xlGetImage();
			return bind->header.metaheader.path;
			break;
		}
		case XL_SOUND_METAHEADER_PATH:
		{
			XLsound *bind = xlGetSound();
			return bind->header.metaheader.path;
			break;
		}
		case XL_FONT_METAHEADER_PATH:
		{
			XLfont *bind = xlGetFont();
			return bind->header.metaheader.path;
			break;
		}
		case XL_FONT_PATH:
		{
			XLfont *bind = xlGetFont();
			return bind->body.path;
			break;
		}
		case XL_MATERIAL_METAHEADER_PATH:
		{
			XLmaterial *bind = xlGetMaterial();
			return bind->header.metaheader.path;
			break;
		}
		case XL_MATERIAL_PROPERTY_IMAGE:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			return property->image;
			break;
		}
		case XL_SURFACE_METAHEADER_PATH:
		{
			XLsurface *bind = xlGetSurface();
			return bind->header.metaheader.path;
			break;
		}
		case XL_SURFACE_MATERIAL:
		{
			XLsurface *bind = xlGetSurface();
			return bind->body.material->path;
			break;
		}
		case XL_OBJECT_METAHEADER_PATH:
		{
			XLobject *bind = xlGetObject();
			return bind->header.metaheader.path;
			break;
		}
		case XL_MODEL_METAHEADER_PATH:
		{
			XLmodel *bind = xlGetModel();
			return bind->header.metaheader.path;
			break;
		}
		case XL_MODEL_OBJECT:
		{
			XLmodel *bind = xlGetModel();
			return bind->body.object->path;
			break;
		}
		case XL_PARTICLES_METAHEADER_PATH:
		{
			XLparticles *bind = xlGetParticles();
			return bind->header.metaheader.path;
			break;
		}
		case XL_CAMERA_METAHEADER_PATH:
		{
			XLcamera *bind = xlGetCamera();
			return bind->header.metaheader.path;
			break;
		}
		case XL_OPERATOR_METAHEADER_PATH:
		{
			XLoperator *bind = xlGetOperator();
			return bind->header.metaheader.path;
			break;
		}
		case XL_OPERATOR_CAMERA:
		{
			XLoperator *bind = xlGetOperator();
			return bind->body.camera->path;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			return NULL;
			break;
	}
}

void
xlGetDoublev(XLenum pname, XLdouble *params)
{
}

void
xlGetFloatv(XLenum pname, XLfloat *params)
{
}

void
xlGetRealv(XLenum pname, XLreal *params)
{
	switch(pname)
	{
		case XL_TIME_TOTAL:
		{
			*params =  xlTimeTotal;
			break;
		}
		case XL_TIME_DELTA:
		{
			*params =  xlTimeDelta;
			break;
		}
		case XL_MATERIAL_PROPERTY_ALPHA:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->alpha;
			break;
		}
		case XL_MATERIAL_PROPERTY_SHININESS:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->shininess;
			break;
		}
		case XL_SURFACE_ACTION_FRAME_TIME:
		{
			XLsurface *bind = xlGetSurface();
			XLSurfaceAction *action = &bind->body.actions[bind->runtime.action];
			XLSurfaceFrame *frame = &bind->body.frames[action->frames.start + bind->runtime.frame];
			*params = frame->time;
			break;
		}
		case XL_PARTICLES_PARTICLE_ENERGY:
		{
			XLparticles *bind = xlGetParticles();
			*params = bind->runtime.particles[bind->runtime.particle].energy;
			break;
		}
		case XL_PARTICLES_ENERGY:
		{
			XLparticles *bind = xlGetParticles();
			*params = bind->runtime.global.energy;
			break;
		}
		case XL_CAMERA_PROPERTY_LEFT:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->details.orthogonal.left;
			break;
		}
		case XL_CAMERA_PROPERTY_RIGHT:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->details.orthogonal.right;
			break;
		}
		case XL_CAMERA_PROPERTY_BOTTOM:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->details.orthogonal.bottom;
			break;
		}
		case XL_CAMERA_PROPERTY_TOP:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->details.orthogonal.top;
			break;
		}
		case XL_CAMERA_PROPERTY_FIELD_OF_VIEW:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->details.perspective.fovy;
			break;
		}
		case XL_CAMERA_PROPERTY_ASPECT:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->details.perspective.aspect;
			break;
		}
		case XL_CAMERA_PROPERTY_ZNEAR:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->details.perspective.znear;
			break;
		}
		case XL_CAMERA_PROPERTY_ZFAR:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = property->details.perspective.zfar;
			break;
		}
		case XL_OPERATOR_ACTION_FRAME_TIME:
		{
			XLoperator *bind = xlGetOperator();
			XLOperatorAction *action = &bind->body.actions[bind->runtime.action];
			XLOperatorFrame *frame = &bind->body.frames[action->frames.start + bind->runtime.frame];
			*params = frame->time;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

XLreal
xlGetReal(XLenum pname)
{
	XLreal params;
	xlGetRealv(pname, &params);
	return params;
}

#define _xlPairGet(e, c) \
		case XL_PAIR_ ## e: \
			*params = xlPair ## c; \
			break;

void
xlGetPairv(XLenum pname, XLpair **params)
{
	switch(pname)
	{
		xlPairsForEach(_xlPairGet)

		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

#undef _xlPairGet

XLpair *
xlGetPair(XLenum pname)
{
	XLpair *params;
	xlGetPairv(pname, &params);
	return params;
}

#define _xlColorGet(e, c) \
		case XL_COLOR_ ## e: \
			*params = xlColor ## c; \
			break;

void
xlGetColorv(XLenum pname, XLcolor **params)
{
	switch(pname)
	{
		xlColorsForEach(_xlColorGet)

		case XL_IMAGE_PIXELS:
		{
			XLimage *bind = xlGetImage();
			*params = bind->body.pixels;
			break;
		}
		case XL_MATERIAL_PROPERTY_AMBIENT:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			*params = &property->ambient;
			break;
		}
		case XL_MATERIAL_PROPERTY_DIFFUSE:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			*params = &property->diffuse;
			break;
		}
		case XL_MATERIAL_PROPERTY_SPECULAR:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			*params = &property->specular;
			break;
		}
		case XL_MATERIAL_PROPERTY_EMISSION:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			*params = &property->emission;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

#undef _xlColorGet

XLcolor *
xlGetColor(XLenum pname)
{
	XLcolor *params;
	xlGetColorv(pname, &params);
	return params;
}

#define _xlPointGet(e, c) \
		case XL_POINT_ ## e: \
			*params = xlPoint ## c; \
			break;

void
xlGetPointv(XLenum pname, XLpoint **params)
{
	switch(pname)
	{
		xlPointsForEach(_xlPointGet)

		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

#undef _xlPointGet

XLpoint *
xlGetPoint(XLenum pname)
{
	XLpoint *params;
	xlGetPointv(pname, &params);
	return params;
}

#define _xlVectorGet(e, c) \
		case XL_VECTOR_ ## e: \
			*params = xlVector ## c; \
			break;

void
xlGetVectorv(XLenum pname, XLvector **params)
{
	switch(pname)
	{
		xlVectorsForEach(_xlVectorGet)

		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

#undef _xlVectorGet

XLvector *
xlGetVector(XLenum pname)
{
	XLvector *params;
	xlGetVectorv(pname, &params);
	return params;
}

#define _xlMatrixGet(e, c) \
		case XL_MATRIX_ ## e: \
			*params = xlMatrix ## c; \
			break;

void
xlGetMatrixv(XLenum pname, XLmatrix **params)
{
	switch(pname)
	{
		xlMatricesForEach(_xlMatrixGet)

		case XL_MATERIAL_PROPERTY_MATRIX:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			*params = &property->matrix;
			break;
		}
		case XL_SURFACE_ACTION_FRAME_MATRIX:
		{
			XLsurface *bind = xlGetSurface();
			XLSurfaceAction *action = &bind->body.actions[bind->runtime.action];
			XLSurfaceFrame *frame = &bind->body.frames[action->frames.start + bind->runtime.frame];
			*params = &frame->matrix;
			break;
		}
		case XL_OBJECT_TAG_MATRIX:
		{
			XLobject *bind = xlGetObject();
			XLObjectTag *tag = &bind->body.tags[bind->runtime.tag];
			*params = &tag->matrix;
		}
		case XL_OBJECT_MATRIX:
		{
			XLobject *bind = xlGetObject();
			*params = &bind->runtime.matrix;
			break;
		}
		case XL_PARTICLES_PARTICLE_MATRIX:
		{
			XLparticles *bind = xlGetParticles();
			*params = &bind->runtime.particles[bind->runtime.particle].matrix;
			break;
		}
		case XL_PARTICLES_MATRIX:
		{
			XLparticles *bind = xlGetParticles();
			*params = &bind->runtime.global.matrix;
			break;
		}
		case XL_CAMERA_PROPERTY_MATRIX:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = &property->matrix;
			break;
		}
		case XL_CAMERA_PROPERTY_PROJECTION:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = &property->projection;
			break;
		}
		case XL_CAMERA_PROPERTY_MODELVIEW:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			*params = &property->modelview;
			break;
		}
		case XL_OPERATOR_ACTION_FRAME_MATRIX:
		{
			XLoperator *bind = xlGetOperator();
			XLOperatorAction *action = &bind->body.actions[bind->runtime.action];
			XLOperatorFrame *frame = &bind->body.frames[action->frames.start + bind->runtime.frame];
			*params = &frame->matrix;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

#undef _xlMatrixGet

XLmatrix *
xlGetMatrix(XLenum pname)
{
	XLmatrix *params;
	xlGetMatrixv(pname, &params);
	return params;
}

void
xlGetPointerv(XLenum pname, void **params)
{
	switch(pname)
	{
		case XL_PARTICLES_PARTICLE:
		{
			XLparticles *bind = xlGetParticles();
			*params = &bind->runtime.particles[bind->runtime.particle];
			break;
		}
		case XL_PARTICLES_PARTICLE_DATA:
		{
			XLparticles *bind = xlGetParticles();
			*params = &bind->runtime.particles[bind->runtime.particle].data;
			break;
		}
		case XL_PARTICLES_DATA:
		{
			XLparticles *bind = xlGetParticles();
			*params = &bind->runtime.global.data;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

void *
xlGetPointer(XLenum pname)
{
	void *params;
	xlGetPointerv(pname, &params);
	return params;
}

XLenum 
xlGetPathType(const XLpath path)
{
	XLenum type;
	XLsizei len;
	
	len = xlPathLength(path);
	if((len > 4 && xlPathEqual(path + len - 4, ".xlc")) || (len > 8 && xlPathEqual(path + len - 8, ".xlc.bz2")))
		type = XL_DATA_BINARY;
	else if((len > 4 && xlPathEqual(path + len - 4, ".xld")) || (len > 8 && xlPathEqual(path + len - 8, ".xld.bz2")))
		type = XL_DATA_SOURCE;
	else if((len > 3 && xlPathEqual(path + len - 3, ".xl")) || (len > 7 && xlPathEqual(path + len - 7, ".xl.bz2")))
		type = XL_DATA_PROCESS;
	else
		type = XL_DATA_EXTERNAL;

	return type;
}

XLenum 
xlGetPathFormat(const XLpath path)
{
	XLenum format = XL_NONE;
	const XLchar *mime;
	
	if((mime = magic_file(xlMagicCookie, path)))
	{
		if(xlPathCappedEqual(mime, "application/x-bzip2", 19))
			format = XL_FILE_BZIP2;
		else
			format = XL_FILE_PLAIN;
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);

	return format;
}

XLenum
xlGetMagic(XLstring type)
{
	XLenum magic;

	if(xlStringEqual(type, L"image"))
		magic = XL_IMAGE_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"sound"))
		magic = XL_SOUND_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"font"))
		magic = XL_FONT_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"material"))
		magic = XL_MATERIAL_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"surface"))
		magic = XL_SURFACE_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"object"))
		magic = XL_OBJECT_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"model"))
		magic = XL_MODEL_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"particles"))
		magic = XL_PARTICLES_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"camera"))
		magic = XL_CAMERA_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"operator"))
		magic = XL_OPERATOR_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"viewport"))
		magic = XL_VIEWPORT_METAHEADER_MAGIC;
	else if(xlStringEqual(type, L"window"))
		magic = XL_WINDOW_METAHEADER_MAGIC;
	else
	{
		xlSetError(XL_ERROR_VALUE_INVALID_PARAM);
		magic = XL_NONE;
	}

	return magic;
}

#define _xlGetIdStore(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	case XL_ ## IDENTIFIER: \
	{ \
		return xlStores.data[xl ## Identifiers]; \
		break; \
	}
		
XLstore *
xlGetStore(XLenum pname)
{
	switch(pname)
	{
		case XL_METAHEADER:
		{
			return xlStores.data[xlMetaHeaders];
			break;
		}
		case XL_METADATA:
		{
			return xlStores.data[xlMetaDatas];
			break;
		}

		xlIdForEach(_xlGetIdStore)

		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			return NULL;
			break;
	}
}

#undef _xlGetIdStore

XLmetaheader *
xlGetMetaHeader(void)
{
	XLstore *metaheaders = xlStores.data[xlMetaHeaders];
	return metaheaders->data[metaheaders->bind];
}

XLmetadata *
xlGetMetaData(void)
{
	XLstore *metadatas = xlStores.data[xlMetaDatas];
	return metadatas->data[metadatas->bind];
}

#define _xlGetIdentifier(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	XL ## identifier *\
	xlGet ## Identifier(void) \
	{ \
		XLstore *store = xlStores.data[xl ## Identifiers]; \
		return store->data[store->bind]; \
	}
		
xlIdForEach(_xlGetIdentifier)

#undef _xlGetIdentifier

XLcolor *
xlGetImgPixels(void)
{
	XLstore *images = xlStores.data[xlImages];
	XLimage *bind = images->data[images->bind];

	return bind->body.pixels;
}

XLsample *
xlGetSndSamples(void)
{
	XLstore *sounds = xlStores.data[xlSounds];
	XLsound *bind = sounds->data[sounds->bind];

	return bind->body.samples;
}

