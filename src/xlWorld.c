#include "XL/xlWorld.h"
#include <stdlib.h>
#include <string.h>
#include "XL/xlVector.h"
#include "XL/xlMaterial.h"
#include "XL/xlModel.h"
#include <GL/gl.h>

#include "XL/id.h"

static XLWorld
store;

static XLWorldFace
faces[ID_EXTRA_LARGE_STORE];

void
xlWorldCreate(void)
{
	xlMemoryZero(&store, sizeof(XLWorld));
}

void
xlWorldDestroy(void)
{
	xlMemoryZero(&store, sizeof(XLWorld));
}

void
xlWorldAdd(unsigned int model)
{
	store.models[store.header.models++] = model;
}

void
xlWorldClear(void)
{
	xlMemoryZero(&store, sizeof(XLWorld));
}

void
xlWorldTick(float f)
{
	unsigned int i;

	for(i = 0; i < store.header.models; i++)
		xlModelTick(store.models[i], f);
}

void
xlWorldDraw(void)
{
	unsigned int i;

	for(i = 0; i < store.header.models; i++)
		xlModelDraw(store.models[i]);
}

static int
_xlWorldFaceCmp(const void *p1, const void *p2)
{
	float *mv, v1[3], v2[3], tmp1[3], tmp2[3],(*c1)[3], (*c2)[3];
	const XLWorldFace *wf1, *wf2;
	XLmodel *m1, *m2;
	unsigned int i;

	wf1 = p1;
	wf2 = p2;

	m1 = xlModelStore(wf1->model);
	m2 = xlModelStore(wf2->model);

	c1 = m1->anim[2];
	c2 = m2->anim[2];

	mv = xlGetMatrix(XL_CAMERA_PROPERTY_MODELVIEW);

	xlVectorAssignCopy(v1, c1 ? c1[m1->faces[wf1->face].vertices[0]] : m1->vertices[m1->faces[wf1->face].vertices[0]].coord);
	xlVectorAssignCopy(v2, c2 ? c2[m2->faces[wf2->face].vertices[0]] : m2->vertices[m2->faces[wf2->face].vertices[0]].coord);
	xlVectorMultMatrix(v1, m1->matrix);
	xlVectorMultMatrix(v1, mv);
	xlVectorMultMatrix(v2, m2->matrix);
	xlVectorMultMatrix(v2, mv);
	for(i = 1; i < 3; i++)
	{
		xlVectorAssignCopy(tmp1, c1 ? c1[m1->faces[wf1->face].vertices[i]] : m1->vertices[m1->faces[wf1->face].vertices[i]].coord);
		xlVectorMultMatrix(tmp1, m1->matrix);
		xlVectorMultMatrix(tmp1, mv);
		if(tmp1[2] > v1[2]) xlVectorAssignCopy(v1, tmp1);
		xlVectorAssignCopy(tmp2, c2 ? c2[m2->faces[wf2->face].vertices[i]] : m2->vertices[m2->faces[wf2->face].vertices[i]].coord);
		xlVectorMultMatrix(tmp2, m2->matrix);
		xlVectorMultMatrix(tmp2, mv);
		if(tmp2[2] > v2[2]) xlVectorAssignCopy(v2, tmp2);
	}
	return (int) (v1[2] - v2[2]);
}

void
xlWorldSortDraw(void)
{
	unsigned int f, i, j, k;
	int m;
	XLmodel *model;
	float (*coords)[3];

	f = 0;
	for(i = 0; i < store.header.models; i++)
	{
		model = xlModelStore(store.models[i]);
		for(j = 0; j < model->header.materials; j++)
		{
			for(k = model->materials[j].start; k < model->materials[j].start + model->materials[j].faces; k++)
			{
				faces[f].model = store.models[i];
				faces[f].material = model->mats[j];
				faces[f].face = k;
				f++;
			}	
		}
	}
	qsort(faces, f, sizeof(XLWorldFace), _xlWorldFaceCmp);
	m = -1;
	for(i = 0; i < f; i++)
	{
		model = xlModelStore(faces[i].model);
		coords = model->anim[2];

		if(m != faces[i].material)
		{
			if(m != -1) xlMaterialEnd(m);

			m = faces[i].material;

			xlMaterialBegin(m);
			xlMaterialBind(m);
		}

		glBegin(GL_TRIANGLES);
		for(k = 0; k < 3; k++)
		{
			glTexCoord2fv(model->faces[faces[i].face].texcoords[k]);
			glNormal3fv(model->vertices[model->faces[faces[i].face].vertices[k]].normal);
			glVertex3fv(coords ? coords[model->faces[faces[i].face].vertices[k]] : model->vertices[model->faces[faces[i].face].vertices[k]].coord);
		}
		glEnd();
	}
	if(m != -1) xlMaterialEnd(m);
}
