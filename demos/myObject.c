#include "myObject.h"

void
myObject(XLenum mode, const XLpath xlpath, XLint t)
{
	XLobject object;
	XLmetaheader *metaheader;
	XLmetadata *metadata;

	xlMemoryZero(&object, sizeof(XLobject));

	metaheader = &object.header.metaheader;
	metadata = &object.header.metadata;

	xlMetaHeaderSet(metaheader, XL_OBJECT_METAHEADER_MAGIC, xlpath);
	if(mode == XL_DATA_META || mode == XL_DATA_METAHEADER)
	{
		xlMetHeadType(metaheader);
		if(mode == XL_DATA_METAHEADER)
			return;
	}

	switch(t)
	{
		case 0: xlStringCopy(metadata->name, L"Demo"); break;
		default: xlSetError(XL_ERROR_VALUE_INVALID_PARAM); break;
	}
	xlStringCopy(metadata->version, xlGetString(XL_VERSION));
	xlStringCopy(metadata->author, xlGetString(XL_AUTHOR));
	xlStringCopy(metadata->date, xlGetString(XL_DATE));
	xlStringCopy(metadata->copyright, xlGetString(XL_COPYRIGHT));
	xlStringCopy(metadata->license, xlGetString(XL_LICENSE));
	xlStringCopy(metadata->url, xlGetString(XL_URL));
	xlStringCopy(metadata->email, xlGetString(XL_EMAIL));
	xlStringCopy(metadata->tool, xlGetString(XL_TOOL));
	xlStringCopy(metadata->comment, L"Proceduralized");
	xlStringCopy(metadata->xl, xlGetString(XL_VERSION));
	if(mode == XL_DATA_META || mode == XL_DATA_METADATA)
	{
		xlMetDatType(metadata);
		if(mode == XL_DATA_METADATA)
			return;
	}

	if(mode == XL_DATA_META)
		return;

	switch(t)
	{
		case 0:
		{
			object.header.vertices = 8;
			object.header.materials = 1;
			object.header.faces = 12;
			object.header.tags = 0;

			object.body.vertices = xlAlloc(object.header.vertices * sizeof(XLObjectVertex));
			xlPointAssignReals(&object.body.vertices[0].coord, XL_REAL(-10), XL_REAL(-10),  XL_REAL(10));
			xlPointAssignReals(&object.body.vertices[1].coord,  XL_REAL(10), XL_REAL(-10),  XL_REAL(10));
			xlPointAssignReals(&object.body.vertices[2].coord,  XL_REAL(10),  XL_REAL(10),  XL_REAL(10));
			xlPointAssignReals(&object.body.vertices[3].coord, XL_REAL(-10),  XL_REAL(10),  XL_REAL(10));
			xlPointAssignReals(&object.body.vertices[4].coord, XL_REAL(-10), XL_REAL(-10), XL_REAL(-10));
			xlPointAssignReals(&object.body.vertices[5].coord,  XL_REAL(10), XL_REAL(-10), XL_REAL(-10));
			xlPointAssignReals(&object.body.vertices[6].coord,  XL_REAL(10),  XL_REAL(10), XL_REAL(-10));
			xlPointAssignReals(&object.body.vertices[7].coord, XL_REAL(-10),  XL_REAL(10), XL_REAL(-10));

			object.body.materials = xlAlloc(object.header.materials * sizeof(XLObjectMaterial));
			xlStringZero(object.body.materials[0].name);
			xlStringCopy(object.body.materials[0].name, L"Material");
			xlPathZero(object.body.materials[0].path);
			xlPathCopy(object.body.materials[0].path, "Test3.xlc");
			object.body.materials[0].surface = 0;
			xlRangeLoad(&object.body.materials[0].faces, 0, object.header.faces);

			object.body.faces = xlAlloc(object.header.faces * sizeof(XLObjectFace));
			xlVerticesLoad(object.body.faces[0].vertices, 0, 1, 2);
			xlVectorAssignReals(&object.body.faces[0].normal, XL_REAL(0), XL_REAL(0), XL_REAL(1));
			xlTexCoordsLoad(object.body.faces[0].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(1), XL_REAL(1));

			xlVerticesLoad(object.body.faces[1].vertices, 0, 2, 3);
			xlVectorAssignReals(&object.body.faces[1].normal, XL_REAL(0), XL_REAL(0), XL_REAL(1));
			xlTexCoordsLoad(object.body.faces[1].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(1), XL_REAL(0), XL_REAL(1));

			xlVerticesLoad(object.body.faces[2].vertices, 5, 4, 7);
			xlVectorAssignReals(&object.body.faces[2].normal, XL_REAL(0), XL_REAL(0), XL_REAL(-1));
			xlTexCoordsLoad(object.body.faces[2].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(1), XL_REAL(1));

			xlVerticesLoad(object.body.faces[3].vertices, 5, 7, 6);
			xlVectorAssignReals(&object.body.faces[3].normal, XL_REAL(0), XL_REAL(0), XL_REAL(-1));
			xlTexCoordsLoad(object.body.faces[3].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(1), XL_REAL(0), XL_REAL(1));

			xlVerticesLoad(object.body.faces[4].vertices, 1, 5, 6);
			xlVectorAssignReals(&object.body.faces[4].normal, XL_REAL(1), XL_REAL(0), XL_REAL(0));
			xlTexCoordsLoad(object.body.faces[4].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(1), XL_REAL(1));

			xlVerticesLoad(object.body.faces[5].vertices, 1, 6, 2);
			xlVectorAssignReals(&object.body.faces[5].normal, XL_REAL(1), XL_REAL(0), XL_REAL(0));
			xlTexCoordsLoad(object.body.faces[5].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(1), XL_REAL(0), XL_REAL(1));

			xlVerticesLoad(object.body.faces[6].vertices, 4, 0, 3);
			xlVectorAssignReals(&object.body.faces[6].normal, XL_REAL(-1), XL_REAL(0), XL_REAL(0));
			xlTexCoordsLoad(object.body.faces[6].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(1), XL_REAL(1));

			xlVerticesLoad(object.body.faces[7].vertices, 4, 3, 7);
			xlVectorAssignReals(&object.body.faces[7].normal, XL_REAL(-1), XL_REAL(0), XL_REAL(0));
			xlTexCoordsLoad(object.body.faces[7].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(1), XL_REAL(0), XL_REAL(1));

			xlVerticesLoad(object.body.faces[8].vertices, 7, 3, 2);
			xlVectorAssignReals(&object.body.faces[8].normal, XL_REAL(0), XL_REAL(1), XL_REAL(0));
			xlTexCoordsLoad(object.body.faces[8].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(1), XL_REAL(1));

			xlVerticesLoad(object.body.faces[9].vertices, 7, 2, 6);
			xlVectorAssignReals(&object.body.faces[9].normal, XL_REAL(0), XL_REAL(1), XL_REAL(0));
			xlTexCoordsLoad(object.body.faces[9].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(1), XL_REAL(0), XL_REAL(1));

			xlVerticesLoad(object.body.faces[10].vertices, 5, 1, 0);
			xlVectorAssignReals(&object.body.faces[10].normal, XL_REAL(0), XL_REAL(-1), XL_REAL(0));
			xlTexCoordsLoad(object.body.faces[10].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(1), XL_REAL(1));

			xlVerticesLoad(object.body.faces[11].vertices, 5, 0, 4);
			xlVectorAssignReals(&object.body.faces[11].normal, XL_REAL(0), XL_REAL(-1), XL_REAL(0));
			xlTexCoordsLoad(object.body.faces[11].texcoords, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(1), XL_REAL(0), XL_REAL(1));

			object.body.bound = xlAlloc(1 * sizeof(XLObjectBound));
			xlSphereLoad(object.body.bound->sphere, XL_REAL(0),  XL_REAL(0), XL_REAL(0), XL_REAL(10));

			xlMatrixAssignIdentity(&object.runtime.matrix);
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_PARAM);
			break;
	}

	xlObjType(&object);
}

XLuint
myObjCubeXL(XLenum mode, const XLpath xlpath)
{
	myObject(mode, xlpath, 0);

	return 0;
}
