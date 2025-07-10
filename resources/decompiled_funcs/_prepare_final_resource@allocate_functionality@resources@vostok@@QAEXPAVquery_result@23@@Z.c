void __userpurge vostok::resources::allocate_functionality::prepare_final_resource(
        vostok::resources::query_result *query@<eax>,
        int a2@<ecx>,
        vostok::resources::allocate_functionality *this)
{
  vostok::resources::cook_base *cook; // eax
  vostok::resources::class_id_enum v5; // edx
  int v6; // ecx
  unsigned int m_flags; // eax
  int final_managed_resource_if_needed; // eax
  vostok::resources::query_result *v9; // ecx
  vostok::resources::cook_base *v10; // eax
  vostok::resources::resources_manager *thread_id; // ebx
  vostok::resources::resources_manager *v12; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v14; // ecx
  bool *v15; // [esp+0h] [ebp-10h]

  cook = vostok::resources::resources_manager::find_cook(a2, query->m_class_id);
  if ( cook && (m_flags = cook->m_flags.m_flags, (m_flags & 0x20) != 0) && (m_flags & 0x18) == 0 )
  {
    if ( GetCurrentThreadId() != *(int *)((char *)&dword_203CC
                                        + (unsigned int)vostok::resources::g_resources_manager.m_variable) )
    {
      vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)vostok::resources::g_resources_manager.m_variable,
        this,
        query,
        v15);
      SetEvent(*(HANDLE *)((char *)&dword_203D0 + (unsigned int)vostok::resources::g_resources_manager.m_variable));
      return;
    }
    final_managed_resource_if_needed = vostok::resources::query_result::allocate_final_managed_resource_if_needed(
                                         (vostok::resources::query_result *)vostok::resources::g_resources_manager.m_variable,
                                         (int)query);
  }
  else
  {
    v10 = vostok::resources::resources_manager::find_cook(v6, v5);
    if ( !v10 || (v10->m_flags.m_flags & 0x38) != 0 )
      v10 = 0;
    if ( (v10->m_flags.m_flags & 2) != 0 )
      goto LABEL_8;
    thread_id = (vostok::resources::resources_manager *)vostok::resources::query_result::allocate_thread_id(
                                                          v9,
                                                          (int)query);
    if ( thread_id != (vostok::resources::resources_manager *)GetCurrentThreadId() )
    {
      thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                            v12,
                            vostok::resources::g_resources_manager.m_variable,
                            (unsigned int)thread_id,
                            1);
      vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        v14,
        &thread_local_data->to_allocate_resource.m_size,
        query,
        v15);
      vostok::resources::resources_manager::wakeup_thread_by_id_if_needed(
        thread_id,
        (int)vostok::resources::g_resources_manager.m_variable);
      return;
    }
    final_managed_resource_if_needed = vostok::resources::query_result::allocate_final_unmanaged_resource_if_needed(
                                         (vostok::resources::query_result *)v12,
                                         (int)query);
  }
  if ( final_managed_resource_if_needed == 1 )
  {
LABEL_8:
    vostok::resources::query_result::send_to_create_resource(v9, (int)query);
    return;
  }
  if ( !final_managed_resource_if_needed && !_InterlockedExchangeAdd(&query->m_query_end_guard, 0xFFFFFFFF) )
    vostok::resources::query_result::end_query_might_destroy_this_impl(0, query);
}
