void __thiscall survarium::character_dispersion_calculator::set_character_dispersion_params(
        survarium::character_dispersion_calculator *this,
        const survarium::character_dispersion_params *character_params)
{
  this->m_params = character_params;
  if ( this->m_params )
  {
    this->m_target_value = this->m_params->idle_multiplier;
    this->m_current_value = this->m_params->idle_multiplier;
    this->m_value = this->m_params->idle_multiplier;
  }
}
