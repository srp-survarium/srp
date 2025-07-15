bool __thiscall survarium::weapon_core_throw_grenade_idle_substate::is_ready_for_transition(
        survarium::weapon_core_throw_grenade_idle_substate *this)
{
  return survarium::weapon_core_throw_grenade_state::test_input_throw_action(this->m_owner, 0);
}
