#include "XL/xlError.h"
#include "XL/xl.h"

const XLwchar *
xlErrorString(XLenum error)
{
	switch(error)
	{
		case XL_ERROR_VALUE_NONE: return L"None, all correct"; break;
		case XL_ERROR_VALUE_INVALID: return L"Invalid error"; break;
		case XL_ERROR_VALUE_INVALID_ENUM: return L"Invalid enumerant"; break;
		case XL_ERROR_VALUE_INVALID_VALUE: return L"Invalid value"; break;
		case XL_ERROR_VALUE_INVALID_OP: return L"Invalid operation"; break;
		case XL_ERROR_VALUE_INVALID_PARAM: return L"Invalid parameter"; break;
		case XL_ERROR_VALUE_INVALID_PATH: return L"Invalid path"; break;
		case XL_ERROR_VALUE_INVALID_DATA: return L"Invalid data"; break;
		default: return L"Unknown error"; break;
	}
}
