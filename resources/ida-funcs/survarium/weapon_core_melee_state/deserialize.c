void __thiscall survarium::weapon_core_melee_state::deserialize(
        survarium::weapon_core_melee_state *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  survarium::weapon_core_base_state::deserialize(this, reader, client_reader);
  this->subscribe_animation_player(this);
}
