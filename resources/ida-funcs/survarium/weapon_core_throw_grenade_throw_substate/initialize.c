void __thiscall survarium::weapon_core_throw_grenade_throw_substate::initialize(
        survarium::weapon_core_throw_grenade_idle_substate *this)
{
  survarium::weapon_core_throw_grenade_idle_substate_vtbl *v1; // eax

  v1 = this->__vftable;
  this->m_animation_has_been_ended = 0;
  ((void (*)(void))v1->subscribe_animation_player)();
}
