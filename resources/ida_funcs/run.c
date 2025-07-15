void __usercall run(
        vostok::apc::threads_enum thread_id@<edi>,
        const boost::function<void __cdecl(void)> *callback,
        vostok::apc::break_parameters break_parameters,
        vostok::apc::wait_parameters wait_parameters,
        bool remote_only)
{
  vostok::apc::callback *v5; // ebx
  vostok::apc::callback *v6; // esi

  v5 = &g_threads.m_begin[thread_id];
  if ( v5->m_thread_id == GetCurrentThreadId() )
  {
    if ( !remote_only )
      boost::function0<void>::operator()(&callback->boost::function0<void>);
  }
  else
  {
    vostok::apc::wait(thread_id);
    v6 = &g_threads.m_begin[thread_id];
    boost::function<void __cdecl (void)>::operator=(&v6->m_callback, callback);
    v6->m_break_parameters = break_parameters;
    _InterlockedExchange(&v6->m_pending, 1);
    if ( wait_parameters == wait_for_completion )
      vostok::apc::wait(thread_id);
  }
}
