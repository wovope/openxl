#ifndef XL_VECTOR_H
#define XL_VECTOR_H

#include <XL/xlTypes.h>

XLvector *
xlVectorAlloc(void);

#define _xlVector(e, v) \
	extern \
	XLvector \
	*xlVector ## v; \
	\
	XLvector * \
	xlVectorAssign ## v(XLvector *a);

xlVectorsForEach(_xlVector)

#undef _xlVector

XLvector *
xlVectorAssignArray(XLvector *a, XLreal *array);

XLvector *
xlVectorAssignReals(XLvector *a, XLreal x, XLreal y, XLreal z);

XLvector *
xlVectorAssignRand(XLvector *a);

XLvector *
xlVectorSwizzle(XLvector *a, XLint x, XLint y, XLint z);

XLvector *
xlVectorAssignSwizzle(XLvector *a, XLvector *b, XLint x, XLint y, XLint z);

XLvector *
xlVectorAssignSwizzleMatrix(XLvector *a, XLmatrix *b, XLint x, XLint y, XLint z);

XLvector *
xlVectorAssignMatrixForward(XLvector *a, XLmatrix *b);

XLvector *
xlVectorAssignMatrixUp(XLvector *a, XLmatrix *b);

XLvector *
xlVectorAssignMatrixRight(XLvector *a, XLmatrix *b);

XLvector *
xlVectorAssignMatrixPosition(XLvector *a, XLmatrix *b);

XLvector *
xlVectorAssignMatrixScalation(XLvector *a, XLmatrix *b);

XLvector *
xlVectorClear(XLvector *a);

XLvector *
xlVectorCopy(XLvector *a);

XLvector *
xlVectorAssignCopy(XLvector *a, XLvector *b);

XLvector *
xlVectorComp(XLvector *a);

XLvector *
xlVectorAssignComp(XLvector *a, XLvector *b);

XLvector *
xlVectorNeg(XLvector *a);

XLvector *
xlVectorAssignNeg(XLvector *a, XLvector *b);

XLvector *
xlVectorInc(XLvector *a);

XLvector *
xlVectorAssignInc(XLvector *a, XLvector *b);

XLvector *
xlVectorDec(XLvector *a);

XLvector *
xlVectorAssignDec(XLvector *a, XLvector *b);

XLvector *
xlVectorAbs(XLvector *a);

XLvector *
xlVectorAssignAbs(XLvector *a, XLvector *b);

XLreal
xlVectorSquareNorm(XLvector *a);

XLreal
xlVectorNorm(XLvector *a);

XLvector *
xlVectorNormal(XLvector *a);

XLvector *
xlVectorAssignNormal(XLvector *a, XLvector *b);

XLboolean
xlVectorBooleanEqual(XLvector *a, XLvector *b);

XLvector *
xlVectorVectorEqual(XLvector *a, XLvector *b);

XLvector *
xlVectorVectorAssignEqualPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorVectorAssignEqual(XLvector *a, XLvector *b, XLvector *c);

XLboolean
xlVectorBooleanGreater(XLvector *a, XLvector *b);

XLvector *
xlVectorVectorGreater(XLvector *a, XLvector *b);

XLvector *
xlVectorVectorAssignGreaterPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLboolean
xlVectorBooleanLesser(XLvector *a, XLvector *b);

XLvector *
xlVectorVectorLesser(XLvector *a, XLvector *b);

XLvector *
xlVectorVectorAssignLesserPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorVectorAssignLesser(XLvector *a, XLvector *b, XLvector *c);

XLreal
xlVectorAngle(XLvector *a, XLvector *b);

XLreal
xlVectorDot(XLvector *a, XLvector *b);

XLvector *
xlVectorAndReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignAndReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorAnd(XLvector *a, XLvector *b);

XLvector *
xlVectorAssignAndPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignAnd(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorOrReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignOrReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorOr(XLvector *a, XLvector *b);

XLvector *
xlVectorAssignOrPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignOr(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorXorReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignXorReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorXor(XLvector *a, XLvector *b);

XLvector *
xlVectorAssignXorPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignXor(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorLShiftReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignLShiftReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorLShift(XLvector *a, XLvector *b);

XLvector *
xlVectorAssignLShiftPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignLShift(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorRShiftReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignRShiftReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorRShift(XLvector *a, XLvector *b);

XLvector *
xlVectorAssignRShiftPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignRShift(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorAddReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignAddReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorAdd(XLvector *a, XLvector *b);

XLvector *
xlVectorAssignAddPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignAdd(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorSubReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignSubReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorSub(XLvector *a, XLvector *b);

XLvector *
xlVectorAssignSubPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignSub(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorMultReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignMultReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorMult(XLvector *a, XLvector *b);

XLvector *
xlVectorMultMatrix(XLvector *a, XLmatrix *b);

XLvector *
xlVectorAssignMultPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignMult(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorAssignMultMatrix(XLvector *a, XLvector *b, XLmatrix *c);

XLvector *
xlVectorDivReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignDivReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorDiv(XLvector *a, XLvector *b);

XLvector *
xlVectorDivMatrix(XLvector *a, XLmatrix *b);

XLvector *
xlVectorAssignDivPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignDiv(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorAssignDivMatrix(XLvector *a, XLvector *b, XLmatrix *c);

XLvector *
xlVectorModReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignModReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorMod(XLvector *a, XLvector *b);

XLvector *
xlVectorModMatrix(XLvector *a, XLmatrix *b);

XLvector *
xlVectorAssignModPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignMod(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorAssignModMatrix(XLvector *a, XLvector *b, XLmatrix *c);

XLvector *
xlVectorInvDivReal(XLvector *a, XLreal r);

XLvector *
xlVectorAssignInvDivReal(XLvector *a, XLvector *b, XLreal r);

XLvector *
xlVectorInvDiv(XLvector *a, XLvector *b);

XLvector *
xlVectorInvDivMatrix(XLvector *a, XLmatrix *b);

XLvector *
xlVectorAssignInvDivPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorAssignInvDiv(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorAssignInvDivMatrix(XLvector *a, XLvector *b, XLmatrix *c);

XLvector *
xlVectorCross(XLvector *a, XLvector *b);

XLvector *
xlVectorAssignCross(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorAssignCrossPoint(XLvector *a, XLpoint *b, XLpoint *c);

XLvector *
xlVectorMin(XLvector *a, XLvector *b);

XLvector *
xlVectorAssignMin(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorMax(XLvector *a, XLvector *b);

XLvector *
xlVectorAssignMax(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorClampReal(XLvector *a, XLreal b, XLreal c);

XLvector *
xlVectorAssignClampReal(XLvector *a, XLvector *b, XLreal c, XLreal d);

XLvector *
xlVectorClamp(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorAssignClamp(XLvector *a, XLvector *b, XLvector *c, XLvector *d);

XLvector *
xlVectorAssignRandRangeReal(XLvector *a, XLreal b, XLreal c);

XLvector *
xlVectorAssignRandRange(XLvector *a, XLvector *b, XLvector *c);

XLvector *
xlVectorRotate(XLvector *a, XLvector *axis, XLreal angle);

XLvector *
xlVectorAssignRotate(XLvector *a, XLvector *b, XLvector *axis, XLreal angle);

XLvector *
xlVectorLerp(XLvector *a, XLvector *b, XLreal t);

XLvector *
xlVectorAssignLerp(XLvector *a, XLvector *b, XLvector *c, XLreal t);

XLvector *
xlVectorQuadBezier(XLvector *a, XLvector *b, XLvector *c, XLreal t);

XLvector *
xlVectorAssignQuadBezier(XLvector *a, XLvector *b, XLvector *c, XLvector *d, XLreal t);

XLvector *
xlVectorCubicBezier(XLvector *a, XLvector *b, XLvector *c, XLvector *d, XLreal t);

XLvector *
xlVectorAssignCubicBezier(XLvector *a, XLvector *b, XLvector *c, XLvector *d, XLvector *e, XLreal t);

void
xlVectorInit();

void
xlVectorFini();

#endif
