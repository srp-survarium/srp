void __thiscall survarium::weapon_core_hide_state_base::deserialize(
        survarium::weapon_core_hide_state_base *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  survarium::weapon_core_animation_end_aware_state::deserialize(this, reader, client_reader);
  this->m_is_ready_to_be_deactivated = this->m_animation_has_been_ended;
}
