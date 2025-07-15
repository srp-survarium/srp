bool __thiscall survarium::weapon_core_throw_grenade_base_substate::is_ready_for_transition(
        survarium::weapon_core_throw_grenade_base_substate *this)
{
  return this->m_animation_has_been_ended;
}
