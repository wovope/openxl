#include "XL/xlOperator.h"
#include "XL/xl.h"

XLuint
xlGetOpActionId(const XLstring name)
{
	XLoperator *bind = xlGetOperator();
	XLuint i;

	for(i = 0; !xlStringEqual(bind->body.actions[i].name, name); i++);

	return i;
}

const XLwchar *
xlGetOpActionName(XLuint action)
{
	XLoperator *bind = xlGetOperator();

	return bind->body.actions[action].name;
}

void
xlGetOpMatrix(XLmatrix *matrix)
{
	XLoperator *bind = xlGetOperator();
	XLcamera *camera = xlGetCamera();
	XLCameraProperty *property = &camera->body.properties[camera->runtime.property];
	XLOperatorAction *action  = &bind->body.actions[bind->runtime.action];
	XLOperatorFrame *frame  = &bind->body.frames[action->frames.start + bind->runtime.frame % action->frames.count];

	xlMatrixAssignMult(matrix, &property->matrix, &frame->matrix);
}

void
xlOpBegin(void)
{
	XLcamera *camera = xlGetCamera();
	XLCameraProperty *property = &camera->body.properties[camera->runtime.property];

	xlGetOpMatrix(&property->modelview);

	//glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(XL_MATRIX_ARRAY(&property->modelview));

	glDebug(__FILE__, __LINE__);
}

void
xlOpEnd(void)
{
	//XLoperator *bind = xlGetOperator();

	glPopMatrix();
	//glMatrixMode(GL_MODELVIEW);

	glDebug(__FILE__, __LINE__);
}

void
xlOpCamera(void)
{
	XLoperator *bind = xlGetOperator();

	xlBindCamera(bind->runtime.camera);
}

void
xlOpCameraProperty(void)
{
	XLoperator *bind = xlGetOperator();

	xlBindCamera(bind->runtime.camera);
	xlCamProperty();
}
