void __fastcall stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        int __holeIndex,
        int __len,
        unsigned int *__first,
        unsigned int __val,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v5; // eax
  bool v6; // zf
  int __topIndex; // [esp+8h] [ebp-4h]

  v5 = 2 * __holeIndex + 2;
  v6 = v5 == __len;
  for ( __topIndex = __holeIndex; v5 < __len; v6 = v5 == __len )
  {
    if ( *(float *)((_DWORD)__comp.m_distances + 4 * __first[v5 - 1]) > *(float *)((_DWORD)__comp.m_distances
                                                                                 + 4 * __first[v5]) )
      --v5;
    __first[__holeIndex] = __first[v5];
    __holeIndex = v5;
    v5 = 2 * v5 + 2;
  }
  if ( v6 )
  {
    __first[__holeIndex] = __first[v5 - 1];
    __holeIndex = v5 - 1;
  }
  stlp_std::__push_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
    __first,
    __holeIndex,
    __topIndex,
    __val,
    __comp);
}
