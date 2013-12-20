#include "XL/xlSurface.h"
#include "XL/xl.h"

XLuint
xlGetSurfActionId(const XLstring name)
{
	XLsurface *bind = xlGetSurface();
	XLuint i;

	for(i = 0; !xlStringEqual(bind->body.actions[i].name, name); i++);

	return i;
}

const XLwchar *
xlGetSurfActionName(XLuint action)
{
	XLsurface *bind = xlGetSurface();

	return bind->body.actions[action].name;
}

void
xlGetSurfMatrix(XLmatrix *matrix)
{
	XLsurface *bind = xlGetSurface();
	XLmaterial *material = xlGetMaterial();
	XLMaterialProperty *property = &material->body.properties[material->runtime.property];
	XLSurfaceAction *action = &bind->body.actions[bind->runtime.action];
	XLSurfaceFrame *frame = &bind->body.frames[action->frames.start + bind->runtime.frame % action->frames.count];

	xlMatrixAssignMult(matrix, &property->matrix, &frame->matrix);
}

void
xlSurfBegin(void)
{
	XLmaterial *material;
	XLMaterialProperty *property;
	XLmatrix matrix;

	xlSurfMaterial();
	material = xlGetMaterial();
	property = &material->body.properties[material->runtime.property];

	xlGetSurfMatrix(&matrix);
	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glMultMatrixf(XL_MATRIX_ARRAY(&matrix));
	glMatrixMode(GL_MODELVIEW);

	glPushAttrib(GL_DEPTH_BUFFER_BIT);

	if(property->alpha == XL_REAL(1)) glDepthMask(GL_TRUE);
	else glDepthMask(GL_FALSE);

	glDebug(__FILE__, __LINE__);
}

void
xlSurfEnd(void)
{
	//XLsurface *bind = xlGetSurface();

	glPopAttrib();

	glMatrixMode(GL_TEXTURE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glDebug(__FILE__, __LINE__);
}

void
xlSurfMaterial(void)
{
	XLsurface *bind = xlGetSurface();

	xlBindMaterial(bind->runtime.material);
}

void
xlSurfMaterialProperty(void)
{
	XLsurface *bind = xlGetSurface();

	xlBindMaterial(bind->runtime.material);
	xlMatProperty();
}
