void __thiscall vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
        vostok::network_core::packet<vostok::network_core::udp_match_packet> *this,
        float value)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(4u, this, (unsigned __int8 *)&value);
}
