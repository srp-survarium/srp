void __usercall stlp_std::priv::__introsort_loop<vostok::resources::query_result * *,vostok::resources::query_result *,int,vostok::resources::sorting_predicate>(
        vostok::resources::sorting_predicate a1@<sil>,
        vostok::resources::query_result **__first,
        vostok::resources::query_result **__last,
        vostok::resources::query_result **__formal,
        int __depth_limit,
        vostok::resources::query_result **__comp)
{
  vostok::resources::query_result **v6; // ebx
  unsigned int m_quality_index; // ecx
  int v9; // kr00_4
  unsigned int v10; // edx
  vostok::resources::query_result **v11; // eax
  unsigned int v12; // ebp
  vostok::resources::query_result **v13; // esi
  int __depth_limita; // [esp+18h] [ebp+10h]

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
          __first,
          v6,
          v6,
          __comp,
          a1);
        return;
      }
      m_quality_index = (*__first)->m_quality_index;
      v9 = v6 - __first;
      v10 = __first[v9 / 2]->m_quality_index;
      v11 = &__first[v9 / 2];
      __depth_limita = __depth_limit - 1;
      v12 = (*(v6 - 1))->m_quality_index;
      if ( m_quality_index < v10 )
      {
        if ( m_quality_index >= v12 )
          goto LABEL_8;
        if ( v10 >= v12 )
LABEL_10:
          v11 = v6 - 1;
      }
      else if ( v10 < v12 )
      {
        if ( m_quality_index >= v12 )
          goto LABEL_10;
LABEL_8:
        v11 = __first;
      }
      __depth_limit = __depth_limita;
      v13 = stlp_std::priv::__unguarded_partition<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
              __first,
              v6,
              *v11,
              (vostok::resources::sorting_predicate)__comp);
      stlp_std::priv::__introsort_loop<vostok::resources::query_result * *,vostok::resources::query_result *,int,vostok::resources::sorting_predicate>(
        v13,
        v6,
        0,
        __depth_limita,
        (vostok::resources::sorting_predicate)__comp);
      v6 = v13;
    }
    while ( (int)(((char *)v13 - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}
