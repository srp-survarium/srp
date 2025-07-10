char __cdecl vostok::apc::try_process_single_call()
{
  volatile __int32 *p_m_pending; // esi

  p_m_pending = &g_threads.m_begin[1].m_pending;
  if ( !g_threads.m_begin[1].m_pending )
    return 0;
  boost::function0<void>::operator()(&g_threads.m_begin[1].m_callback);
  _InterlockedExchange(p_m_pending, 0);
  return 1;
}
