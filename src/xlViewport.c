#include "XL/xlViewport.h"
#include "XL/xl.h"

void
xlVptProperty(void)
{
	XLviewport *bind = xlGetViewport();
	XLViewportProperty *property = &bind->body.properties[bind->runtime.property];

	glViewport(XL_PAIR_X(&property->position), XL_PAIR_Y(&property->position), XL_PAIR_X(&property->size), XL_PAIR_Y(&property->size)); 

	glDebug(__FILE__, __LINE__);
}
