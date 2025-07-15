void __userpurge vostok::resources::resources_manager::execute_fs_sub_tasks(
        vostok::resources::fs_task *task@<eax>,
        vostok::resources::resources_manager *a2@<ecx>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::fs_task *v3; // esi
  vostok::resources::fs_task *m_next; // edi

  v3 = task;
  if ( task )
  {
    do
    {
      m_next = v3->m_next;
      vostok::resources::resources_manager::execute_fs_task(this, v3, a2);
      v3 = m_next;
    }
    while ( m_next );
  }
}
