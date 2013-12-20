/*

                                  **  ** **  
                                   ****  **  
                                  **  ** ****

               Copyright (C) 2012, 2013 Juan Manuel Borges Caño

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.

**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  
 ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  
**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****

*/

#include <XL/xl.h>

int
main(int argc, char *argv[])
{
  XLmatrix *va, *vb, *vc;

#ifndef XL_DEBUG
	xlSetLogLevel(XL_LOG_LEVEL_STDOUT);
#endif

  xlLog(L"%s\n", "0 =");
  xlMatrixLog(xlMatrixZero);
  xlLog(L"\n");

  xlLog(L"%s\n", "0.5 =");
  xlMatrixLog(xlMatrixHalf);
  xlLog(L"\n");

  xlLog(L"%s\n", "-0.5 =");
  xlMatrixLog(xlMatrixNegHalf);
  xlLog(L"\n");

  xlLog(L"%s\n", "1 =");
  xlMatrixLog(xlMatrixOne);
  xlLog(L"\n");

  xlLog(L"%s\n", "-1 =");
  xlMatrixLog(xlMatrixNegOne);
  xlLog(L"\n");

  xlLog(L"%s\n", "2 =");
  xlMatrixLog(xlMatrixDouble);
  xlLog(L"\n");

  xlLog(L"%s\n", "-2 =");
  xlMatrixLog(xlMatrixNegDouble);
  xlLog(L"\n");

  xlLog(L"%s\n", "X =");
  xlMatrixLog(xlMatrixX);
  xlLog(L"\n");

  xlLog(L"%s\n", "-X =");
  xlMatrixLog(xlMatrixNegX);
  xlLog(L"\n");

  xlLog(L"%s\n", "Y =");
  xlMatrixLog(xlMatrixY);
  xlLog(L"\n");

  xlLog(L"%s\n", "-Y =");
  xlMatrixLog(xlMatrixNegY);
  xlLog(L"\n");

  xlLog(L"%s\n", "Z =");
  xlMatrixLog(xlMatrixZ);
  xlLog(L"\n");

  xlLog(L"%s\n", "-Z =");
  xlMatrixLog(xlMatrixNegZ);
  xlLog(L"\n");

  xlLog(L"%s\n", "W =");
  xlMatrixLog(xlMatrixW);
  xlLog(L"\n");

  xlLog(L"%s\n", "-W =");
  xlMatrixLog(xlMatrixNegW);
  xlLog(L"\n");

  xlLog(L"%s\n", "I =");
  xlMatrixLog(xlMatrixIdentity);
  xlLog(L"\n");

  xlLog(L"%s\n", "-I =");
  xlMatrixLog(xlMatrixNegIdentity);
  xlLog(L"\n");

  xlLog(L"%s\n", "0.5I =");
  xlMatrixLog(xlMatrixHalfIdentity);
  xlLog(L"\n");

  xlLog(L"%s\n", "-0.5I =");
  xlMatrixLog(xlMatrixNegHalfIdentity);
  xlLog(L"\n");

  xlLog(L"%s\n", "2I =");
  xlMatrixLog(xlMatrixDoubleIdentity);
  xlLog(L"\n");

  xlLog(L"%s\n", "-2I =");
  xlMatrixLog(xlMatrixNegDoubleIdentity);
  xlLog(L"\n");

  xlLog(L"\n");

  va = xlMatrixAlloc();
  xlMatrixAssignReals(va, XL_REAL(-1.1), XL_REAL(2.2), XL_REAL(-3.3), XL_REAL(4.4), XL_REAL(-5.5), XL_REAL(6.6), XL_REAL(-7.7), XL_REAL(8.8), XL_REAL(-9.9), XL_REAL(10.10), XL_REAL(-11.11), XL_REAL(12.12), XL_REAL(-13.13), XL_REAL(14.14), XL_REAL(-15.15), XL_REAL(16.16));

  vb = xlMatrixAlloc();
  xlMatrixAssignReals(vb, XL_REAL(-16.16), XL_REAL(15.15), XL_REAL(-14.14), XL_REAL(13.13), XL_REAL(-12.12), XL_REAL(11.11), XL_REAL(-10.10), XL_REAL(9.9), XL_REAL(-8.8), XL_REAL(7.7), XL_REAL(-6.6), XL_REAL(5.5), XL_REAL(-4.4), XL_REAL(3.3), XL_REAL(-2.2), XL_REAL(1.1));

  vc = xlMatrixCopy(xlMatrixZero);
  xlMatrixLog(vc);
  xlLog(L" %s\n", "assign");
  xlMatrixLog(va);
  xlLog(L" %s\n", "=");
  xlMatrixAssignArray(vc, XL_MATRIX_ARRAY(va));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "swizzle(15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)=");
  vc = xlMatrixSwizzle(xlMatrixCopy(va), 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "swizzle(14,13,12)=");
  xlVectorAssignSwizzleMatrix(xlVectorTMP, va, 14, 13, 12);
  xlVectorLog(xlVectorTMP);
  xlLog(L"\n");

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "clear=");
  vc = xlMatrixClear(xlMatrixCopy(va));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "zero=");
  vc = xlMatrixAssignZero(xlMatrixCopy(va));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "copy=");
  vc = xlMatrixCopy(va);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

#if 0
  xlLog(L"%65s\n", "~");
  xlMatrixLog(va);
  xlLog(L" %s\n", "=");
  vc = xlMatrixComp(xlMatrixCopy(va));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");
#endif

  xlLog(L"%65s\n", "-");
  xlMatrixLog(va);
  xlLog(L" %s\n", "=");
  vc = xlMatrixNeg(xlMatrixCopy(va));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlLog(L"%65s\n", "++");
  xlMatrixLog(va);
  xlLog(L" %s\n", "=");
  vc = xlMatrixInc(xlMatrixCopy(va));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlLog(L"%65s\n", "--");
  xlMatrixLog(va);
  xlLog(L" %s\n", "=");
  vc = xlMatrixDec(xlMatrixCopy(va));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "abs=");
  vc = xlMatrixAbs(xlMatrixCopy(va));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

/*
  xlMatrixLog(va);
  xlLog(L" %s", "norm=");
  xlLogReal(xlMatrixNorm(va));
  xlLog(L"\n");

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "normal=");
  vc = xlMatrixNormal(xlMatrixCopy(va));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");
*/

  xlMatrixLog(va);
  xlLog(L" %s\n", "transpose=");
  vc = xlMatrixTranspose(xlMatrixCopy(va));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "booleanEqual");
  xlMatrixLog(va);
  xlLog(L" %s", "=");
  xlLogBoolean(xlMatrixBooleanEqual(va, va));
  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "booleanEqual");
  xlMatrixLog(vb);
  xlLog(L" %s", "=");
  xlLogBoolean(xlMatrixBooleanEqual(va, vb));
  xlLog(L"\n");

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "matrixEqual");
  xlMatrixLog(va);
  xlLog(L" %s\n", "=");
  vc = xlMatrixMatrixEqual(xlMatrixCopy(va), va);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlMatrixLog(va);
  xlLog(L" %s\n", "matrixEqual");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixMatrixEqual(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

/*
  xlMatrixLog(va);
  xlLog(L" %s\n", "angle");
  xlMatrixLog(vb);
  xlLog(L" %s", "=");
  xlLogReal(xlMatrixAngle(va, vb));
  xlLog(L"\n");

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "dot");
  xlMatrixLog(vb);
  xlLog(L" %s", "=");
  xlLogReal(xlMatrixDot(va, vb));
  xlLog(L"\n");

  xlLog(L"\n");
*/

#if 0
  xlMatrixLog(va);
  xlLog(L" %s", "&");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixAndReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s", "&");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixAndReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "|");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixOr(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s", "|");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixOrReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "^");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixXor(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s", "^");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixXorReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "<<");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixLshift(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s", "<<");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixLshiftReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", ">>");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixRshift(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", ">>");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixRshift(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");
#endif

  xlMatrixLog(va);
  xlLog(L" %s", "+");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixAddReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "+");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixAdd(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s", "-");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixSubReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "-");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixSub(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s", "*");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixMultReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "*");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixMult(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s", "/");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixDivReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

#if 0
  xlMatrixLog(va);
  xlLog(L" %s\n", "/");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixDiv(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s", "%");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixModReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "%");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixMod(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");
#endif

  xlMatrixLog(va);
  xlLog(L" %s", "invdiv");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlMatrixInvDivReal(xlMatrixCopy(va), XL_REAL(3));
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

#if 0
  xlMatrixLog(va);
  xlLog(L" %s\n", "invdiv");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixInvDiv(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");
#endif

/*
  xlMatrixLog(va);
  xlLog(L" %s\n", "cross");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixCross(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");
*/

  xlMatrixLog(va);
  xlLog(L" %s\n", "min");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixMin(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "max");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixMax(xlMatrixCopy(va), vb);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "translate");
  xlPointLog(xlPointX);
  xlLog(L" %s\n", "=");
  vc = xlMatrixTranslate(xlMatrixCopy(va), xlPointX);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "scale");
  xlVectorLog(xlVectorX);
  xlLog(L" %s\n", "=");
  vc = xlMatrixScale(xlMatrixCopy(va), xlVectorX);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "rotate(180)");
  xlVectorLog(xlVectorY);
  xlLog(L" %s\n", "=");
  vc = xlMatrixRotate(xlMatrixCopy(va), xlVectorY, 180);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlMatrixLog(va);
  xlLog(L" %s\n", "lerp(0.5)");
  xlMatrixLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlMatrixLerp(xlMatrixCopy(va), vb, 0.5);
  xlMatrixLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

#if 0
  int i;
  for(i = 0; i < 1000000; i++)
  {
    xlMatrixMult(va, vb);
  }
#endif

  xlFree(vb);
  xlFree(va);

  return EXIT_SUCCESS;
}
