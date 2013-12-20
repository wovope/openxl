#include "XL/xlDebug.h"
#include "XL/xl.h"

#ifdef XL_DEBUG

void
glDebug(const XLpath file, XLint line)
{
	GLenum error;

	if((error = glGetError()) != GL_NO_ERROR)
		xlLog(L"GL debug:%s:%i:GL error:%i:%s\n", file, line, error, gluErrorString(error));
}

void
xlDebug(const XLpath file, XLint line)
{
	XLerror *error;

	error = xlGetError();
	if(error->value != XL_ERROR_VALUE_NONE)
		xlLog(L"XL debug:%s:%i:XL error:%s:%s:%i:%i:%ls\n", file, line, error->file, error->function, error->line, error->value, xlGetString(error->value));
}

#endif
