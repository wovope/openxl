/*

                                  **  ** **  
                                   ****  **  
                                  **  ** ****

               Copyright (C) 2012 - 2014 Juan Manuel Borges Caño

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
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "swizzle(2,0,1)=");
  vc = xlVectorSwizzle(xlVectorCopy(va), 2, 0, 1);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "clear=");
  vc = xlVectorClear(xlVectorCopy(va));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "zero=");
  vc = xlVectorAssignZero(xlVectorCopy(va));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "copy=");
  vc = xlVectorCopy(va);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

#if 0
  xlLog(L"%s\n", "~");
  xlVectorLog(va);
  xlLog(L" %s\n", "=");
  vc = xlVectorComp(xlVectorCopy(va));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");
#endif

  xlLog(L"%s\n", "-");
  xlVectorLog(va);
  xlLog(L" %s\n", "=");
  vc = xlVectorNeg(xlVectorCopy(va));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlLog(L"%s\n", "++");
  xlVectorLog(va);
  xlLog(L" %s\n", "=");
  vc = xlVectorInc(xlVectorCopy(va));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlLog(L"%s\n", "--");
  xlVectorLog(va);
  xlLog(L" %s\n", "=");
  vc = xlVectorDec(xlVectorCopy(va));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "abs=");
  vc = xlVectorAbs(xlVectorCopy(va));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "norm=");
  xlLogReal(xlVectorNorm(va));
  xlLog(L"\n");

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "normal=");
  vc = xlVectorNormal(xlVectorCopy(va));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

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
  vc = xlVectorVectorEqual(xlVectorCopy(va), va);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlVectorLog(va);
  xlLog(L" %s\n", "vectorEqual");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorVectorEqual(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

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
  vc = xlVectorAndReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "&");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAndReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "|");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorOr(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "|");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorOrReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "^");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorXor(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "^");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorXorReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc); xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "<<");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorLshift(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "<<");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorLshiftReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", ">>");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorRshift(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", ">>");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorRshift(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");
#endif

  xlVectorLog(va);
  xlLog(L" %s", "+");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorAddReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "+");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorAdd(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "-");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorSubReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "-");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorSub(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "*");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorMultReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "*");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorMult(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s", "/");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorDivReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "/");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorDiv(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

#if 0
  xlVectorLog(va);
  xlLog(L" %s", "%");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorModReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "%");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorMod(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");
#endif

  xlVectorLog(va);
  xlLog(L" %s", "invdiv");
  xlLogReal(XL_REAL(3));
  xlLog(L" %s\n", "=");
  vc = xlVectorInvDivReal(xlVectorCopy(va), XL_REAL(3));
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "invdiv");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorInvDiv(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "cross");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorCross(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "min");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorMin(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "max");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorMax(xlVectorCopy(va), vb);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "rotate(180)");
  xlVectorLog(xlVectorY);
  xlLog(L" %s\n", "=");
  vc = xlVectorRotate(xlVectorCopy(va), xlVectorY, 180);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

  xlVectorLog(va);
  xlLog(L" %s\n", "lerp(0.5)");
  xlVectorLog(vb);
  xlLog(L" %s\n", "=");
  vc = xlVectorLerp(xlVectorCopy(va), vb, 0.5);
  xlVectorLog(vc);
  xlLog(L"\n");
  xlFree(vc);

  xlLog(L"\n");

#if 0
  int i;
  for(i = 0; i < 10000000; i++)
  {
    xlVectorCross(va, vb);
  }
#endif

  xlFree(vb);
  xlFree(va);
  return EXIT_SUCCESS;
}
