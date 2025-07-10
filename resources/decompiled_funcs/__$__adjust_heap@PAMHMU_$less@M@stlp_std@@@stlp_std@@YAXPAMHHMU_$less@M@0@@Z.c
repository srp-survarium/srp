void __fastcall stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(
        float *__first,
        int __len,
        int __holeIndex,
        float __val)
{
  int v4; // esi
  int v5; // eax
  bool i; // zf
  int v7; // eax
  float v8; // xmm0_4

  v4 = __holeIndex;
  v5 = 2 * __holeIndex + 2;
  for ( i = v5 == __len; v5 < __len; i = v5 == __len )
  {
    if ( __first[v5 - 1] > __first[v5] )
      --v5;
    __first[v4] = __first[v5];
    v4 = v5;
    v5 = 2 * v5 + 2;
  }
  if ( i )
  {
    __first[v4] = __first[v5 - 1];
    v4 = v5 - 1;
  }
  v7 = (v4 - 1) / 2;
  if ( v4 <= __holeIndex )
  {
    __first[v4] = __val;
  }
  else
  {
    do
    {
      v8 = __first[v7];
      if ( __val <= v8 )
        break;
      __first[v4] = v8;
      v4 = v7;
      v7 = (v7 - 1) / 2;
    }
    while ( v4 > __holeIndex );
    __first[v4] = __val;
  }
}
