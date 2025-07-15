void __thiscall vostok::network::match_client_impl::set_connection_ports(
        vostok::network::match_client_impl *this,
        int ping_message_type,
        unsigned int session_id,
        vostok::network_core::udp_match_client *first_port,
        unsigned __int16 last_port)
{
  vostok::network_core::udp_match_client::set_connection_ports(
    (vostok::network_core::udp_match_client *)((char *)this + (_DWORD)&loc_5545C + 4),
    first_port,
    ping_message_type,
    session_id,
    last_port);
}
