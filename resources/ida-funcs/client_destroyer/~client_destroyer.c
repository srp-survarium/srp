void __thiscall client_destroyer::~client_destroyer(client_destroyer *this)
{
  vostok::memory::base_allocator *v1; // eax
  void **p_m_client; // [esp+Ch] [ebp-14h]

  this->__vftable = (client_destroyer_vtbl *)&client_destroyer::`vftable';
  p_m_client = (void **)&this->m_client;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_client);
  if ( *p_m_client )
  {
    vostok::memory::base_allocator::free_impl(v1, *p_m_client);
    *p_m_client = 0;
  }
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::~intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(&this->m_responses_allocator);
  this->__vftable = (client_destroyer_vtbl *)&vostok::network::order::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->next_for_orders);
}
