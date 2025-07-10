void __usercall stlp_std::priv::__unguarded_linear_insert<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__last@<eax>,
        vostok::resources::resource_base *__val@<edi>)
{
  float m_current_satisfaction; // xmm1_4
  vostok::resources::resource_base **v3; // esi
  vostok::resources::resource_base **i; // ecx
  vostok::resources::resource_base *v5; // eax
  float v6; // xmm0_4

  m_current_satisfaction = __val->m_current_satisfaction;
  v3 = __last;
  for ( i = __last - 1; ; --i )
  {
    v5 = *i;
    v6 = (*i)->m_current_satisfaction;
    if ( fabs(m_current_satisfaction - v6) >= 0.050000001 )
      break;
    if ( __val->m_reconstruction_size >= v5->m_reconstruction_size )
      goto LABEL_6;
LABEL_4:
    *v3 = v5;
    v3 = i;
  }
  if ( m_current_satisfaction > v6 )
    goto LABEL_4;
LABEL_6:
  *v3 = __val;
}
