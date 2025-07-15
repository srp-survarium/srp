BOOL __thiscall survarium::weapon_core::is_sprinting(survarium::weapon_core *this)
{
  return survarium::weapon_user_animations_selector::is_sprinting(
           (survarium::weapon_user_animations_selector *)this,
           (int)&this->m_portable_interactive_object->m_user_animations_selector);
}
