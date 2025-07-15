void __thiscall survarium::base_network_client::~base_network_client(survarium::base_network_client *this)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v3; // edi
  vostok::memory::doug_lea_allocator *v4; // ecx
  survarium::stats_graph *m_linear_speed_graph; // edi
  vostok::memory::doug_lea_allocator *v6; // esi
  vostok::memory::doug_lea_allocator *v7; // ecx
  const char *v8; // [esp+0h] [ebp-Ch]
  const char *v9; // [esp+4h] [ebp-8h]
  unsigned int v10; // [esp+8h] [ebp-4h]

  v2 = survarium::g_allocator;
  if ( this->m_input_handler )
  {
    v3 = __RTCastToVoid((void **)&this->m_input_handler->__vftable);
    ((void (__thiscall *)(survarium::player_input_handler *, _DWORD))this->m_input_handler->~survarium::player_input_handler)(
      this->m_input_handler,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v4, (int)v2, v3, v8, v9, v10);
    this->m_input_handler = 0;
  }
  m_linear_speed_graph = this->m_linear_speed_graph;
  v6 = survarium::g_allocator;
  if ( m_linear_speed_graph )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<survarium::stats_graph>(m_linear_speed_graph);
    vostok::memory::doug_lea_allocator::free_impl(v7, (int)v6, (char *)m_linear_speed_graph, v8, v9, v10);
    this->m_linear_speed_graph = 0;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_last_current_player);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_current_player);
}
