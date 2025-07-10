void __thiscall survarium::dispersion_calculator::apply_aim_speed(survarium::dispersion_calculator *this)
{
  float aiming_speed; // [esp+4h] [ebp-Ch]

  if ( this->m_weapon )
    aiming_speed = this->m_weapon->m_dispersion_params.speed_of_aiming * this->m_aiming_speed_coeff;
  else
    aiming_speed = *(float *)&FLOAT_0_0;
  this->m_character_calculator.m_aiming_speed = aiming_speed;
  survarium::weapon_dispersion_calculator::set_aiming_speed(&this->m_weapon_calculator, aiming_speed);
}
