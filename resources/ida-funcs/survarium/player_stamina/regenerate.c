void __usercall survarium::player_stamina::regenerate(
        survarium::player_stamina *this@<esi>,
        const unsigned int current_time_in_ms@<eax>,
        float a3@<xmm0>)
{
  float max_value; // xmm0_4
  bool v5; // cc
  float v6; // [esp+10h] [ebp-4h]
  float v7; // [esp+10h] [ebp-4h]

  v6 = survarium::player_params_modifiers_container::apply_modifier(
         this->m_modifiers,
         stamina_regenation_speed_modifier,
         a3,
         this->m_params.regeneration_speed,
         1.0);
  max_value = 0.0;
  if ( v6 > 0.0 )
  {
    v7 = (double)(current_time_in_ms - this->m_current_time_in_ms) * 0.001 * v6 + this->m_value;
    if ( v7 > 0.0 )
    {
      max_value = v7;
      if ( this->m_params.max_value < v7 )
        max_value = this->m_params.max_value;
    }
    v5 = max_value <= this->m_params.stop_low_stamina_value;
    this->m_value = max_value;
    if ( !v5 )
      this->m_is_low_stamina = 0;
  }
}
