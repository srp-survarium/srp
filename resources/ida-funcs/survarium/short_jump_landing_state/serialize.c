// attributes: thunk
void __thiscall survarium::short_jump_landing_state::serialize(
        survarium::short_jump_landing_state *this,
        const vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  survarium::jump_logic_base_state::serialize(this, writer, client_writer);
}
