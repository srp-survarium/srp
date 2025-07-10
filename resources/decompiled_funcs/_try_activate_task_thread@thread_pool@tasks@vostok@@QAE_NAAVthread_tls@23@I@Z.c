char __usercall vostok::tasks::thread_pool::try_activate_task_thread@<al>(
        vostok::tasks::thread_pool *this@<edx>,
        vostok::tasks::thread_tls *tls@<esi>,
        unsigned int use_hardware_thread@<ecx>)
{
  if ( _InterlockedCompareExchange(&tls->state, 0, 1) != 1 )
    return 0;
  _InterlockedExchangeAdd(&this->m_active_task_thread_count, 1u);
  tls->hardware_thread = use_hardware_thread;
  vostok::tasks::thread_pool::log(
    this,
    tls,
    "%d>activated(%d)",
    use_hardware_thread,
    _InterlockedIncrement(&this->m_core_thread_count.m_begin[use_hardware_thread]));
  SetEvent(*(HANDLE *)tls->event_should_work.m_event);
  return 1;
}
