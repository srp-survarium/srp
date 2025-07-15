void __thiscall survarium::weapon_core_throw_grenade_base_substate::serialize(
        survarium::weapon_core_throw_grenade_base_substate *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx

  vostok::network_core::buffer_writer::w<bool>(
    &this->m_animation_has_been_ended,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\weapon_core_throw_grenade_substate.cpp",
    (const char *)0x31,
    "survarium::weapon_core_throw_grenade_base_substate::serialize",
    "m_animation_has_been_ended");
  vostok::network_core::buffer_writer::w<unsigned char>(
    &this->m_index_of_animation_to_wait,
    v4,
    writer,
    ".\\weapon_core_throw_grenade_substate.cpp",
    (const char *)0x32,
    "survarium::weapon_core_throw_grenade_base_substate::serialize",
    "m_index_of_animation_to_wait");
}
