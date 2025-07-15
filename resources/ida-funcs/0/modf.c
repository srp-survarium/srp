double __cdecl modf(double X, double *Y)
{
  __m128i v2; // xmm0
  int v3; // eax
  bool v4; // zf
  char v6; // [esp+0h] [ebp-8h]

  if ( !__use_sse2_mathfcns )
    return _modf_default(X, Y);
  v3 = _mm_getcsr() & 0x1F80;
  v4 = v3 == 8064;
  if ( v3 == 8064 )
    v4 = (v6 & 0x7F) == 127;
  if ( v4 )
    return _modf_pentium4(v2);
  else
    return _modf_default(X, Y);
}


double __usercall modf@<st0>(float a1@<xmm0>, double x)
{
  double result; // st7
  double Y; // [esp+Ch] [ebp-Ch] BYREF

  result = modf(a1, &Y);
  *(float *)LODWORD(x) = Y;
  return result;
}
