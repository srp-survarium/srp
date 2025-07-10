void __thiscall vostok::resources::resources_manager::deallocate_delayed_unmanaged_resources(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *thisa)
{
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v3; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  volatile __int32 *p_deallocating_resources; // ebp
  vostok::resources::unmanaged_resource_buffer *v6; // eax
  vostok::resources::unmanaged_resource_buffer *m_next_to_deallocate; // edi

  CurrentThreadId = GetCurrentThreadId();
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(v3, thisa, CurrentThreadId, 0);
  if ( thread_local_data )
  {
    p_deallocating_resources = &thread_local_data->deallocating_resources;
    v6 = (vostok::resources::unmanaged_resource_buffer *)vostok::intrusive_list<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_resource *,232,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
                                                           (vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)_InterlockedExchange(&thread_local_data->deallocating_resources, 1),
                                                           (int)&thread_local_data->delayed_deallocate_unmanaged_resources);
    if ( v6 )
    {
      do
      {
        m_next_to_deallocate = v6->m_next_to_deallocate;
        vostok::resources::resources_manager::deallocate_unmanaged_resource(v6, thisa);
        v6 = m_next_to_deallocate;
      }
      while ( m_next_to_deallocate );
    }
    _InterlockedExchange(p_deallocating_resources, 0);
  }
}
