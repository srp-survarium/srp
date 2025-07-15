void __thiscall survarium::dispersion_calculator::fire(survarium::dispersion_calculator *this)
{
  survarium::weapon_dispersion_calculator::fire(&this->m_weapon_calculator);
}
