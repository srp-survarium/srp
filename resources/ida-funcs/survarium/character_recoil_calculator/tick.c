void __userpurge survarium::character_recoil_calculator::tick(
        survarium::character_recoil_calculator *this@<ecx>,
        int character_state@<eax>,
        unsigned int current_time_in_ms@<esi>,
        const bool is_aiming)
{
  unsigned int m_current_time_in_ms; // edx
  const survarium::character_recoil_params *v5; // eax
  float aimed_crouch_multiplier; // xmm0_4
  const survarium::character_recoil_params *m_params; // eax
  float m_current_value; // xmm1_4
  float m_target_value; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // [esp+8h] [ebp+8h]

  m_current_time_in_ms = this->m_current_time_in_ms;
  if ( current_time_in_ms <= m_current_time_in_ms )
    return;
  if ( !character_state )
    goto LABEL_7;
  if ( character_state == 1 )
  {
    m_params = this->m_params;
    if ( is_aiming )
      aimed_crouch_multiplier = m_params->aimed_crouch_multiplier;
    else
      aimed_crouch_multiplier = m_params->crouch_multiplier;
    goto LABEL_13;
  }
  if ( character_state > 1 && (character_state <= 3 || character_state == 5) )
  {
LABEL_7:
    v5 = this->m_params;
    if ( is_aiming )
      aimed_crouch_multiplier = v5->aimed_stand_multiplier;
    else
      aimed_crouch_multiplier = v5->stand_multiplier;
LABEL_13:
    this->m_target_value = aimed_crouch_multiplier;
  }
  m_current_value = this->m_current_value;
  m_target_value = this->m_target_value;
  v12 = (double)(current_time_in_ms - m_current_time_in_ms) * 0.001;
  this->m_current_time_in_ms = current_time_in_ms;
  if ( m_current_value != m_target_value )
  {
    if ( m_current_value <= m_target_value )
    {
      v11 = (float)(this->m_increase_speed * v12) + m_current_value;
      if ( m_target_value <= v11 )
        v11 = m_target_value;
      this->m_current_value = v11;
    }
    else
    {
      v10 = m_current_value - (float)(this->m_decrease_speed * v12);
      if ( v10 <= m_target_value )
        v10 = m_target_value;
      this->m_current_value = v10;
    }
  }
}
