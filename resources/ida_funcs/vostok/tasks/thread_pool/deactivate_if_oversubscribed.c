char __usercall vostok::tasks::thread_pool::deactivate_if_oversubscribed@<al>(
        vostok::tasks::thread_pool *this@<edi>,
        vostok::tasks::thread_tls *tls@<eax>)
{
  LPVOID Value; // eax
  int v4; // eax
  signed __int32 v5; // eax

  Value = TlsGetValue(s_thread_affinity_tls_key);
  if ( Value )
    v4 = (int)Value - 1;
  else
    v4 = -1;
  if ( this->m_core_thread_count.m_begin[v4] <= 1
    || this->m_active_task_thread_count <= this->m_min_permanent_working_threads )
  {
    return 0;
  }
  v5 = _InterlockedDecrement(&this->m_core_thread_count.m_begin[tls->hardware_thread]);
  if ( !v5 )
  {
    _InterlockedExchangeAdd(&this->m_core_thread_count.m_begin[tls->hardware_thread], 1u);
    return 0;
  }
  vostok::tasks::thread_pool::log(this, tls, "%d>deactivated(%d)", tls->hardware_thread, v5 + 1);
  _InterlockedExchange(&tls->state, 1);
  _InterlockedExchangeAdd(&this->m_active_task_thread_count, 0xFFFFFFFF);
  return 1;
}
