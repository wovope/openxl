#include "XL/xlObject.h"
#include "XL/xl.h"

XLuint
xlGetObjMaterialId(const XLstring name)
{
	XLobject *bind = xlGetObject();
	XLuint i;

	for(i = 0; !xlStringEqual(bind->body.materials[i].name, name); i++);
	return i;
}

const XLwchar *
xlGetObjMaterialName(XLuint material)
{
	XLobject *bind = xlGetObject();

	return bind->body.materials[material].name;
}

XLuint
xlGetObjMaterialSurface(XLuint material)
{
	XLobject *bind = xlGetObject();

	return bind->body.materials[material].surface;
}

XLuint
xlGetObjMaterial(XLuint material)
{
	XLobject *bind = xlGetObject();

	return bind->runtime.materials[material];
}

XLuint
xlGetObjTagId(const XLstring name)
{
	XLobject *bind = xlGetObject();
	XLuint i;

	for(i = 0; !xlStringEqual(bind->body.tags[i].name, name); i++);
	return i;
}

const XLwchar *
xlGetObjTagName(XLuint tag)
{
	XLobject *bind = xlGetObject();

	return bind->body.tags[tag].name;
}

const XLmatrix *
xlGetObjTagMatrix(XLuint tag)
{
	XLobject *bind = xlGetObject();

	return &bind->body.tags[tag].matrix;
}

const XLreal *
xlGetObjBoundSphere(void)
{
	XLobject *bind = xlGetObject();

	return bind->body.bound->sphere;
}

const XLreal *
xlGetObjBoundDimensions(void)
{
	XLobject *bind = xlGetObject();

	return bind->body.bound->dimensions;
}

void
xlGetObjMatrixBoundSphere(XLreal sphere[4])
{
	XLobject *bind = xlGetObject();
	XLvector v;

	xlVectorAssignArray(&v, bind->body.bound->sphere);
	xlVectorMultMatrix(&v, &bind->runtime.matrix);
	xlRealCopy(sphere, XL_VECTOR_ARRAY(&v), 3);
	sphere[3] = bind->body.bound->sphere[3];
}

const XLmatrix *
xlGetObjMatrix(void)
{
	XLobject *bind = xlGetObject();

	return &bind->runtime.matrix;
}

void
xlObjMatrix(const XLmatrix *matrix)
{
	XLobject *bind = xlGetObject();

	xlMatrixAssignCopy(&bind->runtime.matrix, matrix);
}

void
xlObjMaterial(void)
{
	XLobject *bind = xlGetObject();
	XLObjectMaterial *material = &bind->body.materials[bind->runtime.material];
	XLid mat = bind->runtime.materials[bind->runtime.material];

	if(material->surface)
	{
		xlBindSurface(mat);
		xlSurfMaterial();
	}
	else
		xlBindMaterial(mat);
}

void
xlObjVerticesCoords(XLpoint *coords)
{
	XLobject *bind = xlGetObject();

	XLObjectVertex *vertices = bind->body.vertices;
	XLObjectMaterial *material;
	XLObjectFace *faces = bind->body.faces;
	XLvertex *verts = bind->runtime.vertices;
	XLuint j, k;

	for(bind->runtime.material = 0; bind->runtime.material < bind->header.materials; bind->runtime.material++)
	{
		material = &bind->body.materials[bind->runtime.material];

		for(j = material->faces.start; j < material->faces.start + material->faces.count; j++)
		{
			for(k = 0; k < 3; k++)
			{
				xlPairAssignCopy(&verts[j * 3 + k].tex, &faces[j].texcoords[k]);
				xlVectorAssignCopy(&verts[j * 3 + k].normal, &vertices[faces[j].vertices[k]].normal);
				xlPointAssignCopy(&verts[j * 3 + k].coord, coords ? &coords[faces[j].vertices[k]] : &vertices[faces[j].vertices[k]].coord);
			}
		}
	}

	glVertexPointer(3, GL_FLOAT, sizeof(XLvertex), &verts[0].coord);
	glNormalPointer(GL_FLOAT, sizeof(XLvertex), &verts[0].normal);
	glTexCoordPointer(2, GL_FLOAT, sizeof(XLvertex), &verts[0].tex);
}

void
xlObjVertices(void)
{
	xlObjVerticesCoords(NULL);
}
