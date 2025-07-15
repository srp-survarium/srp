bool __thiscall survarium::weapon_core::can_and_must_reload_and_animation_ended_predicate(survarium::weapon_core *this)
{
  return survarium::weapon_core_base_state::has_animation_ended(
           (survarium::weapon_core_base_state *)this->m_logic->m_current_state,
           (int)this->m_logic->m_current_state)
      && survarium::weapon_core::can_and_must_reload_predicate(this);
}
