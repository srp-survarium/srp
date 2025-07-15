void __thiscall survarium::jump_logic_state_prepare::serialize(
        survarium::jump_logic_state_prepare *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx

  survarium::jump_logic_base_state::serialize(this, writer, client_writer);
  vostok::network_core::buffer_writer::w<float>(
    &this->m_time_scale,
    v4,
    writer,
    ".\\jump_logic_state_prepare.cpp",
    (const char *)0x87,
    "survarium::jump_logic_state_prepare::serialize",
    "m_time_scale");
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_prepare_interval_ended,
    v5,
    writer,
    ".\\jump_logic_state_prepare.cpp",
    (const char *)0x88,
    "survarium::jump_logic_state_prepare::serialize",
    "m_prepare_interval_ended");
}
