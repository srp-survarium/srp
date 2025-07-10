void __userpurge vostok::resources::game_resources_manager::capture_resource(
        vostok::intrusive_double_linked_list<vostok::resources::resource_base,vostok::resources::resource_base *,156,152,vostok::threading::single_threading_policy,vostok::size_policy,vostok::debug_policy> *resource@<edi>,
        double a2@<st0>,
        vostok::resources::game_resources_manager *this)
{
  vostok::resources::resource_base *p_m_policy; // eax
  volatile signed __int32 *v4; // eax
  vostok::intrusive_list<vostok::resources::unmanaged_resource_buffer,vostok::resources::unmanaged_resource_buffer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v5; // ecx
  const vostok::resources::memory_type *m_last; // ebx
  vostok::resources::game_resources_manager *v7; // ecx
  bool *v8; // [esp+0h] [ebp-8h]

  if ( ((int)resource->m_last & 1) != 0 && resource )
  {
    p_m_policy = (vostok::resources::resource_base *)&resource[13].m_policy;
  }
  else if ( ((int)resource->m_last & 4) != 0 && resource )
  {
    p_m_policy = (vostok::resources::resource_base *)&resource[13];
  }
  else
  {
    p_m_policy = 0;
  }
  if ( (p_m_policy->type & 1) == 0
    && (vostok::resources::memory_type *)resource[5].m_last != &vostok::resources::nocache_memory )
  {
    if ( ((int)resource->m_last & 1) != 0 )
    {
      v4 = (volatile signed __int32 *)&resource[13].m_policy;
    }
    else if ( ((int)resource->m_last & 4) != 0 )
    {
      v4 = (volatile signed __int32 *)&resource[13];
    }
    else
    {
      v4 = 0;
    }
    _InterlockedExchangeAdd(v4, 1u);
    vostok::threading::interlocked_or(v4 + 1, 1u);
    m_last = (const vostok::resources::memory_type *)resource[5].m_last;
    if ( !m_last->in_list )
    {
      vostok::intrusive_list<vostok::resources::memory_type,vostok::resources::memory_type *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        v5,
        (int)&this->m_data.memory_types,
        (vostok::resources::unmanaged_resource_buffer *)resource[5].m_last,
        v8);
      m_last->in_list = 1;
    }
    vostok::intrusive_double_linked_list<vostok::resources::resource_base,vostok::resources::resource_base *,156,152,vostok::threading::single_threading_policy,vostok::size_policy,vostok::debug_policy>::push_back(
      resource,
      &m_last->resources.m_size);
    vostok::resources::resource_quality::update_satisfaction(
      (vostok::resources::resource_quality *)resource,
      a2,
      this->m_data.current_increase_quality_tick);
    if ( *(_DWORD *)&resource[6].m_policy.vostok::core::noncopyable != 1 )
      vostok::resources::game_resources_manager::add_new_resource_to_increase_quality_tree(
        v7,
        this,
        (vostok::resources::quality_increase_functionality)resource);
  }
}
