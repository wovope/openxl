#ifndef XL_MODEL_H
#define XL_MODEL_H

#include <XL/xlTypes.h>

XLuint
xlGetModBoneId(const XLstring name);

const XLwchar *
xlGetModBoneName(XLuint bone);

XLuint
xlGetModBoneParents(XLuint bone);

void
xlGetModTagMatrix(XLuint tag, XLmatrix *matrix);

XLuint
xlGetModActionId(const XLstring name);

const XLwchar *
xlGetModActionName(XLuint action);

XLuint
xlGetModActionFrames(XLuint action);

const XLmatrix *
xlGetModActionFrameMatrix(XLuint action, XLuint frame);

XLreal
xlGetModActionFrameTime(XLuint action, XLuint frame);

XLuint
xlGetModAction(void);

XLuint
xlGetModActionFrame(void);

void
xlModAction(XLuint action);

void
xlModActionFrame(XLuint frame);

void
xlModActionMorph(XLboolean morph);

void
xlModActionBlend(XLboolean blend);

void
xlModObject(void);

void
xlModAnim(void);

void
xlModObjectVertices(void);

#endif
