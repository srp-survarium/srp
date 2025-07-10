void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        vostok::resources::query_result **__first@<eax>,
        vostok::resources::query_result **__last)
{
  vostok::resources::query_result **i; // esi
  vostok::resources::query_result *v3; // edi
  vostok::resources::query_result **v4; // ecx
  vostok::resources::query_result **j; // eax

  for ( i = __first; i != __last; *v4 = v3 )
  {
    v3 = *i;
    v4 = i;
    for ( j = i - 1; v3->m_quality_index >= (*j)->m_quality_index; --j )
    {
      *v4 = *j;
      v4 = j;
    }
    ++i;
  }
}
