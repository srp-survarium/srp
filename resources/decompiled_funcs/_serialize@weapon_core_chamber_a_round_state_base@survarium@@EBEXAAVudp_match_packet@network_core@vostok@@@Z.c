void __thiscall survarium::weapon_core_chamber_a_round_state_base::serialize(
        survarium::weapon_core_chamber_a_round_state_base *this,
        vostok::network_core::udp_match_packet *packet)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_animation_has_been_ended);
}
