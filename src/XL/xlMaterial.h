#ifndef XL_MATERIAL_H
#define XL_MATERIAL_H

#include <XL/xlTypes.h>

XLuint
xlGetMatPropertyId(const XLstring name);

XLuint
xlGetMatPropertyImage(XLuint property);

XLchar *
xlGetMatPropertyImageName(XLuint property);

void
xlMatBegin(void);

void
xlMatEnd(void);

void
xlMatProperty(void);

/*
void
xlMatSync(void);
*/

#endif
