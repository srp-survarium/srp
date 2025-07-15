vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *__usercall vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::pop_front@<eax>(
        vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *this@<ecx>,
        int a2@<eax>)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  __int32 v5; // esi
  __int32 v6; // eax
  __int32 v7; // ecx
  __int32 v8; // edx

  if ( *(_DWORD *)a2 )
    goto pop_front_existing;
  while ( 1 )
  {
    v3 = (_RTL_CRITICAL_SECTION *)(a2 + 72);
    vostok::threading::mutex::lock((vostok::threading::mutex *)this, (_RTL_CRITICAL_SECTION *)(a2 + 72));
    if ( !*(_DWORD *)a2 )
      break;
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 72));
pop_front_existing:
    this = *(vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> **)a2;
    if ( *(_DWORD *)a2 )
    {
      do
      {
        if ( (vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *)_InterlockedCompareExchange((volatile signed __int32 *)a2, *(_DWORD *)&this->m_cache_line_pad[4], (signed __int32)this) == this )
          break;
        this = *(vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> **)a2;
      }
      while ( *(_DWORD *)a2 );
      if ( this )
        return this;
    }
  }
  if ( *(_DWORD *)(a2 + 64) )
  {
    v6 = _InterlockedExchange((volatile __int32 *)(a2 + 64), 0);
    v7 = 0;
    if ( v6 )
    {
      do
      {
        v8 = *(_DWORD *)(v6 + 8);
        *(_DWORD *)(v6 + 8) = v7;
        v7 = v6;
        v6 = v8;
      }
      while ( v8 );
    }
    *(_DWORD *)a2 = *(_DWORD *)(v7 + 8);
    v5 = v7;
  }
  else
  {
    v5 = 0;
  }
  LeaveCriticalSection(v3);
  return (vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *)v5;
}


vostok::tasks::task *__fastcall vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,12,vostok::threading::mutex>::pop_front(
        vostok::tasks::task *m_pop_list)
{
  __int32 v2; // esi
  __int32 v3; // eax
  __int32 v4; // ecx
  __int32 v5; // edx

  if ( s_task_manager.m_pending_tasks.m_pop_list )
    goto pop_front_existing_0;
  while ( 1 )
  {
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)m_pop_list,
      (_RTL_CRITICAL_SECTION *)&s_task_manager.m_pending_tasks.m_threading_policy);
    if ( !s_task_manager.m_pending_tasks.m_pop_list )
      break;
    LeaveCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_pending_tasks.m_threading_policy);
pop_front_existing_0:
    m_pop_list = s_task_manager.m_pending_tasks.m_pop_list;
    if ( s_task_manager.m_pending_tasks.m_pop_list )
    {
      do
      {
        if ( (vostok::tasks::task *)_InterlockedCompareExchange(
                                      (volatile signed __int32 *)&s_task_manager,
                                      (signed __int32)m_pop_list->m_next_task_in_full_queue,
                                      (signed __int32)m_pop_list) == m_pop_list )
          break;
        m_pop_list = s_task_manager.m_pending_tasks.m_pop_list;
      }
      while ( s_task_manager.m_pending_tasks.m_pop_list );
      if ( m_pop_list )
        return m_pop_list;
    }
  }
  if ( s_task_manager.m_pending_tasks.m_push_list )
  {
    v3 = _InterlockedExchange((volatile __int32 *)&s_task_manager.m_pending_tasks.m_push_list, 0);
    v4 = 0;
    if ( v3 )
    {
      do
      {
        v5 = *(_DWORD *)(v3 + 12);
        *(_DWORD *)(v3 + 12) = v4;
        v4 = v3;
        v3 = v5;
      }
      while ( v5 );
    }
    s_task_manager.m_pending_tasks.m_pop_list = *(vostok::tasks::task **)(v4 + 12);
    v2 = v4;
  }
  else
  {
    v2 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&s_task_manager.m_pending_tasks.m_threading_policy);
  return (vostok::tasks::task *)v2;
}
