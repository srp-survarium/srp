bool __thiscall survarium::weapon_core::instant_idle_predicate(survarium::weapon_core *this)
{
  return survarium::weapon_user_animations_selector::sprint_predicate(&this->m_user_animations_selector)
      || survarium::weapon_user_animations_selector::is_in_jump(&this->m_user_animations_selector);
}
