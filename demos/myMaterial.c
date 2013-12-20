#include "myMaterial.h"
#include <config.h>

void
myMaterial(XLenum mode, const XLpath xlpath, int t)
{
	XLmaterial material;
	XLmetaheader *metaheader;
	XLmetadata *metadata;

	xlMemoryZero(&material, sizeof(XLmaterial));

	metaheader = &material.header.metaheader;
	metadata = &material.header.metadata;

	xlMetaHeaderSet(metaheader, XL_MATERIAL_METAHEADER_MAGIC, xlpath);
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

			material.header.properties = 3;

			material.body.properties = xlAlloc(material.header.properties * sizeof(XLMaterialProperty));
			for(i = 0; i < material.header.properties; i++)
			{
				xlStringZero(material.body.properties[i].name);
				xlPathZero(material.body.properties[i].image);
				switch(i)
				{
					case 0: xlStringCopy(material.body.properties[i].name, L"textil"); strcpy(material.body.properties[i].image, "Textil.xlc"); break;
					case 1: xlStringCopy(material.body.properties[i].name, L"wood"); strcpy(material.body.properties[i].image, "Wood.xlc"); break;
					case 2: xlStringCopy(material.body.properties[i].name, L"grass"); strcpy(material.body.properties[i].image, "Grass.xlc"); break;
					default: break;
				}
				material.body.properties[i].alpha = XL_REAL(1);
				xlColorAssignReals(&material.body.properties[i].ambient, XL_REAL(0.2), XL_REAL(0.2), XL_REAL(0.2), XL_REAL(1.0));
				xlColorAssignReals(&material.body.properties[i].diffuse, XL_REAL(0.2), XL_REAL(0.2), XL_REAL(0.2), XL_REAL(1.0));
				xlColorAssignOne(&material.body.properties[i].specular);
				xlColorAssignZero(&material.body.properties[i].emission);
				material.body.properties[i].shininess = XL_REAL(0.5);
				xlMatrixAssignIdentity(&material.body.properties[i].matrix);
			}
			break;

		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_PARAM);
			break;
	}

	xlMatType(&material);
}

unsigned int
myMatTestXL(XLenum mode, const XLpath xlpath)
{
	myMaterial(mode, xlpath, 0);

	return 0;
}

