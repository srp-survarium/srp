void _CIsin()
{
  int v0; // eax
  bool v1; // zf
  char v2; // [esp+0h] [ebp-8h]

  if ( !__use_sse2_mathfcns )
    goto __CIsin;
  v0 = _mm_getcsr() & 0x1F80;
  v1 = v0 == 8064;
  if ( v0 == 8064 )
    v1 = (v2 & 0x7F) == 127;
  if ( v1 )
    _CIsin_pentium4();
  else
__CIsin:
    _CIsin_default();
}
