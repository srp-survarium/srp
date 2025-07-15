void vostok::tasks::wait_for_all_children()
{
  vostok::tasks::thread_pool *m_variable; // ebp
  char *Value; // edi
  vostok::tasks::task *v2; // esi
  vostok::tasks::task *v3; // ecx

  m_variable = s_thread_pool.m_variable;
  Value = (char *)TlsGetValue(s_thread_pool.m_variable->m_thread_tls_key);
  v2 = (vostok::tasks::task *)*((_DWORD *)Value + 67);
  vostok::tasks::thread_pool::wait_for_task_list(v2, m_variable);
  if ( *((_DWORD *)Value + 72) == 1 )
  {
    vostok::tasks::task::unlink_from_children(v3, v2);
    *((_DWORD *)Value + 67) = Value + 144;
  }
}
