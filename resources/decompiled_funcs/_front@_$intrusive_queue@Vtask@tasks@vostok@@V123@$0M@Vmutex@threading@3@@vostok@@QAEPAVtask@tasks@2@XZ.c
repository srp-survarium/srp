vostok::tasks::task *vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,12,vostok::threading::mutex>::front()
{
  vostok::tasks::task *result; // eax
  __int32 v1; // eax
  vostok::tasks::task *v2; // esi
  __int32 v3; // ecx

  if ( s_task_manager.m_pending_tasks.m_pop_list )
    goto pop_front_existing_2;
  while ( 1 )
  {
    vostok::threading::mutex::lock(&s_task_manager.m_pending_tasks.m_threading_policy);
    if ( !s_task_manager.m_pending_tasks.m_pop_list )
      break;
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_pending_tasks.m_threading_policy);
pop_front_existing_2:
    result = s_task_manager.m_pending_tasks.m_pop_list;
    if ( s_task_manager.m_pending_tasks.m_pop_list )
      return result;
  }
  if ( s_task_manager.m_pending_tasks.m_push_list )
  {
    v1 = _InterlockedExchange((volatile __int32 *)&s_task_manager.m_pending_tasks.m_push_list, 0);
    v2 = 0;
    if ( v1 )
    {
      do
      {
        v3 = *(_DWORD *)(v1 + 12);
        *(_DWORD *)(v1 + 12) = v2;
        v2 = (vostok::tasks::task *)v1;
        v1 = v3;
      }
      while ( v3 );
    }
    s_task_manager.m_pending_tasks.m_pop_list = v2;
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_pending_tasks.m_threading_policy);
    return v2;
  }
  else
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_pending_tasks.m_threading_policy);
    return 0;
  }
}
