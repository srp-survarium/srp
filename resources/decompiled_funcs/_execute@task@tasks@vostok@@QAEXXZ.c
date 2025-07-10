void __usercall vostok::tasks::task::execute(vostok::tasks::task *this@<ecx>, vostok::tasks::task *a2@<eax>)
{
  boost::function0<void> *p_m_function; // edi
  volatile signed __int32 *p_m_state; // edi
  vostok::tasks::task *m_parent; // eax
  HANDLE *m_event_wait_for_children; // eax
  vostok::tasks::task_allocator *v7; // ecx

  p_m_function = &a2->m_function;
  if ( boost::function0<void>::operator void (__thiscall boost::function0<void>::dummy::*)(void)(&a2->m_function) )
    boost::function0<void>::operator()(p_m_function);
  p_m_state = &a2->m_state;
  *((_DWORD *)TlsGetValue(s_thread_pool.m_variable->m_thread_tls_key) + 67) = 0;
  while ( _InterlockedCompareExchange(p_m_state, 4, 2) != 2 )
    ;
  m_parent = a2->m_parent;
  if ( m_parent )
  {
    _InterlockedExchangeAdd(&m_parent->m_child_counter, 0xFFFFFFFF);
    if ( !m_parent->m_child_counter )
    {
      m_event_wait_for_children = (HANDLE *)m_parent->m_event_wait_for_children;
      if ( m_event_wait_for_children )
        SetEvent(*m_event_wait_for_children);
    }
  }
  _InterlockedCompareExchange(p_m_state, 3, 4);
  vostok::tasks::task::unlink_from_children((vostok::tasks::task *)3, a2);
  if ( !_InterlockedDecrement(&a2->m_reference_counter) )
    vostok::tasks::task_allocator::deallocate(v7, (int)&s_task_manager.m_task_allocator, a2);
}
