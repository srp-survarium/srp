void vostok::resources::on_resources_thread_started()
{
  vostok::memory::doug_lea_allocator *v0; // ecx
  vostok::timing::timer *v1; // ecx
  vostok::resources::game_resources_manager *v2; // ecx
  vostok::resources::resources_manager *v3; // ecx

  _InterlockedExchange(&s_resources_manager_buffer.m_resources_thread_id, GetCurrentThreadId());
  vostok::memory::doug_lea_allocator::user_current_thread_id(
    (vostok::memory::doug_lea_allocator *)&s_resources_manager_buffer.m_resources_thread_id,
    (int)&vostok::memory::g_resources_helper_allocator);
  vostok::memory::doug_lea_allocator::user_current_thread_id(v0, (int)&vostok::memory::g_resources_unmanaged_allocator);
  vostok::timing::timer::start(v1, (LARGE_INTEGER *)&s_resources_manager_buffer.m_flush_timer);
  vostok::resources::initialize_game_resources_manager(v2);
  if ( s_resources_manager_buffer.m_do_mount_mounts_path )
  {
    s_resources_manager_buffer.m_vfs.unmount_thread_id = GetCurrentThreadId();
    vostok::resources::resources_manager::do_mount_mounts_path(v3);
    s_resources_manager_buffer.m_do_mount_mounts_path = 0;
  }
}
