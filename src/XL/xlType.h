#ifndef XL_TYPE_H
#define XL_TYPE_H

#include <XL/xlTypes.h>

void
xlMetHeadType(XLmetaheader *type);

void
xlMetDatType(XLmetadata *type);

void
xlMetType(XLmetaheader *mhtype, XLmetadata *mdtype);

#define _xlIdType(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xl ## Id ## Type(XL ## identifier *type);
		
xlIdForEach(_xlIdType)

#undef _xlIdType

void
xlPartsTypeParticle(XLuint particle, XLparticle *type);

#endif
