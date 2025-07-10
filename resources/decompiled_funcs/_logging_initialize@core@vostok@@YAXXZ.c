void __cdecl vostok::core::logging_initialize()
{
  vostok::logging::logging_filters_console_command *v0; // eax
  vostok::logging::logging_filters_console_command *v1; // eax
  vostok::fs_new::device_file_system_no_watcher_proxy device; // [esp+8h] [ebp-11Ch] BYREF
  vostok::fs_new::native_path_string log_file_name; // [esp+Ch] [ebp-118h] BYREF

  vostok::core::g_log_filter_tree = vostok::logging::new_filter_tree(&vostok::memory::g_mt_allocator);
  v0 = (vostok::logging::logging_filters_console_command *)pt3malloc((char *)0x48);
  if ( v0 )
  {
    vostok::logging::logging_filters_console_command::logging_filters_console_command(
      v0,
      vostok::core::g_log_filter_tree,
      "logging_rule",
      1,
      command_type_user_specific,
      execution_filter_early);
    s_logging_console_command = v1;
  }
  else
  {
    s_logging_console_command = 0;
  }
  vostok::core::push_logging_filters();
  if ( vostok::core::g_log_file_usage )
  {
    vostok::fs_new::device_file_system_no_watcher_proxy::device_file_system_no_watcher_proxy(
      &device,
      &s_hdd,
      watcher_enabled_true);
    log_file_name.m_string.m_begin = log_file_name.m_string.m_buffer;
    log_file_name.m_string.m_end = log_file_name.m_string.m_buffer;
    log_file_name.m_string.m_max_end = &log_file_name.m_separator;
    log_file_name.m_string.m_buffer[0] = 0;
    log_file_name.m_separator = 92;
    vostok::core::generate_log_file_name((vostok::fs_new::virtual_path_string *)&log_file_name);
    vostok::core::g_log_file = vostok::logging::new_log_file(
                                 &vostok::memory::g_mt_allocator,
                                 &device,
                                 log_file_name.m_string.m_begin,
                                 vostok::core::g_log_file_usage);
  }
}
