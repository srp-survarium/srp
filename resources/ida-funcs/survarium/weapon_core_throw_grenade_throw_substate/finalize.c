void __thiscall survarium::weapon_core_throw_grenade_throw_substate::finalize(
        survarium::weapon_core_throw_grenade_throw_substate *this)
{
  survarium::base_player *v2; // ecx

  survarium::weapon_core_throw_grenade_base_substate::finalize(this);
  survarium::base_player::unsubscribe_animation_player(v2, (int)this->m_weapon->m_user, "shoot", (int)this);
}
