#ifndef XL_MATRIX_H
#define XL_MATRIX_H

#include <XL/xlTypes.h>

XLmatrix *
xlMatrixAlloc(void);

#define _xlMatrix(e, m) \
	extern \
	XLmatrix \
	*xlMatrix ## m; \
	\
	XLmatrix * \
	xlMatrixAssign ## m(XLmatrix *a);

xlMatricesForEach(_xlMatrix)

#undef _xlMatrix

XLmatrix *
xlMatrixAssignArray(XLmatrix *a, XLreal *array);

XLmatrix *
xlMatrixAssignReals(XLmatrix *a, XLreal xx, XLreal yx, XLreal zx, XLreal wx, XLreal xy, XLreal yy, XLreal zy, XLreal wy, XLreal xz, XLreal yz, XLreal zz, XLreal wz, XLreal xw, XLreal yw, XLreal zw, XLreal ww);

XLmatrix *
xlMatrixAssignRand(XLmatrix *a);

XLmatrix *
xlMatrixAssignTranslation(XLmatrix *a, XLpoint *p);

XLmatrix *
xlMatrixAssignScalation(XLmatrix *a, XLvector *s);

XLmatrix *
xlMatrixAssignRotation(XLmatrix *a, XLvector *x, XLreal r);

XLmatrix *
xlMatrixAssignLook(XLmatrix *a, XLpoint *p, XLvector *f, XLvector *u);

XLmatrix *
xlMatrixAssignLookAt(XLmatrix *a, XLpoint *e, XLpoint *c, XLvector *u);

XLmatrix *
xlMatrixAssignBillboard(XLmatrix *a, XLmatrix *m, XLpoint *p);

XLmatrix *
xlMatrixSwizzle(XLmatrix *a, XLint xx, XLint yx, XLint zx, XLint wx, XLint xy, XLint yy, XLint zy, XLint wy, XLint xz, XLint yz, XLint zz, XLint wz, XLint xw, XLint yw, XLint zw, XLint ww);

XLmatrix *
xlMatrixAssignSwizzle(XLmatrix *a, XLmatrix *b, XLint xx, XLint yx, XLint zx, XLint wx, XLint xy, XLint yy, XLint zy, XLint wy, XLint xz, XLint yz, XLint zz, XLint wz, XLint xw, XLint yw, XLint zw, XLint ww);

XLmatrix *
xlMatrixForward(XLmatrix *a, XLvector *b);

XLmatrix *
xlMatrixAssignForward(XLmatrix *a, const XLmatrix *b, XLvector *c);

XLmatrix *
xlMatrixUp(XLmatrix *a, XLvector *b);

XLmatrix *
xlMatrixAssignUp(XLmatrix *a, const XLmatrix *b, XLvector *c);

XLmatrix *
xlMatrixRight(XLmatrix *a, XLvector *b);

XLmatrix *
xlMatrixAssignRight(XLmatrix *a, const XLmatrix *b, XLvector *c);

XLmatrix *
xlMatrixPosition(XLmatrix *a, XLpoint *b);

XLmatrix *
xlMatrixAssignPosition(XLmatrix *a, const XLmatrix *b, XLpoint *c);

XLmatrix *
xlMatrixClear(XLmatrix *a);

XLmatrix *
xlMatrixCopy(XLmatrix *a);

XLmatrix *
xlMatrixAssignCopy(XLmatrix *a, const XLmatrix *b);

XLmatrix *
xlMatrixComp(XLmatrix *a);

XLmatrix *
xlMatrixAssignComp(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixNeg(XLmatrix *a);

XLmatrix *
xlMatrixAssignNeg(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixInc(XLmatrix *a);

XLmatrix *
xlMatrixAssignInc(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixDec(XLmatrix *a);

XLmatrix *
xlMatrixAssignDec(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAbs(XLmatrix *a);

XLmatrix *
xlMatrixAssignAbs(XLmatrix *a, XLmatrix *b);

#if 0
XLreal
xlMatrixSquareNorm(XLmatrix *a);

XLreal
xlMatrixNorm(XLmatrix *a);

XLmatrix *
xlMatrixNormal(XLmatrix *a);

XLmatrix *
xlMatrixAssignNormal(XLmatrix *a, XLmatrix *b);

#endif

XLmatrix *
xlMatrixTranspose(XLmatrix *a);

XLmatrix *
xlMatrixAssignTranspose(XLmatrix *a, XLmatrix *b);

XLboolean
xlMatrixBooleanEqual(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixMatrixEqual(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixMatrixAssignEqual(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLboolean
xlMatrixBooleanGreater(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixMatrixGreater(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixMatrixAssignGreater(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLboolean
xlMatrixBooleanLesser(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixMatrixLesser(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixMatrixAssignLesser(XLmatrix *a, XLmatrix *b, XLmatrix *c);

#if 0
XLreal
xlMatrixAngle(XLmatrix *a, XLmatrix *b);

XLreal
xlMatrixDot(XLmatrix *a, XLmatrix *b);

#endif

XLmatrix *
xlMatrixAndReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignAndReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixAnd(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignAnd(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixOrReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignOrReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixOr(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignOr(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixXorReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignXorReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixXor(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignXor(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixLShiftReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignLShiftReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixLShift(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignLShift(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixRShiftReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignRShiftReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixRShift(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignRShift(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixAddReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignAddReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixAdd(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignAdd(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixSubReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignSubReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixSub(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignSub(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixMultReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignMultReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixMult(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignMult(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixDivReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignDivReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixDiv(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignDiv(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixModReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignModReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixMod(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignMod(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixInvDivReal(XLmatrix *a, XLreal r);

XLmatrix *
xlMatrixAssignInvDivReal(XLmatrix *a, XLmatrix *b, XLreal r);

XLmatrix *
xlMatrixInvDiv(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignInvDiv(XLmatrix *a, XLmatrix *b, XLmatrix *c);

#if 0
XLmatrix *
xlMatrixCross(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignCross(XLmatrix *a, XLmatrix *b, XLmatrix *c);

#endif

XLmatrix *
xlMatrixMin(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignMin(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixMax(XLmatrix *a, XLmatrix *b);

XLmatrix *
xlMatrixAssignMax(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixClampReal(XLmatrix *a, XLreal b, XLreal c);

XLmatrix *
xlMatrixAssignClampReal(XLmatrix *a, XLmatrix *b, XLreal c, XLreal d);

XLmatrix *
xlMatrixClamp(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixAssignClamp(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d);

XLmatrix *
xlMatrixAssignRandRangeReal(XLmatrix *a, XLreal b, XLreal c);

XLmatrix *
xlMatrixAssignRandRange(XLmatrix *a, XLmatrix *b, XLmatrix *c);

XLmatrix *
xlMatrixTranslate(XLmatrix *a, XLpoint *position);

XLmatrix *
xlMatrixAssignTranslate(XLmatrix *a, XLmatrix *b, XLpoint *position);

XLmatrix *
xlMatrixScale(XLmatrix *a, XLvector *scale);

XLmatrix *
xlMatrixAssignScale(XLmatrix *a, XLmatrix *b, XLvector *scale);

XLmatrix *
xlMatrixRotate(XLmatrix *a, XLvector *axis, XLreal angle);

XLmatrix *
xlMatrixAssignRotate(XLmatrix *a, XLmatrix *b, XLvector *axis, XLreal angle);

XLmatrix *
xlMatrixLerp(XLmatrix *a, XLmatrix *b, XLreal t);

XLmatrix *
xlMatrixAssignLerp(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLreal t);

XLmatrix *
xlMatrixQuadBezier(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLreal t);

XLmatrix *
xlMatrixAssignQuadBezier(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d, XLreal t);

XLmatrix *
xlMatrixCubicBezier(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d, XLreal t);

XLmatrix *
xlMatrixAssignCubicBezier(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d, XLmatrix *e, XLreal t);

void
xlMatrixInit();

void
xlMatrixFini();

#endif
