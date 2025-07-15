void __thiscall survarium::weapon_core_throw_grenade_idle_substate::finalize(
        survarium::weapon_core_throw_grenade_idle_substate *this)
{
  survarium::base_player *v2; // ecx

  survarium::weapon_core_throw_grenade_base_substate::finalize(this);
  survarium::base_player::unsubscribe_animation_player(
    v2,
    (vostok::animation::reserved_channel_ids_enum)this->m_weapon->m_user,
    (const void *)1,
    (int)this);
}
