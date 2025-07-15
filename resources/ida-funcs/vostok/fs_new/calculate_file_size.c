char __usercall vostok::fs_new::calculate_file_size@<al>(
        const vostok::fs_new::synchronous_device_interface *device@<eax>,
        unsigned __int64 *const out_file_size@<edi>,
        const vostok::fs_new::native_path_string *physical_path,
        assert_on_fail_bool assert_on_fail)
{
  vostok::fs_new::device_file_system_no_watcher_proxy *p_m_device; // esi
  char result; // al
  vostok::fs_new::device_file_system_proxy_base *v6; // ecx
  __int64 v7; // rax
  vostok::fs_new::device_file_system_interface *m_device_file_system; // ecx
  void **v9; // [esp-4h] [ebp-Ch]
  vostok::fs_new::use_buffering_bool v10; // [esp+0h] [ebp-8h]
  void **v11; // [esp+4h] [ebp-4h] BYREF

  v11 = 0;
  p_m_device = &device->m_device;
  result = vostok::fs_new::device_file_system_no_watcher_proxy::open(
             &device->m_device,
             open_existing,
             &v11,
             physical_path,
             read,
             assert_on_fail,
             notify_watcher_true,
             v10);
  if ( result )
  {
    vostok::fs_new::device_file_system_proxy_base::seek(v6, p_m_device, v11, 0, seek_file_end);
    v7 = p_m_device->m_device_file_system->tell(p_m_device->m_device_file_system, v11);
    m_device_file_system = p_m_device->m_device_file_system;
    v9 = v11;
    *(_DWORD *)out_file_size = v7;
    LODWORD(v7) = (vostok::fs_new::device_file_system_interface)m_device_file_system->__vftable;
    *((_DWORD *)out_file_size + 1) = HIDWORD(v7);
    (*(void (__thiscall **)(vostok::fs_new::device_file_system_interface *, void **))(v7 + 8))(m_device_file_system, v9);
    return 1;
  }
  return result;
}
