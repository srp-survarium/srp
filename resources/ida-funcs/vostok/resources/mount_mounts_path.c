void __usercall vostok::resources::mount_mounts_path(char *mounts_path@<eax>)
{
  vostok::command_line::key *v1; // ecx
  vostok::command_line::key *v2; // ecx
  char *v3; // [esp+4h] [ebp-4h] BYREF

  v3 = mounts_path;
  if ( mounts_path )
  {
    vostok::fs_new::path_string_impl::assign_with_conversion<char const *>(
      &s_resources_manager_buffer.m_mounts_path,
      &v3);
    _InterlockedExchange(&s_resources_manager_buffer.m_do_mount_mounts_path, 1);
    SetEvent(*(HANDLE *)s_resources_manager_buffer.m_resources_wakeup_event.m_event.m_event);
    if ( vostok::command_line::key::is_set(v1, (int)&vostok::threading::g_debug_single_thread) )
      vostok::resources::tick(v2);
  }
  else
  {
    _InterlockedExchange(&s_resources_manager_buffer.m_do_mount_mounts_path, 0);
  }
}
