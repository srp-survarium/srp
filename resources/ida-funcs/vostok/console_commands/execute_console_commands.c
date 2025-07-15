char __cdecl vostok::console_commands::execute_console_commands(vostok::fs_new::native_path_string cfg_file_path)
{
  vostok::fs_new::synchronous_device_interface *m_variable; // ebx
  char result; // al
  vostok::fs_new::device_file_system_proxy_base *v3; // ecx
  char v4; // bl
  const unsigned __int8 *m_data; // edi
  void *v6; // esp
  vostok::fs_new::device_file_system_proxy_base *v7; // [esp-4h] [ebp-30h]
  _BYTE v8[16]; // [esp+0h] [ebp-2Ch] BYREF
  vostok::memory::reader out_file_size; // [esp+10h] [ebp-1Ch] BYREF
  vostok::fs_new::synchronous_device_interface *v10; // [esp+20h] [ebp-Ch] BYREF
  void **v11; // [esp+24h] [ebp-8h] BYREF

  m_variable = s_core_synchronous_device.m_variable;
  *(_QWORD *)&out_file_size.m_data = 0;
  result = vostok::fs_new::calculate_file_size(
             s_core_synchronous_device.m_variable,
             (unsigned __int64 *const)&out_file_size,
             &cfg_file_path,
             assert_on_fail_false);
  if ( result )
  {
    v10 = m_variable;
    vostok::fs_new::open_cached_file(
      m_variable,
      &v11,
      &cfg_file_path,
      open_existing,
      read,
      assert_on_fail_true,
      notify_watcher_true);
    if ( v11 )
    {
      m_data = out_file_size.m_data;
      v6 = alloca((int)out_file_size.m_data);
      vostok::fs_new::device_file_system_proxy_base::read(
        v3,
        &m_variable->m_device.m_device_file_system,
        v11,
        v8,
        (unsigned int)out_file_size.m_data);
      out_file_size.m_data = v8;
      out_file_size.m_pointer = v8;
      out_file_size.m_size = (unsigned int)m_data;
      vostok::console_commands::load(&out_file_size, execution_filter_early, 2u);
      v3 = v7;
      v4 = 1;
    }
    else
    {
      v4 = 0;
    }
    vostok::fs_new::file_type_pointer::close((vostok::fs_new::file_type_pointer *)v3, &v10);
    return v4;
  }
  return result;
}
