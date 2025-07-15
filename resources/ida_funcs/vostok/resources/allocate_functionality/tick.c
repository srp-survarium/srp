void __thiscall vostok::resources::allocate_functionality::tick(
        vostok::resources::allocate_functionality *this,
        vostok::resources::allocate_functionality *finalizing_thread,
        vostok::resources::allocate_functionality *finalizing_threada)
{
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v4; // ecx
  vostok::resources::thread_local_data *thread_local_data; // esi
  bool v6; // [esp+0h] [ebp-Ch]

  if ( GetCurrentThreadId() == *(int *)((char *)&dword_203CC
                                      + (unsigned int)vostok::resources::g_resources_manager.m_variable) )
  {
    vostok::resources::allocate_functionality::allocate_final_resources<vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>(
      &finalizing_thread->m_queries_to_allocate_managed_resource,
      finalizing_thread,
      (bool)finalizing_threada);
  }
  else
  {
    CurrentThreadId = GetCurrentThreadId();
    thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                          v4,
                          vostok::resources::g_resources_manager.m_variable,
                          CurrentThreadId,
                          0);
    vostok::resources::allocate_functionality::allocate_final_resources<vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>(
      &thread_local_data->to_allocate_resource,
      finalizing_thread,
      (bool)finalizing_threada);
    vostok::resources::allocate_functionality::allocate_raw_resources(thread_local_data, finalizing_threada, v6);
  }
}
