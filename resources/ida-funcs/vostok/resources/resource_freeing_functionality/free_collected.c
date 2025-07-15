void __usercall vostok::resources::resource_freeing_functionality::free_collected(
        vostok::resources::resource_freeing_functionality *this@<ecx>,
        vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> **a2@<esi>)
{
  int v2; // eax
  vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v3; // ecx
  vostok::resources::resource_base *m_first; // eax
  vostok::resources::resource_base *i; // edi
  vostok::resources::resource_base *v6; // eax
  vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_observed_resource_destructions_left; // ecx
  vostok::resources::query_result *v8; // edx
  vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v9; // [esp+8h] [ebp-8h] BYREF
  vostok::resources::resource_base *v10; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)&(*a2)[2].gap4;
  if ( v2 )
    *(_BYTE *)(v2 + 724) = 0;
  v3 = *a2;
  if ( *(_DWORD *)&(*a2)[2].gap4 )
  {
    m_first = v3->m_first;
    for ( i = 0; m_first; m_first = m_first->m_next_for_grm_observer_list )
    {
      if ( m_first->m_memory_usage_self.vostok::resources::resource_quality::type == (const vostok::resources::memory_type *)v3[1].m_first )
        i = m_first;
    }
    v10 = i;
  }
  else
  {
    v10 = 0;
  }
  v9 = a2[1];
  while ( v3->m_first )
  {
    v6 = vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(v3);
    p_m_observed_resource_destructions_left = *a2;
    v8 = *(vostok::resources::query_result **)&(*a2)[2].gap4;
    if ( v8
      && v6->m_memory_usage_self.vostok::resources::resource_quality::type == (const vostok::resources::memory_type *)p_m_observed_resource_destructions_left[1].m_first )
    {
      p_m_observed_resource_destructions_left = (vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&v8->m_observed_resource_destructions_left;
      _InterlockedExchangeAdd(&v8->m_observed_resource_destructions_left, 1u);
      v6->m_destruction_observer = v8;
    }
    if ( v6 == v10 )
    {
      p_m_observed_resource_destructions_left = *(vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,184,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> **)&(*a2)[2].gap4;
      p_m_observed_resource_destructions_left[45].gap4 = 1;
    }
    vostok::resources::releasing_functionality::release_resource(
      (vostok::resources::releasing_functionality *)p_m_observed_resource_destructions_left,
      (vostok::resources::resource_base *)&v9,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v6);
    v3 = *a2;
  }
}
