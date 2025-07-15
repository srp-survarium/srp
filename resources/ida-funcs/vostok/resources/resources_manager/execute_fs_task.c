void __usercall vostok::resources::resources_manager::execute_fs_task(
        vostok::resources::resources_manager *this@<eax>,
        vostok::resources::fs_task *task@<esi>,
        vostok::resources::resources_manager *a3@<ecx>)
{
  vostok::resources::fs_task::type_enum m_type; // eax
  char v5; // bl
  vostok::resources::resources_manager *v6; // ecx
  vostok::command_line::key *v7; // ecx

  m_type = task->m_type;
  if ( m_type <= type_mount_operations_start || m_type >= type_mount_operations_end )
  {
    v5 = 0;
  }
  else
  {
    v5 = 1;
    while ( *(int *)((char *)&dword_20380 + (_DWORD)this) )
    {
      vostok::resources::resources_manager::delete_delayed_unmanaged_resources(a3, this);
      vostok::resources::resources_manager::deallocate_delayed_unmanaged_resources(v6, this);
      if ( vostok::command_line::key::is_set(v7, (int)&vostok::threading::g_debug_single_thread) )
        vostok::resources::dispatch_callbacks((vostok::command_line::key *)a3);
    }
  }
  task->execute_may_destroy_this(task);
  if ( v5 )
    _InterlockedExchangeAdd((volatile signed __int32 *)((char *)&dword_201B8 + (_DWORD)this), 0xFFFFFFFF);
}
