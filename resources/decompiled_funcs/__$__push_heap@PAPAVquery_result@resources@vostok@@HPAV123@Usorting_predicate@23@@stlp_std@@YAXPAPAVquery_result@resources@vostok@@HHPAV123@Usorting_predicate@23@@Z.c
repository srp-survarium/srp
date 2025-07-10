void __usercall stlp_std::__push_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        vostok::resources::query_result **__first@<esi>,
        int __holeIndex@<ecx>,
        vostok::resources::query_result *__val@<edi>,
        int __topIndex)
{
  int v4; // eax
  vostok::resources::query_result *v5; // edx

  v4 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    do
    {
      v5 = __first[v4];
      if ( v5->m_quality_index < __val->m_quality_index )
        break;
      __first[__holeIndex] = v5;
      __holeIndex = v4;
      v4 = (v4 - 1) / 2;
    }
    while ( __holeIndex > __topIndex );
    __first[__holeIndex] = __val;
  }
}
