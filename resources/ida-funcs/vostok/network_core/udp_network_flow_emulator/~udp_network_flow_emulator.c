void __thiscall vostok::network_core::udp_network_flow_emulator::~udp_network_flow_emulator(
        vostok::network_core::udp_network_flow_emulator *this)
{
  survarium::game_camera *v1; // ecx

  while ( this->m_delayed_packets._M_impl._M_start != this->m_delayed_packets._M_impl._M_finish )
  {
    vostok::network_core::delete_udp_match_packet(
      this->m_packets_allocator,
      (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&this->m_delayed_packets._M_impl._M_finish[-1]);
    --this->m_delayed_packets._M_impl._M_finish;
  }
  stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>>,vostok::vectora_allocator<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>>>>::~_Impl_vector<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>>,vostok::vectora_allocator<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>>>>(&this->m_delayed_packets._M_impl);
  survarium::weapon_user_dead_state::finalize(v1);
}
