void __userpurge vostok::tasks::thread_pool::wait_for_task_list(
        vostok::tasks::task *parent@<eax>,
        vostok::tasks::thread_pool *this)
{
  vostok::tasks::thread_tls *Value; // eax
  vostok::tasks::thread_tls *v4; // esi
  vostok::threading::event **p_m_event_wait_for_children; // ebx
  vostok::tasks::task_type *v6; // [esp-4h] [ebp-14h]
  vostok::threading::event *v7; // [esp-4h] [ebp-14h]

  Value = (vostok::tasks::thread_tls *)TlsGetValue(this->m_thread_tls_key);
  v4 = Value;
  if ( this->m_execute_while_wait_for_children != execute_while_wait_for_children_true
    || (vostok::tasks::thread_pool::log(this, Value, "%d>exec children", Value->hardware_thread),
        vostok::tasks::thread_pool::execute_children(parent, v6, this) != 1)
    || parent->m_child_counter )
  {
    vostok::tasks::thread_pool::log(this, v4, "%d>wait4children", v4->hardware_thread);
    p_m_event_wait_for_children = &parent->m_event_wait_for_children;
    _InterlockedExchange((volatile __int32 *)&parent->m_event_wait_for_children, (__int32)&v4->event_wait_for_children);
    if ( parent->m_child_counter )
      vostok::threading::event::wait(v7, (HANDLE *)*p_m_event_wait_for_children, 0xFFFFFFFF);
    _InterlockedExchange((volatile __int32 *)p_m_event_wait_for_children, 0);
  }
}
