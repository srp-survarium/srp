void __cdecl vostok::tasks::on_current_thread_unlocks()
{
  vostok::tasks::thread_pool *v0; // ecx

  if ( s_thread_pool.m_initialized )
  {
    if ( TlsGetValue(s_thread_affinity_tls_key) )
      vostok::tasks::thread_pool::on_current_thread_unlocks(v0);
  }
}
