#include "XL/xlData.h"
#include "XL/xl.h"

void
xlDataAdd(const XLpath path, XLuint (*data)(XLenum mode, const XLpath))
{
	XLuint i;

	for(i = 0; xlDatas[i].data; i++);

	xlDatas[i].path = xlPathDup(path);
	xlDatas[i].data = data;
}

void
xlDataRemove(const XLpath path)
{
	XLuint i;

	for(i = 0; xlDatas[i].path && !xlPathEqual(xlDatas[i].path, path); i++);

	xlFree(xlDatas[i].path);
	xlDatas[i].data = NULL;
}

void
xlDatasRemove(void)
{
	XLuint i;

	for(i = 0; xlDatas[i].path; i++)
	{
		xlFree(xlDatas[i].path);
		xlDatas[i].data = NULL;
	}
}

#define _xlIdData(id, identifier, Identifier, Identifiers, IDENTIFIER) \
	case XL_ ## IDENTIFIER ## _METAHEADER_MAGIC: \
		switch(type) \
		{ \
			case XL_DATA_SOURCE: xl ## id ## Compile(path); break; \
			case XL_DATA_BINARY: xl ## id ## Load(path); break; \
			case XL_DATA_EXTERNAL: xl ## id ## Import(path); break; \
			default: xlSetError(XL_ERROR_VALUE_INVALID_ENUM); break; \
		} \
		break;

XLuint
xlData(XLenum mode, const XLpath path)
{
	XLuint i;

	for(i = 0; xlDatas[i].path && !xlPathEqual(xlDatas[i].path, path); i++);
	if(xlDatas[i].data)
		return xlDatas[i].data(mode, path);
	else if(mode == XL_DATA_METAHEADER)
	{
		switch(xlGetPathType(path))
		{
			case XL_DATA_SOURCE: xlMetHeadCompile(path); break; 
			case XL_DATA_BINARY: xlMetHeadLoad(path); break;
			case XL_DATA_EXTERNAL: xlMetHeadImport(path); break;
			default: xlSetError(XL_ERROR_VALUE_INVALID_ENUM); break;
		}
	}
	else if(mode == XL_DATA_METADATA)
	{
		switch(xlGetPathType(path))
		{
			case XL_DATA_SOURCE: xlMetDatCompile(path); break; 
			case XL_DATA_BINARY: xlMetDatLoad(path); break;
			case XL_DATA_EXTERNAL: xlMetDatImport(path); break;
			default: xlSetError(XL_ERROR_VALUE_INVALID_ENUM); break;
		}
	}
	else if(mode == XL_DATA_META)
	{
		switch(xlGetPathType(path))
		{
			case XL_DATA_SOURCE: xlMetCompile(path); break; 
			case XL_DATA_BINARY: xlMetLoad(path); break;
			case XL_DATA_EXTERNAL: xlMetImport(path); break;
			default: xlSetError(XL_ERROR_VALUE_INVALID_ENUM); break;
		}
	}
	else if(mode == XL_DATA_LOAD)
	{
		XLenum type;
		XLid mh;

		xlGenMetaHeaders(1, &mh);
		xlBindMetaHeader(mh);

		type = xlGetPathType(path);

		switch(type)
		{
			case XL_DATA_SOURCE: xlMetHeadCompile(path); break; 
			case XL_DATA_BINARY: xlMetHeadLoad(path); break;
			case XL_DATA_EXTERNAL: xlMetHeadImport(path); break;
			default: xlSetError(XL_ERROR_VALUE_INVALID_ENUM); break;
		}

		switch(xlGetInteger(XL_METAHEADER_MAGIC))
		{
			xlIdForEach(_xlIdData)

			default:
				xlSetError(XL_ERROR_VALUE_INVALID_DATA);
				break;
		}

		xlMetHeadUnload();
		xlDeleteMetaHeaders(1, &mh);
	}

	return 0;
}

#undef _xlIdData

XLuint
xlDataMetaHeader(const XLpath path)
{
	return xlData(XL_DATA_METAHEADER, path);
}

XLuint
xlDataMetaData(const XLpath path)
{
	return xlData(XL_DATA_METADATA, path);
}

XLuint
xlDataMeta(const XLpath path)
{
	return xlData(XL_DATA_META, path);
}

XLuint
xlDataLoad(const XLpath path)
{
	return xlData(XL_DATA_LOAD, path);
}

#define _xlDataLoadIdentifier(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xlDataLoad ## Identifier(const XLpath path) \
	{ \
		XLenum type = xlGetPathType(path); \
	 	\
		switch(type) \
		{ \
			case XL_DATA_SOURCE: xl ## Id ## Compile(path); break; \
			case XL_DATA_BINARY: xl ## Id ## Load(path); break; \
			case XL_DATA_EXTERNAL: xl ## Id ## Import(path); break; \
			default: xlSetError(XL_ERROR_VALUE_INVALID_ENUM); break; \
		} \
	}

xlIdForEach(_xlDataLoadIdentifier)

#undef _xlDataLoadIdentifier

void
xlDataInit(void)
{
	xlMemoryZero(xlDatas, XL_STORE_SIZE * sizeof(XLdata));
}

void
xlDataFini(void)
{
	xlMemoryZero(xlDatas, XL_STORE_SIZE * sizeof(XLdata));
}
