void __thiscall survarium::character_dispersion_calculator::character_dispersion_calculator(
        survarium::character_dispersion_calculator *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_params = 0;
  this->m_target_value = *(float *)&FLOAT_0_0;
  this->m_current_value = *(float *)&FLOAT_0_0;
  this->m_value = *(float *)&FLOAT_0_0;
  this->m_value_smoothing_speed = 5.0;
  LODWORD(this->m_aiming_speed) = clear_value;
  this->m_current_time = 0;
  this->m_jumped = 0;
}
