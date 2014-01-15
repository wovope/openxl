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

#define _xlGenIdentifiers(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xlGen ## Identifiers (XLsizei n, XLid *ids);
		
xlIdForEach(_xlGenIdentifiers)

#undef _xlGenIdentifiers

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
