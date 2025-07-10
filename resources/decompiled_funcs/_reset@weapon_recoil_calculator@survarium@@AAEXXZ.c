void __thiscall survarium::weapon_recoil_calculator::reset(survarium::weapon_recoil_calculator *this)
{
  this->m_time_since_last_dispersion_change = *(float *)&FLOAT_0_0;
  this->m_time_since_shoot = *(float *)&FLOAT_0_0;
  this->m_additive_recoil_timer = *(float *)&FLOAT_0_0;
  this->m_target_vertical_koef = *(float *)&FLOAT_0_0;
  this->m_target_horizontal_koef = *(float *)&FLOAT_0_0;
  this->m_target_vertical_koef = *(float *)&FLOAT_0_0;
  this->m_target_horizontal_koef = *(float *)&FLOAT_0_0;
}
