void __thiscall survarium::breath_vibration_calculator::tick(
        survarium::breath_vibration_calculator *this,
        unsigned int current_time_in_ms,
        float time_scale)
{
  float v3; // xmm2_4
  float m_target_multiplier; // xmm0_4
  float v5; // [esp+14h] [ebp-30h]
  float dt; // [esp+38h] [ebp-Ch]
  survarium::breath_state *current_state; // [esp+3Ch] [ebp-8h]
  float current_phase; // [esp+40h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( current_time_in_ms >= this->m_last_time_in_ms )
  {
    dt = (double)(current_time_in_ms - this->m_last_time_in_ms) * 0.001 * time_scale;
    this->m_last_time_in_ms = current_time_in_ms;
    vostok::ai::fsm::tick(&this->m_logic);
    current_state = (survarium::breath_state *)this->m_logic.m_current_state;
    current_state->tick(current_state, COERCE_FLOAT(LODWORD(dt)));
    this->m_target_multiplier = current_state->m_multiplier;
    if ( this->m_current_multiplier <= this->m_target_multiplier )
    {
      m_target_multiplier = this->m_target_multiplier;
      vostok::math::min();
      v5 = m_target_multiplier;
    }
    else
    {
      v3 = this->m_current_multiplier - (float)(this->m_params->multiplier_decrease_speed * dt);
      vostok::math::max();
      v5 = v3;
    }
    this->m_current_multiplier = v5;
    current_phase = (double)this->m_user->local_time((survarium::base_player *)this->m_user, current_time_in_ms)
                  * 0.001
                  * 6.2831855
                  * time_scale;
    this->m_horizontal_value = vostok::math::sin(current_phase / this->m_params->horizontal_peroid)
                             * this->m_params->horizontal_amplitude
                             * this->m_character_multiplier
                             * this->m_current_multiplier;
    this->m_vertical_value = vostok::math::sin(current_phase / this->m_params->vertical_peroid)
                           * this->m_params->vertical_amplitude
                           * this->m_character_multiplier
                           * this->m_current_multiplier;
    if ( !s_enable_breath_vibration_value )
    {
      this->m_vertical_value = *(float *)&FLOAT_0_0;
      this->m_horizontal_value = *(float *)&FLOAT_0_0;
    }
  }
}
