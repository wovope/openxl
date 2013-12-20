#ifndef XL_DELETE_H
#define XL_DELETE_H

#include <XL/xlTypes.h>

void
xlDeleteStores(XLsizei n, const XLid *stores);

void
xlDeleteBinds(XLsizei n, const XLid *binds);

void
xlDeleteIds(XLstore *store, XLsizei n, const XLid *ids);

void
xlDeleteMetaHeaders(XLsizei n, const XLid *ids);

void
xlDeleteMetaDatas(XLsizei n, const XLid *ids);

void
xlDeleteMetas(XLsizei n, const XLid *mhids, const XLid *mdids);

void
xlDeleteImages(XLsizei n, const XLid *ids);

void
xlDeleteFonts(XLsizei n, const XLid *ids);

void
xlDeleteMaterials(XLsizei n, const XLid *ids);

void
xlDeleteSurfaces(XLsizei n, const XLid *ids);

void
xlDeleteObjects(XLsizei n, const XLid *ids);

void
xlDeleteModels(XLsizei n, const XLid *ids);

void
xlDeleteParticles(XLsizei n, const XLid *ids);

void
xlDeleteCameras(XLsizei n, const XLid *ids);

void
xlDeleteOperators(XLsizei n, const XLid *ids);

void
xlDeleteViewports(XLsizei n, const XLid *ids);

void
xlDeleteWindows(XLsizei n, const XLid *ids);

void
xlMatDeleteImages(void);

void
xlMatDeleteTextures(void);

void
xlSurfDeleteMaterial(void);

void
xlObjDeleteMaterials(void);

void
xlObjDeleteImages(void);

void
xlObjDeleteTextures(void);

void
xlObjDeleteVertices(void);

void
xlModDeleteObject(void);

void
xlModDeleteAnim(void);

void
xlOpDeleteCamera(void);

#endif
