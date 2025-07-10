void __thiscall vostok::network_core::udp_match_connection::enqueue(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::udp_match_packet *packet)
{
  if ( this->m_state )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    vostok::network_core::delete_udp_match_packet(
      this->m_packets_allocator,
      (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&packet);
  }
  else
  {
    vostok::network_core::udp_match_connection::enqueue_impl(this, packet);
  }
}
