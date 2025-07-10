void __thiscall vostok::network::match_client::~match_client(vostok::network::match_client *this)
{
  vostok::memory::base_allocator *v1; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::network::response *v6; // [esp+4h] [ebp-40h]
  vostok::network::match_client_impl **m_client; // [esp+18h] [ebp-2Ch]
  vostok::network::network_world *v9; // [esp+1Ch] [ebp-28h]
  vostok::memory::base_allocator *m_owner_allocator; // [esp+20h] [ebp-24h]
  void *_Where; // [esp+28h] [ebp-1Ch]
  vostok::network::network_world *m_world; // [esp+30h] [ebp-14h]
  char *v13; // [esp+3Ch] [ebp-8h]

  m_world = this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world->m_channel.orders.m_owner_allocator);
  _Where = vostok::memory::base_allocator::malloc_impl(v1, 0x14u);
  v13 = (char *)operator new(0x14u, _Where);
  if ( v13 )
  {
    v9 = this->m_world;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v9);
    m_owner_allocator = v9->m_channel.orders.m_owner_allocator;
    m_client = this->m_client;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)(v13 + 4));
    *(_DWORD *)v13 = &vostok::network::order::`vftable';
    *(_DWORD *)v13 = &client_destroyer::`vftable';
    vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
      &this->m_response_packets_allocator,
      (vostok::network_core::udp_match_packets_allocator **)v13 + 2);
    *((_DWORD *)v13 + 3) = m_owner_allocator;
    *((_DWORD *)v13 + 4) = m_client;
    v6 = (vostok::network::response *)v13;
  }
  else
  {
    v6 = 0;
  }
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::operator=(
    0,
    (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **)&this->m_response_packets_allocator);
  vostok::network::network_world::add_order(this->m_world, v6);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (int *)&this->m_on_disconnected);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v3,
    (int *)&this->m_on_packet_received);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    (int *)&this->m_on_connected);
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::~intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(&this->m_response_packets_allocator);
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::~intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(&this->m_order_packets_allocator);
  survarium::weapon_user_dead_state::finalize(v5);
}
