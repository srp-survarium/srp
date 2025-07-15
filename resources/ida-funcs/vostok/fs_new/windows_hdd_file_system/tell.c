_LARGE_INTEGER __thiscall vostok::fs_new::windows_hdd_file_system::tell(
        vostok::fs_new::windows_hdd_file_system *this,
        void *handle)
{
  _LARGE_INTEGER out; // [esp+4h] [ebp-10h] BYREF
  _LARGE_INTEGER offset; // [esp+Ch] [ebp-8h]

  offset.QuadPart = 0;
  if ( SetFilePointerEx(handle, 0, &out, 1u) )
  {
    return out;
  }
  else
  {
    vostok::fs_new::log_last_error(
      (const char *)&stru_955E40.m_fat_it.m_type,
      (survarium::game_camera *)&stru_955E40.m_deleter);
    return 0;
  }
}
