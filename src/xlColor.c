/* http://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html */
/* http://www.w3schools.com/cssref/css_colornames.asp */

#include "XL/xlColor.h"
#include "XL/xl.h"

#define xlColorArrayAssignNoneOp(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(); \
		XL_COLOR_G(a) = xlReal ## Op(); \
		XL_COLOR_B(a) = xlReal ## Op(); \
		XL_COLOR_A(a) = xlReal ## Op(); \
		return a; \
	}
#define xlColorArrayOp(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(a)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(a)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(a)); \
		return a; \
	}
#define xlColorArrayAssignOpColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b)); \
		return a; \
	}
#define xlColorArrayBooleanOpColor(Name, Op) \
	XLboolean \
	xlColor ## Name(XLcolor *a, XLcolor *b) \
	{ \
		return \
			xlReal ## Op(XL_COLOR_R(a), XL_COLOR_R(b)) && \
			xlReal ## Op(XL_COLOR_G(a), XL_COLOR_G(b)) && \
			xlReal ## Op(XL_COLOR_B(a), XL_COLOR_B(b)) && \
			xlReal ## Op(XL_COLOR_A(a), XL_COLOR_A(b)); \
	}
#define xlColorArrayOpColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a), XL_COLOR_R(b)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(a), XL_COLOR_G(b)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(a), XL_COLOR_B(b)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(a), XL_COLOR_A(b)); \
		return a; \
	}
#define xlColorArrayAssignOpColorColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b), XL_COLOR_R(c)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b), XL_COLOR_G(c)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b), XL_COLOR_B(c)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b), XL_COLOR_A(c)); \
		return a; \
	}
#define xlColorArrayAssignNoneOpRealReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLreal b, XLreal c) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(b, c); \
		XL_COLOR_G(a) = xlReal ## Op(b, c); \
		XL_COLOR_B(a) = xlReal ## Op(b, c); \
		XL_COLOR_A(a) = xlReal ## Op(b, c); \
		return a; \
	}
#define xlColorArrayAssignNoneOpColorColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b), XL_COLOR_R(c)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b), XL_COLOR_G(c)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b), XL_COLOR_B(c)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b), XL_COLOR_A(c)); \
		return a; \
	}
#define xlColorArrayOpRealReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLreal b, XLreal c) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a), b, c); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(a), b, c); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(a), b, c); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(a), b, c); \
		return a; \
	}
#define xlColorArrayAssignOpColorRealReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLreal c, XLreal d) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b), c, d); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b), c, d); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b), c, d); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b), c, d); \
		return a; \
	}
#define xlColorArrayOpColorColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a), XL_COLOR_R(b), XL_COLOR_R(c)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(a), XL_COLOR_G(b), XL_COLOR_G(c)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(a), XL_COLOR_B(b), XL_COLOR_B(c)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(a), XL_COLOR_A(b), XL_COLOR_A(c)); \
		return a; \
	}
#define xlColorArrayAssignOpColorColorColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLcolor *d) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b), XL_COLOR_R(c), XL_COLOR_R(d)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b), XL_COLOR_G(c), XL_COLOR_G(d)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b), XL_COLOR_B(c), XL_COLOR_B(d)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b), XL_COLOR_A(c), XL_COLOR_A(d)); \
		return a; \
	}

#ifdef XL_SIMD
#define xlColorOp(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(a)); \
		return a; \
	}
#define xlColorAssignOpColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(b)); \
		return a; \
	}
#define xlColorOpReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op ## Real(XL_VECTOR_SIMD(a), r); \
		return a; \
	}
#define xlColorAssignOpColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op ## Real(XL_VECTOR_SIMD(b), r); \
		return a; \
	}
#define xlColorOpColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(a), XL_VECTOR_SIMD(b)); \
		return a; \
	}
#define xlColorAssignOpColorColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c)); \
		return a; \
	}
#define xlColorOpMatrix(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLmatrix *b) \
	{ \
		XLsimd4sr simd[4] = { \
			{ XL_MATRIX_SIMD(b)[0], XL_MATRIX_SIMD(b)[1], XL_MATRIX_SIMD(b)[2], XL_MATRIX_SIMD(b)[3] }, \
			{ XL_MATRIX_SIMD(b)[4], XL_MATRIX_SIMD(b)[5], XL_MATRIX_SIMD(b)[6], XL_MATRIX_SIMD(b)[7] }, \
			{ XL_MATRIX_SIMD(b)[8], XL_MATRIX_SIMD(b)[9], XL_MATRIX_SIMD(b)[10], XL_MATRIX_SIMD(b)[11] }, \
			{ XL_MATRIX_SIMD(b)[12], XL_MATRIX_SIMD(b)[13], XL_MATRIX_SIMD(b)[14], XL_MATRIX_SIMD(b)[15] } \
		}; \
		simd[0] = xlReal ## Op ## Simd4sr(XL_COLOR_R(a), simd[0]); \
		simd[1] = xlReal ## Op ## Simd4sr(XL_COLOR_G(a), simd[1]); \
		simd[2] = xlReal ## Op ## Simd4sr(XL_COLOR_B(a), simd[2]); \
		simd[3] = xlReal ## Op ## Simd4sr(XL_COLOR_A(a), simd[3]); \
		XL_VECTOR_SIMD(a) = simd[0] + simd[1] + simd[2] + simd[3]; \
		return a; \
	}
#define xlColorAssignOpColorMatrix(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLmatrix *c) \
	{ \
		XLsimd4sr simd[4] = { \
			{ XL_MATRIX_SIMD(c)[0], XL_MATRIX_SIMD(c)[1], XL_MATRIX_SIMD(c)[2], XL_MATRIX_SIMD(c)[3] }, \
			{ XL_MATRIX_SIMD(c)[4], XL_MATRIX_SIMD(c)[5], XL_MATRIX_SIMD(c)[6], XL_MATRIX_SIMD(c)[7] }, \
			{ XL_MATRIX_SIMD(c)[8], XL_MATRIX_SIMD(c)[9], XL_MATRIX_SIMD(c)[10], XL_MATRIX_SIMD(c)[11] }, \
			{ XL_MATRIX_SIMD(c)[12], XL_MATRIX_SIMD(c)[13], XL_MATRIX_SIMD(c)[14], XL_MATRIX_SIMD(c)[15] } \
		}; \
		simd[0] = xlReal ## Op ## Simd4sr(XL_COLOR_R(b), simd[0]); \
		simd[1] = xlReal ## Op ## Simd4sr(XL_COLOR_G(b), simd[1]); \
		simd[2] = xlReal ## Op ## Simd4sr(XL_COLOR_B(b), simd[2]); \
		simd[3] = xlReal ## Op ## Simd4sr(XL_COLOR_A(b), simd[3]); \
		XL_VECTOR_SIMD(a) = simd[0] + simd[1] + simd[2] + simd[3]; \
		return a; \
	}
#define xlColorOpColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(a), XL_VECTOR_SIMD(b), r); \
		return a; \
	}
#define xlColorAssignOpColorColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c), r); \
		return a; \
	}
#define xlColorOpColorColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(a), XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c), r); \
		return a; \
	}
#define xlColorAssignOpColorColorColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLcolor *d, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c), XL_VECTOR_SIMD(d), r); \
		return a; \
	}
#define xlColorOpColorColorColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLcolor *d, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(a), XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c), XL_VECTOR_SIMD(d), r); \
		return a; \
	}
#define xlColorAssignOpColorColorColorColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLcolor *d, XLcolor *e, XLreal r) \
	{ \
		XL_VECTOR_SIMD(a) = xlSimd4sr ## Op(XL_VECTOR_SIMD(b), XL_VECTOR_SIMD(c), XL_VECTOR_SIMD(d), XL_VECTOR_SIMD(e), r); \
		return a; \
	}
#else
#define xlColorOp(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(a)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(a)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(a)); \
		return a; \
	}
#define xlColorAssignOpColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b)); \
		return a; \
	}
#define xlColorOpReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLreal r) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a), r); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(a), r); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(a), r); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(a), r); \
		return a; \
	}
#define xlColorAssignOpColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLreal r) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b), r); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b), r); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b), r); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b), r); \
		return a; \
	}
#define xlColorOpColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a), XL_COLOR_R(b)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(a), XL_COLOR_G(b)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(a), XL_COLOR_B(b)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(a), XL_COLOR_A(b)); \
		return a; \
	}
#define xlColorAssignOpColorColor(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b), XL_COLOR_R(c)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b), XL_COLOR_G(c)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b), XL_COLOR_B(c)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b), XL_COLOR_A(c)); \
		return a; \
	}
#define xlColorOpMatrix(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLmatrix *b) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a), XL_MATRIX_XX(b)) + xlReal ## Op(XL_COLOR_G(a), XL_MATRIX_XY(b)) + xlReal ## Op(XL_COLOR_B(a), XL_MATRIX_XZ(b)) + xlReal ## Op(XL_COLOR_A(a), XL_MATRIX_XW(b)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_R(a), XL_MATRIX_YX(b)) + xlReal ## Op(XL_COLOR_G(a), XL_MATRIX_YY(b)) + xlReal ## Op(XL_COLOR_B(a), XL_MATRIX_YZ(b)) + xlReal ## Op(XL_COLOR_A(a), XL_MATRIX_YW(b)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_R(a), XL_MATRIX_ZX(b)) + xlReal ## Op(XL_COLOR_G(a), XL_MATRIX_ZY(b)) + xlReal ## Op(XL_COLOR_B(a), XL_MATRIX_ZZ(b)) + xlReal ## Op(XL_COLOR_A(a), XL_MATRIX_ZW(b)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_R(a), XL_MATRIX_ZX(b)) + xlReal ## Op(XL_COLOR_G(a), XL_MATRIX_ZY(b)) + xlReal ## Op(XL_COLOR_B(a), XL_MATRIX_ZZ(b)) + xlReal ## Op(XL_COLOR_A(a), XL_MATRIX_ZW(b)); \
		return a; \
	}
#define xlColorAssignOpColorMatrix(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLmatrix *c) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b), XL_MATRIX_XX(c)) + xlReal ## Op(XL_COLOR_G(b), XL_MATRIX_XY(c)) + xlReal ## Op(XL_COLOR_B(b), XL_MATRIX_XZ(c)) + xlReal ## Op(XL_COLOR_A(b), XL_MATRIX_XW(c)); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_R(b), XL_MATRIX_YX(c)) + xlReal ## Op(XL_COLOR_G(b), XL_MATRIX_YY(c)) + xlReal ## Op(XL_COLOR_B(b), XL_MATRIX_YZ(c)) + xlReal ## Op(XL_COLOR_A(b), XL_MATRIX_YW(c)); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_R(b), XL_MATRIX_ZX(c)) + xlReal ## Op(XL_COLOR_G(b), XL_MATRIX_ZY(c)) + xlReal ## Op(XL_COLOR_B(b), XL_MATRIX_ZZ(c)) + xlReal ## Op(XL_COLOR_A(b), XL_MATRIX_ZW(c)); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_R(b), XL_MATRIX_ZX(c)) + xlReal ## Op(XL_COLOR_G(b), XL_MATRIX_ZY(c)) + xlReal ## Op(XL_COLOR_B(b), XL_MATRIX_ZZ(c)) + xlReal ## Op(XL_COLOR_A(b), XL_MATRIX_ZW(c)); \
		return a; \
	}
#define xlColorOpColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLreal r) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a), XL_COLOR_R(b), r); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(a), XL_COLOR_G(b), r); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(a), XL_COLOR_B(b), r); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(a), XL_COLOR_A(b), r); \
		return a; \
	}
#define xlColorAssignOpColorColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLreal r) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b), XL_COLOR_R(c), r); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b), XL_COLOR_G(c), r); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b), XL_COLOR_B(c), r); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b), XL_COLOR_A(c), r); \
		return a; \
	}
#define xlColorOpColorColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLreal r) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a), XL_COLOR_R(b), XL_COLOR_R(c), r); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(a), XL_COLOR_G(b), XL_COLOR_G(c), r); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(a), XL_COLOR_B(b), XL_COLOR_B(c), r); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(a), XL_COLOR_A(b), XL_COLOR_A(c), r); \
		return a; \
	}
#define xlColorAssignOpColorColorColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLcolor *d, XLreal r) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b), XL_COLOR_R(c), XL_COLOR_R(d), r); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b), XL_COLOR_G(c), XL_COLOR_G(d), r); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b), XL_COLOR_B(c), XL_COLOR_B(d), r); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b), XL_COLOR_A(c), XL_COLOR_A(d), r); \
		return a; \
	}
#define xlColorOpColorColorColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLcolor *d, XLreal r) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(a), XL_COLOR_R(b), XL_COLOR_R(c), XL_COLOR_R(d), r); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(a), XL_COLOR_G(b), XL_COLOR_G(c), XL_COLOR_G(d), r); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(a), XL_COLOR_B(b), XL_COLOR_B(c), XL_COLOR_B(d), r); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(a), XL_COLOR_A(b), XL_COLOR_A(c), XL_COLOR_A(d), r); \
		return a; \
	}
#define xlColorAssignOpColorColorColorColorReal(Name, Op) \
	XLcolor * \
	xlColor ## Name(XLcolor *a, XLcolor *b, XLcolor *c, XLcolor *d, XLcolor *e, XLreal r) \
	{ \
		XL_COLOR_R(a) = xlReal ## Op(XL_COLOR_R(b), XL_COLOR_R(c), XL_COLOR_R(d), XL_COLOR_R(e), r); \
		XL_COLOR_G(a) = xlReal ## Op(XL_COLOR_G(b), XL_COLOR_G(c), XL_COLOR_G(d), XL_COLOR_G(e), r); \
		XL_COLOR_B(a) = xlReal ## Op(XL_COLOR_B(b), XL_COLOR_B(c), XL_COLOR_B(d), XL_COLOR_B(e), r); \
		XL_COLOR_A(a) = xlReal ## Op(XL_COLOR_A(b), XL_COLOR_A(c), XL_COLOR_A(d), XL_COLOR_A(e), r); \
		return a; \
	}
#endif


XLcolor *
xlColorAlloc(void)
{
	XLcolor *ca;
#ifdef XL_SIMD
	ca = xlSimdAligned4srAlloc(sizeof(XLcolor));
#else
	ca = xlMemoryAlloc(sizeof(XLcolor));
#endif
	return ca;
}

#define _xlColor(c, r, g, b, a) \
	static \
	XLcolor \
	_xlColor ## c; \
	\
	XLcolor \
	*xlColor ## c; \
	\
	XLcolor * \
	xlColorAssign ## c(XLcolor *ca) \
	{ \
		return xlColorAssignReals(ca, r, g, b, a); \
	} 

_xlColor(Default, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlColor(NegDefault, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlColor(Zero, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlColor(Half, XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5));
_xlColor(NegHalf, XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5));
_xlColor(One, XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1));
_xlColor(NegOne, XL_REAL(-1), XL_REAL(-1), XL_REAL(-1), XL_REAL(-1));
_xlColor(Double, XL_REAL(2), XL_REAL(2), XL_REAL(2), XL_REAL(2));
_xlColor(NegDouble, XL_REAL(-2), XL_REAL(-2), XL_REAL(-2), XL_REAL(-2));
_xlColor(R, XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlColor(NegR, XL_REAL(-1), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlColor(G, XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(0));
_xlColor(NegG, XL_REAL(0), XL_REAL(-1), XL_REAL(0), XL_REAL(0));
_xlColor(B, XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0));
_xlColor(NegB, XL_REAL(0), XL_REAL(0), XL_REAL(-1), XL_REAL(0));
_xlColor(A, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlColor(NegA, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(-1));
_xlColor(TMP, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlColor(TMP1, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlColor(TMP2, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlColor(TMP3, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlColor(TMP4, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlColor(AliceBlue, XL_REAL(0.94117647058823529411), XL_REAL(0.97254901960784313725), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(AntiqueWhite, XL_REAL(0.98039215686274509803), XL_REAL(0.92156862745098039215), XL_REAL(0.84313725490196078431), XL_REAL(1));
_xlColor(Aqua, XL_REAL(0), XL_REAL(1.00000000000000000000), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(Aquamarine, XL_REAL(0.49803921568627450980), XL_REAL(1.00000000000000000000), XL_REAL(0.83137254901960784313), XL_REAL(1));
_xlColor(Azure, XL_REAL(0.94117647058823529411), XL_REAL(1.00000000000000000000), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(Beige, XL_REAL(0.96078431372549019607), XL_REAL(0.96078431372549019607), XL_REAL(0.86274509803921568627), XL_REAL(1));
_xlColor(Bisque, XL_REAL(1.00000000000000000000), XL_REAL(0.89411764705882352941), XL_REAL(0.76862745098039215686), XL_REAL(1));
_xlColor(Black, XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlColor(BlanchedAlmond, XL_REAL(1.00000000000000000000), XL_REAL(0.92156862745098039215), XL_REAL(0.80392156862745098039), XL_REAL(1));
_xlColor(Blue, XL_REAL(0), XL_REAL(0), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(BlueViolet, XL_REAL(0.54117647058823529411), XL_REAL(0.16862745098039215686), XL_REAL(0.88627450980392156862), XL_REAL(1));
_xlColor(Brown, XL_REAL(0.64705882352941176470), XL_REAL(0.16470588235294117647), XL_REAL(0.16470588235294117647), XL_REAL(1));
_xlColor(BurlyWood, XL_REAL(0.87058823529411764705), XL_REAL(0.72156862745098039215), XL_REAL(0.52941176470588235294), XL_REAL(1));
_xlColor(CadetBlue, XL_REAL(0.37254901960784313725), XL_REAL(0.61960784313725490196), XL_REAL(0.62745098039215686274), XL_REAL(1));
_xlColor(Chartreuse, XL_REAL(0.49803921568627450980), XL_REAL(1.00000000000000000000), XL_REAL(0), XL_REAL(1));
_xlColor(Chocolate, XL_REAL(0.82352941176470588235), XL_REAL(0.41176470588235294117), XL_REAL(0.11764705882352941176), XL_REAL(1));
_xlColor(Coral, XL_REAL(1.00000000000000000000), XL_REAL(0.49803921568627450980), XL_REAL(0.31372549019607843137), XL_REAL(1));
_xlColor(CornflowerBlue, XL_REAL(0.39215686274509803921), XL_REAL(0.58431372549019607843), XL_REAL(0.92941176470588235294), XL_REAL(1));
_xlColor(Cornsilk, XL_REAL(1.00000000000000000000), XL_REAL(0.97254901960784313725), XL_REAL(0.86274509803921568627), XL_REAL(1));
_xlColor(Crimson, XL_REAL(0.86274509803921568627), XL_REAL(0.07843137254901960784), XL_REAL(0.23529411764705882352), XL_REAL(1));
_xlColor(Cyan, XL_REAL(0), XL_REAL(1.00000000000000000000), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(DarkBlue, XL_REAL(0), XL_REAL(0), XL_REAL(0.54509803921568627450), XL_REAL(1));
_xlColor(DarkCyan, XL_REAL(0), XL_REAL(0.54509803921568627450), XL_REAL(0.54509803921568627450), XL_REAL(1));
_xlColor(DarkGoldenRod, XL_REAL(0.72156862745098039215), XL_REAL(0.52549019607843137254), XL_REAL(0.04313725490196078431), XL_REAL(1));
_xlColor(DarkGray, XL_REAL(0.66274509803921568627), XL_REAL(0.66274509803921568627), XL_REAL(0.66274509803921568627), XL_REAL(1));
_xlColor(DarkGreen, XL_REAL(0), XL_REAL(0.39215686274509803921), XL_REAL(0), XL_REAL(1));
_xlColor(DarkKhaki, XL_REAL(0.74117647058823529411), XL_REAL(0.71764705882352941176), XL_REAL(0.41960784313725490196), XL_REAL(1));
_xlColor(DarkMagenta, XL_REAL(0.54509803921568627450), XL_REAL(0), XL_REAL(0.54509803921568627450), XL_REAL(1));
_xlColor(DarkOliveGreen, XL_REAL(0.33333333333333333333), XL_REAL(0.41960784313725490196), XL_REAL(0.18431372549019607843), XL_REAL(1));
_xlColor(DarkOrange, XL_REAL(1.00000000000000000000), XL_REAL(0.54901960784313725490), XL_REAL(0), XL_REAL(1));
_xlColor(DarkOrchid, XL_REAL(0.60000000000000000000), XL_REAL(0.19607843137254901960), XL_REAL(0.80000000000000000000), XL_REAL(1));
_xlColor(DarkRed, XL_REAL(0.54509803921568627450), XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlColor(DarkSalmon, XL_REAL(0.91372549019607843137), XL_REAL(0.58823529411764705882), XL_REAL(0.47843137254901960784), XL_REAL(1));
_xlColor(DarkSeaGreen, XL_REAL(0.56078431372549019607), XL_REAL(0.73725490196078431372), XL_REAL(0.56078431372549019607), XL_REAL(1));
_xlColor(DarkSlateBlue, XL_REAL(0.28235294117647058823), XL_REAL(0.23921568627450980392), XL_REAL(0.54509803921568627450), XL_REAL(1));
_xlColor(DarkSlateGray, XL_REAL(0.18431372549019607843), XL_REAL(0.30980392156862745098), XL_REAL(0.30980392156862745098), XL_REAL(1));
_xlColor(DarkTurquoise, XL_REAL(0), XL_REAL(0.80784313725490196078), XL_REAL(0.81960784313725490196), XL_REAL(1));
_xlColor(DarkViolet, XL_REAL(0.58039215686274509803), XL_REAL(0), XL_REAL(0.82745098039215686274), XL_REAL(1));
_xlColor(DeepPink, XL_REAL(1.00000000000000000000), XL_REAL(0.07843137254901960784), XL_REAL(0.57647058823529411764), XL_REAL(1));
_xlColor(DeepSkyBlue, XL_REAL(0), XL_REAL(0.74901960784313725490), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(DimGray, XL_REAL(0.41176470588235294117), XL_REAL(0.41176470588235294117), XL_REAL(0.41176470588235294117), XL_REAL(1));
_xlColor(DimGrey, XL_REAL(0.41176470588235294117), XL_REAL(0.41176470588235294117), XL_REAL(0.41176470588235294117), XL_REAL(1));
_xlColor(DodgerBlue, XL_REAL(0.11764705882352941176), XL_REAL(0.56470588235294117647), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(FireBrick, XL_REAL(0.69803921568627450980), XL_REAL(0.13333333333333333333), XL_REAL(0.13333333333333333333), XL_REAL(1));
_xlColor(FloralWhite, XL_REAL(1.00000000000000000000), XL_REAL(0.98039215686274509803), XL_REAL(0.94117647058823529411), XL_REAL(1));
_xlColor(ForestGreen, XL_REAL(0.13333333333333333333), XL_REAL(0.54509803921568627450), XL_REAL(0.13333333333333333333), XL_REAL(1));
_xlColor(Fuchsia, XL_REAL(1.00000000000000000000), XL_REAL(0), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(Gainsboro, XL_REAL(0.86274509803921568627), XL_REAL(0.86274509803921568627), XL_REAL(0.86274509803921568627), XL_REAL(1));
_xlColor(GhostWhite, XL_REAL(0.97254901960784313725), XL_REAL(0.97254901960784313725), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(Gold, XL_REAL(1.00000000000000000000), XL_REAL(0.84313725490196078431), XL_REAL(0), XL_REAL(1));
_xlColor(GoldenRod, XL_REAL(0.85490196078431372549), XL_REAL(0.64705882352941176470), XL_REAL(0.12549019607843137254), XL_REAL(1));
_xlColor(Gray, XL_REAL(0.50196078431372549019), XL_REAL(0.50196078431372549019), XL_REAL(0.50196078431372549019), XL_REAL(1));
_xlColor(Green, XL_REAL(0), XL_REAL(0.50196078431372549019), XL_REAL(0), XL_REAL(1));
_xlColor(GreenYellow, XL_REAL(0.67843137254901960784), XL_REAL(1.00000000000000000000), XL_REAL(0.18431372549019607843), XL_REAL(1));
_xlColor(HoneyDew, XL_REAL(0.94117647058823529411), XL_REAL(1.00000000000000000000), XL_REAL(0.94117647058823529411), XL_REAL(1));
_xlColor(HotPink, XL_REAL(1.00000000000000000000), XL_REAL(0.41176470588235294117), XL_REAL(0.70588235294117647058), XL_REAL(1));
_xlColor(IndianRed, XL_REAL(0.80392156862745098039), XL_REAL(0.36078431372549019607), XL_REAL(0.36078431372549019607), XL_REAL(1));
_xlColor(Indigo, XL_REAL(0.29411764705882352941), XL_REAL(0), XL_REAL(0.50980392156862745098), XL_REAL(1));
_xlColor(Ivory, XL_REAL(1.00000000000000000000), XL_REAL(1.00000000000000000000), XL_REAL(0.94117647058823529411), XL_REAL(1));
_xlColor(Khaki, XL_REAL(0.94117647058823529411), XL_REAL(0.90196078431372549019), XL_REAL(0.54901960784313725490), XL_REAL(1));
_xlColor(Lavender, XL_REAL(0.90196078431372549019), XL_REAL(0.90196078431372549019), XL_REAL(0.98039215686274509803), XL_REAL(1));
_xlColor(LavenderBlush, XL_REAL(1.00000000000000000000), XL_REAL(0.94117647058823529411), XL_REAL(0.96078431372549019607), XL_REAL(1));
_xlColor(LawnGreen, XL_REAL(0.48627450980392156862), XL_REAL(0.98823529411764705882), XL_REAL(0), XL_REAL(1));
_xlColor(LemonChiffon, XL_REAL(1.00000000000000000000), XL_REAL(0.98039215686274509803), XL_REAL(0.80392156862745098039), XL_REAL(1));
_xlColor(LightBlue, XL_REAL(0.67843137254901960784), XL_REAL(0.84705882352941176470), XL_REAL(0.90196078431372549019), XL_REAL(1));
_xlColor(LightCoral, XL_REAL(0.94117647058823529411), XL_REAL(0.50196078431372549019), XL_REAL(0.50196078431372549019), XL_REAL(1));
_xlColor(LightCyan, XL_REAL(0.87843137254901960784), XL_REAL(1.00000000000000000000), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(LightGoldenRodYellow, XL_REAL(0.98039215686274509803), XL_REAL(0.98039215686274509803), XL_REAL(0.82352941176470588235), XL_REAL(1));
_xlColor(LightGray, XL_REAL(0.82745098039215686274), XL_REAL(0.82745098039215686274), XL_REAL(0.82745098039215686274), XL_REAL(1));
_xlColor(LightGreen, XL_REAL(0.56470588235294117647), XL_REAL(0.93333333333333333333), XL_REAL(0.56470588235294117647), XL_REAL(1));
_xlColor(LightPink, XL_REAL(1.00000000000000000000), XL_REAL(0.71372549019607843137), XL_REAL(0.75686274509803921568), XL_REAL(1));
_xlColor(LightSalmon, XL_REAL(1.00000000000000000000), XL_REAL(0.62745098039215686274), XL_REAL(0.47843137254901960784), XL_REAL(1));
_xlColor(LightSeaGreen, XL_REAL(0.12549019607843137254), XL_REAL(0.69803921568627450980), XL_REAL(0.66666666666666666666), XL_REAL(1));
_xlColor(LightSkyBlue, XL_REAL(0.52941176470588235294), XL_REAL(0.80784313725490196078), XL_REAL(0.98039215686274509803), XL_REAL(1));
_xlColor(LightSlateGray, XL_REAL(0.46666666666666666666), XL_REAL(0.53333333333333333333), XL_REAL(0.60000000000000000000), XL_REAL(1));
_xlColor(LightSteelBlue, XL_REAL(0.69019607843137254901), XL_REAL(0.76862745098039215686), XL_REAL(0.87058823529411764705), XL_REAL(1));
_xlColor(LightYellow, XL_REAL(1.00000000000000000000), XL_REAL(1.00000000000000000000), XL_REAL(0.87843137254901960784), XL_REAL(1));
_xlColor(Lime, XL_REAL(0), XL_REAL(1.00000000000000000000), XL_REAL(0), XL_REAL(1));
_xlColor(LimeGreen, XL_REAL(0.19607843137254901960), XL_REAL(0.80392156862745098039), XL_REAL(0.19607843137254901960), XL_REAL(1));
_xlColor(Linen, XL_REAL(0.98039215686274509803), XL_REAL(0.94117647058823529411), XL_REAL(0.90196078431372549019), XL_REAL(1));
_xlColor(Magenta, XL_REAL(1.00000000000000000000), XL_REAL(0), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(Maroon, XL_REAL(0.50196078431372549019), XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlColor(MediumAquaMarine, XL_REAL(0.40000000000000000000), XL_REAL(0.80392156862745098039), XL_REAL(0.66666666666666666666), XL_REAL(1));
_xlColor(MediumBlue, XL_REAL(0), XL_REAL(0), XL_REAL(0.80392156862745098039), XL_REAL(1));
_xlColor(MediumOrchid, XL_REAL(0.72941176470588235294), XL_REAL(0.33333333333333333333), XL_REAL(0.82745098039215686274), XL_REAL(1));
_xlColor(MediumPurple, XL_REAL(0.57647058823529411764), XL_REAL(0.43921568627450980392), XL_REAL(0.85882352941176470588), XL_REAL(1));
_xlColor(MediumSeaGreen, XL_REAL(0.23529411764705882352), XL_REAL(0.70196078431372549019), XL_REAL(0.44313725490196078431), XL_REAL(1));
_xlColor(MediumSlateBlue, XL_REAL(0.48235294117647058823), XL_REAL(0.40784313725490196078), XL_REAL(0.93333333333333333333), XL_REAL(1));
_xlColor(MediumSpringGreen, XL_REAL(0), XL_REAL(0.98039215686274509803), XL_REAL(0.60392156862745098039), XL_REAL(1));
_xlColor(MediumTurquoise, XL_REAL(0.28235294117647058823), XL_REAL(0.81960784313725490196), XL_REAL(0.80000000000000000000), XL_REAL(1));
_xlColor(MediumVioletRed, XL_REAL(0.78039215686274509803), XL_REAL(0.08235294117647058823), XL_REAL(0.52156862745098039215), XL_REAL(1));
_xlColor(MidnightBlue, XL_REAL(0.09803921568627450980), XL_REAL(0.09803921568627450980), XL_REAL(0.43921568627450980392), XL_REAL(1));
_xlColor(MintCream, XL_REAL(0.96078431372549019607), XL_REAL(1.00000000000000000000), XL_REAL(0.98039215686274509803), XL_REAL(1));
_xlColor(MistyRose, XL_REAL(1.00000000000000000000), XL_REAL(0.89411764705882352941), XL_REAL(0.88235294117647058823), XL_REAL(1));
_xlColor(Moccasin, XL_REAL(1.00000000000000000000), XL_REAL(0.89411764705882352941), XL_REAL(0.70980392156862745098), XL_REAL(1));
_xlColor(NavajoWhite, XL_REAL(1.00000000000000000000), XL_REAL(0.87058823529411764705), XL_REAL(0.67843137254901960784), XL_REAL(1));
_xlColor(Navy, XL_REAL(0), XL_REAL(0), XL_REAL(0.50196078431372549019), XL_REAL(1));
_xlColor(OldLace, XL_REAL(0.99215686274509803921), XL_REAL(0.96078431372549019607), XL_REAL(0.90196078431372549019), XL_REAL(1));
_xlColor(Olive, XL_REAL(0.50196078431372549019), XL_REAL(0.50196078431372549019), XL_REAL(0), XL_REAL(1));
_xlColor(OliveDrab, XL_REAL(0.41960784313725490196), XL_REAL(0.55686274509803921568), XL_REAL(0.13725490196078431372), XL_REAL(1));
_xlColor(Orange, XL_REAL(1.00000000000000000000), XL_REAL(0.64705882352941176470), XL_REAL(0), XL_REAL(1));
_xlColor(OrangeRed, XL_REAL(1.00000000000000000000), XL_REAL(0.27058823529411764705), XL_REAL(0), XL_REAL(1));
_xlColor(Orchid, XL_REAL(0.85490196078431372549), XL_REAL(0.43921568627450980392), XL_REAL(0.83921568627450980392), XL_REAL(1));
_xlColor(PaleGoldenRod, XL_REAL(0.93333333333333333333), XL_REAL(0.90980392156862745098), XL_REAL(0.66666666666666666666), XL_REAL(1));
_xlColor(PaleGreen, XL_REAL(0.59607843137254901960), XL_REAL(0.98431372549019607843), XL_REAL(0.59607843137254901960), XL_REAL(1));
_xlColor(PaleTurquoise, XL_REAL(0.68627450980392156862), XL_REAL(0.93333333333333333333), XL_REAL(0.93333333333333333333), XL_REAL(1));
_xlColor(PaleVioletRed, XL_REAL(0.85882352941176470588), XL_REAL(0.43921568627450980392), XL_REAL(0.57647058823529411764), XL_REAL(1));
_xlColor(PapayaWhip, XL_REAL(1.00000000000000000000), XL_REAL(0.93725490196078431372), XL_REAL(0.83529411764705882352), XL_REAL(1));
_xlColor(PeachPuff, XL_REAL(1.00000000000000000000), XL_REAL(0.85490196078431372549), XL_REAL(0.72549019607843137254), XL_REAL(1));
_xlColor(Peru, XL_REAL(0.80392156862745098039), XL_REAL(0.52156862745098039215), XL_REAL(0.24705882352941176470), XL_REAL(1));
_xlColor(Pink, XL_REAL(1.00000000000000000000), XL_REAL(0.75294117647058823529), XL_REAL(0.79607843137254901960), XL_REAL(1));
_xlColor(Plum, XL_REAL(0.86666666666666666666), XL_REAL(0.62745098039215686274), XL_REAL(0.86666666666666666666), XL_REAL(1));
_xlColor(PowderBlue, XL_REAL(0.69019607843137254901), XL_REAL(0.87843137254901960784), XL_REAL(0.90196078431372549019), XL_REAL(1));
_xlColor(Purple, XL_REAL(0.50196078431372549019), XL_REAL(0), XL_REAL(0.50196078431372549019), XL_REAL(1));
_xlColor(Red, XL_REAL(1.00000000000000000000), XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlColor(RosyBrown, XL_REAL(0.73725490196078431372), XL_REAL(0.56078431372549019607), XL_REAL(0.56078431372549019607), XL_REAL(1));
_xlColor(RoyalBlue, XL_REAL(0.25490196078431372549), XL_REAL(0.41176470588235294117), XL_REAL(0.88235294117647058823), XL_REAL(1));
_xlColor(SaddleBrown, XL_REAL(0.54509803921568627450), XL_REAL(0.27058823529411764705), XL_REAL(0.07450980392156862745), XL_REAL(1));
_xlColor(Salmon, XL_REAL(0.98039215686274509803), XL_REAL(0.50196078431372549019), XL_REAL(0.44705882352941176470), XL_REAL(1));
_xlColor(SandyBrown, XL_REAL(0.95686274509803921568), XL_REAL(0.64313725490196078431), XL_REAL(0.37647058823529411764), XL_REAL(1));
_xlColor(SeaGreen, XL_REAL(0.18039215686274509803), XL_REAL(0.54509803921568627450), XL_REAL(0.34117647058823529411), XL_REAL(1));
_xlColor(SeaShell, XL_REAL(1.00000000000000000000), XL_REAL(0.96078431372549019607), XL_REAL(0.93333333333333333333), XL_REAL(1));
_xlColor(Sienna, XL_REAL(0.62745098039215686274), XL_REAL(0.32156862745098039215), XL_REAL(0.17647058823529411764), XL_REAL(1));
_xlColor(Silver, XL_REAL(0.75294117647058823529), XL_REAL(0.75294117647058823529), XL_REAL(0.75294117647058823529), XL_REAL(1));
_xlColor(SkyBlue, XL_REAL(0.52941176470588235294), XL_REAL(0.80784313725490196078), XL_REAL(0.92156862745098039215), XL_REAL(1));
_xlColor(SlateBlue, XL_REAL(0.41568627450980392156), XL_REAL(0.35294117647058823529), XL_REAL(0.80392156862745098039), XL_REAL(1));
_xlColor(SlateGray, XL_REAL(0.43921568627450980392), XL_REAL(0.50196078431372549019), XL_REAL(0.56470588235294117647), XL_REAL(1));
_xlColor(Snow, XL_REAL(1.00000000000000000000), XL_REAL(0.98039215686274509803), XL_REAL(0.98039215686274509803), XL_REAL(1));
_xlColor(SpringGreen, XL_REAL(0), XL_REAL(1.00000000000000000000), XL_REAL(0.49803921568627450980), XL_REAL(1));
_xlColor(SteelBlue, XL_REAL(0.27450980392156862745), XL_REAL(0.50980392156862745098), XL_REAL(0.70588235294117647058), XL_REAL(1));
_xlColor(Tan, XL_REAL(0.82352941176470588235), XL_REAL(0.70588235294117647058), XL_REAL(0.54901960784313725490), XL_REAL(1));
_xlColor(Teal, XL_REAL(0), XL_REAL(0.50196078431372549019), XL_REAL(0.50196078431372549019), XL_REAL(1));
_xlColor(Thistle, XL_REAL(0.84705882352941176470), XL_REAL(0.74901960784313725490), XL_REAL(0.84705882352941176470), XL_REAL(1));
_xlColor(Tomato, XL_REAL(1.00000000000000000000), XL_REAL(0.38823529411764705882), XL_REAL(0.27843137254901960784), XL_REAL(1));
_xlColor(Turquoise, XL_REAL(0.25098039215686274509), XL_REAL(0.87843137254901960784), XL_REAL(0.81568627450980392156), XL_REAL(1));
_xlColor(Violet, XL_REAL(0.93333333333333333333), XL_REAL(0.50980392156862745098), XL_REAL(0.93333333333333333333), XL_REAL(1));
_xlColor(Wheat, XL_REAL(0.96078431372549019607), XL_REAL(0.87058823529411764705), XL_REAL(0.70196078431372549019), XL_REAL(1));
_xlColor(White, XL_REAL(1.00000000000000000000), XL_REAL(1.00000000000000000000), XL_REAL(1.00000000000000000000), XL_REAL(1));
_xlColor(WhiteSmoke, XL_REAL(0.96078431372549019607), XL_REAL(0.96078431372549019607), XL_REAL(0.96078431372549019607), XL_REAL(1));
_xlColor(Yellow, XL_REAL(1.00000000000000000000), XL_REAL(1.00000000000000000000), XL_REAL(0), XL_REAL(1));
_xlColor(YellowGreen, XL_REAL(0.60392156862745098039), XL_REAL(0.80392156862745098039), XL_REAL(0.19607843137254901960), XL_REAL(1));

#undef _xlColor

XLcolor *
xlColorAssignArray(XLcolor *ca, XLreal *array)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { array[0], array[1], array[2], array[3] };
	XL_COLOR_SIMD(ca) = simd;
#else
	xlRealCopy(XL_COLOR_ARRAY(ca), array, 4);
#endif
	return ca;
}

XLcolor *
xlColorAssignReals(XLcolor *ca, XLreal r, XLreal g, XLreal b, XLreal a)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { r, g, b, a };
	XL_COLOR_SIMD(ca) = simd;
#else
	XL_COLOR_R(ca) = r;
	XL_COLOR_G(ca) = g;
	XL_COLOR_B(ca) = b;
	XL_COLOR_A(ca) = a;
#endif
	return ca;
}

xlColorArrayAssignNoneOp(AssignRand, Rand);

XLcolor *
xlColorSwizzle(XLcolor *ca, XLint r, XLint g, XLint b, XLint a)
{
#ifdef XL_SIMD
	XLsimd4si mask = { r, g, b, a };
	XL_COLOR_SIMD(ca) = __builtin_shuffle(XL_COLOR_SIMD(ca), mask);
#else
	XLreal data[4];
	data[0] = XL_COLOR_ARRAY(ca)[r];
	data[1] = XL_COLOR_ARRAY(ca)[g];
	data[2] = XL_COLOR_ARRAY(ca)[b];
	data[3] = XL_COLOR_ARRAY(ca)[a];
	xlRealCopy(XL_COLOR_ARRAY(ca), data, 4);
#endif
	return ca;
}

XLcolor *
xlColorAssignSwizzle(XLcolor *ca, XLcolor *cb, XLint r, XLint g, XLint b, XLint a)
{
#ifdef XL_SIMD
	XLsimd4si mask = { r, g, b, a };
	XL_COLOR_SIMD(ca) = __builtin_shuffle(XL_COLOR_SIMD(cb), mask);
#else
	XL_COLOR_R(ca) = XL_COLOR_ARRAY(cb)[r];
	XL_COLOR_G(ca) = XL_COLOR_ARRAY(cb)[g];
	XL_COLOR_B(ca) = XL_COLOR_ARRAY(cb)[b];
	XL_COLOR_A(ca) = XL_COLOR_ARRAY(cb)[a];
#endif
	return ca;
}

XLcolor *
xlColorAssignSwizzleVector(XLcolor *ca, XLvector *cb, XLint r, XLint g, XLint b, XLint a)
{
//#ifdef XL_SIMD
//!	XLsimd4si mask = { r, g, b, a };
//	XL_COLOR_SIMD(cb) = __builtin_shuffle(XL_COLOR_SIMD(ca), mask);
//#else
	XL_COLOR_R(ca) = XL_VECTOR_ARRAY(cb)[r];
	XL_COLOR_G(ca) = XL_VECTOR_ARRAY(cb)[g];
	XL_COLOR_B(ca) = XL_VECTOR_ARRAY(cb)[b];
	XL_COLOR_A(ca) = XL_VECTOR_ARRAY(cb)[a];
//#endif
	return ca;
}

XLcolor *
xlColorAssignSwizzleMatrix(XLcolor *ca, XLmatrix *cb, XLint r, XLint g, XLint b, XLint a)
{
	XL_COLOR_R(ca) = XL_MATRIX_ARRAY(cb)[r];
	XL_COLOR_G(ca) = XL_MATRIX_ARRAY(cb)[g];
	XL_COLOR_B(ca) = XL_MATRIX_ARRAY(cb)[b];
	XL_COLOR_A(ca) = XL_MATRIX_ARRAY(cb)[a];
	return ca;
}

XLcolor *
xlColorAssignMatrixForward(XLcolor *ca, XLmatrix *cb)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_ZX(cb), XL_MATRIX_ZY(cb), XL_MATRIX_ZZ(cb), XL_MATRIX_ZW(cb) };
	XL_COLOR_SIMD(ca) = -simd;
#else
	XL_COLOR_R(ca) = -XL_MATRIX_ZX(cb);
	XL_COLOR_G(ca) = -XL_MATRIX_ZY(cb);
	XL_COLOR_B(ca) = -XL_MATRIX_ZZ(cb);
	XL_COLOR_A(ca) = -XL_MATRIX_ZW(cb);
#endif
	return ca;
}

XLcolor *
xlColorAssignMatrixUp(XLcolor *ca, XLmatrix *cb)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_YX(cb), XL_MATRIX_YY(cb), XL_MATRIX_YZ(cb), XL_MATRIX_YW(cb) };
	XL_COLOR_SIMD(ca) = simd;
#else
	XL_COLOR_R(ca) = XL_MATRIX_YX(cb);
	XL_COLOR_G(ca) = XL_MATRIX_YY(cb);
	XL_COLOR_B(ca) = XL_MATRIX_YZ(cb);
	XL_COLOR_A(ca) = XL_MATRIX_YW(cb);
#endif
	return ca;
}

XLcolor *
xlColorAssignMatrixRight(XLcolor *ca, XLmatrix *cb)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XX(cb), XL_MATRIX_XY(cb), XL_MATRIX_XZ(cb), XL_MATRIX_XW(cb) };
	XL_COLOR_SIMD(ca) = simd;
#else
	XL_COLOR_R(ca) = XL_MATRIX_XX(cb);
	XL_COLOR_G(ca) = XL_MATRIX_XY(cb);
	XL_COLOR_B(ca) = XL_MATRIX_XZ(cb);
	XL_COLOR_A(ca) = XL_MATRIX_XW(cb);
#endif
	return ca;
}

XLcolor *
xlColorAssignMatrixPosition(XLcolor *ca, XLmatrix *cb)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XW(cb), XL_MATRIX_YW(cb), XL_MATRIX_ZW(cb), XL_MATRIX_WW(cb) };
	XL_COLOR_SIMD(ca) = simd;
#else
	XL_COLOR_R(ca) = XL_MATRIX_XW(cb);
	XL_COLOR_G(ca) = XL_MATRIX_YW(cb);
	XL_COLOR_B(ca) = XL_MATRIX_ZW(cb);
	XL_COLOR_A(ca) = XL_MATRIX_WW(cb);
#endif
	return ca;
}

XLcolor *
xlColorAssignMatrixScalation(XLcolor *ca, XLmatrix *cb)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_MATRIX_XX(cb), XL_MATRIX_YY(cb), XL_MATRIX_ZZ(cb), XL_MATRIX_WW(cb) };
	XL_COLOR_SIMD(ca) = simd;
#else
	XL_COLOR_R(ca) = XL_MATRIX_XX(cb);
	XL_COLOR_G(ca) = XL_MATRIX_YY(cb);
	XL_COLOR_B(ca) = XL_MATRIX_ZZ(cb);
	XL_COLOR_A(ca) = XL_MATRIX_ZW(cb);
#endif
	return ca;
}

XLcolor *
xlColorClear(XLcolor *ca)
{
#ifdef XL_SIMD
	XLsimd4sr simd = { XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0) };
	XL_COLOR_SIMD(ca) = simd;
#else
	xlMemoryZero(ca, sizeof(XLcolor));
#endif
	return ca;
}

XLcolor *
xlColorCopy(XLcolor *ca)
{
	XLcolor *cb;

	cb = xlColorAlloc();
	return xlColorAssignCopy(cb, ca);
}

XLcolor *
xlColorAssignCopy(XLcolor *ca, XLcolor *cb)
{
#ifdef XL_SIMD
	XL_COLOR_SIMD(ca) = XL_COLOR_SIMD(cb);
#else
	xlMemoryCopy(ca, cb, sizeof(XLcolor));
#endif
	return ca;
}

xlColorOp(Comp, Comp);
xlColorAssignOpColor(AssignComp, Comp);

xlColorOp(Neg, Neg);
xlColorAssignOpColor(AssignNeg, Neg);

xlColorOp(Inc, Inc);
xlColorAssignOpColor(AssignInc, Inc);

xlColorOp(Dec, Dec);
xlColorAssignOpColor(AssignDec, Dec);

xlColorArrayOp(Abs, Abs);
xlColorArrayAssignOpColor(AssignAbs, Abs);

XLreal
xlColorSquareNorm(XLcolor *ca)
{
	return xlColorDot(ca, ca);
}

XLreal
xlColorNorm(XLcolor *ca)
{
	return xlRealSquareRoot(xlColorSquareNorm(ca));
}

XLcolor *
xlColorNormal(XLcolor *ca)
{
	return xlColorMultReal(ca, XL_REAL(1) / xlColorNorm(ca));
}

XLcolor *
xlColorAssignNormal(XLcolor *ca, XLcolor *cb)
{
	return xlColorAssignMultReal(ca, cb, XL_REAL(1) / xlColorNorm(cb));
}

xlColorArrayBooleanOpColor(BooleanEqual, Equal);
xlColorOpColor(ColorEqual, Equal);
xlColorAssignOpColorColor(ColorAssignEqual, Equal);

xlColorArrayBooleanOpColor(BooleanGreater, Greater);
xlColorOpColor(ColorGreater, Greater);
xlColorAssignOpColorColor(ColorAssignGreater, Greater);

xlColorArrayBooleanOpColor(BooleanLesser, Lesser);
xlColorOpColor(ColorLesser, Lesser);
xlColorAssignOpColorColor(ColorAssignLesser, Lesser);

XLreal
xlColorAngle(XLcolor *ca, XLcolor *cb)
{
	return xlRealRadToDeg(xlRealArcCosine(xlColorDot(ca, cb) / (xlColorNorm(ca) * xlColorNorm(cb))));
}

XLreal
xlColorDot(XLcolor *ca, XLcolor *cb)
{
	XLreal r;
#ifdef XL_SIMD
	XLsimd4sr simd;
	simd = XL_COLOR_SIMD(ca) * XL_COLOR_SIMD(cb);
	r = simd[0] + simd[1] + simd[2] + simd[3];
#else
	r = XL_COLOR_R(ca) * XL_COLOR_R(cb) + XL_COLOR_G(ca) * XL_COLOR_G(cb) + XL_COLOR_B(ca) * XL_COLOR_B(cb) + XL_COLOR_A(ca) * XL_COLOR_A(cb);
#endif
	return r;
}

xlColorOpReal(AndReal, And);
xlColorAssignOpColorReal(AssignAndReal, And);
xlColorOpColor(And, And);
xlColorAssignOpColorColor(AssignAnd, And);

xlColorOpReal(OrReal, Or);
xlColorAssignOpColorReal(AssignOrReal, Or);
xlColorOpColor(Or, Or);
xlColorAssignOpColorColor(AssignOr, Or);

xlColorOpReal(XorReal, Xor);
xlColorAssignOpColorReal(AssignXorReal, Xor);
xlColorOpColor(Xor, Xor);
xlColorAssignOpColorColor(AssignXor, Xor);

xlColorOpReal(LShiftReal, LShift);
xlColorAssignOpColorReal(AssignLShiftReal, LShift);
xlColorOpColor(LShift, LShift);
xlColorAssignOpColorColor(AssignLShift, LShift);

xlColorOpReal(RShiftReal, RShift);
xlColorAssignOpColorReal(AssignRShiftReal, RShift);
xlColorOpColor(RShift, RShift);
xlColorAssignOpColorColor(AssignRShift, RShift);

xlColorOpReal(AddReal, Add);
xlColorAssignOpColorReal(AssignAddReal, Add);
xlColorOpColor(Add, Add);
xlColorAssignOpColorColor(AssignAdd, Add);

xlColorOpReal(SubReal, Sub);
xlColorAssignOpColorReal(AssignSubReal, Sub);
xlColorOpColor(Sub, Sub);
xlColorAssignOpColorColor(AssignSub, Sub);

xlColorOpReal(MultReal, Mult);
xlColorAssignOpColorReal(AssignMultReal, Mult);
xlColorOpColor(Mult, Mult);
xlColorAssignOpColorColor(AssignMult, Mult);
xlColorOpMatrix(MultMatrix, Mult);
xlColorAssignOpColorMatrix(AssignMultMatrix, Mult);

xlColorOpReal(DivReal, Div);
xlColorAssignOpColorReal(AssignDivReal, Div);
xlColorOpColor(Div, Div);
xlColorAssignOpColorColor(AssignDiv, Div);
xlColorOpMatrix(DivMatrix, Div);
xlColorAssignOpColorMatrix(AssignDivMatrix, Div);

xlColorOpReal(ModReal, Mod);
xlColorAssignOpColorReal(AssignModReal, Mod);
xlColorOpColor(Mod, Mod);
xlColorAssignOpColorColor(AssignMod, Mod);
xlColorOpMatrix(ModMatrix, Mod);
xlColorAssignOpColorMatrix(AssignModMatrix, Mod);

xlColorOpReal(InvDivReal, InvDiv);
xlColorAssignOpColorReal(AssignInvDivReal, InvDiv);
xlColorOpColor(InvDiv, InvDiv);
xlColorAssignOpColorColor(AssignInvDiv, InvDiv);
xlColorOpMatrix(InvDivMatrix, InvDiv);
xlColorAssignOpColorMatrix(AssignInvDivMatrix, InvDiv);

//!
XLcolor *
xlColorCross(XLcolor *ca, XLcolor *cb)
{
#ifdef XL_SIMD
	XLsimd4si mask[2] = { { 1, 2, 0, 3 }, { 2, 0, 1, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_COLOR_SIMD(ca), mask[0]);
	simd[1] = __builtin_shuffle(XL_COLOR_SIMD(cb), mask[1]);
	simd[2] = __builtin_shuffle(XL_COLOR_SIMD(ca), mask[1]);
	simd[3] = __builtin_shuffle(XL_COLOR_SIMD(cb), mask[0]);
	XL_COLOR_SIMD(ca) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XLreal data[4];
	data[0] = XL_COLOR_G(ca) * XL_COLOR_B(cb) - XL_COLOR_B(ca) * XL_COLOR_G(cb);
	data[1] = XL_COLOR_B(ca) * XL_COLOR_R(cb) - XL_COLOR_R(ca) * XL_COLOR_B(cb);
	data[2] = XL_COLOR_R(ca) * XL_COLOR_G(cb) - XL_COLOR_G(ca) * XL_COLOR_R(cb);
	data[3] = XL_COLOR_A(ca) * XL_COLOR_A(cb) - XL_COLOR_A(ca) * XL_COLOR_A(cb);
	xlRealCopy(XL_COLOR_ARRAY(ca), data, 4);
#endif
	return ca;
}

//!
XLcolor *
xlColorAssignCross(XLcolor *ca, XLcolor *cb, XLcolor *cc)
{
#ifdef XL_SIMD
	XLsimd4si mask[2] = { { 1, 2, 0, 3 }, { 2, 0, 1, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_COLOR_SIMD(cb), mask[0]);
	simd[1] = __builtin_shuffle(XL_COLOR_SIMD(cc), mask[1]);
	simd[2] = __builtin_shuffle(XL_COLOR_SIMD(cb), mask[1]);
	simd[3] = __builtin_shuffle(XL_COLOR_SIMD(cc), mask[0]);
	XL_COLOR_SIMD(ca) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XL_COLOR_R(ca) = XL_COLOR_G(cb) * XL_COLOR_B(cc) - XL_COLOR_B(cb) * XL_COLOR_G(cc);
	XL_COLOR_G(ca) = XL_COLOR_B(cb) * XL_COLOR_R(cc) - XL_COLOR_R(cb) * XL_COLOR_B(cc);
	XL_COLOR_B(ca) = XL_COLOR_R(cb) * XL_COLOR_G(cc) - XL_COLOR_G(cb) * XL_COLOR_R(cc);
	XL_COLOR_A(ca) = XL_COLOR_A(cb) * XL_COLOR_A(cc) - XL_COLOR_A(cb) * XL_COLOR_A(cc);
#endif
	return ca;
}

xlColorArrayOpColor(Min, Min);
xlColorArrayAssignOpColorColor(AssignMin, Min);

xlColorArrayOpColor(Max, Max);
xlColorArrayAssignOpColorColor(AssignMax, Max);

xlColorArrayOpRealReal(ClampReal, Clamp);
xlColorArrayAssignOpColorRealReal(AssignClampReal, Clamp);
xlColorArrayOpColorColor(Clamp, Clamp);
xlColorArrayAssignOpColorColorColor(AssignClamp, Clamp);

xlColorArrayAssignNoneOpRealReal(AssignRandRangeReal, RandRange);
xlColorArrayAssignNoneOpColorColor(AssignRandRange, RandRange);

XLcolor *
xlColorRotate(XLcolor *ca, XLcolor *axis, XLreal angle)
{
	XLmatrix m;
	XLvector v;
	xlVectorAssignArray(&v, XL_COLOR_ARRAY(axis));
	xlMatrixAssignRotation(&m, &v, angle);
	return xlColorMultMatrix(ca, &m);
}

XLcolor *
xlColorAssignRotate(XLcolor *ca, XLcolor *cb, XLcolor *axis, XLreal angle)
{
	XLmatrix m;
	XLvector v;
	xlVectorAssignArray(&v, XL_COLOR_ARRAY(axis));
	xlMatrixAssignRotation(&m, &v, angle);
	return xlColorAssignMultMatrix(ca, cb, &m);
}

xlColorOpColorReal(Lerp, Lerp);
xlColorAssignOpColorColorReal(AssignLerp, Lerp);

xlColorOpColorColorReal(QuadBezier, QuadBezier);
xlColorAssignOpColorColorColorReal(AssignQuadBezier, QuadBezier);

xlColorOpColorColorColorReal(CubicBezier, CubicBezier);
xlColorAssignOpColorColorColorColorReal(AssignCubicBezier, CubicBezier);

#define _xlColorInit(e, c) \
	xlColor ## c = &_xlColor ## c; \
	xlColorAssign ## c(xlColor ## c);

void
xlColorInit()
{
	xlColorsForEach(_xlColorInit)
}

#undef _xlColorInit

void
xlColorFini()
{
}

#undef xlColorAssignOpColorColorColorColorReal
#undef xlColorOpColorColorColorReal
#undef xlColorAssignOpColorColorColorReal
#undef xlColorOpColorColorReal
#undef xlColorAssignOpColorColorReal
#undef xlColorOpColorReal
#undef xlColorAssignOpColorMatrix
#undef xlColorOpMatrix
#undef xlColorAssignOpColorColor
#undef xlColorOpColor
#undef xlColorAssignOpColorReal
#undef xlColorOpReal
#undef xlColorAssignOpColor
#undef xlColorOp
#undef xlColorArrayAssignOpColorColorColor
#undef xlColorArrayOpColorColor
#undef xlColorArrayAssignOpColorRealReal
#undef xlColorArrayOpRealReal
#undef xlColorArrayAssignOpColorColor
#undef xlColorArrayOpColor
#undef xlColorArrayBooleanOpColor
#undef xlColorArrayAssignOpColor
#undef xlColorArrayOp
