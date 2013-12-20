#ifndef XL_POINT_H
#define XL_POINT_H

#include <XL/xlTypes.h>

XLpoint *
xlPointAlloc(void);

#define _xlPoint(e, v) \
	extern \
	XLpoint \
	*xlPoint ## v; \
	\
	XLpoint * \
	xlPointAssign ## v(XLpoint *a);

xlPointsForEach(_xlPoint)

#undef _xlPoint

XLpoint *
xlPointAssignArray(XLpoint *a, XLreal *array);

XLpoint *
xlPointAssignReals(XLpoint *a, XLreal x, XLreal y, XLreal z);

XLpoint *
xlPointAssignRand(XLpoint *a);

XLpoint *
xlPointSwizzle(XLpoint *a, XLint x, XLint y, XLint z);

XLpoint *
xlPointAssignSwizzle(XLpoint *a, XLpoint *b, XLint x, XLint y, XLint z);

XLpoint *
xlPointAssignSwizzleMatrix(XLpoint *a, XLmatrix *b, XLint x, XLint y, XLint z);

XLpoint *
xlPointAssignMatrixForward(XLpoint *a, XLmatrix *b);

XLpoint *
xlPointAssignMatrixUp(XLpoint *a, XLmatrix *b);

XLpoint *
xlPointAssignMatrixRight(XLpoint *a, XLmatrix *b);

XLpoint *
xlPointAssignMatrixPosition(XLpoint *a, XLmatrix *b);

XLpoint *
xlPointAssignMatrixScalation(XLpoint *a, XLmatrix *b);

XLpoint *
xlPointClear(XLpoint *a);

XLpoint *
xlPointCopy(XLpoint *a);

XLpoint *
xlPointAssignCopy(XLpoint *a, XLpoint *b);

XLpoint *
xlPointComp(XLpoint *a);

XLpoint *
xlPointAssignComp(XLpoint *a, XLpoint *b);

XLpoint *
xlPointNeg(XLpoint *a);

XLpoint *
xlPointAssignNeg(XLpoint *a, XLpoint *b);

XLpoint *
xlPointInc(XLpoint *a);

XLpoint *
xlPointAssignInc(XLpoint *a, XLpoint *b);

XLpoint *
xlPointDec(XLpoint *a);

XLpoint *
xlPointAssignDec(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAbs(XLpoint *a);

XLpoint *
xlPointAssignAbs(XLpoint *a, XLpoint *b);

XLreal
xlPointSquareNorm(XLpoint *a);

XLreal
xlPointNorm(XLpoint *a);

XLpoint *
xlPointNormal(XLpoint *a);

XLpoint *
xlPointAssignNormal(XLpoint *a, XLpoint *b);

XLboolean
xlPointBooleanEqual(XLpoint *a, XLpoint *b);

XLpoint *
xlPointPointEqual(XLpoint *a, XLpoint *b);

XLpoint *
xlPointPointAssignEqual(XLpoint *a, XLpoint *b, XLpoint *c);

XLboolean
xlPointBooleanGreater(XLpoint *a, XLpoint *b);

XLpoint *
xlPointPointGreater(XLpoint *a, XLpoint *b);

XLpoint *
xlPointPointAssignGreater(XLpoint *a, XLpoint *b, XLpoint *c);

XLboolean
xlPointBooleanLesser(XLpoint *a, XLpoint *b);

XLpoint *
xlPointPointLesser(XLpoint *a, XLpoint *b);

XLpoint *
xlPointPointAssignLesser(XLpoint *a, XLpoint *b, XLpoint *c);

XLreal
xlPointAngle(XLpoint *a, XLpoint *b);

XLreal
xlPointDot(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAndReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignAndReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointAnd(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAssignAnd(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointOrReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignOrReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointOr(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAssignOr(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointXorReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignXorReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointXor(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAssignXor(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointLShiftReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignLShiftReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointLShift(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAssignLShift(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointRShiftReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignRShiftReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointRShift(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAssignRShift(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointAddReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignAddReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointAdd(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAssignAdd(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointSubReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignSubReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointSub(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAssignSub(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointMultReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignMultReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointMult(XLpoint *a, XLpoint *b);

XLpoint *
xlPointMultMatrix(XLpoint *a, XLmatrix *b);

XLpoint *
xlPointAssignMult(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointAssignMultMatrix(XLpoint *a, XLpoint *b, XLmatrix *c);

XLpoint *
xlPointDivReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignDivReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointDiv(XLpoint *a, XLpoint *b);

XLpoint *
xlPointDivMatrix(XLpoint *a, XLmatrix *b);

XLpoint *
xlPointAssignDiv(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointAssignDivMatrix(XLpoint *a, XLpoint *b, XLmatrix *c);

XLpoint *
xlPointModReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignModReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointMod(XLpoint *a, XLpoint *b);

XLpoint *
xlPointModMatrix(XLpoint *a, XLmatrix *b);

XLpoint *
xlPointAssignMod(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointAssignModMatrix(XLpoint *a, XLpoint *b, XLmatrix *c);

XLpoint *
xlPointInvDivReal(XLpoint *a, XLreal r);

XLpoint *
xlPointAssignInvDivReal(XLpoint *a, XLpoint *b, XLreal r);

XLpoint *
xlPointInvDiv(XLpoint *a, XLpoint *b);

XLpoint *
xlPointInvDivMatrix(XLpoint *a, XLmatrix *b);

XLpoint *
xlPointAssignInvDiv(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointAssignInvDivMatrix(XLpoint *a, XLpoint *b, XLmatrix *c);

XLpoint *
xlPointCross(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAssignCross(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointMin(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAssignMin(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointMax(XLpoint *a, XLpoint *b);

XLpoint *
xlPointAssignMax(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointClampReal(XLpoint *a, XLreal b, XLreal c);

XLpoint *
xlPointAssignClampReal(XLpoint *a, XLpoint *b, XLreal c, XLreal d);

XLpoint *
xlPointClamp(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointAssignClamp(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d);

XLpoint *
xlPointAssignRandRangeReal(XLpoint *a, XLreal b, XLreal c);

XLpoint *
xlPointAssignRandRange(XLpoint *a, XLpoint *b, XLpoint *c);

XLpoint *
xlPointRotate(XLpoint *a, XLvector *axis, XLreal angle);

XLpoint *
xlPointAssignRotate(XLpoint *a, XLpoint *b, XLvector *axis, XLreal angle);

XLpoint *
xlPointLerp(XLpoint *a, XLpoint *b, XLreal t);

XLpoint *
xlPointAssignLerp(XLpoint *a, XLpoint *b, XLpoint *c, XLreal t);

XLpoint *
xlPointQuadBezier(XLpoint *a, XLpoint *b, XLpoint *c, XLreal t);

XLpoint *
xlPointAssignQuadBezier(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d, XLreal t);

XLpoint *
xlPointCubicBezier(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d, XLreal t);

XLpoint *
xlPointAssignCubicBezier(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d, XLpoint *e, XLreal t);

void
xlPointInit();

void
xlPointFini();

#endif
