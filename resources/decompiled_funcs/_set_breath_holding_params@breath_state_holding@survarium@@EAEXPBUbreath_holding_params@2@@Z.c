void __thiscall survarium::breath_state_holding::set_breath_holding_params(
        survarium::breath_state_holding *this,
        const survarium::breath_holding_params *params)
{
  this->m_params = params;
  if ( this->m_params )
    this->m_multiplier = params->breath_holding_multiplier;
}
