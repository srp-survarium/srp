void __thiscall vostok::resources::resources_manager::deallocate_delayed_unmanaged_resources(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *a2)
{
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v3; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::intrusive_list<vostok::resources::unmanaged_resource_buffer,vostok::resources::unmanaged_resource_buffer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_delayed_deallocate_unmanaged_resources; // esi
  vostok::resources::unmanaged_resource_buffer *m_first; // ebx
  vostok::fixed_string<260> *v7; // ecx
  vostok::resources::unmanaged_resource_buffer *v8; // edi
  vostok::resources::unmanaged_resource_buffer *m_next_to_deallocate; // esi
  volatile __int32 *p_deallocating_resources; // [esp+10h] [ebp-4h]

  CurrentThreadId = GetCurrentThreadId();
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        v3,
                        (unsigned int)a2,
                        CurrentThreadId,
                        0);
  if ( thread_local_data )
  {
    p_deallocating_resources = &thread_local_data->deallocating_resources;
    _InterlockedExchange(&thread_local_data->deallocating_resources, 1);
    p_delayed_deallocate_unmanaged_resources = &thread_local_data->delayed_deallocate_unmanaged_resources;
    if ( thread_local_data->delayed_deallocate_unmanaged_resources.m_first )
    {
      vostok::threading::mutex::lock(
        (vostok::threading::mutex *)&thread_local_data->deallocating_resources,
        (_RTL_CRITICAL_SECTION *)&thread_local_data->delayed_deallocate_unmanaged_resources.vostok::threading::mutex);
      m_first = p_delayed_deallocate_unmanaged_resources->m_first;
      p_delayed_deallocate_unmanaged_resources->m_first = 0;
      p_delayed_deallocate_unmanaged_resources->m_last = 0;
      p_delayed_deallocate_unmanaged_resources->m_size = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&p_delayed_deallocate_unmanaged_resources->vostok::threading::mutex);
      v8 = m_first;
      if ( m_first )
      {
        do
        {
          m_next_to_deallocate = v8->m_next_to_deallocate;
          vostok::resources::resources_manager::deallocate_unmanaged_resource(v8, v7, a2);
          v8 = m_next_to_deallocate;
        }
        while ( m_next_to_deallocate );
      }
    }
    _InterlockedExchange(p_deallocating_resources, 0);
  }
}
