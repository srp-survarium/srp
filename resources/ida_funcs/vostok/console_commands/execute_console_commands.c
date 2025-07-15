char __cdecl vostok::console_commands::execute_console_commands(vostok::fs_new::native_path_string cfg_file_path)
{
  vostok::fs_new::synchronous_device_interface *m_variable; // edi
  void *v3; // esp
  vostok::animation::mixing::animation_interval *v4; // eax
  vostok::fs_new::device_file_system_proxy_base *v5; // eax
  int v6; // ecx
  vostok::vfs::base_node<1> *v7; // [esp-10h] [ebp-44h]
  char *m_data; // [esp-Ch] [ebp-40h]
  unsigned __int64 v9; // [esp-8h] [ebp-3Ch]
  unsigned __int8 v10[12]; // [esp+0h] [ebp-34h] BYREF
  vostok::memory::reader F; // [esp+Ch] [ebp-28h] BYREF
  vostok::mutable_buffer buffer; // [esp+18h] [ebp-1Ch] BYREF
  vostok::fs_new::file_type_pointer file; // [esp+20h] [ebp-14h] BYREF
  unsigned __int64 file_size; // [esp+28h] [ebp-Ch] BYREF

  m_variable = s_core_synchronous_device.m_variable;
  file_size = 0;
  if ( !vostok::fs_new::calculate_file_size(
          s_core_synchronous_device.m_variable,
          &file_size,
          &cfg_file_path,
          assert_on_fail_false) )
    return 0;
  vostok::fs_new::file_type_pointer::file_type_pointer(
    &file,
    (vostok::fs_new::open_file_cache *)&cfg_file_path,
    m_variable,
    open_existing,
    read,
    assert_on_fail_true,
    notify_watcher_true,
    use_buffering_true);
  if ( !vostok::vfs::vfs_iterator::operator bool((vostok::vfs::vfs_iterator *)&file) )
  {
    vostok::fs_new::file_type_pointer::~file_type_pointer(&file);
    return 0;
  }
  v3 = alloca(file_size);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &buffer,
    v10,
    file_size);
  v9 = (unsigned int)file_size;
  m_data = buffer.m_data;
  v7 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&file);
  v4 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->(m_variable);
  v5 = (vostok::fs_new::device_file_system_proxy_base *)vostok::animation::mixing::animation_interval::animation(v4);
  vostok::fs_new::device_file_system_proxy_base::read(v5, (void **)&v7->m_mount_root.pointer, m_data, v9);
  F.m_data = (const unsigned __int8 *)buffer.m_data;
  F.m_pointer = (const unsigned __int8 *)buffer.m_data;
  F.m_size = file_size;
  vostok::console_commands::load(&F, v6, execution_filter_early);
  vostok::fs_new::file_type_pointer::~file_type_pointer(&file);
  return 1;
}
