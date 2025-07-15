char __thiscall vostok::fs_new::windows_hdd_file_system::find_next(
        vostok::fs_new::windows_hdd_file_system *this,
        unsigned __int64 *in_out_search_handle,
        vostok::fs_new::physical_path_info_data *out_data)
{
  _finddata32i64_t pfd; // [esp+8h] [ebp-120h] BYREF

  if ( _findnext32i64(*(HANDLE *)in_out_search_handle, &pfd) == -1 )
  {
    *(_DWORD *)in_out_search_handle = -1;
    *((_DWORD *)in_out_search_handle + 1) = -1;
    return 0;
  }
  else
  {
    vostok::fs_new::init_from_os_struct(out_data, &pfd);
    return 1;
  }
}
