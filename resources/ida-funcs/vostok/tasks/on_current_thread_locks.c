void __cdecl vostok::tasks::on_current_thread_locks()
{
  vostok::tasks::thread_pool *v0; // ecx

  if ( s_thread_pool.m_initialized )
  {
    if ( vostok::threading::current_thread_affinity() != -1 )
      vostok::tasks::thread_pool::on_current_thread_locks(v0, s_thread_pool.m_variable);
  }
}
