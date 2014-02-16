#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Pivot.xlc";

#define DEMO_PARTICLES XL_PAIRS_DIRECTION_COUNT
XLid parts;

void
myParticlesActorInit(void *user)
{
}

void
myParticlesActorFini(void *user)
{
}

void
myParticlesActorPair(void *user)
{
}

void
myParticlesActorDrawPair(void *user)
{
	XLuint particle;
	XLpair *pair;
	XLcolor *color;
	XLenum c;

	particle = xlGetInteger(XL_PARTICLES_PARTICLE);
	pair = xlGetPair(XL_PAIR_DIRECTION_FIRST + particle);
	c = XL_COLOR_FIRST + particle;
	color = xlGetColor(c >= XL_COLOR_BLACK ? c + 1 : c);

	glPushMatrix();
	xlScale(xlVectorAssignMultReal(xlVectorTMP, xlVectorOne, XL_REAL(10)));
	xlColor(color);
	glBegin(GL_POINTS);
	xlVertex2(pair);
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
	xlPartsAct(myParticlesActorDrawPair, NULL);
	xlPartsEnd();
}

void
demoTimer(int value)
{
	xlPartsAct(myParticlesActorPair, NULL);
}

void
demoLoad(int *argc, char **argv)
{
	glDisable(GL_LIGHTING);
	glPointSize(XL_REAL(5));

	xlGenParticles(1, &parts);
	xlBindParticles(parts);
	xlDataLoad("data/particles/Pairs.xlc");
	xlPartsGen();
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
