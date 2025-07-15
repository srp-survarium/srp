void __thiscall vostok::resources::resources_manager::execute_fs_tasks(
        vostok::resources::resources_manager *this,
        vostok::resources::fs_task *task)
{
  vostok::resources::fs_task *v2; // edi
  vostok::resources::fs_task *m_next; // ebx
  vostok::resources::resource_base *v4; // eax

  v2 = task;
  if ( task )
  {
    do
    {
      m_next = v2->m_next;
      if ( v2->m_type == type_mount_composite )
      {
        v4 = vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
               (vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
               (int)&v2[1].m_next);
        vostok::resources::resources_manager::execute_fs_tasks(this, (vostok::resources::fs_task *)v4);
      }
      vostok::resources::resources_manager::execute_fs_task(this, v2, this);
      v2 = m_next;
    }
    while ( m_next );
  }
}
