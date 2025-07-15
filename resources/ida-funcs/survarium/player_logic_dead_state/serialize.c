void __thiscall survarium::player_logic_dead_state::serialize(
        survarium::player_logic_dead_state *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_is_ready_to_be_deactivated,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\player_logic_dead_state.cpp",
    (const char *)0x2A,
    "survarium::player_logic_dead_state::serialize",
    "m_is_ready_to_be_deactivated");
}
