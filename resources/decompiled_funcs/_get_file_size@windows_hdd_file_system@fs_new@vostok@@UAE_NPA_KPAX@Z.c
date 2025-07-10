char __thiscall vostok::fs_new::windows_hdd_file_system::get_file_size(
        vostok::fs_new::windows_hdd_file_system *this,
        _LARGE_INTEGER *out_size,
        void *handle)
{
  _LARGE_INTEGER out; // [esp+4h] [ebp-8h] BYREF

  if ( GetFileSizeEx(handle, &out) )
  {
    *out_size = out;
    return 1;
  }
  else
  {
    vostok::fs_new::log_last_error(
      (const char *)&stru_955E40.m_fat_it.m_type,
      (survarium::game_camera *)&stru_955E40.m_construct_thread_id);
    return 0;
  }
}
