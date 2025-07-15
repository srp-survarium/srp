void __usercall vostok::apc::process(
        const vostok::apc::threads_enum thread_id@<eax>,
        vostok::command_line::key *a2@<ecx>,
        const bool do_dispatch_callbacks_while_pending)
{
  vostok::apc::callback *v3; // edi
  volatile __int32 *p_m_pending; // ebx
  vostok::apc::break_parameters m_break_parameters; // esi

  v3 = &g_threads.m_begin[thread_id];
  p_m_pending = &v3->m_pending;
  do
  {
    while ( !*p_m_pending )
    {
      if ( do_dispatch_callbacks_while_pending )
        vostok::resources::dispatch_callbacks(a2);
      vostok::threading::yield(1u, (vostok::tasks *)a2);
    }
    m_break_parameters = v3->m_break_parameters;
    boost::function0<void>::operator()((boost::function0<bool> *)a2, v3);
    a2 = (vostok::command_line::key *)&v3->m_pending;
    _InterlockedExchange(p_m_pending, 0);
  }
  while ( m_break_parameters );
}
