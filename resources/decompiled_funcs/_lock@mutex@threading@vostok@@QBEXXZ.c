void __thiscall vostok::threading::mutex::lock(vostok::threading::mutex *this)
{
  int v1; // esi
  vostok::tasks::thread_pool *v3; // ecx
  vostok::tasks::thread_pool *v4; // ecx

  v1 = 0;
  if ( s_spin_count.m_begin )
  {
    while ( !TryEnterCriticalSection((LPCRITICAL_SECTION)this) )
    {
      if ( (vostok::tasks::thread_tls *)++v1 >= s_spin_count.m_begin )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
      vostok::tasks::thread_pool::on_current_thread_locks(v3, s_thread_pool.m_variable);
    EnterCriticalSection((LPCRITICAL_SECTION)this);
    if ( s_thread_pool.m_initialized )
    {
      if ( TlsGetValue(s_thread_affinity_tls_key) )
        vostok::tasks::thread_pool::on_current_thread_unlocks(v4, s_thread_pool.m_variable);
    }
  }
}
