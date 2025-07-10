double __thiscall survarium::weapon_core::get_dispersion(survarium::weapon_core *this)
{
  return survarium::dispersion_calculator::get_dispersion(&this->m_dispersion_calculator);
}
