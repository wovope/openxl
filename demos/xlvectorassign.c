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
  XLvector *va, *vb, *vc;

#ifndef XL_DEBUG
	xlSetLogLevel(XL_LOG_LEVEL_STDOUT);
#endif

  xlLog(L"%s\n", "0 =");
  xlVectorLog(xlVectorZero);
  xlLog(L"\n");

  xlLog(L"%s\n", "0.5 =");
  xlVectorLog(xlVectorHalf);
  xlLog(L"\n");

  xlLog(L"%s\n", "-0.5 =");
  xlVectorLog(xlVectorNegHalf);
  xlLog(L"\n");

  xlLog(L"%s\n", "1 =");
  xlVectorLog(xlVectorOne);
  xlLog(L"\n");

  xlLog(L"%s\n", "-1 =");
  xlVectorLog(xlVectorNegOne);
  xlLog(L"\n");

  xlLog(L"%s\n", "2 =");
  xlVectorLog(xlVectorDouble);
  xlLog(L"\n");

  xlLog(L"%s\n", "-2 =");
  xlVectorLog(xlVectorNegDouble);
  xlLog(L"\n");

  xlLog(L"%s\n", "X =");
  xlVectorLog(xlVectorX);
  xlLog(L"\n");

  xlLog(L"%s\n", "-X =");
  xlVectorLog(xlVectorNegX);
  xlLog(L"\n");

  xlLog(L"%s\n", "Y =");
  xlVectorLog(xlVectorY);
  xlLog(L"\n");

  xlLog(L"%s\n", "-Y =");
  xlVectorLog(xlVectorNegY);
  xlLog(L"\n");

  xlLog(L"%s\n", "Z =");
  xlVectorLog(xlVectorZ);
  xlLog(L"\n");

  xlLog(L"%s\n", "-Z =");
  xlVectorLog(xlVectorNegZ);
  xlLog(L"\n");

  xlLog(L"\n");

  va = xlVectorAlloc();
  xlVectorAssignReals(va, XL_REAL(-1.1), XL_REAL(2.2), XL_REAL(3.3));

  vb = xlVectorAlloc();
  xlVectorAssignReals(vb, XL_REAL(3.3), XL_REAL(2.2), XL_REAL(-1.1));

  vc = xlVectorCopy(xlVectorZero);

  xlVectorLog(vc);
  xlLog(L" %s\n", "assign");
  xlVectorLog(va);
  xlLog(L" %s\n", "=");
  xlVectorAssignArray(vc, XL_VECTOR_ARRAY(va));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "swizzle(2,0,1)=");
  vc = xlVectorAssignSwizzle(vc, va, 2, 0, 1);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "clear=");
  vc = xlVectorClear(xlVectorAssignCopy(vc, va));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "zero=");
  vc = xlVectorAssignZero(xlVectorAssignCopy(vc, va));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "copy=");
  vc = xlVectorAssignCopy(vc, va);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

#if 0
  xlLog(L"%s\n", "~");
  xlVectorLog(va);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignComp(vc, va);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");
#endif

  xlLog(L"%s\n", "-");
  xlVectorLog(va);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignNeg(vc, va);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlLog(L"%s\n", "++");
  xlVectorLog(va);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignInc(vc, va);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlLog(L"%s\n", "--");
  xlVectorLog(va);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignDec(vc, va);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "abs=");
  vc = xlVectorAssignAbs(vc, va);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "norm=");
  xlLogReal(xlVectorNorm(va));
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "normal=");
  vc = xlVectorAssignNormal(vc, va);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "booleanEqual");
  xlVectorLog(va);
  xlLog(L" %s", "=");
  xlLogBoolean(xlVectorBooleanEqual(va, va));
  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "booleanEqual");
  xlVectorLog(vb);
  xlLog(L" %s", "=");
  xlLogBoolean(xlVectorBooleanEqual(va, vb));
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "vectorEqual");
  xlVectorLog(va);
  xlLog(L" %s\n", "=");
  vc = xlVectorVectorAssignEqual(vc, va, va);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "vectorEqual");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorVectorAssignEqual(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "angle");
  xlVectorLog(vb);
  xlLog(L" %s", "=");
  xlLogReal(xlVectorAngle(va, vb));
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "dot");
  xlVectorLog(vb);
  xlLog(L" %s", "=");
  xlLogReal(xlVectorDot(va, vb));
  xlLog(L"\n");

  xlLog(L"\n");

#if 0
  xlVectorLog(va);
  xlLog(L" %s", "&");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignAndReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "&");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignAndReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "|");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignOr(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "|");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignOrReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "^");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignXor(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "^");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignXorReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "<<");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignLshift(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "<<");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignLshiftReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", ">>");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignRshift(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", ">>");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignRshift(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");
#endif

  xlVectorLog(va);
  xlLog(L" %s", "+");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignAddReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "+");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignAdd(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "-");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignSubReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "-");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignSub(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "*");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignMultReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "*");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignMult(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "/");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignDivReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "/");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignDiv(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

#if 0
  xlVectorLog(va);
  xlLog(L" %s", "%");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignModReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "%");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignMod(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");
#endif

  xlVectorLog(va);
  xlLog(L" %s", "invdiv");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignInvDivReal(vc, va, XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "invdiv");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignInvDiv(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "cross");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignCross(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "min");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignMin(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "max");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignMax(vc, va, vb);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "rotate(180)");
  xlVectorLog(xlVectorY);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignRotate(vc, va, xlVectorY, 180);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "lerp(0.5)");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAssignLerp(vc, va, vb, 0.5);
  xlVectorLog(vc);
  xlLog(L"\n");

  xlLog(L"\n");

#if 0
  int i;
  for(i = 0; i < 10000000; i++)
  {
    xlVectorAssignCross(vc, va, vc);
  }
#endif

  xlFree(vc);
  xlFree(vb);
  xlFree(va);

  return EXIT_SUCCESS;
}
