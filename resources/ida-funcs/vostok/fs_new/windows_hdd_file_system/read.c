unsigned __int64 __thiscall vostok::fs_new::windows_hdd_file_system::read(
        vostok::fs_new::windows_hdd_file_system *this,
        HANDLE handle,
        void *data,
        unsigned __int64 size)
{
  unsigned int NumberOfBytesRead; // [esp+0h] [ebp-4h] BYREF

  NumberOfBytesRead = 0;
  ReadFile(handle, data, size, &NumberOfBytesRead, 0);
  return NumberOfBytesRead;
}
