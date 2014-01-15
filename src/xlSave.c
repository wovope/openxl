#include "XL/xlSave.h"
#include "XL/xl.h"

void
xlImgSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");
	if(stream)
	{
		XLimage *bind = xlGetImage();

		xlFileWrite(&bind->header, 1, xlImgS(Header), stream);

		xlFileWrite(bind->body.pixels, sizeof(XLcolor), bind->header.width * bind->header.height, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlFntSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");

	if(stream)
	{
		XLfont *bind = xlGetFont();

		xlFileWrite(&bind->header, 1, xlFntS(Header), stream);

		xlFileWrite(bind->body.properties, xlFntS(Property), bind->header.properties, stream);
		xlFileWrite(bind->body.path, 1, sizeof(XLpath), stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlMatSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");
	if(stream)
	{
		XLmaterial *bind = xlGetMaterial();

		xlFileWrite(&bind->header, 1, xlMatS(Header), stream);

		xlFileWrite(bind->body.properties, xlMatS(Property), bind->header.properties, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlSurfSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");
	if(stream)
	{
		XLsurface *bind = xlGetSurface();

		xlFileWrite(&bind->header, 1, xlSurfS(Header), stream);

		xlFileWrite(bind->body.material, 1, xlSurfS(Material), stream);
		xlFileWrite(bind->body.frames, xlSurfS(Frame), bind->header.frames, stream);
		xlFileWrite(bind->body.actions, xlSurfS(Action), bind->header.actions, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlObjSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");
	if(stream)
	{
		XLobject *bind = xlGetObject();

		xlFileWrite(&bind->header, 1, xlObjS(Header), stream);

		xlFileWrite(bind->body.vertices, bind->header.vertices, xlObjS(Vertex), stream);
		xlFileWrite(bind->body.materials, bind->header.materials, xlObjS(Material), stream);
		xlFileWrite(bind->body.faces, bind->header.faces, xlObjS(Face), stream);
		xlFileWrite(bind->body.tags, bind->header.tags, xlObjS(Tag), stream);
		xlFileWrite(bind->body.bound, 1, xlObjS(Bound), stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlModSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");
	if(stream)
	{
		XLmodel *bind = xlGetModel();
		XLuint i;

		xlFileWrite(&bind->header, 1, xlModS(Header), stream);

		xlFileWrite(bind->body.object, 1, xlModS(Object), stream);
		xlFileWrite(bind->body.bones, bind->header.bones, xlModS(Bone), stream);
		xlFileWrite(bind->body.parents, bind->header.parents, xlModS(Parent), stream);
		xlFileWrite(bind->body.vertices, bind->header.vertices, xlModS(Vertex), stream);
		xlFileWrite(bind->body.tags, bind->header.tags, xlModS(Tag), stream);
		xlFileWrite(bind->body.weights, bind->header.weights, xlModS(Weight), stream);
		for(i = 0; i < bind->header.frames; i++)
		{
			xlFileWrite(bind->body.frames[i].bones, bind->header.bones, xlModS(BoneFrame), stream);
			xlFileWrite(&bind->body.frames[i].matrix, 16, sizeof(XLreal), stream);
			xlFileWrite(&bind->body.frames[i].time, 1, sizeof(XLreal), stream);
		}
		xlFileWrite(bind->body.actions, bind->header.actions, xlModS(Action), stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlPartsSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");

	if(stream)
	{
		XLparticles *bind = xlGetParticles();

		xlFileWrite(&bind->header, 1, xlPartsS(Header), stream);

		xlFileWrite(&bind->body, 1, xlPartsS(Body), stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlCamSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");

	if(stream)
	{
		XLcamera *bind = xlGetCamera();

		xlFileWrite(&bind->header, 1, xlCamS(Header), stream);

		xlFileWrite(bind->body.properties, xlCamS(Property), bind->header.properties, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlOpSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");
	if(stream)
	{
		XLoperator *bind = xlGetOperator();

		xlFileWrite(&bind->header, 1, xlOpS(Header), stream);

		xlFileWrite(bind->body.camera, 1, xlOpS(Camera), stream);
		xlFileWrite(bind->body.frames, xlOpS(Frame), bind->header.frames, stream);
		xlFileWrite(bind->body.actions, xlOpS(Action), bind->header.actions, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlVptSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");

	if(stream)
	{
		XLviewport *bind = xlGetViewport();

		xlFileWrite(&bind->header, 1, xlViewS(Header), stream);

		xlFileWrite(bind->body.properties, xlViewS(Property), bind->header.properties, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}

void
xlWinSave(const XLpath filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");

	if(stream)
	{
		XLwindow *bind = xlGetWindow();

		xlFileWrite(&bind->header, 1, xlWinS(Header), stream);

		xlFileWrite(bind->body.properties, xlWinS(Property), bind->header.properties, stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_VALUE_INVALID_PATH);
}
