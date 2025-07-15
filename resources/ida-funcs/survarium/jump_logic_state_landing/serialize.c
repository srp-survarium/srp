void __thiscall survarium::jump_logic_state_landing::serialize(
        survarium::jump_logic_state_landing *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx

  survarium::jump_logic_base_state::serialize(this, writer, client_writer);
  HIBYTE(client_writer) = this->m_landing_type;
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)&client_writer + 3,
    v4,
    writer,
    ".\\jump_logic_state_landing.cpp",
    (const char *)0xAB,
    "survarium::jump_logic_state_landing::serialize",
    "static_cast< u8 >( m_landing_type )");
}
