void __cdecl vostok::logging::new_log_file(vostok::logging::base_allocator *log_file_name)
{
  vostok::logging::fs_new_device_impl *v1; // ebx
  vostok::threading::mutex_tasks_unaware *v2; // esi
  vostok::logging::memory_base_allocator_wrapper *v3; // ebp
  vostok::logging::log_file *v4; // edi

  v1 = s_logging_fs_device_impl;
  v2 = (vostok::threading::mutex_tasks_unaware *)vostok::core::g_log_file_usage;
  v3 = s_logging_allocator_wrapper;
  v4 = (vostok::logging::log_file *)((int (__stdcall *)(int))s_logging_allocator_wrapper->allocate)(17504);
  if ( v4 )
    vostok::logging::log_file::log_file(v4, v2, v1, v3, (char *)log_file_name);
}
