void __thiscall survarium::messaging_client::on_connected(survarium::messaging_client *this)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v3; // ecx
  vostok::network::login_client *v4; // eax
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::messaging_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<survarium::messaging_client *>,boost::arg<1> > > v6; // [esp-8h] [ebp-50h]
  unsigned __int8 buffer[4]; // [esp+10h] [ebp-38h] BYREF
  vostok::network_core::packet<vostok::network_core::tcp_packet> v8; // [esp+14h] [ebp-34h] BYREF
  int v9; // [esp+20h] [ebp-28h]
  boost::function<void __cdecl(vostok::network_core::packet_reader &)> on_packet_received; // [esp+28h] [ebp-20h] BYREF

  v6.l_.a1_.t_ = this;
  v6.f_.f_ = survarium::messaging_client::sign_in_on_packet_received;
  this->m_connection_state = client_connecting;
  on_packet_received.vtable = 0;
  boost::function1<void,vostok::network_core::packet_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::messaging_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<survarium::messaging_client *>,boost::arg<1>>>>(
    (boost::function1<void,vostok::network_core::packet_reader &> *)this,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::messaging_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<survarium::messaging_client *>,boost::arg<1> > > *)&on_packet_received,
    v6);
  vostok::network::tcp_packet_client::set_on_packet_received(
    &this->m_network_client,
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)&on_packet_received);
  if ( on_packet_received.vtable )
  {
    if ( ((int)on_packet_received.vtable & 1) == 0 )
    {
      v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_packet_received.vtable & 0xFFFFFFFE);
      if ( v2 )
        v2(&on_packet_received.functor, &on_packet_received.functor, 2);
    }
  }
  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&v8.m_buffer_size,
    &vostok::memory::g_mt_allocator);
  buffer[0] = -61;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v3, (int)&v8.m_buffer_size, buffer, 1u);
  v4 = this->m_game->m_network_client->login_client(this->m_game->m_network_client);
  v8.m_buffer = (unsigned __int8 *)vostok::network::login_client::session_id(v4);
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    &v8,
    (int)&v8.m_buffer_size,
    (unsigned __int8 *)&v8,
    4u);
  buffer[0] = 5;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v5, (int)&v8.m_buffer_size, buffer, 1u);
  vostok::network::tcp_packet_client::send(
    &this->m_network_client,
    (const vostok::network_core::tcp_packet *)&v8.m_buffer_size);
  if ( v8.m_buffer_size )
  {
    if ( v8.m_buffer_size != 3 )
      (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v9 + 24))(v9, v8.m_buffer_size - 3);
  }
}
