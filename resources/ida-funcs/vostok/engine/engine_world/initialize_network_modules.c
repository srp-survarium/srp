void __thiscall vostok::engine::engine_world::initialize_network_modules(vostok::engine::engine_world *this)
{
  vostok::memory::doug_lea_allocator *p_m_network_allocator; // esi
  vostok::network::engine *v3; // esi
  vostok::memory::doug_lea_allocator *v4; // eax
  vostok::network::network_world *v5; // ecx

  p_m_network_allocator = &this->m_network_allocator;
  vostok::memory::doug_lea_allocator::user_current_thread_id(
    (vostok::memory::doug_lea_allocator *)this,
    (int)&this->m_network_allocator);
  vostok::network::g_allocator = p_m_network_allocator;
  vostok::network_core::g_allocator = p_m_network_allocator;
  if ( this )
    v3 = (vostok::network::engine *)&this->gapC;
  else
    v3 = 0;
  v4 = this->m_engine_user_module_proxy->allocator(this->m_engine_user_module_proxy);
  vostok::network::network_world::network_world(v5, (int)&s_world_2, v3, v4);
  _InterlockedExchange(&s_world_2.m_initialized, 1);
  _InterlockedExchange((volatile __int32 *)&this->m_network_world, (__int32)s_world_2.m_variable);
}
