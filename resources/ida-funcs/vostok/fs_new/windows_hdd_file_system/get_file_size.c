char __thiscall vostok::fs_new::windows_hdd_file_system::get_file_size(
        vostok::fs_new::windows_hdd_file_system *this,
        _LARGE_INTEGER *out_size,
        HANDLE handle)
{
  _LARGE_INTEGER FileSize; // [esp+0h] [ebp-8h] BYREF

  if ( !GetFileSizeEx(handle, &FileSize) )
    return 0;
  *out_size = FileSize;
  return 1;
}
