void __cdecl btConvexHullInternal::DMul<btConvexHullInternal::Int128,unsigned __int64>::mul(
        btConvexHullInternal::Int128 a,
        btConvexHullInternal::Int128 b,
        unsigned __int64 resLow)
{
  unsigned __int64 v3; // kr00_8
  unsigned __int64 v4; // kr08_8
  unsigned __int64 v5; // kr10_8
  unsigned __int64 v6; // kr18_8
  btConvexHullInternal::Int128 p01; // [esp+10h] [ebp-54h] BYREF
  btConvexHullInternal::Int128 p11; // [esp+20h] [ebp-44h] BYREF
  btConvexHullInternal::Int128 p00; // [esp+30h] [ebp-34h] BYREF
  btConvexHullInternal::Int128 p10; // [esp+40h] [ebp-24h] BYREF
  btConvexHullInternal::Int128 p0110; // [esp+50h] [ebp-14h]

  btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(a.high, b.high, &p00.low, &p00.high);
  btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(a.high, resLow, &p01.low, &p01.high);
  btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(b.low, b.high, &p10.low, &p10.high);
  btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(b.low, resLow, &p11.low, &p11.high);
  v3 = p10.low + p01.low;
  HIDWORD(p0110.high) = 0;
  v4 = p01.high + p11.low;
  if ( p01.high + p11.low < p11.low )
    ++p11.high;
  v5 = v4 + p10.high;
  if ( v4 + p10.high < v4 )
    ++p11.high;
  v6 = v5 + __PAIR64__(HIDWORD(p0110.high), p10.low + p01.low < p01.low);
  HIDWORD(p01.low) = (v5 + __PAIR64__(HIDWORD(p0110.high), p10.low + p01.low < p01.low)) >> 32;
  if ( v6 < v5 )
    ++p11.high;
  p11.low = v6;
  p00.high += v3;
  if ( p00.high < v3 )
  {
    p11.low = v6 + 1;
    if ( v6 == -1 )
      ++p11.high;
  }
  *(btConvexHullInternal::Int128 *)LODWORD(a.low) = p00;
  *(btConvexHullInternal::Int128 *)HIDWORD(a.low) = p11;
}
