void __thiscall survarium::character_recoil_calculator::character_recoil_calculator(
        survarium::character_recoil_calculator *this)
{
  this->m_params = 0;
  this->m_target_value = *(float *)&FLOAT_0_0;
  this->m_current_value = *(float *)&FLOAT_0_0;
  LODWORD(this->m_increase_speed) = clear_value;
  LODWORD(this->m_decrease_speed) = clear_value;
  this->m_current_time = 0;
}
