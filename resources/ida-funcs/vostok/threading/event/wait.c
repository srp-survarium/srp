int __thiscall vostok::threading::event::wait(
        vostok::threading::event *this,
        vostok::threading::event *max_wait_time_ms,
        unsigned int max_wait_time_msa)
{
  DWORD v3; // eax
  int v5; // esi
  vostok::tasks::thread_pool *v6; // ecx
  DWORD v7; // eax
  int v8; // ebx
  vostok::tasks::thread_pool *v9; // ecx

  if ( !max_wait_time_msa )
  {
    v3 = WaitForSingleObject(*(HANDLE *)max_wait_time_ms->m_event.m_event, 0);
    if ( v3 )
      return v3 != 258 ? 0 : 2;
    return 1;
  }
  v5 = 0;
  if ( s_spin_count.m_begin )
  {
    while ( WaitForSingleObject(*(HANDLE *)max_wait_time_ms->m_event.m_event, 0) )
    {
      if ( (vostok::tasks::thread_tls *)++v5 >= s_spin_count.m_begin )
        goto LABEL_7;
    }
    return 1;
  }
LABEL_7:
  if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
    vostok::tasks::thread_pool::on_current_thread_locks(v6, s_thread_pool.m_variable);
  v7 = WaitForSingleObject(*(HANDLE *)max_wait_time_ms->m_event.m_event, max_wait_time_msa);
  if ( v7 )
    v8 = v7 != 258 ? 0 : 2;
  else
    v8 = 1;
  if ( s_thread_pool.m_initialized )
  {
    if ( TlsGetValue(s_thread_affinity_tls_key) )
      vostok::tasks::thread_pool::on_current_thread_unlocks(v9, s_thread_pool.m_variable);
  }
  return v8;
}
