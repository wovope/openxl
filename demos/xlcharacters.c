#include "xlDemo.h"
XLchar xlDemoOperatorPath[] = "data/operators/Pivot.xlc";

XLstring chars;
XLuint nchars;
XLid imgs[XL_STRING_SIZE], parts;
XLmatrix sum, up, m;
XLpoint p;
XLvector v;
XLint size[2] = { XL_REAL(128), XL_REAL(128) };
XLstring str;
XLboolean mode;

typedef struct
{
	XLuint character;
	XLuint color;
} XLParticleData;

void
myParticlesActorInit(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	particle->energy = XL_REAL(0);
	xlMatrixAssignIdentity(&particle->matrix);
	particle->type = xlIntegerRandRange(0, 3);
	particle->data = xlAlloc(sizeof(XLParticleData));
}

void
myParticlesActorFini(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	xlFree(particle->data);
}

void
myParticlesActorBall1(void *user)
{
	XLparticle *particle = xlGetPointer(XL_PARTICLES_PARTICLE);

	if(particle->energy <= XL_REAL(0))
	{
		XLreal xr, yr, zr;
		((XLParticleData *) particle->data)->character = xlIntegerRandRange(0, nchars);
		((XLParticleData *) particle->data)->color = xlIntegerRandRange(XL_COLOR_FIRST, XL_COLOR_LAST);
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
		((XLParticleData *) particle->data)->character = xlIntegerRandRange(0, nchars);
		((XLParticleData *) particle->data)->color = xlIntegerRandRange(XL_COLOR_FIRST, XL_COLOR_LAST);
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
			((XLParticleData *) particle->data)->character = xlIntegerRandRange(0, nchars);
			((XLParticleData *) particle->data)->color = xlIntegerRandRange(XL_COLOR_FIRST, XL_COLOR_LAST);
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
			xlBindImage(imgs[((XLParticleData *)particle->data)->character]);
			xlImgTexture();
			xlColor(xlGetColor(((XLParticleData *) particle->data)->color));
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
			xlBindImage(imgs[((XLParticleData *)particle->data)->character]);
			xlImgTexture();
			xlColor(xlGetColor(((XLParticleData *) particle->data)->color));
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
		case 0: myParticlesActorDrawBall(user); break;
		case 1: myParticlesActorDrawBall(user); break;
		case 2: myParticlesActorDrawSmoke(user); break;
		default: break;
	}
}

void
demoKeyboard(unsigned char key, int x, int y)
{
}

void
demoDisplay(void)
{
	xlPartsDepthSort();
	xlPartsBegin();
	xlPartsAct(myParticlesActorDraw, NULL);
	xlPartsEnd();
}

void
demoTimer(int value)
{
	xlPartsAct(myParticlesActor, NULL);
}

void
demoLoad(int *argc, char **argv)
{
	XLint i;

	mode = *argc > 2 && argv[1][0] == '1';
	if(*argc < 3) xlStringCopy(chars, L"0123456789"); //xlStringCopy(chars, L"abcdefghijklmnopqrstuvwxyz");
	else xlStringPrintFormatted(chars, XL_STRING_SIZE, L"%s", argv[2]);
	nchars = xlStringLength(chars);

	glDisable(GL_LIGHTING);

	xlMatrixAssignReals(&sum, XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1));
	xlMatrixAssignReals(&up, XL_REAL(1.01), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1.01), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1.01), XL_REAL(0), XL_REAL(0), XL_REAL(2.5), XL_REAL(0), XL_REAL(1));

	xlGenImages(nchars, imgs);
	for(i = 0; i < nchars; i++)
	{
		xlBindImage(imgs[i]);
		xlSetIntegerv(XL_IMAGE_SIZE, size);
		if(mode)
			xlStringPrintFormatted(str, XL_STRING_SIZE, L"%ls", chars);
		else
			xlStringPrintFormatted(str, XL_STRING_SIZE, L"%lc", chars[i]);
		xlImgString(XL_RENDER_TEXTURE, str);
		xlImgGenTexture();
	}

	xlGenParticles(1, &parts);
	xlBindParticles(parts);
	xlDataLoad("data/particles/Test.xlc");
	xlPartsGen();
	xlPartsAct(myParticlesActorInit, NULL);
}

void
demoUnload()
{
	XLint i;

	xlPartsAct(myParticlesActorFini, NULL);
	xlPartsDelete();
	xlPartsUnload();
	xlDeleteParticles(1, &parts);

	for(i = nchars - 1; i >= 0; i--)
	{
		xlBindImage(imgs[i]);
		xlImgDeleteTexture();
		xlImgUnload();
	}
	xlDeleteImages(nchars, imgs);
}
