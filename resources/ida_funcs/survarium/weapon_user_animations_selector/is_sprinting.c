BOOL __thiscall survarium::weapon_user_animations_selector::is_sprinting(
        survarium::weapon_user_animations_selector *this)
{
  return survarium::weapon_user_animations_selector::current_state(this)->m_weapon_user_state_id == type_sprint;
}
