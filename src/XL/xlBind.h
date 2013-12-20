#ifndef XL_BIND_H
#define XL_BIND_H

#include <XL/xlTypes.h>

void
xlBindStore(XLid id);

void
xlBindBind(XLid id);

void
xlBindMetaHeader(XLid id);

void
xlBindMetaData(XLid id);

void
xlBindMeta(XLid mhid, XLid mdid);

void
xlBindImage(XLid id);

void
xlBindFont(XLid id);

void
xlBindMaterial(XLid id);

void
xlBindSurface(XLid id);

void
xlBindObject(XLid id);

void
xlBindModel(XLid id);

void
xlBindParticles(XLid id);

void
xlBindCamera(XLid id);

void
xlBindOperator(XLid id);

void
xlBindViewport(XLid id);

void
xlBindWindow(XLid id);

#endif
