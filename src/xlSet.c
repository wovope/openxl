#include "XL/xlSet.h"
#include "XL/xl.h"

void
xlSetErrorPoint(const XLpath file, const XLpath function, XLuint line, XLenum error)
{
	xlPathCopy(xlError.file, file);
	xlPathCopy(xlError.function, function);
	xlError.line = line;
	xlError.value = error;
}

void
xlSetLogLevel(XLenum level)
{
	xlLogLevel = level;
}

void
xlSetBooleanv(XLenum pname, XLboolean *params)
{
	switch(pname)
	{
		case XL_OBJECT_MATERIAL_SURFACE:
		{
			XLobject *bind = xlGetObject();
			bind->body.materials[bind->runtime.material].surface = *params;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

void
xlSetBoolean(XLenum pname, XLboolean param)
{
	xlSetBooleanv(pname, &param);
}

void
xlSetIntegerv(XLenum pname, XLint *params)
{
	switch(pname)
	{
		case XL_ERROR_LINE:
		{
			XLerror *error = xlGetError();
			error->line = *params;
			break;
		}
		case XL_ERROR_VALUE:
		{
			XLerror *error = xlGetError();
			error->value = *params;
			break;
		}
		case XL_METAHEADER:
		{
			XLstore *metaheaders = xlGetStore(XL_METAHEADER);
			metaheaders->bind = *params;
			break;
		}
		case XL_METAHEADER_MAGIC:
		{
			XLmetaheader *metaheader = xlGetMetaHeader();
			metaheader->magic = *params;
			break;
		}
		case XL_METADATA:
		{
			XLstore *metadatas = xlGetStore(XL_METADATA);
			metadatas->bind = *params;
			break;
		}
		case XL_IMAGE:
		{
			XLstore *images = xlGetStore(XL_IMAGE);
			images->bind = *params;
			break;
		}
		case XL_IMAGE_WIDTH:
		{
			XLimage *bind = xlGetImage();
			bind->header.width = *params;
			break;
		}
		case XL_IMAGE_HEIGHT:
		{
			XLimage *bind = xlGetImage();
			bind->header.height = *params;
			break;
		}
		case XL_IMAGE_SIZE:
		{
			XLimage *bind = xlGetImage();
			bind->header.width = params[0];
			bind->header.height = params[1];
			break;
		}
		case XL_IMAGE_BYTES_PER_PIXEL:
		{
			XLimage *bind = xlGetImage();
			bind->header.bpp = *params;
			break;
		}
		case XL_IMAGE_TEXTURE:
		{
			XLimage *bind = xlGetImage();
			bind->runtime.texture = *params;
			break;
		}
		case XL_FONT:
		{
			XLstore *fonts = xlGetStore(XL_FONT);
			fonts->bind = *params;
			break;
		}
		case XL_FONT_PROPERTIES:
		{
			XLfont *bind = xlGetFont();
			bind->header.properties = *params;
			break;
		}
		case XL_FONT_PROPERTY:
		{
			XLfont *bind = xlGetFont();
			bind->runtime.property = *params;
			break;
		}
		case XL_FONT_PROPERTY_WIDTH:
		{
			XLfont *bind = xlGetFont();
			XLFontProperty *property = &bind->body.properties[bind->runtime.property];
			property->width = *params;
			break;
		}
		case XL_FONT_PROPERTY_HEIGHT:
		{
			XLfont *bind = xlGetFont();
			XLFontProperty *property = &bind->body.properties[bind->runtime.property];
			property->height = *params;
			break;
		}
		case XL_FONT_PROPERTY_SIZE:
		{
			XLfont *bind = xlGetFont();
			XLFontProperty *property = &bind->body.properties[bind->runtime.property];
			property->width = params[0];
			property->height = params[1];
			break;
		}
		case XL_MATERIAL:
		{
			XLstore *materials = xlGetStore(XL_MATERIAL);
			materials->bind = *params;
			break;
		}
		case XL_MATERIAL_PROPERTIES:
		{
			XLmaterial *bind = xlGetMaterial();
			bind->header.properties = *params;
			break;
		}
		case XL_MATERIAL_PROPERTY:
		{
			XLmaterial *bind = xlGetMaterial();
			bind->runtime.property = *params;
			break;
		}
		case XL_SURFACE:
		{
			XLstore *surfaces = xlGetStore(XL_SURFACE);
			surfaces->bind = *params;
			break;
		}
		case XL_SURFACE_MATERIAL:
		{
			XLsurface *bind = xlGetSurface();
			bind->runtime.material = *params;
			break;
		}
		case XL_SURFACE_FRAMES:
		{
			XLsurface *bind = xlGetSurface();
			bind->header.frames = *params;
			break;
		}
		case XL_SURFACE_ACTIONS:
		{
			XLsurface *bind = xlGetSurface();
			bind->header.actions = *params;
			break;
		}
		case XL_SURFACE_ACTION_FRAMES:
		{
			XLsurface *bind = xlGetSurface();
			XLSurfaceAction *action = &bind->body.actions[bind->runtime.action];
			action->frames.start = *params;
			break;
		}
		case XL_SURFACE_ACTION:
		{
			XLsurface *bind = xlGetSurface();
			bind->runtime.action = *params;
			bind->runtime.frame = 0;
			bind->runtime.time = XL_REAL(0);
			break;
		}
		case XL_SURFACE_ACTION_FRAME:
		{
			XLsurface *bind = xlGetSurface();
			bind->runtime.frame = *params;
			break;
		}
		case XL_OBJECT:
		{
			XLstore *objects = xlGetStore(XL_OBJECT);
			objects->bind = *params;
			break;
		}
		case XL_OBJECT_VERTICES:
		{
			XLobject *bind = xlGetObject();
			bind->header.vertices = *params;
			break;
		}
		case XL_OBJECT_MATERIALS:
		{
			XLobject *bind = xlGetObject();
			bind->header.materials = *params;
			break;
		}
		case XL_OBJECT_MATERIAL:
		{
			XLobject *bind = xlGetObject();
			bind->runtime.material = *params;
			break;
		}
		case XL_OBJECT_MATERIAL_MATERIAL:
		{
			XLobject *bind = xlGetObject();
			bind->runtime.materials[bind->runtime.material] = *params;
			break;
		}
		case XL_OBJECT_TAG:
		{
			XLobject *bind = xlGetObject();
			bind->runtime.tag = *params;
			break;
		}
		case XL_OBJECT_FACES:
		{
			XLobject *bind = xlGetObject();
			bind->header.faces = *params;
			break;
		}
		case XL_OBJECT_TAGS:
		{
			XLobject *bind = xlGetObject();
			bind->header.tags = *params;
			break;
		}
		case XL_MODEL:
		{
			XLstore *models = xlGetStore(XL_MODEL);
			models->bind = *params;
			break;
		}
		case XL_MODEL_OBJECT:
		{
			XLmodel *bind = xlGetModel();
			bind->runtime.object = *params;
			break;
		}
		case XL_MODEL_BONES:
		{
			XLmodel *bind = xlGetModel();
			bind->header.bones = *params;
			break;
		}
		case XL_MODEL_PARENTS:
		{
			XLmodel *bind = xlGetModel();
			bind->header.parents = *params;
			break;
		}
		case XL_MODEL_VERTICES:
		{
			XLmodel *bind = xlGetModel();
			bind->header.vertices = *params;
			break;
		}
		case XL_MODEL_TAGS:
		{
			XLmodel *bind = xlGetModel();
			bind->header.tags = *params;
			break;
		}
		case XL_MODEL_WEIGHTS:
		{
			XLmodel *bind = xlGetModel();
			bind->header.weights = *params;
			break;
		}
		case XL_MODEL_FRAMES:
		{
			XLmodel *bind = xlGetModel();
			bind->header.frames = *params;
			break;
		}
		case XL_MODEL_ACTIONS:
		{
			XLmodel *bind = xlGetModel();
			bind->header.actions = *params;
			break;
		}
		case XL_MODEL_ACTION_FRAMES:
		{
			XLmodel *bind = xlGetModel();
			XLModelAction *action = &bind->body.actions[bind->runtime.action[1]];
			action->frames.count = *params;
			break;
		}
		case XL_MODEL_ACTION:
		{
			XLmodel *bind = xlGetModel();
			bind->runtime.action[0] = bind->runtime.action[1];
			bind->runtime.frame[0] = bind->runtime.frame[1];
			bind->runtime.action[1] = *params;
			bind->runtime.frame[1] = 0;
			bind->runtime.morphfactor = XL_REAL(0);
			bind->runtime.time[0] = bind->runtime.time[1];
			bind->runtime.time[1] = XL_REAL(0);
			break;
		}
		case XL_MODEL_ACTION_FRAME:
		{
			XLmodel *bind = xlGetModel();
			bind->runtime.action[0] = bind->runtime.action[1];
			bind->runtime.frame[0] = bind->runtime.frame[1];
			bind->runtime.frame[1] = *params;
			bind->runtime.morphfactor = XL_REAL(0);
			bind->runtime.time[0] = bind->runtime.time[1];
			bind->runtime.time[1] = XL_REAL(0);
			break;
		}
		case XL_PARTICLES:
		{
			XLstore *particles = xlGetStore(XL_PARTICLES);
			particles->bind = *params;
			break;
		}
		case XL_PARTICLES_PARTICLE:
		{
			XLparticles *particles = xlGetParticles();
			particles->runtime.particle = *params;
			break;
		}
		case XL_PARTICLES_PARTICLE_TYPE:
		{
			XLparticles *particles = xlGetParticles();
			particles->runtime.particles[particles->runtime.particle].type = *params;
			break;
		}
		case XL_PARTICLES_TYPE:
		{
			XLparticles *particles = xlGetParticles();
			particles->runtime.global.type = *params;
			break;
		}
		case XL_PARTICLES_COUNT:
		{
			XLparticles *particles = xlGetParticles();
			particles->body.count = *params;
			break;
		}
		case XL_CAMERA:
		{
			XLstore *cameras = xlGetStore(XL_CAMERA);
			cameras->bind = *params;
			break;
		}
		case XL_CAMERA_PROPERTIES:
		{
			XLcamera *bind = xlGetCamera();
			bind->header.properties = *params;
			break;
		}
		case XL_CAMERA_PROPERTY:
		{
			XLcamera *bind = xlGetCamera();
			bind->runtime.property = *params;
			break;
		}
		case XL_CAMERA_PROPERTY_TYPE:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->type = *params;
			break;
		}
		case XL_OPERATOR:
		{
			XLstore *operators = xlGetStore(XL_OPERATOR);
			operators->bind = *params;
			break;
		}
		case XL_OPERATOR_CAMERA:
		{
			XLoperator *bind = xlGetOperator();
			bind->runtime.camera = *params;
			break;
		}
		case XL_OPERATOR_FRAMES:
		{
			XLoperator *bind = xlGetOperator();
			bind->header.frames = *params;
			break;
		}
		case XL_OPERATOR_ACTIONS:
		{
			XLoperator *bind = xlGetOperator();
			bind->header.actions = *params;
			break;
		}
		case XL_OPERATOR_ACTION_FRAMES:
		{
			XLoperator *bind = xlGetOperator();
			XLOperatorAction *action = &bind->body.actions[bind->runtime.action];
			action->frames.count = *params;
			break;
		}
		case XL_OPERATOR_ACTION:
		{
			XLoperator *bind = xlGetOperator();
			bind->runtime.action = *params;
			bind->runtime.frame = 0;
			bind->runtime.time = XL_REAL(0);
			break;
		}
		case XL_OPERATOR_ACTION_FRAME:
		{
			XLoperator *bind = xlGetOperator();
			bind->runtime.frame = *params;
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
			bind->header.properties = *params;
			break;
		}
		case XL_VIEWPORT_PROPERTY:
		{
			XLviewport *bind = xlGetViewport();
			bind->runtime.property = *params;
			break;
		}
		case XL_VIEWPORT_PROPERTY_X:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_X(&property->position) = *params;
			break;
		}
		case XL_VIEWPORT_PROPERTY_Y:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_Y(&property->position) = *params;
			break;
		}
		case XL_VIEWPORT_PROPERTY_POSITION:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_X(&property->position) = params[0];
			XL_PAIR_Y(&property->position) = params[1];
			break;
		}
		case XL_VIEWPORT_PROPERTY_WIDTH:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_X(&property->size) = *params;
			break;
		}
		case XL_VIEWPORT_PROPERTY_HEIGHT:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_Y(&property->size) = *params;
			break;
		}
		case XL_VIEWPORT_PROPERTY_SIZE:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_X(&property->size) = params[0];
			XL_PAIR_Y(&property->size) = params[1];
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
			bind->header.properties = *params;
			break;
		}
		case XL_WINDOW_PROPERTY:
		{
			XLwindow *bind = xlGetWindow();
			bind->runtime.property = *params;
			break;
		}
		case XL_WINDOW_PROPERTY_X:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_X(&property->position) = *params;
			break;
		}
		case XL_WINDOW_PROPERTY_Y:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_Y(&property->position) = *params;
			break;
		}
		case XL_WINDOW_PROPERTY_POSITION:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_X(&property->position) = params[0];
			XL_PAIR_Y(&property->position) = params[1];
			break;
		}
		case XL_WINDOW_PROPERTY_WIDTH:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_X(&property->size) = *params;
			break;
		}
		case XL_WINDOW_PROPERTY_HEIGHT:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_Y(&property->size) = *params;
			break;
		}
		case XL_WINDOW_PROPERTY_SIZE:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			XL_PAIR_X(&property->size) = params[0];
			XL_PAIR_Y(&property->size) = params[1];
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

void
xlSetInteger(XLenum pname, XLint param)
{
	xlSetIntegerv(pname, &param);
}

void
xlSetStringv(XLenum name, XLstring *params)
{
	switch(name)
	{
		case XL_METAHEADER_TYPE:
		{
			XLmetaheader *metaheader = xlGetMetaHeader();
			metaheader->magic = xlGetMagic(*params);
			break;
		}
		case XL_METADATA_NAME:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(metadata->name, *params);
			break;
		}
		case XL_METADATA_VERSION:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(metadata->version, *params);
			break;
		}
		case XL_METADATA_AUTHOR:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(metadata->author, *params);
			break;
		}
		case XL_METADATA_DATE:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(metadata->date, *params);
			break;
		}
		case XL_METADATA_COPYRIGHT:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(metadata->copyright, *params);
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
			xlStringCopy(metadata->url, *params);
			break;
		}
		case XL_METADATA_EMAIL:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(metadata->email, *params);
			break;
		}
		case XL_METADATA_TOOL:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(metadata->tool, *params);
			break;
		}
		case XL_METADATA_COMMENT:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(metadata->comment, *params);
			break;
		}
		case XL_METADATA_XL:
		{
			XLmetadata *metadata = xlGetMetaData();
			xlStringCopy(metadata->xl, *params);
			break;
		}
		case XL_FONT_PROPERTY_NAME:
		{
			XLfont *bind = xlGetFont();
			XLFontProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(property->name, *params);
			break;
		}
		case XL_MATERIAL_PROPERTY_NAME:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(property->name, *params);
			break;
		}
		case XL_SURFACE_ACTION_NAME:
		{
			XLsurface *bind = xlGetSurface();
			XLSurfaceAction *action = &bind->body.actions[bind->runtime.action];
			xlStringCopy(action->name, *params);
			break;
		}
		case XL_OBJECT_MATERIAL_NAME:
		{
			XLobject *bind = xlGetObject();
			XLObjectMaterial *material = &bind->body.materials[bind->runtime.material];
			xlStringCopy(material->name, *params);
		}
		case XL_OBJECT_TAG_NAME:
		{
			XLobject *bind = xlGetObject();
			XLObjectTag *tag = &bind->body.tags[bind->runtime.tag];
			xlStringCopy(tag->name, *params);
		}
		case XL_CAMERA_PROPERTY_NAME:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(property->name, *params);
			break;
		}
		case XL_OPERATOR_ACTION_NAME:
		{
			XLoperator *bind = xlGetOperator();
			XLOperatorAction *action = &bind->body.actions[bind->runtime.action];
			xlStringCopy(action->name, *params);
			break;
		}
		case XL_VIEWPORT_PROPERTY_NAME:
		{
			XLviewport *bind = xlGetViewport();
			XLViewportProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(property->name, *params);
			break;
		}
		case XL_WINDOW_PROPERTY_NAME:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(property->name, *params);
			break;
		}
		case XL_WINDOW_PROPERTY_TITLE:
		{
			XLwindow *bind = xlGetWindow();
			XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
			xlStringCopy(property->title, *params);
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

void
xlSetString(XLenum pname, XLstring param)
{
	xlSetStringv(pname, (XLstring *) &param[0]);
}

void
xlSetPathv(XLenum name, XLpath *params)
{
	switch(name)
	{
		case XL_ERROR_FILE:
		{
			XLerror *error = xlGetError();
			xlPathCopy(error->file, *params);
			break;
		}
		case XL_ERROR_FUNCTION:
		{
			XLerror *error = xlGetError();
			xlPathCopy(error->function, *params);
			break;
		}
		case XL_METAHEADER_PATH:
		{
			XLmetaheader *metaheader = xlGetMetaHeader();
			xlPathCopy(metaheader->path, *params);
			break;
		}
		case XL_IMAGE_METAHEADER_PATH:
		{
			XLimage *bind = xlGetImage();
			xlPathCopy(bind->header.metaheader.path, *params);
			break;
		}
		case XL_FONT_METAHEADER_PATH:
		{
			XLfont *bind = xlGetFont();
			xlPathCopy(bind->header.metaheader.path, *params);
			break;
		}
		case XL_FONT_PATH:
		{
			XLfont *bind = xlGetFont();
			xlPathCopy(bind->body.path, *params);
			break;
		}
		case XL_MATERIAL_METAHEADER_PATH:
		{
			XLmaterial *bind = xlGetMaterial();
			xlPathCopy(bind->header.metaheader.path, *params);
			break;
		}
		case XL_MATERIAL_PROPERTY_IMAGE:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			xlPathCopy(property->image, *params);
			break;
		}
		case XL_SURFACE_METAHEADER_PATH:
		{
			XLsurface *bind = xlGetSurface();
			xlPathCopy(bind->header.metaheader.path, *params);
			break;
		}
		case XL_SURFACE_MATERIAL:
		{
			XLsurface *bind = xlGetSurface();
			xlPathCopy(bind->body.material->path, *params);
			break;
		}
		case XL_OBJECT_METAHEADER_PATH:
		{
			XLobject *bind = xlGetObject();
			xlPathCopy(bind->header.metaheader.path, *params);
			break;
		}
		case XL_MODEL_METAHEADER_PATH:
		{
			XLmodel *bind = xlGetModel();
			xlPathCopy(bind->header.metaheader.path, *params);
			break;
		}
		case XL_MODEL_OBJECT:
		{
			XLmodel *bind = xlGetModel();
			xlPathCopy(bind->body.object->path, *params);
			break;
		}
		case XL_PARTICLES_METAHEADER_PATH:
		{
			XLparticles *particles = xlGetParticles();
			xlPathCopy(particles->header.metaheader.path, *params);
			break;
		}
		case XL_CAMERA_METAHEADER_PATH:
		{
			XLcamera *bind = xlGetCamera();
			xlPathCopy(bind->header.metaheader.path, *params);
			break;
		}
		case XL_OPERATOR_METAHEADER_PATH:
		{
			XLoperator *bind = xlGetOperator();
			xlPathCopy(bind->header.metaheader.path, *params);
			break;
		}
		case XL_OPERATOR_CAMERA:
		{
			XLoperator *bind = xlGetOperator();
			xlPathCopy(bind->body.camera->path, *params);
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

void
xlSetPath(XLenum pname, XLpath param)
{
	xlSetPathv(pname, (XLpath *) &param);
}

void
xlSetDoublev(XLenum pname, XLdouble *params)
{
}

void
xlSetFloatv(XLenum pname, XLfloat *params)
{
}

void
xlSetRealv(XLenum pname, XLreal *params)
{
	switch(pname)
	{
		case XL_TIME_TOTAL:
		{
			xlTimeTotal = *params;
			break;
		}
		case XL_TIME_DELTA:
		{
			xlTimeDelta = *params;
			break;
		}
		case XL_MATERIAL_PROPERTY_ALPHA:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			property->alpha = *params;
			break;
		}
		case XL_MATERIAL_PROPERTY_SHININESS:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			property->shininess = *params;
			break;
		}
		case XL_SURFACE_ACTION_FRAME_TIME:
		{
			XLsurface *bind = xlGetSurface();
			XLSurfaceAction *action = &bind->body.actions[bind->runtime.action];
			XLSurfaceFrame *frame = &bind->body.frames[action->frames.start + bind->runtime.frame];
			frame->time = *params;
			break;
		}
		case XL_PARTICLES_PARTICLE_ENERGY:
		{
			XLparticles *particles = xlGetParticles();
			particles->runtime.particles[particles->runtime.particle].energy = *params;
			break;
		}
		case XL_PARTICLES_ENERGY:
		{
			XLparticles *particles = xlGetParticles();
			particles->runtime.global.energy = *params;
			break;
		}
		case XL_CAMERA_PROPERTY_LEFT:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->details.orthogonal.left = *params;
			break;
		}
		case XL_CAMERA_PROPERTY_RIGHT:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->details.orthogonal.right = *params;
			break;
		}
		case XL_CAMERA_PROPERTY_BOTTOM:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->details.orthogonal.bottom = *params;
			break;
		}
		case XL_CAMERA_PROPERTY_TOP:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->details.orthogonal.top = *params;
			break;
		}
		case XL_CAMERA_PROPERTY_FIELD_OF_VIEW:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->details.perspective.fovy = *params;
			break;
		}
		case XL_CAMERA_PROPERTY_ASPECT:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->details.perspective.aspect = *params;
			break;
		}
		case XL_CAMERA_PROPERTY_ZNEAR:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->details.perspective.znear = *params;
			break;
		}
		case XL_CAMERA_PROPERTY_ZFAR:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->details.perspective.zfar = *params;
			break;
		}
		case XL_OPERATOR_ACTION_FRAME_TIME:
		{
			XLoperator *bind = xlGetOperator();
			XLOperatorAction *action = &bind->body.actions[bind->runtime.action];
			XLOperatorFrame *frame = &bind->body.frames[action->frames.start + bind->runtime.frame];
			frame->time = *params;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

void
xlSetReal(XLenum pname, XLreal param)
{
	xlSetRealv(pname, &param);
}

#define _xlPairSet(e, c) \
		case XL_PAIR_ ## e: \
			*xlPair ## c = **params; \
			break;

void
xlSetPairv(XLenum pname, XLpair **params)
{
	switch(pname)
	{
		xlPairsForEach(_xlPairSet)

		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

#undef _xlPairSet

void
xlSetPair(XLenum pname, XLpair *param)
{
	xlSetPairv(pname, &param);
}

#define _xlColorSet(e, c) \
		case XL_COLOR_ ## e: \
			*xlColor ## c = **params; \
			break;

void
xlSetColorv(XLenum pname, XLcolor **params)
{
	switch(pname)
	{
		xlColorsForEach(_xlColorSet)

		case XL_IMAGE_PIXELS:
		{
			XLimage *bind = xlGetImage();
			bind->body.pixels = *params;
			break;
		}
		case XL_MATERIAL_PROPERTY_AMBIENT:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			property->ambient = **params;
			break;
		}
		case XL_MATERIAL_PROPERTY_DIFFUSE:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			property->diffuse = **params;
			break;
		}
		case XL_MATERIAL_PROPERTY_SPECULAR:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			property->specular = **params;
			break;
		}
		case XL_MATERIAL_PROPERTY_EMISSION:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			property->emission = **params;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

#undef _xlColorSet

void
xlSetColor(XLenum pname, XLcolor *param)
{
	xlSetColorv(pname, &param);
}

#define _xlPointSet(e, c) \
		case XL_POINT_ ## e: \
			*xlPoint ## c = **params; \
			break;

void
xlSetPointv(XLenum pname, XLpoint **params)
{
	switch(pname)
	{
		xlPointsForEach(_xlPointSet)

		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

#undef _xlPointSet

void
xlSetPoint(XLenum pname, XLpoint *param)
{
	xlSetPointv(pname, &param);
}

#define _xlVectorSet(e, c) \
		case XL_VECTOR_ ## e: \
			*xlVector ## c = **params; \
			break;

void
xlSetVectorv(XLenum pname, XLvector **params)
{
	switch(pname)
	{
		xlVectorsForEach(_xlVectorSet)

		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

#undef _xlVectorSet

void
xlSetVector(XLenum pname, XLvector *param)
{
	xlSetVectorv(pname, &param);
}

#define _xlMatrixSet(e, c) \
		case XL_MATRIX_ ## e: \
			*xlMatrix ## c = **params; \
			break;

void
xlSetMatrixv(XLenum pname, XLmatrix **params)
{
	switch(pname)
	{
		xlMatricesForEach(_xlMatrixSet)

		case XL_MATERIAL_PROPERTY_MATRIX:
		{
			XLmaterial *bind = xlGetMaterial();
			XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];
			property->matrix = **params;
			break;
		}
		case XL_SURFACE_ACTION_FRAME_MATRIX:
		{
			XLsurface *bind = xlGetSurface();
			XLSurfaceAction *action = &bind->body.actions[bind->runtime.action];
			XLSurfaceFrame *frame = &bind->body.frames[action->frames.start + bind->runtime.frame];
			frame->matrix = **params;
			break;
		}
		case XL_OBJECT_TAG_MATRIX:
		{
			XLobject *bind = xlGetObject();
			XLObjectTag *tag = &bind->body.tags[bind->runtime.tag];
			tag->matrix = **params;
		}
		case XL_OBJECT_MATRIX:
		{
			XLobject *bind = xlGetObject();
			bind->runtime.matrix = **params;
			break;
		}
		case XL_PARTICLES_PARTICLE_MATRIX:
		{
			XLparticles *particles = xlGetParticles();
			particles->runtime.particles[particles->runtime.particle].matrix = **params;
			break;
		}
		case XL_PARTICLES_MATRIX:
		{
			XLparticles *particles = xlGetParticles();
			particles->runtime.global.matrix = **params;
			break;
		}
		case XL_CAMERA_PROPERTY_PROJECTION:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->projection = **params;
			break;
		}
		case XL_CAMERA_PROPERTY_MATRIX:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->matrix = **params;
			break;
		}
		case XL_CAMERA_PROPERTY_MODELVIEW:
		{
			XLcamera *bind = xlGetCamera();
			XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
			property->modelview = **params;
			break;
		}
		case XL_OPERATOR_ACTION_FRAME_MATRIX:
		{
			XLoperator *bind = xlGetOperator();
			XLOperatorAction *action = &bind->body.actions[bind->runtime.action];
			XLOperatorFrame *frame = &bind->body.frames[action->frames.start + bind->runtime.frame];
			frame->matrix = **params;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}

#undef _xlMatrixSet

void
xlSetMatrix(XLenum pname, XLmatrix *param)
{
	xlSetMatrixv(pname, &param);
}

void
xlSetPointerv(XLenum pname, void **params)
{
	switch(pname)
	{
		case XL_PARTICLES_PARTICLE:
		{
			XLparticles *particles = xlGetParticles();
			particles->runtime.particles[particles->runtime.particle] = * (XLparticle *) *params;
			break;
		}
		case XL_PARTICLES_PARTICLE_DATA:
		{
			XLparticles *particles = xlGetParticles();
			particles->runtime.particles[particles->runtime.particle].data = *params;
			break;
		}
		case XL_PARTICLES_DATA:
		{
			XLparticles *particles = xlGetParticles();
			particles->runtime.global.data = *params;
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_ENUM);
			break;
	}
}
void
xlSetPointer(XLenum pname, void *param)
{
	xlSetPointerv(pname, &param);
}
