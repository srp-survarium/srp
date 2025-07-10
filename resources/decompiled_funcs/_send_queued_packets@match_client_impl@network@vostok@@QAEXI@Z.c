void __thiscall vostok::network::match_client_impl::send_queued_packets(
        vostok::network::match_client_impl *this,
        unsigned int current_time_in_ms)
{
  if ( *(int *)((char *)&dword_258154 + (_DWORD)this) != 3 )
    vostok::network_core::udp_match_client::send_queued_packets(
      (vostok::network_core::udp_match_client *)((char *)this + (_DWORD)&loc_258034 + 4),
      current_time_in_ms);
}
