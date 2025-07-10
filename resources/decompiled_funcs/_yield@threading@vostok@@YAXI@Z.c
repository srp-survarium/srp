void __cdecl vostok::threading::yield(unsigned int yield_time_in_ms)
{
  vostok::tasks::thread_pool *v1; // ecx
  vostok::tasks::thread_pool *v2; // ecx

  if ( yield_time_in_ms )
  {
    if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
      vostok::tasks::thread_pool::on_current_thread_locks(v1);
    Sleep(yield_time_in_ms);
    if ( s_thread_pool.m_initialized )
    {
      if ( TlsGetValue(s_thread_affinity_tls_key) )
        vostok::tasks::thread_pool::on_current_thread_unlocks(v2);
    }
  }
  else if ( !SwitchToThread() )
  {
    Sleep(0);
  }
}
