unsigned __int64 __thiscall vostok::fs_new::windows_hdd_file_system::read(
        vostok::fs_new::windows_hdd_file_system *this,
        void *handle,
        void *data,
        unsigned __int64 size)
{
  unsigned int bytes_read; // [esp+4h] [ebp-4h] BYREF

  bytes_read = 0;
  if ( !ReadFile(handle, data, size, &bytes_read, 0) )
    vostok::fs_new::log_last_error((const char *)&stru_955E40.m_fat_it.m_type, (survarium::game_camera *)"read_file");
  return bytes_read;
}
