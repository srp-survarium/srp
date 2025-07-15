bool __thiscall survarium::breath_state_shortbreathing::is_ready_for_transition(
        survarium::breath_state_shortbreathing *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return *this->m_breath_holding_reserve == this->m_params->max_breath_holding_time;
}
