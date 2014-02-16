#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Pivot.xlc";

#define DEMO_PARTICLES XL_POINTS_DIRECTION_COUNT
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
myParticlesActorDrawPoint(void *user)
{
	XLuint id = xlGetInteger(XL_PARTICLES_PARTICLE);
	XLpoint *point;
	XLcolor *color;
	XLenum c;

	point = xlGetPoint(XL_POINT_DIRECTION_FIRST + id);
	c = XL_COLOR_FIRST + id;
	color = xlGetColor(c >= XL_COLOR_BLACK ? c + 1 : c);
	glPushMatrix();
	xlScale(xlVectorAssignMultReal(xlVectorTMP, xlVectorOne, XL_REAL(10)));
	xlColor(color);
	glBegin(GL_POINTS);
	xlVertex(point);
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
	xlPartsAct(myParticlesActorDrawPoint, NULL);
	xlPartsEnd();
}

void
demoTimer(int value)
{
}

void
demoLoad(int *argc, char **argv)
{
	glDisable(GL_LIGHTING);
	glPointSize(XL_REAL(5));

	xlGenParticles(1, &parts);
	xlBindParticles(parts);
	xlDataLoad("data/particles/Points.xlc");
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
