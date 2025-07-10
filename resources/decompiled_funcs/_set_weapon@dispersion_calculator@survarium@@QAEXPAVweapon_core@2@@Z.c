void __thiscall survarium::dispersion_calculator::set_weapon(
        survarium::dispersion_calculator *this,
        survarium::weapon_core *weapon)
{
  this->m_weapon = weapon;
  if ( this->m_weapon )
  {
    survarium::weapon_dispersion_calculator::set_one_shoot_dispersion_amount(
      &this->m_weapon_calculator,
      this->m_weapon->m_dispersion_params.one_shoot_dispersion_amount);
    survarium::weapon_dispersion_calculator::set_reload_dispersion_amount(
      &this->m_weapon_calculator,
      this->m_weapon->m_dispersion_params.reload_dispersion_amount);
  }
  survarium::dispersion_calculator::apply_aim_speed(this);
}
