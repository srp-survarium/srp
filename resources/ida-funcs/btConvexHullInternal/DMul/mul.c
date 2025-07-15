void __cdecl btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(
        unsigned __int64 a,
        unsigned __int64 b,
        unsigned __int64 *resLow,
        unsigned __int64 *resHigh)
{
  unsigned __int64 v4; // rax
  unsigned int v5; // edi
  unsigned int v6; // esi
  unsigned __int64 v7; // rax
  unsigned int v8; // [esp+Ch] [ebp-10h]
  unsigned int v9; // [esp+14h] [ebp-8h]

  v4 = (unsigned int)b * (unsigned __int64)HIDWORD(a);
  v8 = v4 + a * HIDWORD(b);
  v5 = (HIDWORD(a) * (unsigned __int64)HIDWORD(b)
      + (((unsigned int)a * (unsigned __int64)HIDWORD(b)) >> 32)
      + HIDWORD(v4)
      + (((unsigned int)v4 + (unsigned __int64)(unsigned int)(a * HIDWORD(b))) >> 32)) >> 32;
  v6 = HIDWORD(a) * HIDWORD(b)
     + (((unsigned int)a * (unsigned __int64)HIDWORD(b)) >> 32)
     + HIDWORD(v4)
     + (((unsigned int)v4 + (unsigned __int64)(unsigned int)(a * HIDWORD(b))) >> 32);
  v9 = v6;
  v7 = __PAIR64__(v8, 0) + (unsigned int)b * (unsigned __int64)(unsigned int)a;
  if ( HIDWORD(v7) < v8 )
  {
    v5 = (__PAIR64__(v5, v6) + 1) >> 32;
    v9 = v6 + 1;
  }
  *resLow = v7;
  *((_DWORD *)resHigh + 1) = v5;
  *(_DWORD *)resHigh = v9;
}
