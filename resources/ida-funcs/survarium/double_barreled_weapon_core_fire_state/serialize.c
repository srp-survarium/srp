void __thiscall survarium::double_barreled_weapon_core_fire_state::serialize(
        survarium::double_barreled_weapon_core_fire_state *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx

  survarium::weapon_core_fire_state_base::serialize(this, writer, client_writer);
  vostok::network_core::buffer_writer::w<unsigned char>(
    &this->m_weapon_animation_index,
    v4,
    writer,
    ".\\double_barreled_weapon_core_fire_state.cpp",
    (const char *)0x7A,
    "survarium::double_barreled_weapon_core_fire_state::serialize",
    "m_weapon_animation_index");
}
