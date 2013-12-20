#ifndef XL_PAIR_H
#define XL_PAIR_H

#include <XL/xlTypes.h>

XLpair *
xlPairAlloc(void);

#define _xlPair(e, p) \
	extern \
	XLpair \
	*xlPair ## p; \
	\
	XLpair * \
	xlPairAssign ## p(XLpair *a);

xlPairsForEach(_xlPair)

#undef _xlPair

XLpair *
xlPairAssignArray(XLpair *a, XLreal *array);

XLpair *
xlPairAssignReals(XLpair *a, XLreal x, XLreal y);

XLpair *
xlPairAssignRand(XLpair *a);

XLpair *
xlPairSwizzle(XLpair *a, XLint x, XLint y);

XLpair *
xlPairAssignSwizzle(XLpair *a, XLpair *b, XLint x, XLint y);

XLpair *
xlPairAssignSwizzleVector(XLpair *a, XLvector *b, XLint x, XLint y);

XLpair *
xlPairAssignSwizzleMatrix(XLpair *a, XLmatrix *b, XLint x, XLint y);

XLpair *
xlPairAssignMatrixForward(XLpair *a, XLmatrix *b);

XLpair *
xlPairAssignMatrixUp(XLpair *a, XLmatrix *b);

XLpair *
xlPairAssignMatrixRight(XLpair *a, XLmatrix *b);

XLpair *
xlPairAssignMatrixPosition(XLpair *a, XLmatrix *b);

XLpair *
xlPairAssignMatrixScalation(XLpair *a, XLmatrix *b);

XLpair *
xlPairClear(XLpair *a);

XLpair *
xlPairCopy(XLpair *a);

XLpair *
xlPairAssignCopy(XLpair *a, XLpair *b);

XLpair *
xlPairComp(XLpair *a);

XLpair *
xlPairAssignComp(XLpair *a, XLpair *b);

XLpair *
xlPairNeg(XLpair *a);

XLpair *
xlPairAssignNeg(XLpair *a, XLpair *b);

XLpair *
xlPairInc(XLpair *a);

XLpair *
xlPairAssignInc(XLpair *a, XLpair *b);

XLpair *
xlPairDec(XLpair *a);

XLpair *
xlPairAssignDec(XLpair *a, XLpair *b);

XLpair *
xlPairAbs(XLpair *a);

XLpair *
xlPairAssignAbs(XLpair *a, XLpair *b);

XLreal
xlPairSquareNorm(XLpair *a);

XLreal
xlPairNorm(XLpair *a);

XLpair *
xlPairNormal(XLpair *a);

XLpair *
xlPairAssignNormal(XLpair *a, XLpair *b);

XLboolean
xlPairBooleanEqual(XLpair *a, XLpair *b);

XLpair *
xlPairPairEqual(XLpair *a, XLpair *b);

XLpair *
xlPairPairAssignEqual(XLpair *a, XLpair *b, XLpair *c);

XLboolean
xlPairBooleanGreater(XLpair *a, XLpair *b);

XLpair *
xlPairPairGreater(XLpair *a, XLpair *b);

XLpair *
xlPairPairAssignGreater(XLpair *a, XLpair *b, XLpair *c);

XLboolean
xlPairBooleanLesser(XLpair *a, XLpair *b);

XLpair *
xlPairPairLesser(XLpair *a, XLpair *b);

XLpair *
xlPairPairAssignLesser(XLpair *a, XLpair *b, XLpair *c);

XLreal
xlPairAngle(XLpair *a, XLpair *b);

XLreal
xlPairDot(XLpair *a, XLpair *b);

XLpair *
xlPairAndReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignAndReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairAnd(XLpair *a, XLpair *b);

XLpair *
xlPairAssignAnd(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairOrReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignOrReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairOr(XLpair *a, XLpair *b);

XLpair *
xlPairAssignOr(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairXorReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignXorReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairXor(XLpair *a, XLpair *b);

XLpair *
xlPairAssignXor(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairLShiftReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignLShiftReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairLShift(XLpair *a, XLpair *b);

XLpair *
xlPairAssignLShift(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairRShiftReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignRShiftReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairRShift(XLpair *a, XLpair *b);

XLpair *
xlPairAssignRShift(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairAddReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignAddReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairAdd(XLpair *a, XLpair *b);

XLpair *
xlPairAssignAdd(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairSubReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignSubReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairSub(XLpair *a, XLpair *b);

XLpair *
xlPairAssignSub(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairMultReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignMultReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairMult(XLpair *a, XLpair *b);

XLpair *
xlPairMultMatrix(XLpair *a, XLmatrix *b);

XLpair *
xlPairAssignMult(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairAssignMultMatrix(XLpair *a, XLpair *b, XLmatrix *c);

XLpair *
xlPairDivReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignDivReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairDiv(XLpair *a, XLpair *b);

XLpair *
xlPairDivMatrix(XLpair *a, XLmatrix *b);

XLpair *
xlPairAssignDiv(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairAssignDivMatrix(XLpair *a, XLpair *b, XLmatrix *c);

XLpair *
xlPairModReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignModReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairMod(XLpair *a, XLpair *b);

XLpair *
xlPairModMatrix(XLpair *a, XLmatrix *b);

XLpair *
xlPairAssignMod(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairAssignModMatrix(XLpair *a, XLpair *b, XLmatrix *c);

XLpair *
xlPairInvDivReal(XLpair *a, XLreal r);

XLpair *
xlPairAssignInvDivReal(XLpair *a, XLpair *b, XLreal r);

XLpair *
xlPairInvDiv(XLpair *a, XLpair *b);

XLpair *
xlPairInvDivMatrix(XLpair *a, XLmatrix *b);

XLpair *
xlPairAssignInvDiv(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairAssignInvDivMatrix(XLpair *a, XLpair *b, XLmatrix *c);

XLpair *
xlPairCross(XLpair *a, XLpair *b);

XLpair *
xlPairAssignCross(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairMin(XLpair *a, XLpair *b);

XLpair *
xlPairAssignMin(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairMax(XLpair *a, XLpair *b);

XLpair *
xlPairAssignMax(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairClampReal(XLpair *a, XLreal b, XLreal c);

XLpair *
xlPairAssignClampReal(XLpair *a, XLpair *b, XLreal c, XLreal d);

XLpair *
xlPairClamp(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairAssignClamp(XLpair *a, XLpair *b, XLpair *c, XLpair *d);

XLpair *
xlPairAssignRandRangeReal(XLpair *a, XLreal b, XLreal c);

XLpair *
xlPairAssignRandRange(XLpair *a, XLpair *b, XLpair *c);

XLpair *
xlPairRotate(XLpair *a, XLpair *axis, XLreal angle);

XLpair *
xlPairAssignRotate(XLpair *a, XLpair *b, XLpair *axis, XLreal angle);

XLpair *
xlPairLerp(XLpair *a, XLpair *b, XLreal t);

XLpair *
xlPairAssignLerp(XLpair *a, XLpair *b, XLpair *c, XLreal t);

XLpair *
xlPairQuadBezier(XLpair *a, XLpair *b, XLpair *c, XLreal t);

XLpair *
xlPairAssignQuadBezier(XLpair *a, XLpair *b, XLpair *c, XLpair *d, XLreal t);

XLpair *
xlPairCubicBezier(XLpair *a, XLpair *b, XLpair *c, XLpair *d, XLreal t);

XLpair *
xlPairAssignCubicBezier(XLpair *a, XLpair *b, XLpair *c, XLpair *d, XLpair *e, XLreal t);

void
xlPairInit();

void
xlPairFini();

#endif
