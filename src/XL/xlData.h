#ifndef XL_DATA_H
#define XL_DATA_H

#include <XL/xlTypes.h>

void
xlDataAdd(const XLpath path, XLuint (*data)(XLenum mode, const XLpath));

void
xlDataRemove(const XLpath path);

void
xlDatasRemove(void);

XLuint
xlData(XLenum mode, const XLpath path);

XLuint
xlDataMetaHeader(const XLpath path);

XLuint
xlDataMetaData(const XLpath path);

XLuint
xlDataMeta(const XLpath path);

XLuint
xlDataLoad(const XLpath path);

#define _xlDataLoadId(e, ts, tp, a) \
	void \
	xlDataLoad ## ts(const XLpath path);

xlIdForEach(_xlDataLoadId)

#undef _xlDataLoadId

void
xlDataInit(void);

void
xlDataFini(void);

#endif
