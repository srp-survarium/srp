void __usercall vostok::tasks::task::unlink_from_children(vostok::tasks::task *this@<ecx>, _DWORD *a2@<esi>)
{
  vostok::tasks::task *v2; // eax
  vostok::tasks::task *m_next_task_in_child_queue; // ecx
  vostok::tasks::task *v4; // ecx
  volatile signed __int32 *p_m_state; // edx
  signed __int32 m_state; // eax

  while ( a2[6] )
  {
    v2 = (vostok::tasks::task *)a2[6];
    --a2[4];
    m_next_task_in_child_queue = v2->m_next_task_in_child_queue;
    a2[6] = v2->m_next_task_in_child_queue;
    if ( !m_next_task_in_child_queue )
      a2[7] = 0;
    v4 = v2;
    p_m_state = &v2->m_state;
    v2->m_next_task_in_child_queue = 0;
    m_state = v2->m_state;
    while ( m_state != 3 )
    {
      while ( 1 )
      {
        m_state = _InterlockedCompareExchange(p_m_state, 4, 2);
        if ( m_state != 2 )
          break;
        v4->m_parent = 0;
        _InterlockedCompareExchange(p_m_state, 2, 4);
      }
    }
    vostok::tasks::task::decrement_reference_count_and_deallocate_when_zero(v4, (unsigned int)v4);
  }
}
