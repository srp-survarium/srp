void __thiscall survarium::weapon_core_throw_grenade_pull_substate::initialize(
        survarium::weapon_core_throw_grenade_pull_substate *this)
{
  survarium::weapon_core_throw_grenade_pull_substate_vtbl *v2; // eax
  survarium::grenade_set_core *v3; // ecx

  v2 = this->__vftable;
  this->m_animation_has_been_ended = 0;
  ((void (*)(void))v2->subscribe_animation_player)();
  survarium::grenade_set_core::pull_pin(
    v3,
    (int)this->m_owner->m_grenade_set.m_object,
    this->m_weapon->m_user->m_current_time_in_ms);
}
