#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Ortho.xlc";

#define DEMO_PARTICLES 300
XLid parts;

void
myParticlesActorInit(void *user)
{
	XLuint id = xlGetInteger(XL_PARTICLES_PARTICLE);
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);
	XLpoint t;

	particle->energy = XL_REAL(100);
	xlPointAssignReals(&t,
		XL_REAL(XL_REAL(id % 10) - XL_REAL(5)) * XL_REAL(1) / XL_REAL(5) + XL_REAL(1) / XL_REAL(10),
		XL_REAL(XL_REAL(id / 10) - XL_REAL(15)) * XL_REAL(1) / XL_REAL(15) + XL_REAL(1) / XL_REAL(30),
		XL_REAL(0));
	xlMatrixAssignTranslation(&particle->matrix, &t);
	particle->type = xlIntegerRandRange(XL_COLOR_FIRST, XL_COLOR_LAST);
}

void
myParticlesActorFini(void *user)
{
}

void
myParticlesActorColor(void *user)
{
	XLuint id = xlGetInteger(XL_PARTICLES_PARTICLE);
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	if(particle->energy <= XL_REAL(0))
	{
		XLpoint t;
		particle->type = xlIntegerRandRange(XL_COLOR_FIRST, XL_COLOR_LAST);
		xlPointAssignReals(&t,
			XL_REAL(XL_REAL(id % 10) - XL_REAL(5)) * XL_REAL(1) / XL_REAL(5) + XL_REAL(1) / XL_REAL(10),
			XL_REAL(XL_REAL(id / 10) - XL_REAL(15)) * XL_REAL(1) / XL_REAL(15) + XL_REAL(1) / XL_REAL(30),
			XL_REAL(0));
		xlMatrixAssignTranslation(&particle->matrix, &t);
		particle->energy = XL_REAL(100);
	}
	else 
	{
		XLmatrix m;
		xlMatrixAssignRotation(&m, xlVectorX, xlRealRandRange(0, 15));
		xlMatrixAssignMult(&particle->matrix, &m, &particle->matrix);
		particle->energy -= xlTimeDelta * xlRealRandRange(0, 50);
	}
}

void
myParticlesActorDrawColor(void *data)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	if(particle->energy > XL_REAL(0))
	{
		XLcolor *color;

		color = xlGetColor(particle->type);

		glPushMatrix();
		xlMultMatrix(&particle->matrix);
		xlColor(color);
		glScalef(XL_REAL(1) / XL_REAL(10), XL_REAL(1) / XL_REAL(30), XL_REAL(1));
		glBegin(GL_QUADS);
		xlVertex2(xlPointLeftUp);
		xlVertex2(xlPointLeftDown);
		xlVertex2(xlPointRightDown);
		xlVertex2(xlPointRightUp);
		glEnd();
		glPopMatrix();
	}
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
	xlPartsAct(myParticlesActorDrawColor, NULL);
	xlPartsEnd();
}

void
demoTimer(int value)
{
	xlPartsAct(myParticlesActorColor, NULL);
}

void
demoLoad(int *argc, char **argv)
{
	glDisable(GL_LIGHTING);

	xlGenParticles(1, &parts);
	xlBindParticles(parts);
	xlDataLoad("data/particles/Colors.xlc");
	xlPartsGen();
	xlPartsAct(myParticlesActorInit, NULL);
}

void
demoUnload()
{
	xlPartsAct(myParticlesActorFini, NULL);
	xlPartsDelete(),
	xlPartsUnload();
	xlDeleteParticles(1, &parts);
}
