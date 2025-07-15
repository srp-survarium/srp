void __thiscall survarium::weapon_dispersion_calculator::weapon_dispersion_calculator(
        survarium::weapon_dispersion_calculator *this)
{
  LODWORD(this->m_one_shoot_dispersion_amount) = clear_value;
  LODWORD(this->m_reload_dispersion_amount) = clear_value;
  this->m_growth_speed = 5.0;
  LODWORD(this->m_aiming_speed) = clear_value;
  this->m_max_value = retry_to_increase_quality_period_sec;
  this->m_target_coeff = *(float *)&FLOAT_0_0;
  this->m_current_coeff = *(float *)&FLOAT_0_0;
  this->m_current_time = 0;
}
