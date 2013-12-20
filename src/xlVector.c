/* http://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html */

#include "XL/xlVector.h"
#include "XL/xl.h"

#define xlVectorArrayAssignNoneOp(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(); \
		XL_VECTOR_Y(a) = xlReal ## Op(); \
		XL_VECTOR_Z(a) = xlReal ## Op(); \
		return a; \
	}
#define xlVectorArrayOp(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(a)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(a)); \
		return a; \
	}
#define xlVectorArrayAssignOpVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b)); \
		return a; \
	}
#define xlVectorArrayBooleanOpVector(Name, Op) \
	XLboolean \
	xlVector ## Name(XLvector *a, XLvector *b) \
	{ \
		return \
			xlReal ## Op(XL_VECTOR_X(a), XL_VECTOR_X(b)) && \
			xlReal ## Op(XL_VECTOR_Y(a), XL_VECTOR_Y(b)) && \
			xlReal ## Op(XL_VECTOR_Z(a), XL_VECTOR_Z(b)); \
	}
#define xlVectorArrayOpVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a), XL_VECTOR_X(b)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(a), XL_VECTOR_Y(b)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(a), XL_VECTOR_Z(b)); \
		return a; \
	}
#define xlVectorArrayAssignOpPointPoint(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLpoint *b, XLpoint *c) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_POINT_X(b), XL_POINT_X(c)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_POINT_Y(b), XL_POINT_Y(c)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_POINT_Z(b), XL_POINT_Z(c)); \
		return a; \
	}
#define xlVectorArrayAssignOpVectorVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b), XL_VECTOR_X(c)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b), XL_VECTOR_Y(c)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b), XL_VECTOR_Z(c)); \
		return a; \
	}
#define xlVectorArrayAssignNoneOpRealReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLreal b, XLreal c) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(b, c); \
		XL_VECTOR_Y(a) = xlReal ## Op(b, c); \
		XL_VECTOR_Z(a) = xlReal ## Op(b, c); \
		return a; \
	}
#define xlVectorArrayAssignNoneOpVectorVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b), XL_VECTOR_X(c)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b), XL_VECTOR_Y(c)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b), XL_VECTOR_Z(c)); \
		return a; \
	}
#define xlVectorArrayOpRealReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLreal b, XLreal c) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a), b, c); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(a), b, c); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(a), b, c); \
		return a; \
	}
#define xlVectorArrayAssignOpVectorRealReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLreal c, XLreal d) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b), c, d); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b), c, d); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b), c, d); \
		return a; \
	}
#define xlVectorArrayOpVectorVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a), XL_VECTOR_X(b), XL_VECTOR_X(c)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(a), XL_VECTOR_Y(b), XL_VECTOR_Y(c)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(a), XL_VECTOR_Z(b), XL_VECTOR_Z(c)); \
		return a; \
	}
#define xlVectorArrayAssignOpVectorVectorVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLvector *d) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b), XL_VECTOR_X(c), XL_VECTOR_X(d)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b), XL_VECTOR_Y(c), XL_VECTOR_Y(d)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b), XL_VECTOR_Z(c), XL_VECTOR_Z(d)); \
		return a; \
	}

#ifdef XL_SIMD
#define xlVectorOp(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(a)); \
		return a; \
	}
#define xlVectorAssignOpVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(b)); \
		return a; \
	}
#define xlVectorOpReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op ## Real(XL_VECTOR_SIMD(a), r); \
		return a; \
	}
#define xlVectorAssignOpVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op ## Real(XL_VECTOR_SIMD(b), r); \
		return a; \
	}
#define xlVectorOpVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(a), XL_VECTOR_SIMD(b)); \
		return a; \
	}
#define xlVectorAssignOpPointPoint(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLpoint *b, XLpoint *c) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_POINT_SIMD(b), XL_POINT_SIMD(c)); \
		return a; \
	}
#define xlVectorAssignOpVectorVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c)); \
		return a; \
	}
#define xlVectorOpMatrix(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLmatrix *b) \
	{ \
		XLsimd4sr simd[4] = { \
			{ XL_MATRIX_SIMD(b)[0], XL_MATRIX_SIMD(b)[1], XL_MATRIX_SIMD(b)[2], XL_MATRIX_SIMD(b)[3] }, \
			{ XL_MATRIX_SIMD(b)[4], XL_MATRIX_SIMD(b)[5], XL_MATRIX_SIMD(b)[6], XL_MATRIX_SIMD(b)[7] }, \
			{ XL_MATRIX_SIMD(b)[8], XL_MATRIX_SIMD(b)[9], XL_MATRIX_SIMD(b)[10], XL_MATRIX_SIMD(b)[11] }, \
			{ XL_MATRIX_SIMD(b)[12], XL_MATRIX_SIMD(b)[13], XL_MATRIX_SIMD(b)[14], XL_MATRIX_SIMD(b)[15] } \
		}; \
		simd[0] = xlReal ## Op ## Simd4sr(XL_VECTOR_X(a), simd[0]); \
		simd[1] = xlReal ## Op ## Simd4sr(XL_VECTOR_Y(a), simd[1]); \
		simd[2] = xlReal ## Op ## Simd4sr(XL_VECTOR_Z(a), simd[2]); \
		simd[3] = xlReal ## Op ## Simd4sr(XL_REAL(1), simd[3]); \
		XL_VECTOR_SIMD(a) = simd[0] + simd[1] + simd[2] + simd[3]; \
		return a; \
	}
#define xlVectorAssignOpVectorMatrix(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLmatrix *c) \
	{ \
		XLsimd4sr simd[4] = { \
			{ XL_MATRIX_SIMD(c)[0], XL_MATRIX_SIMD(c)[1], XL_MATRIX_SIMD(c)[2], XL_MATRIX_SIMD(c)[3] }, \
			{ XL_MATRIX_SIMD(c)[4], XL_MATRIX_SIMD(c)[5], XL_MATRIX_SIMD(c)[6], XL_MATRIX_SIMD(c)[7] }, \
			{ XL_MATRIX_SIMD(c)[8], XL_MATRIX_SIMD(c)[9], XL_MATRIX_SIMD(c)[10], XL_MATRIX_SIMD(c)[11] }, \
			{ XL_MATRIX_SIMD(c)[12], XL_MATRIX_SIMD(c)[13], XL_MATRIX_SIMD(c)[14], XL_MATRIX_SIMD(c)[15] } \
		}; \
		simd[0] = xlReal ## Op ## Simd4sr(XL_VECTOR_X(b), simd[0]); \
		simd[1] = xlReal ## Op ## Simd4sr(XL_VECTOR_Y(b), simd[1]); \
		simd[2] = xlReal ## Op ## Simd4sr(XL_VECTOR_Z(b), simd[2]); \
		simd[3] = xlReal ## Op ## Simd4sr(XL_REAL(1), simd[3]); \
		XL_VECTOR_SIMD(a) = simd[0] + simd[1] + simd[2] + simd[3]; \
		return a; \
	}
#define xlVectorOpVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(a), XL_VECTOR_SIMD(b), r); \
		return a; \
	}
#define xlVectorAssignOpVectorVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c), r); \
		return a; \
	}
#define xlVectorOpVectorVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(a), XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c), r); \
		return a; \
	}
#define xlVectorAssignOpVectorVectorVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLvector *d, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c), XL_VECTOR_SIMD(d), r); \
		return a; \
	}
#define xlVectorOpVectorVectorVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLvector *d, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(a), XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c), XL_VECTOR_SIMD(d), r); \
		return a; \
	}
#define xlVectorAssignOpVectorVectorVectorVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLvector *d, XLvector *e, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c), XL_VECTOR_SIMD(d), XL_VECTOR_SIMD(e), r); \
		return a; \
	}
#else
#define xlVectorOp(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(a)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(a)); \
		return a; \
	}
#define xlVectorAssignOpVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b)); \
		return a; \
	}
#define xlVectorOpReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLreal r) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a), r); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(a), r); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(a), r); \
		return a; \
	}
#define xlVectorAssignOpVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLreal r) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b), r); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b), r); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b), r); \
		return a; \
	}
#define xlVectorOpVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a), XL_VECTOR_X(b)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(a), XL_VECTOR_Y(b)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(a), XL_VECTOR_Z(b)); \
		return a; \
	}
#define xlVectorAssignOpPointPoint(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLpoint *b, XLpoint *c) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_POINT_X(b), XL_POINT_X(c)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_POINT_Y(b), XL_POINT_Y(c)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_POINT_Z(b), XL_POINT_Z(c)); \
		return a; \
	}
#define xlVectorAssignOpVectorVector(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b), XL_VECTOR_X(c)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b), XL_VECTOR_Y(c)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b), XL_VECTOR_Z(c)); \
		return a; \
	}
#define xlVectorOpMatrix(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLmatrix *b) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a), XL_MATRIX_XX(b)) + xlReal ## Op(XL_VECTOR_Y(a), XL_MATRIX_XY(b)) + xlReal ## Op(XL_VECTOR_Z(a), XL_MATRIX_XZ(b)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_XW(b)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_X(a), XL_MATRIX_YX(b)) + xlReal ## Op(XL_VECTOR_Y(a), XL_MATRIX_YY(b)) + xlReal ## Op(XL_VECTOR_Z(a), XL_MATRIX_YZ(b)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_YW(b)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_X(a), XL_MATRIX_ZX(b)) + xlReal ## Op(XL_VECTOR_Y(a), XL_MATRIX_ZY(b)) + xlReal ## Op(XL_VECTOR_Z(a), XL_MATRIX_ZZ(b)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_ZW(b)); \
		return a; \
	}
#define xlVectorAssignOpVectorMatrix(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLmatrix *c) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b), XL_MATRIX_XX(c)) + xlReal ## Op(XL_VECTOR_Y(b), XL_MATRIX_XY(c)) + xlReal ## Op(XL_VECTOR_Z(b), XL_MATRIX_XZ(c)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_XW(c)); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_X(b), XL_MATRIX_YX(c)) + xlReal ## Op(XL_VECTOR_Y(b), XL_MATRIX_YY(c)) + xlReal ## Op(XL_VECTOR_Z(b), XL_MATRIX_YZ(c)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_YW(c)); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_X(b), XL_MATRIX_ZX(c)) + xlReal ## Op(XL_VECTOR_Y(b), XL_MATRIX_ZY(c)) + xlReal ## Op(XL_VECTOR_Z(b), XL_MATRIX_ZZ(c)) + xlReal ## Op(XL_REAL(1), XL_MATRIX_ZW(c)); \
		return a; \
	}
#define xlVectorOpVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLreal r) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a), XL_VECTOR_X(b), r); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(a), XL_VECTOR_Y(b), r); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(a), XL_VECTOR_Z(b), r); \
		return a; \
	}
#define xlVectorAssignOpVectorVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLreal r) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b), XL_VECTOR_X(c), r); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b), XL_VECTOR_Y(c), r); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b), XL_VECTOR_Z(c), r); \
		return a; \
	}
#define xlVectorOpVectorVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLreal r) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a), XL_VECTOR_X(b), XL_VECTOR_X(c), r); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(a), XL_VECTOR_Y(b), XL_VECTOR_Y(c), r); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(a), XL_VECTOR_Z(b), XL_VECTOR_Z(c), r); \
		return a; \
	}
#define xlVectorAssignOpVectorVectorVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLvector *d, XLreal r) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b), XL_VECTOR_X(c), XL_VECTOR_X(d), r); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b), XL_VECTOR_Y(c), XL_VECTOR_Y(d), r); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b), XL_VECTOR_Z(c), XL_VECTOR_Z(d), r); \
		return a; \
	}
#define xlVectorOpVectorVectorVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLvector *d, XLreal r) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(a), XL_VECTOR_X(b), XL_VECTOR_X(c), XL_VECTOR_X(d), r); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(a), XL_VECTOR_Y(b), XL_VECTOR_Y(c), XL_VECTOR_Y(d), r); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(a), XL_VECTOR_Z(b), XL_VECTOR_Z(c), XL_VECTOR_Z(d), r); \
		return a; \
	}
#define xlVectorAssignOpVectorVectorVectorVectorReal(Name, Op) \
	XLvector * \
	xlVector ## Name(XLvector *a, XLvector *b, XLvector *c, XLvector *d, XLvector *e, XLreal r) \
	{ \
		XL_VECTOR_X(a) = xlReal ## Op(XL_VECTOR_X(b), XL_VECTOR_X(c), XL_VECTOR_X(d), XL_VECTOR_X(e), r); \
		XL_VECTOR_Y(a) = xlReal ## Op(XL_VECTOR_Y(b), XL_VECTOR_Y(c), XL_VECTOR_Y(d), XL_VECTOR_Y(e), r); \
		XL_VECTOR_Z(a) = xlReal ## Op(XL_VECTOR_Z(b), XL_VECTOR_Z(c), XL_VECTOR_Z(d), XL_VECTOR_Z(e), r); \
		return a; \
	}
#endif

XLvector *
xlVectorAlloc(void)
{
	XLvector *a;
#ifdef XL_SIMD
	a = xlSimdAligned4srAlloc(sizeof(XLvector));
#else
	a = xlMemoryAlloc(sizeof(XLvector));
#endif
	return a;
}

#define _xlVector(v, x, y, z) \
	static \
	XLvector \
	_xlVector ## v; \
	\
	XLvector \
	*xlVector ## v; \
	\
	XLvector * \
	xlVectorAssign ## v(XLvector *a) \
	{ \
		return xlVectorAssignReals(a, x, y, z); \
	} 

_xlVector(Default, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlVector(NegDefault, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlVector(Zero, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlVector(Half, XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5));
_xlVector(NegHalf, XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5));
_xlVector(One, XL_REAL(1), XL_REAL(1), XL_REAL(1));
_xlVector(NegOne, XL_REAL(-1), XL_REAL(-1), XL_REAL(-1));
_xlVector(Double, XL_REAL(2), XL_REAL(2), XL_REAL(2));
_xlVector(NegDouble, XL_REAL(-2), XL_REAL(-2), XL_REAL(-2));
_xlVector(X, XL_REAL(1), XL_REAL(0), XL_REAL(0));
_xlVector(NegX, XL_REAL(-1), XL_REAL(0), XL_REAL(0));
_xlVector(Y, XL_REAL(0), XL_REAL(1), XL_REAL(0));
_xlVector(NegY, XL_REAL(0), XL_REAL(-1), XL_REAL(0));
_xlVector(Z, XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlVector(NegZ, XL_REAL(0), XL_REAL(0), XL_REAL(-1));
_xlVector(TMP, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlVector(TMP1, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlVector(TMP2, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlVector(TMP3, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlVector(TMP4, XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlVector(Front, XL_REAL(0.000000), XL_REAL(0.000000), XL_REAL(1.000000));
_xlVector(Back, XL_REAL(0.000000), XL_REAL(0.000000), XL_REAL(-1.000000));
_xlVector(Right, XL_REAL(1.000000), XL_REAL(0.000000), XL_REAL(0.000000));
_xlVector(Left, XL_REAL(-1.000000), XL_REAL(0.000000), XL_REAL(0.000000));
_xlVector(Up, XL_REAL(0.000000), XL_REAL(1.000000), XL_REAL(0.000000));
_xlVector(Down, XL_REAL(0.000000), XL_REAL(-1.000000), XL_REAL(0.000000));
_xlVector(FrontRight, XL_REAL(0.707107), XL_REAL(0.000000), XL_REAL(0.707107));
_xlVector(FrontLeft, XL_REAL(-0.707107), XL_REAL(0.000000), XL_REAL(0.707107));
_xlVector(FrontUp, XL_REAL(0.000000), XL_REAL(0.707107), XL_REAL(0.707107));
_xlVector(FrontDown, XL_REAL(0.000000), XL_REAL(-0.707107), XL_REAL(0.707107));
_xlVector(BackRight, XL_REAL(0.707107), XL_REAL(0.000000), XL_REAL(-0.707107));
_xlVector(BackLeft, XL_REAL(-0.707107), XL_REAL(0.000000), XL_REAL(-0.707107));
_xlVector(BackUp, XL_REAL(0.000000), XL_REAL(0.707107), XL_REAL(-0.707107));
_xlVector(BackDown, XL_REAL(0.000000), XL_REAL(-0.707107), XL_REAL(-0.707107));
_xlVector(RightUp, XL_REAL(0.707107), XL_REAL(0.707107), XL_REAL(0.000000));
_xlVector(RightDown, XL_REAL(0.707107), XL_REAL(-0.707107), XL_REAL(0.000000));
_xlVector(LeftUp, XL_REAL(-0.707107), XL_REAL(0.707107), XL_REAL(0.000000));
_xlVector(LeftDown, XL_REAL(-0.707107), XL_REAL(-0.707107), XL_REAL(0.000000));
_xlVector(FrontRightUp, XL_REAL(0.577350), XL_REAL(0.577350), XL_REAL(0.577350));
_xlVector(FrontRightDown, XL_REAL(0.577350), XL_REAL(-0.577350), XL_REAL(0.577350));
_xlVector(FrontLeftUp, XL_REAL(-0.577350), XL_REAL(0.577350), XL_REAL(0.577350));
_xlVector(FrontLeftDown, XL_REAL(-0.577350), XL_REAL(-0.577350), XL_REAL(0.577350));
_xlVector(BackRightUp, XL_REAL(0.577350), XL_REAL(0.577350), XL_REAL(-0.577350));
_xlVector(BackRightDown, XL_REAL(0.577350), XL_REAL(-0.577350), XL_REAL(-0.577350));
_xlVector(BackLeftUp, XL_REAL(-0.577350), XL_REAL(0.577350), XL_REAL(-0.577350));
_xlVector(BackLeftDown, XL_REAL(-0.577350), XL_REAL(-0.577350), XL_REAL(-0.577350));
_xlVector(North, XL_REAL(0.000000), XL_REAL(0.000000), XL_REAL(1.000000));
_xlVector(South, XL_REAL(0.000000), XL_REAL(0.000000), XL_REAL(-1.000000));
_xlVector(East, XL_REAL(1.000000), XL_REAL(0.000000), XL_REAL(0.000000));
_xlVector(West, XL_REAL(-1.000000), XL_REAL(0.000000), XL_REAL(0.000000));
_xlVector(Sky, XL_REAL(0.000000), XL_REAL(1.000000), XL_REAL(0.000000));
_xlVector(Ground, XL_REAL(0.000000), XL_REAL(-1.000000), XL_REAL(0.000000));
_xlVector(NorthEast, XL_REAL(0.707107), XL_REAL(0.000000), XL_REAL(0.707107));
_xlVector(NorthWest, XL_REAL(-0.707107), XL_REAL(0.000000), XL_REAL(0.707107));
_xlVector(NorthSky, XL_REAL(0.000000), XL_REAL(0.707107), XL_REAL(0.707107));
_xlVector(NorthGround, XL_REAL(0.000000), XL_REAL(-0.707107), XL_REAL(0.707107));
_xlVector(SouthEast, XL_REAL(0.707107), XL_REAL(0.000000), XL_REAL(-0.707107));
_xlVector(SouthWest, XL_REAL(-0.707107), XL_REAL(0.000000), XL_REAL(-0.707107));
_xlVector(SouthSky, XL_REAL(0.000000), XL_REAL(0.707107), XL_REAL(-0.707107));
_xlVector(SouthGround, XL_REAL(0.000000), XL_REAL(-0.707107), XL_REAL(-0.707107));
_xlVector(EastSky, XL_REAL(0.707107), XL_REAL(0.707107), XL_REAL(0.000000));
_xlVector(EastGround, XL_REAL(0.707107), XL_REAL(-0.707107), XL_REAL(0.000000));
_xlVector(WestSky, XL_REAL(-0.707107), XL_REAL(0.707107), XL_REAL(0.000000));
_xlVector(WestGround, XL_REAL(-0.707107), XL_REAL(-0.707107), XL_REAL(0.000000));
_xlVector(NorthEastSky, XL_REAL(0.577350), XL_REAL(0.577350), XL_REAL(0.577350));
_xlVector(NorthEastGround, XL_REAL(0.577350), XL_REAL(-0.577350), XL_REAL(0.577350));
_xlVector(NorthWestSky, XL_REAL(-0.577350), XL_REAL(0.577350), XL_REAL(0.577350));
_xlVector(NorthWestGround, XL_REAL(-0.577350), XL_REAL(-0.577350), XL_REAL(0.577350));
_xlVector(SouthEastSky, XL_REAL(0.577350), XL_REAL(0.577350), XL_REAL(-0.577350));
_xlVector(SouthEastGround, XL_REAL(0.577350), XL_REAL(-0.577350), XL_REAL(-0.577350));
_xlVector(SouthWestSky, XL_REAL(-0.577350), XL_REAL(0.577350), XL_REAL(-0.577350));
_xlVector(SouthWestGround, XL_REAL(-0.577350), XL_REAL(-0.577350), XL_REAL(-0.577350));

#undef _xlVector

XLvector *
xlVectorAssignArray(XLvector *a, XLreal *array)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { array[0], array[1], array[2], XL_REAL(1) };
	XL_VECTOR_SIMD(a) = simd;
#else
	xlRealCopy(XL_VECTOR_ARRAY(a), array, 3);
#endif
	return a;
}

XLvector *
xlVectorAssignReals(XLvector *a, XLreal x, XLreal y, XLreal z)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { x, y, z, XL_REAL(1) };
	XL_VECTOR_SIMD(a) = simd;
#else
	XL_VECTOR_X(a) = x;
	XL_VECTOR_Y(a) = y;
	XL_VECTOR_Z(a) = z;
#endif
	return a;
}

xlVectorArrayAssignNoneOp(AssignRand, Rand);

XLvector *
xlVectorSwizzle(XLvector *a, XLint x, XLint y, XLint z)
{
#ifdef XL_SIMD
	XLsimd4si mask = { x, y, z, 3 };
	XL_VECTOR_SIMD(a) = __builtin_shuffle(XL_VECTOR_SIMD(a), mask);
#else
	XLreal data[3];
	data[0] = XL_VECTOR_ARRAY(a)[x];
	data[1] = XL_VECTOR_ARRAY(a)[y];
	data[2] = XL_VECTOR_ARRAY(a)[z];
	xlRealCopy(XL_VECTOR_ARRAY(a), data, 3);
#endif
	return a;
}

XLvector *
xlVectorAssignSwizzle(XLvector *a, XLvector *b, XLint x, XLint y, XLint z)
{
#ifdef XL_SIMD
	XLsimd4si mask = { x, y, z, 3 };
	XL_VECTOR_SIMD(a) = __builtin_shuffle(XL_VECTOR_SIMD(b), mask);
#else
	XL_VECTOR_X(a) = XL_VECTOR_ARRAY(b)[x];
	XL_VECTOR_Y(a) = XL_VECTOR_ARRAY(b)[y];
	XL_VECTOR_Z(a) = XL_VECTOR_ARRAY(b)[z];
#endif
	return a;
}

XLvector *
xlVectorAssignSwizzleMatrix(XLvector *a, XLmatrix *b, XLint x, XLint y, XLint z)
{
	XL_VECTOR_X(a) = XL_MATRIX_ARRAY(b)[x];
	XL_VECTOR_Y(a) = XL_MATRIX_ARRAY(b)[y];
	XL_VECTOR_Z(a) = XL_MATRIX_ARRAY(b)[z];
	return a;
}

XLvector *
xlVectorAssignMatrixForward(XLvector *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_ZX(b), XL_MATRIX_ZY(b), XL_MATRIX_ZZ(b), XL_REAL(1) };
	XL_VECTOR_SIMD(a) = -simd;
#else
	XL_VECTOR_X(a) = -XL_MATRIX_ZX(b);
	XL_VECTOR_Y(a) = -XL_MATRIX_ZY(b);
	XL_VECTOR_Z(a) = -XL_MATRIX_ZZ(b);
#endif
	return a;
}

XLvector *
xlVectorAssignMatrixUp(XLvector *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_YX(b), XL_MATRIX_YY(b), XL_MATRIX_YZ(b), XL_REAL(1) };
	XL_VECTOR_SIMD(a) = simd;
#else
	XL_VECTOR_X(a) = XL_MATRIX_YX(b);
	XL_VECTOR_Y(a) = XL_MATRIX_YY(b);
	XL_VECTOR_Z(a) = XL_MATRIX_YZ(b);
#endif
	return a;
}

XLvector *
xlVectorAssignMatrixRight(XLvector *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XX(b), XL_MATRIX_XY(b), XL_MATRIX_XZ(b), XL_REAL(1) };
	XL_VECTOR_SIMD(a) = simd;
#else
	XL_VECTOR_X(a) = XL_MATRIX_XX(b);
	XL_VECTOR_Y(a) = XL_MATRIX_XY(b);
	XL_VECTOR_Z(a) = XL_MATRIX_XZ(b);
#endif
	return a;
}

XLvector *
xlVectorAssignMatrixPosition(XLvector *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XW(b), XL_MATRIX_YW(b), XL_MATRIX_ZW(b), XL_REAL(1) };
	XL_VECTOR_SIMD(a) = simd;
#else
	XL_VECTOR_X(a) = XL_MATRIX_XW(b);
	XL_VECTOR_Y(a) = XL_MATRIX_YW(b);
	XL_VECTOR_Z(a) = XL_MATRIX_ZW(b);
#endif
	return a;
}

XLvector *
xlVectorAssignMatrixScalation(XLvector *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XX(b), XL_MATRIX_YY(b), XL_MATRIX_ZZ(b), XL_REAL(1) };
	XL_VECTOR_SIMD(a) = simd;
#else
	XL_VECTOR_X(a) = XL_MATRIX_XX(b);
	XL_VECTOR_Y(a) = XL_MATRIX_YY(b);
	XL_VECTOR_Z(a) = XL_MATRIX_ZZ(b);
#endif
	return a;
}

XLvector *
xlVectorClear(XLvector *a)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0) };
	XL_VECTOR_SIMD(a) = simd;
#else
	xlMemoryZero(a, sizeof(XLvector));
#endif
	return a;
}

XLvector *
xlVectorCopy(XLvector *a)
{
	XLvector *b;

	b = xlVectorAlloc();
	return xlVectorAssignCopy(b, a);
}

XLvector *
xlVectorAssignCopy(XLvector *a, XLvector *b)
{
#ifdef XL_SIMD
	XL_VECTOR_SIMD(a) = XL_VECTOR_SIMD(b);
#else
	xlMemoryCopy(a, b, sizeof(XLvector));
#endif
	return a;
}

xlVectorOp(Comp, Comp);
xlVectorAssignOpVector(AssignComp, Comp);

xlVectorOp(Neg, Neg);
xlVectorAssignOpVector(AssignNeg, Neg);

xlVectorOp(Inc, Inc);
xlVectorAssignOpVector(AssignInc, Inc);

xlVectorOp(Dec, Dec);
xlVectorAssignOpVector(AssignDec, Dec);

xlVectorArrayOp(Abs, Abs);
xlVectorArrayAssignOpVector(AssignAbs, Abs);

XLreal
xlVectorSquareNorm(XLvector *a)
{
	return xlVectorDot(a, a);
}

XLreal
xlVectorNorm(XLvector *a)
{
	return xlRealSquareRoot(xlVectorSquareNorm(a));
}

XLvector *
xlVectorNormal(XLvector *a)
{
	return xlVectorMultReal(a, XL_REAL(1) / xlVectorNorm(a));
}

XLvector *
xlVectorAssignNormal(XLvector *a, XLvector *b)
{
	return xlVectorAssignMultReal(a, b, XL_REAL(1) / xlVectorNorm(b));
}

xlVectorArrayBooleanOpVector(BooleanEqual, Equal);
xlVectorOpVector(VectorEqual, Equal);
xlVectorAssignOpPointPoint(AssignEqualPoint, Equal);
xlVectorAssignOpVectorVector(VectorAssignEqual, Equal);

xlVectorArrayBooleanOpVector(BooleanGreater, Greater);
xlVectorOpVector(VectorGreater, Greater);
xlVectorAssignOpPointPoint(AssignGreaterPoint, Greater);
xlVectorAssignOpVectorVector(VectorAssignGreater, Greater);

xlVectorArrayBooleanOpVector(BooleanLesser, Lesser);
xlVectorOpVector(VectorLesser, Lesser);
xlVectorAssignOpPointPoint(AssignLesserPoint, Lesser);
xlVectorAssignOpVectorVector(VectorAssignLesser, Lesser);

XLreal
xlVectorAngle(XLvector *a, XLvector *b)
{
	return xlRealRadToDeg(xlRealArcCosine(xlVectorDot(a, b) / (xlVectorNorm(a) * xlVectorNorm(b))));
}

XLreal
xlVectorDot(XLvector *a, XLvector *b)
{
	XLreal r;
#ifdef XL_SIMD
	XLsimd4sr simd;
	simd = XL_VECTOR_SIMD(a) * XL_VECTOR_SIMD(b);
	r = simd[0] + simd[1] + simd[2];
#else
	r = XL_VECTOR_X(a) * XL_VECTOR_X(b) + XL_VECTOR_Y(a) * XL_VECTOR_Y(b) + XL_VECTOR_Z(a) * XL_VECTOR_Z(b);
#endif
	return r;
}

xlVectorOpReal(AndReal, And);
xlVectorAssignOpVectorReal(AssignAndReal, And);
xlVectorOpVector(And, And);
xlVectorAssignOpPointPoint(AssignAndPoint, And);
xlVectorAssignOpVectorVector(AssignAnd, And);

xlVectorOpReal(OrReal, Or);
xlVectorAssignOpVectorReal(AssignOrReal, Or);
xlVectorOpVector(Or, Or);
xlVectorAssignOpPointPoint(AssignOrPoint, Or);
xlVectorAssignOpVectorVector(AssignOr, Or);

xlVectorOpReal(XorReal, Xor);
xlVectorAssignOpVectorReal(AssignXorReal, Xor);
xlVectorOpVector(Xor, Xor);
xlVectorAssignOpPointPoint(AssignXorPoint, Xor);
xlVectorAssignOpVectorVector(AssignXor, Xor);

xlVectorOpReal(LShiftReal, LShift);
xlVectorAssignOpVectorReal(AssignLShiftReal, LShift);
xlVectorOpVector(LShift, LShift);
xlVectorAssignOpPointPoint(AssignLShiftPoint, LShift);
xlVectorAssignOpVectorVector(AssignLShift, LShift);

xlVectorOpReal(RShiftReal, RShift);
xlVectorAssignOpVectorReal(AssignRShiftReal, RShift);
xlVectorOpVector(RShift, RShift);
xlVectorAssignOpPointPoint(AssignRShiftPoint, RShift);
xlVectorAssignOpVectorVector(AssignRShift, RShift);

xlVectorOpReal(AddReal, Add);
xlVectorAssignOpVectorReal(AssignAddReal, Add);
xlVectorOpVector(Add, Add);
xlVectorAssignOpPointPoint(AssignAddPoint, Add);
xlVectorAssignOpVectorVector(AssignAdd, Add);

xlVectorOpReal(SubReal, Sub);
xlVectorAssignOpVectorReal(AssignSubReal, Sub);
xlVectorOpVector(Sub, Sub);
xlVectorAssignOpPointPoint(AssignSubPoint, Sub);
xlVectorAssignOpVectorVector(AssignSub, Sub);

xlVectorOpReal(MultReal, Mult);
xlVectorAssignOpVectorReal(AssignMultReal, Mult);
xlVectorOpVector(Mult, Mult);
xlVectorAssignOpPointPoint(AssignMultPoint, Mult);
xlVectorAssignOpVectorVector(AssignMult, Mult);
xlVectorOpMatrix(MultMatrix, Mult);
xlVectorAssignOpVectorMatrix(AssignMultMatrix, Mult);

xlVectorOpReal(DivReal, Div);
xlVectorAssignOpVectorReal(AssignDivReal, Div);
xlVectorOpVector(Div, Div);
xlVectorAssignOpPointPoint(AssignDivPoint, Div);
xlVectorAssignOpVectorVector(AssignDiv, Div);
xlVectorOpMatrix(DivMatrix, Div);
xlVectorAssignOpVectorMatrix(AssignDivMatrix, Div);

xlVectorOpReal(ModReal, Mod);
xlVectorAssignOpVectorReal(AssignModReal, Mod);
xlVectorOpVector(Mod, Mod);
xlVectorAssignOpPointPoint(AssignModPoint, Mod);
xlVectorAssignOpVectorVector(AssignMod, Mod);
xlVectorOpMatrix(ModMatrix, Mod);
xlVectorAssignOpVectorMatrix(AssignModMatrix, Mod);

xlVectorOpReal(InvDivReal, InvDiv);
xlVectorAssignOpVectorReal(AssignInvDivReal, InvDiv);
xlVectorOpVector(InvDiv, InvDiv);
xlVectorAssignOpPointPoint(AssignInvDivPoint, InvDiv);
xlVectorAssignOpVectorVector(AssignInvDiv, InvDiv);
xlVectorOpMatrix(InvDivMatrix, InvDiv);
xlVectorAssignOpVectorMatrix(AssignInvDivMatrix, InvDiv);

XLvector *
xlVectorCross(XLvector *a, XLvector *b)
{
#ifdef XL_SIMD
	XLsimd4si mask[2] = { { 1, 2, 0, 3 }, { 2, 0, 1, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_VECTOR_SIMD(a), mask[0]);
	simd[1] = __builtin_shuffle(XL_VECTOR_SIMD(b), mask[1]);
	simd[2] = __builtin_shuffle(XL_VECTOR_SIMD(a), mask[1]);
	simd[3] = __builtin_shuffle(XL_VECTOR_SIMD(b), mask[0]);
	XL_VECTOR_SIMD(a) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XLreal data[3];
	data[0] = XL_VECTOR_Y(a) * XL_VECTOR_Z(b) - XL_VECTOR_Z(a) * XL_VECTOR_Y(b);
	data[1] = XL_VECTOR_Z(a) * XL_VECTOR_X(b) - XL_VECTOR_X(a) * XL_VECTOR_Z(b);
	data[2] = XL_VECTOR_X(a) * XL_VECTOR_Y(b) - XL_VECTOR_Y(a) * XL_VECTOR_X(b);
	xlRealCopy(XL_VECTOR_ARRAY(a), data, 3);
#endif
	return a;
}

XLvector *
xlVectorAssignCross(XLvector *a, XLvector *b, XLvector *c)
{
#ifdef XL_SIMD
	XLsimd4si mask[2] = { { 1, 2, 0, 3 }, { 2, 0, 1, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_VECTOR_SIMD(b), mask[0]);
	simd[1] = __builtin_shuffle(XL_VECTOR_SIMD(c), mask[1]);
	simd[2] = __builtin_shuffle(XL_VECTOR_SIMD(b), mask[1]);
	simd[3] = __builtin_shuffle(XL_VECTOR_SIMD(c), mask[0]);
	XL_VECTOR_SIMD(a) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XL_VECTOR_X(a) = XL_VECTOR_Y(b) * XL_VECTOR_Z(c) - XL_VECTOR_Z(b) * XL_VECTOR_Y(c);
	XL_VECTOR_Y(a) = XL_VECTOR_Z(b) * XL_VECTOR_X(c) - XL_VECTOR_X(b) * XL_VECTOR_Z(c);
	XL_VECTOR_Z(a) = XL_VECTOR_X(b) * XL_VECTOR_Y(c) - XL_VECTOR_Y(b) * XL_VECTOR_X(c);
#endif
	return a;
}

XLvector *
xlVectorAssignCrossPoint(XLvector *a, XLpoint *b, XLpoint *c)
{
#ifdef XL_SIMD
	XLsimd4si mask[2] = { { 1, 2, 0, 3 }, { 2, 0, 1, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_POINT_SIMD(b), mask[0]);
	simd[1] = __builtin_shuffle(XL_POINT_SIMD(c), mask[1]);
	simd[2] = __builtin_shuffle(XL_POINT_SIMD(b), mask[1]);
	simd[3] = __builtin_shuffle(XL_POINT_SIMD(c), mask[0]);
	XL_VECTOR_SIMD(a) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XL_VECTOR_X(a) = XL_POINT_Y(b) * XL_POINT_Z(c) - XL_POINT_Z(b) * XL_POINT_Y(c);
	XL_VECTOR_Y(a) = XL_POINT_Z(b) * XL_POINT_X(c) - XL_POINT_X(b) * XL_POINT_Z(c);
	XL_VECTOR_Z(a) = XL_POINT_X(b) * XL_POINT_Y(c) - XL_POINT_Y(b) * XL_POINT_X(c);
#endif
	return a;
}

xlVectorArrayOpVector(Min, Min);
xlVectorArrayAssignOpPointPoint(AssignMinPoint, Min);
xlVectorArrayAssignOpVectorVector(AssignMin, Min);

xlVectorArrayOpVector(Max, Max);
xlVectorArrayAssignOpPointPoint(AssignMaxPoint, Max);
xlVectorArrayAssignOpVectorVector(AssignMax, Max);

xlVectorArrayOpRealReal(ClampReal, Clamp);
xlVectorArrayAssignOpVectorRealReal(AssignClampReal, Clamp);
xlVectorArrayOpVectorVector(Clamp, Clamp);
xlVectorArrayAssignOpVectorVectorVector(AssignClamp, Clamp);

xlVectorArrayAssignNoneOpRealReal(AssignRandRangeReal, RandRange);
xlVectorArrayAssignNoneOpVectorVector(AssignRandRange, RandRange);

XLvector *
xlVectorRotate(XLvector *a, XLvector *axis, XLreal angle)
{
	XLmatrix m;
	xlMatrixAssignRotation(&m, axis, angle);
	return xlVectorMultMatrix(a, &m);
}

XLvector *
xlVectorAssignRotate(XLvector *a, XLvector *b, XLvector *axis, XLreal angle)
{
	XLmatrix m;
	xlMatrixAssignRotation(&m, axis, angle);
	return xlVectorAssignMultMatrix(a, b, &m);
}

xlVectorOpVectorReal(Lerp, Lerp);
xlVectorAssignOpVectorVectorReal(AssignLerp, Lerp);

xlVectorOpVectorVectorReal(QuadBezier, QuadBezier);
xlVectorAssignOpVectorVectorVectorReal(AssignQuadBezier, QuadBezier);

xlVectorOpVectorVectorVectorReal(CubicBezier, CubicBezier);
xlVectorAssignOpVectorVectorVectorVectorReal(AssignCubicBezier, CubicBezier);

#define _xlVectorInit(e, v) \
	xlVector ## v = &_xlVector ## v; \
	xlVectorAssign ## v(xlVector ## v);

void
xlVectorInit()
{
	xlVectorsForEach(_xlVectorInit)
}

#undef _xlVectorInit

void
xlVectorFini()
{
}

#undef xlVectorAssignOpVectorVectorVectorVectorReal
#undef xlVectorOpVectorVectorVectorReal
#undef xlVectorAssignOpVectorVectorVectorReal
#undef xlVectorOpVectorVectorReal
#undef xlVectorAssignOpVectorVectorReal
#undef xlVectorOpVectorReal
#undef xlVectorAssignOpVectorMatrix
#undef xlVectorOpMatrix
#undef xlVectorAssignOpVectorVector
#undef xlVectorAssignOpPointPoint
#undef xlVectorOpVector
#undef xlVectorAssignOpVectorReal
#undef xlVectorOpReal
#undef xlVectorAssignOpVector
#undef xlVectorOp
#undef xlVectorArrayAssignOpVectorVectorVector
#undef xlVectorArrayOpVectorVector
#undef xlVectorArrayAssignOpVectorRealReal
#undef xlVectorArrayOpRealReal
#undef xlVectorArrayAssignOpVectorVector
#undef xlVectorArrayAssignOpPointPoint
#undef xlVectorArrayOpVector
#undef xlVectorArrayBooleanOpVector
#undef xlVectorArrayAssignOpVector
#undef xlVectorArrayOp
