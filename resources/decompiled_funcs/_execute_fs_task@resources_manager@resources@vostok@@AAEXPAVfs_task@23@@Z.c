void __usercall vostok::resources::resources_manager::execute_fs_task(
        vostok::resources::resources_manager *this@<eax>,
        vostok::resources::fs_task *task@<esi>,
        vostok::resources::resources_manager *a3@<ecx>)
{
  vostok::resources::fs_task::type_enum m_type; // eax
  char v5; // bl
  vostok::resources::resources_manager *v6; // ecx

  m_type = task->m_type;
  if ( m_type <= type_mount_operations_start || m_type >= type_mount_operations_end )
  {
    v5 = 0;
  }
  else
  {
    v5 = 1;
    while ( *(_UNKNOWN **)((char *)&off_20378 + (_DWORD)this) )
    {
      vostok::resources::resources_manager::delete_delayed_unmanaged_resources(a3, this);
      vostok::resources::resources_manager::deallocate_delayed_unmanaged_resources(v6, this);
      if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
      {
        vostok::threading::g_debug_single_thread.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( vostok::threading::g_debug_single_thread.m_type != type_recursive )
        vostok::resources::dispatch_callbacks(a3);
    }
  }
  task->execute_may_destroy_this(task);
  if ( v5 )
    _InterlockedExchangeAdd((volatile signed __int32 *)((char *)&loc_201B0 + (_DWORD)this), 0xFFFFFFFF);
}
