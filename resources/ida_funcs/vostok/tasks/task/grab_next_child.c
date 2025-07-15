vostok::tasks::task *__usercall vostok::tasks::task::grab_next_child@<eax>(
        vostok::tasks::task *this@<ecx>,
        _DWORD *a2@<edi>)
{
  vostok::tasks::task *v2; // esi
  vostok::tasks::task *m_next_task_in_child_queue; // eax
  bool v4; // bl
  _DWORD *Value; // eax

  while ( a2[6] )
  {
    v2 = (vostok::tasks::task *)a2[6];
    --a2[4];
    m_next_task_in_child_queue = v2->m_next_task_in_child_queue;
    a2[6] = v2->m_next_task_in_child_queue;
    if ( !m_next_task_in_child_queue )
      a2[7] = 0;
    v2->m_next_task_in_child_queue = 0;
    v4 = _InterlockedCompareExchange(&v2->m_state, 2, 1) == 1;
    if ( !_InterlockedDecrement(&v2->m_reference_counter) )
      vostok::tasks::task_allocator::deallocate(0, (int)&s_task_manager.m_task_allocator, v2);
    if ( v4 )
    {
      Value = TlsGetValue(s_thread_pool.m_variable->m_thread_tls_key);
      Value[67] = v2;
      Value[68] = v2->m_type;
      return v2;
    }
  }
  return 0;
}
