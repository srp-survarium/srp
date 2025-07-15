void **__usercall vostok::journaling::open_file@<eax>(
        char *access@<eax>,
        vostok::fs_new::device_file_system_no_watcher_proxy *device,
        char *file_name)
{
  vostok::fixed_string<260> *v4; // ecx
  vostok::fs_new::synchronous_device_interface *v6; // [esp-4h] [ebp-14Ch]
  vostok::fs_new::native_path_string v7; // [esp+Ch] [ebp-13Ch] BYREF
  vostok::fs_new::open_file_params v8; // [esp+120h] [ebp-28h] BYREF
  vostok::fs_new::synchronous_device_interface v9; // [esp+138h] [ebp-10h] BYREF
  void **v10; // [esp+144h] [ebp-4h] BYREF

  v9.m_device = (vostok::fs_new::device_file_system_no_watcher_proxy)device->m_device_file_system;
  v9.m_synchronize_query = 0;
  v9.m_out_of_memory = 0;
  vostok::fs_new::create_folder_r(access, &v9, file_name);
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v6, (int *)&v9);
  v8.access = (vostok::fs_new::file_access::access_enum)access;
  v8.assert_on_fail = assert_on_fail_true;
  v8.notify_watcher = notify_watcher_true;
  v8.mode = access != (char *)2;
  v8.use_buffering = use_buffering_true;
  v8.file_type_allocated_by_user = 0;
  v10 = 0;
  vostok::fixed_string<260>::fixed_string<260>(v4, &v7.m_string, file_name);
  v7.m_separator = 92;
  if ( !vostok::fs_new::device_file_system_no_watcher_proxy::open(device, &v7, &v10, &v8)
    && !debug_macro_helper_ignore_always_25 )
  {
    HIBYTE(device) = 0;
    vostok::debug::on_error(
      (bool *)&device + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\journaling_journal.cpp",
      "vostok::journaling::open_file",
      (const char *)0x1B,
      "cannot open file %s",
      file_name);
    if ( vostok::debug::is_debugger_present() || HIBYTE(device) )
      __debugbreak();
  }
  return v10;
}
