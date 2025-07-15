BOOL __thiscall vostok::resources::resources_manager::thread_can_exit(vostok::resources::resources_manager *this)
{
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v2; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  bool v5; // al

  CurrentThreadId = GetCurrentThreadId();
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        v2,
                        (unsigned int)&s_resources_manager_buffer,
                        CurrentThreadId,
                        0);
  if ( !thread_local_data )
    return 1;
  v5 = !thread_local_data->resources_to_deallocate_after_destroy_in_other_thread_count
    && !thread_local_data->delayed_delete_unmanaged_resources.m_first
    && !thread_local_data->deleting_resources
    && !thread_local_data->delayed_deallocate_unmanaged_resources.m_first
    && !thread_local_data->deallocating_resources
    && !thread_local_data->ready_fs_tasks.m_first
    && !thread_local_data->finished_queries.m_first
    && !thread_local_data->to_free_user_buffers.m_first
    && !thread_local_data->queries_with_tasks_finished.m_first
    && !thread_local_data->to_create_resource.m_first;
  return !s_resources_manager_buffer.m_pending_queries_count
      && !s_resources_manager_buffer.m_created_resources.m_first
      && !s_resources_manager_buffer.m_dispatching_created_resources
      && !s_resources_manager_buffer.m_delayed_delete_managed_resources.m_first
      && !s_resources_manager_buffer.m_delayed_delete_unmanaged_resources.m_first
      && !s_resources_manager_buffer.m_fs_tasks.m_first
      && !s_resources_manager_buffer.m_fs_tasks_execute_on_current_tick
      && !s_resources_manager_buffer.m_pending_mount_operations_count
      && v5;
}
