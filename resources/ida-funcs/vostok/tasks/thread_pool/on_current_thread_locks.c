void __usercall vostok::tasks::thread_pool::on_current_thread_locks(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_pool *a2@<edi>)
{
  signed __int32 v2; // esi
  LPVOID Value; // ebx
  vostok::tasks::thread_tls *i; // esi
  unsigned int v5; // [esp+Ch] [ebp-4h]

  v5 = vostok::threading::current_thread_affinity();
  v2 = _InterlockedDecrement(&a2->m_core_thread_count.m_begin[v5]);
  Value = TlsGetValue(a2->m_thread_tls_key);
  vostok::tasks::thread_pool::log(
    a2,
    *((_DWORD *)Value + 72) == 0 ? (vostok::tasks::thread_tls *)Value : 0,
    "%d>locked(%d)",
    v5,
    v2 + 1);
  if ( !*((_DWORD *)Value + 72) )
  {
    _InterlockedExchange((volatile __int32 *)Value + 18, 2);
    _InterlockedExchangeAdd(&a2->m_active_task_thread_count, 0xFFFFFFFF);
  }
  if ( !v2 && (s_task_manager.m_pending_tasks.m_pop_list || s_task_manager.m_pending_tasks.m_push_list) )
  {
    for ( i = a2->m_task_thread_tls.m_begin;
          i != a2->m_task_thread_tls.m_end
       && (i->state != 1 || !vostok::tasks::thread_pool::try_activate_task_thread(a2, i, v5));
          ++i )
    {
      ;
    }
  }
}
