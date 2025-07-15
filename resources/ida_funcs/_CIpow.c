void __cdecl _CIpow(__int64 a1, __int64 a2)
{
  int v4; // eax
  bool v5; // zf
  char v6; // [esp+0h] [ebp-8h]

  if ( !__use_sse2_mathfcns )
    goto __CIpow;
  v4 = _mm_getcsr() & 0x1F80;
  v5 = v4 == 8064;
  if ( v4 == 8064 )
    v5 = (v6 & 0x7F) == 127;
  if ( v5 )
    _CIpow_pentium4(a1, a2);
  else
__CIpow:
    _CIpow_default(a1, HIDWORD(a1), a2, HIDWORD(a2));
}
