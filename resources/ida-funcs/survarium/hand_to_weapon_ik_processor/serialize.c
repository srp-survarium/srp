void __thiscall survarium::hand_to_weapon_ik_processor::serialize(
        survarium::hand_to_weapon_ik_processor *this,
        vostok::network_core::udp_match_packet *packet,
        unsigned int client_offset)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
    packet,
    (this->m_hands[1].is_active ? 2 : 0) | this->m_hands[0].is_active);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
    packet,
    COERCE_FLOAT(this->m_hands[0].start_transition_time_in_ms - client_offset));
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
    packet,
    COERCE_FLOAT(this->m_hands[1].start_transition_time_in_ms - client_offset));
}
