#include "XL/xlType.h"
#include "XL/xl.h"

void
xlMetHeadType(XLmetaheader *type)
{
	XLmetaheader *bind = xlGetMetaHeader();

	xlMemoryCopy(bind, type, sizeof(XLmetaheader));
	xlMetHeadLog();
}

void
xlMetDatType(XLmetadata *type)
{
	XLmetadata *bind = xlGetMetaData();

	xlMemoryCopy(bind, type, sizeof(XLmetadata));
	xlMetDatLog();
}

void
xlMetType(XLmetaheader *mhtype, XLmetadata *mdtype)
{
	XLmetaheader *mhbind = xlGetMetaHeader();
	XLmetadata *mdbind = xlGetMetaData();

	xlMemoryCopy(mhbind, mhtype, sizeof(XLmetaheader));
	xlMemoryCopy(mdbind, mdtype, sizeof(XLmetadata));
	xlMetLog();
}

#define _xlIdType(Id, identifier, Identifier, Identifiers, IDENTIFIER) \
	void \
	xl ## Id ## Type(XL ## identifier *type) \
	{ \
		XL ## identifier *bind = xlGet ## Identifier(); \
		\
		xlMemoryCopy(bind, type, sizeof(XL ## identifier)); \
		xl ## Id ## Log(); \
	}
		
xlIdForEach(_xlIdType)

#undef _xlIdType

void
xlPartsTypeParticle(XLuint particle, XLparticle *type)
{
	XLparticles *particles = xlGetParticles();

	particles->runtime.particles[particle] = *type;
}

