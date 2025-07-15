int __usercall vostok::tasks::thread_pool::execute_children@<eax>(
        vostok::tasks::thread_pool *this@<esi>,
        vostok::tasks::task *m_begin@<ecx>)
{
  vostok::tasks::task *v3; // ecx
  LPVOID Value; // eax
  int v5; // eax

  while ( vostok::tasks::task::grab_next_child(m_begin) )
  {
    vostok::tasks::task::execute(v3);
    Value = TlsGetValue(s_thread_affinity_tls_key);
    if ( Value )
      v5 = (int)Value - 1;
    else
      v5 = -1;
    m_begin = (vostok::tasks::task *)this->m_core_thread_count.m_begin;
    if ( *((int *)&m_begin->m_next_task_in_child_queue + v5) > 1
      && this->m_active_task_thread_count > this->m_min_permanent_working_threads )
    {
      return 0;
    }
  }
  return 1;
}
