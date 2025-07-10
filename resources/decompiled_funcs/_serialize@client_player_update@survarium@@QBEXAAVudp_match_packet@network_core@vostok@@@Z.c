void __thiscall survarium::client_player_update::serialize(
        survarium::client_player_update *this,
        vostok::network_core::udp_match_packet *packet)
{
  survarium::player_input::serialize(&this->input, packet);
  survarium::player_state::serialize(&this->state, packet);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, *(float *)&this->time_in_ms);
}
