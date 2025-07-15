bool __usercall vostok::tasks::thread_pool::deactivate_if_oversubscribed@<al>(
        vostok::tasks::thread_pool *this@<ecx>,
        vostok::tasks::thread_tls *tls@<eax>)
{
  bool result; // al
  signed __int32 v5; // eax

  if ( !vostok::tasks::thread_pool::current_thread_core_is_oversubscribed(this, this) )
    return 0;
  v5 = _InterlockedDecrement(&this->m_core_thread_count.m_begin[tls->hardware_thread]);
  if ( !v5 )
  {
    _InterlockedExchangeAdd(&this->m_core_thread_count.m_begin[tls->hardware_thread], 1u);
    return 0;
  }
  vostok::tasks::thread_pool::log(this, tls, "%d>deactivated(%d)", tls->hardware_thread, v5 + 1);
  result = 1;
  _InterlockedExchange(&tls->state, 1);
  _InterlockedExchangeAdd(&this->m_active_task_thread_count, 0xFFFFFFFF);
  return result;
}
