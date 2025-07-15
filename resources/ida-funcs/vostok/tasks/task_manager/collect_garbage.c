void __thiscall vostok::tasks::task_manager::collect_garbage(unsigned int *collector)
{
  vostok::tasks::thread_tls *i; // ecx
  vostok::tasks::thread_tls *m_begin; // eax
  vostok::threading::mutex *p_m_end; // ecx
  vostok::tasks::task *m_pop_list; // esi
  __int32 v5; // eax
  __int32 v6; // ecx
  vostok::tasks::task *v7; // ecx
  vostok::tasks::task_type **p_m_first; // esi
  vostok::threading::mutex_tasks_unaware *v9; // ebp
  vostok::threading::mutex *v10; // ecx
  vostok::tasks::task_type *v11; // esi
  vostok::tasks::task_type *m_next_task_type; // ebx
  vostok::tasks::task_manager::collector v13; // [esp+10h] [ebp-4h] BYREF

  EnterCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_mutex_collect_garbage);
  _InterlockedExchange(&s_task_manager.m_collecting_garbage, 1);
  for ( i = s_thread_pool.m_variable->m_task_thread_tls.m_begin; i != s_thread_pool.m_variable->m_task_thread_tls.m_end; ++i )
  {
    while ( i->in_grab_next_task )
      ;
  }
  m_begin = s_thread_pool.m_variable->m_user_thread_tls.m_begin;
  p_m_end = (vostok::threading::mutex *)&s_thread_pool.m_variable->m_user_thread_tls.m_end;
  while ( m_begin != (vostok::tasks::thread_tls *)LODWORD(p_m_end->m_mutex.m_mutex[0]) )
  {
    while ( m_begin->in_grab_next_task )
      ;
    ++m_begin;
  }
  while ( 1 )
  {
    if ( s_task_manager.m_pending_tasks.m_pop_list )
    {
LABEL_12:
      m_pop_list = s_task_manager.m_pending_tasks.m_pop_list;
      if ( s_task_manager.m_pending_tasks.m_pop_list )
        goto LABEL_18;
    }
    vostok::threading::mutex::lock(p_m_end, (_RTL_CRITICAL_SECTION *)&s_task_manager.m_pending_tasks.m_threading_policy);
    m_pop_list = 0;
    if ( s_task_manager.m_pending_tasks.m_pop_list )
    {
      LeaveCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_pending_tasks.m_threading_policy);
      goto LABEL_12;
    }
    if ( !s_task_manager.m_pending_tasks.m_push_list )
      break;
    v5 = _InterlockedExchange((volatile __int32 *)&s_task_manager.m_pending_tasks.m_push_list, 0);
    if ( v5 )
    {
      do
      {
        v6 = *(_DWORD *)(v5 + 12);
        *(_DWORD *)(v5 + 12) = m_pop_list;
        m_pop_list = (vostok::tasks::task *)v5;
        v5 = v6;
      }
      while ( v6 );
    }
    s_task_manager.m_pending_tasks.m_pop_list = m_pop_list;
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_pending_tasks.m_threading_policy);
LABEL_18:
    if ( !m_pop_list || m_pop_list->m_state == 1 )
      goto LABEL_22;
    vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,12,vostok::threading::mutex>::pop_front((vostok::tasks::task *)p_m_end);
    vostok::tasks::task::decrement_reference_count_and_deallocate_when_zero(v7, (unsigned int)m_pop_list);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_pending_tasks.m_threading_policy);
LABEL_22:
  v13.m_tasks_freed_count = 0;
  if ( s_task_type_list )
  {
    p_m_first = &s_task_type_list->m_first;
    if ( s_task_type_list->m_first )
    {
      v9 = &s_task_type_list->vostok::threading::mutex_tasks_unaware;
      EnterCriticalSection((LPCRITICAL_SECTION)&s_task_type_list->vostok::threading::mutex_tasks_unaware);
      v11 = *p_m_first;
      if ( v11 )
      {
        do
        {
          m_next_task_type = v11->m_next_task_type;
          vostok::tasks::task_manager::collector::operator()(v11, v10, &v13);
          v11 = m_next_task_type;
        }
        while ( m_next_task_type );
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)v9);
    }
  }
  _InterlockedExchange((volatile __int32 *)((char *)&s_task_manager + (_DWORD)&loc_60141 + 3), 0);
  LeaveCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_mutex_collect_garbage);
}
