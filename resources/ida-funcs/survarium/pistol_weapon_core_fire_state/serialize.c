void __thiscall survarium::pistol_weapon_core_fire_state::serialize(
        survarium::pistol_weapon_core_fire_state *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx

  survarium::weapon_core_fire_state_base::serialize(this, writer, client_writer);
  vostok::network_core::buffer_writer::w<unsigned char>(
    &this->m_weapon_animation_index,
    v4,
    writer,
    ".\\pistol_weapon_core_fire_state.cpp",
    (const char *)0x7B,
    "survarium::pistol_weapon_core_fire_state::serialize",
    "m_weapon_animation_index");
}
