vostok::tasks::thread_tls *__cdecl vostok::tasks::current_task_thread_tls()
{
  return (vostok::tasks::thread_tls *)TlsGetValue(s_thread_pool.m_variable->m_thread_tls_key);
}
