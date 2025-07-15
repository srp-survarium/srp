unsigned int __thiscall survarium::weapon_user_animations_selector::get_current_state_id(
        survarium::weapon_user_animations_selector *this)
{
  return this->m_logic.m_current_state[1].transitions.m_size;
}
