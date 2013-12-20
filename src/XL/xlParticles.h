#ifndef XL_PARTICLES_H
#define XL_PARTICLES_H

#include <XL/xlTypes.h>

void
xlPartsGen(void);

void
xlPartsDelete(void);

void
xlPartsAct(void (*actor)(void *user), void *user);

void
xlPartsDepthSort();

void
xlPartsBegin(void);

void
xlPartsEnd(void);

#endif
