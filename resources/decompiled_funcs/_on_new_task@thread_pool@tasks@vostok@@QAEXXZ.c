void __fastcall vostok::tasks::thread_pool::on_new_task(
        vostok::tasks::thread_pool *this,
        vostok::tasks::thread_pool *a2)
{
  volatile int *m_end; // ebx
  volatile int *m_begin; // edi
  int v4; // ecx
  int v5; // ebp
  int *v6; // eax
  int v7; // esi
  vostok::tasks::thread_tls *v8; // esi
  int v9; // [esp+10h] [ebp-4h]

  m_end = a2->m_core_thread_count.m_end;
  m_begin = a2->m_core_thread_count.m_begin;
  v4 = -1;
  v5 = -1;
  v6 = (int *)m_begin;
  if ( m_begin == m_end )
    goto LABEL_10;
  v9 = 0;
  while ( 1 )
  {
    v7 = *v6;
    if ( v4 == -1 || v7 < v5 )
    {
      v5 = *v6;
      v4 = v9 >> 2;
    }
    if ( !v7 )
      break;
    v9 += 4;
    if ( ++v6 == m_end )
      goto LABEL_10;
  }
  if ( v6 - m_begin == -1 )
  {
LABEL_10:
    if ( a2->m_active_task_thread_count >= a2->m_min_permanent_working_threads )
      return;
  }
  v8 = a2->m_task_thread_tls.m_begin;
  if ( v8 != a2->m_task_thread_tls.m_end )
  {
    while ( v8->state != 1 || _InterlockedCompareExchange(&v8->state, 0, 1) != 1 )
    {
      if ( ++v8 == a2->m_task_thread_tls.m_end )
        return;
    }
    _InterlockedExchangeAdd(&a2->m_active_task_thread_count, 1u);
    v8->hardware_thread = v4;
    vostok::tasks::thread_pool::log(
      a2,
      v8,
      "%d>activated(%d)",
      v4,
      _InterlockedIncrement(&a2->m_core_thread_count.m_begin[v4]));
    SetEvent(*(HANDLE *)v8->event_should_work.m_event);
  }
}
