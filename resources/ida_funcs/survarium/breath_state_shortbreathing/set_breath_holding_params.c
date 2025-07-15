void __thiscall survarium::breath_state_shortbreathing::set_breath_holding_params(
        survarium::breath_state_shortbreathing *this,
        const survarium::breath_holding_params *params)
{
  this->m_params = params;
  if ( this->m_params )
  {
    this->m_multiplier = this->m_params->shortbreathing_multiplier;
    this->m_restoring_speed = this->m_params->max_breath_holding_time / this->m_params->shortbreathing_repair_time;
  }
}
