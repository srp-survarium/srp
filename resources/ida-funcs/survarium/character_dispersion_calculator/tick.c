void __thiscall survarium::character_dispersion_calculator::tick(
        survarium::character_dispersion_calculator *this,
        survarium::weapon_user_state_enum character_state,
        bool is_moving,
        bool is_aiming,
        unsigned __int8 broken_hands_count,
        bool using_double_handed_weapon,
        unsigned int current_time_in_ms)
{
  float m_target_value; // xmm0_4
  float m_current_value; // xmm0_4
  float v9; // xmm0_4
  float target_koef; // [esp+0h] [ebp-1Ch]
  float dt; // [esp+18h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->m_current_time )
  {
    if ( this->m_current_time < current_time_in_ms )
    {
      dt = (double)(current_time_in_ms - this->m_current_time) / 1000.0;
      this->m_current_time = current_time_in_ms;
      target_koef = survarium::character_dispersion_calculator::get_target_koef(
                      this,
                      character_state,
                      is_moving,
                      is_aiming);
      this->m_target_value = survarium::character_dispersion_calculator::get_broken_hands_penalty(
                               this,
                               broken_hands_count,
                               using_double_handed_weapon)
                           * target_koef;
      m_target_value = this->m_target_value;
      vostok::math::max();
      this->m_current_value = m_target_value;
      if ( this->m_value <= this->m_current_value )
      {
        if ( this->m_current_value > this->m_value )
        {
          v9 = (float)(this->m_value_smoothing_speed * dt) + this->m_value;
          vostok::math::min();
          this->m_value = v9;
        }
      }
      else
      {
        m_current_value = this->m_current_value;
        vostok::math::max();
        this->m_value = m_current_value;
      }
    }
  }
  else
  {
    this->m_current_time = current_time_in_ms;
  }
}
