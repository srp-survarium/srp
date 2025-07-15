unsigned __int64 __thiscall vostok::fs_new::windows_hdd_file_system::write(
        vostok::fs_new::windows_hdd_file_system *this,
        HANDLE handle,
        LPCVOID data,
        unsigned __int64 size)
{
  unsigned int NumberOfBytesWritten; // [esp+0h] [ebp-4h] BYREF

  NumberOfBytesWritten = 0;
  WriteFile(handle, data, size, &NumberOfBytesWritten, 0);
  return NumberOfBytesWritten;
}
