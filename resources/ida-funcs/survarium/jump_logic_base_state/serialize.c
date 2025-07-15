void __thiscall survarium::jump_logic_base_state::serialize(
        survarium::jump_logic_base_state *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx

  vostok::network_core::buffer_writer::w<unsigned char>(
    &this->m_interval_id_to_wait_for,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\jump_logic_base_state.cpp",
    (const char *)0x11,
    "survarium::jump_logic_base_state::serialize",
    "m_interval_id_to_wait_for");
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_is_jump_finished,
    v4,
    writer,
    ".\\jump_logic_base_state.cpp",
    (const char *)0x12,
    "survarium::jump_logic_base_state::serialize",
    "m_is_jump_finished");
}
