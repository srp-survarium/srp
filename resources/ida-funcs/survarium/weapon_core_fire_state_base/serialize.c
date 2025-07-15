void __thiscall survarium::weapon_core_fire_state_base::serialize(
        survarium::weapon_core_fire_state_base *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx

  survarium::weapon_core_animation_end_aware_state::serialize(this, writer, client_writer);
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_keep_shooting,
    v4,
    writer,
    ".\\weapon_core_fire_state_base.cpp",
    (const char *)0x6F,
    "survarium::weapon_core_fire_state_base::serialize",
    "m_keep_shooting");
}
