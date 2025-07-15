char __usercall vostok::apc::try_process_single_call@<al>(const vostok::apc::threads_enum thread_id@<eax>)
{
  vostok::apc::callback *v1; // eax
  volatile __int32 *p_m_pending; // esi
  boost::function0<bool> *m_pending; // ecx

  v1 = &g_threads.m_begin[thread_id];
  p_m_pending = &v1->m_pending;
  m_pending = (boost::function0<bool> *)v1->m_pending;
  if ( !m_pending )
    return 0;
  boost::function0<void>::operator()(m_pending, v1);
  _InterlockedExchange(p_m_pending, 0);
  return 1;
}
