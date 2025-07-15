void __cdecl vostok::tasks::wait_for_all_children()
{
  vostok::tasks::task **Value; // edi
  vostok::tasks::thread_pool *v1; // ecx
  vostok::tasks::task *v2; // ecx

  Value = (vostok::tasks::task **)TlsGetValue(s_thread_pool.m_variable->m_thread_tls_key);
  vostok::tasks::thread_pool::wait_for_task_list(v1, Value[67]);
  if ( Value[72] == (vostok::tasks::task *)1 )
  {
    vostok::tasks::task::unlink_from_children(v2);
    Value[67] = (vostok::tasks::task *)(Value + 36);
  }
}
