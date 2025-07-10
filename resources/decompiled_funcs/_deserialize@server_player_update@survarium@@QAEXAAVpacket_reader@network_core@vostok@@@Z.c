void __userpurge survarium::server_player_update::deserialize(
        survarium::server_player_update *this@<ecx>,
        float a2@<xmm0>,
        vostok::network_core::packet_reader *packet)
{
  survarium::player_input::deserialize(&this->input, packet);
  survarium::player_state::deserialize(&this->state, a2, packet);
  survarium::weapon_state::deserialize(&this->weapon_state, packet);
}
