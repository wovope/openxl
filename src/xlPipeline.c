#include "XL/xl.h"

// FIXME: currently only flat normals, and object linear (?) texturing
// FLAT: face normals are cross product of triangle plane
// SMOOTH: average weight each face normal that shares that vertex

static GLenum xlObjPrimitive;
static XLuint xlObjPrimitiveVertex;
static XLuint xlObjPrimitiveVertices;
static XLuint xlObjPipelineVertices;
static XLuint xlObjPipelineFaces;
XLvector _xlVectorS, *xlVectorS;
XLvector _xlVectorT, *xlVectorT;
XLmatrix _xlMatrixModelView, *xlMatrixModelView;

void
xlObjPipelineBegin(void)
{
	xlVectorAssignCopy(xlVectorS, xlVectorX);
	xlVectorAssignCopy(xlVectorT, xlVectorY);
	xlMatrixAssignIdentity(xlMatrixModelView);
	xlObjPipelineVertices = xlObjPipelineFaces = 0;
}

void
xlObjPipelineEnd(void)
{
}

void
xlObjPipelineCountEnd(void)
{
	XLobject *bind = xlGetObject();

	bind->header.vertices = xlObjPipelineVertices;
	bind->header.faces = xlObjPipelineFaces;
}

void
xlObjPrimitiveBegin(GLenum prim)
{
	xlObjPrimitive = prim;
	xlObjPrimitiveVertices = 0;
}

void
xlObjPrimitiveEnd(void)
{
}

void
xlObjPrimitiveCountVertexPoint(XLpoint *coord)
{
	xlObjPrimitiveVertices++;
	xlObjPipelineVertices++;	

	if(xlObjPrimitive != GL_TRIANGLES && xlObjPrimitive != GL_TRIANGLE_STRIP && xlObjPrimitive != GL_TRIANGLE_FAN && xlObjPrimitive != GL_QUADS && xlObjPrimitive != GL_QUAD_STRIP)
		xlSetError(XL_ERROR_VALUE_INVALID_ENUM);

	if(xlObjPrimitive == GL_TRIANGLES && xlObjPrimitiveVertices % 3 == 0)
		xlObjPipelineFaces++;
	else if(xlObjPrimitive == GL_TRIANGLE_STRIP && xlObjPrimitiveVertices > 2)
		xlObjPipelineFaces++;
	else if(xlObjPrimitive == GL_TRIANGLE_FAN && xlObjPrimitiveVertices > 2)
		xlObjPipelineFaces++;
	else if(xlObjPrimitive == GL_QUADS && xlObjPrimitiveVertices % 4 == 0)
		xlObjPipelineFaces += 2;
	else if(xlObjPrimitive == GL_QUAD_STRIP && xlObjPrimitiveVertices % 2 == 0 && xlObjPrimitiveVertices > 3 )
		xlObjPipelineFaces += 2;
}

void
xlObjTessPrimitiveCountVertexdv(double *data)
{
	xlObjPrimitiveVertices++;
	xlObjPipelineVertices++;	

	if(xlObjPrimitive != GL_TRIANGLES && xlObjPrimitive != GL_TRIANGLE_STRIP && xlObjPrimitive != GL_TRIANGLE_FAN && xlObjPrimitive != GL_QUADS && xlObjPrimitive != GL_QUAD_STRIP)
		xlSetError(XL_ERROR_VALUE_INVALID_ENUM);

	if(xlObjPrimitive == GL_TRIANGLES && xlObjPrimitiveVertices % 3 == 0)
		xlObjPipelineFaces++;
	else if(xlObjPrimitive == GL_TRIANGLE_STRIP && xlObjPrimitiveVertices > 2)
		xlObjPipelineFaces++;
	else if(xlObjPrimitive == GL_TRIANGLE_FAN && xlObjPrimitiveVertices > 2)
		xlObjPipelineFaces++;
	else if(xlObjPrimitive == GL_QUADS && xlObjPrimitiveVertices % 4 == 0)
		xlObjPipelineFaces += 2;
	else if(xlObjPrimitive == GL_QUAD_STRIP && xlObjPrimitiveVertices % 2 == 0 && xlObjPrimitiveVertices > 3 )
		xlObjPipelineFaces += 2;
}

void
xlObjPipelineFace(XLuint c, XLuint b, XLuint a)
{
	XLobject *object = xlGetObject();
	XLvector u, v, normal;
	XLpoint *coord;

	xlVerticesLoad(object->body.faces[xlObjPipelineFaces].vertices, c, b, a);

	xlVectorAssignSubPoint(&u, &object->body.vertices[a].coord, &object->body.vertices[c].coord);
	xlVectorAssignSubPoint(&v, &object->body.vertices[b].coord, &object->body.vertices[c].coord);
	xlVectorNormal(xlVectorAssignCross(&normal, &u, &v));

	xlVectorAssignCopy(&object->body.vertices[c].normal, &normal);
	xlVectorAssignCopy(&object->body.vertices[b].normal, &normal);
	xlVectorAssignCopy(&object->body.vertices[a].normal, &normal);

	coord = &object->body.vertices[c].coord;
	XL_PAIR_X(&object->body.faces[xlObjPipelineFaces].texcoords[0]) = XL_VECTOR_X(xlVectorS) * XL_POINT_X(coord) + XL_VECTOR_Y(xlVectorS) * XL_POINT_Y(coord) + XL_VECTOR_Z(xlVectorS) * XL_POINT_Z(coord) + 0;
	XL_PAIR_Y(&object->body.faces[xlObjPipelineFaces].texcoords[0]) = XL_VECTOR_X(xlVectorT) * XL_POINT_X(coord) + XL_VECTOR_Y(xlVectorT) * XL_POINT_Y(coord) + XL_VECTOR_Z(xlVectorT) * XL_POINT_Z(coord) + 0;

	coord = &object->body.vertices[b].coord;
	XL_PAIR_X(&object->body.faces[xlObjPipelineFaces].texcoords[1]) = XL_VECTOR_X(xlVectorS) * XL_POINT_X(coord) + XL_VECTOR_Y(xlVectorS) * XL_POINT_Y(coord) + XL_VECTOR_Z(xlVectorS) * XL_POINT_Z(coord) + 0;
	XL_PAIR_Y(&object->body.faces[xlObjPipelineFaces].texcoords[1]) = XL_VECTOR_X(xlVectorT) * XL_POINT_X(coord) + XL_VECTOR_Y(xlVectorT) * XL_POINT_Y(coord) + XL_VECTOR_Z(xlVectorT) * XL_POINT_Z(coord) + 0;

	coord = &object->body.vertices[a].coord;
	XL_PAIR_X(&object->body.faces[xlObjPipelineFaces].texcoords[2]) = XL_VECTOR_X(xlVectorS) * XL_POINT_X(coord) + XL_VECTOR_Y(xlVectorS) * XL_POINT_Y(coord) + XL_VECTOR_Z(xlVectorS) * XL_POINT_Z(coord) + 0;
	XL_PAIR_Y(&object->body.faces[xlObjPipelineFaces].texcoords[2]) = XL_VECTOR_X(xlVectorT) * XL_POINT_X(coord) + XL_VECTOR_Y(xlVectorT) * XL_POINT_Y(coord) + XL_VECTOR_Z(xlVectorT) * XL_POINT_Z(coord) + 0;

	xlVectorAssignCopy(&object->body.faces[xlObjPipelineFaces].normal, &normal);

	xlObjPipelineFaces++;
}

void
xlObjPrimitiveVertexPoint(XLpoint *coord)
{
	XLobject *object = xlGetObject();
	XLuint c, b, a;

	xlPointAssignMultMatrix(&object->body.vertices[xlObjPipelineVertices].coord, coord, xlMatrixModelView);

	xlObjPrimitiveVertices++;
	xlObjPipelineVertices++;

	if(xlObjPrimitive != GL_TRIANGLES && xlObjPrimitive != GL_TRIANGLE_STRIP && xlObjPrimitive != GL_TRIANGLE_FAN && xlObjPrimitive != GL_QUADS && xlObjPrimitive != GL_QUAD_STRIP)
		xlSetError(XL_ERROR_VALUE_INVALID_ENUM);

	if(xlObjPrimitiveVertices == 1)
		xlObjPrimitiveVertex = xlObjPipelineVertices - 1;
	else if(xlObjPrimitive == GL_TRIANGLES && xlObjPrimitiveVertices % 3 == 0)
	{
		c = xlObjPipelineVertices - 3;
		b = xlObjPipelineVertices - 2;
		a = xlObjPipelineVertices - 1;
		xlObjPipelineFace(c, b, a);
	}
	else if(xlObjPrimitive == GL_TRIANGLE_STRIP && xlObjPrimitiveVertices > 2)
	{
		if((xlObjPrimitiveVertices % 2) != 0)
		{
			c = xlObjPipelineVertices - 3;
			b = xlObjPipelineVertices - 2;
			a = xlObjPipelineVertices - 1;
		}
		else
		{
			c = xlObjPipelineVertices - 3;
			b = xlObjPipelineVertices - 1;
			a = xlObjPipelineVertices - 2;
		}
		xlObjPipelineFace(c, b, a);
	}
	else if(xlObjPrimitive == GL_TRIANGLE_FAN && xlObjPrimitiveVertices > 2)
	{
		c = xlObjPrimitiveVertex;
		b = xlObjPipelineVertices - 2;
		a = xlObjPipelineVertices - 1;
		xlObjPipelineFace(c, b, a);
	}
	else if(xlObjPrimitive == GL_QUADS && xlObjPrimitiveVertices % 4 == 0)
	{
		c = xlObjPipelineVertices - 4;
		b = xlObjPipelineVertices - 3;
		a = xlObjPipelineVertices - 2;
		xlObjPipelineFace(c, b, a);
		c = xlObjPipelineVertices - 3;
		b = xlObjPipelineVertices - 1;
		a = xlObjPipelineVertices - 2;
		xlObjPipelineFace(c, b, a);
	}
	else if(xlObjPrimitive == GL_QUAD_STRIP && xlObjPrimitiveVertices % 2 == 0 && xlObjPrimitiveVertices > 3)
	{
		if((xlObjPrimitiveVertices % 4) == 0)
		{
			c = xlObjPipelineVertices - 4;
			b = xlObjPipelineVertices - 3;
			a = xlObjPipelineVertices - 2;
			xlObjPipelineFace(c, b, a);
			c = xlObjPipelineVertices - 3;
			b = xlObjPipelineVertices - 1;
			a = xlObjPipelineVertices - 2;
			xlObjPipelineFace(c, b, a);
		}
		else
		{
			c = xlObjPipelineVertices - 4;
			b = xlObjPipelineVertices - 2;
			a = xlObjPipelineVertices - 3;
			xlObjPipelineFace(c, b, a);
			c = xlObjPipelineVertices - 3;
			b = xlObjPipelineVertices - 2;
			a = xlObjPipelineVertices - 1;
			xlObjPipelineFace(c, b, a);
		}
	}
}

void
xlObjTessPrimitiveVertexdv(double *data)
{
	XLobject *object = xlGetObject();
	XLpoint coord;
	XLuint c, b, a;

	xlPointAssignReals(&coord, XL_REAL(data[0]), XL_REAL(data[1]), XL_REAL(data[2]));

	xlPointAssignMultMatrix(&object->body.vertices[xlObjPipelineVertices].coord, &coord, xlMatrixModelView);

	xlObjPrimitiveVertices++;
	xlObjPipelineVertices++;

	if(xlObjPrimitive != GL_TRIANGLES && xlObjPrimitive != GL_TRIANGLE_STRIP && xlObjPrimitive != GL_TRIANGLE_FAN && xlObjPrimitive != GL_QUADS && xlObjPrimitive != GL_QUAD_STRIP)
		xlSetError(XL_ERROR_VALUE_INVALID_ENUM);

	if(xlObjPrimitiveVertices == 1)
		xlObjPrimitiveVertex = xlObjPipelineVertices - 1;
	else if(xlObjPrimitive == GL_TRIANGLES && xlObjPrimitiveVertices % 3 == 0)
	{
		c = xlObjPipelineVertices - 3;
		b = xlObjPipelineVertices - 2;
		a = xlObjPipelineVertices - 1;
		xlObjPipelineFace(c, b, a);
	}
	else if(xlObjPrimitive == GL_TRIANGLE_STRIP && xlObjPrimitiveVertices > 2)
	{
		if((xlObjPrimitiveVertices % 2) != 0)
		{
			c = xlObjPipelineVertices - 3;
			b = xlObjPipelineVertices - 2;
			a = xlObjPipelineVertices - 1;
		}
		else
		{
			c = xlObjPipelineVertices - 3;
			b = xlObjPipelineVertices - 1;
			a = xlObjPipelineVertices - 2;
		}
		xlObjPipelineFace(c, b, a);
	}
	else if(xlObjPrimitive == GL_TRIANGLE_FAN && xlObjPrimitiveVertices > 2)
	{
		c = xlObjPrimitiveVertex;
		b = xlObjPipelineVertices - 2;
		a = xlObjPipelineVertices - 1;
		xlObjPipelineFace(c, b, a);
	}
	else if(xlObjPrimitive == GL_QUADS && xlObjPrimitiveVertices % 4 == 0)
	{
		c = xlObjPipelineVertices - 4;
		b = xlObjPipelineVertices - 3;
		a = xlObjPipelineVertices - 2;
		xlObjPipelineFace(c, b, a);
		c = xlObjPipelineVertices - 3;
		b = xlObjPipelineVertices - 1;
		a = xlObjPipelineVertices - 2;
		xlObjPipelineFace(c, b, a);
	}
	else if(xlObjPrimitive == GL_QUAD_STRIP && xlObjPrimitiveVertices % 2 == 0 && xlObjPrimitiveVertices > 3)
	{
		if((xlObjPrimitiveVertices % 4) == 0)
		{
			c = xlObjPipelineVertices - 4;
			b = xlObjPipelineVertices - 3;
			a = xlObjPipelineVertices - 2;
			xlObjPipelineFace(c, b, a);
			c = xlObjPipelineVertices - 3;
			b = xlObjPipelineVertices - 1;
			a = xlObjPipelineVertices - 2;
			xlObjPipelineFace(c, b, a);
		}
		else
		{
			c = xlObjPipelineVertices - 4;
			b = xlObjPipelineVertices - 2;
			a = xlObjPipelineVertices - 3;
			xlObjPipelineFace(c, b, a);
			c = xlObjPipelineVertices - 3;
			b = xlObjPipelineVertices - 2;
			a = xlObjPipelineVertices - 1;
			xlObjPipelineFace(c, b, a);
		}
	}
}

void
xlPipelineInit(void)
{
	xlMatrixModelView = &_xlMatrixModelView;
	xlVectorS = &_xlVectorS;
	xlVectorT = &_xlVectorT;
}

void
xlPipelineFini(void)
{
}
