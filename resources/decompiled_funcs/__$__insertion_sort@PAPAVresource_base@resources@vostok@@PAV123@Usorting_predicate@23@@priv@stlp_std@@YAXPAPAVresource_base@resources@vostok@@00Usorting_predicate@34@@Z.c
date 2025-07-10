void __cdecl stlp_std::priv::__insertion_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first,
        vostok::resources::resource_base **__last,
        vostok::resources::resource_base **a3)
{
  vostok::resources::resource_base **v3; // esi
  signed int v4; // ebx
  vostok::resources::resource_base *v5; // edi
  float m_current_satisfaction; // xmm1_4

  v3 = __first + 1;
  if ( __first + 1 != __last )
  {
    v4 = 4;
    do
    {
      v5 = *v3;
      m_current_satisfaction = (*__first)->m_current_satisfaction;
      if ( fabs((*v3)->m_current_satisfaction - m_current_satisfaction) >= 0.050000001 )
      {
        if ( (*v3)->m_current_satisfaction > m_current_satisfaction )
        {
LABEL_5:
          if ( v4 > 0 )
            memmove((unsigned __int8 *)&v3[v4 / 0xFFFFFFFC + 1], (unsigned __int8 *)__first, v4);
          *__first = v5;
          goto LABEL_10;
        }
      }
      else if ( v5->m_reconstruction_size < (*__first)->m_reconstruction_size )
      {
        goto LABEL_5;
      }
      stlp_std::priv::__unguarded_linear_insert<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        v3,
        v5,
        *(vostok::resources::sorting_predicate *)a3);
LABEL_10:
      ++v3;
      v4 += 4;
    }
    while ( v3 != __last );
  }
}
