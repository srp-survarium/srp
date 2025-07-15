bool __thiscall vostok::fs_new::windows_hdd_file_system::seek(
        vostok::fs_new::windows_hdd_file_system *this,
        HANDLE handle,
        LARGE_INTEGER in_offset,
        vostok::fs_new::seek_file_enum origin)
{
  DWORD v4; // edx

  v4 = 0;
  if ( origin )
  {
    LOBYTE(v4) = origin != seek_file_current;
    ++v4;
  }
  return SetFilePointerEx(handle, in_offset, 0, v4);
}
