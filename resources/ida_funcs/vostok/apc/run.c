void __usercall vostok::apc::run(
        vostok::apc::threads_enum thread_id@<edi>,
        const boost::function<void __cdecl(void)> *callback,
        vostok::apc::break_parameters break_parameters,
        vostok::apc::wait_parameters wait_parameters)
{
  vostok::apc::callback *v4; // ebx
  vostok::apc::callback *v5; // esi

  v4 = &g_threads.m_begin[thread_id];
  if ( v4->m_thread_id == GetCurrentThreadId() )
  {
    boost::function0<void>::operator()(&callback->boost::function0<void>);
  }
  else
  {
    vostok::apc::wait(thread_id);
    v5 = &g_threads.m_begin[thread_id];
    boost::function<void __cdecl (void)>::operator=(&v5->m_callback, callback);
    v5->m_break_parameters = break_parameters;
    _InterlockedExchange(&v5->m_pending, 1);
    if ( wait_parameters == wait_for_completion )
      vostok::apc::wait(thread_id);
  }
}
