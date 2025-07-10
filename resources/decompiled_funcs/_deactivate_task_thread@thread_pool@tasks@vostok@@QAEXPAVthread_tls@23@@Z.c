void __usercall vostok::tasks::thread_pool::deactivate_task_thread(
        vostok::tasks::thread_pool *this@<eax>,
        vostok::tasks::thread_tls *tls@<esi>)
{
  vostok::tasks::thread_pool::log(
    this,
    tls,
    "%d>deactivated(%d)",
    tls->hardware_thread,
    this->m_core_thread_count.m_begin[tls->hardware_thread]);
  _InterlockedExchange(&tls->state, 1);
  _InterlockedExchangeAdd(&this->m_core_thread_count.m_begin[tls->hardware_thread], 0xFFFFFFFF);
  _InterlockedExchangeAdd(&this->m_active_task_thread_count, 0xFFFFFFFF);
}
