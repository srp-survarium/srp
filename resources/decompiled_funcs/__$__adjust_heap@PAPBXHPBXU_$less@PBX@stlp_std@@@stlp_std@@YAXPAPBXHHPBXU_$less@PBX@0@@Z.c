void __fastcall stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
        unsigned int *__first,
        int __len,
        int __holeIndex,
        unsigned int __val)
{
  int v4; // esi
  int v5; // eax
  bool i; // zf
  int j; // eax
  unsigned int v8; // edx

  v4 = __holeIndex;
  v5 = 2 * __holeIndex + 2;
  for ( i = v5 == __len; v5 < __len; i = v5 == __len )
  {
    if ( __first[v5] < __first[v5 - 1] )
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
  for ( j = (v4 - 1) / 2; v4 > __holeIndex; j = (j - 1) / 2 )
  {
    v8 = __first[j];
    if ( v8 >= __val )
      break;
    __first[v4] = v8;
    v4 = j;
  }
  __first[v4] = __val;
}
