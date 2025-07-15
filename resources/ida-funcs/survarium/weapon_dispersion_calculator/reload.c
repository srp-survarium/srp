void __thiscall survarium::weapon_dispersion_calculator::reload(survarium::weapon_dispersion_calculator *this)
{
  float m_max_value; // xmm0_4

  m_max_value = this->m_max_value;
  vostok::math::min();
  this->m_target_coeff = m_max_value;
}
