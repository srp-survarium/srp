void __thiscall survarium::messaging_client::disconnect(survarium::messaging_client *this)
{
  boost::function1<void,vostok::physics::contact_point const &> *p_m_network_client; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> v3; // [esp+8h] [ebp-20h] BYREF

  if ( this->m_connection_state != client_disconnected )
  {
    p_m_network_client = (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_network_client;
    this->m_connection_state = client_disconnected;
    vostok::network::tcp_packet_client::disconnect(
      (vostok::network::tcp_packet_client *)this,
      (int)&this->m_network_client);
    v3.vtable = 0;
    boost::function<void __cdecl (boost::system::error_code)>::operator=(&v3, p_m_network_client);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v2,
      (int *)&v3);
  }
}
