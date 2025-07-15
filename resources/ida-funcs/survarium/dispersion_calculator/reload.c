void __thiscall survarium::dispersion_calculator::reload(survarium::dispersion_calculator *this)
{
  survarium::weapon_dispersion_calculator::reload(&this->m_weapon_calculator);
}
