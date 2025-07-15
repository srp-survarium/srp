vostok::tasks::task *__thiscall vostok::tasks::task_manager::grab_next_task(vostok::tasks::task_manager *this)
{
  char *Value; // ebp
  int v2; // edi
  vostok::tasks::task *v3; // esi
  bool v4; // bl
  volatile __int64 m_oldest_task_ordinal; // rax
  volatile __int64 *p_m_oldest_task_ordinal; // edi
  bool popped_from_type; // [esp+13h] [ebp-Dh]
  volatile __int32 *v9; // [esp+14h] [ebp-Ch]

  while ( s_task_manager.m_collecting_garbage )
    ;
  Value = (char *)TlsGetValue(s_thread_pool.m_variable->m_thread_tls_key);
  v9 = (volatile __int32 *)(Value + 292);
  _InterlockedExchange((volatile __int32 *)Value + 73, 1);
  do
  {
    v2 = *((_DWORD *)Value + 68);
    popped_from_type = 0;
    if ( !v2
      || s_task_manager.m_oldest_task_ordinal + 51200 <= *(_QWORD *)(v2 + 96)
      || (v3 = vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::pop_front(
                 (vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *)(LODWORD(s_task_manager.m_oldest_task_ordinal) + 51200),
                 v2),
          popped_from_type = 1,
          !v3) )
    {
      v3 = vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,12,vostok::threading::mutex>::pop_front();
      if ( !v3 )
      {
        _InterlockedExchange(v9, 0);
        return 0;
      }
    }
    v4 = _InterlockedCompareExchange(&v3->m_state, 2, 1) == 1;
    if ( !_InterlockedDecrement(&v3->m_reference_counter) )
      vostok::tasks::task_allocator::deallocate(0, (int)&s_task_manager.m_task_allocator, v3);
  }
  while ( !v4 );
  if ( popped_from_type )
  {
    p_m_oldest_task_ordinal = (volatile __int64 *)(v2 + 96);
    m_oldest_task_ordinal = *p_m_oldest_task_ordinal;
  }
  else
  {
    m_oldest_task_ordinal = s_task_manager.m_oldest_task_ordinal;
    p_m_oldest_task_ordinal = &s_task_manager.m_oldest_task_ordinal;
  }
  _InterlockedCompareExchange64(p_m_oldest_task_ordinal, v3->m_ordinal, m_oldest_task_ordinal);
  *((_DWORD *)Value + 67) = v3;
  *((_DWORD *)Value + 68) = v3->m_type;
  _InterlockedExchange(v9, 0);
  return v3;
}
