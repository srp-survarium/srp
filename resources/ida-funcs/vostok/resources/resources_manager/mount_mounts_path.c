void __usercall vostok::resources::resources_manager::mount_mounts_path(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>,
        vostok::resources *mounts_path)
{
  vostok::resources::resources_manager *v4; // eax

  if ( this )
  {
    v4 = *(vostok::resources::resources_manager **)(a2 + 16);
    if ( v4 != this )
    {
      *(_DWORD *)(a2 + 20) = v4;
      LOBYTE(v4->m_fs_tasks_execute_on_current_tick) = 0;
      vostok::buffer_string::operator+=((vostok::buffer_string *)(a2 + 16), (const char *)this);
    }
    vostok::fs_new::path_string_impl::convert(
      (vostok::fs_new::path_string_impl *)(a2 + 16),
      *(char **)(a2 + 16),
      *(char **)(a2 + 20));
    _InterlockedExchange((volatile __int32 *)(a2 + 292), 1);
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + a2));
    if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
    {
      vostok::threading::g_debug_single_thread.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( vostok::threading::g_debug_single_thread.m_type != type_recursive )
      vostok::resources::tick(mounts_path);
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(a2 + 292), 0);
  }
}
