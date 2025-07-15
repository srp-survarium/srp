void __thiscall survarium::weapon_core_shotgun_reload_state::deserialize(
        survarium::weapon_core_shotgun_reload_state *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  survarium::weapon_core_base_state::deserialize(this, reader, client_reader);
  vostok::ai::fsm::deserialize(this->m_logic, reader, client_reader);
}
