void __thiscall vostok::resources::allocate_functionality::tick(
        vostok::resources::allocate_functionality *this,
        vostok::resources::allocate_functionality *finalizing_thread,
        vostok::resources::allocate_functionality *finalizing_threada)
{
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v4; // ecx
  vostok::resources::thread_local_data *thread_local_data; // esi
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v6; // ecx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v7; // ecx
  bool v8; // [esp+0h] [ebp-8h]

  if ( GetCurrentThreadId() == s_resources_manager_buffer.m_resources_thread_id )
  {
    vostok::resources::allocate_functionality::allocate_final_resources<vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>(
      &finalizing_thread->m_queries_to_allocate_managed_resource,
      (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)s_resources_manager_buffer.m_resources_thread_id,
      finalizing_thread,
      (bool)finalizing_threada);
  }
  else
  {
    CurrentThreadId = GetCurrentThreadId();
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                          v4,
                          (unsigned int)&s_resources_manager_buffer,
                          CurrentThreadId,
                          0);
    vostok::resources::allocate_functionality::allocate_final_resources<vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>(
      &thread_local_data->to_allocate_resource,
      v6,
      finalizing_thread,
      (bool)finalizing_threada);
    vostok::resources::allocate_functionality::allocate_raw_resources(thread_local_data, v7, finalizing_threada, v8);
  }
}
