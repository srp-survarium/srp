void __usercall stlp_std::__adjust_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first@<eax>,
        int __holeIndex@<ecx>,
        int __len,
        vostok::resources::resource_base *__val,
        vostok::resources::sorting_predicate __comp)
{
  int v6; // eax
  bool v7; // zf
  vostok::resources::resource_base *v8; // esi
  vostok::resources::resource_base *v9; // edx
  float m_current_satisfaction; // xmm1_4
  int __topIndex; // [esp+Ch] [ebp-4h]

  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  __topIndex = __holeIndex;
  if ( v6 < __len )
  {
    while ( 1 )
    {
      v8 = __first[v6];
      v9 = __first[v6 - 1];
      m_current_satisfaction = v9->m_current_satisfaction;
      if ( fabs(v8->m_current_satisfaction - m_current_satisfaction) >= 0.050000001 )
        break;
      if ( v8->m_reconstruction_size < v9->m_reconstruction_size )
        goto LABEL_4;
LABEL_5:
      __first[__holeIndex] = __first[v6];
      __holeIndex = v6;
      v6 = 2 * v6 + 2;
      v7 = v6 == __len;
      if ( v6 >= __len )
        goto LABEL_6;
    }
    if ( v8->m_current_satisfaction <= m_current_satisfaction )
      goto LABEL_5;
LABEL_4:
    --v6;
    goto LABEL_5;
  }
LABEL_6:
  if ( v7 )
  {
    __first[__holeIndex] = __first[v6 - 1];
    __holeIndex = v6 - 1;
  }
  stlp_std::__push_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
    __first,
    __holeIndex,
    __topIndex,
    __val,
    __comp);
}
