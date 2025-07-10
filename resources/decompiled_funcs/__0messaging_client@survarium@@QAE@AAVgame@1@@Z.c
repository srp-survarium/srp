void __usercall survarium::messaging_client::messaging_client(
        survarium::messaging_client *this@<edi>,
        survarium::game *g@<eax>)
{
  vostok::memory::base_allocator *f; // eax
  boost::function0<void> *v3; // ecx
  boost::function0<void> *v4; // ecx
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code> *v6; // ecx
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::messaging_client>,boost::_bi::list1<boost::_bi::value<survarium::messaging_client *> > > v9; // [esp-8h] [ebp-3Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::messaging_client>,boost::_bi::list1<boost::_bi::value<survarium::messaging_client *> > > v10; // [esp-8h] [ebp-3Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::messaging_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<survarium::messaging_client *>,boost::arg<1>,boost::arg<2> > > v11; // [esp-8h] [ebp-3Ch]
  boost::function<void __cdecl(void)> on_connected; // [esp+10h] [ebp-24h] BYREF

  this->m_game = g;
  this->m_chat_handler = g->m_chat_handler;
  this->m_connection_state = client_disconnected;
  vostok::network::tcp_packet_client::tcp_packet_client(
    &this->m_network_client,
    (vostok::network::network_world *)g->m_network_world);
  f = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  this->m_match_channel_id_ = -1;
  this->m_friend_list._M_impl._M_start = 0;
  this->m_friend_list._M_impl._M_finish = 0;
  this->m_friend_list._M_impl._M_end_of_storage.m_allocator = f;
  this->m_friend_list._M_impl._M_end_of_storage._M_data = 0;
  this->m_ignore_list._M_impl._M_start = 0;
  this->m_ignore_list._M_impl._M_finish = 0;
  this->m_ignore_list._M_impl._M_end_of_storage.m_allocator = f;
  this->m_ignore_list._M_impl._M_end_of_storage._M_data = 0;
  this->m_found_players_list._M_impl._M_start = 0;
  this->m_found_players_list._M_impl._M_finish = 0;
  this->m_found_players_list._M_impl._M_end_of_storage.m_allocator = f;
  this->m_found_players_list._M_impl._M_end_of_storage._M_data = 0;
  *(_DWORD *)&this->m_scheduler_identifier &= ~0x80000000;
  this->m_connection_info.session_id = -1;
  this->m_connection_info.host[0] = 0;
  this->m_connection_info.port = 0;
  this->m_connection_info.need_resolve = 1;
  this->m_connection_info.connection_error_count = 0;
  sprintf_s<32>((char (*)[32])this->m_local_name, "local");
  v9.l_.a1_.t_ = this;
  v9.f_.f_ = survarium::messaging_client::on_connected;
  on_connected.vtable = 0;
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::messaging_client>,boost::_bi::list1<boost::_bi::value<survarium::messaging_client *>>>>(
    v3,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::messaging_client>,boost::_bi::list1<boost::_bi::value<survarium::messaging_client *> > > *)&on_connected,
    v9);
  vostok::network::tcp_packet_client::set_on_connected(&this->m_network_client, &on_connected);
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
  v10.f_.f_ = survarium::messaging_client::on_disconnected;
  on_connected.vtable = 0;
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::messaging_client>,boost::_bi::list1<boost::_bi::value<survarium::messaging_client *>>>>(
    v4,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::messaging_client>,boost::_bi::list1<boost::_bi::value<survarium::messaging_client *> > > *)&on_connected,
    v10);
  vostok::network::tcp_packet_client::set_on_disconnected(&this->m_network_client, &on_connected);
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
  v11.f_.f_ = survarium::messaging_client::on_error;
  on_connected.vtable = 0;
  boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::messaging_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<survarium::messaging_client *>,boost::arg<1>,boost::arg<2>>>>(
    v6,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::messaging_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<survarium::messaging_client *>,boost::arg<1>,boost::arg<2> > > *)&on_connected,
    v11);
  vostok::network::tcp_packet_client::set_on_error(
    &this->m_network_client,
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)&on_connected);
  if ( on_connected.vtable && ((int)on_connected.vtable & 1) == 0 )
  {
    v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_connected.vtable & 0xFFFFFFFE);
    if ( v8 )
      v8(&on_connected.functor, &on_connected.functor, 2);
  }
}
