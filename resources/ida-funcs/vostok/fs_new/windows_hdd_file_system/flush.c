// attributes: thunk
BOOL __stdcall vostok::fs_new::windows_hdd_file_system::flush(HANDLE hFile)
{
  return FlushFileBuffers(hFile);
}
