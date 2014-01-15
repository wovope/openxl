#ifndef XL_MACROS_H
#define XL_MACROS_H

#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include <wchar.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>
#include <stdio.h>
#include <stdarg.h>
#include <XL/FL/xlflut.h>
#include <XL/GL/xlglut.h>
#include <XL/AL/xlalut.h>

#ifdef __cplusplus
#define XL_BEGIN_DECLS extern "C" {
#define XL_END_DECLS }
#else
#define XL_BEGIN_DECLS 
#define XL_END_DECLS 
#endif

#define xlLocaleSet setlocale
#define XL_LOCALE_ALL LC_ALL

#define xlMemoryZero bzero
#define xlMemorySet memset
#define xlMemoryCopy memcpy
#define xlMemoryAlloc malloc
#define xlMemoryFree free

#define xlRandSeed srand
#define XL_RAND_MAX RAND_MAX

#define xlSleepSeconds sleep
#define xlSleepMicroSeconds usleep
#define xlSleepMilliSeconds(a) usleep(a * 1000)

#define xlTime time
#define xlTimes times
#define	xlClockTicks() sysconf(_SC_CLK_TCK)

#define XL_INTEGER(i) ((XLint) (i))
#define xlIntegerCopy(ia, ib, n) xlMemoryCopy((ia), (ib), (n) * sizeof(XLint))
#define XL_INTEGER_RAND_MAX XL_INTEGER(XL_RAND_MAX)
#define xlIntegerRand rand
#define xlIntegerRandRange(a, b) (xlIntegerRand() % ((b) - (a)) + (a))
#define xlIntegerSleepMicroSeconds xlSleepMicroSeconds
#define xlIntegerSleepMilliSeconds(a) xlSleepMicroSeconds(a * XL_INTEGER(1000))
#define xlIntegerSleepSeconds xlSleepSeconds

#define XL_BOOLEAN(b) ((XLboolean) (b))
#define XL_FALSE 0
#define XL_TRUE 1
#define xlBooleanCopy(ia, ib, n) xlMemoryCopy((ia), (ib), (n) * sizeof(XLboolean))
#define xlBooleanRand() xlIntegerRandRange(0, 1)

#define XL_REAL(r) ((XLreal) (r))
#define xlRealPi XL_REAL(3.14159265358979323846)
#define xlRealZero XL_REAL(0)
#define xlRealHalf XL_REAL(0.5)
#define xlRealNegHalf XL_REAL(-0.5)
#define xlRealOne XL_REAL(1)
#define xlRealNegOne XL_REAL(-1)
#define xlRealDouble XL_REAL(2)
#define xlRealNegDouble XL_REAL(-2)
#define xlRealCopy(ra, rb, n) xlMemoryCopy((ra), (rb), (n) * sizeof(XLreal))
#define XL_REAL_RAND_MAX XL_REAL(XL_RAND_MAX)
#define xlRealRand() (XL_REAL(xlIntegerRand()) / XL_REAL_RAND_MAX)
#define xlRealRandRange(a, b) (xlRealRand() * ((b) - (a)) + (a))
#define xlRealSleepMicroSeconds xlIntegerSleepMicroSeconds
#define xlRealSleepMilliSeconds(r) xlIntegerSleepMicroSeconds(XL_INTEGER(r * XL_REAL(1000)))
#define xlRealSleepSeconds(r) xlIntegerSleepMicroSeconds(XL_INTEGER(r * XL_REAL(1000000)))

#if defined(XL_REAL_TYPE_FLOAT)
	#define XL_REAL_MAX FLT_MAX 
	#define xlRealSine sinf
	#define xlRealArcSine asinf
	#define xlRealCosine cosf
	#define xlRealArcCosine acosf
	#define xlRealSquareRoot sqrtf
	#define xlRealPower powf
	#define xlRealCeil ceilf
	#define xlRealLog logf
#elif defined(XL_REAL_TYPE_DOUBLE)
	#define XL_REAL_MAX DBL_MAX
	#define xlRealSine sin
	#define xlRealArcSine asin
	#define xlRealCosine cos
	#define xlRealArcCosine acos
	#define xlRealSquareRoot sqrt
	#define xlRealPower pow
	#define xlRealCeil ceil
	#define xlRealLog log
#endif
#define xlRealRadToDeg(r) ((r) * (XL_REAL(180) / xlRealPi))
#define xlRealDegToRad(r) ((r) * (xlRealPi / XL_REAL(180)))
#define xlRealNextTwoPower(r) (xlRealPower(XL_REAL(2), xlRealCeil(xlRealLog(r) / xlRealLog(XL_REAL(2)))))

#define xlIntegerComp(i) (~(i))
#define xlRealComp(r) XL_REAL(xlIntegerComp(XL_INTEGER(r)))

#define xlIntegerAbs(r) ((r) >= XL_INTEGER(0) ? (r) : -(r))
#define xlRealAbs(r) ((r) >= XL_REAL(0) ? (r) : -(r))

#define xlIntegerNeg(i) (-(i))
#define xlRealNeg(r) (-(r))

#define xlIntegerInc(i) ((i) + XL_INTEGER(1))
#define xlRealInc(r) ((r) + XL_REAL(1))

#define xlIntegerDec(i) ((i) - XL_INTEGER(1))
#define xlRealDec(r) ((r) - XL_REAL(1))

#define xlIntegerEqual(ia, ib) ((ia) == (ib))
#define xlRealEqual(ra, rb) ((ra) == (rb))

#define xlIntegerGreater(ia, ib) ((ia) > (ib))
#define xlRealGreater(ra, rb) ((ra) > (rb))

#define xlIntegerLesser(ia, ib) ((ia) < (ib))
#define xlRealLesser(ra, rb) ((ra) < (rb))

#define xlIntegerAnd(ia, ib) ((ia) & (ib))
#define xlRealAnd(ra, rb) XL_REAL(xlIntegerAnd(XL_INTEGER(ra), XL_INTEGER(rb)))

#define xlIntegerOr(ia, ib) ((ia) | (ib))
#define xlRealOr(ra, rb) XL_REAL(xlIntegerOr(XL_INTEGER(ra), XL_INTEGER(rb)))

#define xlIntegerXor(ia, ib) ((ia) ^ (ib))
#define xlRealXor(ra, rb) XL_REAL(xlIntegerXor(XL_INTEGER(ra), XL_INTEGER(rb)))

#define xlIntegerLShift(ia, ib) ((ia) << (ib))
#define xlRealLShift(ra, rb) XL_REAL(xlIntegerLShift(XL_INTEGER(ra), XL_INTEGER(rb)))

#define xlIntegerRShift(ia, ib) ((ia) >> (ib))
#define xlRealRShift(ra, rb) XL_REAL(xlIntegerRShift(XL_INTEGER(ra), XL_INTEGER(rb)))

#define xlIntegerAdd(ia, ib) ((ia) + (ib))
#define xlRealAdd(ra, rb) ((ra) + (rb))

#define xlIntegerSub(ia, ib) ((ia) - (ib))
#define xlRealSub(ra, rb) ((ra) - (rb))

#define xlIntegerMult(ia, ib) ((ia) * (ib))
#define xlRealMult(ra, rb) ((ra) * (rb))

#define xlIntegerDiv(ia, ib) ((ia) / (ib))
#define xlRealDiv(ra, rb) ((ra) / (rb))

#define xlIntegerMod(ia, ib) ((ia) % (ib))
#define xlRealMod(ra, rb) XL_REAL(xlIntegerMod(XL_INTEGER(ra), XL_INTEGER(rb)))

#define xlIntegerInvDiv(ia, ib) ((ib) / (ia))
#define xlRealInvDiv(ra, rb) ((rb) / (ra))

#define xlIntegerMin(a, b) ((a) > (b) ? (b) : (a))
#define xlRealMin(a, b) ((a) > (b) ? (b) : (a))

#define xlIntegerMax(a, b) ((a) > (b) ? (a) : (b))
#define xlRealMax(a, b) ((a) > (b) ? (a) : (b))

#define xlIntegerClamp(i, a, b) ((i) < (a) ? (a) : ((b) < (i) ? (b) : (i)))
#define xlRealClamp(r, a, b) ((r) < (a) ? (a) : ((b) < (r) ? (b) : (r)))

#define xlIntegerLerp(a, b, t) (((b) - (a)) * (t) + (a))
#define xlRealLerp(a, b, t) (((b) - (a)) * (t) + (a))

#define xlIntegerQuadBezier(a, b, c, t) ((XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (a) + XL_INTEGER(2) * (XL_INTEGER(1) - (t)) * (t) * (b) + (t) * (t) * (c))
#define xlRealQuadBezier(a, b, c, t) ((XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (a) + XL_REAL(2) * (XL_REAL(1) - (t)) * (t) * (b) + (t) * (t) * (c))

#define xlIntegerCubicBezier(a, b, c, d, t) ((XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (a) + XL_INTEGER(3) * (XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (t) * (b) + XL_INTEGER(3) * (XL_INTEGER(1) - (t)) * (t) * (t) * (c) + (t) * (t) * (t) * (d))
#define xlRealCubicBezier(a, b, c, d, t) ((XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (a) + XL_REAL(3) * (XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (t) * (b) + XL_REAL(3) * (XL_REAL(1) - (t)) * (t) * (t) * (c) + (t) * (t) * (t) * (d))

#define xlIntegerInIndex(i, a, b) ((a) <= (i) && (i) < (b))
#define xlRealInIndex(r, a, b) ((a) <= (r) && (r) < (b))

#define xlIntegerInRange(i, a, b) ((a) <= (i) && (i) <= (b))
#define xlRealInRange(r, a, b) ((a) <= (r) && (r) <= (b))

#ifdef XL_SIMD
	#define XL_SIMD_VECTOR_SIZE(v, s) v __attribute__ ((vector_size(s), aligned(s)))
	#define XL_SIMD_ALIGNED(v, a) v __attribute__ ((aligned(a)))
	#define XL_SIMD_IS_ALIGNED(v, a) (!(((XLulong)(&(v))) % (a)))
	#define xlSimdAlignedAlloc(a, b) aligned_alloc(a, b)
	
	#define XL_SIMD4SI(i) ((XLsimd4si) (i))
	#define XL_SIMD16SI(i) ((XLsimd16si) (i))

	#define XL_SIMD4SR(r) ((XLsimd4sr) (r))
	#define XL_SIMD16SR(r) ((XLsimd16sr) (r))

	#if defined(XL_REAL_TYPE_FLOAT)
		#define XL_SIMD_ALIGNED_4SI(v) XL_SIMD_ALIGNED(v, 4 * sizeof(XLint))
		#define XL_SIMD_IS_ALIGNED_4SI(v) XL_SIMD_IS_ALIGNED(v, 4 * sizeof(XLint))
		#define xlSimdAligned4siAlloc(a) xlSimdAlignedAlloc(4 * sizeof(XLint), a) 

		#define XL_SIMD_ALIGNED_16SI(v) XL_SIMD_ALIGNED(v, 16 * sizeof(XLint))
		#define XL_SIMD_IS_ALIGNED_16SI(v) XL_SIMD_IS_ALIGNED(v, 16 * sizeof(XLint))
		#define xlSimdAligned16siAlloc(a) xlSimdAlignedAlloc(16 * sizeof(XLint), a)
	#elif defined(XL_REAL_TYPE_DOUBLE)
		#define XL_SIMD_ALIGNED_4SI(v) XL_SIMD_ALIGNED(v, 4 * sizeof(XLint64))
		#define XL_SIMD_IS_ALIGNED_4SI(v) XL_SIMD_IS_ALIGNED(v, 4 * sizeof(XLint64))
		#define xlSimdAligned4siAlloc(a) xlSimdAlignedAlloc(4 * sizeof(XLint64), a)
	
		#define XL_SIMD_ALIGNED_16SI(v) XL_SIMD_ALIGNED(v, 16 * sizeof(XLint64))
		#define XL_SIMD_IS_ALIGNED_16SI(v) XL_SIMD_IS_ALIGNED(v, 16 * sizeof(XLint64))
		#define xlSimdAligned16siAlloc(a) xlSimdAlignedAlloc(16 * sizeof(XLint64), a)
	#endif

	#define XL_SIMD_ALIGNED_4SR(v) XL_SIMD_ALIGNED(v, 4 * sizeof(XLreal))
	#define XL_SIMD_IS_ALIGNED_4SR(v) XL_SIMD_IS_ALIGNED(v, 4 * sizeof(XLreal))
	#define xlSimdAligned4srAlloc(a) xlSimdAlignedAlloc(4 * sizeof(XLreal), a)
	
	#define XL_SIMD_ALIGNED_16SR(v) XL_SIMD_ALIGNED(v, 16 * sizeof(XLreal))
	#define XL_SIMD_IS_ALIGNED_16SR(v) XL_SIMD_IS_ALIGNED(v, 16 * sizeof(XLreal))
	#define xlSimdAligned16srAlloc(a) xlSimdAlignedAlloc(16 * sizeof(XLreal), a)
	
	#define xlAlloc xlSimdAligned16srAlloc
#else
	#define xlAlloc malloc
#endif
#define xlFree free

#ifdef XL_SIMD
	#define xlSimd4siComp(i) (~(i))
	#define xlSimd16siComp(i) (~(i))
	#define xlSimd4srComp(r) XL_SIMD4SR(xlSimd4siComp(XL_SIMD4SI(r)))
	#define xlSimd16srComp(r) XL_SIMD16SR(xlSimd16siComp(XL_SIMD16SI(r)))

	#define xlSimd4siNeg(i) (-(i))
	#define xlSimd16siNeg(i) (-(i))
	#define xlSimd4srNeg(r) (-(r))
	#define xlSimd16srNeg(r) (-(r))

	#define xlSimd4siInc(i) ((i) + XL_INTEGER(1))
	#define xlSimd16siInc(i) ((i) + XL_INTEGER(1))
	#define xlSimd4srInc(r) ((r) + XL_REAL(1))
	#define xlSimd16srInc(r) ((r) + XL_REAL(1))

	#define xlSimd4siDec(i) ((i) - XL_INTEGER(1))
	#define xlSimd16siDec(i) ((i) - XL_INTEGER(1))
	#define xlSimd4srDec(r) ((r) - XL_REAL(1))
	#define xlSimd16srDec(r) ((r) - XL_REAL(1))

	#define xlSimd4siEqual(ia, ib) ((ia) == (ib))
	#define xlSimd16siEqual(ia, ib) ((ia) == (ib))
	#define xlSimd4srEqual(ra, rb) ((ra) == (rb))
	#define xlSimd16srEqual(ra, rb) ((ra) == (rb))

	#define xlSimd4siGreater(ia, ib) ((ia) > (ib))
	#define xlSimd16siGreater(ia, ib) ((ia) > (ib))
	#define xlSimd4srGreater(ra, rb) ((ra) > (rb))
	#define xlSimd16srGreater(ra, rb) ((ra) > (rb))

	#define xlSimd4siLesser(ia, ib) ((ia) < (ib))
	#define xlSimd16siLesser(ia, ib) ((ia) < (ib))
	#define xlSimd4srLesser(ra, rb) ((ra) < (rb))
	#define xlSimd16srLesser(ra, rb) ((ra) < (rb))

	#define xlSimd4siAndInteger(ia, ib) ((ia) & (ib))
	#define xlSimd16siAndInteger(ia, ib) ((ia) & (ib))
	#define xlSimd4srAndReal(ra, rb) XL_SIMD4SR(xlSimd4siAndInteger(XL_SIMD4SI(ra), XL_INTEGER(rb)))
	#define xlSimd16srAndReal(ra, rb) XL_SIMD16SR(xlSimd16siAndInteger(XL_SIMD16SI(ra), XL_INTEGER(rb)))
	#define xlSimd4siAnd(ia, ib) ((ia) & (ib))
	#define xlSimd16siAnd(ia, ib) ((ia) & (ib))
	#define xlSimd4srAnd(ra, rb) XL_SIMD4SR(xlSimd4siAnd(XL_SIMD4SI(ra), XL_SIMD4SI(rb)))
	#define xlSimd16srAnd(ra, rb) XL_SIMD16SR(xlSimd16siAnd(XL_SIMD16SI(ra), XL_SIMD16SI(rb)))

	#define xlSimd4siOrInteger(ia, ib) ((ia) | (ib))
	#define xlSimd16siOrInteger(ia, ib) ((ia) | (ib))
	#define xlSimd4srOrReal(ra, rb) XL_SIMD4SR(xlSimd4siOrInteger(XL_SIMD4SI(ra), XL_INTEGER(rb)))
	#define xlSimd16srOrReal(ra, rb) XL_SIMD16SR(xlSimd16siOrInteger(XL_SIMD16SI(ra), XL_INTEGER(rb)))
	#define xlSimd4siOr(ia, ib) ((ia) | (ib))
	#define xlSimd16siOr(ia, ib) ((ia) | (ib))
	#define xlSimd4srOr(ra, rb) XL_SIMD4SR(xlSimd4siOr(XL_SIMD4SI(ra), XL_SIMD4SI(rb)))
	#define xlSimd16srOr(ra, rb) XL_SIMD16SR(xlSimd16siOr(XL_SIMD16SI(ra), XL_SIMD16SI(rb)))

	#define xlSimd4siXorInteger(ia, ib) ((ia) ^ (ib))
	#define xlSimd16siXorInteger(ia, ib) ((ia) ^ (ib))
	#define xlSimd4srXorReal(ra, rb) XL_SIMD4SR(xlSimd4siXorInteger(XL_SIMD4SI(ra), XL_INTEGER(rb)))
	#define xlSimd16srXorReal(ra, rb) XL_SIMD16SR(xlSimd16siXorInteger(XL_SIMD16SI(ra), XL_INTEGER(rb)))
	#define xlSimd4siXor(ia, ib) ((ia) ^ (ib))
	#define xlSimd16siXor(ia, ib) ((ia) ^ (ib))
	#define xlSimd4srXor(ra, rb) XL_SIMD4SR(xlSimd4siXor(XL_SIMD4SI(ra), XL_SIMD4SI(rb)))
	#define xlSimd16srXor(ra, rb) XL_SIMD16SR(xlSimd16siXor(XL_SIMD16SI(ra), XL_SIMD16SI(rb)))

	#define xlSimd4siLShiftInteger(ia, ib) ((ia) << (ib))
	#define xlSimd16siLShiftInteger(ia, ib) ((ia) << (ib))
	#define xlSimd4srLShiftReal(ra, rb) XL_SIMD4SR(xlSimd4siLShiftInteger(XL_SIMD4SI(ra), XL_INTEGER(rb)))
	#define xlSimd16srLShiftReal(ra, rb) XL_SIMD16SR(xlSimd16siLShiftInteger(XL_SIMD16SI(ra), XL_INTEGER(rb)))
	#define xlSimd4siLShift(ia, ib) ((ia) << (ib))
	#define xlSimd16siLShift(ia, ib) ((ia) << (ib))
	#define xlSimd4srLShift(ra, rb) XL_SIMD4SR(xlSimd4siLShift(XL_SIMD4SI(ra), XL_SIMD4SI(rb)))
	#define xlSimd16srLShift(ra, rb) XL_SIMD16SR(xlSimd16siLShift(XL_SIMD16SI(ra), XL_SIMD16SI(rb)))

	#define xlSimd4siRShiftInteger(ia, ib) ((ia) >> (ib))
	#define xlSimd16siRShiftInteger(ia, ib) ((ia) >> (ib))
	#define xlSimd4srRShiftReal(ra, rb) XL_SIMD4SR(xlSimd4siRShiftInteger(XL_SIMD4SI(ra), XL_INTEGER(rb)))
	#define xlSimd16srRShiftReal(ra, rb) XL_SIMD16SR(xlSimd16siRShiftInteger(XL_SIMD16SI(ra), XL_INTEGER(rb)))
	#define xlSimd4siRShift(ia, ib) ((ia) >> (ib))
	#define xlSimd16siRShift(ia, ib) ((ia) >> (ib))
	#define xlSimd4srRShift(ra, rb) XL_SIMD4SR(xlSimd4siRShift(XL_SIMD4SI(ra), XL_SIMD4SI(rb)))
	#define xlSimd16srRShift(ra, rb) XL_SIMD16SR(xlSimd16siRShift(XL_SIMD16SI(ra), XL_SIMD16SI(rb)))

	#define xlSimd4siAddInteger(ia, ib) ((ia) + (ib))
	#define xlSimd16siAddInteger(ia, ib) ((ia) + (ib))
	#define xlSimd4srAddReal(ra, rb) ((ra) + (rb))
	#define xlSimd16srAddReal(ra, rb) ((ra) + (rb))
	#define xlSimd4siAdd(ia, ib) ((ia) + (ib))
	#define xlSimd16siAdd(ia, ib) ((ia) + (ib))
	#define xlSimd4srAdd(ra, rb) ((ra) + (rb))
	#define xlSimd16srAdd(ra, rb) ((ra) + (rb))

	#define xlSimd4siSubInteger(ia, ib) ((ia) - (ib))
	#define xlSimd16siSubInteger(ia, ib) ((ia) - (ib))
	#define xlSimd4srSubReal(ra, rb) ((ra) - (rb))
	#define xlSimd16srSubReal(ra, rb) ((ra) - (rb))
	#define xlSimd4siSub(ia, ib) ((ia) - (ib))
	#define xlSimd16siSub(ia, ib) ((ia) - (ib))
	#define xlSimd4srSub(ra, rb) ((ra) - (rb))
	#define xlSimd16srSub(ra, rb) ((ra) - (rb))

	#define xlSimd4siMultInteger(ia, ib) ((ia) * (ib))
	#define xlSimd16siMultInteger(ia, ib) ((ia) * (ib))
	#define xlSimd4srMultReal(ra, rb) ((ra) * (rb))
	#define xlSimd16srMultReal(ra, rb) ((ra) * (rb))
	#define xlIntegerMultSimd4si(ia, ib) ((ia) * (ib))
	#define xlIntegerMultSimd16si(ia, ib) ((ia) * (ib))
	#define xlRealMultSimd4sr(ra, rb) ((ra) * (rb))
	#define xlRealMultSimd16sr(ra, rb) ((ra) * (rb))
	#define xlSimd4siMult(ia, ib) ((ia) * (ib))
	#define xlSimd16siMult(ia, ib) ((ia) * (ib))
	#define xlSimd4srMult(ra, rb) ((ra) * (rb))
	#define xlSimd16srMult(ra, rb) ((ra) * (rb))

	#define xlSimd4siDivInteger(ia, ib) ((ia) / (ib))
	#define xlSimd16siDivInteger(ia, ib) ((ia) / (ib))
	#define xlSimd4srDivReal(ra, rb) ((ra) / (rb))
	#define xlSimd16srDivReal(ra, rb) ((ra) / (rb))
	#define xlIntegerDivSimd4si(ia, ib) ((ia) / (ib))
	#define xlIntegerDivSimd16si(ia, ib) ((ia) / (ib))
	#define xlRealDivSimd4sr(ra, rb) ((ra) / (rb))
	#define xlRealDivSimd16sr(ra, rb) ((ra) / (rb))
	#define xlSimd4siDiv(ia, ib) ((ia) / (ib))
	#define xlSimd16siDiv(ia, ib) ((ia) / (ib))
	#define xlSimd4srDiv(ra, rb) ((ra) / (rb))
	#define xlSimd16srDiv(ra, rb) ((ra) / (rb))

	#define xlSimd4siModInteger(ia, ib) ((ia) % (ib))
	#define xlSimd16siModInteger(ia, ib) ((ia) % (ib))
	#define xlSimd4srModReal(ra, rb) XL_SIMD4SR(xlSimd4siModInteger(XL_SIMD4SI(ra), XL_INTEGER(rb)))
	#define xlSimd16srModReal(ra, rb) XL_SIMD16SR(xlSimd16siModInteger(XL_SIMD16SI(ra), XL_INTEGER(rb)))
	#define xlIntegerModSimd4si(ia, ib) ((ia) % (ib))
	#define xlIntegerModSimd16si(ia, ib) ((ia) % (ib))
	#define xlRealModSimd4sr(ra, rb) XL_SIMD4SR(XL_INTEGER(ra) % XL_SIMD4SI(rb))
	#define xlRealModSimd16sr(ra, rb) XL_SIMD16SR(XL_INTEGER(ra) % XL_SIMD16SI(rb))
	#define xlSimd4siMod(ia, ib) ((ia) % (ib))
	#define xlSimd16siMod(ia, ib) ((ia) % (ib))
	#define xlSimd4srMod(ra, rb) XL_SIMD4SR(xlSimd4siMod(XL_SIMD4SI(ra), XL_SIMD4SI(rb)))
	#define xlSimd16srMod(ra, rb) XL_SIMD16SR(xlSimd16siMod(XL_SIMD16SI(ra), XL_SIMD16SI(rb)))

	#define xlSimd4siInvDivInteger(ia, ib) ((ib) / (ia))
	#define xlSimd16siInvDivInteger(ia, ib) ((ib) / (ia))
	#define xlSimd4srInvDivReal(ra, rb) ((rb) / (ra))
	#define xlSimd16srInvDivReal(ra, rb) ((rb) / (ra))
	#define xlIntegerInvDivSimd4si(ia, ib) ((ib) / (ia))
	#define xlIntegerInvDivSimd16si(ia, ib) ((ib) / (ia))
	#define xlRealInvDivSimd4sr(ra, rb) ((rb) / (ra))
	#define xlRealInvDivSimd16sr(ra, rb) ((rb) / (ra))
	#define xlSimd4siInvDiv(ia, ib) ((ib) / (ia))
	#define xlSimd16siInvDiv(ia, ib) ((ib) / (ia))
	#define xlSimd4srInvDiv(ra, rb) ((rb) / (ra))
	#define xlSimd16srInvDiv(ra, rb) ((rb) / (ra))

	#define xlSimd4siLerp(a, b, t) (((b) - (a)) * (t) + (a))
	#define xlSimd16siLerp(a, b, t) (((b) - (a)) * (t) + (a))
	#define xlSimd4srLerp(a, b, t) (((b) - (a)) * (t) + (a))
	#define xlSimd16srLerp(a, b, t) (((b) - (a)) * (t) + (a))

	#define xlSimd4siQuadBezier(a, b, c, t) ((XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (a) + XL_INTEGER(2) * (XL_INTEGER(1) - (t)) * (t) * (b) + (t) * (t) * (c))
	#define xlSimd16siQuadBezier(a, b, c, t) ((XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (a) + XL_INTEGER(2) * (XL_INTEGER(1) - (t)) * (t) * (b) + (t) * (t) * (c))
	#define xlSimd4srQuadBezier(a, b, c, t) ((XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (a) + XL_REAL(2) * (XL_REAL(1) - (t)) * (t) * (b) + (t) * (t) * (c))
	#define xlSimd16srQuadBezier(a, b, c, t) ((XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (a) + XL_REAL(2) * (XL_REAL(1) - (t)) * (t) * (b) + (t) * (t) * (c))

	#define xlSimd4siCubicBezier(a, b, c, d, t) ((XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (a) + XL_INTEGER(3) * (XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (t) * (b) + XL_INTEGER(3) * (XL_INTEGER(1) - (t)) * (t) * (t) * (c) + (t) * (t) * (t) * (d))
	#define xlSimd16siCubicBezier(a, b, c, d, t) ((XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (a) + XL_INTEGER(3) * (XL_INTEGER(1) - (t)) * (XL_INTEGER(1) - (t)) * (t) * (b) + XL_INTEGER(3) * (XL_INTEGER(1) - (t)) * (t) * (t) * (c) + (t) * (t) * (t) * (d))
	#define xlSimd4srCubicBezier(a, b, c, d, t) ((XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (a) + XL_REAL(3) * (XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (t) * (b) + XL_REAL(3) * (XL_REAL(1) - (t)) * (t) * (t) * (c) + (t) * (t) * (t) * (d))
	#define xlSimd16srCubicBezier(a, b, c, d, t) ((XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (a) + XL_REAL(3) * (XL_REAL(1) - (t)) * (XL_REAL(1) - (t)) * (t) * (b) + XL_REAL(3) * (XL_REAL(1) - (t)) * (t) * (t) * (c) + (t) * (t) * (t) * (d))
#endif

#define XL_STRING_SIZE 256
#define XL_STRING_BUFFER_SIZE (XL_STRING_SIZE * 2)
#define xlStringZero(s) xlMemorySet(s, 0, XL_STRING_SIZE * sizeof(XLwchar))
#define xlStringCopy wcscpy
#define xlStringCappedCopy wcsncpy
#define xlStringLength wcslen
#define xlStringDup wcsdup
#define xlStringEqual(a, b) (!wcscmp(a, b))
#define xlStringCappedEqual(a, b, n) (!wcsncmp(a, b, n))
#define xlStringConcat wcscat
#define xlStringCappedConcat wcsncat
#define xlStringScanFormatted swscanf
#define xlStringPrintFormatted swprintf
#define xlStringFromPath mbstowcs
#define xlPathToString mbstowcs
#define xlIntegerToString(a) wcstol(a, NULL, 10)
#define xlRealToString(a) wcstof(a, NULL, 10)

#define XL_PATH_SIZE 256
#define XL_PATH_BUFFER_SIZE (XL_PATH_SIZE * 2)
#define XL_PATH_SEPARATOR "/"
#define XL_PATH_DOT "."
#define XL_PATH_EXTENSION_COMPILED "xlc"
#define XL_PATH_EXTENSION_DECOMPILED "xld"
#define XL_PATH_EXTENSION_PROCEDURAL "xl"
#define XL_PATH_STANDARD_LOG "xl.log"
#define xlPathZero(p) xlMemorySet(p, 0, XL_PATH_SIZE * sizeof(XLchar))
#define xlPathCopy strcpy
#define xlPathCappedCopy strncpy
#define xlPathLength strlen
#define xlPathDup strdup
#define xlPathEqual(a, b) (!strcmp(a, b))
#define xlPathCappedEqual(a, b, n) (!strncmp(a, b, n))
#define xlPathConcat strcat
#define xlPathCappedConcat strncat
#define xlPathScanFormatted scanf
#define xlPathPrintFormatted snprintf
#define xlPathFromString wcstombs
#define xlStringToPath wcstombs
#define xlIntegerToPath(a) strtol(a, NULL, 10)
#define xlRealToPath(a) strtof(a, NULL, 10)

#define XL_FILE_STANDARD_INPUT stdin
#define XL_FILE_STANDARD_OUTPUT stdout
#define XL_FILE_STANDARD_ERROR stderr
#define xlFileOpen fopen
#define xlFileClose fclose
#define xlFileFlush fflush
#define xlFileRewind rewind
#define xlFileRead fread
#define xlFileWrite fwrite
#define xlFileGetString fgetws
#define xlFileScanString fwscanf
#define xlFilePrintStringFormatted fwprintf
#define xlFilePrintStringFormattedVariadic vfwprintf
#define xlFileMakeTemporal mktemp

#define XLpixel XLfloat
#define GL_PIXEL GL_FLOAT
#define Pixel FloatPixel

#ifdef XL_SIMD
	#define XL_PAIR_ARRAY(v) \
		((v)->value.array)
	#define XL_PAIR_SIMD(v) \
		((v)->value.simd)

	#define XL_COLOR_ARRAY(v) \
		((v)->value.array)
	#define XL_COLOR_SIMD(v) \
		((v)->value.simd)

	#define XL_POINT_ARRAY(v) \
		((v)->value.array)
	#define XL_POINT_SIMD(v) \
		((v)->value.simd)

	#define XL_VECTOR_ARRAY(v) \
		((v)->value.array)
	#define XL_VECTOR_SIMD(v) \
		((v)->value.simd)

	#define XL_MATRIX_ARRAY(v) \
		((v)->value.array)
	#define XL_MATRIX_SIMD(v) \
		((v)->value.simd)
#else
	#define XL_PAIR_ARRAY(v) \
		((v)->array)

	#define XL_COLOR_ARRAY(v) \
		((v)->array)

	#define XL_POINT_ARRAY(v) \
		((v)->array)

	#define XL_VECTOR_ARRAY(v) \
		((v)->array)

	#define XL_MATRIX_ARRAY(v) \
		((v)->array)
#endif

#define XL_PAIR_X(v) \
	(XL_PAIR_ARRAY(v)[0])
#define XL_PAIR_Y(v) \
	(XL_PAIR_ARRAY(v)[1])
#define XL_PAIR_Z(v) \
	(XL_PAIR_ARRAY(v)[2])
#define XL_PAIR_W(v) \
	(XL_PAIR_ARRAY(v)[3])

#define XL_COLOR_R(v) \
	(XL_COLOR_ARRAY(v)[0])
#define XL_COLOR_G(v) \
	(XL_COLOR_ARRAY(v)[1])
#define XL_COLOR_B(v) \
	(XL_COLOR_ARRAY(v)[2])
#define XL_COLOR_A(v) \
	(XL_COLOR_ARRAY(v)[3])

#define XL_POINT_X(v) \
	(XL_POINT_ARRAY(v)[0])
#define XL_POINT_Y(v) \
	(XL_POINT_ARRAY(v)[1])
#define XL_POINT_Z(v) \
	(XL_POINT_ARRAY(v)[2])
#define XL_POINT_W(v) \
	(XL_POINT_ARRAY(v)[3])

#define XL_VECTOR_X(v) \
	(XL_VECTOR_ARRAY(v)[0])
#define XL_VECTOR_Y(v) \
	(XL_VECTOR_ARRAY(v)[1])
#define XL_VECTOR_Z(v) \
	(XL_VECTOR_ARRAY(v)[2])
#define XL_VECTOR_W(v) \
	(XL_VECTOR_ARRAY(v)[3])

#define XL_MATRIX_XX(v) \
	(XL_MATRIX_ARRAY(v)[0])
#define XL_MATRIX_YX(v) \
	(XL_MATRIX_ARRAY(v)[1])
#define XL_MATRIX_ZX(v) \
	(XL_MATRIX_ARRAY(v)[2])
#define XL_MATRIX_WX(v) \
	(XL_MATRIX_ARRAY(v)[3])
#define XL_MATRIX_XY(v) \
	(XL_MATRIX_ARRAY(v)[4])
#define XL_MATRIX_YY(v) \
	(XL_MATRIX_ARRAY(v)[5])
#define XL_MATRIX_ZY(v) \
	(XL_MATRIX_ARRAY(v)[6])
#define XL_MATRIX_WY(v) \
	(XL_MATRIX_ARRAY(v)[7])
#define XL_MATRIX_XZ(v) \
	(XL_MATRIX_ARRAY(v)[8])
#define XL_MATRIX_YZ(v) \
	(XL_MATRIX_ARRAY(v)[9])
#define XL_MATRIX_ZZ(v) \
	(XL_MATRIX_ARRAY(v)[10])
#define XL_MATRIX_WZ(v) \
	(XL_MATRIX_ARRAY(v)[11])
#define XL_MATRIX_XW(v) \
	(XL_MATRIX_ARRAY(v)[12])
#define XL_MATRIX_YW(v) \
	(XL_MATRIX_ARRAY(v)[13])
#define XL_MATRIX_ZW(v) \
	(XL_MATRIX_ARRAY(v)[14])
#define XL_MATRIX_WW(v) \
	(XL_MATRIX_ARRAY(v)[15])

#define xlPairsForEach(f) \
	f(DEFAULT, Default) \
	f(NEG_DEFAULT, NegDefault) \
	f(ZERO, Zero) \
	f(HALF, Half) \
	f(NEG_HALF, NegHalf) \
	f(ONE, One) \
	f(NEG_ONE, NegOne) \
	f(DOUBLE, Double) \
	f(NEG_DOUBLE, NegDouble) \
	f(X, X) \
	f(NEG_X, NegX) \
	f(Y, Y) \
	f(NEG_Y, NegY) \
	f(TMP, TMP) \
	f(TMP1, TMP1) \
	f(TMP2, TMP2) \
	f(TMP3, TMP3) \
	f(TMP4, TMP4) \
	f(CENTER, Center) \
	f(RIGHT, Right) \
	f(LEFT, Left) \
	f(UP, Up) \
	f(DOWN, Down) \
	f(RIGHT_UP, RightUp) \
	f(RIGHT_DOWN, RightDown) \
	f(LEFT_UP, LeftUp) \
	f(LEFT_DOWN, LeftDown) \
	f(ORIGIN, Origin) \
	f(NORTH, North) \
	f(SOUTH, South) \
	f(EAST, East) \
	f(WEST, West) \
	f(NORTH_EAST, NorthEast) \
	f(NORTH_WEST, NorthWest) \
	f(SOUTH_EAST, SouthEast) \
	f(SOUTH_WEST, SouthWest) \

#define XL_PAIR_DIRECTION_FIRST XL_PAIR_CENTER
#define XL_PAIR_DIRECTION_LAST XL_PAIR_LEFT_DOWN
#define XL_PAIRS_DIRECTION_COUNT (XL_PAIR_DIRECTION_LAST - XL_PAIR_DIRECTION_FIRST + 1)

#define XL_PAIR_ORIENTATION_FIRST XL_PAIR_ORIGIN
#define XL_PAIR_ORIENTATION_LAST XL_PAIR_SOUTH_WEST
#define XL_PAIRS_ORIENTATION_COUNT (XL_PAIR_ORIENTATION_LAST - XL_PAIR_ORIENTATION_FIRST + 1)

#define xlColorsForEach(f) \
	f(DEFAULT, Default) \
	f(NEG_DEFAULT, NegDefault) \
	f(ZERO, Zero) \
	f(HALF, Half) \
	f(NEG_HALF, NegHalf) \
	f(ONE, One) \
	f(NEG_ONE, NegOne) \
	f(DOUBLE, Double) \
	f(NEG_DOUBLE, NegDouble) \
	f(R, R) \
	f(NEG_R, NegR) \
	f(G, G) \
	f(NEG_G, NegG) \
	f(B, B) \
	f(NEG_B, NegB) \
	f(A, A) \
	f(NEG_A, NegA) \
	f(TMP, TMP) \
	f(TMP1, TMP1) \
	f(TMP2, TMP2) \
	f(TMP3, TMP3) \
	f(TMP4, TMP4) \
	f(ALICE_BLUE, AliceBlue) \
	f(ANTIQUE_WHITE, AntiqueWhite) \
	f(AQUA, Aqua) \
	f(AQUAMARINE, Aquamarine) \
	f(AZURE, Azure) \
	f(BEIGE, Beige) \
	f(BISQUE, Bisque) \
	f(BLACK, Black) \
	f(BLANCHED_ALMOND, BlanchedAlmond) \
	f(BLUE, Blue) \
	f(BLUE_VIOLET, BlueViolet) \
	f(BROWN, Brown) \
	f(BURLY_WOOD, BurlyWood) \
	f(CADET_BLUE, CadetBlue) \
	f(CHARTREUSE, Chartreuse) \
	f(CHOCOLATE, Chocolate) \
	f(CORAL, Coral) \
	f(CORNFLOWER_BLUE, CornflowerBlue) \
	f(CORNSILK, Cornsilk) \
	f(CRIMSON, Crimson) \
	f(CYAN, Cyan) \
	f(DARK_BLUE, DarkBlue) \
	f(DARK_CYAN, DarkCyan) \
	f(DARK_GOLDEN_ROD, DarkGoldenRod) \
	f(DARK_GRAY, DarkGray) \
	f(DARK_GREEN, DarkGreen) \
	f(DARK_KHAKI, DarkKhaki) \
	f(DARK_MAGENTA, DarkMagenta) \
	f(DARK_OLIVE_GREEN, DarkOliveGreen) \
	f(DARK_ORANGE, DarkOrange) \
	f(DARK_ORCHID, DarkOrchid) \
	f(DARK_RED, DarkRed) \
	f(DARK_SALMON, DarkSalmon) \
	f(DARK_SEA_GREEN, DarkSeaGreen) \
	f(DARK_SLATE_BLUE, DarkSlateBlue) \
	f(DARK_SLATE_GRAY, DarkSlateGray) \
	f(DARK_TURQUOISE, DarkTurquoise) \
	f(DARK_VIOLET, DarkViolet) \
	f(DEEP_PINK, DeepPink) \
	f(DEEP_SKY_BLUE, DeepSkyBlue) \
	f(DIM_GRAY, DimGray) \
	f(DIM_GREY, DimGrey) \
	f(DODGER_BLUE, DodgerBlue) \
	f(FIRE_BRICK, FireBrick) \
	f(FLORAL_WHITE, FloralWhite) \
	f(FOREST_GREEN, ForestGreen) \
	f(FUCHSIA, Fuchsia) \
	f(GAINSBORO, Gainsboro) \
	f(GHOST_WHITE, GhostWhite) \
	f(GOLD, Gold) \
	f(GOLDEN_ROD, GoldenRod) \
	f(GRAY, Gray) \
	f(GREEN, Green) \
	f(GREEN_YELLOW, GreenYellow) \
	f(HONEY_DEW, HoneyDew) \
	f(HOT_PINK, HotPink) \
	f(INDIAN_RED, IndianRed) \
	f(INDIGO, Indigo) \
	f(IVORY, Ivory) \
	f(KHAKI, Khaki) \
	f(LAVENDER, Lavender) \
	f(LAVENDER_BLUSH, LavenderBlush) \
	f(LAWN_GREEN, LawnGreen) \
	f(LEMON_CHIFFON, LemonChiffon) \
	f(LIGHT_BLUE, LightBlue) \
	f(LIGHT_CORAL, LightCoral) \
	f(LIGHT_CYAN, LightCyan) \
	f(LIGHT_GOLDEN_ROD_YELLOW, LightGoldenRodYellow) \
	f(LIGHT_GRAY, LightGray) \
	f(LIGHT_GREEN, LightGreen) \
	f(LIGHT_PINK, LightPink) \
	f(LIGHT_SALMON, LightSalmon) \
	f(LIGHT_SEA_GREEN, LightSeaGreen) \
	f(LIGHT_SKY_BLUE, LightSkyBlue) \
	f(LIGHT_SLATE_GRAY, LightSlateGray) \
	f(LIGHT_STEEL_BLUE, LightSteelBlue) \
	f(LIGHT_YELLOW, LightYellow) \
	f(LIME, Lime) \
	f(LIME_GREEN, LimeGreen) \
	f(LINEN, Linen) \
	f(MAGENTA, Magenta) \
	f(MAROON, Maroon) \
	f(MEDIUM_AQUA_MARINE, MediumAquaMarine) \
	f(MEDIUM_BLUE, MediumBlue) \
	f(MEDIUM_ORCHID, MediumOrchid) \
	f(MEDIUM_PURPLE, MediumPurple) \
	f(MEDIUM_SEA_GREEN, MediumSeaGreen) \
	f(MEDIUM_SLATE_BLUE, MediumSlateBlue) \
	f(MEDIUM_SPRING_GREEN, MediumSpringGreen) \
	f(MEDIUM_TURQUOISE, MediumTurquoise) \
	f(MEDIUM_VIOLET_RED, MediumVioletRed) \
	f(MIDNIGHT_BLUE, MidnightBlue) \
	f(MINT_CREAM, MintCream) \
	f(MISTY_ROSE, MistyRose) \
	f(MOCCASIN, Moccasin) \
	f(NAVAJO_WHITE, NavajoWhite) \
	f(NAVY, Navy) \
	f(OLD_LACE, OldLace) \
	f(OLIVE, Olive) \
	f(OLIVE_DRAB, OliveDrab) \
	f(ORANGE, Orange) \
	f(ORANGE_RED, OrangeRed) \
	f(ORCHID, Orchid) \
	f(PALE_GOLDEN_ROD, PaleGoldenRod) \
	f(PALE_GREEN, PaleGreen) \
	f(PALE_TURQUOISE, PaleTurquoise) \
	f(PALE_VIOLET_RED, PaleVioletRed) \
	f(PAPAYA_WHIP, PapayaWhip) \
	f(PEACH_PUFF, PeachPuff) \
	f(PERU, Peru) \
	f(PINK, Pink) \
	f(PLUM, Plum) \
	f(POWDER_BLUE, PowderBlue) \
	f(PURPLE, Purple) \
	f(RED, Red) \
	f(ROSY_BROWN, RosyBrown) \
	f(ROYAL_BLUE, RoyalBlue) \
	f(SADDLE_BROWN, SaddleBrown) \
	f(SALMON, Salmon) \
	f(SANDY_BROWN, SandyBrown) \
	f(SEA_GREEN, SeaGreen) \
	f(SEA_SHELL, SeaShell) \
	f(SIENNA, Sienna) \
	f(SILVER, Silver) \
	f(SKY_BLUE, SkyBlue) \
	f(SLATE_BLUE, SlateBlue) \
	f(SLATE_GRAY, SlateGray) \
	f(SNOW, Snow) \
	f(SPRING_GREEN, SpringGreen) \
	f(STEEL_BLUE, SteelBlue) \
	f(TAN, Tan) \
	f(TEAL, Teal) \
	f(THISTLE, Thistle) \
	f(TOMATO, Tomato) \
	f(TURQUOISE, Turquoise) \
	f(VIOLET, Violet) \
	f(WHEAT, Wheat) \
	f(WHITE, White) \
	f(WHITE_SMOKE, WhiteSmoke) \
	f(YELLOW, Yellow) \
	f(YELLOW_GREEN, YellowGreen)

#define XL_COLOR_FIRST XL_COLOR_ALICE_BLUE
#define XL_COLOR_LAST XL_COLOR_YELLOW_GREEN
#define XL_COLORS_COUNT (XL_COLOR_LAST - XL_COLOR_FIRST + 1)

#define xlPointsForEach(f) \
	f(DEFAULT, Default) \
	f(NEG_DEFAULT, NegDefault) \
	f(ZERO, Zero) \
	f(HALF, Half) \
	f(NEG_HALF, NegHalf) \
	f(ONE, One) \
	f(NEG_ONE, NegOne) \
	f(DOUBLE, Double) \
	f(NEG_DOUBLE, NegDouble) \
	f(X, X) \
	f(NEG_X, NegX) \
	f(Y, Y) \
	f(NEG_Y, NegY) \
	f(Z, Z) \
	f(NEG_Z, NegZ) \
	f(TMP, TMP) \
	f(TMP1, TMP1) \
	f(TMP2, TMP2) \
	f(TMP3, TMP3) \
	f(TMP4, TMP4) \
	f(CENTER, Center) \
	f(FRONT, Front) \
	f(BACK, Back) \
	f(RIGHT, Right) \
	f(LEFT, Left) \
	f(UP, Up) \
	f(DOWN, Down) \
	f(FRONT_RIGHT, FrontRight) \
	f(FRONT_LEFT, FrontLeft) \
	f(FRONT_UP, FrontUp) \
	f(FRONT_DOWN, FrontDown) \
	f(BACK_RIGHT, BackRight) \
	f(BACK_LEFT, BackLeft) \
	f(BACK_UP, BackUp) \
	f(BACK_DOWN, BackDown) \
	f(RIGHT_UP, RightUp) \
	f(RIGHT_DOWN, RightDown) \
	f(LEFT_UP, LeftUp) \
	f(LEFT_DOWN, LeftDown) \
	f(FRONT_RIGHT_UP, FrontRightUp) \
	f(FRONT_RIGHT_DOWN, FrontRightDown) \
	f(FRONT_LEFT_UP, FrontLeftUp) \
	f(FRONT_LEFT_DOWN, FrontLeftDown) \
	f(BACK_RIGHT_UP, BackRightUp) \
	f(BACK_RIGHT_DOWN, BackRightDown) \
	f(BACK_LEFT_UP, BackLeftUp) \
	f(BACK_LEFT_DOWN, BackLeftDown) \
	f(ORIGIN, Origin) \
	f(NORTH, North) \
	f(SOUTH, South) \
	f(EAST, East) \
	f(WEST, West) \
	f(SKY, Sky) \
	f(GROUND, Ground) \
	f(NORTH_EAST, NorthEast) \
	f(NORTH_WEST, NorthWest) \
	f(NORTH_SKY, NorthSky) \
	f(NORTH_GROUND, NorthGround) \
	f(SOUTH_EAST, SouthEast) \
	f(SOUTH_WEST, SouthWest) \
	f(SOUTH_SKY, SouthSky) \
	f(SOUTH_GROUND, SouthGround) \
	f(EAST_SKY, EastSky) \
	f(EAST_GROUND, EastGround) \
	f(WEST_SKY, WestSky) \
	f(WEST_GROUND, WestGround) \
	f(NORTH_EAST_SKY, NorthEastSky) \
	f(NORTH_EAST_GROUND, NorthEastGround) \
	f(NORTH_WEST_SKY, NorthWestSky) \
	f(NORTH_WEST_GROUND, NorthWestGround) \
	f(SOUTH_EAST_SKY, SouthEastSky) \
	f(SOUTH_EAST_GROUND, SouthEastGround) \
	f(SOUTH_WEST_SKY, SouthWestSky) \
	f(SOUTH_WEST_GROUND, SouthWestGround)

#define XL_POINT_DIRECTION_FIRST XL_POINT_CENTER
#define XL_POINT_DIRECTION_LAST XL_POINT_BACK_LEFT_DOWN
#define XL_POINTS_DIRECTION_COUNT (XL_POINT_DIRECTION_LAST - XL_POINT_DIRECTION_FIRST + 1)

#define XL_POINT_ORIENTATION_FIRST XL_POINT_ORIGIN
#define XL_POINT_ORIENTATION_LAST XL_POINT_SOUTH_WEST_GROUND
#define XL_POINTS_ORIENTATION_COUNT (XL_POINT_ORIENTATION_LAST - XL_POINT_ORIENTATION_FIRST + 1)

#define xlVectorsForEach(f) \
	f(DEFAULT, Default) \
	f(NEG_DEFAULT, NegDefault) \
	f(ZERO, Zero) \
	f(HALF, Half) \
	f(NEG_HALF, NegHalf) \
	f(ONE, One) \
	f(NEG_ONE, NegOne) \
	f(DOUBLE, Double) \
	f(NEG_DOUBLE, NegDouble) \
	f(X, X) \
	f(NEG_X, NegX) \
	f(Y, Y) \
	f(NEG_Y, NegY) \
	f(Z, Z) \
	f(NEG_Z, NegZ) \
	f(TMP, TMP) \
	f(TMP1, TMP1) \
	f(TMP2, TMP2) \
	f(TMP3, TMP3) \
	f(TMP4, TMP4) \
	f(FRONT, Front) \
	f(BACK, Back) \
	f(RIGHT, Right) \
	f(LEFT, Left) \
	f(UP, Up) \
	f(DOWN, Down) \
	f(FRONT_RIGHT, FrontRight) \
	f(FRONT_LEFT, FrontLeft) \
	f(FRONT_UP, FrontUp) \
	f(FRONT_DOWN, FrontDown) \
	f(BACK_RIGHT, BackRight) \
	f(BACK_LEFT, BackLeft) \
	f(BACK_UP, BackUp) \
	f(BACK_DOWN, BackDown) \
	f(RIGHT_UP, RightUp) \
	f(RIGHT_DOWN, RightDown) \
	f(LEFT_UP, LeftUp) \
	f(LEFT_DOWN, LeftDown) \
	f(FRONT_RIGHT_UP, FrontRightUp) \
	f(FRONT_RIGHT_DOWN, FrontRightDown) \
	f(FRONT_LEFT_UP, FrontLeftUp) \
	f(FRONT_LEFT_DOWN, FrontLeftDown) \
	f(BACK_RIGHT_UP, BackRightUp) \
	f(BACK_RIGHT_DOWN, BackRightDown) \
	f(BACK_LEFT_UP, BackLeftUp) \
	f(BACK_LEFT_DOWN, BackLeftDown) \
	f(NORTH, North) \
	f(SOUTH, South) \
	f(EAST, East) \
	f(WEST, West) \
	f(SKY, Sky) \
	f(GROUND, Ground) \
	f(NORTH_EAST, NorthEast) \
	f(NORTH_WEST, NorthWest) \
	f(NORTH_SKY, NorthSky) \
	f(NORTH_GROUND, NorthGround) \
	f(SOUTH_EAST, SouthEast) \
	f(SOUTH_WEST, SouthWest) \
	f(SOUTH_SKY, SouthSky) \
	f(SOUTH_GROUND, SouthGround) \
	f(EAST_SKY, EastSky) \
	f(EAST_GROUND, EastGround) \
	f(WEST_SKY, WestSky) \
	f(WEST_GROUND, WestGround) \
	f(NORTH_EAST_SKY, NorthEastSky) \
	f(NORTH_EAST_GROUND, NorthEastGround) \
	f(NORTH_WEST_SKY, NorthWestSky) \
	f(NORTH_WEST_GROUND, NorthWestGround) \
	f(SOUTH_EAST_SKY, SouthEastSky) \
	f(SOUTH_EAST_GROUND, SouthEastGround) \
	f(SOUTH_WEST_SKY, SouthWestSky) \
	f(SOUTH_WEST_GROUND, SouthWestGround)

#define XL_VECTOR_DIRECTION_FIRST XL_VECTOR_FRONT
#define XL_VECTOR_DIRECTION_LAST XL_VECTOR_BACK_LEFT_DOWN
#define XL_VECTORS_DIRECTION_COUNT (XL_VECTOR_DIRECTION_LAST - XL_VECTOR_DIRECTION_FIRST + 1)

#define XL_VECTOR_ORIENTATION_FIRST XL_VECTOR_NORTH
#define XL_VECTOR_ORIENTATION_LAST XL_VECTOR_SOUTH_WEST_GROUND
#define XL_VECTORS_ORIENTATION_COUNT (XL_VECTOR_ORIENTATION_LAST - XL_VECTOR_ORIENTATION_FIRST + 1)

#define xlMatricesForEach(f) \
	f(DEFAULT, Default) \
	f(NEG_DEFAULT, NegDefault) \
	f(ZERO, Zero) \
	f(HALF, Half) \
	f(NEG_HALF, NegHalf) \
	f(ONE, One) \
	f(NEG_ONE, NegOne) \
	f(DOUBLE, Double) \
	f(NEG_DOUBLE, NegDouble) \
	f(X, X) \
	f(NEG_X, NegX) \
	f(Y, Y) \
	f(NEG_Y, NegY) \
	f(Z, Z) \
	f(NEG_Z, NegZ) \
	f(W, W) \
	f(NEG_W, NegW) \
	f(HALF_IDENTITY, HalfIdentity) \
	f(NEG_HALF_IDENTITY, NegHalfIdentity) \
	f(IDENTITY, Identity) \
	f(NEG_IDENTITY, NegIdentity) \
	f(DOUBLE_IDENTITY, DoubleIdentity) \
	f(NEG_DOUBLE_IDENTITY, NegDoubleIdentity) \
	f(TMP, TMP) \
	f(TMP1, TMP1) \
	f(TMP2, TMP2) \
	f(TMP3, TMP3) \
	f(TMP4, TMP4)

#define xlTexCoord2(p) glTexCoord2fv(XL_PAIR_ARRAY(p))
#define xlTexCoord xlTexCoord2
#define xlColor3(c) glColor3fv(XL_COLOR_ARRAY(c));
#define xlColor4(c) glColor4fv(XL_COLOR_ARRAY(c));
#define xlColor xlColor4
#define xlMaterialc(f, p, c) glMaterialfv(f, p, XL_COLOR_ARRAY(c));
#define xlVertex2(p) glVertex2fv(XL_POINT_ARRAY(p))
#define xlVertex3(p) glVertex3fv(XL_POINT_ARRAY(p))
#define xlVertex xlVertex3
#define xlNormal3(v) glNormal3fv(XL_VECTOR_ARRAY(v))
#define xlNormal xlNormal3
#define xlTranslate(v) glTranslatef(XL_VECTOR_X(v), XL_VECTOR_Y(v), XL_VECTOR_Z(v))
#define xlScale(v) glScalef(XL_VECTOR_X(v), XL_VECTOR_Y(v), XL_VECTOR_Z(v))
#define xlRotate(a, v) glRotatef(a, XL_VECTOR_X(v), XL_VECTOR_Y(v), XL_VECTOR_Z(v))
#define xlMultMatrix(m) glMultMatrixf(XL_MATRIX_ARRAY(m))

#define xlImgS(t) sizeof(XLImage ## t)
#define xlFntS(t) sizeof(XLFont ## t)
#define xlMatS(t) sizeof(XLMaterial ## t)
#define xlSurfS(t) sizeof(XLSurface ## t)
#define xlObjS(t) sizeof(XLObject ## t)
#define xlModS(t) sizeof(XLModel ## t)
#define xlPartsS(t) sizeof(XLParticles ## t)
#define xlOpS(t) sizeof(XLOperator ## t)
#define xlCamS(t) sizeof(XLCamera ## t)
#define xlViewS(t) sizeof(XLViewport ## t)
#define xlWinS(t) sizeof(XLWindow ## t)

#define xlIdForEach(f) \
	f(Img, image, Image, Images, IMAGE) \
	f(Fnt, font, Font, Fonts, FONT) \
	f(Mat, material, Material, Materials, MATERIAL) \
	f(Surf, surface, Surface, Surfaces, SURFACE) \
	f(Obj, object, Object, Objects, OBJECT) \
	f(Mod, model, Model, Models, MODEL) \
	f(Parts, particles, Particles, Particles, PARTICLES) \
	f(Cam, camera, Camera, Cameras, CAMERA) \
	f(Op, operator, Operator, Operators, OPERATOR) \
	f(Vpt, viewport, Viewport, Viewports, VIEWPORT) \
	f(Win, window, Window, Windows, WINDOW) \

#define XL_BOOLEAN_FORMAT L"%ls"
#define XL_BOOLEAN_PARAMS(b) ((b) ? L"True" : L"False")

#define XL_INTEGER_FORMAT L"%i"
#define XL_INTEGER_PARAMS(i) i

#define XL_STRING_FORMAT L"%ls"
#define XL_STRING_PARAMS(s) s

#define XL_PATH_FORMAT L"%s"
#define XL_PATH_PARAMS(s) s

#define XL_REAL_FORMAT L"%f"
#define XL_REAL_PARAMS(r) r

#define XL_PAIR_FORMAT \
	L"( " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" )"
#define XL_PAIR_PARAMS(v) \
	XL_REAL_PARAMS(XL_PAIR_X(v)), XL_REAL_PARAMS(XL_PAIR_Y(v))

#define XL_COLOR_FORMAT \
	L"( " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" )"
#define XL_COLOR_PARAMS(v) \
	XL_REAL_PARAMS(XL_COLOR_R(v)), XL_REAL_PARAMS(XL_COLOR_G(v)), XL_REAL_PARAMS(XL_COLOR_B(v)), XL_REAL_PARAMS(XL_COLOR_A(v))

#define XL_POINT_FORMAT \
	L"( " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" )"
#define XL_POINT_PARAMS(v) \
	XL_REAL_PARAMS(XL_POINT_X(v)), XL_REAL_PARAMS(XL_POINT_Y(v)), XL_REAL_PARAMS(XL_POINT_Z(v))

#define XL_VECTOR_FORMAT \
	L"( " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" )"
#define XL_VECTOR_PARAMS(v) \
	XL_REAL_PARAMS(XL_VECTOR_X(v)), XL_REAL_PARAMS(XL_VECTOR_Y(v)), XL_REAL_PARAMS(XL_VECTOR_Z(v))

#define XL_MATRIX_FORMAT \
	L"| " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" |\n" \
	L"| " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" |\n" \
	L"| " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" |\n" \
	L"| " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" " XL_REAL_FORMAT L" |"
#define XL_MATRIX_PARAMS(m) \
	XL_REAL_PARAMS(XL_MATRIX_XX(m)), XL_REAL_PARAMS(XL_MATRIX_YX(m)), XL_REAL_PARAMS(XL_MATRIX_ZX(m)), XL_REAL_PARAMS(XL_MATRIX_WX(m)), \
	XL_REAL_PARAMS(XL_MATRIX_XY(m)), XL_REAL_PARAMS(XL_MATRIX_YY(m)), XL_REAL_PARAMS(XL_MATRIX_ZY(m)), XL_REAL_PARAMS(XL_MATRIX_WY(m)), \
	XL_REAL_PARAMS(XL_MATRIX_XZ(m)), XL_REAL_PARAMS(XL_MATRIX_YZ(m)), XL_REAL_PARAMS(XL_MATRIX_ZZ(m)), XL_REAL_PARAMS(XL_MATRIX_WZ(m)), \
	XL_REAL_PARAMS(XL_MATRIX_XW(m)), XL_REAL_PARAMS(XL_MATRIX_YW(m)), XL_REAL_PARAMS(XL_MATRIX_ZW(m)), XL_REAL_PARAMS(XL_MATRIX_WW(m))

#define XL_ERROR_FORMAT \
	L"XL error:" XL_PATH_FORMAT L":" XL_PATH_FORMAT L":" XL_INTEGER_FORMAT L":" XL_INTEGER_FORMAT L":" XL_STRING_FORMAT
#define XL_ERROR_PARAMS(e) \
	(e)->file, (e)-function, (e)->line, (e)->value, xlGetString((e)->value)

#define XL_METAHEADER_FORMAT \
	XL_PATH_FORMAT L": path: " XL_PATH_FORMAT L"\n" \
	XL_PATH_FORMAT L": type: " XL_STRING_FORMAT L"\n"
#define XL_METAHEADER_PARAMS \
	xlGetPath(XL_METAHEADER_PATH), xlGetPath(XL_METAHEADER_PATH), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METAHEADER_TYPE)

#define XL_METADATA_FORMAT \
	XL_PATH_FORMAT L": name: " XL_STRING_FORMAT L"\n" \
	XL_PATH_FORMAT L": version: " XL_STRING_FORMAT L"\n" \
	XL_PATH_FORMAT L": author: " XL_STRING_FORMAT L"\n" \
	XL_PATH_FORMAT L": date: " XL_STRING_FORMAT L"\n" \
	XL_PATH_FORMAT L": copyright: " XL_STRING_FORMAT L"\n" \
	XL_PATH_FORMAT L": license: " XL_STRING_FORMAT L"\n" \
	XL_PATH_FORMAT L": url: " XL_STRING_FORMAT L"\n" \
	XL_PATH_FORMAT L": email: " XL_STRING_FORMAT L"\n" \
	XL_PATH_FORMAT L": tool: " XL_STRING_FORMAT L"\n" \
	XL_PATH_FORMAT L": comment: " XL_STRING_FORMAT L"\n" \
	XL_PATH_FORMAT L": xl: " XL_STRING_FORMAT L"\n" 
#define XL_METADATA_PARAMS \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_NAME), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_VERSION), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_AUTHOR), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_DATE), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_COPYRIGHT), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_LICENSE), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_URL), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_EMAIL), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_TOOL), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_COMMENT), \
	xlGetPath(XL_METAHEADER_PATH), xlGetString(XL_METADATA_XL)

#define XL_META_FORMAT \
	XL_METAHEADER_FORMAT \
	XL_METADATA_FORMAT
#define XL_META_PARAMS \
	XL_METAHEADER_PARAMS, \
	XL_METADATA_PARAMS

#define XL_IMAGE_FORMAT \
	XL_PATH_FORMAT L": width: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": height: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": bpp: " XL_INTEGER_FORMAT L"\n"
#define XL_IMAGE_PARAMS \
	xlGetPath(XL_IMAGE_METAHEADER_PATH), xlGetInteger(XL_IMAGE_WIDTH), \
	xlGetPath(XL_IMAGE_METAHEADER_PATH), xlGetInteger(XL_IMAGE_HEIGHT), \
	xlGetPath(XL_IMAGE_METAHEADER_PATH), xlGetInteger(XL_IMAGE_BYTES_PER_PIXEL)

#define XL_FONT_FORMAT \
	XL_PATH_FORMAT L": properties: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": path: " XL_PATH_FORMAT L"\n"
#define XL_FONT_PARAMS \
	xlGetPath(XL_FONT_METAHEADER_PATH), xlGetInteger(XL_FONT_PROPERTIES), \
	xlGetPath(XL_FONT_METAHEADER_PATH), xlGetPath(XL_FONT_PATH)

#define XL_MATERIAL_FORMAT \
	XL_PATH_FORMAT L": properties: " XL_INTEGER_FORMAT L"\n"
#define XL_MATERIAL_PARAMS \
	xlGetPath(XL_MATERIAL_METAHEADER_PATH), xlGetInteger(XL_MATERIAL_PROPERTIES)

#define XL_SURFACE_FORMAT \
	XL_PATH_FORMAT L": material\n" \
	XL_PATH_FORMAT L": frames: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": actions: " XL_INTEGER_FORMAT L"\n"
#define XL_SURFACE_PARAMS \
	xlGetPath(XL_SURFACE_METAHEADER_PATH), \
	xlGetPath(XL_SURFACE_METAHEADER_PATH), xlGetInteger(XL_SURFACE_FRAMES), \
	xlGetPath(XL_SURFACE_METAHEADER_PATH), xlGetInteger(XL_SURFACE_ACTIONS)

#define XL_OBJECT_FORMAT \
	XL_PATH_FORMAT L": vertices: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": materials: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": faces: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": tags: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": bound\n"
#define XL_OBJECT_PARAMS \
	xlGetPath(XL_OBJECT_METAHEADER_PATH), xlGetInteger(XL_OBJECT_VERTICES), \
	xlGetPath(XL_OBJECT_METAHEADER_PATH), xlGetInteger(XL_OBJECT_MATERIALS), \
	xlGetPath(XL_OBJECT_METAHEADER_PATH), xlGetInteger(XL_OBJECT_FACES), \
	xlGetPath(XL_OBJECT_METAHEADER_PATH), xlGetInteger(XL_OBJECT_TAGS), \
	xlGetPath(XL_OBJECT_METAHEADER_PATH)

#define XL_MODEL_FORMAT \
	XL_PATH_FORMAT L": object\n" \
	XL_PATH_FORMAT L": bones: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": parents: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": vertices: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": tags: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": weights: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": frames: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": actions: " XL_INTEGER_FORMAT L"\n"
#define XL_MODEL_PARAMS \
	xlGetPath(XL_MODEL_METAHEADER_PATH), \
	xlGetPath(XL_MODEL_METAHEADER_PATH), xlGetInteger(XL_MODEL_BONES), \
	xlGetPath(XL_MODEL_METAHEADER_PATH), xlGetInteger(XL_MODEL_PARENTS), \
	xlGetPath(XL_MODEL_METAHEADER_PATH), xlGetInteger(XL_MODEL_VERTICES), \
	xlGetPath(XL_MODEL_METAHEADER_PATH), xlGetInteger(XL_MODEL_TAGS), \
	xlGetPath(XL_MODEL_METAHEADER_PATH), xlGetInteger(XL_MODEL_WEIGHTS), \
	xlGetPath(XL_MODEL_METAHEADER_PATH), xlGetInteger(XL_MODEL_FRAMES), \
	xlGetPath(XL_MODEL_METAHEADER_PATH), xlGetInteger(XL_MODEL_ACTIONS)

#define XL_PARTICLES_FORMAT \
	XL_PATH_FORMAT L": particles\n"
#define XL_PARTICLES_PARAMS \
	xlGetPath(XL_PARTICLES_METAHEADER_PATH)

#define XL_CAMERA_FORMAT \
	XL_PATH_FORMAT L": properties: " XL_INTEGER_FORMAT L"\n"
#define XL_CAMERA_PARAMS \
	xlGetPath(XL_CAMERA_METAHEADER_PATH), xlGetInteger(XL_CAMERA_PROPERTIES)

#define XL_OPERATOR_FORMAT \
	XL_PATH_FORMAT L": camera\n" \
	XL_PATH_FORMAT L": frames: " XL_INTEGER_FORMAT L"\n" \
	XL_PATH_FORMAT L": actions: " XL_INTEGER_FORMAT L"\n"
#define XL_OPERATOR_PARAMS \
	xlGetPath(XL_OPERATOR_METAHEADER_PATH), \
	xlGetPath(XL_OPERATOR_METAHEADER_PATH), xlGetInteger(XL_OPERATOR_FRAMES), \
	xlGetPath(XL_OPERATOR_METAHEADER_PATH), xlGetInteger(XL_OPERATOR_ACTIONS)

#define XL_VIEWPORT_FORMAT \
	XL_PATH_FORMAT L": properties: " XL_INTEGER_FORMAT L"\n"
#define XL_VIEWPORT_PARAMS \
	xlGetPath(XL_VIEWPORT_METAHEADER_PATH), xlGetInteger(XL_VIEWPORT_PROPERTIES)

#define XL_WINDOW_FORMAT \
	XL_PATH_FORMAT L": properties: " XL_INTEGER_FORMAT L"\n"
#define XL_WINDOW_PARAMS \
	xlGetPath(XL_WINDOW_METAHEADER_PATH), xlGetInteger(XL_WINDOW_PROPERTIES)

#define XL_FORMAT \
	L"**  ** **  \n" \
	L" ****  **  \n" \
	L"**  ** ****\n"
#define XL_PARAMS

#define XL_INFO_FORMAT \
	L"XL Vendor: " XL_STRING_FORMAT L"\n" \
	L"XL Renderer: " XL_STRING_FORMAT L"\n" \
	L"XL Version: " XL_STRING_FORMAT L"\n"
#define XL_INFO_PARAMS \
	xlGetString(XL_VENDOR), \
	xlGetString(XL_RENDERER), \
	xlGetString(XL_VERSION)

#define XL_CREDITS_FORMAT \
	XL_STRING_FORMAT
#define XL_CREDITS_PARAMS \
	L"**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  \n" \
	L" ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  \n" \
	L"**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****\n" \
	L"                                                                                \n" \
        L"                   Open X Library: Multiple Purpose C Open Engine               \n" \
	L"                                                                                \n" \
	L"                                  **  ** **                                     \n" \
	L"                                   ****  **                                     \n" \
	L"                                  **  ** ****                                   \n" \
	L"                                                                                \n" \
	L"                   Licensed GPLv3 by Juan Manuel Borges Caño                    \n" \
	L"                  * Homepage <http://code.google.com/p/openxl>                  \n" \
	L"                     * Mail <mailto:juanmabcmail@gmail.com>                     \n" \
	L"                   * Blog <http://juanmabcblog.blogspot.com>                    \n" \
	L"               Copyright (C) 2012 - 2014 Juan Manuel Borges Caño                \n" \
	L"                                                                                \n" \
	L"**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  \n" \
	L" ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  \n" \
	L"**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****\n"
#define XL_BANNER_FORMAT \
	XL_CREDITS_FORMAT \
	L"                                                                                \n" \
	L"**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  \n" \
	L" ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  \n" \
	L"**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****\n" \
	L"                                                                                \n" \
	L"                                  **  ** **                                     \n" \
	L"                                   ****  **                                     \n" \
	L"                                  **  ** ****                                   \n" \
	L"                                                                                \n" \
	L"		       XL Vendor: " XL_STRING_FORMAT L"\n" \
	L"		  XL Renderer: " XL_STRING_FORMAT L"\n" \
	L"			     XL Version: " XL_STRING_FORMAT L"\n" \
	L"                                                                                \n" \
	L"**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  \n" \
	L" ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  \n" \
	L"**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****\n" \
	L"                                                                                \n"
#define XL_BANNER_PARAMS \
	XL_CREDITS_PARAMS, \
	XL_INFO_PARAMS

#define xlLogBoolean(b) xlLog(XL_BOOLEAN_FORMAT L"\n", XL_BOOLEAN_PARAMS(b))
#define xlLogInteger(i) xlLog(XL_INTEGER_FORMAT L"\n", XL_INTEGER_PARAMS(i))
#define xlLogString(s) xlLog(XL_STRING_FORMAT L"\n", XL_STRING_PARAMS(s))
#define xlLogPath(p) xlLog(XL_PATH_FORMAT L"\n", XL_PATH_PARAMS(p))
#define xlLogReal(r) xlLog(XL_REAL_FORMAT L"\n", XL_REAL_PARAMS(r))
#define xlLogPair(v) xlLog(XL_PAIR_FORMAT L"\n", XL_PAIR_PARAMS(v))
#define xlPairLog(v) xlLog(XL_PAIR_FORMAT L"\n", XL_PAIR_PARAMS(v))
#define xlLogColor(v) xlLog(XL_COLOR_FORMAT L"\n", XL_COLOR_PARAMS(v))
#define xlColorLog(v) xlLog(XL_COLOR_FORMAT L"\n", XL_COLOR_PARAMS(v))
#define xlLogPoint(v) xlLog(XL_POINT_FORMAT L"\n", XL_POINT_PARAMS(v))
#define xlPointLog(v) xlLog(XL_POINT_FORMAT L"\n", XL_POINT_PARAMS(v))
#define xlLogVector(v) xlLog(XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(v))
#define xlVectorLog(v) xlLog(XL_VECTOR_FORMAT L"\n", XL_VECTOR_PARAMS(v))
#define xlLogMatrix(m) xlLog(XL_MATRIX_FORMAT L"\n", XL_MATRIX_PARAMS(m))
#define xlMatrixLog(m) xlLog(XL_MATRIX_FORMAT L"\n", XL_MATRIX_PARAMS(m))

#define xlErrorLog(e) xlLog(XL_ERROR_FORMAT L"\n", XL_ERROR_PARAMS(e))
#define xlLogError(e) xlLog(XL_ERROR_FORMAT L"\n", XL_ERROR_PARAMS(e))

#define xlLogMeta(mh, md) \
	xlLog( \
		XL_METAHEADER_FORMAT \
		XL_METADATA_FORMAT, \
		(mh)->path, (mh)->path, \
		(mh)->path, xlGetString((mh)->magic), \
		(mh)->path, (md)->name, \
		(mh)->path, (md)->version, \
		(mh)->path, (md)->author, \
		(mh)->path, (md)->date, \
		(mh)->path, (md)->copyright, \
		(mh)->path, (md)->license, \
		(mh)->path, (md)->url, \
		(mh)->path, (md)->email, \
		(mh)->path, (md)->tool, \
		(mh)->path, (md)->comment, \
		(mh)->path, (md)->xl \
	)
#define xlLogBind(b) xlLog(b ## _FORMAT, b ## _PARAMS)

#define xlLogXL() xlLog(XL_FORMAT, XL_PARAMS)
#define xlLogInfo() xlLog(XL_INFO_FORMAT, XL_INFO_PARAMS)
#define xlLogCredits() xlLog(XL_CREDITS_FORMAT, XL_CREDITS_PARAMS)
#define xlLogBanner() xlLog(XL_BANNER_FORMAT, XL_BANNER_PARAMS)

#define XL_STORE_SIZE 1024

#endif
