void __thiscall vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
        vostok::network_core::packet<vostok::network_core::udp_match_packet> *this,
        unsigned __int16 value)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(2u, this, (unsigned __int8 *)&value);
}
