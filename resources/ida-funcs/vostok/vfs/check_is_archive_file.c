char __usercall vostok::vfs::check_is_archive_file@<al>(
        vostok::fs_new::synchronous_device_interface *device@<eax>,
        vostok::fixed_string<260> *a2@<ecx>,
        char *physical_path)
{
  char v4; // bl
  vostok::fs_new::file_type_pointer *v5; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *p_m_device; // edi
  vostok::fs_new::device_file_system_proxy_base *v8; // ecx
  int v9; // edx
  vostok::fs_new::device_file_system_proxy_base *v10; // ecx
  vostok::fs_new::device_file_system_proxy_base *v11; // ecx
  vostok::fs_new::native_path_string v12; // [esp+10h] [ebp-174h] BYREF
  vostok::buffer_string v13; // [esp+124h] [ebp-60h] BYREF
  char v14[12]; // [esp+130h] [ebp-54h] BYREF
  vostok::buffer_string v15; // [esp+13Ch] [ebp-48h] BYREF
  char v16[12]; // [esp+148h] [ebp-3Ch] BYREF
  const char *v17; // [esp+154h] [ebp-30h]
  char *v18; // [esp+158h] [ebp-2Ch]
  char *v19; // [esp+15Ch] [ebp-28h]
  _BYTE v20[10]; // [esp+160h] [ebp-24h] BYREF
  char v21; // [esp+16Ah] [ebp-1Ah] BYREF
  char v22; // [esp+16Bh] [ebp-19h] BYREF
  int v23; // [esp+16Ch] [ebp-18h] BYREF
  int v24; // [esp+170h] [ebp-14h] BYREF
  vostok::fs_new::synchronous_device_interface *v25; // [esp+174h] [ebp-10h] BYREF
  void **v26; // [esp+178h] [ebp-Ch] BYREF
  char v27; // [esp+17Eh] [ebp-6h]
  char v28[5]; // [esp+17Fh] [ebp-5h] BYREF

  vostok::fixed_string<260>::fixed_string<260>(a2, &v12.m_string, physical_path);
  v4 = 0;
  v12.m_separator = 92;
  v25 = device;
  vostok::fs_new::open_cached_file(device, &v26, &v12, open_existing, read, assert_on_fail_false, notify_watcher_true);
  if ( v26 )
  {
    v23 = (int)"";
    v24 = 11;
    vostok::buffer_string::buffer_string(
      v14,
      (const unsigned int *)&v24,
      &v13,
      (char **)&big_endian_string_0,
      (const char **)&v23);
    v24 = (int)&off_7FCE86;
    v23 = 11;
    vostok::buffer_string::buffer_string(
      v16,
      (const unsigned int *)&v23,
      &v15,
      (char **)&little_endian_string,
      (const char **)&v24);
    v17 = v20;
    v19 = &v22;
    v18 = &v21;
    p_m_device = &device->m_device;
    v20[0] = 0;
    v21 = 0;
    v27 = 0;
    if ( vostok::fs_new::device_file_system_proxy_base::read(v8, p_m_device, v26, v20, 0xAu) != 10
      || v9
      || vostok::detail::strcmp_s(v17, v13.m_begin) && vostok::detail::strcmp_s(v17, v15.m_begin)
      || (v27 = 1,
          vostok::fs_new::device_file_system_proxy_base::seek(v10, p_m_device, v26, 0x400u, seek_file_begin),
          v28[0] = 0,
          vostok::fs_new::device_file_system_proxy_base::read(v11, p_m_device, v26, v28, 1u),
          v28[0] == 13) )
    {
      v4 = v27;
    }
    vostok::fs_new::file_type_pointer::close((vostok::fs_new::file_type_pointer *)v10, &v25);
    return v4;
  }
  else
  {
    vostok::fs_new::file_type_pointer::close(v5, &v25);
    return 0;
  }
}
