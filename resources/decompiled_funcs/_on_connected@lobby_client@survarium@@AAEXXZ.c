void __thiscall survarium::lobby_client::on_connected(survarium::lobby_client *this)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v3; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::lobby_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<survarium::lobby_client *>,boost::arg<1> > > v4; // [esp-8h] [ebp-50h]
  unsigned __int8 buffer[4]; // [esp+10h] [ebp-38h] BYREF
  vostok::network_core::packet<vostok::network_core::tcp_packet> *session_id; // [esp+14h] [ebp-34h] BYREF
  vostok::network_core::tcp_packet packet; // [esp+18h] [ebp-30h] BYREF
  boost::function<void __cdecl(vostok::network_core::packet_reader &)> on_packet_received; // [esp+28h] [ebp-20h] BYREF

  v4.l_.a1_.t_ = this;
  v4.f_.f_ = survarium::lobby_client::sign_in_on_packet_received;
  on_packet_received.vtable = 0;
  boost::function1<void,vostok::network_core::packet_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::lobby_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<survarium::lobby_client *>,boost::arg<1>>>>(
    (boost::function1<void,vostok::network_core::packet_reader &> *)this,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::lobby_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<survarium::lobby_client *>,boost::arg<1> > > *)&on_packet_received,
    v4);
  vostok::network::tcp_packet_client::set_on_packet_received(&this->m_packet_client, &on_packet_received);
  if ( on_packet_received.vtable )
  {
    if ( ((int)on_packet_received.vtable & 1) == 0 )
    {
      v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_packet_received.vtable & 0xFFFFFFFE);
      if ( v2 )
        v2(&on_packet_received.functor, &on_packet_received.functor, 2);
    }
  }
  vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
  buffer[0] = 38;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v3, (int)&packet, buffer, 1u);
  session_id = (vostok::network_core::packet<vostok::network_core::tcp_packet> *)this->m_connection_info.session_id;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    session_id,
    (int)&packet,
    (unsigned __int8 *)&session_id,
    4u);
  vostok::network::tcp_packet_client::send(&this->m_packet_client, &packet);
  if ( packet.m_buffer )
  {
    if ( packet.m_buffer != (unsigned __int8 *)3 )
      packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
  }
}
