/* http://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html */

#include "XL/xlPoint.h"
#include "XL/xl.h"

#define xlPointArrayAssignNoneOp(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(); \
		XL_POINT_Y(a) = xlReal ## Op(); \
		XL_POINT_Z(a) = xlReal ## Op(); \
		return a; \
	}
#define xlPointArrayOp(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(a)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(a)); \
		return a; \
	}
#define xlPointArrayAssignOpPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b)); \
		return a; \
	}
#define xlPointArrayBooleanOpPoint(Name, Op) \
	XLboolean \
	xlPoint ## Name(XLpoint *a, XLpoint *b) \
	{ \
		return \
			xlReal ## Op(XL_POINT_X(a), XL_POINT_X(b)) && \
			xlReal ## Op(XL_POINT_Y(a), XL_POINT_Y(b)) && \
			xlReal ## Op(XL_POINT_Z(a), XL_POINT_Z(b)); \
	}
#define xlPointArrayOpPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a), XL_POINT_X(b)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(a), XL_POINT_Y(b)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(a), XL_POINT_Z(b)); \
		return a; \
	}
#define xlPointArrayAssignOpPointPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b), XL_POINT_X(c)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b), XL_POINT_Y(c)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b), XL_POINT_Z(c)); \
		return a; \
	}
#define xlPointArrayAssignNoneOpRealReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLreal b, XLreal c) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(b, c); \
		XL_POINT_Y(a) = xlReal ## Op(b, c); \
		XL_POINT_Z(a) = xlReal ## Op(b, c); \
		return a; \
	}
#define xlPointArrayAssignNoneOpPointPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b), XL_POINT_X(c)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b), XL_POINT_Y(c)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b), XL_POINT_Z(c)); \
		return a; \
	}
#define xlPointArrayOpRealReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLreal b, XLreal c) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a), b, c); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(a), b, c); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(a), b, c); \
		return a; \
	}
#define xlPointArrayAssignOpPointRealReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLreal c, XLreal d) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b), c, d); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b), c, d); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b), c, d); \
		return a; \
	}
#define xlPointArrayOpPointPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a), XL_POINT_X(b), XL_POINT_X(c)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(a), XL_POINT_Y(b), XL_POINT_Y(c)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(a), XL_POINT_Z(b), XL_POINT_Z(c)); \
		return a; \
	}
#define xlPointArrayAssignOpPointPointPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b), XL_POINT_X(c), XL_POINT_X(d)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b), XL_POINT_Y(c), XL_POINT_Y(d)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b), XL_POINT_Z(c), XL_POINT_Z(d)); \
		return a; \
	}

#ifdef XL_SIMD
#define xlPointOp(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(a)); \
		return a; \
	}
#define xlPointAssignOpPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(b)); \
		return a; \
	}
#define xlPointOpReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLreal r) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op ## Real(XL_POINT_SIMD(a), r); \
		return a; \
	}
#define xlPointAssignOpPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLreal r) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op ## Real(XL_POINT_SIMD(b), r); \
		return a; \
	}
#define xlPointOpPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(a), XL_POINT_SIMD(b)); \
		return a; \
	}
#define xlPointAssignOpPointPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(b), XL_POINT_SIMD(c)); \
		return a; \
	}
#define xlPointOpMatrix(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLmatrix *b) \
	{ \
		XLsimd4sr simd[4] = { \
			{ XL_MATRIX_SIMD(b)[0], XL_MATRIX_SIMD(b)[1], XL_MATRIX_SIMD(b)[2], XL_MATRIX_SIMD(b)[3] }, \
			{ XL_MATRIX_SIMD(b)[4], XL_MATRIX_SIMD(b)[5], XL_MATRIX_SIMD(b)[6], XL_MATRIX_SIMD(b)[7] }, \
			{ XL_MATRIX_SIMD(b)[8], XL_MATRIX_SIMD(b)[9], XL_MATRIX_SIMD(b)[10], XL_MATRIX_SIMD(b)[11] }, \
			{ XL_MATRIX_SIMD(b)[12], XL_MATRIX_SIMD(b)[13], XL_MATRIX_SIMD(b)[14], XL_MATRIX_SIMD(b)[15] } \
		}; \
		simd[0] = xlReal ## Op ## Simd4sr(XL_POINT_X(a), simd[0]); \
		simd[1] = xlReal ## Op ## Simd4sr(XL_POINT_Y(a), simd[1]); \
		simd[2] = xlReal ## Op ## Simd4sr(XL_POINT_Z(a), simd[2]); \
		simd[3] = xlReal ## Op ## Simd4sr(XL_REAL(1), simd[3]); \
		XL_POINT_SIMD(a) = simd[0] + simd[1] + simd[2] + simd[3]; \
		return a; \
	}
#define xlPointAssignOpPointMatrix(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLmatrix *c) \
	{ \
		XLsimd4sr simd[4] = { \
			{ XL_MATRIX_SIMD(c)[0], XL_MATRIX_SIMD(c)[1], XL_MATRIX_SIMD(c)[2], XL_MATRIX_SIMD(c)[3] }, \
			{ XL_MATRIX_SIMD(c)[4], XL_MATRIX_SIMD(c)[5], XL_MATRIX_SIMD(c)[6], XL_MATRIX_SIMD(c)[7] }, \
			{ XL_MATRIX_SIMD(c)[8], XL_MATRIX_SIMD(c)[9], XL_MATRIX_SIMD(c)[10], XL_MATRIX_SIMD(c)[11] }, \
			{ XL_MATRIX_SIMD(c)[12], XL_MATRIX_SIMD(c)[13], XL_MATRIX_SIMD(c)[14], XL_MATRIX_SIMD(c)[15] } \
		}; \
		simd[0] = xlReal ## Op ## Simd4sr(XL_POINT_X(b), simd[0]); \
		simd[1] = xlReal ## Op ## Simd4sr(XL_POINT_Y(b), simd[1]); \
		simd[2] = xlReal ## Op ## Simd4sr(XL_POINT_Z(b), simd[2]); \
		simd[3] = xlReal ## Op ## Simd4sr(XL_REAL(1), simd[3]); \
		XL_POINT_SIMD(a) = simd[0] + simd[1] + simd[2] + simd[3]; \
		return a; \
	}
#define xlPointOpPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLreal r) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(a), XL_POINT_SIMD(b), r); \
		return a; \
	}
#define xlPointAssignOpPointPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLreal r) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(b), XL_POINT_SIMD(c), r); \
		return a; \
	}
#define xlPointOpPointPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLreal r) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(a), XL_POINT_SIMD(b), XL_POINT_SIMD(c), r); \
		return a; \
	}
#define xlPointAssignOpPointPointPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d, XLreal r) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(b), XL_POINT_SIMD(c), XL_POINT_SIMD(d), r); \
		return a; \
	}
#define xlPointOpPointPointPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d, XLreal r) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(a), XL_POINT_SIMD(b), XL_POINT_SIMD(c), XL_POINT_SIMD(d), r); \
		return a; \
	}
#define xlPointAssignOpPointPointPointPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d, XLpoint *e, XLreal r) \
	{ \
		XL_POINT_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(b), XL_POINT_SIMD(c), XL_POINT_SIMD(d), XL_POINT_SIMD(e), r); \
		return a; \
	}
#else
#define xlPointOp(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(a)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(a)); \
		return a; \
	}
#define xlPointAssignOpPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b)); \
		return a; \
	}
#define xlPointOpReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLreal r) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a), r); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(a), r); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(a), r); \
		return a; \
	}
#define xlPointAssignOpPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLreal r) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b), r); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b), r); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b), r); \
		return a; \
	}
#define xlPointOpPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a), XL_POINT_X(b)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(a), XL_POINT_Y(b)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(a), XL_POINT_Z(b)); \
		return a; \
	}
#define xlPointAssignOpPointPoint(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b), XL_POINT_X(c)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b), XL_POINT_Y(c)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b), XL_POINT_Z(c)); \
		return a; \
	}
#define xlPointOpMatrix(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLmatrix *b) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a), XL_MATRIX_XX(b)) + xlReal ## Op(XL_POINT_Y(a), XL_MATRIX_XY(b)) + xlReal ## Op(XL_POINT_Z(a), XL_MATRIX_XZ(b)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_XW(b)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_X(a), XL_MATRIX_YX(b)) + xlReal ## Op(XL_POINT_Y(a), XL_MATRIX_YY(b)) + xlReal ## Op(XL_POINT_Z(a), XL_MATRIX_YZ(b)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_YW(b)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_X(a), XL_MATRIX_ZX(b)) + xlReal ## Op(XL_POINT_Y(a), XL_MATRIX_ZY(b)) + xlReal ## Op(XL_POINT_Z(a), XL_MATRIX_ZZ(b)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_ZW(b)); \
		return a; \
	}
#define xlPointAssignOpPointMatrix(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLmatrix *c) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b), XL_MATRIX_XX(c)) + xlReal ## Op(XL_POINT_Y(b), XL_MATRIX_XY(c)) + xlReal ## Op(XL_POINT_Z(b), XL_MATRIX_XZ(c)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_XW(c)); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_X(b), XL_MATRIX_YX(c)) + xlReal ## Op(XL_POINT_Y(b), XL_MATRIX_YY(c)) + xlReal ## Op(XL_POINT_Z(b), XL_MATRIX_YZ(c)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_YW(c)); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_X(b), XL_MATRIX_ZX(c)) + xlReal ## Op(XL_POINT_Y(b), XL_MATRIX_ZY(c)) + xlReal ## Op(XL_POINT_Z(b), XL_MATRIX_ZZ(c)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_ZW(c)); \
		return a; \
	}
#define xlPointOpPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLreal r) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a), XL_POINT_X(b), r); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(a), XL_POINT_Y(b), r); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(a), XL_POINT_Z(b), r); \
		return a; \
	}
#define xlPointAssignOpPointPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLreal r) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b), XL_POINT_X(c), r); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b), XL_POINT_Y(c), r); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b), XL_POINT_Z(c), r); \
		return a; \
	}
#define xlPointOpPointPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLreal r) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a), XL_POINT_X(b), XL_POINT_X(c), r); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(a), XL_POINT_Y(b), XL_POINT_Y(c), r); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(a), XL_POINT_Z(b), XL_POINT_Z(c), r); \
		return a; \
	}
#define xlPointAssignOpPointPointPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d, XLreal r) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b), XL_POINT_X(c), XL_POINT_X(d), r); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b), XL_POINT_Y(c), XL_POINT_Y(d), r); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b), XL_POINT_Z(c), XL_POINT_Z(d), r); \
		return a; \
	}
#define xlPointOpPointPointPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d, XLreal r) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(a), XL_POINT_X(b), XL_POINT_X(c), XL_POINT_X(d), r); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(a), XL_POINT_Y(b), XL_POINT_Y(c), XL_POINT_Y(d), r); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(a), XL_POINT_Z(b), XL_POINT_Z(c), XL_POINT_Z(d), r); \
		return a; \
	}
#define xlPointAssignOpPointPointPointPointReal(Name, Op) \
	XLpoint * \
	xlPoint ## Name(XLpoint *a, XLpoint *b, XLpoint *c, XLpoint *d, XLpoint *e, XLreal r) \
	{ \
		XL_POINT_X(a) = xlReal ## Op(XL_POINT_X(b), XL_POINT_X(c), XL_POINT_X(d), XL_POINT_X(e), r); \
		XL_POINT_Y(a) = xlReal ## Op(XL_POINT_Y(b), XL_POINT_Y(c), XL_POINT_Y(d), XL_POINT_Y(e), r); \
		XL_POINT_Z(a) = xlReal ## Op(XL_POINT_Z(b), XL_POINT_Z(c), XL_POINT_Z(d), XL_POINT_Z(e), r); \
		return a; \
	}
#endif

XLpoint *
xlPointAlloc(void)
{
	XLpoint *a;
#ifdef XL_SIMD
	a = xlSimdAligned4srAlloc(sizeof(XLpoint));
#else
	a = xlMemoryAlloc(sizeof(XLpoint));
#endif
	return a;
}

#define _xlPoint(v, x, y, z) \
	static \
	XLpoint \
	_xlPoint ## v; \
	\
	XLpoint \
	*xlPoint ## v; \
	\
	XLpoint * \
	xlPointAssign ## v(XLpoint *a) \
	{ \
		return xlPointAssignReals(a, x, y, z); \
	} 

_xlPoint(Default, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlPoint(NegDefault, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlPoint(Zero, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlPoint(Half, XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5));
_xlPoint(NegHalf, XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5));
_xlPoint(One, XL_REAL(1), XL_REAL(1), XL_REAL(1));
_xlPoint(NegOne, XL_REAL(-1), XL_REAL(-1), XL_REAL(-1));
_xlPoint(Double, XL_REAL(2), XL_REAL(2), XL_REAL(2));
_xlPoint(NegDouble, XL_REAL(-2), XL_REAL(-2), XL_REAL(-2));
_xlPoint(X, XL_REAL(1), XL_REAL(0), XL_REAL(0));
_xlPoint(NegX, XL_REAL(-1), XL_REAL(0), XL_REAL(0));
_xlPoint(Y, XL_REAL(0), XL_REAL(1), XL_REAL(0));
_xlPoint(NegY, XL_REAL(0), XL_REAL(-1), XL_REAL(0));
_xlPoint(Z, XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlPoint(NegZ, XL_REAL(0), XL_REAL(0), XL_REAL(-1));
_xlPoint(TMP, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlPoint(TMP1, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlPoint(TMP2, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlPoint(TMP3, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlPoint(TMP4, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlPoint(Center, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlPoint(Front, XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlPoint(Back, XL_REAL(0), XL_REAL(0), XL_REAL(-1));
_xlPoint(Right, XL_REAL(1), XL_REAL(0), XL_REAL(0));
_xlPoint(Left, XL_REAL(-1), XL_REAL(0), XL_REAL(0));
_xlPoint(Up, XL_REAL(0), XL_REAL(1), XL_REAL(0));
_xlPoint(Down, XL_REAL(0), XL_REAL(-1), XL_REAL(0));
_xlPoint(FrontRight, XL_REAL(1), XL_REAL(0), XL_REAL(1));
_xlPoint(FrontLeft, XL_REAL(-1), XL_REAL(0), XL_REAL(1));
_xlPoint(FrontUp, XL_REAL(0), XL_REAL(1), XL_REAL(1));
_xlPoint(FrontDown, XL_REAL(0), XL_REAL(-1), XL_REAL(1));
_xlPoint(BackRight, XL_REAL(1), XL_REAL(0), XL_REAL(-1));
_xlPoint(BackLeft, XL_REAL(-1), XL_REAL(0), XL_REAL(-1));
_xlPoint(BackUp, XL_REAL(0), XL_REAL(1), XL_REAL(-1));
_xlPoint(BackDown, XL_REAL(0), XL_REAL(-1), XL_REAL(-1));
_xlPoint(RightUp, XL_REAL(1), XL_REAL(1), XL_REAL(0));
_xlPoint(RightDown, XL_REAL(1), XL_REAL(-1), XL_REAL(0));
_xlPoint(LeftUp, XL_REAL(-1), XL_REAL(1), XL_REAL(0));
_xlPoint(LeftDown, XL_REAL(-1), XL_REAL(-1), XL_REAL(0));
_xlPoint(FrontRightUp, XL_REAL(1), XL_REAL(1), XL_REAL(1));
_xlPoint(FrontRightDown, XL_REAL(1), XL_REAL(-1), XL_REAL(1));
_xlPoint(FrontLeftUp, XL_REAL(-1), XL_REAL(1), XL_REAL(1));
_xlPoint(FrontLeftDown, XL_REAL(-1), XL_REAL(-1), XL_REAL(1));
_xlPoint(BackRightUp, XL_REAL(1), XL_REAL(1), XL_REAL(-1));
_xlPoint(BackRightDown, XL_REAL(1), XL_REAL(-1), XL_REAL(-1));
_xlPoint(BackLeftUp, XL_REAL(-1), XL_REAL(1), XL_REAL(-1));
_xlPoint(BackLeftDown, XL_REAL(-1), XL_REAL(-1), XL_REAL(-1));
_xlPoint(Origin, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlPoint(North, XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlPoint(South, XL_REAL(0), XL_REAL(0), XL_REAL(-1));
_xlPoint(East, XL_REAL(1), XL_REAL(0), XL_REAL(0));
_xlPoint(West, XL_REAL(-1), XL_REAL(0), XL_REAL(0));
_xlPoint(Sky, XL_REAL(0), XL_REAL(1), XL_REAL(0));
_xlPoint(Ground, XL_REAL(0), XL_REAL(-1), XL_REAL(0));
_xlPoint(NorthEast, XL_REAL(1), XL_REAL(0), XL_REAL(1));
_xlPoint(NorthWest, XL_REAL(-1), XL_REAL(0), XL_REAL(1));
_xlPoint(NorthSky, XL_REAL(0), XL_REAL(1), XL_REAL(1));
_xlPoint(NorthGround, XL_REAL(0), XL_REAL(-1), XL_REAL(1));
_xlPoint(SouthEast, XL_REAL(1), XL_REAL(0), XL_REAL(-1));
_xlPoint(SouthWest, XL_REAL(-1), XL_REAL(0), XL_REAL(-1));
_xlPoint(SouthSky, XL_REAL(0), XL_REAL(1), XL_REAL(-1));
_xlPoint(SouthGround, XL_REAL(0), XL_REAL(-1), XL_REAL(-1));
_xlPoint(EastSky, XL_REAL(1), XL_REAL(1), XL_REAL(0));
_xlPoint(EastGround, XL_REAL(1), XL_REAL(-1), XL_REAL(0));
_xlPoint(WestSky, XL_REAL(-1), XL_REAL(1), XL_REAL(0));
_xlPoint(WestGround, XL_REAL(-1), XL_REAL(-1), XL_REAL(0));
_xlPoint(NorthEastSky, XL_REAL(1), XL_REAL(1), XL_REAL(1));
_xlPoint(NorthEastGround, XL_REAL(1), XL_REAL(-1), XL_REAL(1));
_xlPoint(NorthWestSky, XL_REAL(-1), XL_REAL(1), XL_REAL(1));
_xlPoint(NorthWestGround, XL_REAL(-1), XL_REAL(-1), XL_REAL(1));
_xlPoint(SouthEastSky, XL_REAL(1), XL_REAL(1), XL_REAL(-1));
_xlPoint(SouthEastGround, XL_REAL(1), XL_REAL(-1), XL_REAL(-1));
_xlPoint(SouthWestSky, XL_REAL(-1), XL_REAL(1), XL_REAL(-1));
_xlPoint(SouthWestGround, XL_REAL(-1), XL_REAL(-1), XL_REAL(-1));

#undef _xlPoint

XLpoint *
xlPointAssignArray(XLpoint *a, XLreal *array)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { array[0], array[1], array[2], XL_REAL(1) };
	XL_POINT_SIMD(a) = simd;
#else
	xlRealCopy(XL_POINT_ARRAY(a), array, 3);
#endif
	return a;
}

XLpoint *
xlPointAssignReals(XLpoint *a, XLreal x, XLreal y, XLreal z)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { x, y, z, XL_REAL(1) };
	XL_POINT_SIMD(a) = simd;
#else
	XL_POINT_X(a) = x;
	XL_POINT_Y(a) = y;
	XL_POINT_Z(a) = z;
#endif
	return a;
}

xlPointArrayAssignNoneOp(AssignRand, Rand);

XLpoint *
xlPointSwizzle(XLpoint *a, XLint x, XLint y, XLint z)
{
#ifdef XL_SIMD
	XLsimd4si mask = { x, y, z, 3 };
	XL_POINT_SIMD(a) = __builtin_shuffle(XL_POINT_SIMD(a), mask);
#else
	XLreal data[3];
	data[0] = XL_POINT_ARRAY(a)[x];
	data[1] = XL_POINT_ARRAY(a)[y];
	data[2] = XL_POINT_ARRAY(a)[z];
	xlRealCopy(XL_POINT_ARRAY(a), data, 3);
#endif
	return a;
}

XLpoint *
xlPointAssignSwizzle(XLpoint *a, XLpoint *b, XLint x, XLint y, XLint z)
{
#ifdef XL_SIMD
	XLsimd4si mask = { x, y, z, 3 };
	XL_POINT_SIMD(a) = __builtin_shuffle(XL_POINT_SIMD(b), mask);
#else
	XL_POINT_X(a) = XL_POINT_ARRAY(b)[x];
	XL_POINT_Y(a) = XL_POINT_ARRAY(b)[y];
	XL_POINT_Z(a) = XL_POINT_ARRAY(b)[z];
#endif
	return a;
}

XLpoint *
xlPointAssignSwizzleMatrix(XLpoint *a, XLmatrix *b, XLint x, XLint y, XLint z)
{
	XL_POINT_X(a) = XL_MATRIX_ARRAY(b)[x];
	XL_POINT_Y(a) = XL_MATRIX_ARRAY(b)[y];
	XL_POINT_Z(a) = XL_MATRIX_ARRAY(b)[z];
	return a;
}

XLpoint *
xlPointAssignMatrixForward(XLpoint *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_ZX(b), XL_MATRIX_ZY(b), XL_MATRIX_ZZ(b), XL_REAL(1) };
	XL_POINT_SIMD(a) = -simd;
#else
	XL_POINT_X(a) = -XL_MATRIX_ZX(b);
	XL_POINT_Y(a) = -XL_MATRIX_ZY(b);
	XL_POINT_Z(a) = -XL_MATRIX_ZZ(b);
#endif
	return a;
}

XLpoint *
xlPointAssignMatrixUp(XLpoint *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_YX(b), XL_MATRIX_YY(b), XL_MATRIX_YZ(b), XL_REAL(1) };
	XL_POINT_SIMD(a) = simd;
#else
	XL_POINT_X(a) = XL_MATRIX_YX(b);
	XL_POINT_Y(a) = XL_MATRIX_YY(b);
	XL_POINT_Z(a) = XL_MATRIX_YZ(b);
#endif
	return a;
}

XLpoint *
xlPointAssignMatrixRight(XLpoint *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XX(b), XL_MATRIX_XY(b), XL_MATRIX_XZ(b), XL_REAL(1) };
	XL_POINT_SIMD(a) = simd;
#else
	XL_POINT_X(a) = XL_MATRIX_XX(b);
	XL_POINT_Y(a) = XL_MATRIX_XY(b);
	XL_POINT_Z(a) = XL_MATRIX_XZ(b);
#endif
	return a;
}

XLpoint *
xlPointAssignMatrixPosition(XLpoint *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XW(b), XL_MATRIX_YW(b), XL_MATRIX_ZW(b), XL_REAL(1) };
	XL_POINT_SIMD(a) = simd;
#else
	XL_POINT_X(a) = XL_MATRIX_XW(b);
	XL_POINT_Y(a) = XL_MATRIX_YW(b);
	XL_POINT_Z(a) = XL_MATRIX_ZW(b);
#endif
	return a;
}

XLpoint *
xlPointAssignMatrixScalation(XLpoint *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XX(b), XL_MATRIX_YY(b), XL_MATRIX_ZZ(b), XL_REAL(1) };
	XL_POINT_SIMD(a) = simd;
#else
	XL_POINT_X(a) = XL_MATRIX_XX(b);
	XL_POINT_Y(a) = XL_MATRIX_YY(b);
	XL_POINT_Z(a) = XL_MATRIX_ZZ(b);
#endif
	return a;
}

XLpoint *
xlPointClear(XLpoint *a)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0) };
	XL_POINT_SIMD(a) = simd;
#else
	xlMemoryZero(a, sizeof(XLpoint));
#endif
	return a;
}

XLpoint *
xlPointCopy(XLpoint *a)
{
	XLpoint *b;

	b = xlPointAlloc();
	return xlPointAssignCopy(b, a);
}

XLpoint *
xlPointAssignCopy(XLpoint *a, XLpoint *b)
{
#ifdef XL_SIMD
	XL_POINT_SIMD(a) = XL_POINT_SIMD(b);
#else
	xlMemoryCopy(a, b, sizeof(XLpoint));
#endif
	return a;
}

xlPointOp(Comp, Comp);
xlPointAssignOpPoint(AssignComp, Comp);

xlPointOp(Neg, Neg);
xlPointAssignOpPoint(AssignNeg, Neg);

xlPointOp(Inc, Inc);
xlPointAssignOpPoint(AssignInc, Inc);

xlPointOp(Dec, Dec);
xlPointAssignOpPoint(AssignDec, Dec);

xlPointArrayOp(Abs, Abs);
xlPointArrayAssignOpPoint(AssignAbs, Abs);

XLreal
xlPointSquareNorm(XLpoint *a)
{
	return xlPointDot(a, a);
}

XLreal
xlPointNorm(XLpoint *a)
{
	return xlRealSquareRoot(xlPointSquareNorm(a));
}

XLpoint *
xlPointNormal(XLpoint *a)
{
	return xlPointMultReal(a, XL_REAL(1) / xlPointNorm(a));
}

XLpoint *
xlPointAssignNormal(XLpoint *a, XLpoint *b)
{
	return xlPointAssignMultReal(a, b, XL_REAL(1) / xlPointNorm(b));
}

xlPointArrayBooleanOpPoint(BooleanEqual, Equal);
xlPointOpPoint(PointEqual, Equal);
xlPointAssignOpPointPoint(PointAssignEqual, Equal);

xlPointArrayBooleanOpPoint(BooleanGreater, Greater);
xlPointOpPoint(PointGreater, Greater);
xlPointAssignOpPointPoint(PointAssignGreater, Greater);

xlPointArrayBooleanOpPoint(BooleanLesser, Lesser);
xlPointOpPoint(PointLesser, Lesser);
xlPointAssignOpPointPoint(PointAssignLesser, Lesser);

XLreal
xlPointAngle(XLpoint *a, XLpoint *b)
{
	return xlRealRadToDeg(xlRealArcCosine(xlPointDot(a, b) / (xlPointNorm(a) * xlPointNorm(b))));
}

XLreal
xlPointDot(XLpoint *a, XLpoint *b)
{
	XLreal r;
#ifdef XL_SIMD
	XLsimd4sr simd;
	simd = XL_POINT_SIMD(a) * XL_POINT_SIMD(b);
	r = simd[0] + simd[1] + simd[2];
#else
	r = XL_POINT_X(a) * XL_POINT_X(b) + XL_POINT_Y(a) * XL_POINT_Y(b) + XL_POINT_Z(a) * XL_POINT_Z(b);
#endif
	return r;
}

xlPointOpReal(AndReal, And);
xlPointAssignOpPointReal(AssignAndReal, And);
xlPointOpPoint(And, And);
xlPointAssignOpPointPoint(AssignAnd, And);

xlPointOpReal(OrReal, Or);
xlPointAssignOpPointReal(AssignOrReal, Or);
xlPointOpPoint(Or, Or);
xlPointAssignOpPointPoint(AssignOr, Or);

xlPointOpReal(XorReal, Xor);
xlPointAssignOpPointReal(AssignXorReal, Xor);
xlPointOpPoint(Xor, Xor);
xlPointAssignOpPointPoint(AssignXor, Xor);

xlPointOpReal(LShiftReal, LShift);
xlPointAssignOpPointReal(AssignLShiftReal, LShift);
xlPointOpPoint(LShift, LShift);
xlPointAssignOpPointPoint(AssignLShift, LShift);

xlPointOpReal(RShiftReal, RShift);
xlPointAssignOpPointReal(AssignRShiftReal, RShift);
xlPointOpPoint(RShift, RShift);
xlPointAssignOpPointPoint(AssignRShift, RShift);

xlPointOpReal(AddReal, Add);
xlPointAssignOpPointReal(AssignAddReal, Add);
xlPointOpPoint(Add, Add);
xlPointAssignOpPointPoint(AssignAdd, Add);

xlPointOpReal(SubReal, Sub);
xlPointAssignOpPointReal(AssignSubReal, Sub);
xlPointOpPoint(Sub, Sub);
xlPointAssignOpPointPoint(AssignSub, Sub);

xlPointOpReal(MultReal, Mult);
xlPointAssignOpPointReal(AssignMultReal, Mult);
xlPointOpPoint(Mult, Mult);
xlPointAssignOpPointPoint(AssignMult, Mult);
xlPointOpMatrix(MultMatrix, Mult);
xlPointAssignOpPointMatrix(AssignMultMatrix, Mult);

xlPointOpReal(DivReal, Div);
xlPointAssignOpPointReal(AssignDivReal, Div);
xlPointOpPoint(Div, Div);
xlPointAssignOpPointPoint(AssignDiv, Div);
xlPointOpMatrix(DivMatrix, Div);
xlPointAssignOpPointMatrix(AssignDivMatrix, Div);

xlPointOpReal(ModReal, Mod);
xlPointAssignOpPointReal(AssignModReal, Mod);
xlPointOpPoint(Mod, Mod);
xlPointAssignOpPointPoint(AssignMod, Mod);
xlPointOpMatrix(ModMatrix, Mod);
xlPointAssignOpPointMatrix(AssignModMatrix, Mod);

xlPointOpReal(InvDivReal, InvDiv);
xlPointAssignOpPointReal(AssignInvDivReal, InvDiv);
xlPointOpPoint(InvDiv, InvDiv);
xlPointAssignOpPointPoint(AssignInvDiv, InvDiv);
xlPointOpMatrix(InvDivMatrix, InvDiv);
xlPointAssignOpPointMatrix(AssignInvDivMatrix, InvDiv);

XLpoint *
xlPointCross(XLpoint *a, XLpoint *b)
{
#ifdef XL_SIMD
	XLsimd4si mask[2] = { { 1, 2, 0, 3 }, { 2, 0, 1, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_POINT_SIMD(a), mask[0]);
	simd[1] = __builtin_shuffle(XL_POINT_SIMD(b), mask[1]);
	simd[2] = __builtin_shuffle(XL_POINT_SIMD(a), mask[1]);
	simd[3] = __builtin_shuffle(XL_POINT_SIMD(b), mask[0]);
	XL_POINT_SIMD(a) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XLreal data[3];
	data[0] = XL_POINT_Y(a) * XL_POINT_Z(b) - XL_POINT_Z(a) * XL_POINT_Y(b);
	data[1] = XL_POINT_Z(a) * XL_POINT_X(b) - XL_POINT_X(a) * XL_POINT_Z(b);
	data[2] = XL_POINT_X(a) * XL_POINT_Y(b) - XL_POINT_Y(a) * XL_POINT_X(b);
	xlRealCopy(XL_POINT_ARRAY(a), data, 3);
#endif
	return a;
}

XLpoint *
xlPointAssignCross(XLpoint *a, XLpoint *b, XLpoint *c)
{
#ifdef XL_SIMD
	XLsimd4si mask[2] = { { 1, 2, 0, 3 }, { 2, 0, 1, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_POINT_SIMD(b), mask[0]);
	simd[1] = __builtin_shuffle(XL_POINT_SIMD(c), mask[1]);
	simd[2] = __builtin_shuffle(XL_POINT_SIMD(b), mask[1]);
	simd[3] = __builtin_shuffle(XL_POINT_SIMD(c), mask[0]);
	XL_POINT_SIMD(a) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XL_POINT_X(a) = XL_POINT_Y(b) * XL_POINT_Z(c) - XL_POINT_Z(b) * XL_POINT_Y(c);
	XL_POINT_Y(a) = XL_POINT_Z(b) * XL_POINT_X(c) - XL_POINT_X(b) * XL_POINT_Z(c);
	XL_POINT_Z(a) = XL_POINT_X(b) * XL_POINT_Y(c) - XL_POINT_Y(b) * XL_POINT_X(c);
#endif
	return a;
}

xlPointArrayOpPoint(Min, Min);
xlPointArrayAssignOpPointPoint(AssignMin, Min);

xlPointArrayOpPoint(Max, Max);
xlPointArrayAssignOpPointPoint(AssignMax, Max);

xlPointArrayOpRealReal(ClampReal, Clamp);
xlPointArrayAssignOpPointRealReal(AssignClampReal, Clamp);
xlPointArrayOpPointPoint(Clamp, Clamp);
xlPointArrayAssignOpPointPointPoint(AssignClamp, Clamp);

xlPointArrayAssignNoneOpRealReal(AssignRandRangeReal, RandRange);
xlPointArrayAssignNoneOpPointPoint(AssignRandRange, RandRange);

XLpoint *
xlPointRotate(XLpoint *a, XLvector *axis, XLreal angle)
{
	XLmatrix m;
	xlMatrixAssignRotation(&m, axis, angle);
	return xlPointMultMatrix(a, &m);
}

XLpoint *
xlPointAssignRotate(XLpoint *a, XLpoint *b, XLvector *axis, XLreal angle)
{
	XLmatrix m;
	xlMatrixAssignRotation(&m, axis, angle);
	return xlPointAssignMultMatrix(a, b, &m);
}

xlPointOpPointReal(Lerp, Lerp);
xlPointAssignOpPointPointReal(AssignLerp, Lerp);

xlPointOpPointPointReal(QuadBezier, QuadBezier);
xlPointAssignOpPointPointPointReal(AssignQuadBezier, QuadBezier);

xlPointOpPointPointPointReal(CubicBezier, CubicBezier);
xlPointAssignOpPointPointPointPointReal(AssignCubicBezier, CubicBezier);

#define _xlPointInit(e, v) \
	xlPoint ## v = &_xlPoint ## v; \
	xlPointAssign ## v(xlPoint ## v);

void
xlPointInit()
{
	xlPointsForEach(_xlPointInit)
}

#undef _xlPointInit

void
xlPointFini()
{
}

#undef xlPointAssignOpPointPointPointPointReal
#undef xlPointOpPointPointPointReal
#undef xlPointAssignOpPointPointPointReal
#undef xlPointOpPointPointReal
#undef xlPointAssignOpPointPointReal
#undef xlPointOpPointReal
#undef xlPointAssignOpPointMatrix
#undef xlPointOpMatrix
#undef xlPointAssignOpPointPoint
#undef xlPointOpPoint
#undef xlPointAssignOpPointReal
#undef xlPointOpReal
#undef xlPointAssignOpPoint
#undef xlPointOp
#undef xlPointArrayAssignOpPointPointPoint
#undef xlPointArrayOpPointPoint
#undef xlPointArrayAssignOpPointRealReal
#undef xlPointArrayOpRealReal
#undef xlPointArrayAssignOpPointPoint
#undef xlPointArrayOpPoint
#undef xlPointArrayBooleanOpPoint
#undef xlPointArrayAssignOpPoint
#undef xlPointArrayOp
