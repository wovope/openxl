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

#define _xlBindIdentifier(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xlBind ## Identifier(XLid id);
		
xlIdForEach(_xlBindIdentifier)

#undef _xlBindIdentifier

#endif
