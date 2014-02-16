#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Pivot.xlc";

#define DEMO_PARTICLES XL_VECTORS_DIRECTION_COUNT
XLid parts;

void
myParticlesActorInit(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	particle->energy = XL_REAL(360);
}

void
myParticlesActorFini(void *user)
{
}

void
myParticlesActorVector(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	if(particle->energy > XL_REAL(0))
		particle->energy -= XL_REAL(2);
	else
	{
		particle->energy = XL_REAL(360);
		xlSetReal(XL_PARTICLES_ENERGY, XL_REAL(0));
	}
}
void
myParticlesActorDrawVector(void *user)
{
	XLuint id = xlGetInteger(XL_PARTICLES_PARTICLE);
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);
	XLvector *data;
	XLvector *vector;
	XLcolor *color;
	XLenum c;

	data = xlGetPointer(XL_PARTICLES_DATA);
	vector = xlGetVector(XL_VECTOR_DIRECTION_FIRST + id);
	c = XL_COLOR_FIRST + id;
	color = xlGetColor(c >= XL_COLOR_BLACK ? c + 1 : c);

	glPushMatrix();
	xlScale(xlVectorAssignMultReal(xlVectorTMP, xlVectorOne, XL_REAL(10)));
	xlRotate(particle->energy, data);
	xlColor(color);
	glBegin(GL_LINES);
	xlVertex(xlVectorZero);
	xlVertex(vector);
	glEnd();
	glPopMatrix();
}

void
demoKeyboard(unsigned char key, int x, int y)
{
}

void
demoDisplay(void)
{
	//xlPartsDepthSort();
	xlPartsBegin();
	xlPartsAct(myParticlesActorDrawVector, NULL);
	xlPartsEnd();
}

void
demoTimer(int value)
{
	if(xlGetReal(XL_PARTICLES_ENERGY) <= XL_REAL(0))
	{
		xlSetPointer(XL_PARTICLES_DATA, xlGetVector(xlIntegerRandRange(XL_VECTOR_DIRECTION_FIRST, XL_VECTOR_DIRECTION_LAST)));
		xlSetReal(XL_PARTICLES_ENERGY, XL_REAL(1));
	}
	xlPartsAct(myParticlesActorVector, NULL);
}

void
demoLoad(int *argc, char **argv)
{
	glDisable(GL_LIGHTING);

	xlGenParticles(1, &parts);
	xlBindParticles(parts);
	xlPartsLoad("data/particles/Vectors.xlc");
	xlPartsGen();
	xlSetReal(XL_PARTICLES_ENERGY, XL_REAL(1));
	xlSetPointer(XL_PARTICLES_DATA, xlGetVector(xlIntegerRandRange(XL_VECTOR_DIRECTION_FIRST, XL_VECTOR_DIRECTION_LAST)));
	xlPartsAct(myParticlesActorInit, NULL);
}

void
demoUnload()
{
	xlPartsAct(myParticlesActorFini, NULL);
	xlPartsDelete();
	xlPartsUnload();
	xlDeleteParticles(1, &parts);
}
