#ifndef XL_WORLD_H
#define XL_WORLD_H

#include <XL/id.h>

typedef struct
{
	unsigned int model;
	unsigned int material;
	unsigned int mat;
	unsigned int face;
} XLWorldFace;

typedef struct
{
	struct
	{
		unsigned int models;
	} header;
	unsigned int models[ID_SMALL_STORE];
} XLWorld;

void
xlWorldCreate(void);

void
xlWorldDestroy(void);

void
xlWorldAdd(unsigned int model);

void
xlWorldClear(void);

void
xlWorldTick(float f);

void
xlWorldDraw(void);


void
xlWorldSortDraw(void);

#include <XL/unid.h>

#endif
