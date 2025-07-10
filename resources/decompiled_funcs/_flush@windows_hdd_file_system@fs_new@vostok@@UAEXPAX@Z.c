void __thiscall vostok::fs_new::windows_hdd_file_system::flush(
        vostok::fs_new::windows_hdd_file_system *this,
        void *handle)
{
  if ( !FlushFileBuffers(handle) )
    vostok::fs_new::log_last_error((const char *)&stru_955E40.m_fat_it.m_type, (survarium::game_camera *)"flush_file");
}
