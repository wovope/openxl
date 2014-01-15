#include "XL/xlBind.h"
#include "XL/xl.h"

void
xlBindStore(XLid id)
{
	xlStores.bind = id;
}

void
xlBindBind(XLid id)
{
	XLstore *store = xlStores.data[xlBinds];

	store->bind = id;
}

void
xlBindMetaHeader(XLid id)
{
	XLstore *store = xlGetStore(XL_METAHEADER);

	store->bind = id;
}

void
xlBindMetaData(XLid id)
{
	XLstore *store = xlGetStore(XL_METADATA);

	store->bind = id;
}

void
xlBindMeta(XLid mhid, XLid mdid)
{
	xlBindMetaHeader(mhid);
	xlBindMetaData(mdid);
}

#define _xlBindIdentifier(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xlBind ## Identifier(XLid id) \
	{ \
		XLstore *store = xlGetStore(XL_ ## IDENTIFIER); \
		\
		store->bind = id; \
	}
		
xlIdForEach(_xlBindIdentifier)

#undef _xlBindIdentifier
