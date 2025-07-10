vostok::resources::resource_base **__usercall stlp_std::priv::__unguarded_partition<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>@<eax>(
        vostok::resources::resource_base **__first@<eax>,
        vostok::resources::resource_base **__last@<edx>,
        vostok::resources::resource_base *__pivot@<esi>)
{
  float m_current_satisfaction; // xmm1_4
  int v4; // ecx
  float v5; // xmm0_4
  vostok::resources::resource_base *v6; // ecx

  m_current_satisfaction = __pivot->m_current_satisfaction;
  while ( 1 )
  {
    while ( fabs((*__first)->m_current_satisfaction - m_current_satisfaction) < 0.050000001 )
    {
      if ( (*__first)->m_reconstruction_size >= __pivot->m_reconstruction_size )
        goto LABEL_6;
LABEL_4:
      ++__first;
    }
    if ( (*__first)->m_current_satisfaction > m_current_satisfaction )
      goto LABEL_4;
    do
    {
LABEL_6:
      while ( 1 )
      {
        v4 = (int)*(__last - 1);
        v5 = *(float *)(v4 + 112);
        --__last;
        if ( fabs(m_current_satisfaction - v5) >= 0.050000001 )
          break;
        if ( __pivot->m_reconstruction_size >= *(_DWORD *)(v4 + 24) )
          goto LABEL_8;
      }
    }
    while ( m_current_satisfaction > v5 );
LABEL_8:
    if ( __first >= __last )
      return __first;
    v6 = *__first;
    *__first = *__last;
    *__last = v6;
    ++__first;
  }
}
