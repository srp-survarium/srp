void __thiscall survarium::jump_logic_state_start::serialize(
        survarium::jump_logic_state_start *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx

  survarium::jump_logic_base_state::serialize(this, writer, client_writer);
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_preface_interval_ended,
    v4,
    writer,
    ".\\jump_logic_state_start.cpp",
    (const char *)0xB2,
    "survarium::jump_logic_state_start::serialize",
    "m_preface_interval_ended");
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_jump_interval_ended,
    v5,
    writer,
    ".\\jump_logic_state_start.cpp",
    (const char *)0xB3,
    "survarium::jump_logic_state_start::serialize",
    "m_jump_interval_ended");
}
