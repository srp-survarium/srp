void __usercall vostok::strings::shared::profile::destroy(
        vostok::threading::mutex *mutex@<edi>,
        vostok::strings::shared::profile *string@<eax>)
{
  DWORD CurrentThreadId; // eax

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
  if ( string )
  {
    vostok::strings::shared::g_allocator.m_out_of_memory = 0;
    vostok_mspace_free((malloc_state *)vostok::strings::shared::g_allocator.m_arena, (char *)string);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)mutex);
}
