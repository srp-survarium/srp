BOOL __thiscall survarium::weapon_core::chamber_a_round_pred(survarium::weapon_core *this)
{
  return this->m_user->m_is_alive
      && this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size != 3
      && !survarium::weapon_core::is_going_to_jump(this, (int)this)
      && !this->m_is_round_chambered
      && this->m_ammo_in_magazine;
}
