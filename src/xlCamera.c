#include "XL/xlCamera.h"
#include "XL/xl.h"

void
xlCamPerspective(void)
{
	XLcamera *bind = xlGetCamera();
	XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
	XLreal aspect;

	if(property->details.perspective.aspect == XL_REAL(0))
	{
		aspect = XL_REAL(xlGetInteger(XL_VIEWPORT_PROPERTY_WIDTH)) / XL_REAL(xlGetInteger(XL_VIEWPORT_PROPERTY_HEIGHT));
	}
	else
		aspect = property->details.perspective.aspect;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(property->details.perspective.fovy, property->details.perspective.aspect, property->details.perspective.znear, property->details.perspective.zfar);
	//FIXME: do xlMatrixPerspective
	gluPerspective(property->details.perspective.fovy, aspect, property->details.perspective.znear, property->details.perspective.zfar);
	glGetFloatv(GL_PROJECTION_MATRIX, XL_MATRIX_ARRAY(&property->projection));
	glMatrixMode(GL_MODELVIEW);

	glDebug(__FILE__, __LINE__);
}

void
xlCamOrtho(void)
{
	XLcamera *bind = xlGetCamera();
	XLCameraProperty *property = &bind->body.properties[bind->runtime.property];
	XLreal left, right, bottom, top;

	if(property->details.orthogonal.left == XL_REAL(0) && property->details.orthogonal.right == XL_REAL(0) && property->details.orthogonal.bottom == XL_REAL(0) && property->details.orthogonal.top == XL_REAL(0))
	{
		left = xlGetInteger(XL_VIEWPORT_PROPERTY_X);
		top = xlGetInteger(XL_VIEWPORT_PROPERTY_Y);
		right = xlGetInteger(XL_VIEWPORT_PROPERTY_WIDTH);
		bottom = xlGetInteger(XL_VIEWPORT_PROPERTY_HEIGHT);
	}
	else
	{
		left = property->details.orthogonal.left;
		right = property->details.orthogonal.right;
		bottom = property->details.orthogonal.bottom;
		top = property->details.orthogonal.top;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(property->details.orthogonal.left, property->details.orthogonal.right, property->details.orthogonal.bottom, property->details.orthogonal.top);
	//FIXME: do xlMatrixOrho2D
	gluOrtho2D(left, right, bottom, top);
	glGetFloatv(GL_PROJECTION_MATRIX, XL_MATRIX_ARRAY(&property->projection));
	glMatrixMode(GL_MODELVIEW);

	glDebug(__FILE__, __LINE__);
}

void
xlCamBegin(void)
{
	XLcamera *bind = xlGetCamera();
	XLCameraProperty *property = &bind->body.properties[bind->runtime.property];

	xlMatrixAssignCopy(&property->modelview, &property->matrix);

	//glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(XL_MATRIX_ARRAY(&property->modelview));

	glDebug(__FILE__, __LINE__);
}

void
xlCamEnd(void)
{
	//XLcamera *bind = xlGetCamera();
	//XLCameraProperty *property = &bind->body.properties[bind->runtime.property];

	glPopMatrix();
	//glMatrixMode(GL_MODELVIEW);

	glDebug(__FILE__, __LINE__);
}

void
xlCamProperty(void)
{
	XLcamera *bind = xlGetCamera();
	XLCameraProperty *property = &bind->body.properties[bind->runtime.property];

	switch(property->type)
	{
		case XL_CAMERA_PROPERTY_ORTHOGONAL:
			xlCamOrtho();
			break;
		case XL_CAMERA_PROPERTY_PERSPECTIVE:
			xlCamPerspective();
			break;
		default:
			break;
	}
}

void
xlCamCalcFrustum(void)
{
	XLcamera *bind = xlGetCamera();
	XLCameraProperty *property = &bind->body.properties[bind->runtime.property];

	XLreal *frustum, *prj, *mv, clip[16], t;
	XLvector v;

	prj = XL_MATRIX_ARRAY(&property->projection);
	mv = XL_MATRIX_ARRAY(&property->modelview);

	clip[0] = mv[0] * prj[0] + mv[1] * prj[4] + mv[2] * prj[8] + mv[3] * prj[12];
	clip[1] = mv[0] * prj[1] + mv[1] * prj[5] + mv[2] * prj[9] + mv[3] * prj[13];
	clip[2] = mv[0] * prj[2] + mv[1] * prj[6] + mv[2] * prj[10] + mv[3] * prj[14];
	clip[3] = mv[0] * prj[3] + mv[1] * prj[7] + mv[2] * prj[11] + mv[3] * prj[15];
	clip[4] = mv[4] * prj[0] + mv[5] * prj[4] + mv[6] * prj[8] + mv[7] * prj[12];
	clip[5] = mv[4] * prj[1] + mv[5] * prj[5] + mv[6] * prj[9] + mv[7] * prj[13];
	clip[6] = mv[4] * prj[2] + mv[5] * prj[6] + mv[6] * prj[10] + mv[7] * prj[14];
	clip[7] = mv[4] * prj[3] + mv[5] * prj[7] + mv[6] * prj[11] + mv[7] * prj[15];
	clip[8] = mv[8] * prj[0] + mv[9] * prj[4] + mv[10] * prj[8] + mv[11] * prj[12];
	clip[9] = mv[8] * prj[1] + mv[9] * prj[5] + mv[10] * prj[9] + mv[11] * prj[13];
	clip[10] = mv[8] * prj[2] + mv[9] * prj[6] + mv[10] * prj[10] + mv[11] * prj[14];
	clip[11] = mv[8] * prj[3] + mv[9] * prj[7] + mv[10] * prj[11] + mv[11] * prj[15];
	clip[12] = mv[12] * prj[0] + mv[13] * prj[4] + mv[14] * prj[8] + mv[15] * prj[12];
	clip[13] = mv[12] * prj[1] + mv[13] * prj[5] + mv[14] * prj[9] + mv[15] * prj[13];
	clip[14] = mv[12] * prj[2] + mv[13] * prj[6] + mv[14] * prj[10] + mv[15] * prj[14];
	clip[15] = mv[12] * prj[3] + mv[13] * prj[7] + mv[14] * prj[11] + mv[15] * prj[15];

	frustum = bind->runtime.frustum;

	frustum[0] = clip[3] - clip[0];
	frustum[1] = clip[7] - clip[4];
	frustum[2] = clip[11] - clip[8];
	frustum[3] = clip[15] - clip[12];
	xlVectorAssignArray(&v, &frustum[0]);
	t = xlVectorNorm(&v);
	frustum[0] /= t;
	frustum[1] /= t;
	frustum[2] /= t;
	frustum[3] /= t;

	frustum[4] = clip[3] + clip[0];
	frustum[5] = clip[7] + clip[4];
	frustum[6] = clip[11] + clip[8];
	frustum[7] = clip[15] + clip[12];
	xlVectorAssignArray(&v, &frustum[4]);
	t = xlVectorNorm(&v);
	frustum[4] /= t;
	frustum[5] /= t;
	frustum[6] /= t;
	frustum[7] /= t;

	frustum[8] = clip[3] + clip[1];
	frustum[9] = clip[7] + clip[5];
	frustum[10] = clip[11] + clip[9];
	frustum[11] = clip[15] + clip[13];
	xlVectorAssignArray(&v, &frustum[8]);
	t = xlVectorNorm(&v);
	frustum[8] /= t;
	frustum[9] /= t;
	frustum[10] /= t;
	frustum[11] /= t;

	frustum[12] = clip[3] - clip[1];
	frustum[13] = clip[7] - clip[5];
	frustum[14] = clip[11] - clip[9];
	frustum[15] = clip[15] - clip[13];
	xlVectorAssignArray(&v, &frustum[12]);
	t = xlVectorNorm(&v);
	frustum[12] /= t;
	frustum[13] /= t;
	frustum[14] /= t;
	frustum[15] /= t;

	frustum[16] = clip[3] - clip[2];
	frustum[17] = clip[7] - clip[6];
	frustum[18] = clip[11] - clip[10];
	frustum[19] = clip[15] - clip[14];
	xlVectorAssignArray(&v, &frustum[16]);
	t = xlVectorNorm(&v);
	frustum[16] /= t;
	frustum[17] /= t;
	frustum[18] /= t;
	frustum[19] /= t;

	frustum[20] = clip[3] + clip[2];
	frustum[21] = clip[7] + clip[6];
	frustum[22] = clip[11] + clip[10];
	frustum[23] = clip[15] + clip[14];
	xlVectorAssignArray(&v, &frustum[20]);
	t = xlVectorNorm(&v);
	frustum[20] /= t;
	frustum[21] /= t;
	frustum[22] /= t;
	frustum[23] /= t;
}

XLuint
xlCamFrustumCullPoint(const XLreal *point)
{
	XLcamera *bind = xlGetCamera();
	XLreal *frustum;
	XLuint f;

	frustum = bind->runtime.frustum;

	for(f = 0; f < 6; f++)
		if(frustum[f * 4 + 0] * point[0] + frustum[f * 4 + 1] * point[1] + frustum[f * 4 + 2] * point[2] + frustum[f * 4 + 3] <= XL_REAL(0))
			return 0;
	return 1;
}

XLuint
xlCamFrustumCullSphere(const XLreal *sphere)
{
	XLcamera *bind = xlGetCamera();
	XLreal *frustum;
	XLuint p;

	frustum = bind->runtime.frustum;

	for(p = 0; p < 6; p++)
		if(frustum[p * 4 + 0] * sphere[0] + frustum[p * 4 + 1] * sphere[1] + frustum[p * 4 + 2] * sphere[2] + frustum[p * 4 + 3] < -sphere[3])
			return 1;
	return 0;
}

XLuint
xlCamFrustumCullTriangle(const XLreal *triangle)
{
	XLcamera *bind = xlGetCamera();
	XLreal *frustum;
	XLuint f, p;

	frustum = bind->runtime.frustum;

	for(f = 0; f < 6; f++)
	{
		for(p = 0; p < 3; p++)
			if(frustum[f * 4 + 0] * triangle[p * 3 + 0] + frustum[f * 4 + 1] * triangle[p * 3 + 1] + frustum[f * 4 + 2] * triangle[p * 3 + 2] + frustum[f * 4 + 3] > XL_REAL(0))
				break;
		if(p == 3)
			return 0;
	}
	return 1;
}

XLuint
xlCamFrustumCullCube(const XLreal *cube)
{
	XLcamera *bind = xlGetCamera();
	XLreal *frustum;
	XLuint p;

	frustum = bind->runtime.frustum;

	for(p = 0; p < 6; p++)
	{
		if(frustum[p * 4 + 0] * (cube[0] - cube[3]) + frustum[p * 4 + 1] * (cube[1] - cube[3]) + frustum[p * 4 + 2] * (cube[2] - cube[3]) + frustum[p * 4 + 3] > XL_REAL(0))
			continue;
		if(frustum[p * 4 + 0] * (cube[0] + cube[3]) + frustum[p * 4 + 1] * (cube[1] - cube[3]) + frustum[p * 4 + 2] * (cube[2] - cube[3]) + frustum[p * 4 + 3] > XL_REAL(0))
			continue;
		if(frustum[p * 4 + 0] * (cube[0] - cube[3]) + frustum[p * 4 + 1] * (cube[1] + cube[3]) + frustum[p * 4 + 2] * (cube[2] - cube[3]) + frustum[p * 4 + 3] > XL_REAL(0))
			continue;
		if(frustum[p * 4 + 0] * (cube[0] + cube[3]) + frustum[p * 4 + 1] * (cube[1] + cube[3]) + frustum[p * 4 + 2] * (cube[2] - cube[3]) + frustum[p * 4 + 3] > XL_REAL(0))
			continue;
		if(frustum[p * 4 + 0] * (cube[0] - cube[3]) + frustum[p * 4 + 1] * (cube[1] - cube[3]) + frustum[p * 4 + 2] * (cube[2] + cube[3]) + frustum[p * 4 + 3] > XL_REAL(0))
			continue;
		if(frustum[p * 4 + 0] * (cube[0] + cube[3]) + frustum[p * 4 + 1] * (cube[1] - cube[3]) + frustum[p * 4 + 2] * (cube[2] + cube[3]) + frustum[p * 4 + 3] > XL_REAL(0))
			continue;
		if(frustum[p * 4 + 0] * (cube[0] - cube[3]) + frustum[p * 4 + 1] * (cube[1] + cube[3]) + frustum[p * 4 + 2] * (cube[2] + cube[3]) + frustum[p * 4 + 3] > XL_REAL(0))
			continue;
		if(frustum[p * 4 + 0] * (cube[0] + cube[3]) + frustum[p * 4 + 1] * (cube[1] + cube[3]) + frustum[p * 4 + 2] * (cube[2] + cube[3]) + frustum[p * 4 + 3] > XL_REAL(0))
			continue;
		return 0;
	}
	return 1;
}

XLuint
xlCamFrustumCullPolygon(const XLreal *points, XLuint npoints)
{
	XLcamera *bind = xlGetCamera();
	XLreal *frustum;
	XLuint f, p;

	frustum = bind->runtime.frustum;

	for(f = 0; f < 6; f++)
	{
		for(p = 0; p < npoints; p++)
			if(frustum[f * 4 + 0] * points[p * 3] + frustum[f * 4 + 1] * points[p * 3 + 1] + frustum[f * 4 + 2] * points[p * 3 + 2] + frustum[f * 4 + 3] > XL_REAL(0))
				break;
		if(p == npoints)
			return 0;
	}
	return 1;
}
