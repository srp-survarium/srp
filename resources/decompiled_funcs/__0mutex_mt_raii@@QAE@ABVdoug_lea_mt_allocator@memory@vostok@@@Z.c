mutex_mt_raii *__usercall mutex_mt_raii::mutex_mt_raii@<eax>(mutex_mt_raii *this@<ecx>, mutex_mt_raii *a2@<edi>)
{
  char m_instance; // al
  const vostok::memory::doug_lea_mt_allocator *v3; // esi
  DWORD CurrentThreadId; // eax
  const char *Value; // eax

  a2->m_instance = (const vostok::memory::doug_lea_mt_allocator *)this;
  m_instance = (char)this[13].m_instance;
  a2->m_is_tasks_aware = m_instance;
  if ( m_instance )
    vostok::threading::mutex::lock((vostok::threading::mutex *)&this[7]);
  else
    EnterCriticalSection((LPCRITICAL_SECTION)&this[10]);
  v3 = a2->m_instance;
  CurrentThreadId = GetCurrentThreadId();
  if ( v3->m_user_thread_id != CurrentThreadId )
  {
    _InterlockedExchange((volatile __int32 *)&v3->m_user_thread_id, CurrentThreadId);
    if ( v3->m_thread_id_const )
      v3->m_user_thread_id_called = 1;
  }
  Value = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !Value )
    Value = "undefined";
  v3->m_user_thread_logging_name = Value;
  return a2;
}
