void __cdecl survarium::serialize_affect(
        vostok::network_core::udp_match_packet *packet,
        const stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *affect,
        int client_offset)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, affect->first);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
    packet,
    COERCE_FLOAT(affect->second - client_offset));
}
