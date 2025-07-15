void __thiscall vostok::fs_new::windows_hdd_file_system::find_close(
        vostok::fs_new::windows_hdd_file_system *this,
        unsigned __int64 search_handle)
{
  _findclose((HANDLE)search_handle);
}
