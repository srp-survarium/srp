void __usercall vostok::resources::resources_manager::delete_delayed_unmanaged_resources(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *a2@<edi>)
{
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v3; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  volatile __int32 *p_deleting_resources; // ebx
  vostok::resources::unmanaged_resource *v6; // eax
  int v7; // ecx
  vostok::resources::unmanaged_resource *m_next_delay_delete; // esi

  CurrentThreadId = GetCurrentThreadId();
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(v3, a2, CurrentThreadId, 0);
  if ( thread_local_data && thread_local_data->delayed_delete_unmanaged_resources.m_first )
  {
    p_deleting_resources = &thread_local_data->deleting_resources;
    v6 = (vostok::resources::unmanaged_resource *)vostok::intrusive_list<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_resource *,232,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
                                                    (vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)_InterlockedExchange(&thread_local_data->deleting_resources, 1),
                                                    (int)&thread_local_data->delayed_delete_unmanaged_resources);
    if ( v6 )
    {
      do
      {
        m_next_delay_delete = v6->m_next_delay_delete;
        vostok::resources::resources_manager::delete_unmanaged_resource(v6, v7, a2);
        v6 = m_next_delay_delete;
      }
      while ( m_next_delay_delete );
    }
    _InterlockedExchange(p_deleting_resources, 0);
  }
}
