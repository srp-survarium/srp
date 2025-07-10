void __thiscall survarium::character_recoil_calculator::tick(
        survarium::character_recoil_calculator *this,
        survarium::weapon_user_state_enum character_state,
        bool is_aiming,
        unsigned int current_time_in_ms,
        float time_scale)
{
  float m_target_value; // xmm0_4
  float v6; // [esp+0h] [ebp-28h]
  float aimed_crouch_multiplier; // [esp+Ch] [ebp-1Ch]
  float aimed_stand_multiplier; // [esp+10h] [ebp-18h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  switch ( character_state )
  {
    case type_stand:
    case type_sprint:
    case type_jump:
    case type_preview:
      if ( is_aiming )
        aimed_stand_multiplier = this->m_params->aimed_stand_multiplier;
      else
        aimed_stand_multiplier = this->m_params->stand_multiplier;
      this->m_target_value = aimed_stand_multiplier;
      break;
    case type_crouch:
      if ( is_aiming )
        aimed_crouch_multiplier = this->m_params->aimed_crouch_multiplier;
      else
        aimed_crouch_multiplier = this->m_params->crouch_multiplier;
      this->m_target_value = aimed_crouch_multiplier;
      break;
    default:
      break;
  }
  if ( current_time_in_ms <= this->m_current_time )
    v6 = *(float *)&FLOAT_0_0;
  else
    v6 = (double)(current_time_in_ms - this->m_current_time) * 0.001 * time_scale;
  this->m_current_time = current_time_in_ms;
  if ( this->m_current_value != this->m_target_value )
  {
    if ( this->m_current_value <= this->m_target_value )
    {
      m_target_value = this->m_target_value;
      vostok::math::min();
    }
    else
    {
      m_target_value = this->m_current_value - (float)(this->m_decrease_speed * v6);
      vostok::math::max();
    }
    this->m_current_value = m_target_value;
  }
}
