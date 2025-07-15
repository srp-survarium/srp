void __thiscall survarium::player_input::serialize(
        survarium::player_input *this,
        vostok::network_core::udp_match_packet *packet)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, &this->angular_velocity);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, &this->angular_acceleration);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, *(float *)&this->actions_mask);
}
