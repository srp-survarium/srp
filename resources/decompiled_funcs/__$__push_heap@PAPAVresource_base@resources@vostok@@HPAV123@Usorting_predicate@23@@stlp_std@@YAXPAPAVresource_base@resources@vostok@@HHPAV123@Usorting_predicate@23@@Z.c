void __usercall stlp_std::__push_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first@<edi>,
        int __holeIndex@<ecx>,
        int __topIndex,
        vostok::resources::resource_base *__val)
{
  int v4; // eax
  float m_current_satisfaction; // xmm1_4
  vostok::resources::resource_base *v6; // esi

  v4 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    m_current_satisfaction = __val->m_current_satisfaction;
    do
    {
      v6 = __first[v4];
      if ( fabs(v6->m_current_satisfaction - m_current_satisfaction) >= 0.050000001 )
      {
        if ( v6->m_current_satisfaction <= m_current_satisfaction )
          break;
      }
      else if ( v6->m_reconstruction_size >= __val->m_reconstruction_size )
      {
        break;
      }
      __first[__holeIndex] = v6;
      __holeIndex = v4;
      v4 = (v4 - 1) / 2;
    }
    while ( __holeIndex > __topIndex );
  }
  __first[__holeIndex] = __val;
}
