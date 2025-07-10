BOOL __usercall vostok::resources::resources_manager::thread_can_exit@<eax>(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *a2@<esi>)
{
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v3; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  bool v6; // al

  CurrentThreadId = GetCurrentThreadId();
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(v3, a2, CurrentThreadId, 0);
  if ( !thread_local_data )
    return 1;
  v6 = !thread_local_data->resources_to_deallocate_after_destroy_in_other_thread_count
    && !thread_local_data->delayed_delete_unmanaged_resources.m_first
    && !thread_local_data->deleting_resources
    && !thread_local_data->delayed_deallocate_unmanaged_resources.m_first
    && !thread_local_data->deallocating_resources
    && !thread_local_data->ready_fs_tasks.m_first
    && !thread_local_data->finished_queries.m_first
    && !thread_local_data->to_free_user_buffers.m_first
    && !thread_local_data->queries_with_tasks_finished.m_first
    && !thread_local_data->to_create_resource.m_first;
  return !a2->m_pending_queries_count
      && !*(_DWORD *)((char *)&loc_20444 + (_DWORD)a2)
      && !*(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20415 + 3)
      && !*(_DWORD *)((char *)&loc_2033C + (_DWORD)a2)
      && !*(_DWORD *)((char *)&loc_2036C + (_DWORD)a2)
      && !*(_DWORD *)((char *)&loc_2053C + (_DWORD)a2)
      && !a2->m_fs_tasks_execute_on_current_tick
      && !*(_DWORD *)((char *)&loc_201B0 + (_DWORD)a2)
      && v6;
}
