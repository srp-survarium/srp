BOOL __thiscall survarium::weapon_user_animations_selector::jump_predicate(
        survarium::weapon_user_animations_selector *this)
{
  survarium::weapon_user_animations_selector *v2; // ecx

  return this->m_user->m_current_active_object->can_jump(this->m_user->m_current_active_object)
      && survarium::weapon_user_animations_selector::is_trying_to_jump(v2, (int)this);
}
