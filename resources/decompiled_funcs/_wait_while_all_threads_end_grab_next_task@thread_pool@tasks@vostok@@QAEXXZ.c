void __thiscall vostok::tasks::thread_pool::wait_while_all_threads_end_grab_next_task(vostok::tasks::thread_pool *this)
{
  vostok::tasks::thread_tls *i; // eax
  vostok::tasks::thread_tls *j; // eax

  for ( i = this->m_task_thread_tls.m_begin; i != this->m_task_thread_tls.m_end; ++i )
  {
    while ( i->in_grab_next_task )
      ;
  }
  for ( j = this->m_user_thread_tls.m_begin; j != this->m_user_thread_tls.m_end; ++j )
  {
    while ( j->in_grab_next_task )
      ;
  }
}
