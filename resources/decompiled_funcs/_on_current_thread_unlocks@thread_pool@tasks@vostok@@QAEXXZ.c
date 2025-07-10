void __usercall vostok::tasks::thread_pool::on_current_thread_unlocks(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_pool *a2@<edi>)
{
  LPVOID Value; // eax
  int v3; // ebx
  signed __int32 v4; // esi
  vostok::tasks::thread_tls *v5; // eax
  vostok::tasks::thread_tls *v6; // ecx

  Value = TlsGetValue(s_thread_affinity_tls_key);
  if ( Value )
    v3 = (int)Value - 1;
  else
    v3 = -1;
  v4 = _InterlockedIncrement(&a2->m_core_thread_count.m_begin[v3]);
  v5 = (vostok::tasks::thread_tls *)TlsGetValue(a2->m_thread_tls_key);
  v6 = 0;
  if ( v5->thread_type == type_task_thread )
  {
    _InterlockedExchange(&v5->state, 0);
    _InterlockedExchangeAdd(&a2->m_active_task_thread_count, 1u);
    v6 = v5;
  }
  vostok::tasks::thread_pool::log(a2, v6, "%d>unlocked(%d)", v3, v4);
}
