void __thiscall vostok::journaling::journal::flush(vostok::journaling::journal *this, char *in_file_name, char *src)
{
  char *v3; // edi
  vostok::fs_new::synchronous_device_interface *v4; // ecx
  vostok::fs_new::synchronous_device_interface *v5; // ecx
  vostok::fs_new::device_file_system_proxy_base *v6; // ecx
  unsigned __int64 v7; // rax
  vostok::fs_new::device_file_system_no_watcher_proxy *v8; // ecx
  vostok::fs_new::device_file_system_proxy_base *v9; // [esp-4h] [ebp-113Ch]
  vostok::fs_new::synchronous_device_interface v10; // [esp+Ch] [ebp-112Ch] BYREF
  vostok::fs_new::synchronous_device_interface *v11; // [esp+18h] [ebp-1120h] BYREF
  void **v12; // [esp+1Ch] [ebp-111Ch] BYREF
  vostok::fs_new::native_path_string result; // [esp+20h] [ebp-1118h] BYREF
  _BYTE v14[4096]; // [esp+138h] [ebp-1000h] BYREF

  v3 = in_file_name + 4;
  (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)in_file_name + 1) + 12))(
    *((_DWORD *)in_file_name + 1),
    *((_DWORD *)in_file_name + 2));
  if ( src && _stricmp(in_file_name + 32, src) )
  {
    vostok::fs_new::device_file_system_proxy_base::seek(v9, v3, *((void ***)in_file_name + 2), 0, seek_file_begin);
    vostok::fs_new::native_path_string::convert(&result, src);
    v10.m_device.m_device_file_system = *(vostok::fs_new::device_file_system_interface **)v3;
    v10.m_synchronize_query = 0;
    v10.m_out_of_memory = 0;
    vostok::fs_new::create_folder_r(in_file_name, &v10, &result, 0);
    vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v4, (int *)&v10);
    v10.m_device.m_device_file_system = *(vostok::fs_new::device_file_system_interface **)v3;
    v11 = &v10;
    v10.m_synchronize_query = 0;
    v10.m_out_of_memory = 0;
    vostok::fs_new::open_cached_file(
      &v10,
      &v12,
      &result,
      create_always,
      write,
      assert_on_fail_false,
      notify_watcher_false);
    vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v5, (int *)&v10);
    if ( v12 )
    {
      while ( 1 )
      {
        LODWORD(v7) = vostok::fs_new::device_file_system_proxy_base::read(
                        v6,
                        v3,
                        *((void ***)in_file_name + 2),
                        v14,
                        0x1000u);
        if ( v7 != 4096 )
          break;
        vostok::fs_new::device_file_system_no_watcher_proxy::write(v8, v3, v12, v14, 0x1000u);
      }
      vostok::fs_new::device_file_system_no_watcher_proxy::write(v8, v3, v12, v14, v7);
    }
    vostok::fs_new::file_type_pointer::close((vostok::fs_new::file_type_pointer *)v6, &v11);
  }
}
