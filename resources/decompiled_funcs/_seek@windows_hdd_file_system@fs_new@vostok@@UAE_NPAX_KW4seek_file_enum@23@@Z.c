char __thiscall vostok::fs_new::windows_hdd_file_system::seek(
        vostok::fs_new::windows_hdd_file_system *this,
        void *handle,
        unsigned __int64 in_offset,
        vostok::fs_new::seek_file_enum origin)
{
  BOOL v4; // eax

  if ( origin )
  {
    if ( origin == seek_file_current )
      v4 = SetFilePointerEx(handle, (LARGE_INTEGER)in_offset, 0, 1u);
    else
      v4 = SetFilePointerEx(handle, (LARGE_INTEGER)in_offset, 0, 2u);
  }
  else
  {
    v4 = SetFilePointerEx(handle, (LARGE_INTEGER)in_offset, 0, 0);
  }
  if ( v4 )
    return 1;
  vostok::fs_new::log_last_error(
    (const char *)&stru_955E40.m_fat_it.m_type,
    (survarium::game_camera *)&stru_955E40.vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags);
  return 0;
}
