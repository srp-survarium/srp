char __usercall vostok::fs_new::create_folder_r@<al>(
        char *a1@<esi>,
        const vostok::fs_new::synchronous_device_interface *device,
        const vostok::fs_new::native_path_string *path,
        bool create_last)
{
  char result; // al
  int v5; // eax
  int v6; // eax
  int v7; // esi
  char v8; // [esp+Fh] [ebp-399h]
  vostok::fs_new::path_part_iterator v9; // [esp+10h] [ebp-398h] BYREF
  char *end; // [esp+28h] [ebp-380h] BYREF
  char *begin; // [esp+2Ch] [ebp-37Ch] BYREF
  _DWORD v12[6]; // [esp+30h] [ebp-378h] BYREF
  vostok::fs_new::path_part_iterator v13; // [esp+48h] [ebp-360h] BYREF
  vostok::fs_new::native_path_string v14; // [esp+60h] [ebp-348h] BYREF
  vostok::fs_new::native_path_string v15; // [esp+178h] [ebp-230h] BYREF
  vostok::fs_new::native_path_string v16; // [esp+290h] [ebp-118h] BYREF

  vostok::fs_new::native_path_string::native_path_string(&v15);
  result = vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
             path,
             a1,
             &v15,
             assert_on_fail_true);
  if ( result )
  {
    strchr(v15.m_string.m_begin, 0x3Au);
    if ( v5 )
      v6 = v5 - (unsigned int)v15.m_string.m_begin;
    else
      v6 = -1;
    v7 = v6 + 2;
    vostok::fs_new::native_path_string::native_path_string(&v14);
    begin = v15.m_string.m_begin;
    end = &v15.m_string.m_begin[v7];
    vostok::fs_new::path_string_impl::assign<char const *>(
      (vostok::fs_new::path_string_impl *)&v15.m_string.m_begin[v7],
      &v14.m_string,
      &begin,
      (const char **)&end);
    v9.m_include_empty_string_in_iteration = include_empty_string_in_iteration_false;
    v9.m_path_str = &v15.m_string.m_begin[v7];
    v9.m_cur_str = &v15.m_string.m_begin[v7];
    v9.m_cur_end = &v15.m_string.m_begin[v7];
    v9.m_separator = 92;
    v9.m_path_end = v15.m_string.m_end;
    vostok::fs_new::path_part_iterator::operator++((vostok::fs_new::path_part_iterator *)v15.m_string.m_begin, (int)&v9);
    vostok::fs_new::path_part_iterator::path_part_iterator(&v13, 0, include_empty_string_in_iteration_false, 0);
    v8 = 1;
    while ( vostok::fs_new::path_part_iterator::operator!=(&v9, &v13) )
    {
      vostok::fs_new::native_path_string::native_path_string(&v16);
      if ( v9.m_cur_str != v9.m_cur_end )
        vostok::buffer_string::append(
          &v16.m_string,
          v9.m_cur_end,
          (char *)&v9.m_cur_str[*v9.m_cur_str == v9.m_separator]);
      vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(&v16, &v14.m_string);
      qmemcpy(v12, &v9, sizeof(v12));
      vostok::fs_new::path_part_iterator::operator++(0, (int)v12);
      if ( !create_last && v12[0] == v13.m_include_empty_string_in_iteration && (const char *)v12[3] == v13.m_cur_str )
        break;
      v8 &= ((int (__thiscall *)(vostok::fs_new::device_file_system_interface *, vostok::fs_new::native_path_string *))device->m_device.m_device_file_system->create_folder)(
              device->m_device.m_device_file_system,
              &v14);
      *v14.m_string.m_end++ = 92;
      *v14.m_string.m_end = 0;
      qmemcpy(&v9, v12, sizeof(v9));
    }
    return v8;
  }
  return result;
}


char __usercall vostok::fs_new::create_folder_r@<al>(
        char *a1@<esi>,
        const vostok::fs_new::synchronous_device_interface *device,
        char *path)
{
  const vostok::fs_new::native_path_string *v3; // eax
  vostok::fs_new::native_path_string result; // [esp+0h] [ebp-114h] BYREF

  v3 = vostok::fs_new::native_path_string::convert(&result, path);
  return vostok::fs_new::create_folder_r(a1, device, v3, 0);
}
