/*
 * 141 colors name are defined. The 17 standard colors are: aqua, black,
 * blue, fuchsia, gray, green, lime, maroon, navy, olive, orange, purple,
 * red, silver, teal, white, and yellow.
 *
 * http://www.w3schools.com/cssref/css_colornames.asp
 */

#ifndef XL_COLOR_H
#define XL_COLOR_H

#include <XL/xlTypes.h>

XLcolor *
xlColorAlloc(void);

#define _xlColor(e, c) \
	extern \
	XLcolor \
	*xlColor ## c; \
	\
	XLcolor * \
	xlColorAssign ## c(XLcolor *ca);

xlColorsForEach(_xlColor)

#undef _xlColor

XLcolor *
xlColorAssignArray(XLcolor *ca, XLreal *array);

XLcolor *
xlColorAssignReals(XLcolor *ca, XLreal r, XLreal g, XLreal b, XLreal a);

XLcolor *
xlColorAssignRand(XLcolor *a);

XLcolor *
xlColorSwizzle(XLcolor *ca, XLint r, XLint g, XLint b, XLint a);

XLcolor *
xlColorAssignSwizzle(XLcolor *ca, XLcolor *cb, XLint r, XLint g, XLint b, XLint a);

XLcolor *
xlColorAssignSwizzleVector(XLcolor *ca, XLvector *cb, XLint r, XLint g, XLint b, XLint a);

XLcolor *
xlColorAssignSwizzleMatrix(XLcolor *ca, XLmatrix *cb, XLint r, XLint g, XLint b, XLint a);

XLcolor *
xlColorAssignMatrixForward(XLcolor *ca, XLmatrix *cb);

XLcolor *
xlColorAssignMatrixUp(XLcolor *ca, XLmatrix *cb);

XLcolor *
xlColorAssignMatrixRight(XLcolor *ca, XLmatrix *cb);

XLcolor *
xlColorAssignMatrixPosition(XLcolor *ca, XLmatrix *cb);

XLcolor *
xlColorAssignMatrixScalation(XLcolor *ca, XLmatrix *cb);

XLcolor *
xlColorClear(XLcolor *ca);

XLcolor *
xlColorCopy(XLcolor *ca);

XLcolor *
xlColorAssignCopy(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorComp(XLcolor *ca);

XLcolor *
xlColorAssignComp(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorNeg(XLcolor *ca);

XLcolor *
xlColorAssignNeg(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorInc(XLcolor *ca);

XLcolor *
xlColorAssignInc(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorDec(XLcolor *ca);

XLcolor *
xlColorAssignDec(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAbs(XLcolor *ca);

XLcolor *
xlColorAssignAbs(XLcolor *ca, XLcolor *cb);

XLreal
xlColorSquareNorm(XLcolor *ca);

XLreal
xlColorNorm(XLcolor *ca);

XLcolor *
xlColorNormal(XLcolor *ca);

XLcolor *
xlColorAssignNormal(XLcolor *ca, XLcolor *cb);

XLboolean
xlColorBooleanEqual(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorColorEqual(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorColorAssignEqual(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLboolean
xlColorBooleanGreater(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorColorGreater(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorColorAssignGreater(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLboolean
xlColorBooleanLesser(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorColorLesser(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorColorAssignLesser(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLreal
xlColorAngle(XLcolor *ca, XLcolor *cb);

XLreal
xlColorDot(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAndReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignAndReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorAnd(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAssignAnd(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorOrReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignOrReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorOr(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAssignOr(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorXorReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignXorReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorXor(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAssignXor(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorLShiftReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignLShiftReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorLShift(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAssignLShift(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorRShiftReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignRShiftReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorRShift(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAssignRShift(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorAddReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignAddReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorAdd(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAssignAdd(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorSubReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignSubReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorSub(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAssignSub(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorMultReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignMultReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorMult(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorMultMatrix(XLcolor *ca, XLmatrix *cb);

XLcolor *
xlColorAssignMult(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorAssignMultMatrix(XLcolor *ca, XLcolor *cb, XLmatrix *cc);

XLcolor *
xlColorDivReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignDivReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorDiv(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorDivMatrix(XLcolor *ca, XLmatrix *cb);

XLcolor *
xlColorAssignDiv(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorAssignDivMatrix(XLcolor *ca, XLcolor *cb, XLmatrix *cc);

XLcolor *
xlColorModReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignModReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorMod(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorModMatrix(XLcolor *ca, XLmatrix *cb);

XLcolor *
xlColorAssignMod(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorAssignModMatrix(XLcolor *ca, XLcolor *cb, XLmatrix *cc);

XLcolor *
xlColorInvDivReal(XLcolor *ca, XLreal r);

XLcolor *
xlColorAssignInvDivReal(XLcolor *ca, XLcolor *cb, XLreal r);

XLcolor *
xlColorInvDiv(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorInvDivMatrix(XLcolor *ca, XLmatrix *cb);

XLcolor *
xlColorAssignInvDiv(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorAssignInvDivMatrix(XLcolor *ca, XLcolor *cb, XLmatrix *c);

XLcolor *
xlColorCross(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAssignCross(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorMin(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAssignMin(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorMax(XLcolor *ca, XLcolor *cb);

XLcolor *
xlColorAssignMax(XLcolor *ca, XLcolor *cb, XLcolor *cc);

XLcolor *
xlColorClampReal(XLcolor *a, XLreal b, XLreal c);

XLcolor *
xlColorAssignClampReal(XLcolor *a, XLcolor *b, XLreal c, XLreal d);

XLcolor *
xlColorClamp(XLcolor *a, XLcolor *b, XLcolor *c);

XLcolor *
xlColorAssignClamp(XLcolor *a, XLcolor *b, XLcolor *c, XLcolor *d);

XLcolor *
xlColorAssignRandRangeReal(XLcolor *a, XLreal b, XLreal c);

XLcolor *
xlColorAssignRandRange(XLcolor *a, XLcolor *b, XLcolor *c);

XLcolor *
xlColorRotate(XLcolor *ca, XLcolor *axis, XLreal angle);

XLcolor *
xlColorAssignRotate(XLcolor *ca, XLcolor *cb, XLcolor *axis, XLreal angle);

XLcolor *
xlColorLerp(XLcolor *ca, XLcolor *cb, XLreal t);

XLcolor *
xlColorAssignLerp(XLcolor *ca, XLcolor *cb, XLcolor *cc, XLreal t);

XLcolor *
xlColorQuadBezier(XLcolor *ca, XLcolor *cb, XLcolor *cc, XLreal t);

XLcolor *
xlColorAssignQuadBezier(XLcolor *ca, XLcolor *cb, XLcolor *cc, XLcolor *cd, XLreal t);

XLcolor *
xlColorCubicBezier(XLcolor *ca, XLcolor *cb, XLcolor *cc, XLcolor *cd, XLreal t);

XLcolor *
xlColorAssignCubicBezier(XLcolor *ca, XLcolor *cb, XLcolor *cc, XLcolor *cd, XLcolor *ce, XLreal t);

inline
void
xlColorMaterial(XLcolor *ca, GLenum face, GLenum pname);

void
xlColorInit();

void
xlColorFini();

#endif
