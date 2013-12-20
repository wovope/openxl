#include "mySurface.h"

void
mySurface(XLenum mode, const XLpath xlpath, XLint t)
{
	XLsurface surface;
	XLmetaheader *metaheader;
	XLmetadata *metadata;

	xlMemoryZero(&surface, sizeof(XLsurface));

	metaheader = &surface.header.metaheader;
	metadata = &surface.header.metadata;

	xlMetaHeaderSet(metaheader, XL_SURFACE_METAHEADER_MAGIC, xlpath);
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
			XLuint i;

			surface.header.frames = 100;
			surface.header.actions = 1;

			surface.body.material = xlAlloc(1 * sizeof(XLSurfaceMaterial));
			xlPathZero(surface.body.material->path);
			xlPathCopy(surface.body.material->path, "Test.xlc");

			surface.body.frames = xlAlloc(surface.header.frames * sizeof(XLSurfaceFrame));
			XLmatrix matrix;
			XLpoint point;
			xlMatrixAssignIdentity(&matrix);
			XL_POINT_X(&point) = XL_REAL(0);
			XL_POINT_Z(&point) = XL_REAL(0);
			xlMatrixAssignIdentity(&surface.body.frames[0].matrix);
			surface.body.frames[0].time = XL_REAL(1);
			XL_POINT_Y(&point) = XL_REAL(5) / XL_REAL(surface.header.frames);
			for(i = 1; i < surface.header.frames / 2; i++)
			{
				xlMatrixAssignCopy(&surface.body.frames[i].matrix, &matrix);
				surface.body.frames[i].time = XL_REAL(1) / surface.header.frames;
				xlMatrixTranslate(&matrix, &point);
			}
			xlMatrixAssignIdentity(&surface.body.frames[i].matrix);
			surface.body.frames[i].time = XL_REAL(1);
			XL_POINT_Y(&point) = XL_REAL(-5) / surface.header.frames;
			for(i = surface.header.frames / 2 + 1; i < surface.header.frames; i++)
			{
				xlMatrixAssignCopy(&surface.body.frames[i].matrix, &matrix);
				surface.body.frames[i].time = XL_REAL(1) / XL_REAL(surface.header.frames);
				xlMatrixTranslate(&matrix, &point);
			}

			surface.body.actions = xlAlloc(surface.header.actions * sizeof(XLSurfaceAction));
			for(i = 0; i < surface.header.actions; i++)
			{
				switch(i)
				{
					case 0:
						xlStringCopy(surface.body.actions[i].name, L"y"); 
						xlRangeLoad(&surface.body.actions[i].frames, 0, surface.header.frames);
						break;
					default:
						break;
				}
			}
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_PARAM);
			break;
	}

	xlSurfType(&surface);
}

XLuint
mySurfTestXL(XLenum mode, const XLpath xlpath)
{
	mySurface(mode, xlpath, 0);

	return 0;
}
