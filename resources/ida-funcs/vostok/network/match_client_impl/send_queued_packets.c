void __thiscall vostok::network::match_client_impl::send_queued_packets(
        vostok::network::match_client_impl *this,
        boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::system::error_code const &,unsigned int)> const &)> *current_time_in_ms)
{
  if ( *(_DWORD *)((char *)&loc_55F64 + (_DWORD)this) != 3 )
    vostok::network_core::udp_match_client::send_queued_packets(
      (vostok::network_core::udp_match_client *)((char *)this + (_DWORD)&loc_5545C + 4),
      (unsigned int)this + (_DWORD)&loc_5545C + 4,
      current_time_in_ms);
}
