bool __thiscall survarium::weapon_core::target_and_animation_ended_predicate(
        survarium::weapon_core *this,
        survarium::weapon_targets target)
{
  return this->m_target == target
      && survarium::weapon_core_base_state::has_animation_ended(
           (survarium::weapon_core_base_state *)this->m_logic->m_current_state,
           (int)this->m_logic->m_current_state);
}
