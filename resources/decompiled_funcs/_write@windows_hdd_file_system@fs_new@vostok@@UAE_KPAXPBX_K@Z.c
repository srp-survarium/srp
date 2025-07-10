unsigned __int64 __thiscall vostok::fs_new::windows_hdd_file_system::write(
        vostok::fs_new::windows_hdd_file_system *this,
        void *handle,
        const void *data,
        unsigned __int64 size)
{
  unsigned int bytes_written; // [esp+8h] [ebp-4h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  bytes_written = 0;
  if ( !WriteFile(handle, data, size, &bytes_written, 0) )
    vostok::fs_new::log_last_error((const char *)&stru_955E40.m_fat_it.m_type, (survarium::game_camera *)"write_file");
  return bytes_written;
}
