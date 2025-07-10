void __userpurge vostok::tasks::thread_pool::wait_for_task_list(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_pool *a2@<eax>,
        vostok::tasks::task *parent)
{
  vostok::tasks::thread_tls *Value; // eax
  vostok::tasks::thread_tls *v5; // edi
  vostok::tasks::task *v6; // ecx
  unsigned int *p_m_event_wait_for_children; // esi
  vostok::threading::event *m_child_counter; // ecx

  Value = (vostok::tasks::thread_tls *)TlsGetValue(a2->m_thread_tls_key);
  v5 = Value;
  if ( a2->m_execute_while_wait_for_children != execute_while_wait_for_children_true
    || (vostok::tasks::thread_pool::log(a2, Value, "%d>exec children", Value->hardware_thread),
        vostok::tasks::thread_pool::execute_children(a2, v6) != 1)
    || parent->m_child_counter )
  {
    vostok::tasks::thread_pool::log(a2, v5, "%d>wait4children", v5->hardware_thread);
    p_m_event_wait_for_children = (unsigned int *)&parent->m_event_wait_for_children;
    _InterlockedExchange((volatile __int32 *)&parent->m_event_wait_for_children, (__int32)&v5->event_wait_for_children);
    m_child_counter = (vostok::threading::event *)parent->m_child_counter;
    if ( m_child_counter )
      vostok::threading::event::wait(m_child_counter, *p_m_event_wait_for_children);
    _InterlockedExchange((volatile __int32 *)p_m_event_wait_for_children, 0);
  }
}
