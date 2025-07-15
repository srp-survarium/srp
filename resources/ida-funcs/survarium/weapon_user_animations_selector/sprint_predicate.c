BOOL __thiscall survarium::weapon_user_animations_selector::sprint_predicate(
        survarium::weapon_user_animations_selector *this)
{
  return survarium::weapon_user_animations_selector::is_trying_to_sprint(this, (int)this)
      && this->m_user->m_current_active_object->can_sprint(this->m_user->m_current_active_object);
}
