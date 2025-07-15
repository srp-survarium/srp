bool __thiscall survarium::weapon_user_animations_selector::is_ready_to_be_deactivated(
        survarium::weapon_user_animations_selector *this)
{
  return survarium::weapon_user_animations_selector::current_state(this)->m_is_ready_to_be_deactivated;
}
