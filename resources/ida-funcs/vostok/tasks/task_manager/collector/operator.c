void __userpurge vostok::tasks::task_manager::collector::operator()(
        vostok::tasks::task_type *const task_type@<esi>,
        vostok::threading::mutex *a2@<ecx>,
        vostok::tasks::task_manager::collector *this)
{
  vostok::tasks::task *m_pop_list; // edi
  __int32 v4; // eax
  __int32 v5; // ecx
  vostok::tasks::task *m_reference_counter; // ecx

  while ( task_type->m_tasks.m_pop_list )
  {
    while ( 1 )
    {
      m_pop_list = task_type->m_tasks.m_pop_list;
      if ( task_type->m_tasks.m_pop_list )
        break;
LABEL_3:
      vostok::threading::mutex::lock(a2, (_RTL_CRITICAL_SECTION *)&task_type->m_tasks.m_threading_policy);
      m_pop_list = 0;
      if ( !task_type->m_tasks.m_pop_list )
      {
        if ( task_type->m_tasks.m_push_list )
        {
          v4 = _InterlockedExchange((volatile __int32 *)&task_type->m_tasks.m_push_list, 0);
          if ( v4 )
          {
            do
            {
              v5 = *(_DWORD *)(v4 + 8);
              *(_DWORD *)(v4 + 8) = m_pop_list;
              m_pop_list = (vostok::tasks::task *)v4;
              v4 = v5;
            }
            while ( v5 );
          }
          task_type->m_tasks.m_pop_list = m_pop_list;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&task_type->m_tasks.m_threading_policy);
        break;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&task_type->m_tasks.m_threading_policy);
    }
    if ( m_pop_list->m_state == 1 )
      return;
    vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::pop_front(
      (vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *)a2,
      (int)task_type);
    if ( this->m_tasks_freed_count )
    {
      m_reference_counter = (vostok::tasks::task *)m_pop_list->m_reference_counter;
      if ( m_reference_counter == (vostok::tasks::task *)1 )
        ++*this->m_tasks_freed_count;
    }
    vostok::tasks::task::decrement_reference_count_and_deallocate_when_zero(
      m_reference_counter,
      (unsigned int)m_pop_list);
  }
  if ( task_type->m_tasks.m_push_list )
    goto LABEL_3;
}
