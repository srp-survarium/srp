bool __thiscall vostok::fs_new::windows_hdd_file_system::find_first(
        vostok::fs_new::windows_hdd_file_system *this,
        unsigned __int64 *out_search_handle,
        vostok::fs_new::physical_path_info_data *out_data,
        char *absolute_native_physical_path_mask)
{
  int v5; // edi
  bool result; // al
  _finddata32i64_t pfd; // [esp+10h] [ebp-120h] BYREF

  v5 = _findfirst32i64(absolute_native_physical_path_mask, &pfd);
  if ( v5 == -1 )
  {
    result = 0;
  }
  else
  {
    do
    {
      if ( pfd.name[0] != 46 )
      {
        *out_search_handle = v5;
        vostok::fs_new::init_from_os_struct(out_data, &pfd);
        return 1;
      }
    }
    while ( _findnext32i64((HANDLE)v5, &pfd) != -1 );
    ((void (__thiscall *)(vostok::fs_new::windows_hdd_file_system *, int, int))this->find_close)(this, v5, v5 >> 31);
    result = 1;
  }
  *(_DWORD *)out_search_handle = -1;
  *((_DWORD *)out_search_handle + 1) = -1;
  return result;
}
