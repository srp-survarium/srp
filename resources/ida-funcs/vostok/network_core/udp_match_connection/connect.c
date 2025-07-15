void __thiscall vostok::network_core::udp_match_connection::connect(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::udp_match_packet *packet)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_state = connected;
  if ( packet )
    vostok::network_core::udp_match_connection::enqueue_impl(this, packet);
}
