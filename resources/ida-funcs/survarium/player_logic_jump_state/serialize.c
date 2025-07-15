void __thiscall survarium::player_logic_jump_state::serialize(
        survarium::player_logic_jump_state *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx

  survarium::jump_logic::serialize((survarium::jump_logic *)this, (int)&this->m_logic, writer, client_writer);
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_is_sprinting,
    v4,
    writer,
    ".\\player_logic_jump_state.cpp",
    (const char *)0x59,
    "survarium::player_logic_jump_state::serialize",
    "m_is_sprinting");
}
