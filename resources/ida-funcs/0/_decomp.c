long double __cdecl _decomp(long double x, int *pexp)
{
  long double result; // st7
  int v3; // edx
  int v4; // edx
  BOOL v5; // eax
  unsigned int v6; // edx

  result = 0.0;
  if ( 0.0 == x )
  {
    v3 = 0;
  }
  else if ( (HIWORD(x) & 0x7FF0) == 0 && (((unsigned int)&loc_FFFFF & HIDWORD(x)) != 0 || LODWORD(x)) )
  {
    v4 = -1021;
    v5 = x < 0.0;
    while ( (BYTE6(x) & 0x10) == 0 )
    {
      HIDWORD(x) *= 2;
      if ( SLODWORD(x) < 0 )
        HIDWORD(x) |= 1u;
      LODWORD(x) *= 2;
      --v4;
    }
    HIWORD(x) &= ~0x10u;
    if ( v5 )
      HIWORD(x) |= 0x8000u;
    result = _set_exp(x, 0);
  }
  else
  {
    result = _set_exp(x, 0);
    v3 = ((v6 >> 4) & 0x7FF) - 1022;
  }
  *pexp = v3;
  return result;
}
