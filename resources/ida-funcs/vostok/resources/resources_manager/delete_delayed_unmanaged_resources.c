void __thiscall vostok::resources::resources_manager::delete_delayed_unmanaged_resources(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *a2)
{
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v3; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::intrusive_list<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_resource *,232,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_delayed_delete_unmanaged_resources; // esi
  vostok::resources::unmanaged_resource *m_first; // ebx
  vostok::resources::resources_manager *v7; // ecx
  vostok::resources::unmanaged_resource *v8; // eax
  vostok::resources::unmanaged_resource *m_next_delay_delete; // esi
  volatile __int32 *p_deleting_resources; // [esp+Ch] [ebp-4h]

  CurrentThreadId = GetCurrentThreadId();
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        v3,
                        (unsigned int)a2,
                        CurrentThreadId,
                        0);
  if ( thread_local_data && thread_local_data->delayed_delete_unmanaged_resources.m_first )
  {
    p_deleting_resources = &thread_local_data->deleting_resources;
    _InterlockedExchange(&thread_local_data->deleting_resources, 1);
    p_delayed_delete_unmanaged_resources = &thread_local_data->delayed_delete_unmanaged_resources;
    if ( thread_local_data->delayed_delete_unmanaged_resources.m_first )
    {
      vostok::threading::mutex::lock(
        (vostok::threading::mutex *)&thread_local_data->deleting_resources,
        (_RTL_CRITICAL_SECTION *)&thread_local_data->delayed_delete_unmanaged_resources.vostok::threading::mutex);
      m_first = p_delayed_delete_unmanaged_resources->m_first;
      p_delayed_delete_unmanaged_resources->m_first = 0;
      p_delayed_delete_unmanaged_resources->m_last = 0;
      p_delayed_delete_unmanaged_resources->m_size = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&p_delayed_delete_unmanaged_resources->vostok::threading::mutex);
      v8 = m_first;
      if ( m_first )
      {
        do
        {
          m_next_delay_delete = v8->m_next_delay_delete;
          vostok::resources::resources_manager::delete_unmanaged_resource(v7, a2, v8);
          v8 = m_next_delay_delete;
        }
        while ( m_next_delay_delete );
      }
    }
    _InterlockedExchange(p_deleting_resources, 0);
  }
}
