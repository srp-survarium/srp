void __thiscall vostok::resources::resource_freeing_functionality::free_collected(
        vostok::resources::resource_freeing_functionality *this,
        vostok::resources::releasing_functionality releasing)
{
  vostok::resources::game_resources_manager_data **m_data; // ebp
  int v3; // eax
  vostok::resources::game_resources_manager_data *v4; // eax
  vostok::resources::resource_base *v5; // esi
  unsigned int m_size; // ecx
  vostok::resources::resource_base *i; // edx
  vostok::resources::resource_base *v8; // ecx
  vostok::resources::resource_base *m_next_for_grm_observer_list; // edx
  vostok::resources::query_result *v10; // eax

  m_data = (vostok::resources::game_resources_manager_data **)releasing.m_data;
  v3 = *(_DWORD *)(releasing.m_data->flags.m_flags + 36);
  if ( v3 )
    *(_BYTE *)(v3 + 708) = 0;
  v4 = *m_data;
  if ( HIDWORD((*m_data)->memory_types.m_mutex.m_mutex[2]) )
  {
    m_size = v4->memory_types.m_size;
    for ( i = 0; m_size; m_size = *(_DWORD *)(m_size + 184) )
    {
      if ( *(_DWORD *)(m_size + 88) == LODWORD(v4->memory_types.m_mutex.m_mutex[1]) )
        i = (vostok::resources::resource_base *)m_size;
    }
    v5 = i;
  }
  else
  {
    v5 = 0;
  }
  releasing.m_data = m_data[1];
  if ( v4->memory_types.m_size )
  {
    do
    {
      v8 = (vostok::resources::resource_base *)v4->memory_types.m_size;
      --v4->flags.m_flags;
      m_next_for_grm_observer_list = v8->m_next_for_grm_observer_list;
      v4->memory_types.m_size = (unsigned int)m_next_for_grm_observer_list;
      if ( !m_next_for_grm_observer_list )
        *((_DWORD *)&v4->memory_types.vostok::size_policy + 1) = 0;
      v8->m_next_for_grm_observer_list = 0;
      v10 = (vostok::resources::query_result *)HIDWORD((*m_data)->memory_types.m_mutex.m_mutex[2]);
      if ( v10
        && v8->m_memory_usage_self.vostok::resources::resource_quality::type == (const vostok::resources::memory_type *)LODWORD((*m_data)->memory_types.m_mutex.m_mutex[1]) )
      {
        _InterlockedExchangeAdd(&v10->m_observed_resource_destructions_left, 1u);
        v8->m_destruction_observer = v10;
      }
      if ( v8 == v5 )
        *(_BYTE *)(HIDWORD((*m_data)->memory_types.m_mutex.m_mutex[2]) + 708) = 1;
      vostok::resources::releasing_functionality::release_resource(&releasing, v8);
      v4 = *m_data;
    }
    while ( (*m_data)->memory_types.m_size );
  }
}
