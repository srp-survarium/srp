void __usercall survarium::lobby_client::lobby_client(survarium::lobby_client *this@<edi>, survarium::game *g@<eax>)
{
  vostok::memory::base_allocator *f; // ecx
  boost::function0<void> *v3; // ecx
  boost::function0<void> *v4; // ecx
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code> *v6; // ecx
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::lobby_client>,boost::_bi::list1<boost::_bi::value<survarium::lobby_client *> > > v9; // [esp-8h] [ebp-3Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::lobby_client>,boost::_bi::list1<boost::_bi::value<survarium::lobby_client *> > > v10; // [esp-8h] [ebp-3Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::lobby_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<survarium::lobby_client *>,boost::arg<1>,boost::arg<2> > > v11; // [esp-8h] [ebp-3Ch]
  boost::function<void __cdecl(void)> on_connected; // [esp+10h] [ebp-24h] BYREF

  this->m_game = g;
  vostok::network::tcp_packet_client::tcp_packet_client(&this->m_packet_client, g->m_network_world);
  this->m_on_packet_received.vtable = 0;
  this->m_on_connected.vtable = 0;
  this->m_on_disconnected.vtable = 0;
  this->m_status = unknown;
  this->m_net_client_connected = 0;
  this->m_team_id = team_undefined;
  this->m_match_id = -1;
  this->m_match_order_id = -1;
  this->m_last_status_message.m_begin = this->m_last_status_message.m_buffer;
  this->m_last_status_message.m_end = this->m_last_status_message.m_buffer;
  this->m_last_status_message.m_buffer[0] = 0;
  this->m_last_status_message.m_max_end = (char *)&this->m_player_name;
  this->m_player_name.m_begin = this->m_player_name.m_buffer;
  this->m_player_name.m_end = this->m_player_name.m_buffer;
  this->m_player_name.m_buffer[0] = 0;
  this->m_player_name.m_max_end = (char *)&this->m_profiles_count;
  this->m_profiles_count = 0;
  `vector constructor iterator'(
    (char *)this->m_profiles,
    0x1B8u,
    3,
    (void *(__thiscall *)(void *))survarium::player_profile::player_profile);
  f = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  this->m_inventory_item_instances._M_impl._M_start = 0;
  this->m_inventory_item_instances._M_impl._M_finish = 0;
  this->m_inventory_item_instances._M_impl._M_end_of_storage.m_allocator = f;
  this->m_inventory_item_instances._M_impl._M_end_of_storage._M_data = 0;
  this->m_player_skills = 0;
  this->m_player_skills_count = 0;
  this->m_player_reputations = 0;
  this->m_player_reputations_count = 0;
  this->m_account_money.generic_money = 0;
  this->m_account_money.premium_money = 0;
  this->m_account_money.total_skill_points = 0;
  this->m_player_perks = 0;
  this->m_player_perks_count = 0;
  this->m_profile_slot_restrictions = 0;
  this->m_profile_slot_restrictions_count = 0;
  this->m_items_compatibility = 0;
  this->m_items_compatibilities_count = 0;
  this->m_skills_tree_config.m_object = 0;
  this->m_discard_playing_order_on_connected = 0;
  this->m_connection_info.session_id = -1;
  this->m_connection_info.host[0] = 0;
  this->m_connection_info.port = 0;
  this->m_connection_info.need_resolve = 1;
  this->m_connection_info.connection_error_count = 0;
  memset((int)this->m_prices, 0, sizeof(this->m_prices));
  v9.l_.a1_.t_ = this;
  v9.f_.f_ = survarium::lobby_client::on_connected;
  on_connected.vtable = 0;
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::lobby_client>,boost::_bi::list1<boost::_bi::value<survarium::lobby_client *>>>>(
    v3,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::lobby_client>,boost::_bi::list1<boost::_bi::value<survarium::lobby_client *> > > *)&on_connected,
    v9);
  vostok::network::tcp_packet_client::set_on_connected(&this->m_packet_client, &on_connected);
  if ( on_connected.vtable )
  {
    if ( ((int)on_connected.vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_connected.vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&on_connected.functor, &on_connected.functor, 2);
    }
  }
  v10.l_.a1_.t_ = this;
  v10.f_.f_ = survarium::lobby_client::on_disconnected;
  on_connected.vtable = 0;
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::lobby_client>,boost::_bi::list1<boost::_bi::value<survarium::lobby_client *>>>>(
    v4,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::lobby_client>,boost::_bi::list1<boost::_bi::value<survarium::lobby_client *> > > *)&on_connected,
    v10);
  vostok::network::tcp_packet_client::set_on_disconnected(&this->m_packet_client, &on_connected);
  if ( on_connected.vtable )
  {
    if ( ((int)on_connected.vtable & 1) == 0 )
    {
      v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_connected.vtable & 0xFFFFFFFE);
      if ( v7 )
        v7(&on_connected.functor, &on_connected.functor, 2);
    }
  }
  v11.l_.a1_.t_ = this;
  v11.f_.f_ = survarium::lobby_client::on_error;
  on_connected.vtable = 0;
  boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::lobby_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<survarium::lobby_client *>,boost::arg<1>,boost::arg<2>>>>(
    v6,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::lobby_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<survarium::lobby_client *>,boost::arg<1>,boost::arg<2> > > *)&on_connected,
    v11);
  vostok::network::tcp_packet_client::set_on_error(
    &this->m_packet_client,
    (const boost::function<void __cdecl(enum vostok::network_core::client_error_codes_enum,boost::system::error_code)> *)&on_connected);
  if ( on_connected.vtable && ((int)on_connected.vtable & 1) == 0 )
  {
    v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_connected.vtable & 0xFFFFFFFE);
    if ( v8 )
      v8(&on_connected.functor, &on_connected.functor, 2);
  }
}
