#ifndef XL_DELETE_H
#define XL_DELETE_H

#include <XL/xlTypes.h>

void
xlDeleteStores(XLsizei n, const XLid *stores);

void
xlDeleteBinds(XLsizei n, const XLid *binds);

void
xlDeleteIdentifiers(XLstore *store, XLsizei n, const XLid *ids);

void
xlDeleteMetaHeaders(XLsizei n, const XLid *ids);

void
xlDeleteMetaDatas(XLsizei n, const XLid *ids);

void
xlDeleteMetas(XLsizei n, const XLid *mhids, const XLid *mdids);

#define _xlDeleteIdentifiers(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xlDelete ## Identifiers (XLsizei n, XLid *ids);
		
xlIdForEach(_xlDeleteIdentifiers)

#undef _xlDeleteIdentifiers

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
