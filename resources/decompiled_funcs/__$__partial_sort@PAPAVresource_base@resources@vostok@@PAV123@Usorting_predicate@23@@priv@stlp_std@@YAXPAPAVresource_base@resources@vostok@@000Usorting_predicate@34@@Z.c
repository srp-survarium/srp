void __usercall stlp_std::priv::__partial_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first@<eax>,
        vostok::resources::resource_base **__middle,
        vostok::resources::resource_base **__last,
        vostok::resources::resource_base **__formal)
{
  vostok::resources::resource_base **v4; // ebp
  int v6; // ebx
  vostok::resources::resource_base *v7; // ecx
  vostok::resources::resource_base *v8; // eax
  float m_current_satisfaction; // xmm1_4

  v4 = __middle;
  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<vostok::resources::resource_base * *,vostok::resources::sorting_predicate,vostok::resources::resource_base *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    while ( 1 )
    {
      v7 = *v4;
      v8 = *__first;
      m_current_satisfaction = (*__first)->m_current_satisfaction;
      if ( fabs((*v4)->m_current_satisfaction - m_current_satisfaction) >= 0.050000001 )
        break;
      if ( v7->m_reconstruction_size < v8->m_reconstruction_size )
        goto LABEL_6;
LABEL_7:
      if ( ++v4 >= __last )
        goto LABEL_8;
    }
    if ( (*v4)->m_current_satisfaction <= m_current_satisfaction )
      goto LABEL_7;
LABEL_6:
    *v4 = v8;
    stlp_std::__adjust_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
      __first,
      0,
      v6,
      v7,
      (vostok::resources::sorting_predicate)__formal);
    goto LABEL_7;
  }
LABEL_8:
  stlp_std::sort_heap<vostok::resources::resource_base * *,vostok::resources::sorting_predicate>(
    __first,
    __middle,
    (vostok::resources::sorting_predicate)__formal);
}
