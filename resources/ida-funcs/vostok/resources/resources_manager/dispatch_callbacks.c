void __thiscall vostok::resources::resources_manager::dispatch_callbacks(
        vostok::resources::resources_manager *this,
        vostok::resources::allocate_functionality *finalizing_thread)
{
  DWORD CurrentThreadId; // esi
  vostok::resources::resources_manager *v4; // ecx
  vostok::resources::resources_manager *v5; // ecx
  vostok::resources::resources_manager *v6; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v8; // ecx
  vostok::resources::thread_local_data *v9; // edi
  vostok::resources::query_result *v10; // eax
  vostok::resources::query_result *v11; // ecx
  vostok::resources::query_result *m_next_in_device_manager; // esi
  vostok::resources::resource_base *v13; // eax
  vostok::resources::allocate_functionality *v14; // ecx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v15; // ecx
  vostok::resources::query_result *v16; // eax
  vostok::threading::mutex *v17; // ecx
  vostok::resources::queries_result *v18; // eax
  vostok::resources::queries_result *m_first; // ebp
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v20; // ecx
  vostok::resources::query_result *v21; // eax
  boost::function0<bool> *v22; // ecx
  vostok::resources::query_result *v23; // esi
  const vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v24; // [esp+0h] [ebp-10h]
  bool v25; // [esp+0h] [ebp-10h]
  bool v26; // [esp+4h] [ebp-Ch]

  CurrentThreadId = GetCurrentThreadId();
  vostok::resources::resources_manager::dispatch_devices(this);
  vostok::resources::resources_manager::delete_delayed_unmanaged_resources(v4, this);
  vostok::resources::resources_manager::deallocate_delayed_unmanaged_resources(v5, this);
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        v6,
                        (unsigned int)this,
                        CurrentThreadId,
                        1);
  v9 = thread_local_data;
  if ( thread_local_data )
  {
    thread_local_data->dispatching_callbacks = 1;
    v10 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
            v8,
            (int)&thread_local_data->to_translate_query,
            0);
    if ( v10 )
    {
      do
      {
        m_next_in_device_manager = v10->m_next_in_device_manager;
        vostok::resources::query_result::translate_query_if_needed(v11, (int)v10);
        v10 = m_next_in_device_manager;
      }
      while ( m_next_in_device_manager );
    }
    v13 = vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
            (vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v11,
            (int)&v9->ready_fs_tasks);
    if ( v13 )
      vostok::resources::resources_manager::dispatch_fs_tasks_callbacks(
        (vostok::resources::fs_task *)v13,
        (const bool)finalizing_thread);
    vostok::resources::allocate_functionality::tick(v14, &this->m_allocate_functionality, finalizing_thread);
    v16 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
            v15,
            (int)&v9->to_create_resource,
            0);
    vostok::resources::resources_manager::create_resources<vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>(
      v16,
      (vostok::resources::resources_manager *)finalizing_thread,
      v24,
      v26);
    if ( v9->finished_queries.m_first )
    {
      vostok::threading::mutex::lock(v17, (_RTL_CRITICAL_SECTION *)&v9->finished_queries.vostok::threading::mutex);
      m_first = v9->finished_queries.m_first;
      v9->finished_queries.m_first = 0;
      v9->finished_queries.m_last = 0;
      v9->finished_queries.m_size = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&v9->finished_queries.vostok::threading::mutex);
      v18 = m_first;
    }
    else
    {
      v18 = 0;
    }
    vostok::resources::resources_manager::dispatch_query_callbacks(
      v18,
      (vostok::resources::queries_result *)v17,
      (vostok::resources::resources_manager *)finalizing_thread,
      v25);
    v21 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
            v20,
            (int)&v9->queries_with_tasks_finished,
            0);
    if ( v21 )
    {
      do
      {
        v23 = v21->m_next_in_device_manager;
        boost::function0<void>::operator()(v22, &v21->m_tasks_finished_callback.vtable);
        v21 = v23;
      }
      while ( v23 );
    }
    v9->dispatching_callbacks = 0;
  }
}
