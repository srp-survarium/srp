vostok::strings::shared::profile *__cdecl vostok::strings::shared::profile::create(
        vostok::threading::mutex *mutex,
        char *value,
        const vostok::strings::shared::profile *temp)
{
  unsigned int v3; // edi
  DWORD CurrentThreadId; // eax
  int *v5; // esi

  v3 = temp->m_length + 1;
  vostok::threading::mutex::lock(mutex);
  CurrentThreadId = GetCurrentThreadId();
  if ( vostok::strings::shared::g_allocator.m_user_thread_id != CurrentThreadId )
  {
    _InterlockedExchange((volatile __int32 *)&vostok::strings::shared::g_allocator.m_user_thread_id, CurrentThreadId);
    if ( vostok::strings::shared::g_allocator.m_thread_id_const )
      vostok::strings::shared::g_allocator.m_user_thread_id_called = 1;
  }
  vostok::strings::shared::g_allocator.m_user_thread_logging_name = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !vostok::strings::shared::g_allocator.m_user_thread_logging_name )
    vostok::strings::shared::g_allocator.m_user_thread_logging_name = "undefined";
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(&vostok::strings::shared::g_allocator, v3 + 16);
  LeaveCriticalSection((LPCRITICAL_SECTION)mutex);
  v5[1] = 0;
  *v5 = 0;
  v5[2] = temp->m_length;
  v5[3] = temp->m_checksum;
  memcpy((unsigned __int8 *)v5 + 16, (unsigned __int8 *)value, v3);
  return (vostok::strings::shared::profile *)v5;
}
