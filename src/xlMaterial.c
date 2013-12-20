#include "XL/xlMaterial.h"
#include "XL/xl.h"

XLuint
xlGetMatPropertyId(const XLstring name)
{
	XLmaterial *bind = xlGetMaterial();
	XLuint i;

	for(i = 0; !xlStringEqual(bind->body.properties[i].name, name); i++);

	return i;
}

XLchar *
xlGetMatPropertyImageName(XLuint property)
{
	XLmaterial *bind = xlGetMaterial();

	return bind->body.properties[property].image;
}

XLuint
xlGetMatPropertyImage(XLuint property)
{
	XLmaterial *bind = xlGetMaterial();

	return bind->runtime.images[property];
}

void
xlMatBegin(void)
{
	XLmaterial *bind = xlGetMaterial();
	XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glMultMatrixf(XL_MATRIX_ARRAY(&property->matrix));
	glMatrixMode(GL_MODELVIEW);

	glPushAttrib(GL_DEPTH_BUFFER_BIT);

	if(property->alpha == XL_REAL(1)) glDepthMask(GL_TRUE);
	else glDepthMask(GL_FALSE);

	glDebug(__FILE__, __LINE__);
}

void
xlMatEnd(void)
{
	//XLmaterial *bind = xlGetMaterial();

	glDepthMask(GL_TRUE);
	glPopAttrib();

	glMatrixMode(GL_TEXTURE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glDebug(__FILE__, __LINE__);
}

void
xlMatProperty(void)
{
	XLmaterial *bind = xlGetMaterial();
	XLMaterialProperty *property = &bind->body.properties[bind->runtime.property];

	XL_COLOR_A(&property->ambient) = property->alpha;
	XL_COLOR_A(&property->diffuse) = property->alpha;
	XL_COLOR_A(&property->specular) = property->alpha;
	XL_COLOR_A(&property->emission) = property->alpha;

	xlBindImage(bind->runtime.images[bind->runtime.property]);
	xlImgTexture();
	xlMaterialc(GL_FRONT, GL_AMBIENT, &property->ambient);
	xlMaterialc(GL_FRONT, GL_DIFFUSE, &property->diffuse);
	xlMaterialc(GL_FRONT, GL_SPECULAR, &property->specular);
	xlMaterialc(GL_FRONT, GL_EMISSION, &property->emission);
	glMaterialf(GL_FRONT, GL_SHININESS, property->shininess);

	glDebug(__FILE__, __LINE__);
}
