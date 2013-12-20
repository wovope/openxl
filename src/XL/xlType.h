#ifndef XL_TYPE_H
#define XL_TYPE_H

#include <XL/xlTypes.h>

void
xlMetHeadType(XLmetaheader *type);

void
xlMetDatType(XLmetadata *type);

void
xlMetType(XLmetaheader *mhtype, XLmetadata *mdtype);

void
xlImgType(XLimage *type);

void
xlMatType(XLmaterial *type);

void
xlSurfType(XLsurface *type);

void
xlObjType(XLobject *type);

void
xlModType(XLmodel *type);

void
xlPartsType(XLparticles *type);

void
xlPartsTypeParticle(XLuint particle, XLparticle *type);

void
xlCamType(XLcamera *type);

void
xlOpType(XLoperator *type);

void
xlViewType(XLviewport *type);

void
xlWinType(XLwindow *type);

#endif
