void __thiscall vostok::network::tcp_packet_client::connect_impl(
        vostok::network::tcp_packet_client *this,
        char *host,
        boost::asio::ip::tcp port)
{
  vostok::network_core::tcp_packet_client *m_client; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network_core::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *> > > v5; // [esp-8h] [ebp-30h]
  int v6; // [esp+0h] [ebp-28h]
  boost::function<void __cdecl(void)> on_connected; // [esp+8h] [ebp-20h] BYREF

  m_client = this->m_client;
  v5.l_.a1_.t_ = m_client;
  v5.f_.f_ = vostok::network_core::tcp_packet_client::on_connected;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function<void __cdecl(void)> *)this,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network_core::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *> > > *)&on_connected,
    v5,
    v6);
  vostok::network_core::async_connector::connect(
    &m_client->m_socket,
    &on_connected,
    &m_client->m_async_connector,
    host,
    port,
    (boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *)&m_client->m_on_error);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&on_connected);
}
