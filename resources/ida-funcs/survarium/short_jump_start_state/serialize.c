void __thiscall survarium::short_jump_start_state::serialize(
        survarium::short_jump_start_state *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx

  survarium::jump_logic_base_state::serialize(this, writer, client_writer);
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_jump_animation_ended,
    v4,
    writer,
    ".\\short_jump_start_state.cpp",
    (const char *)0x9E,
    "survarium::short_jump_start_state::serialize",
    "m_jump_animation_ended");
}
