BOOL __thiscall survarium::weapon_core::fire_pred(survarium::weapon_core *this)
{
  BOOL result; // eax

  result = 0;
  if ( (unsigned __int8)survarium::weapon_core::could_be_used(
                          (survarium::weapon_core *)this->m_user,
                          (const survarium::base_player *)this)
    && this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size != 3
    && !this->m_is_in_sprint_transition
    && (this->m_user->m_input.actions_mask & 0x20) != 0
    && this->m_bullets_in_queue
    && (this->m_is_there_chamber_a_round_state ? this->m_is_round_chambered : this->m_ammo_in_magazine != 0) )
  {
    return 1;
  }
  return result;
}
