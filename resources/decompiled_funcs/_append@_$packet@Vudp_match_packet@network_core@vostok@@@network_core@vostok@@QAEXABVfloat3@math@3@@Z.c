void __usercall vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
        vostok::network_core::packet<vostok::network_core::udp_match_packet> *this@<ecx>,
        vostok::math::float3 *value@<eax>)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(0xCu, this, (unsigned __int8 *)value);
}
