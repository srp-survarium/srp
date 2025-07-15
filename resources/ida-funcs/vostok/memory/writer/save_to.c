char __userpurge vostok::memory::writer::save_to@<al>(
        vostok::memory::writer *this@<ecx>,
        int a2@<edi>,
        char *fn,
        bool deassociate_resource)
{
  vostok::fs_new::synchronous_device_interface *m_variable; // esi
  const vostok::fs_new::native_path_string *v5; // eax
  char v6; // bl
  vostok::fs_new::device_file_system_no_watcher_proxy *v7; // ecx
  vostok::fs_new::synchronous_device_interface *v9; // [esp+Ch] [ebp-11Ch] BYREF
  void **v10; // [esp+10h] [ebp-118h] BYREF
  vostok::fs_new::native_path_string result; // [esp+14h] [ebp-114h] BYREF

  m_variable = s_core_synchronous_device.m_variable;
  v5 = vostok::fs_new::native_path_string::convert(&result, fn);
  v6 = 0;
  v9 = m_variable;
  vostok::fs_new::open_cached_file(
    m_variable,
    &v10,
    v5,
    create_always,
    write,
    assert_on_fail_true,
    notify_watcher_false);
  if ( v10 )
  {
    vostok::fs_new::device_file_system_no_watcher_proxy::write(
      v7,
      &m_variable->m_device.m_device_file_system,
      v10,
      *(const void **)(a2 + 28),
      *(unsigned int *)(a2 + 40));
    v6 = 1;
  }
  vostok::fs_new::file_type_pointer::close((vostok::fs_new::file_type_pointer *)v7, &v9);
  return v6;
}
