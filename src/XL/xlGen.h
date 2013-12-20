#ifndef XL_GEN_H
#define XL_GEN_H

#include <XL/xlTypes.h>

void
xlGenStores(XLsizei n, XLid *stores);

void
xlGenBinds(XLsizei n, XLid *binds);

void
xlGenIds(XLstore *store, XLsizei size, XLsizei n, XLid *ids);

void
xlGenMetaHeaders(XLsizei n, XLid *ids);

void
xlGenMetaDatas(XLsizei n, XLid *ids);

void
xlGenMetas(XLsizei n, XLid *mhids, XLid *mdids);

void
xlGenImages(XLsizei n, XLid *ids);

void
xlGenFonts(XLsizei n, XLid *ids);

void
xlGenMaterials(XLsizei n, XLid *ids);

void
xlGenSurfaces(XLsizei n, XLid *ids);

void
xlGenObjects(XLsizei n, XLid *ids);

void
xlGenModels(XLsizei n, XLid *ids);

void
xlGenParticles(XLsizei n, XLid *ids);

void
xlGenCameras(XLsizei n, XLid *ids);

void
xlGenOperators(XLsizei n, XLid *ids);

void
xlGenViewports(XLsizei n, XLid *ids);

void
xlGenWindows(XLsizei n, XLid *ids);

void
xlMatGenImages(const XLpath path);

void
xlMatGenTextures(void);

void
xlSurfGenMaterial(const XLchar *path);

void
xlObjGenMaterials(const XLpath matpath, const XLpath animmatpath);

void
xlObjGenImages(const XLpath path);

void
xlObjGenTextures(void);

void
xlObjGenVertices(void);

void
xlModGenObject(const XLchar *path);

void
xlModGenAnim(void);

void
xlOpGenCamera(const XLpath path);

#endif
