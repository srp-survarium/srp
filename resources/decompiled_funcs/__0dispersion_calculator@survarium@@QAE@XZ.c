void __thiscall survarium::dispersion_calculator::dispersion_calculator(survarium::dispersion_calculator *this)
{
  survarium::weapon_dispersion_calculator::weapon_dispersion_calculator(&this->m_weapon_calculator);
  survarium::character_dispersion_calculator::character_dispersion_calculator(&this->m_character_calculator);
  this->m_weapon = 0;
  LODWORD(this->m_shooting_skill_coeff) = clear_value;
  LODWORD(this->m_aiming_speed_coeff) = clear_value;
}
