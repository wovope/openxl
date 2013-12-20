/* http://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html */

#include "XL/xlMatrix.h"
#include "XL/xl.h"

#define xlMatrixArrayAssignNoneOp(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(); \
		XL_MATRIX_YX(a) = xlReal ## Op(); \
		XL_MATRIX_ZX(a) = xlReal ## Op(); \
		XL_MATRIX_WX(a) = xlReal ## Op(); \
		XL_MATRIX_XY(a) = xlReal ## Op(); \
		XL_MATRIX_YY(a) = xlReal ## Op(); \
		XL_MATRIX_ZY(a) = xlReal ## Op(); \
		XL_MATRIX_WY(a) = xlReal ## Op(); \
		XL_MATRIX_XZ(a) = xlReal ## Op(); \
		XL_MATRIX_YZ(a) = xlReal ## Op(); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(); \
		XL_MATRIX_WZ(a) = xlReal ## Op(); \
		XL_MATRIX_XW(a) = xlReal ## Op(); \
		XL_MATRIX_YW(a) = xlReal ## Op(); \
		XL_MATRIX_ZW(a) = xlReal ## Op(); \
		XL_MATRIX_WW(a) = xlReal ## Op(); \
		return a; \
	}
#define xlMatrixArrayOp(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(a)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(a)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(a)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(a)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(a)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(a)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(a)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(a)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(a)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(a)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(a)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(a)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(a)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(a)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(a)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(a)); \
		return a; \
	}
#define xlMatrixArrayAssignOpMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b)); \
		return a; \
	}
#define xlMatrixArrayBooleanOpMatrix(Name, Op) \
	XLboolean \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b) \
	{ \
		return \
			xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_XX(b)) && \
			xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_YX(b)) && \
			xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_ZX(b)) && \
			xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_WX(b)) && \
			xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_XY(b)) && \
			xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_YY(b)) && \
			xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_ZY(b)) && \
			xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_WY(b)) && \
			xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_XZ(b)) && \
			xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_YZ(b)) && \
			xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_ZZ(b)) && \
			xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_WZ(b)) && \
			xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_XW(b)) && \
			xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_YW(b)) && \
			xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_ZW(b)) && \
			xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_WW(b)); \
	}
#define xlMatrixArrayOpMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_XX(b)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_YX(b)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_ZX(b)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_WX(b)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_XY(b)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_YY(b)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_ZY(b)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_WY(b)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_XZ(b)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_YZ(b)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_ZZ(b)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_WZ(b)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_XW(b)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_YW(b)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_ZW(b)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_WW(b)); \
		return a; \
	}
#define xlMatrixArrayAssignOpMatrixMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_XX(c)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_YX(c)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_ZX(c)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_WX(c)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_XY(c)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_YY(c)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_ZY(c)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_WY(c)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_XZ(c)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_YZ(c)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_WZ(c)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_XW(c)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_YW(c)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_ZW(c)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_WW(c)); \
		return a; \
	}
#define xlMatrixArrayAssignNoneOpRealReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLreal b, XLreal c) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(b, c); \
		XL_MATRIX_YX(a) = xlReal ## Op(b, c); \
		XL_MATRIX_ZX(a) = xlReal ## Op(b, c); \
		XL_MATRIX_WX(a) = xlReal ## Op(b, c); \
		XL_MATRIX_XY(a) = xlReal ## Op(b, c); \
		XL_MATRIX_YY(a) = xlReal ## Op(b, c); \
		XL_MATRIX_ZY(a) = xlReal ## Op(b, c); \
		XL_MATRIX_WY(a) = xlReal ## Op(b, c); \
		XL_MATRIX_XZ(a) = xlReal ## Op(b, c); \
		XL_MATRIX_YZ(a) = xlReal ## Op(b, c); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(b, c); \
		XL_MATRIX_WZ(a) = xlReal ## Op(b, c); \
		XL_MATRIX_XW(a) = xlReal ## Op(b, c); \
		XL_MATRIX_YW(a) = xlReal ## Op(b, c); \
		XL_MATRIX_ZW(a) = xlReal ## Op(b, c); \
		XL_MATRIX_WW(a) = xlReal ## Op(b, c); \
		return a; \
	}
#define xlMatrixArrayAssignNoneOpMatrixMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c) \
	{ \
    		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_XX(c)); \
    		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_YX(c)); \
    		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_ZX(c)); \
    		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_WX(c)); \
    		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_XY(c)); \
    		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_YY(c)); \
    		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_ZY(c)); \
    		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_WY(c)); \
    		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_XZ(c)); \
    		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_YZ(c)); \
    		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c)); \
    		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_WZ(c)); \
    		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_XW(c)); \
    		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_YW(c)); \
    		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_ZW(c)); \
    		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_WW(c)); \
		return a; \
	}
#define xlMatrixArrayOpRealReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLreal b, XLreal c) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(a), b, c); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(a), b, c); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(a), b, c); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(a), b, c); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(a), b, c); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(a), b, c); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(a), b, c); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(a), b, c); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(a), b, c); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(a), b, c); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(a), b, c); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(a), b, c); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(a), b, c); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(a), b, c); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(a), b, c); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(a), b, c); \
		return a; \
	}
#define xlMatrixArrayAssignOpMatrixRealReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLreal c, XLreal d) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b), c, d); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b), c, d); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b), c, d); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b), c, d); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b), c, d); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b), c, d); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b), c, d); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b), c, d); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), c, d); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b), c, d); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b), c, d); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b), c, d); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b), c, d); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b), c, d); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b), c, d); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b), c, d); \
		return a; \
	}
#define xlMatrixArrayOpMatrixMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_XX(b), XL_MATRIX_XX(c)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_YX(b), XL_MATRIX_YX(c)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_ZX(b), XL_MATRIX_ZX(c)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_WX(b), XL_MATRIX_WX(c)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_XY(b), XL_MATRIX_XY(c)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_YY(b), XL_MATRIX_YY(c)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_ZY(b), XL_MATRIX_ZY(c)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_WY(b), XL_MATRIX_WY(c)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_XZ(b), XL_MATRIX_XZ(c)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_YZ(b), XL_MATRIX_YZ(c)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_WZ(b), XL_MATRIX_WZ(c)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_XW(b), XL_MATRIX_XW(c)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_YW(b), XL_MATRIX_YW(c)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_ZW(b), XL_MATRIX_ZW(c)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_WW(b), XL_MATRIX_WW(c)); \
		return a; \
	}
#define xlMatrixArrayAssignOpMatrixMatrixMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_XX(c), XL_MATRIX_XX(d)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_YX(c), XL_MATRIX_YX(d)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_ZX(c), XL_MATRIX_ZX(d)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_WX(c), XL_MATRIX_WX(d)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_XY(c), XL_MATRIX_XY(d)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_YY(c), XL_MATRIX_YY(d)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_ZY(c), XL_MATRIX_ZY(d)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_WY(c), XL_MATRIX_WY(d)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_XZ(c), XL_MATRIX_XZ(d)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_YZ(c), XL_MATRIX_YZ(d)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c), XL_MATRIX_ZZ(d)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_WZ(c), XL_MATRIX_WZ(d)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_XW(c), XL_MATRIX_XW(d)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_YW(c), XL_MATRIX_YW(d)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_ZW(c), XL_MATRIX_ZW(d)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_WW(c), XL_MATRIX_WW(d)); \
		return a; \
	}

#ifdef XL_SIMD
#define xlMatrixOp(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op(XL_MATRIX_SIMD(a)); \
		return a; \
	}
#define xlMatrixAssignOpMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op(XL_MATRIX_SIMD(b)); \
		return a; \
	}
#define xlMatrixOpReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLreal r) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op ## Real(XL_MATRIX_SIMD(a), r); \
		return a; \
	}
#define xlMatrixAssignOpMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLreal r) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op ## Real(XL_MATRIX_SIMD(b), r); \
		return a; \
	}
#define xlMatrixOpMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op(XL_MATRIX_SIMD(a), XL_MATRIX_SIMD(b)); \
		return a; \
	}
#define xlMatrixAssignOpMatrixMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op(XL_MATRIX_SIMD(b), XL_MATRIX_SIMD(c)); \
		return a; \
	}
#define xlMatrixMatricialOpMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b) \
	{ \
		XLsimd4sr simda[4] = { \
			{ XL_MATRIX_SIMD(a)[0], XL_MATRIX_SIMD(a)[1], XL_MATRIX_SIMD(a)[2], XL_MATRIX_SIMD(a)[3] }, \
			{ XL_MATRIX_SIMD(a)[4], XL_MATRIX_SIMD(a)[5], XL_MATRIX_SIMD(a)[6], XL_MATRIX_SIMD(a)[7] }, \
			{ XL_MATRIX_SIMD(a)[8], XL_MATRIX_SIMD(a)[9], XL_MATRIX_SIMD(a)[10], XL_MATRIX_SIMD(a)[11] }, \
			{ XL_MATRIX_SIMD(a)[12], XL_MATRIX_SIMD(a)[13], XL_MATRIX_SIMD(a)[14], XL_MATRIX_SIMD(a)[15] } \
		}; \
		XLsimd4sr simdb[4] = { \
			{ XL_MATRIX_SIMD(b)[0], XL_MATRIX_SIMD(b)[4], XL_MATRIX_SIMD(b)[8], XL_MATRIX_SIMD(b)[12] }, \
			{ XL_MATRIX_SIMD(b)[1], XL_MATRIX_SIMD(b)[5], XL_MATRIX_SIMD(b)[9], XL_MATRIX_SIMD(b)[13] }, \
			{ XL_MATRIX_SIMD(b)[2], XL_MATRIX_SIMD(b)[6], XL_MATRIX_SIMD(b)[10], XL_MATRIX_SIMD(b)[14] }, \
			{ XL_MATRIX_SIMD(b)[3], XL_MATRIX_SIMD(b)[7], XL_MATRIX_SIMD(b)[11], XL_MATRIX_SIMD(b)[15] } \
		}; \
		XLsimd4sr simdm[16]; \
		simdm[ 0] = xlSimd4sr ## Op(simda[0], simdb[0]); \
		simdm[ 1] = xlSimd4sr ## Op(simda[0], simdb[1]); \
		simdm[ 2] = xlSimd4sr ## Op(simda[0], simdb[2]); \
		simdm[ 3] = xlSimd4sr ## Op(simda[0], simdb[3]); \
		simdm[ 4] = xlSimd4sr ## Op(simda[1], simdb[0]); \
		simdm[ 5] = xlSimd4sr ## Op(simda[1], simdb[1]); \
		simdm[ 6] = xlSimd4sr ## Op(simda[1], simdb[2]); \
		simdm[ 7] = xlSimd4sr ## Op(simda[1], simdb[3]); \
		simdm[ 8] = xlSimd4sr ## Op(simda[2], simdb[0]); \
		simdm[ 9] = xlSimd4sr ## Op(simda[2], simdb[1]); \
		simdm[10] = xlSimd4sr ## Op(simda[2], simdb[2]); \
		simdm[11] = xlSimd4sr ## Op(simda[2], simdb[3]); \
		simdm[12] = xlSimd4sr ## Op(simda[3], simdb[0]); \
		simdm[13] = xlSimd4sr ## Op(simda[3], simdb[1]); \
		simdm[14] = xlSimd4sr ## Op(simda[3], simdb[2]); \
		simdm[15] = xlSimd4sr ## Op(simda[3], simdb[3]); \
		XLsimd4sr simdt[16] = \
		{ \
			{ simdm[0][0], simdm[1][0], simdm[2][0], simdm[3][0] }, \
			{ simdm[0][1], simdm[1][1], simdm[2][1], simdm[3][1] }, \
			{ simdm[0][2], simdm[1][2], simdm[2][2], simdm[3][2] }, \
			{ simdm[0][3], simdm[1][3], simdm[2][3], simdm[3][3] }, \
			{ simdm[4][0], simdm[5][0], simdm[6][0], simdm[7][0] }, \
			{ simdm[4][1], simdm[5][1], simdm[6][1], simdm[7][1] }, \
			{ simdm[4][2], simdm[5][2], simdm[6][2], simdm[7][2] }, \
			{ simdm[4][3], simdm[5][3], simdm[6][3], simdm[7][3] }, \
			{ simdm[8][0], simdm[9][0], simdm[10][0], simdm[11][0] }, \
			{ simdm[8][1], simdm[9][1], simdm[10][1], simdm[11][1] }, \
			{ simdm[8][2], simdm[9][2], simdm[10][2], simdm[11][2] }, \
			{ simdm[8][3], simdm[9][3], simdm[10][3], simdm[11][3] }, \
			{ simdm[12][0], simdm[13][0], simdm[14][0], simdm[15][0] }, \
			{ simdm[12][1], simdm[13][1], simdm[14][1], simdm[15][1] }, \
			{ simdm[12][2], simdm[13][2], simdm[14][2], simdm[15][2] }, \
			{ simdm[12][3], simdm[13][3], simdm[14][3], simdm[15][3] } \
		}; \
		XLsimd4sr simds[4] = \
		{ \
			simdt[0] + simdt[1] + simdt[2] + simdt[3], \
			simdt[4] + simdt[5] + simdt[6] + simdt[7], \
			simdt[8] + simdt[9] + simdt[10] + simdt[11], \
			simdt[12] + simdt[13] + simdt[14] + simdt[15] \
		}; \
		XLsimd16sr simd = \
		{ \
			simds[0][0], simds[0][1], simds[0][2], simds[0][3], \
			simds[1][0], simds[1][1], simds[1][2], simds[1][3], \
			simds[2][0], simds[2][1], simds[2][2], simds[2][3], \
			simds[3][0], simds[3][1], simds[3][2], simds[3][3] \
		}; \
		XL_MATRIX_SIMD(a) = simd; \
		return a; \
	}
#define xlMatrixAssignMatricialOpMatrixMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c) \
	{ \
		XLsimd4sr simda[4] = { \
			{ XL_MATRIX_SIMD(b)[0], XL_MATRIX_SIMD(b)[1], XL_MATRIX_SIMD(b)[2], XL_MATRIX_SIMD(b)[3] }, \
			{ XL_MATRIX_SIMD(b)[4], XL_MATRIX_SIMD(b)[5], XL_MATRIX_SIMD(b)[6], XL_MATRIX_SIMD(b)[7] }, \
			{ XL_MATRIX_SIMD(b)[8], XL_MATRIX_SIMD(b)[9], XL_MATRIX_SIMD(b)[10], XL_MATRIX_SIMD(b)[11] }, \
			{ XL_MATRIX_SIMD(b)[12], XL_MATRIX_SIMD(b)[13], XL_MATRIX_SIMD(b)[14], XL_MATRIX_SIMD(b)[15] } \
		}; \
		XLsimd4sr simdb[4] = { \
			{ XL_MATRIX_SIMD(c)[0], XL_MATRIX_SIMD(c)[4], XL_MATRIX_SIMD(c)[8], XL_MATRIX_SIMD(c)[12] }, \
			{ XL_MATRIX_SIMD(c)[1], XL_MATRIX_SIMD(c)[5], XL_MATRIX_SIMD(c)[9], XL_MATRIX_SIMD(c)[13] }, \
			{ XL_MATRIX_SIMD(c)[2], XL_MATRIX_SIMD(c)[6], XL_MATRIX_SIMD(c)[10], XL_MATRIX_SIMD(c)[14] }, \
			{ XL_MATRIX_SIMD(c)[3], XL_MATRIX_SIMD(c)[7], XL_MATRIX_SIMD(c)[11], XL_MATRIX_SIMD(c)[15] } \
		}; \
		XLsimd4sr simdm[16]; \
		simdm[ 0] = xlSimd4sr ## Op(simda[0], simdb[0]); \
		simdm[ 1] = xlSimd4sr ## Op(simda[0], simdb[1]); \
		simdm[ 2] = xlSimd4sr ## Op(simda[0], simdb[2]); \
		simdm[ 3] = xlSimd4sr ## Op(simda[0], simdb[3]); \
		simdm[ 4] = xlSimd4sr ## Op(simda[1], simdb[0]); \
		simdm[ 5] = xlSimd4sr ## Op(simda[1], simdb[1]); \
		simdm[ 6] = xlSimd4sr ## Op(simda[1], simdb[2]); \
		simdm[ 7] = xlSimd4sr ## Op(simda[1], simdb[3]); \
		simdm[ 8] = xlSimd4sr ## Op(simda[2], simdb[0]); \
		simdm[ 9] = xlSimd4sr ## Op(simda[2], simdb[1]); \
		simdm[10] = xlSimd4sr ## Op(simda[2], simdb[2]); \
		simdm[11] = xlSimd4sr ## Op(simda[2], simdb[3]); \
		simdm[12] = xlSimd4sr ## Op(simda[3], simdb[0]); \
		simdm[13] = xlSimd4sr ## Op(simda[3], simdb[1]); \
		simdm[14] = xlSimd4sr ## Op(simda[3], simdb[2]); \
		simdm[15] = xlSimd4sr ## Op(simda[3], simdb[3]); \
		XLsimd4sr simdt[16] = \
		{ \
			{ simdm[0][0], simdm[1][0], simdm[2][0], simdm[3][0] }, \
			{ simdm[0][1], simdm[1][1], simdm[2][1], simdm[3][1] }, \
			{ simdm[0][2], simdm[1][2], simdm[2][2], simdm[3][2] }, \
			{ simdm[0][3], simdm[1][3], simdm[2][3], simdm[3][3] }, \
			{ simdm[4][0], simdm[5][0], simdm[6][0], simdm[7][0] }, \
			{ simdm[4][1], simdm[5][1], simdm[6][1], simdm[7][1] }, \
			{ simdm[4][2], simdm[5][2], simdm[6][2], simdm[7][2] }, \
			{ simdm[4][3], simdm[5][3], simdm[6][3], simdm[7][3] }, \
			{ simdm[8][0], simdm[9][0], simdm[10][0], simdm[11][0] }, \
			{ simdm[8][1], simdm[9][1], simdm[10][1], simdm[11][1] }, \
			{ simdm[8][2], simdm[9][2], simdm[10][2], simdm[11][2] }, \
			{ simdm[8][3], simdm[9][3], simdm[10][3], simdm[11][3] }, \
			{ simdm[12][0], simdm[13][0], simdm[14][0], simdm[15][0] }, \
			{ simdm[12][1], simdm[13][1], simdm[14][1], simdm[15][1] }, \
			{ simdm[12][2], simdm[13][2], simdm[14][2], simdm[15][2] }, \
			{ simdm[12][3], simdm[13][3], simdm[14][3], simdm[15][3] } \
		}; \
		XLsimd4sr simds[4] = \
		{ \
			simdt[0] + simdt[1] + simdt[2] + simdt[3], \
			simdt[4] + simdt[5] + simdt[6] + simdt[7], \
			simdt[8] + simdt[9] + simdt[10] + simdt[11], \
			simdt[12] + simdt[13] + simdt[14] + simdt[15] \
		}; \
		XLsimd16sr simd = \
		{ \
			simds[0][0], simds[0][1], simds[0][2], simds[0][3], \
			simds[1][0], simds[1][1], simds[1][2], simds[1][3], \
			simds[2][0], simds[2][1], simds[2][2], simds[2][3], \
			simds[3][0], simds[3][1], simds[3][2], simds[3][3] \
		}; \
		XL_MATRIX_SIMD(a) = simd; \
		return a; \
	}
#define xlMatrixOpMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLreal r) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op(XL_MATRIX_SIMD(a), XL_MATRIX_SIMD(b), r); \
		return a; \
	}
#define xlMatrixAssignOpMatrixMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLreal r) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op(XL_MATRIX_SIMD(b), XL_MATRIX_SIMD(c), r); \
		return a; \
	}
#define xlMatrixOpMatrixMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLreal r) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op(XL_MATRIX_SIMD(a), XL_MATRIX_SIMD(b), XL_MATRIX_SIMD(c), r); \
		return a; \
	}
#define xlMatrixAssignOpMatrixMatrixMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d, XLreal r) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op(XL_MATRIX_SIMD(b), XL_MATRIX_SIMD(c), XL_MATRIX_SIMD(d), r); \
		return a; \
	}
#define xlMatrixOpMatrixMatrixMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d, XLreal r) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op(XL_MATRIX_SIMD(a), XL_MATRIX_SIMD(b), XL_MATRIX_SIMD(c), XL_MATRIX_SIMD(d), r); \
		return a; \
	}
#define xlMatrixAssignOpMatrixMatrixMatrixMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d, XLmatrix *e, XLreal r) \
	{ \
		XL_MATRIX_SIMD(a) = xlSimd16sr ## Op(XL_MATRIX_SIMD(b), XL_MATRIX_SIMD(c), XL_MATRIX_SIMD(d), XL_MATRIX_SIMD(e), r); \
		return a; \
	}
#else
#define xlMatrixOp(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(a)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(a)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(a)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(a)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(a)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(a)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(a)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(a)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(a)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(a)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(a)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(a)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(a)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(a)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(a)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(a)); \
		return a; \
	}
#define xlMatrixAssignOpMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b)); \
		return a; \
	}
#define xlMatrixOpReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLreal r) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(a), r); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(a), r); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(a), r); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(a), r); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(a), r); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(a), r); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(a), r); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(a), r); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(a), r); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(a), r); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(a), r); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(a), r); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(a), r); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(a), r); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(a), r); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(a), r); \
		return a; \
	}
#define xlMatrixAssignOpMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLreal r) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b), r); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b), r); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b), r); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b), r); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b), r); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b), r); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b), r); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b), r); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), r); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b), r); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b), r); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b), r); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b), r); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b), r); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b), r); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b), r); \
		return a; \
	}
#define xlMatrixOpMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_XX(b)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_YX(b)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_ZX(b)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_WX(b)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_XY(b)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_YY(b)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_ZY(b)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_WY(b)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_XZ(b)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_YZ(b)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_ZZ(b)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_WZ(b)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_XW(b)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_YW(b)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_ZW(b)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_WW(b)); \
		return a; \
	}
#define xlMatrixAssignOpMatrixMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_XX(c)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_YX(c)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_ZX(c)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_WX(c)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_XY(c)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_YY(c)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_ZY(c)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_WY(c)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_XZ(c)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_YZ(c)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_WZ(c)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_XW(c)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_YW(c)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_ZW(c)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_WW(c)); \
		return a; \
	}
#define xlMatrixMatricialOpMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b) \
	{ \
		XLreal data[16]; \
		data[ 0] = xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_XX(b)) + xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_XY(b)) + xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_XZ(b)) + xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_XW(b)); \
		data[ 1] = xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_YX(b)) + xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_YY(b)) + xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_YZ(b)) + xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_YW(b)); \
		data[ 2] = xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_ZX(b)) + xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_ZY(b)) + xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_ZZ(b)) + xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_ZW(b)); \
		data[ 3] = xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_WX(b)) + xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_WY(b)) + xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_WZ(b)) + xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_WW(b)); \
		data[ 4] = xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_XX(b)) + xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_XY(b)) + xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_XZ(b)) + xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_XW(b)); \
		data[ 5] = xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_YX(b)) + xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_YY(b)) + xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_YZ(b)) + xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_YW(b)); \
		data[ 6] = xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_ZX(b)) + xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_ZY(b)) + xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_ZZ(b)) + xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_ZW(b)); \
		data[ 7] = xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_WX(b)) + xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_WY(b)) + xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_WZ(b)) + xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_WW(b)); \
		data[ 8] = xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_XX(b)) + xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_XY(b)) + xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_XZ(b)) + xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_XW(b)); \
		data[ 9] = xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_YX(b)) + xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_YY(b)) + xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_YZ(b)) + xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_YW(b)); \
		data[10] = xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_ZX(b)) + xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_ZY(b)) + xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_ZZ(b)) + xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_ZW(b)); \
		data[11] = xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_WX(b)) + xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_WY(b)) + xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_WZ(b)) + xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_WW(b)); \
		data[12] = xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_XX(b)) + xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_XY(b)) + xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_XZ(b)) + xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_XW(b)); \
		data[13] = xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_YX(b)) + xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_YY(b)) + xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_YZ(b)) + xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_YW(b)); \
		data[14] = xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_ZX(b)) + xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_ZY(b)) + xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_ZZ(b)) + xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_ZW(b)); \
		data[15] = xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_WX(b)) + xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_WY(b)) + xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_WZ(b)) + xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_WW(b)); \
		xlRealCopy(XL_MATRIX_ARRAY(a), data, 16); \
		return a; \
	}
#define xlMatrixAssignMatricialOpMatrixMatrix(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_XX(c)) + xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_XY(c)) + xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_XZ(c)) + xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_XW(c)); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_YX(c)) + xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_YY(c)) + xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_YZ(c)) + xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_YW(c)); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_ZX(c)) + xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_ZY(c)) + xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_ZZ(c)) + xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_ZW(c)); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_WX(c)) + xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_WY(c)) + xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_WZ(c)) + xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_WW(c)); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_XX(c)) + xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_XY(c)) + xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_XZ(c)) + xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_XW(c)); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_YX(c)) + xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_YY(c)) + xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_YZ(c)) + xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_YW(c)); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_ZX(c)) + xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_ZY(c)) + xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_ZZ(c)) + xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_ZW(c)); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_WX(c)) + xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_WY(c)) + xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_WZ(c)) + xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_WW(c)); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_XX(c)) + xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_XY(c)) + xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_XZ(c)) + xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_XW(c)); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_YX(c)) + xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_YY(c)) + xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_YZ(c)) + xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_YW(c)); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_ZX(c)) + xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_ZY(c)) + xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c)) + xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_ZW(c)); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_WX(c)) + xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_WY(c)) + xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_WZ(c)) + xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_WW(c)); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_XX(c)) + xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_XY(c)) + xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_XZ(c)) + xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_XW(c)); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_YX(c)) + xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_YY(c)) + xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_YZ(c)) + xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_YW(c)); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_ZX(c)) + xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_ZY(c)) + xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_ZZ(c)) + xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_ZW(c)); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_WX(c)) + xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_WY(c)) + xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_WZ(c)) + xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_WW(c)); \
		return a; \
	}
#define xlMatrixOpMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLreal r) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_XX(b), r); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_YX(b), r); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_ZX(b), r); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_WX(b), r); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_XY(b), r); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_YY(b), r); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_ZY(b), r); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_WY(b), r); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_XZ(b), r); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_YZ(b), r); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_ZZ(b), r); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_WZ(b), r); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_XW(b), r); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_YW(b), r); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_ZW(b), r); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_WW(b), r); \
		return a; \
	}
#define xlMatrixAssignOpMatrixMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLreal r) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_XX(c), r); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_YX(c), r); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_ZX(c), r); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_WX(c), r); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_XY(c), r); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_YY(c), r); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_ZY(c), r); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_WY(c), r); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_XZ(c), r); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_YZ(c), r); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c), r); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_WZ(c), r); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_XW(c), r); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_YW(c), r); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_ZW(c), r); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_WW(c), r); \
		return a; \
	}
#define xlMatrixOpMatrixMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLreal r) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_XX(b), XL_MATRIX_XX(c), r); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_YX(b), XL_MATRIX_YX(c), r); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_ZX(b), XL_MATRIX_ZX(c), r); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_WX(b), XL_MATRIX_WX(c), r); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_XY(b), XL_MATRIX_XY(c), r); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_YY(b), XL_MATRIX_YY(c), r); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_ZY(b), XL_MATRIX_ZY(c), r); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_WY(b), XL_MATRIX_WY(c), r); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_XZ(b), XL_MATRIX_XZ(c), r); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_YZ(b), XL_MATRIX_YZ(c), r); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c), r); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_WZ(b), XL_MATRIX_WZ(c), r); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_XW(b), XL_MATRIX_XW(c), r); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_YW(b), XL_MATRIX_YW(c), r); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_ZW(b), XL_MATRIX_ZW(c), r); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_WW(b), XL_MATRIX_WW(c), r); \
		return a; \
	}
#define xlMatrixAssignOpMatrixMatrixMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d, XLreal r) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_XX(c), XL_MATRIX_XX(d), r); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_YX(c), XL_MATRIX_YX(d), r); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_ZX(c), XL_MATRIX_ZX(d), r); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_WX(c), XL_MATRIX_WX(d), r); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_XY(c), XL_MATRIX_XY(d), r); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_YY(c), XL_MATRIX_YY(d), r); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_ZY(c), XL_MATRIX_ZY(d), r); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_WY(c), XL_MATRIX_WY(d), r); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_XZ(c), XL_MATRIX_XZ(d), r); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_YZ(c), XL_MATRIX_YZ(d), r); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c), XL_MATRIX_ZZ(d), r); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_WZ(c), XL_MATRIX_WZ(d), r); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_XW(c), XL_MATRIX_XW(d), r); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_YW(c), XL_MATRIX_YW(d), r); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_ZW(c), XL_MATRIX_ZW(d), r); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_WW(c), XL_MATRIX_WW(d), r); \
		return a; \
	}
#define xlMatrixOpMatrixMatrixMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d, XLreal r) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(a), XL_MATRIX_XX(b), XL_MATRIX_XX(c), XL_MATRIX_XX(d), r); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(a), XL_MATRIX_YX(b), XL_MATRIX_YX(c), XL_MATRIX_YX(d), r); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(a), XL_MATRIX_ZX(b), XL_MATRIX_ZX(c), XL_MATRIX_ZX(d), r); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(a), XL_MATRIX_WX(b), XL_MATRIX_WX(c), XL_MATRIX_WX(d), r); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(a), XL_MATRIX_XY(b), XL_MATRIX_XY(c), XL_MATRIX_XY(d), r); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(a), XL_MATRIX_YY(b), XL_MATRIX_YY(c), XL_MATRIX_YY(d), r); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(a), XL_MATRIX_ZY(b), XL_MATRIX_ZY(c), XL_MATRIX_ZY(d), r); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(a), XL_MATRIX_WY(b), XL_MATRIX_WY(c), XL_MATRIX_WY(d), r); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(a), XL_MATRIX_XZ(b), XL_MATRIX_XZ(c), XL_MATRIX_XZ(d), r); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(a), XL_MATRIX_YZ(b), XL_MATRIX_YZ(c), XL_MATRIX_YZ(d), r); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(a), XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c), XL_MATRIX_ZZ(d), r); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(a), XL_MATRIX_WZ(b), XL_MATRIX_WZ(c), XL_MATRIX_WZ(d), r); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(a), XL_MATRIX_XW(b), XL_MATRIX_XW(c), XL_MATRIX_XW(d), r); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(a), XL_MATRIX_YW(b), XL_MATRIX_YW(c), XL_MATRIX_YW(d), r); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(a), XL_MATRIX_ZW(b), XL_MATRIX_ZW(c), XL_MATRIX_ZW(d), r); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(a), XL_MATRIX_WW(b), XL_MATRIX_WW(c), XL_MATRIX_WW(d), r); \
		return a; \
	}
#define xlMatrixAssignOpMatrixMatrixMatrixMatrixReal(Name, Op) \
	XLmatrix * \
	xlMatrix ## Name(XLmatrix *a, XLmatrix *b, XLmatrix *c, XLmatrix *d, XLmatrix *e, XLreal r) \
	{ \
		XL_MATRIX_XX(a) = xlReal ## Op(XL_MATRIX_XX(b), XL_MATRIX_XX(c), XL_MATRIX_XX(d), XL_MATRIX_XX(e), r); \
		XL_MATRIX_YX(a) = xlReal ## Op(XL_MATRIX_YX(b), XL_MATRIX_YX(c), XL_MATRIX_YX(d), XL_MATRIX_YX(e), r); \
		XL_MATRIX_ZX(a) = xlReal ## Op(XL_MATRIX_ZX(b), XL_MATRIX_ZX(c), XL_MATRIX_ZX(d), XL_MATRIX_ZX(e), r); \
		XL_MATRIX_WX(a) = xlReal ## Op(XL_MATRIX_WX(b), XL_MATRIX_WX(c), XL_MATRIX_WX(d), XL_MATRIX_WX(e), r); \
		XL_MATRIX_XY(a) = xlReal ## Op(XL_MATRIX_XY(b), XL_MATRIX_XY(c), XL_MATRIX_XY(d), XL_MATRIX_XY(e), r); \
		XL_MATRIX_YY(a) = xlReal ## Op(XL_MATRIX_YY(b), XL_MATRIX_YY(c), XL_MATRIX_YY(d), XL_MATRIX_YY(e), r); \
		XL_MATRIX_ZY(a) = xlReal ## Op(XL_MATRIX_ZY(b), XL_MATRIX_ZY(c), XL_MATRIX_ZY(d), XL_MATRIX_ZY(e), r); \
		XL_MATRIX_WY(a) = xlReal ## Op(XL_MATRIX_WY(b), XL_MATRIX_WY(c), XL_MATRIX_WY(d), XL_MATRIX_WY(e), r); \
		XL_MATRIX_XZ(a) = xlReal ## Op(XL_MATRIX_XZ(b), XL_MATRIX_XZ(c), XL_MATRIX_XZ(d), XL_MATRIX_XZ(e), r); \
		XL_MATRIX_YZ(a) = xlReal ## Op(XL_MATRIX_YZ(b), XL_MATRIX_YZ(c), XL_MATRIX_YZ(d), XL_MATRIX_YZ(e), r); \
		XL_MATRIX_ZZ(a) = xlReal ## Op(XL_MATRIX_ZZ(b), XL_MATRIX_ZZ(c), XL_MATRIX_ZZ(d), XL_MATRIX_ZZ(e), r); \
		XL_MATRIX_WZ(a) = xlReal ## Op(XL_MATRIX_WZ(b), XL_MATRIX_WZ(c), XL_MATRIX_WZ(d), XL_MATRIX_WZ(e), r); \
		XL_MATRIX_XW(a) = xlReal ## Op(XL_MATRIX_XW(b), XL_MATRIX_XW(c), XL_MATRIX_XW(d), XL_MATRIX_XW(e), r); \
		XL_MATRIX_YW(a) = xlReal ## Op(XL_MATRIX_YW(b), XL_MATRIX_YW(c), XL_MATRIX_YW(d), XL_MATRIX_YW(e), r); \
		XL_MATRIX_ZW(a) = xlReal ## Op(XL_MATRIX_ZW(b), XL_MATRIX_ZW(c), XL_MATRIX_ZW(d), XL_MATRIX_ZW(e), r); \
		XL_MATRIX_WW(a) = xlReal ## Op(XL_MATRIX_WW(b), XL_MATRIX_WW(c), XL_MATRIX_WW(d), XL_MATRIX_WW(e), r); \
		return a; \
	}
#endif

XLmatrix *
xlMatrixAlloc(void)
{
	XLmatrix *a;
#ifdef XL_SIMD
	a = xlSimdAligned16srAlloc(sizeof(XLmatrix));
#else
	a = xlMemoryAlloc(sizeof(XLmatrix));
#endif
	return a;
}

#define _xlMatrix(m, xx, yx, zx, wx, xy, yy, zy, wy, xz, yz, zz, wz, xw, yw, zw, ww); \
	static \
	XLmatrix \
	_xlMatrix ## m; \
	\
	XLmatrix \
	*xlMatrix ## m; \
	\
	XLmatrix * \
	xlMatrixAssign ## m(XLmatrix *a) \
	{ \
		return xlMatrixAssignReals(a, xx, yx, zx, wx, xy, yy, zy, wy, xz, yz, zz, wz, xw, yw, zw, ww); \
	} 

_xlMatrix(Default, 
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlMatrix(NegDefault, 
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlMatrix(Zero, 
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlMatrix(Half, 
	XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5),
	XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5),
	XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5),
	XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5));
_xlMatrix(NegHalf, 
	XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5),
	XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5),
	XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5),
	XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(-0.5));
_xlMatrix(One, 
	XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1),
	XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1),
	XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1),
	XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1));
_xlMatrix(NegOne, 
	XL_REAL(-1), XL_REAL(-1), XL_REAL(-1), XL_REAL(-1),
	XL_REAL(-1), XL_REAL(-1), XL_REAL(-1), XL_REAL(-1),
	XL_REAL(-1), XL_REAL(-1), XL_REAL(-1), XL_REAL(-1),
	XL_REAL(-1), XL_REAL(-1), XL_REAL(-1), XL_REAL(-1));
_xlMatrix(Double, 
	XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1),
	XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1),
	XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1),
	XL_REAL(1), XL_REAL(1), XL_REAL(1), XL_REAL(1));
_xlMatrix(NegDouble, 
	XL_REAL(-1), XL_REAL(-1), XL_REAL(-1), XL_REAL(-1),
	XL_REAL(-1), XL_REAL(-1), XL_REAL(-1), XL_REAL(-1),
	XL_REAL(-1), XL_REAL(-1), XL_REAL(-1), XL_REAL(-1),
	XL_REAL(-1), XL_REAL(-1), XL_REAL(-1), XL_REAL(-1));
_xlMatrix(X, 
	XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlMatrix(NegX, 
	XL_REAL(-1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(-1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(-1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(-1), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlMatrix(Y, 
	XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(0));
_xlMatrix(NegY, 
	XL_REAL(0), XL_REAL(-1), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(-1), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(-1), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(-1), XL_REAL(0), XL_REAL(0));
_xlMatrix(Z, 
	XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0));
_xlMatrix(NegZ, 
	XL_REAL(0), XL_REAL(0), XL_REAL(-1), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(-1), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(-1), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(-1), XL_REAL(0));
_xlMatrix(W, 
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlMatrix(NegW, 
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(-1),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(-1),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(-1),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(-1));
_xlMatrix(HalfIdentity, 
	XL_REAL(0.5), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0.5), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0.5), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0.5));
_xlMatrix(NegHalfIdentity, 
	XL_REAL(-0.5), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(-0.5), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(-0.5), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(-0.5));
_xlMatrix(Identity, 
	XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlMatrix(NegIdentity, 
	XL_REAL(-1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(-1), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(-1), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(-1));
_xlMatrix(DoubleIdentity, 
	XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1));
_xlMatrix(NegDoubleIdentity, 
	XL_REAL(-1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(-1), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(-1), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(-1));
_xlMatrix(TMP, 
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlMatrix(TMP1, 
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlMatrix(TMP2, 
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlMatrix(TMP3, 
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));
_xlMatrix(TMP4, 
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
	XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0));

#undef _xlMatrix

XLmatrix *
xlMatrixAssignArray(XLmatrix *a, XLreal *array)
{
#ifdef XL_SIMD
	XLsimd16sr simd = { 
		array[0], array[1], array[2], array[3],
		array[4], array[5], array[6], array[7],
		array[8], array[9], array[10], array[11],
		array[12], array[13], array[14], array[15]
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	xlRealCopy(XL_MATRIX_ARRAY(a), array, 16);
#endif
	return a;
}

XLmatrix *
xlMatrixAssignReals(XLmatrix *a, XLreal xx, XLreal yx, XLreal zx, XLreal wx, XLreal xy, XLreal yy, XLreal zy, XLreal wy, XLreal xz, XLreal yz, XLreal zz, XLreal wz, XLreal xw, XLreal yw, XLreal zw, XLreal ww)
{
#ifdef XL_SIMD
	XLsimd16sr simd = {
		xx, yx, zx, wx,
		xy, yy, zy, wy,
		xz, yz, zz, wz,
		xw, yw, zw, ww
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	XL_MATRIX_XX(a) = xx;
	XL_MATRIX_YX(a) = yx;
	XL_MATRIX_ZX(a) = zx;
	XL_MATRIX_WX(a) = wx;
	XL_MATRIX_XY(a) = xy;
	XL_MATRIX_YY(a) = yy;
	XL_MATRIX_ZY(a) = zy;
	XL_MATRIX_WY(a) = wy;
	XL_MATRIX_XZ(a) = xz;
	XL_MATRIX_YZ(a) = yz;
	XL_MATRIX_ZZ(a) = zz;
	XL_MATRIX_WZ(a) = wz;
	XL_MATRIX_XW(a) = xw;
	XL_MATRIX_YW(a) = yw;
	XL_MATRIX_ZW(a) = zw;
	XL_MATRIX_WW(a) = ww;
#endif
	return a;
}

xlMatrixArrayAssignNoneOp(AssignRand, Rand);

XLmatrix *
xlMatrixAssignTranslation(XLmatrix *a, XLpoint *p)
{
	return xlMatrixAssignReals(a, 
		XL_REAL(1), XL_REAL(0), XL_REAL(0), XL_REAL(0),
		XL_REAL(0), XL_REAL(1), XL_REAL(0), XL_REAL(0),
		XL_REAL(0), XL_REAL(0), XL_REAL(1), XL_REAL(0),
		XL_POINT_X(p), XL_POINT_Y(p), XL_POINT_Z(p), XL_REAL(1)
	);
}

XLmatrix *
xlMatrixAssignScalation(XLmatrix *a, XLvector *s)
{
	return 	xlMatrixAssignReals(a,
		XL_VECTOR_X(s), XL_REAL(0), XL_REAL(0), XL_REAL(0),
		XL_REAL(0), XL_VECTOR_Y(s), XL_REAL(0), XL_REAL(0),
		XL_REAL(0), XL_REAL(0), XL_VECTOR_Z(s), XL_REAL(0),
		XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1)
	);
}

XLmatrix *
xlMatrixAssignRotation(XLmatrix *a, XLvector *x, XLreal r)
{
	const XLreal
		rangle = xlRealDegToRad(r),
		c = xlRealCosine(rangle),
		s = xlRealSine(rangle),
		omc = XL_REAL(1) - c;
	return xlMatrixAssignReals(a,
		XL_VECTOR_X(x) * XL_VECTOR_X(x) * omc + c, XL_VECTOR_Y(x) * XL_VECTOR_X(x) * omc + XL_VECTOR_Z(x) * s, XL_VECTOR_X(x) * XL_VECTOR_Z(x) * omc - XL_VECTOR_Y(x) * s, XL_REAL(0),
		XL_VECTOR_X(x) * XL_VECTOR_Y(x) * omc - XL_VECTOR_Z(x) * s, XL_VECTOR_Y(x) * XL_VECTOR_Y(x) * omc + c, XL_VECTOR_Y(x) * XL_VECTOR_Z(x) * omc + XL_VECTOR_X(x) * s, XL_REAL(0),
		XL_VECTOR_X(x) * XL_VECTOR_Z(x) * omc + XL_VECTOR_Y(x) * s, XL_VECTOR_Y(x) * XL_VECTOR_Z(x) * omc - XL_VECTOR_X(x) * s, XL_VECTOR_Z(x) * XL_VECTOR_Z(x) * omc + c, XL_REAL(0),
		XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1)
	);
}

XLmatrix *
xlMatrixAssignLook(XLmatrix *a, XLpoint *p, XLvector *f, XLvector *u)
{
	XLvector c;
	XLmatrix m;
	XLpoint t;
	xlVectorAssignCross(&c, f, u);
	xlMatrixAssignReals(&m,
		XL_VECTOR_X(&c), XL_VECTOR_X(u), -XL_VECTOR_X(f), XL_REAL(0),
		XL_VECTOR_Y(&c), XL_VECTOR_Y(u), -XL_VECTOR_Y(f), XL_REAL(0),
		XL_VECTOR_Z(&c), XL_VECTOR_Z(u), -XL_VECTOR_Z(f), XL_REAL(0),
		XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(1)
	);
	xlPointAssignNeg(&t, p);
	return xlMatrixAssignTranslate(a, &m, &t);
}

XLmatrix *
xlMatrixAssignLookAt(XLmatrix *a, XLpoint *e, XLpoint *c, XLvector *u)
{
	XLvector f;
	xlVectorAssignSubPoint(&f, c, e);
	xlVectorNormal(&f);
	return xlMatrixAssignLook(a, e, &f, u);
}

XLmatrix *
xlMatrixAssignBillboard(XLmatrix *a, XLmatrix *m, XLpoint *p)
{
	return xlMatrixAssignReals(a,
		XL_MATRIX_XX(m), XL_MATRIX_XY(m), XL_MATRIX_XZ(m), XL_REAL(0),
		XL_MATRIX_YX(m), XL_MATRIX_YY(m), XL_MATRIX_YZ(m), XL_REAL(0),
		XL_MATRIX_ZX(m), XL_MATRIX_ZY(m), XL_MATRIX_ZZ(m), XL_REAL(0),
		XL_POINT_X(p), XL_POINT_Y(p), XL_POINT_Z(p), XL_REAL(1)
	);
}

XLmatrix *
xlMatrixSwizzle(XLmatrix *a, XLint xx, XLint yx, XLint zx, XLint wx, XLint xy, XLint yy, XLint zy, XLint wy, XLint xz, XLint yz, XLint zz, XLint wz, XLint xw, XLint yw, XLint zw, XLint ww)
{
#ifdef XL_SIMD
	XLsimd16si mask = { xx, yx, zx, wx, xy, yy, zy, wy, xz, yz, zz, wz, xw, yw, zw, ww };
	XL_MATRIX_SIMD(a) = __builtin_shuffle(XL_MATRIX_SIMD(a), mask);
#else
	XLreal data[16];
	data[ 0] = XL_MATRIX_ARRAY(a)[xx];
	data[ 1] = XL_MATRIX_ARRAY(a)[yx];
	data[ 2] = XL_MATRIX_ARRAY(a)[zx];
	data[ 3] = XL_MATRIX_ARRAY(a)[wx];
	data[ 4] = XL_MATRIX_ARRAY(a)[xy];
	data[ 5] = XL_MATRIX_ARRAY(a)[yy];
	data[ 6] = XL_MATRIX_ARRAY(a)[zy];
	data[ 7] = XL_MATRIX_ARRAY(a)[wy];
	data[ 8] = XL_MATRIX_ARRAY(a)[xz];
	data[ 9] = XL_MATRIX_ARRAY(a)[yz];
	data[10] = XL_MATRIX_ARRAY(a)[zz];
	data[11] = XL_MATRIX_ARRAY(a)[wz];
	data[12] = XL_MATRIX_ARRAY(a)[xw];
	data[13] = XL_MATRIX_ARRAY(a)[yw];
	data[14] = XL_MATRIX_ARRAY(a)[zw];
	data[15] = XL_MATRIX_ARRAY(a)[ww];
	xlRealCopy(XL_MATRIX_ARRAY(a), data, 16);
#endif
	return a;
}

XLmatrix *
xlMatrixAssignSwizzle(XLmatrix *a, XLmatrix *b, XLint xx, XLint yx, XLint zx, XLint wx, XLint xy, XLint yy, XLint zy, XLint wy, XLint xz, XLint yz, XLint zz, XLint wz, XLint xw, XLint yw, XLint zw, XLint ww)
{
#ifdef XL_SIMD
	XLsimd16si mask = { xx, yx, zx, wx, xy, yy, zy, wy, xz, yz, zz, wz, xw, yw, zw, ww };
	XL_MATRIX_SIMD(a) = __builtin_shuffle(XL_MATRIX_SIMD(b), mask);
#else
	XL_MATRIX_XX(a) = XL_MATRIX_ARRAY(b)[xx];
	XL_MATRIX_YX(a) = XL_MATRIX_ARRAY(b)[yx];
	XL_MATRIX_ZX(a) = XL_MATRIX_ARRAY(b)[zx];
	XL_MATRIX_WX(a) = XL_MATRIX_ARRAY(b)[wx];
	XL_MATRIX_XY(a) = XL_MATRIX_ARRAY(b)[xy];
	XL_MATRIX_YY(a) = XL_MATRIX_ARRAY(b)[yy];
	XL_MATRIX_ZY(a) = XL_MATRIX_ARRAY(b)[zy];
	XL_MATRIX_WY(a) = XL_MATRIX_ARRAY(b)[wy];
	XL_MATRIX_XZ(a) = XL_MATRIX_ARRAY(b)[xz];
	XL_MATRIX_YZ(a) = XL_MATRIX_ARRAY(b)[yz];
	XL_MATRIX_ZZ(a) = XL_MATRIX_ARRAY(b)[zz];
	XL_MATRIX_WZ(a) = XL_MATRIX_ARRAY(b)[wz];
	XL_MATRIX_XW(a) = XL_MATRIX_ARRAY(b)[xw];
	XL_MATRIX_YW(a) = XL_MATRIX_ARRAY(b)[yw];
	XL_MATRIX_ZW(a) = XL_MATRIX_ARRAY(b)[zw];
	XL_MATRIX_WW(a) = XL_MATRIX_ARRAY(b)[ww];
#endif
	return a;
}

XLmatrix *
xlMatrixForward(XLmatrix *a, XLvector *b)
{
#ifdef XL_SIMD
	XLvector t;
	xlVectorAssignNeg(&t, b);
	XLsimd16sr simd =
	{
		XL_MATRIX_XX(a), XL_MATRIX_YX(a), XL_VECTOR_X(&t), XL_MATRIX_WX(a),
		XL_MATRIX_XY(a), XL_MATRIX_YY(a), XL_VECTOR_Y(&t), XL_MATRIX_WY(a),
		XL_MATRIX_XZ(a), XL_MATRIX_YZ(a), XL_VECTOR_Z(&t), XL_MATRIX_WZ(a),
		XL_MATRIX_XW(a), XL_MATRIX_YW(a), XL_MATRIX_ZW(a), XL_MATRIX_WW(a)
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	XL_MATRIX_ZX(a) = -XL_VECTOR_X(b);
	XL_MATRIX_ZY(a) = -XL_VECTOR_Y(b);
	XL_MATRIX_ZZ(a) = -XL_VECTOR_Z(b);
#endif
	return a;
}

XLmatrix *
xlMatrixAssignForward(XLmatrix *a, const XLmatrix *b, XLvector *c)
{
#ifdef XL_SIMD
	XLvector t;
	xlVectorAssignNeg(&t, c);
	XLsimd16sr simd =
	{
		XL_MATRIX_XX(b), XL_MATRIX_YX(b), XL_VECTOR_X(&t), XL_MATRIX_WX(b),
		XL_MATRIX_XY(b), XL_MATRIX_YY(b), XL_VECTOR_Y(&t), XL_MATRIX_WY(b),
		XL_MATRIX_XZ(b), XL_MATRIX_YZ(b), XL_VECTOR_Z(&t), XL_MATRIX_WZ(b),
		XL_MATRIX_XW(b), XL_MATRIX_YW(b), XL_MATRIX_ZW(b), XL_MATRIX_WW(b)
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	XL_MATRIX_XX(a) = XL_MATRIX_XX(b);
	XL_MATRIX_YX(a) = XL_MATRIX_YX(b);
	XL_MATRIX_ZX(a) = -XL_VECTOR_X(c);
	XL_MATRIX_WX(a) = XL_MATRIX_WX(b);
	XL_MATRIX_XY(a) = XL_MATRIX_XY(b);
	XL_MATRIX_YY(a) = XL_MATRIX_YY(b);
	XL_MATRIX_ZY(a) = -XL_VECTOR_Y(c);
	XL_MATRIX_WY(a) = XL_MATRIX_WY(b);
	XL_MATRIX_XZ(a) = XL_MATRIX_XZ(b);
	XL_MATRIX_YZ(a) = XL_MATRIX_YZ(b);
	XL_MATRIX_ZZ(a) = -XL_VECTOR_Z(c);
	XL_MATRIX_WZ(a) = XL_MATRIX_WZ(b);
	XL_MATRIX_XW(a) = XL_MATRIX_XW(b);
	XL_MATRIX_YW(a) = XL_MATRIX_YW(b);
	XL_MATRIX_ZW(a) = XL_MATRIX_ZW(b);
	XL_MATRIX_WW(a) = XL_MATRIX_WW(b);
#endif
	return a;
}

XLmatrix *
xlMatrixUp(XLmatrix *a, XLvector *b)
{
#ifdef XL_SIMD
	XLsimd16sr simd =
	{
		XL_MATRIX_XX(a), XL_VECTOR_X(b), XL_MATRIX_ZX(a), XL_MATRIX_WX(a),
		XL_MATRIX_XY(a), XL_VECTOR_Y(b), XL_MATRIX_ZY(a), XL_MATRIX_WY(a),
		XL_MATRIX_XZ(a), XL_VECTOR_Z(b), XL_MATRIX_ZZ(a), XL_MATRIX_WZ(a),
		XL_MATRIX_XW(a), XL_MATRIX_YW(a), XL_MATRIX_ZW(a), XL_MATRIX_WW(a)
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	XL_MATRIX_YX(a) = XL_VECTOR_X(b);
	XL_MATRIX_YY(a) = XL_VECTOR_Y(b);
	XL_MATRIX_YZ(a) = XL_VECTOR_Z(b);
#endif
	return a;
}

XLmatrix *
xlMatrixAssignUp(XLmatrix *a, const XLmatrix *b, XLvector *c)
{
#ifdef XL_SIMD
	XLsimd16sr simd =
	{
		XL_MATRIX_XX(b), XL_VECTOR_X(c), XL_MATRIX_ZX(b), XL_MATRIX_WX(b),
		XL_MATRIX_XY(b), XL_VECTOR_Y(c), XL_MATRIX_ZY(b), XL_MATRIX_WY(b),
		XL_MATRIX_XZ(b), XL_VECTOR_Z(c), XL_MATRIX_ZZ(b), XL_MATRIX_WZ(b),
		XL_MATRIX_XW(b), XL_MATRIX_YW(b), XL_MATRIX_ZW(b), XL_MATRIX_WW(b)
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	XL_MATRIX_XX(a) = XL_MATRIX_XX(b);
	XL_MATRIX_YX(a) = XL_VECTOR_X(c);
	XL_MATRIX_ZX(a) = XL_MATRIX_ZX(b);
	XL_MATRIX_WX(a) = XL_MATRIX_WX(b);
	XL_MATRIX_XY(a) = XL_MATRIX_XY(b);
	XL_MATRIX_YY(a) = XL_VECTOR_Y(c);
	XL_MATRIX_ZY(a) = XL_MATRIX_ZY(b);
	XL_MATRIX_WY(a) = XL_MATRIX_WY(b);
	XL_MATRIX_XZ(a) = XL_MATRIX_XZ(b);
	XL_MATRIX_YZ(a) = XL_VECTOR_Z(c);
	XL_MATRIX_ZZ(a) = XL_MATRIX_ZZ(b);
	XL_MATRIX_WZ(a) = XL_MATRIX_WZ(b);
	XL_MATRIX_XW(a) = XL_MATRIX_XW(b);
	XL_MATRIX_YW(a) = XL_MATRIX_YW(b);
	XL_MATRIX_ZW(a) = XL_MATRIX_ZW(b);
	XL_MATRIX_WW(a) = XL_MATRIX_WW(b);
#endif
	return a;
}

XLmatrix *
xlMatrixRight(XLmatrix *a, XLvector *b)
{
#ifdef XL_SIMD
	XLsimd16sr simd =
	{
		XL_VECTOR_X(b), XL_MATRIX_YX(a), XL_MATRIX_ZX(a), XL_MATRIX_WX(a),
		XL_VECTOR_Y(b), XL_MATRIX_YY(a), XL_MATRIX_ZY(a), XL_MATRIX_WY(a),
		XL_VECTOR_Z(b), XL_MATRIX_YZ(a), XL_MATRIX_ZZ(a), XL_MATRIX_WZ(a),
		XL_MATRIX_XW(a), XL_MATRIX_YW(a), XL_MATRIX_ZW(a), XL_MATRIX_WW(a)
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	XL_MATRIX_XX(a) = XL_VECTOR_X(b);
	XL_MATRIX_XY(a) = XL_VECTOR_Y(b);
	XL_MATRIX_XZ(a) = XL_VECTOR_Z(b);
#endif
	return a;
}

XLmatrix *
xlMatrixAssignRight(XLmatrix *a, const XLmatrix *b, XLvector *c)
{
#ifdef XL_SIMD
	XLsimd16sr simd =
	{
		XL_VECTOR_X(c), XL_MATRIX_YX(b), XL_MATRIX_ZX(b), XL_MATRIX_WX(b),
		XL_VECTOR_Y(c), XL_MATRIX_YY(b), XL_MATRIX_ZY(b), XL_MATRIX_WY(b),
		XL_VECTOR_Z(c), XL_MATRIX_YZ(b), XL_MATRIX_ZZ(b), XL_MATRIX_WZ(b),
		XL_MATRIX_XW(b), XL_MATRIX_YW(b), XL_MATRIX_ZW(b), XL_MATRIX_WW(b)
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	XL_MATRIX_XX(a) = XL_VECTOR_X(c);
	XL_MATRIX_YX(a) = XL_MATRIX_YX(b);
	XL_MATRIX_ZX(a) = XL_MATRIX_ZX(b);
	XL_MATRIX_WX(a) = XL_MATRIX_WX(b);
	XL_MATRIX_XY(a) = XL_VECTOR_Y(c);
	XL_MATRIX_YY(a) = XL_MATRIX_YY(b);
	XL_MATRIX_ZY(a) = XL_MATRIX_ZY(b);
	XL_MATRIX_WY(a) = XL_MATRIX_WY(b);
	XL_MATRIX_XZ(a) = XL_VECTOR_Z(c);
	XL_MATRIX_YZ(a) = XL_MATRIX_YZ(b);
	XL_MATRIX_ZZ(a) = XL_MATRIX_ZZ(b);
	XL_MATRIX_WZ(a) = XL_MATRIX_WZ(b);
	XL_MATRIX_XW(a) = XL_MATRIX_XW(b);
	XL_MATRIX_YW(a) = XL_MATRIX_YW(b);
	XL_MATRIX_ZW(a) = XL_MATRIX_ZW(b);
	XL_MATRIX_WW(a) = XL_MATRIX_WW(b);
#endif
	return a;
}

XLmatrix *
xlMatrixPosition(XLmatrix *a, XLpoint *b)
{
#ifdef XL_SIMD
	XLsimd16sr simd =
	{
		XL_MATRIX_XX(a), XL_MATRIX_YX(a), XL_MATRIX_ZX(a), XL_MATRIX_WX(a),
		XL_MATRIX_XY(a), XL_MATRIX_YY(a), XL_MATRIX_ZY(a), XL_MATRIX_WY(a),
		XL_MATRIX_XZ(a), XL_MATRIX_YZ(a), XL_MATRIX_ZZ(a), XL_MATRIX_WZ(a),
		XL_POINT_X(b), XL_POINT_Y(b), XL_POINT_Z(b), XL_MATRIX_WW(a)
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	XL_MATRIX_XW(a) = XL_POINT_X(b);
	XL_MATRIX_YW(a) = XL_POINT_Y(b);
	XL_MATRIX_ZW(a) = XL_POINT_Z(b);
#endif
	return a;
}

XLmatrix *
xlMatrixAssignPosition(XLmatrix *a, const XLmatrix *b, XLpoint *c)
{
#ifdef XL_SIMD
	XLsimd16sr simd =
	{
		XL_MATRIX_XX(b), XL_MATRIX_YX(b), XL_MATRIX_ZX(b), XL_MATRIX_WX(b),
		XL_MATRIX_XY(b), XL_MATRIX_YY(b), XL_MATRIX_ZY(b), XL_MATRIX_WY(b),
		XL_MATRIX_XZ(b), XL_MATRIX_YZ(b), XL_MATRIX_ZZ(b), XL_MATRIX_WZ(b),
		XL_POINT_X(c), XL_POINT_Y(c), XL_POINT_Z(c), XL_MATRIX_WW(b)
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	XL_MATRIX_XX(a) = XL_MATRIX_XX(b);
	XL_MATRIX_YX(a) = XL_MATRIX_YX(b);
	XL_MATRIX_ZX(a) = XL_MATRIX_ZX(b);
	XL_MATRIX_WX(a) = XL_MATRIX_WX(b);
	XL_MATRIX_XY(a) = XL_MATRIX_XY(b);
	XL_MATRIX_YY(a) = XL_MATRIX_YY(b);
	XL_MATRIX_ZY(a) = XL_MATRIX_ZY(b);
	XL_MATRIX_WY(a) = XL_MATRIX_WY(b);
	XL_MATRIX_XZ(a) = XL_MATRIX_XZ(b);
	XL_MATRIX_YZ(a) = XL_MATRIX_YZ(b);
	XL_MATRIX_ZZ(a) = XL_MATRIX_ZZ(b);
	XL_MATRIX_WZ(a) = XL_MATRIX_WZ(b);
	XL_MATRIX_XW(a) = XL_POINT_X(c);
	XL_MATRIX_YW(a) = XL_POINT_Y(c);
	XL_MATRIX_ZW(a) = XL_POINT_Z(c);
	XL_MATRIX_WW(a) = XL_MATRIX_WW(b);
#endif
	return a;
}

XLmatrix *
xlMatrixClear(XLmatrix *a)
{
#ifdef XL_SIMD
	XLsimd16sr simd = {
		XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
		XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
		XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0),
		XL_REAL(0), XL_REAL(0), XL_REAL(0), XL_REAL(0)
	};
	XL_MATRIX_SIMD(a) = simd;
#else
	xlMemoryZero(a, sizeof(XLmatrix));
#endif
	return a;
}

XLmatrix *
xlMatrixCopy(XLmatrix *a)
{
	XLmatrix *b;

	b = xlMatrixAlloc();
	return xlMatrixAssignCopy(b, a);
}

XLmatrix *
xlMatrixAssignCopy(XLmatrix *a, const XLmatrix *b)
{
#ifdef XL_SIMD
	XL_MATRIX_SIMD(a) = XL_MATRIX_SIMD(b);
#else
	xlMemoryCopy(a, b, sizeof(XLmatrix));
#endif
	return a;
}


xlMatrixOp(Comp, Comp);
xlMatrixAssignOpMatrix(AssignComp, Comp);

xlMatrixOp(Neg, Neg);
xlMatrixAssignOpMatrix(AssignNeg, Neg);

xlMatrixOp(Inc, Inc);
xlMatrixAssignOpMatrix(AssignInc, Inc);

xlMatrixOp(Dec, Dec);
xlMatrixAssignOpMatrix(AssignDec, Dec);

xlMatrixArrayOp(Abs, Abs);
xlMatrixArrayAssignOpMatrix(AssignAbs, Abs);

#if 0
XLreal
xlMatrixSquareNorm(XLmatrix *a)
{
	return xlMatrixDot(, XL_OBJECT());
}

XLreal
xlMatrixNorm(XLmatrix *a)
{
	return xlRealSquareRoot(xlMatrixSquareNorm());
}

XLmatrix *
xlMatrixNormal(XLmatrix *a)
{
	return xlMatrixMultReal(, XL_REAL(1) / xlMatrixNorm());
}

XLmatrix *
xlMatrixAssignNormal(XLmatrix *a, XLmatrix *b)
{
	return xlMatrixAssignMultReal(a, b, XL_REAL(1) / xlMatrixNorm(b));
}
#endif

XLmatrix *
xlMatrixTranspose(XLmatrix *a)
{
#ifdef XL_SIMD
	XLsimd16si mask = { 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	XL_MATRIX_SIMD(a) = __builtin_shuffle(XL_MATRIX_SIMD(a), mask);
#else
	XLreal data[16];
	data[ 0] = XL_MATRIX_WW(a);
	data[ 1] = XL_MATRIX_ZW(a);
	data[ 2] = XL_MATRIX_YW(a);
	data[ 3] = XL_MATRIX_XW(a);
	data[ 4] = XL_MATRIX_WZ(a);
	data[ 5] = XL_MATRIX_ZZ(a);
	data[ 6] = XL_MATRIX_YZ(a);
	data[ 7] = XL_MATRIX_XZ(a);
	data[ 8] = XL_MATRIX_WY(a);
	data[ 9] = XL_MATRIX_ZY(a);
	data[10] = XL_MATRIX_YY(a);
	data[11] = XL_MATRIX_XY(a);
	data[12] = XL_MATRIX_WX(a);
	data[13] = XL_MATRIX_ZX(a);
	data[14] = XL_MATRIX_YX(a);
	data[15] = XL_MATRIX_XX(a);
	xlRealCopy(XL_MATRIX_ARRAY(a), data, 16);
#endif
	return a;
}

XLmatrix *
xlMatrixAssignTranspose(XLmatrix *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd16si mask = { 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	XL_MATRIX_SIMD(a) = __builtin_shuffle(XL_MATRIX_SIMD(b), mask);
#else
	XL_MATRIX_XX(a) = XL_MATRIX_WW(b);
	XL_MATRIX_YX(a) = XL_MATRIX_ZW(b);
	XL_MATRIX_ZX(a) = XL_MATRIX_YW(b);
	XL_MATRIX_WX(a) = XL_MATRIX_XW(b);
	XL_MATRIX_XY(a) = XL_MATRIX_WZ(b);
	XL_MATRIX_YY(a) = XL_MATRIX_ZZ(b);
	XL_MATRIX_ZY(a) = XL_MATRIX_YZ(b);
	XL_MATRIX_WY(a) = XL_MATRIX_XZ(b);
	XL_MATRIX_XZ(a) = XL_MATRIX_WY(b);
	XL_MATRIX_YZ(a) = XL_MATRIX_ZY(b);
	XL_MATRIX_ZZ(a) = XL_MATRIX_YY(b);
	XL_MATRIX_WZ(a) = XL_MATRIX_XY(b);
	XL_MATRIX_XW(a) = XL_MATRIX_WX(b);
	XL_MATRIX_YW(a) = XL_MATRIX_ZX(b);
	XL_MATRIX_ZW(a) = XL_MATRIX_YX(b);
	XL_MATRIX_WW(a) = XL_MATRIX_XX(b);
#endif
	return a;
}

xlMatrixArrayBooleanOpMatrix(BooleanEqual, Equal);
xlMatrixOpMatrix(MatrixEqual, Equal);
xlMatrixAssignOpMatrixMatrix(MatrixAssignEqual, Equal);

xlMatrixArrayBooleanOpMatrix(BooleanGreater, Greater);
xlMatrixOpMatrix(MatrixGreater, Greater);
xlMatrixAssignOpMatrixMatrix(MatrixAssignGreater, Greater);

xlMatrixArrayBooleanOpMatrix(BooleanLesser, Lesser);
xlMatrixOpMatrix(MatrixLesser, Lesser);
xlMatrixAssignOpMatrixMatrix(MatrixAssignLesser, Lesser);

#if 0
XLreal
xlMatrixAngle(XLmatrix *a, XLmatrix *b)
{
	return xlRealRadToDeg(xlRealArcCosine(xlMatrixDot(a, b) / (xlMatrixNorm(a) *xlMatrixNorm(XL_OPERATIVE_OBJECT(b)))));
}

XLreal
xlMatrixDot(XLmatrix *a, XLmatrix *b)
{
#ifdef XL_SIMD
	//XLmatrixPublic c;
	//c.value.simd = XL_MATRIX_SIMD(a) * XL_MATRIX_SIMD(b);
	//return c.value.array[0] + c.value.array[1] + c.value.array[2];
	XLsimd16sr c;
	c = XL_MATRIX_SIMD(a) * XL_MATRIX_SIMD(b);
	return c[0] + c[1] + c[2];
#else
	return XL_MATRIX_X(a) * XL_MATRIX_X(b) + XL_MATRIX_Y(a) * XL_MATRIX_Y(b) + XL_MATRIX_Z(a) * XL_MATRIX_Z(b);
#endif
}
#endif

xlMatrixOpReal(AndReal, And);
xlMatrixAssignOpMatrixReal(AssignAndReal, And);
xlMatrixOpMatrix(And, And);
xlMatrixAssignOpMatrixMatrix(AssignAnd, And);

xlMatrixOpReal(OrReal, Or);
xlMatrixAssignOpMatrixReal(AssignOrReal, Or);
xlMatrixOpMatrix(Or, Or);
xlMatrixAssignOpMatrixMatrix(AssignOr, Or);

xlMatrixOpReal(XorReal, Xor);
xlMatrixAssignOpMatrixReal(AssignXorReal, Xor);
xlMatrixOpMatrix(Xor, Xor);
xlMatrixAssignOpMatrixMatrix(AssignXor, Xor);

xlMatrixOpReal(LShiftReal, LShift);
xlMatrixAssignOpMatrixReal(AssignLShiftReal, LShift);
xlMatrixOpMatrix(LShift, LShift);
xlMatrixAssignOpMatrixMatrix(AssignLShift, LShift);

xlMatrixOpReal(RShiftReal, RShift);
xlMatrixAssignOpMatrixReal(AssignRShiftReal, RShift);
xlMatrixOpMatrix(RShift, RShift);
xlMatrixAssignOpMatrixMatrix(AssignRShift, RShift);

xlMatrixOpReal(AddReal, Add);
xlMatrixAssignOpMatrixReal(AssignAddReal, Add);
xlMatrixOpMatrix(Add, Add);
xlMatrixAssignOpMatrixMatrix(AssignAdd, Add);

xlMatrixOpReal(SubReal, Sub);
xlMatrixAssignOpMatrixReal(AssignSubReal, Sub);
xlMatrixOpMatrix(Sub, Sub);
xlMatrixAssignOpMatrixMatrix(AssignSub, Sub);

xlMatrixOpReal(MultReal, Mult);
xlMatrixAssignOpMatrixReal(AssignMultReal, Mult);
xlMatrixMatricialOpMatrix(Mult, Mult);
xlMatrixAssignMatricialOpMatrixMatrix(AssignMult, Mult);

xlMatrixOpReal(DivReal, Div);
xlMatrixAssignOpMatrixReal(AssignDivReal, Div);
xlMatrixMatricialOpMatrix(Div, Div);
xlMatrixAssignMatricialOpMatrixMatrix(AssignDiv, Div);

xlMatrixOpReal(ModReal, Mod);
xlMatrixAssignOpMatrixReal(AssignModReal, Mod);
xlMatrixMatricialOpMatrix(Mod, Mod);
xlMatrixAssignMatricialOpMatrixMatrix(AssignMod, Mod);

xlMatrixOpReal(InvDivReal, InvDiv);
xlMatrixAssignOpMatrixReal(AssignInvDivReal, InvDiv);
xlMatrixMatricialOpMatrix(InvDiv, InvDiv);
xlMatrixAssignMatricialOpMatrixMatrix(AssignInvDiv, InvDiv);

#if 0
XLmatrix *
xlMatrixCross(XLmatrix *a, XLmatrix *b)
{
#ifdef XL_SIMD
	XLsimd4si mask[4] = { { 1, 2, 0, 3 }, { 2, 0, 1, 3 }, { 2, 0, 1, 3 }, { 1, 2, 0, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_MATRIX_SIMD(a), mask[0]);
	simd[1] = __builtin_shuffle(XL_MATRIX_SIMD(b), mask[1]);
	simd[2] = __builtin_shuffle(XL_MATRIX_SIMD(a), mask[2]);
	simd[3] = __builtin_shuffle(XL_MATRIX_SIMD(b), mask[3]);
	XL_MATRIX_SIMD(a) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XL_MATRIX_X(a) = XL_MATRIX_Y(a) * XL_MATRIX_Z(b) - XL_MATRIX_Z(a) * XL_MATRIX_Y(b);
	XL_MATRIX_Y(a) = XL_MATRIX_Z(a) * XL_MATRIX_X(b) - XL_MATRIX_X(a) * XL_MATRIX_Z(b);
	XL_MATRIX_Z(a) = XL_MATRIX_X(a) * XL_MATRIX_Y(b) - XL_MATRIX_Y(a) * XL_MATRIX_X(b);
#endif
	return a;
}

XLmatrix *
xlMatrixAssignCross(XLmatrix *a, XLmatrix *b, XLmatrix *c)
{
#ifdef XL_SIMD
	XLsimd4si mask[4] = { { 1, 2, 0, 3 }, { 2, 0, 1, 3 }, { 2, 0, 1, 3 }, { 1, 2, 0, 3 } };
	XLsimd4sr simd[4];
	simd[0] = __builtin_shuffle(XL_MATRIX_SIMD(b), mask[0]);
	simd[1] = __builtin_shuffle(XL_MATRIX_SIMD(c), mask[1]);
	simd[2] = __builtin_shuffle(XL_MATRIX_SIMD(b), mask[2]);
	simd[3] = __builtin_shuffle(XL_MATRIX_SIMD(c), mask[3]);
	XL_MATRIX_SIMD(a) = simd[0] * simd[1] - simd[2] * simd[3];
#else
	XL_MATRIX_X(a) = XL_MATRIX_Y(b) * XL_MATRIX_Z(c) - XL_MATRIX_Z(b) * XL_MATRIX_Y(c);
	XL_MATRIX_Y(a) = XL_MATRIX_Z(b) * XL_MATRIX_X(c) - XL_MATRIX_X(b) * XL_MATRIX_Z(c);
	XL_MATRIX_Z(a) = XL_MATRIX_X(b) * XL_MATRIX_Y(c) - XL_MATRIX_Y(b) * XL_MATRIX_X(c);
#endif
	return a;
}
#endif

xlMatrixArrayOpMatrix(Min, Min);
xlMatrixArrayAssignOpMatrixMatrix(AssignMin, Min);

xlMatrixArrayOpMatrix(Max, Max);
xlMatrixArrayAssignOpMatrixMatrix(AssignMax, Max);

xlMatrixArrayOpRealReal(ClampReal, Clamp);
xlMatrixArrayAssignOpMatrixRealReal(AssignClampReal, Clamp);
xlMatrixArrayOpMatrixMatrix(Clamp, Clamp);
xlMatrixArrayAssignOpMatrixMatrixMatrix(AssignClamp, Clamp);

xlMatrixArrayAssignNoneOpRealReal(AssignRandRangeReal, RandRange);
xlMatrixArrayAssignNoneOpMatrixMatrix(AssignRandRange, RandRange);

XLmatrix *
xlMatrixTranslate(XLmatrix *a, XLpoint *position)
{
	XLmatrix m;
	xlMatrixAssignTranslation(&m, position);
	return xlMatrixMult(a, &m);
}

XLmatrix *
xlMatrixAssignTranslate(XLmatrix *a, XLmatrix *b, XLpoint * position)
{
	XLmatrix m;
	xlMatrixAssignTranslation(&m, position);
	return xlMatrixAssignMult(a, b, &m);
}

XLmatrix *
xlMatrixScale(XLmatrix *a, XLvector *scale)
{
	XLmatrix m;
	xlMatrixAssignScalation(&m, scale);
	return xlMatrixMult(a, &m);
}

XLmatrix *
xlMatrixAssignScale(XLmatrix *a, XLmatrix *b, XLvector *scale)
{
	XLmatrix m;
	xlMatrixAssignScalation(&m, scale);
	return xlMatrixAssignMult(a, b, &m);
}

XLmatrix *
xlMatrixRotate(XLmatrix *a, XLvector *axis, XLreal angle)
{
	XLmatrix m;
	xlMatrixAssignRotation(&m, axis, angle);
	return xlMatrixMult(a, &m);
}

XLmatrix *
xlMatrixAssignRotate(XLmatrix *a, XLmatrix *b, XLvector *axis, XLreal angle)
{
	XLmatrix m;
	xlMatrixAssignRotation(&m, axis, angle);
	return xlMatrixAssignMult(a, b, &m);
}

xlMatrixOpMatrixReal(Lerp, Lerp);
xlMatrixAssignOpMatrixMatrixReal(AssignLerp, Lerp);

xlMatrixOpMatrixMatrixReal(QuadBezier, QuadBezier);
xlMatrixAssignOpMatrixMatrixMatrixReal(AssignQuadBezier, QuadBezier);

xlMatrixOpMatrixMatrixMatrixReal(CubicBezier, CubicBezier);
xlMatrixAssignOpMatrixMatrixMatrixMatrixReal(AssignCubicBezier, CubicBezier);

#define _xlMatrixInit(e, m) \
	xlMatrix ## m = &_xlMatrix ## m; \
	xlMatrixAssign ## m(xlMatrix ## m);

void
xlMatrixInit()
{
	xlMatricesForEach(_xlMatrixInit)
}

#undef _xlMatrixInit

void
xlMatrixFini()
{
}

#undef xlMatrixAssignOpMatrixMatrixMatrixMatrixReal
#undef xlMatrixOpMatrixMatrixMatrixReal
#undef xlMatrixAssignOpMatrixMatrixMatrixReal
#undef xlMatrixOpMatrixMatrixReal
#undef xlMatrixAssignOpMatrixMatrixReal
#undef xlMatrixOpMatrixReal
#undef xlMatrixAssignMatricialOpMatrixMatrix
#undef xlMatrixMatricialOpMatrix
#undef xlMatrixAssignOpMatrixMatrix
#undef xlMatrixOpMatrix
#undef xlMatrixAssignOpMatrixReal
#undef xlMatrixOpReal
#undef xlMatrixAssignOpMatrix
#undef xlMatrixOp
#undef xlMatrixArrayAssignOpMatrixMatrixMatrix
#undef xlMatrixArrayOpMatrixMatrix
#undef xlMatrixArrayAssignOpMatrixRealReal
#undef xlMatrixArrayOpRealReal
#undef xlMatrixArrayAssignOpMatrixMatrix
#undef xlMatrixArrayOpMatrix
#undef xlMatrixArrayBooleanOpMatrix
#undef xlMatrixArrayAssignOpMatrix
#undef xlMatrixArrayOp
