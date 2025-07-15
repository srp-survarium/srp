// attributes: thunk
void __thiscall survarium::weapon_core_melee_state::serialize(
        survarium::weapon_core_melee_state *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  survarium::weapon_core_base_state::serialize(this, writer, client_writer);
}
