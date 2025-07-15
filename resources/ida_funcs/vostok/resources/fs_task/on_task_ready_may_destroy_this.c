void __usercall vostok::resources::fs_task::on_task_ready_may_destroy_this(
        vostok::resources::fs_task *this@<ecx>,
        vostok::resources::fs_task *a2@<eax>)
{
  unsigned int m_thread_id; // edi
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v5; // ecx
  bool *v6; // [esp+0h] [ebp-8h]

  m_thread_id = a2->m_thread_id;
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        (vostok::resources::resources_manager *)this,
                        (unsigned int)vostok::resources::g_resources_manager.m_variable,
                        m_thread_id);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    v5,
    &thread_local_data->ready_fs_tasks.m_size,
    a2,
    v6);
  if ( m_thread_id == *(int *)((char *)&dword_203CC + (unsigned int)vostok::resources::g_resources_manager.m_variable) )
  {
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + (unsigned int)vostok::resources::g_resources_manager.m_variable));
  }
  else if ( m_thread_id == *(_DWORD *)&byte_203D8[(unsigned int)vostok::resources::g_resources_manager.m_variable] )
  {
    SetEvent(*(HANDLE *)((char *)&dword_203E0 + (unsigned int)vostok::resources::g_resources_manager.m_variable));
  }
}
