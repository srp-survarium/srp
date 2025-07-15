double __cdecl ceil(double X)
{
  __m128i v1; // xmm0
  int v2; // eax
  bool v3; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( !__use_sse2_mathfcns )
    return _ceil_default(X);
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v5 & 0x7F) == 127;
  if ( v3 )
    return _ceil_pentium4(v1);
  else
    return _ceil_default(X);
}
