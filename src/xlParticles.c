#include "XL/xlParticles.h"
#include "XL/xl.h"

void
xlPartsGen(void)
{
	XLparticles *bind = xlGetParticles();

	bind->runtime.particles = xlAlloc(bind->body.count * sizeof(XLparticle));
}

void
xlPartsDelete(void)
{
	XLparticles *bind = xlGetParticles();

	xlFree(bind->runtime.particles);
}

void
xlPartsAct(void (*actor)(void *user), void *user)
{
	XLparticles *bind = xlGetParticles();

	for(bind->runtime.particle = 0; bind->runtime.particle < bind->body.count; bind->runtime.particle++)
		actor(user);
}

static
int
xlParticleDepthCmp(const void *a, const void *b)
{
	XLvector va, vb;
	XLmatrix *mv;
	
	mv = xlGetMatrix(XL_CAMERA_PROPERTY_MODELVIEW);

	xlVectorAssignMatrixPosition(&va, &((XLparticle *) a)->matrix);
	xlVectorMultMatrix(&va, mv);
	xlVectorAssignMatrixPosition(&vb, &((XLparticle *) b)->matrix);
	xlVectorMultMatrix(&vb, mv);

	return (int) (XL_VECTOR_Z(&va) - XL_VECTOR_Z(&vb));
}

void
xlPartsDepthSort(void)
{
	XLparticles *bind = xlGetParticles();

	qsort(bind->runtime.particles, bind->body.count, sizeof(XLparticle), xlParticleDepthCmp);
}
void
xlPartsBegin(void)
{
	glDepthMask(GL_FALSE);
}

void
xlPartsEnd(void)
{
	glDepthMask(GL_TRUE);
}
