vostok::resources::query_result **__usercall stlp_std::priv::__unguarded_partition<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>@<eax>(
        vostok::resources::query_result **__first@<eax>,
        vostok::resources::query_result **__last@<ecx>,
        vostok::resources::query_result *__pivot@<esi>)
{
  unsigned int m_quality_index; // edx
  vostok::resources::query_result *v4; // edi
  vostok::resources::query_result *v5; // edx

  while ( 1 )
  {
    m_quality_index = __pivot->m_quality_index;
    while ( (*__first)->m_quality_index >= m_quality_index )
      ++__first;
    do
      v4 = *--__last;
    while ( m_quality_index >= v4->m_quality_index );
    if ( __first >= __last )
      break;
    v5 = *__first;
    *__first = v4;
    *__last = v5;
    ++__first;
  }
  return __first;
}
