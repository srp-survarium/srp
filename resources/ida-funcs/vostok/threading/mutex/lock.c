void __thiscall vostok::threading::mutex::lock(
        vostok::threading::mutex *this,
        _RTL_CRITICAL_SECTION *lpCriticalSection)
{
  int v2; // esi

  v2 = 0;
  if ( s_spin_count.m_begin )
  {
    while ( !TryEnterCriticalSection(lpCriticalSection) )
    {
      if ( (vostok::tasks::thread_tls *)++v2 >= s_spin_count.m_begin )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    vostok::tasks::on_current_thread_locks();
    EnterCriticalSection(lpCriticalSection);
    vostok::tasks::on_current_thread_unlocks();
  }
}
