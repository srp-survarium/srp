BOOL __thiscall survarium::breath_state_shortbreathing::is_ready_for_transition(
        survarium::breath_state_shortbreathing *this)
{
  return *this->m_penalty_factor == s_bm_current_air_resistance;
}
