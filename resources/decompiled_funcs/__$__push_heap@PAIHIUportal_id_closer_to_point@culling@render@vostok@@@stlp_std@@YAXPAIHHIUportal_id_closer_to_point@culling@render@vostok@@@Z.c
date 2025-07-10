void __usercall stlp_std::__push_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first@<esi>,
        int __holeIndex@<ecx>,
        unsigned int __val@<edi>,
        int __topIndex,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v5; // eax
  unsigned int v6; // edx

  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    do
    {
      v6 = __first[v5];
      if ( *(float *)((_DWORD)__comp.m_distances + 4 * __val) <= *(float *)((_DWORD)__comp.m_distances + 4 * v6) )
        break;
      __first[__holeIndex] = v6;
      __holeIndex = v5;
      v5 = (v5 - 1) / 2;
    }
    while ( __holeIndex > __topIndex );
    __first[__holeIndex] = __val;
  }
}
