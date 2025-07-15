void __thiscall vostok::resources::resources_manager::resources_thread_tick(vostok::resources::resources_manager *this)
{
  vostok::vfs::virtual_file_system *v1; // ecx
  vostok::resources::game_resources_manager *v2; // ecx
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v4; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::resources::resources_manager *m_count_of_pending_query_with_fat_it; // ecx
  bool v7; // al
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v8; // ecx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v9; // ecx
  vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v10; // ecx
  vostok::resources::resource_base *v11; // eax
  vostok::threading::mutex *v12; // ecx
  vostok::resources::resource_base *v13; // edi
  vostok::resources::managed_resource *m_first; // esi
  vostok::resources::managed_resource *v15; // eax
  vostok::resources::resources_manager *v16; // ecx
  vostok::resources::resources_manager *v17; // ecx
  vostok::resources::fs_task *v18; // esi
  vostok::resources::fs_task *m_next; // edi
  vostok::resources::query_result *v20; // eax
  vostok::resources::resources_manager *v21; // ecx
  vostok::resources::resources_manager *v22; // ecx
  vostok::resources::allocate_functionality *v23; // ecx
  vostok::resources::resources_manager *v24; // ecx
  void **M_start; // ecx
  void **M_finish; // edi
  void **i; // esi
  vostok::resources::resources_manager *v28; // ecx
  vostok::resources::query_result *v29; // eax
  vostok::resources::query_result *m_next_in_device_manager; // esi
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v31; // ecx
  vostok::resources::resources_manager *v32; // ecx
  const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *j; // esi
  vostok::timing::timer *v34; // ecx
  vostok::timing::timer *v35; // ecx
  char v36; // [esp+15h] [ebp-17h]
  char v37; // [esp+16h] [ebp-16h]
  bool v38; // [esp+17h] [ebp-15h]
  vostok::resources::query_result *v39; // [esp+18h] [ebp-14h]
  vostok::resources::fs_task *task; // [esp+1Ch] [ebp-10h]
  vostok::resources::resource_base *v41; // [esp+20h] [ebp-Ch]
  vostok::resources::query_result *queries_with_unlocked_fat_it; // [esp+24h] [ebp-8h]
  vostok::resources::query_result *v43; // [esp+28h] [ebp-4h]

  vostok::resources::resources_manager::dispatch_devices(&s_resources_manager_buffer);
  vostok::vfs::virtual_file_system::dispatch_callbacks(v1, &s_resources_manager_buffer.m_vfs.mount_history);
  if ( vostok::resources::g_game_resources_manager.m_initialized )
    vostok::resources::game_resources_manager::tick(v2, (int)vostok::resources::g_game_resources_manager.m_variable);
  if ( s_resources_manager_buffer.m_pending_mount_operations_count
    || (v36 = 1, s_resources_manager_buffer.m_pending_mount_helper_query_count) )
  {
    v36 = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        v4,
                        (unsigned int)&s_resources_manager_buffer,
                        CurrentThreadId,
                        0);
  v7 = thread_local_data && thread_local_data->ready_fs_tasks.m_first;
  v38 = s_resources_manager_buffer.m_fs_tasks.m_first != 0;
  if ( s_resources_manager_buffer.m_vfs.scheduled_to_unmount.m_first.m_object
    || (m_count_of_pending_query_with_fat_it = (vostok::resources::resources_manager *)s_resources_manager_buffer.m_count_of_pending_query_with_fat_it) != 0
    || (m_count_of_pending_query_with_fat_it = (vostok::resources::resources_manager *)s_resources_manager_buffer.m_pending_mount_helper_query_count) != 0
    || (v37 = 1, v7) )
  {
    v37 = 0;
  }
  vostok::resources::resources_manager::init_new_autoselect_quality_queries(
    m_count_of_pending_query_with_fat_it,
    (int)&s_resources_manager_buffer);
  if ( v36 )
    v39 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
            v8,
            (int)&s_resources_manager_buffer.m_new_queries_with_unlocked_fat_it,
            0);
  else
    v39 = 0;
  v43 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
          v8,
          (int)&s_resources_manager_buffer.m_new_queries_with_locked_fat_it,
          0);
  queries_with_unlocked_fat_it = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
                                   v9,
                                   (int)&s_resources_manager_buffer.m_new_inorder_queries,
                                   0);
  v11 = vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
          v10,
          (int)&s_resources_manager_buffer.m_fs_sub_tasks);
  v13 = v11;
  v41 = v11;
  if ( (v37 || v11)
    && (v12 = (vostok::threading::mutex *)&s_resources_manager_buffer,
        _InterlockedExchange(&s_resources_manager_buffer.m_fs_tasks_execute_on_current_tick, 1),
        v37) )
  {
    task = (vostok::resources::fs_task *)vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
                                           (vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&s_resources_manager_buffer,
                                           (int)&s_resources_manager_buffer.m_fs_tasks);
  }
  else
  {
    task = 0;
  }
  if ( !task && !v13 )
  {
    v12 = (vostok::threading::mutex *)&s_resources_manager_buffer;
    _InterlockedExchange(&s_resources_manager_buffer.m_fs_tasks_execute_on_current_tick, 0);
  }
  if ( s_resources_manager_buffer.m_delayed_delete_managed_resources.m_first )
  {
    vostok::threading::mutex::lock(
      v12,
      (_RTL_CRITICAL_SECTION *)&s_resources_manager_buffer.m_delayed_delete_managed_resources.vostok::threading::mutex);
    m_first = s_resources_manager_buffer.m_delayed_delete_managed_resources.m_first;
    s_resources_manager_buffer.m_delayed_delete_managed_resources.m_first = 0;
    s_resources_manager_buffer.m_delayed_delete_managed_resources.m_last = 0;
    s_resources_manager_buffer.m_delayed_delete_managed_resources.m_size = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_delayed_delete_managed_resources.vostok::threading::mutex);
    while ( 1 )
    {
      v15 = m_first;
      if ( !m_first )
        break;
      m_first = m_first->m_next_delay_delete;
      vostok::resources::resources_manager::free_managed_resource(
        v15,
        (vostok::fixed_string<512> *)v12,
        &s_resources_manager_buffer);
    }
  }
  vostok::resources::resources_manager::delete_delayed_unmanaged_resources(
    (vostok::resources::resources_manager *)v12,
    &s_resources_manager_buffer);
  vostok::resources::resources_manager::deallocate_delayed_unmanaged_resources(v16, &s_resources_manager_buffer);
  if ( v37 )
    vostok::resources::resources_manager::execute_fs_tasks(&s_resources_manager_buffer, task);
  v18 = (vostok::resources::fs_task *)v41;
  if ( v41 )
  {
    do
    {
      m_next = v18->m_next;
      vostok::resources::resources_manager::execute_fs_task(&s_resources_manager_buffer, v18, v17);
      v18 = m_next;
    }
    while ( m_next );
  }
  if ( s_resources_manager_buffer.m_fs_tasks_execute_on_current_tick )
  {
    v17 = &s_resources_manager_buffer;
    _InterlockedExchange(&s_resources_manager_buffer.m_fs_tasks_execute_on_current_tick, 0);
  }
  if ( v36
    && s_resources_manager_buffer.m_new_queries_waiting_for_cook_register.m_first
    && !s_resources_manager_buffer.m_num_cook_registrators )
  {
    v20 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
            (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v17,
            (int)&s_resources_manager_buffer.m_new_queries_waiting_for_cook_register,
            0);
    v17 = (vostok::resources::resources_manager *)v39;
    if ( v39 )
      v39->m_next_in_device_manager = v20;
    else
      v39 = v20;
  }
  vostok::resources::resources_manager::init_new_queries(queries_with_unlocked_fat_it, v17, &s_resources_manager_buffer);
  vostok::resources::resources_manager::init_new_queries(v43, v21, &s_resources_manager_buffer);
  if ( v36 )
    vostok::resources::resources_manager::init_new_queries(v39, v22, &s_resources_manager_buffer);
  vostok::resources::resources_manager::dispatch_callbacks(&s_resources_manager_buffer, 0);
  vostok::resources::allocate_functionality::tick(v23, &s_resources_manager_buffer.m_allocate_functionality, 0);
  vostok::resources::resources_manager::dispatch_allocated_raw_resources(v24, &s_resources_manager_buffer);
  M_start = s_resources_manager_buffer.m_device_managers._M_impl._M_start;
  M_finish = s_resources_manager_buffer.m_device_managers._M_impl._M_finish;
  for ( i = s_resources_manager_buffer.m_device_managers._M_impl._M_start; i != M_finish; ++i )
    vostok::resources::device_manager::update((vostok::resources::device_manager *)*i);
  vostok::resources::resources_manager::delete_delayed_unmanaged_resources(
    (vostok::resources::resources_manager *)M_start,
    &s_resources_manager_buffer);
  if ( s_resources_manager_buffer.m_created_resources.m_first )
  {
    _InterlockedExchange(&s_resources_manager_buffer.m_dispatching_created_resources, 1);
    v29 = vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
            (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&s_resources_manager_buffer.m_dispatching_created_resources,
            (int)&s_resources_manager_buffer.m_created_resources,
            0);
    if ( v29 )
    {
      do
      {
        m_next_in_device_manager = v29->m_next_in_device_manager;
        vostok::resources::query_result::on_create_resource_end(v29);
        v29 = m_next_in_device_manager;
      }
      while ( m_next_in_device_manager );
    }
    _InterlockedExchange(&s_resources_manager_buffer.m_dispatching_created_resources, 0);
  }
  vostok::resources::resources_manager::dispatch_decompressed_resources(v28, (int)&s_resources_manager_buffer);
  for ( j = (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(v31, (int)&s_resources_manager_buffer.m_generated_resources_to_save_list, 0);
        j;
        j = (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)j[13].m_on_out_of_memory.vtable )
  {
    vostok::resources::resources_manager::save_generated_resource(j, v32, &s_resources_manager_buffer);
  }
  vostok::resources::resources_manager::delete_name_registry_entries(v32, (int)&s_resources_manager_buffer);
  if ( (unsigned int)vostok::timing::timer::get_elapsed_msec(v34, (int)&s_resources_manager_buffer.m_flush_timer) >= 0x3E8 )
    vostok::timing::timer::start(v35, (LARGE_INTEGER *)&s_resources_manager_buffer.m_flush_timer);
  if ( v36 && (v37 || !v38) )
  {
    s_resources_manager_buffer.m_self_wakeuping = 0;
  }
  else
  {
    if ( !s_resources_manager_buffer.m_self_wakeuping )
    {
      s_resources_manager_buffer.m_self_wakeuping = 1;
      vostok::timing::timer::start(v35, (LARGE_INTEGER *)&s_resources_manager_buffer.m_self_wakeup_timer);
    }
    vostok::resources::resources_manager::wakeup_resources_thread(
      (vostok::resources::resources_manager *)v35,
      (int)&s_resources_manager_buffer);
  }
}
