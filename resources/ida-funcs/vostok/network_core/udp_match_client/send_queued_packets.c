void __thiscall vostok::network_core::udp_match_client::send_queued_packets(
        vostok::network_core::udp_match_client *this,
        int current_time_in_ms,
        boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::system::error_code const &,unsigned int)> const &)> *a3)
{
  vostok::network_core::udp_network_flow_emulator *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::network_core::udp_match_client *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::udp_match_client,vostok::network_core::buffer_reader &,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> const &,vostok::network_core::socket_handler *>,boost::_bi::list4<boost::_bi::value<vostok::network_core::udp_match_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > v6; // [esp-8h] [ebp-38h]
  int v7; // [esp+0h] [ebp-30h]
  const boost::function<void __cdecl(vostok::network_core::buffer_reader &,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> const &,vostok::network_core::socket_handler *)> *v8; // [esp+0h] [ebp-30h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::udp_match_client,vostok::network_core::buffer_reader &,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> const &,vostok::network_core::socket_handler *>,boost::_bi::list4<boost::_bi::value<vostok::network_core::udp_match_client *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > time_in_ms[4]; // [esp+10h] [ebp-20h] BYREF

  if ( !*(_DWORD *)(current_time_in_ms + 5584)
    || (v6.l_.a1_.t_ = (vostok::network_core::udp_match_client *)current_time_in_ms,
        v6.f_.f_ = vostok::network_core::udp_match_client::process_incoming_packet,
        boost::function<void __cdecl (vostok::network_core::buffer_reader &,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> const &,vostok::network_core::socket_handler *)>::function<void __cdecl (vostok::network_core::buffer_reader &,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> const &,vostok::network_core::socket_handler *)>(
          (boost::function<void __cdecl(vostok::network_core::buffer_reader &,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> const &,vostok::network_core::socket_handler *)> *)this,
          time_in_ms,
          v6,
          v7),
        vostok::network_core::udp_network_flow_emulator::tick(
          v3,
          *(_DWORD *)(current_time_in_ms + 5584),
          time_in_ms,
          v8),
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v4,
          (int *)time_in_ms),
        *(_DWORD *)(current_time_in_ms + 2820) != 3) )
  {
    *(_DWORD *)(current_time_in_ms + 5588) = a3;
    vostok::timing::timer::start((vostok::timing::timer *)this, (LARGE_INTEGER *)(current_time_in_ms + 2920));
    vostok::network_core::udp_match_client::send_queued_packets_impl(v5, current_time_in_ms, a3);
  }
}
