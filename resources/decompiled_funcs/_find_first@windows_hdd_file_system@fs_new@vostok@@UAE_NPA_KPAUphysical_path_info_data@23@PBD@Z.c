char __thiscall vostok::fs_new::windows_hdd_file_system::find_first(
        vostok::fs_new::windows_hdd_file_system *this,
        unsigned __int64 *out_search_handle,
        vostok::fs_new::physical_path_info_data *out_data,
        const char *absolute_native_physical_path_mask)
{
  int handle; // [esp+4h] [ebp-124h]
  _finddata32i64_t file_desc; // [esp+8h] [ebp-120h] BYREF

  handle = _findfirst32i64(absolute_native_physical_path_mask, &file_desc);
  if ( handle == -1 )
  {
    *(_DWORD *)out_search_handle = -1;
    *((_DWORD *)out_search_handle + 1) = -1;
    return 0;
  }
  else
  {
    while ( file_desc.name[0] == 46 )
    {
      if ( _findnext32i64((void *)handle, &file_desc) == -1 )
      {
        ((void (__thiscall *)(vostok::fs_new::windows_hdd_file_system *, int, int))this->find_close)(
          this,
          handle,
          handle >> 31);
        *(_DWORD *)out_search_handle = -1;
        *((_DWORD *)out_search_handle + 1) = -1;
        return 1;
      }
    }
    *out_search_handle = handle;
    vostok::fs_new::init_from_os_struct(out_data, &file_desc);
    return 1;
  }
}
