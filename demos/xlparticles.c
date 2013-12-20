#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Pivot.xlc";

#define DEMO_PARTICLES 300
XLid mat, parts;
XLmatrix sum, up, m;
XLpoint p;
XLvector v;
XLuint prop;

void
myParticlesActorInit(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	particle->energy = XL_REAL(0);
	xlMatrixAssignIdentity(&particle->matrix);
	particle->type = xlIntegerRandRange(0, 3);
}

void
myParticlesActorFini(void *user)
{
}

void
myParticlesActorBall1(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	if(particle->energy <= XL_REAL(0))
	{
		XLreal xr, yr, zr;
		xlMatrixAssignIdentity(&particle->matrix);
		xr = xlRealRandRange(XL_REAL(-180), XL_REAL(180));
		yr = xlRealRandRange(XL_REAL(-180), XL_REAL(180));
		zr = xlRealRandRange(XL_REAL(-180), XL_REAL(180));
		xlMatrixRotate(&particle->matrix, xlVectorX, xr);
		xlMatrixRotate(&particle->matrix, xlVectorY, yr);
		xlMatrixRotate(&particle->matrix, xlVectorZ, zr);
		particle->energy = XL_REAL(100);
	}
	else 
	{
		xlMatrixAssignCopy(&m, &sum);
		xlPointAssignMatrixPosition(&p, &m);
		xlPointMultReal(&p, xlTimeDelta * XL_REAL(2.5));
		xlMatrixPosition(&m, &p);
		xlMatrixAssignMult(&particle->matrix, &m, &particle->matrix);
		particle->energy -= XL_REAL(10) * xlTimeDelta;
	}
}

void
myParticlesActorBall2(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	if((particle->energy) <= XL_REAL(0))
	{
		XLreal xr, yr, zr;
		xlMatrixAssignIdentity(&particle->matrix);
		xr = xlRealRandRange(XL_REAL(-180), XL_REAL(180));
		yr = xlRealRandRange(XL_REAL(-180), XL_REAL(180));
		zr = xlRealRandRange(XL_REAL(-180), XL_REAL(180));
		xlMatrixRotate(&particle->matrix, xlVectorX, xr);
		xlMatrixRotate(&particle->matrix, xlVectorY, yr);
		xlMatrixRotate(&particle->matrix, xlVectorZ, zr);
		particle->energy = XL_REAL(100);
	}
	else 
	{
		xlMatrixAssignCopy(&m, &sum);
		xlPointAssignMatrixPosition(&p, &m);
		if((particle->energy) >= XL_REAL(50))
			xlPointMultReal(&p, xlTimeDelta * XL_REAL(5));
		else
			xlPointMultReal(&p, xlTimeDelta * XL_REAL(-5));
		xlMatrixPosition(&m, &p);
		xlMatrixAssignMult(&particle->matrix, &m, &particle->matrix);
		particle->energy -= xlTimeDelta * XL_REAL(10);
	}
}

void
myParticlesActorSmoke(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	if((particle->energy) <= XL_REAL(0))
	{
		if(xlRealRand() < XL_REAL(0.01))
		{
			xlMatrixAssignIdentity(&particle->matrix);
			xlPointAssignReals(&p, xlRealRandRange(XL_REAL(-1), XL_REAL(1)), XL_REAL(0), xlRealRandRange(XL_REAL(-1), XL_REAL(1)));
			xlMatrixTranslate(&particle->matrix, &p);
			particle->energy = XL_REAL(100);
		}
	}
	else 
	{
		xlMatrixAssignCopy(&m, &up);
		xlPointAssignMatrixPosition(&p, &m);
		xlPointMultReal(&p, xlTimeDelta * xlRealRandRange(1, XL_REAL(1.25)));
		XL_POINT_Z(&p) = XL_REAL(0);
		xlMatrixPosition(&m, &p);
		xlMatrixAssignMult(&particle->matrix, &m, &particle->matrix);
		particle->energy -= xlTimeDelta * xlRealRandRange(40, 50);
	}
}

void
myParticlesActor(void *user)
{
	switch(xlGetInteger(XL_PARTICLES_PARTICLE_TYPE))
	{
		case 0: myParticlesActorBall1(user); break;
		case 1: myParticlesActorBall2(user); break;
		case 2: myParticlesActorSmoke(user); break;
		default: break;
	}
}

void
myParticlesActorDrawBall(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);
	XLmatrix *mv = xlGetMatrix(XL_CAMERA_PROPERTY_MODELVIEW);

	if(particle->energy > XL_REAL(0))
	{
		XLreal sphere[4];

		xlPointAssignMatrixPosition(&p, &particle->matrix);
		xlMatrixAssignBillboard(&m, mv, &p);
		xlPointAssignMatrixPosition(&p, &m);

		xlRealCopy(sphere, XL_POINT_ARRAY(&p), 3);
		sphere[3] = XL_REAL(2.5);
		if(!xlCamFrustumCullSphere(sphere))
		{
			glPushMatrix();
			xlMultMatrix(&m);
			xlScale(xlVectorAssignMultReal(xlVectorTMP, xlVectorOne, XL_REAL(2.5)));
			glBegin(GL_QUADS);
			xlNormal(xlVectorZ);
			xlTexCoord(xlPairCenter); xlVertex(xlPointLeftUp);
			xlTexCoord(xlPairUp); xlVertex(xlPointLeftDown);
			xlTexCoord(xlPairRightUp); xlVertex(xlPointRightDown);
			xlTexCoord(xlPairRight); xlVertex(xlPointRightUp);
			glEnd();
			glPopMatrix();
		}
	}
}

void
myParticlesActorDrawSmoke(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);
	XLmatrix *mv = xlGetMatrix(XL_CAMERA_PROPERTY_MODELVIEW);

	if(particle->energy > XL_REAL(0))
	{
		XLreal sphere[4];

		xlPointAssignMatrixPosition(&p, &particle->matrix);
		xlMatrixAssignBillboard(&m, mv, &p);
		xlVectorAssignMatrixScalation(&v, &particle->matrix);
		xlMatrixScale(&m, &v);
		xlPointAssignMatrixPosition(&p, &m);

		xlRealCopy(sphere, XL_POINT_ARRAY(&p), 3);
		sphere[3] = XL_REAL(1);
		if(!xlCamFrustumCullSphere(sphere))
		{
			glPushMatrix();
			xlMultMatrix(&m);
			xlScale(xlVectorAssignMatrixScalation(xlVectorTMP, &particle->matrix));
			glBegin(GL_QUADS);
			xlNormal(xlVectorZ);
			xlTexCoord(xlPairCenter); xlVertex(xlPointLeftUp);
			xlTexCoord(xlPairUp); xlVertex(xlPointLeftDown);
			xlTexCoord(xlPairRightUp); xlVertex(xlPointRightDown);
			xlTexCoord(xlPairRight); xlVertex(xlPointRightUp);
			glEnd();
			glPopMatrix();
		}
	}
}

void
myParticlesActorDraw(void *user)
{
	switch(xlGetInteger(XL_PARTICLES_PARTICLE_TYPE))
	{
		case 0:
			xlSetInteger(XL_MATERIAL_PROPERTY, (prop + 0) % 3); xlMatProperty();
			myParticlesActorDrawBall(user);
			break;
		case 1:
			xlSetInteger(XL_MATERIAL_PROPERTY, (prop + 1) % 3); xlMatProperty();
			myParticlesActorDrawBall(user);
			break;
		case 2:
			xlSetInteger(XL_MATERIAL_PROPERTY, (prop + 2) % 3); xlMatProperty();
			myParticlesActorDrawSmoke(user);
			break;
		default:
			break;
	}
}

void
demoKeyboard(unsigned char key, int x, int y)
{
	// FIXME: This breaks on non expected materials, 3 properties.
	switch(key)
	{
		case 'z': prop = 0; break; 
		case 'x': prop = 1; break;
		case 'c': prop = 2; break;
		default: break;
	}
}

void
demoDisplay(void)
{
	xlMatBegin();
	xlPartsDepthSort();
	xlPartsBegin();
	xlPartsAct(myParticlesActorDraw, NULL);
	xlPartsEnd();
	xlMatEnd();
}

void
demoTimer(int value)
{
	xlPartsAct(myParticlesActor, NULL);
}

void
demoLoad(int *argc, char **argv)
{
	glDisable(GL_LIGHTING);

	xlMatrixAssignReals(&sum, XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1));
	xlMatrixAssignReals(&up, XL_REAL(1.01), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1.01), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1.01), XL_REAL(0), XL_REAL(0), XL_REAL(2.5), XL_REAL(0), XL_REAL(1));

	xlGenMaterials(1, &mat);
	xlBindMaterial(mat);
	if(*argc == 2) xlDataLoad(argv[1]);
	else xlDataLoad("data/materials/Particles.xlc");
	xlMatGenImages("data/images");
	xlMatGenTextures();
	xlMatProperty();

	xlGenParticles(1, &parts);
	xlBindParticles(parts);
	xlDataLoad("data/particles/Test.xlc");
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

	xlMatDeleteTextures();
	xlMatUnload();
	xlDeleteMaterials(1, &mat);
}
