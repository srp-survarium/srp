void __thiscall vostok::tasks::thread_pool::wait_for_all_children(
        vostok::tasks::thread_pool *this,
        vostok::tasks::thread_pool *thisa)
{
  vostok::tasks::task **Value; // edi
  vostok::tasks::thread_pool *v3; // ecx
  vostok::tasks::task *v4; // ecx

  Value = (vostok::tasks::task **)TlsGetValue(thisa->m_thread_tls_key);
  vostok::tasks::thread_pool::wait_for_task_list(v3, thisa, Value[67]);
  if ( Value[72] == (vostok::tasks::task *)1 )
  {
    vostok::tasks::task::unlink_from_children(v4);
    Value[67] = (vostok::tasks::task *)(Value + 36);
  }
}
