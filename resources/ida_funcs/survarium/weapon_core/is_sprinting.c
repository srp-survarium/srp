BOOL __thiscall survarium::weapon_core::is_sprinting(survarium::weapon_core *this)
{
  return survarium::weapon_user_animations_selector::is_sprinting(&this->m_user_animations_selector);
}
