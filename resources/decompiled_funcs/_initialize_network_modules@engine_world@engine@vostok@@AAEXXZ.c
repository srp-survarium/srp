void __thiscall vostok::engine::engine_world::initialize_network_modules(vostok::engine::engine_world *this)
{
  vostok::memory::doug_lea_allocator *p_m_network_allocator; // esi
  DWORD CurrentThreadId; // eax
  const char *Value; // eax
  vostok::network::engine *v5; // esi
  vostok::memory::doug_lea_allocator *v6; // eax

  p_m_network_allocator = &this->m_network_allocator;
  CurrentThreadId = GetCurrentThreadId();
  if ( p_m_network_allocator->m_user_thread_id != CurrentThreadId )
  {
    _InterlockedExchange((volatile __int32 *)&p_m_network_allocator->m_user_thread_id, CurrentThreadId);
    if ( p_m_network_allocator->m_thread_id_const )
      p_m_network_allocator->m_user_thread_id_called = 1;
  }
  Value = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !Value )
    Value = "undefined";
  p_m_network_allocator->m_user_thread_logging_name = Value;
  vostok::network::memory_allocator(p_m_network_allocator);
  if ( this )
    v5 = (vostok::network::engine *)&this->gapC;
  else
    v5 = 0;
  v6 = this->m_engine_user_module_proxy->allocator(this->m_engine_user_module_proxy);
  _InterlockedExchange((volatile __int32 *)&this->m_network_world, (__int32)vostok::network::create_world(v5, v6));
}
