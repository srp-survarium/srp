void __usercall vostok::tasks::thread_pool::on_current_thread_locks(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_pool *a2@<edi>)
{
  LPVOID Value; // eax
  unsigned int v3; // ebp
  signed __int32 v4; // ebx
  LPVOID v5; // esi
  vostok::tasks::thread_tls *i; // esi

  Value = TlsGetValue(s_thread_affinity_tls_key);
  if ( Value )
    v3 = (unsigned int)Value - 1;
  else
    v3 = -1;
  v4 = _InterlockedDecrement(&a2->m_core_thread_count.m_begin[v3]);
  v5 = TlsGetValue(a2->m_thread_tls_key);
  vostok::tasks::thread_pool::log(
    a2,
    *((_DWORD *)v5 + 72) == 0 ? (vostok::tasks::thread_tls *)v5 : 0,
    "%d>locked(%d)",
    v3,
    v4 + 1);
  if ( !*((_DWORD *)v5 + 72) )
  {
    _InterlockedExchange((volatile __int32 *)v5 + 18, 2);
    _InterlockedExchangeAdd(&a2->m_active_task_thread_count, 0xFFFFFFFF);
  }
  if ( !v4 && (s_task_manager.m_pending_tasks.m_pop_list || s_task_manager.m_pending_tasks.m_push_list) )
  {
    for ( i = a2->m_task_thread_tls.m_begin; i != a2->m_task_thread_tls.m_end; ++i )
    {
      if ( i->state == 1 && vostok::tasks::thread_pool::try_activate_task_thread(a2, i, v3) )
        break;
    }
  }
}
