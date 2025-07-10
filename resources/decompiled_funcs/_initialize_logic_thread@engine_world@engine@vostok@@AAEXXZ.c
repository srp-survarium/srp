void __thiscall vostok::engine::engine_world::initialize_logic_thread(vostok::engine::engine_world *this)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  DWORD CurrentThreadId; // eax
  const char *Value; // eax

  v1 = this->m_engine_user_module_proxy->allocator(this->m_engine_user_module_proxy);
  CurrentThreadId = GetCurrentThreadId();
  if ( v1->m_user_thread_id != CurrentThreadId )
  {
    _InterlockedExchange((volatile __int32 *)&v1->m_user_thread_id, CurrentThreadId);
    if ( v1->m_thread_id_const )
      v1->m_user_thread_id_called = 1;
  }
  Value = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !Value )
    Value = "undefined";
  v1->m_user_thread_logging_name = Value;
}
