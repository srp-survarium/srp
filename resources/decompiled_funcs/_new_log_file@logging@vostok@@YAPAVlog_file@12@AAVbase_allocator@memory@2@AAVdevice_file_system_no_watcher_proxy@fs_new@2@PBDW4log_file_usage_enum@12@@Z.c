vostok::logging::log_file *__cdecl vostok::logging::new_log_file(
        vostok::memory::base_allocator *allocator,
        vostok::fs_new::device_file_system_no_watcher_proxy *device,
        const char *log_file_name,
        vostok::logging::log_file_usage_enum log_file_usage)
{
  survarium::game_camera *v4; // ecx
  vostok::memory::base_allocator *v5; // eax
  int v6; // eax
  void *_Where; // [esp+4h] [ebp-Ch]
  vostok::logging::log_file *v10; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize(v4);
  _Where = vostok::memory::base_allocator::malloc_impl(v5, 0x4680u);
  v10 = (vostok::logging::log_file *)operator new(0x4680u, _Where);
  if ( !v10 )
    return 0;
  vostok::logging::log_file::log_file(
    v10,
    allocator,
    log_file_usage,
    log_file_name,
    (vostok::fs_new::device_file_system_no_watcher_proxy)device->m_device_file_system);
  return (vostok::logging::log_file *)v6;
}
