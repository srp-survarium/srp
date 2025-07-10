void __thiscall survarium::dispersion_calculator::set_aiming_speed_coeff(
        survarium::dispersion_calculator *this,
        float aiming_speed_coeff)
{
  this->m_aiming_speed_coeff = aiming_speed_coeff;
  survarium::dispersion_calculator::apply_aim_speed(this);
}
