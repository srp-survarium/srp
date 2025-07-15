void __thiscall vostok::resources::resources_manager::execute_fs_tasks(
        vostok::resources::resources_manager *this,
        vostok::resources::fs_task *task)
{
  vostok::resources::fs_task *v2; // esi
  vostok::resources::fs_task *m_next; // edi
  vostok::resources::fs_task *m_type; // ebx

  v2 = task;
  if ( task )
  {
    do
    {
      m_next = v2->m_next;
      if ( v2->m_type == type_mount_composite )
      {
        if ( v2[2].m_type )
        {
          vostok::threading::mutex::lock((vostok::threading::mutex *)&v2[1].m_type);
          m_type = (vostok::resources::fs_task *)v2[2].m_type;
          v2[2].m_type = type_undefined;
          v2[2].m_allocator = 0;
          v2[1].m_next = 0;
          LeaveCriticalSection((LPCRITICAL_SECTION)&v2[1].m_type);
        }
        else
        {
          m_type = 0;
        }
        vostok::resources::resources_manager::execute_fs_tasks(this, m_type);
      }
      vostok::resources::resources_manager::execute_fs_task(this, v2, this);
      v2 = m_next;
    }
    while ( m_next );
  }
}
