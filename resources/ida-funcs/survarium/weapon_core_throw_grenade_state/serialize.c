void __thiscall survarium::weapon_core_throw_grenade_state::serialize(
        survarium::weapon_core_throw_grenade_state *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::ai::fsm *v4; // ecx

  survarium::weapon_core_base_state::serialize(this, writer, client_writer);
  vostok::ai::fsm::serialize(v4, (int)&this->m_logic, writer, client_writer);
}
