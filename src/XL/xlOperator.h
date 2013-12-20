#ifndef XL_OPERATOR_H
#define XL_OPERATOR_H

#include <XL/xlTypes.h>

XLuint
xlGetOpActionId(const XLstring name);

const XLwchar *
xlGetOpActionName(XLuint action);

void
xlOpBegin(void);

void
xlOpEnd(void);

void
xlOpCamera(void);

void
xlOpCameraProperty(void);

#endif
