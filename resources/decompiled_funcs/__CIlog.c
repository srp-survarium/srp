void __cdecl _CIlog(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( !__use_sse2_mathfcns )
    goto __CIlog;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIlog_pentium4(a1);
  else
__CIlog:
    _CIlog_default(a1, HIDWORD(a1));
}
