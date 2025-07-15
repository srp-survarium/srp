void __usercall vostok::tasks::thread_pool::on_current_thread_unlocks(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_pool *a2@<esi>)
{
  unsigned int v2; // ebx
  signed __int32 v3; // edi
  vostok::tasks::thread_tls *Value; // eax

  v2 = vostok::threading::current_thread_affinity();
  v3 = _InterlockedIncrement(&a2->m_core_thread_count.m_begin[v2]);
  Value = (vostok::tasks::thread_tls *)TlsGetValue(a2->m_thread_tls_key);
  if ( Value->thread_type )
  {
    Value = 0;
  }
  else
  {
    _InterlockedExchange(&Value->state, 0);
    _InterlockedExchangeAdd(&a2->m_active_task_thread_count, 1u);
  }
  vostok::tasks::thread_pool::log(a2, Value, "%d>unlocked(%d)", v2, v3);
}
