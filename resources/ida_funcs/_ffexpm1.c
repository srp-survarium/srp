// positive sp value has been detected, the output may be wrong!
double __usercall _ffexpm1@<st0>(char a1@<ch>, int _EBP@<ebp>)
{
  double result; // st7

  __asm
  {
    fld     st
    fabs
    fld     _log2max
    fcompp
    fstsw   word ptr [ebp-0A0h]
  }
  if ( (*(_BYTE *)(_EBP - 159) & 0x41) != 0 )
  {
    __asm
    {
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    if ( (*(_BYTE *)(_EBP - 159) & 1) != 0 )
    {
      *(_BYTE *)(_EBP - 144) = 4;
      return _rtzeronpop();
    }
    else
    {
      __asm
      {
        fstp    st
        fld     __infinity
      }
      if ( a1 )
        __asm { fchs }
    }
  }
  else
  {
    __asm
    {
      fld     st
      frndint
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    __asm
    {
      fxch    st(1)
      fsub    st, st(1)
      ftst
      fstsw   word ptr [ebp-0A0h]
      fabs
      f2xm1
    }
  }
  return result;
}
