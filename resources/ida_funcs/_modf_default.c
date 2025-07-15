double __cdecl _modf_default(long double x, long double *intptr)
{
  unsigned int v2; // ebx
  __int16 v3; // di
  int v4; // eax
  long double v6; // st7
  int savedregs; // [esp+20h] [ebp+0h] BYREF
  double result; // [esp+28h] [ebp+8h]

  v2 = _ctrlfp();
  _ctrlfp();
  v3 = HIWORD(x);
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    *intptr = _d_ind.dbl;
    v4 = _sptype(x);
    if ( v4 <= 0 )
    {
LABEL_7:
      *intptr = x + 1.0;
      return _except1((int)&savedregs, 8, 28, x, x + 1.0, v2);
    }
    if ( v4 > 2 )
    {
      if ( v4 == 3 )
      {
        *intptr = x;
        return _handle_qnan1(0x1Cu, x, v2);
      }
      goto LABEL_7;
    }
    *intptr = x;
    result = _copysign(0.0, x);
    _ctrlfp();
  }
  else
  {
    v6 = _frnd(x);
    *intptr = v6;
    result = x - v6;
    if ( 0.0 == result )
      HIWORD(result) |= v3 & 0x8000;
    _ctrlfp();
  }
  return result;
}
