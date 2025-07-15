bool __thiscall survarium::weapon_core_shotgun_reload_start_substate::is_ready_for_transition(
        survarium::weapon_core_shotgun_reload_start_substate *this)
{
  return this->m_animation_ended;
}
