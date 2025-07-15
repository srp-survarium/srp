int __userpurge vostok::tasks::thread_pool::execute_children@<eax>(
        vostok::tasks::task *parent@<edi>,
        vostok::tasks::task_type *m_type@<ecx>,
        vostok::tasks::thread_pool *this)
{
  vostok::tasks::task *m_first; // esi
  vostok::tasks::task *m_next_task_in_child_queue; // eax
  bool v5; // bl
  vostok::tasks::thread_tls *v6; // eax
  vostok::tasks::thread_pool *v7; // ecx

  while ( 1 )
  {
    while ( 1 )
    {
      m_first = parent->m_children.m_first;
      if ( !m_first )
        break;
      --parent->m_children.m_size;
      m_next_task_in_child_queue = m_first->m_next_task_in_child_queue;
      parent->m_children.m_first = m_first->m_next_task_in_child_queue;
      if ( !m_next_task_in_child_queue )
        parent->m_children.m_last = 0;
      m_first->m_next_task_in_child_queue = 0;
      v5 = _InterlockedCompareExchange(&m_first->m_state, 2, 1) == 1;
      vostok::tasks::task::decrement_reference_count_and_deallocate_when_zero(
        (vostok::tasks::task *)2,
        (unsigned int)m_first);
      if ( v5 )
      {
        v6 = vostok::tasks::current_task_thread_tls();
        v6->current_task = m_first;
        m_type = m_first->m_type;
        v6->last_task_type = m_type;
        goto LABEL_7;
      }
    }
    m_first = 0;
LABEL_7:
    if ( !m_first )
      return 1;
    vostok::tasks::task::execute((vostok::tasks::task *)m_type, m_first);
    if ( vostok::tasks::thread_pool::current_thread_core_is_oversubscribed(v7, this) )
      return 0;
  }
}
