#ifndef XL_WINDOW_H
#define XL_WINDOW_H

#include <XL/xlTypes.h>

void
xlWinCreate(void);

void
xlWinSwapBuffers(void);

void
xlWinPostRedisplay(void);

void
xlWinLoop(void);

void
xlWinLeave(void);

void
xlWinProperty(void);

#endif
