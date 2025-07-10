void __cdecl btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(
        unsigned __int64 a,
        unsigned __int64 b,
        unsigned __int64 *resLow,
        unsigned __int64 *resHigh)
{
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // kr08_8
  unsigned __int64 v6; // rax
  unsigned int p0110; // [esp+18h] [ebp-8h]

  v4 = (unsigned int)b * (unsigned __int64)HIDWORD(a);
  p0110 = v4 + a * HIDWORD(b);
  v5 = HIDWORD(a) * (unsigned __int64)HIDWORD(b)
     + (((unsigned int)a * (unsigned __int64)HIDWORD(b)) >> 32)
     + HIDWORD(v4)
     + (((unsigned int)v4 + (unsigned __int64)(unsigned int)(a * HIDWORD(b))) >> 32);
  v6 = __PAIR64__(p0110, 0) + (unsigned int)b * (unsigned __int64)(unsigned int)a;
  if ( HIDWORD(v6) < p0110 )
    ++v5;
  *resLow = v6;
  *resHigh = v5;
}
