bool __thiscall survarium::weapon_user_animations_selector::crouch_predicate(
        survarium::weapon_user_animations_selector *this)
{
  return survarium::weapon_user_animations_selector::broken_legs_predicate(this)
      || (this->m_user->m_input.actions_mask & 0x200) != 0;
}
