void __thiscall vostok::network_core::udp_match_client::process_incoming_packet(
        vostok::network_core::udp_match_client *this,
        vostok::network_core::packet_reader *reader,
        const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *endpoint)
{
  _BYTE *v3; // eax
  survarium::game_camera *v4; // ecx
  vostok::network_core::udp_match_client *v5; // ecx
  vostok::network_core::process_packet_predicate predicate; // [esp+B0h] [ebp-8h] BYREF
  char v8; // [esp+B6h] [ebp-2h]
  char v9; // [esp+B7h] [ebp-1h]

  v9 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v3 )
  {
    boost::asio::ip::detail::operator==(&endpoint->impl_, &this->m_server_endpoint.impl_);
    survarium::weapon_user_dead_state::finalize(v4);
  }
  v5 = this;
  if ( !this->m_network_flow_emulator
    || (v5 = (vostok::network_core::udp_match_client *)(this->m_connection.m_state == disconnected),
        this->m_connection.m_state != disconnected) )
  {
    v8 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&predicate);
    predicate.m_client = this;
    vostok::network_core::udp_match_connection::process_incoming_packet<vostok::network_core::process_packet_predicate>(
      &this->m_connection,
      reader,
      &predicate);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&predicate);
  }
}
