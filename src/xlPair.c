/* http://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html */

#include "XL/xlPair.h"
#include "XL/xl.h"

#define xlPairArrayAssignNoneOp(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(); \
		XL_PAIR_Y(a) = xlReal ## Op(); \
		return a; \
	}
#define xlPairArrayOp(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(a)); \
		return a; \
	}
#define xlPairArrayAssignOpPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b)); \
		return a; \
	}
#define xlPairArrayBooleanOpPair(Name, Op) \
	XLboolean \
	xlPair ## Name(XLpair *a, XLpair *b) \
	{ \
		return \
			xlReal ## Op(XL_PAIR_X(a), XL_PAIR_X(b)) && \
			xlReal ## Op(XL_PAIR_Y(a), XL_PAIR_Y(b)); \
	}
#define xlPairArrayOpPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a), XL_PAIR_X(b)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(a), XL_PAIR_Y(b)); \
		return a; \
	}
#define xlPairArrayAssignOpPairPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b), XL_PAIR_X(c)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b), XL_PAIR_Y(c)); \
		return a; \
	}
#define xlPairArrayAssignNoneOpRealReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLreal b, XLreal c) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(b, c); \
		XL_PAIR_Y(a) = xlReal ## Op(b, c); \
		return a; \
	}
#define xlPairArrayAssignNoneOpPairPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b), XL_PAIR_X(c)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b), XL_PAIR_Y(c)); \
		return a; \
	}
#define xlPairArrayOpRealReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLreal b, XLreal c) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a), b, c); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(a), b, c); \
		return a; \
	}
#define xlPairArrayAssignOpPairRealReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLreal c, XLreal d) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b), c, d); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b), c, d); \
		return a; \
	}
#define xlPairArrayOpPairPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a), XL_PAIR_X(b), XL_PAIR_X(c)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(a), XL_PAIR_Y(b), XL_PAIR_Y(c)); \
		return a; \
	}
#define xlPairArrayAssignOpPairPairPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLpair *d) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b), XL_PAIR_X(c), XL_PAIR_X(d)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b), XL_PAIR_Y(c), XL_PAIR_Y(d)); \
		return a; \
	}

#ifdef XL_SIMD
#define xlPairOp(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op(XL_PAIR_SIMD(a)); \
		return a; \
	}
#define xlPairAssignOpPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op(XL_PAIR_SIMD(b)); \
		return a; \
	}
#define xlPairOpReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLreal r) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op ## Real(XL_PAIR_SIMD(a), r); \
		return a; \
	}
#define xlPairAssignOpPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLreal r) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op ## Real(XL_PAIR_SIMD(b), r); \
		return a; \
	}
#define xlPairOpPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op(XL_PAIR_SIMD(a), XL_PAIR_SIMD(b)); \
		return a; \
	}
#define xlPairAssignOpPairPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op(XL_PAIR_SIMD(b), XL_PAIR_SIMD(c)); \
		return a; \
	}
#define xlPairOpMatrix(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLmatrix *b) \
	{ \
		XLsimd4sr simd[4] = { \
			{ XL_MATRIX_SIMD(b)[0], XL_MATRIX_SIMD(b)[1], XL_MATRIX_SIMD(b)[2], XL_MATRIX_SIMD(b)[3] }, \
			{ XL_MATRIX_SIMD(b)[4], XL_MATRIX_SIMD(b)[5], XL_MATRIX_SIMD(b)[6], XL_MATRIX_SIMD(b)[7] }, \
			{ XL_MATRIX_SIMD(b)[8], XL_MATRIX_SIMD(b)[9], XL_MATRIX_SIMD(b)[10], XL_MATRIX_SIMD(b)[11] }, \
			{ XL_MATRIX_SIMD(b)[12], XL_MATRIX_SIMD(b)[13], XL_MATRIX_SIMD(b)[14], XL_MATRIX_SIMD(b)[15] } \
		}; \
		simd[0] = xlReal ## Op ## Simd4sr(XL_PAIR_X(a), simd[0]); \
		simd[1] = xlReal ## Op ## Simd4sr(XL_PAIR_Y(a), simd[1]); \
		simd[2] = xlReal ## Op ## Simd4sr(XL_REAL(0), simd[2]); \
		simd[3] = xlReal ## Op ## Simd4sr(XL_REAL(1), simd[3]); \
		XL_PAIR_SIMD(a) = simd[0] + simd[1] + simd[2] + simd[3]; \
		return a; \
	}
#define xlPairAssignOpPairMatrix(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLmatrix *c) \
	{ \
		XLsimd4sr simd[4] = { \
			{ XL_MATRIX_SIMD(c)[0], XL_MATRIX_SIMD(c)[1], XL_MATRIX_SIMD(c)[2], XL_MATRIX_SIMD(c)[3] }, \
			{ XL_MATRIX_SIMD(c)[4], XL_MATRIX_SIMD(c)[5], XL_MATRIX_SIMD(c)[6], XL_MATRIX_SIMD(c)[7] }, \
			{ XL_MATRIX_SIMD(c)[8], XL_MATRIX_SIMD(c)[9], XL_MATRIX_SIMD(c)[10], XL_MATRIX_SIMD(c)[11] }, \
			{ XL_MATRIX_SIMD(c)[12], XL_MATRIX_SIMD(c)[13], XL_MATRIX_SIMD(c)[14], XL_MATRIX_SIMD(c)[15] } \
		}; \
		simd[0] = xlReal ## Op ## Simd4sr(XL_PAIR_X(b), simd[0]); \
		simd[1] = xlReal ## Op ## Simd4sr(XL_PAIR_Y(b), simd[1]); \
		simd[2] = xlReal ## Op ## Simd4sr(XL_REAL(0), simd[2]); \
		simd[3] = xlReal ## Op ## Simd4sr(XL_REAL(1), simd[3]); \
		XL_PAIR_SIMD(a) = simd[0] + simd[1] + simd[2] + simd[3]; \
		return a; \
	}
#define xlPairOpPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLreal r) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op(XL_PAIR_SIMD(a), XL_PAIR_SIMD(b), r); \
		return a; \
	}
#define xlPairAssignOpPairPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLreal r) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op(XL_PAIR_SIMD(b), XL_PAIR_SIMD(c), r); \
		return a; \
	}
#define xlPairOpPairPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLreal r) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op(XL_PAIR_SIMD(a), XL_PAIR_SIMD(b), XL_PAIR_SIMD(c), r); \
		return a; \
	}
#define xlPairAssignOpPairPairPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLpair *d, XLreal r) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op(XL_PAIR_SIMD(b), XL_PAIR_SIMD(c), XL_PAIR_SIMD(d), r); \
		return a; \
	}
#define xlPairOpPairPairPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLpair *d, XLreal r) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op(XL_PAIR_SIMD(a), XL_PAIR_SIMD(b), XL_PAIR_SIMD(c), XL_PAIR_SIMD(d), r); \
		return a; \
	}
#define xlPairAssignOpPairPairPairPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLpair *d, XLpair *e, XLreal r) \
	{ \
		XL_PAIR_SIMD(a) = xlSimd4sr ## Op(XL_PAIR_SIMD(b), XL_PAIR_SIMD(c), XL_PAIR_SIMD(d), XL_PAIR_SIMD(e), r); \
		return a; \
	}
#else
#define xlPairOp(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(a)); \
		return a; \
	}
#define xlPairAssignOpPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b)); \
		return a; \
	}
#define xlPairOpReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLreal r) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a), r); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(a), r); \
		return a; \
	}
#define xlPairAssignOpPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLreal r) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b), r); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b), r); \
		return a; \
	}
#define xlPairOpPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a), XL_PAIR_X(b)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(a), XL_PAIR_Y(b)); \
		return a; \
	}
#define xlPairAssignOpPairPair(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b), XL_PAIR_X(c)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b), XL_PAIR_Y(c)); \
		return a; \
	}
#define xlPairOpMatrix(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLmatrix *b) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a), XL_MATRIX_XX(b)) + xlReal ## Op(XL_PAIR_Y(a), XL_MATRIX_XY(b)) + xlReal ## Op(XL_REAL(0), XL_MATRIX_XZ(b)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_XW(b)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_X(a), XL_MATRIX_YX(b)) + xlReal ## Op(XL_PAIR_Y(a), XL_MATRIX_YY(b)) + xlReal ## Op(XL_REAL(0), XL_MATRIX_YZ(b)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_YW(b)); \
		return a; \
	}
#define xlPairAssignOpPairMatrix(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLmatrix *c) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b), XL_MATRIX_XX(c)) + xlReal ## Op(XL_PAIR_Y(b), XL_MATRIX_XY(c)) + xlReal ## Op(XL_REAL(0), XL_MATRIX_XZ(c)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_XW(c)); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_X(b), XL_MATRIX_YX(c)) + xlReal ## Op(XL_PAIR_Y(b), XL_MATRIX_YY(c)) + xlReal ## Op(XL_REAL(0), XL_MATRIX_YZ(c)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_YW(c)); \
		return a; \
	}
#define xlPairOpPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLreal r) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a), XL_PAIR_X(b), r); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(a), XL_PAIR_Y(b), r); \
		return a; \
	}
#define xlPairAssignOpPairPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLreal r) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b), XL_PAIR_X(c), r); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b), XL_PAIR_Y(c), r); \
		return a; \
	}
#define xlPairOpPairPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLreal r) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a), XL_PAIR_X(b), XL_PAIR_X(c), r); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(a), XL_PAIR_Y(b), XL_PAIR_Y(c), r); \
		return a; \
	}
#define xlPairAssignOpPairPairPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLpair *d, XLreal r) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b), XL_PAIR_X(c), XL_PAIR_X(d), r); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b), XL_PAIR_Y(c), XL_PAIR_Y(d), r); \
		return a; \
	}
#define xlPairOpPairPairPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLpair *d, XLreal r) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(a), XL_PAIR_X(b), XL_PAIR_X(c), XL_PAIR_X(d), r); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(a), XL_PAIR_Y(b), XL_PAIR_Y(c), XL_PAIR_Y(d), r); \
		return a; \
	}
#define xlPairAssignOpPairPairPairPairReal(Name, Op) \
	XLpair * \
	xlPair ## Name(XLpair *a, XLpair *b, XLpair *c, XLpair *d, XLpair *e, XLreal r) \
	{ \
		XL_PAIR_X(a) = xlReal ## Op(XL_PAIR_X(b), XL_PAIR_X(c), XL_PAIR_X(d), XL_PAIR_X(e), r); \
		XL_PAIR_Y(a) = xlReal ## Op(XL_PAIR_Y(b), XL_PAIR_Y(c), XL_PAIR_Y(d), XL_PAIR_Y(e), r); \
		return a; \
	}
#endif

XLpair *
xlPairAlloc(void)
{
	XLpair *a;
#ifdef XL_SIMD
	a = xlSimdAligned4srAlloc(sizeof(XLpair));
#else
	a = xlMemoryAlloc(sizeof(XLpair));
#endif
	return a;
}

#define _xlPair(v, x, y) \
	static \
	XLpair \
	_xlPair ## v; \
	\
	XLpair \
	*xlPair ## v; \
	\
	XLpair * \
	xlPairAssign ## v(XLpair *a) \
	{ \
		return xlPairAssignReals(a, x, y); \
	} 

_xlPair(Default, XL_REAL(0), XL_REAL(0));
_xlPair(NegDefault, XL_REAL(0), XL_REAL(0));
_xlPair(Zero, XL_REAL(0), XL_REAL(0));
_xlPair(Half, XL_REAL(0.5), XL_REAL(0.5));
_xlPair(NegHalf, XL_REAL(-0.5), XL_REAL(-0.5));
_xlPair(One, XL_REAL(1), XL_REAL(1));
_xlPair(NegOne, XL_REAL(-1), XL_REAL(-1));
_xlPair(Double, XL_REAL(2), XL_REAL(2));
_xlPair(NegDouble, XL_REAL(-2), XL_REAL(-2));
_xlPair(X, XL_REAL(1), XL_REAL(0));
_xlPair(NegX, XL_REAL(-1), XL_REAL(0));
_xlPair(Y, XL_REAL(0), XL_REAL(1));
_xlPair(NegY, XL_REAL(0), XL_REAL(-1));
_xlPair(TMP, XL_REAL(0), XL_REAL(0));
_xlPair(TMP1, XL_REAL(0), XL_REAL(0));
_xlPair(TMP2, XL_REAL(0), XL_REAL(0));
_xlPair(TMP3, XL_REAL(0), XL_REAL(0));
_xlPair(TMP4, XL_REAL(0), XL_REAL(0));
_xlPair(Center, XL_REAL(0), XL_REAL(0));
_xlPair(Right, XL_REAL(1), XL_REAL(0));
_xlPair(Left, XL_REAL(-1), XL_REAL(0));
_xlPair(Up, XL_REAL(0), XL_REAL(1));
_xlPair(Down, XL_REAL(0), XL_REAL(-1));
_xlPair(RightUp, XL_REAL(1), XL_REAL(1));
_xlPair(RightDown, XL_REAL(1), XL_REAL(-1));
_xlPair(LeftUp, XL_REAL(-1), XL_REAL(1));
_xlPair(LeftDown, XL_REAL(-1), XL_REAL(-1));
_xlPair(Origin, XL_REAL(0), XL_REAL(0));
_xlPair(North, XL_REAL(0), XL_REAL(1));
_xlPair(South, XL_REAL(0), XL_REAL(-1));
_xlPair(East, XL_REAL(1), XL_REAL(0));
_xlPair(West, XL_REAL(-1), XL_REAL(0));
_xlPair(NorthEast, XL_REAL(1), XL_REAL(1));
_xlPair(NorthWest, XL_REAL(-1), XL_REAL(1));
_xlPair(SouthEast, XL_REAL(1), XL_REAL(-1));
_xlPair(SouthWest, XL_REAL(-1), XL_REAL(-1));

#undef _xlVector
XLpair *
xlPairAssignArray(XLpair *a, XLreal *array)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { array[0], array[1], XL_REAL(1), XL_REAL(1) };
	XL_PAIR_SIMD(a) = simd;
#else
	xlRealCopy(XL_PAIR_ARRAY(a), array, 2);
#endif
	return a;
}

XLpair *
xlPairAssignReals(XLpair *a, XLreal x, XLreal y)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { x, y, XL_REAL(1), XL_REAL(1) };
	XL_PAIR_SIMD(a) = simd;
#else
	XL_PAIR_X(a) = x;
	XL_PAIR_Y(a) = y;
#endif
	return a;
}

xlPairArrayAssignNoneOp(AssignRand, Rand);

XLpair *
xlPairSwizzle(XLpair *a, XLint x, XLint y)
{
#ifdef XL_SIMD
	XLsimd4si mask = { x, y, 2, 3 };
	XL_PAIR_SIMD(a) = __builtin_shuffle(XL_PAIR_SIMD(a), mask);
#else
	XLreal data[2];
	data[0] = XL_PAIR_ARRAY(a)[x];
	data[1] = XL_PAIR_ARRAY(a)[y];
	xlRealCopy(XL_PAIR_ARRAY(a), data, 2);
#endif
	return a;
}

XLpair *
xlPairAssignSwizzle(XLpair *a, XLpair *b, XLint x, XLint y)
{
#ifdef XL_SIMD
	XLsimd4si mask = { x, y, 2, 3 };
	XL_PAIR_SIMD(a) = __builtin_shuffle(XL_PAIR_SIMD(b), mask);
#else
	XL_PAIR_X(a) = XL_PAIR_ARRAY(b)[x];
	XL_PAIR_Y(a) = XL_PAIR_ARRAY(b)[y];
#endif
	return a;
}

XLpair *
xlPairAssignSwizzleVector(XLpair *a, XLvector *b, XLint x, XLint y)
{
	XL_PAIR_X(a) = XL_VECTOR_ARRAY(b)[x];
	XL_PAIR_Y(a) = XL_VECTOR_ARRAY(b)[y];
	return a;
}

XLpair *
xlPairAssignSwizzleMatrix(XLpair *a, XLmatrix *b, XLint x, XLint y)
{
	XL_PAIR_X(a) = XL_MATRIX_ARRAY(b)[x];
	XL_PAIR_Y(a) = XL_MATRIX_ARRAY(b)[y];
	return a;
}

XLpair *
xlPairAssignMatrixForward(XLpair *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_ZX(b), XL_MATRIX_ZY(b), XL_MATRIX_ZZ(b), XL_REAL(1) };
	XL_PAIR_SIMD(a) = -simd;
#else
	XL_PAIR_X(a) = -XL_MATRIX_ZX(b);
	XL_PAIR_Y(a) = -XL_MATRIX_ZY(b);
#endif
	return a;
}

XLpair *
xlPairAssignMatrixUp(XLpair *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_YX(b), XL_MATRIX_YY(b), XL_MATRIX_YZ(b), XL_REAL(1) };
	XL_PAIR_SIMD(a) = simd;
#else
	XL_PAIR_X(a) = XL_MATRIX_YX(b);
	XL_PAIR_Y(a) = XL_MATRIX_YY(b);
#endif
	return a;
}

XLpair *
xlPairAssignMatrixRight(XLpair *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XX(b), XL_MATRIX_XY(b), XL_MATRIX_XZ(b), XL_REAL(1) };
	XL_PAIR_SIMD(a) = simd;
#else
	XL_PAIR_X(a) = XL_MATRIX_XX(b);
	XL_PAIR_Y(a) = XL_MATRIX_XY(b);
#endif
	return a;
}

XLpair *
xlPairAssignMatrixPosition(XLpair *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XW(b), XL_MATRIX_YW(b), XL_MATRIX_ZW(b), XL_REAL(1) };
	XL_PAIR_SIMD(a) = simd;
#else
	XL_PAIR_X(a) = XL_MATRIX_XW(b);
	XL_PAIR_Y(a) = XL_MATRIX_YW(b);
#endif
	return a;
}

XLpair *
xlPairAssignMatrixScalation(XLpair *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XX(b), XL_MATRIX_YY(b), XL_MATRIX_ZZ(b), XL_REAL(1) };
	XL_PAIR_SIMD(a) = simd;
#else
	XL_PAIR_X(a) = XL_MATRIX_XX(b);
	XL_PAIR_Y(a) = XL_MATRIX_YY(b);
#endif
	return a;
}

XLpair *
xlPairClear(XLpair *a)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0) };
	XL_PAIR_SIMD(a) = simd;
#else
	xlMemoryZero(a, sizeof(XLpair));
#endif
	return a;
}

XLpair *
xlPairCopy(XLpair *a)
{
	XLpair *b;

	b = xlPairAlloc();
	return xlPairAssignCopy(b, a);
}

XLpair *
xlPairAssignCopy(XLpair *a, XLpair *b)
{
#ifdef XL_SIMD
	XL_PAIR_SIMD(a) = XL_PAIR_SIMD(b);
#else
	xlMemoryCopy(a, b, sizeof(XLpair));
#endif
	return a;
}

xlPairOp(Comp, Comp);
xlPairAssignOpPair(AssignComp, Comp);

xlPairOp(Neg, Neg);
xlPairAssignOpPair(AssignNeg, Neg);

xlPairOp(Inc, Inc);
xlPairAssignOpPair(AssignInc, Inc);

xlPairOp(Dec, Dec);
xlPairAssignOpPair(AssignDec, Dec);

xlPairArrayOp(Abs, Abs);
xlPairArrayAssignOpPair(AssignAbs, Abs);

XLreal
xlPairSquareNorm(XLpair *a)
{
	return xlPairDot(a, a);
}

XLreal
xlPairNorm(XLpair *a)
{
	return xlRealSquareRoot(xlPairSquareNorm(a));
}

XLpair *
xlPairNormal(XLpair *a)
{
	return xlPairMultReal(a, XL_REAL(1) / xlPairNorm(a));
}

XLpair *
xlPairAssignNormal(XLpair *a, XLpair *b)
{
	return xlPairAssignMultReal(a, b, XL_REAL(1) / xlPairNorm(b));
}

xlPairArrayBooleanOpPair(BooleanEqual, Equal);
xlPairOpPair(PairEqual, Equal);
xlPairAssignOpPairPair(PairAssignEqual, Equal);

xlPairArrayBooleanOpPair(BooleanGreater, Greater);
xlPairOpPair(PairGreater, Greater);
xlPairAssignOpPairPair(PairAssignGreater, Greater);

xlPairArrayBooleanOpPair(BooleanLesser, Lesser);
xlPairOpPair(PairLesser, Lesser);
xlPairAssignOpPairPair(PairAssignLesser, Lesser);

XLreal
xlPairAngle(XLpair *a, XLpair *b)
{
	return xlRealRadToDeg(xlRealArcCosine(xlPairDot(a, b) / (xlPairNorm(a) * xlPairNorm(b))));
}

XLreal
xlPairDot(XLpair *a, XLpair *b)
{
	XLreal r;
#ifdef XL_SIMD
	XLsimd4sr simd;
	simd = XL_PAIR_SIMD(a) * XL_PAIR_SIMD(b);
	r = simd[0] + simd[1] + simd[2];
#else
	r = XL_PAIR_X(a) * XL_PAIR_X(b) + XL_PAIR_Y(a) * XL_PAIR_Y(b);
#endif
	return r;
}

xlPairOpReal(AndReal, And);
xlPairAssignOpPairReal(AssignAndReal, And);
xlPairOpPair(And, And);
xlPairAssignOpPairPair(AssignAnd, And);

xlPairOpReal(OrReal, Or);
xlPairAssignOpPairReal(AssignOrReal, Or);
xlPairOpPair(Or, Or);
xlPairAssignOpPairPair(AssignOr, Or);

xlPairOpReal(XorReal, Xor);
xlPairAssignOpPairReal(AssignXorReal, Xor);
xlPairOpPair(Xor, Xor);
xlPairAssignOpPairPair(AssignXor, Xor);

xlPairOpReal(LShiftReal, LShift);
xlPairAssignOpPairReal(AssignLShiftReal, LShift);
xlPairOpPair(LShift, LShift);
xlPairAssignOpPairPair(AssignLShift, LShift);

xlPairOpReal(RShiftReal, RShift);
xlPairAssignOpPairReal(AssignRShiftReal, RShift);
xlPairOpPair(RShift, RShift);
xlPairAssignOpPairPair(AssignRShift, RShift);

xlPairOpReal(AddReal, Add);
xlPairAssignOpPairReal(AssignAddReal, Add);
xlPairOpPair(Add, Add);
xlPairAssignOpPairPair(AssignAdd, Add);

xlPairOpReal(SubReal, Sub);
xlPairAssignOpPairReal(AssignSubReal, Sub);
xlPairOpPair(Sub, Sub);
xlPairAssignOpPairPair(AssignSub, Sub);

xlPairOpReal(MultReal, Mult);
xlPairAssignOpPairReal(AssignMultReal, Mult);
xlPairOpPair(Mult, Mult);
xlPairAssignOpPairPair(AssignMult, Mult);
xlPairOpMatrix(MultMatrix, Mult);
xlPairAssignOpPairMatrix(AssignMultMatrix, Mult);

xlPairOpReal(DivReal, Div);
xlPairAssignOpPairReal(AssignDivReal, Div);
xlPairOpPair(Div, Div);
xlPairAssignOpPairPair(AssignDiv, Div);
xlPairOpMatrix(DivMatrix, Div);
xlPairAssignOpPairMatrix(AssignDivMatrix, Div);

xlPairOpReal(ModReal, Mod);
xlPairAssignOpPairReal(AssignModReal, Mod);
xlPairOpPair(Mod, Mod);
xlPairAssignOpPairPair(AssignMod, Mod);
xlPairOpMatrix(ModMatrix, Mod);
xlPairAssignOpPairMatrix(AssignModMatrix, Mod);

xlPairOpReal(InvDivReal, InvDiv);
xlPairAssignOpPairReal(AssignInvDivReal, InvDiv);
xlPairOpPair(InvDiv, InvDiv);
xlPairAssignOpPairPair(AssignInvDiv, InvDiv);
xlPairOpMatrix(InvDivMatrix, InvDiv);
xlPairAssignOpPairMatrix(AssignInvDivMatrix, InvDiv);

XLpair *
xlPairCross(XLpair *a, XLpair *b)
{
#ifdef XL_SIMD
	XLsimd4si mask[2] = { { 1, 0, 2, 3 }, { 1, 0, 2, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_PAIR_SIMD(a), mask[0]);
	simd[1] = __builtin_shuffle(XL_PAIR_SIMD(b), mask[1]);
	simd[2] = __builtin_shuffle(XL_PAIR_SIMD(a), mask[1]);
	simd[3] = __builtin_shuffle(XL_PAIR_SIMD(b), mask[0]);
	XL_PAIR_SIMD(a) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XLreal data[2];
	data[0] = XL_PAIR_Y(a) * XL_REAL(1) - XL_REAL(1) * XL_PAIR_Y(b);
	data[1] = XL_REAL(1) * XL_PAIR_X(b) - XL_PAIR_X(a) * XL_REAL(1);
	xlRealCopy(XL_PAIR_ARRAY(a), data, 2);
#endif
	return a;
}

XLpair *
xlPairAssignCross(XLpair *a, XLpair *b, XLpair *c)
{
#ifdef XL_SIMD
	XLsimd4si mask[2] = { { 1, 0, 2, 3 }, { 1, 0, 2, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_PAIR_SIMD(b), mask[0]);
	simd[1] = __builtin_shuffle(XL_PAIR_SIMD(c), mask[1]);
	simd[2] = __builtin_shuffle(XL_PAIR_SIMD(b), mask[1]);
	simd[3] = __builtin_shuffle(XL_PAIR_SIMD(c), mask[0]);
	XL_PAIR_SIMD(a) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XL_PAIR_X(a) = XL_PAIR_Y(b) * XL_REAL(1) - XL_REAL(1) * XL_PAIR_Y(c);
	XL_PAIR_Y(a) = XL_REAL(1) * XL_PAIR_X(c) - XL_PAIR_X(b) * XL_REAL(1);
#endif
	return a;
}

xlPairArrayOpPair(Min, Min);
xlPairArrayAssignOpPairPair(AssignMin, Min);

xlPairArrayOpPair(Max, Max);
xlPairArrayAssignOpPairPair(AssignMax, Max);

xlPairArrayOpRealReal(ClampReal, Clamp);
xlPairArrayAssignOpPairRealReal(AssignClampReal, Clamp);
xlPairArrayOpPairPair(Clamp, Clamp);
xlPairArrayAssignOpPairPairPair(AssignClamp, Clamp);

xlPairArrayAssignNoneOpRealReal(AssignRandRangeReal, RandRange);
xlPairArrayAssignNoneOpPairPair(AssignRandRange, RandRange);

XLpair *
xlPairRotate(XLpair *a, XLpair *axis, XLreal angle)
{
	XLmatrix m;
	XLvector v;
	xlVectorAssignReals(&v, XL_PAIR_X(axis), XL_PAIR_Y(axis), XL_REAL(0));
	xlMatrixAssignRotation(&m, &v, angle);
	return xlPairMultMatrix(a, &m);
}

XLpair *
xlPairAssignRotate(XLpair *a, XLpair *b, XLpair *axis, XLreal angle)
{
	XLmatrix m;
	XLvector v;
	xlVectorAssignReals(&v, XL_PAIR_X(axis), XL_PAIR_Y(axis), XL_REAL(0));
	xlMatrixAssignRotation(&m, &v, angle);
	return xlPairAssignMultMatrix(a, b, &m);
}

xlPairOpPairReal(Lerp, Lerp);
xlPairAssignOpPairPairReal(AssignLerp, Lerp);

xlPairOpPairPairReal(QuadBezier, QuadBezier);
xlPairAssignOpPairPairPairReal(AssignQuadBezier, QuadBezier);

xlPairOpPairPairPairReal(CubicBezier, CubicBezier);
xlPairAssignOpPairPairPairPairReal(AssignCubicBezier, CubicBezier);

#define _xlPairInit(e, p) \
	xlPair ## p = &_xlPair ## p; \
	xlPairAssign ## p(xlPair ## p);

void
xlPairInit()
{
	xlPairsForEach(_xlPairInit)
}

#undef _xlPairInit

void
xlPairFini()
{
}

#undef xlPairAssignOpPairPairPairPairReal
#undef xlPairOpPairPairPairReal
#undef xlPairAssignOpPairPairPairReal
#undef xlPairOpPairPairReal
#undef xlPairAssignOpPairPairReal
#undef xlPairOpPairReal
#undef xlPairAssignOpPairMatrix
#undef xlPairOpMatrix
#undef xlPairAssignOpPairPair
#undef xlPairOpPair
#undef xlPairAssignOpPairReal
#undef xlPairOpReal
#undef xlPairAssignOpPair
#undef xlPairOp
#undef xlPairArrayAssignOpPairPairPair
#undef xlPairArrayOpPairPair
#undef xlPairArrayAssignOpPairRealReal
#undef xlPairArrayOpRealReal
#undef xlPairArrayAssignOpPairPair
#undef xlPairArrayOpPair
#undef xlPairArrayBooleanOpPair
#undef xlPairArrayAssignOpPair
#undef xlPairArrayOp
