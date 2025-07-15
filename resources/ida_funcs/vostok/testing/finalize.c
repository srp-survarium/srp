void __cdecl vostok::testing::finalize()
{
  vostok::tasks::thread_pool *v0; // ecx
  vostok::tasks::thread_pool *v1; // ecx

  if ( s_environment.test_watcher_thread_started )
  {
    SetEvent(*(HANDLE *)s_environment.test_watcher_thread_must_exit.m_event.m_event);
    while ( !s_environment.test_watcher_thread_exited )
    {
      if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
        vostok::tasks::thread_pool::on_current_thread_locks(v0);
      Sleep(1u);
      if ( s_thread_pool.m_initialized )
      {
        if ( TlsGetValue(s_thread_affinity_tls_key) )
          vostok::tasks::thread_pool::on_current_thread_unlocks(v1);
      }
    }
  }
}
