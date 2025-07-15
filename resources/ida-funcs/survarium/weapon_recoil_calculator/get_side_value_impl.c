__m128 __fastcall survarium::weapon_recoil_calculator::get_side_value_impl(
        survarium::weapon_recoil_calculator *this,
        unsigned int current_time_in_ms,
        float target_value,
        float value_at_last_shoot)
{
  unsigned int m_time_to_start_side_compensation; // eax
  float v5; // xmm1_4
  __m128 result; // xmm0
  unsigned int m_time_of_last_shoot; // eax
  __int128 side_increase_speed_low; // xmm1
  float v9; // [esp+4h] [ebp-4h]
  float v10; // [esp+10h] [ebp+8h]

  m_time_to_start_side_compensation = this->m_time_to_start_side_compensation;
  if ( current_time_in_ms < m_time_to_start_side_compensation )
  {
    result = (__m128)LODWORD(s_bm_current_air_resistance);
  }
  else
  {
    v5 = fsqrt(
           (float)(this->m_vertical_target * this->m_vertical_target)
         + (float)(this->m_horizontal_target * this->m_horizontal_target));
    v9 = v5
       - (double)(current_time_in_ms - m_time_to_start_side_compensation)
       * 0.001
       * this->m_weapon->m_recoil_params.side_compensation_speed;
    if ( v9 <= 0.0 )
    {
      result = 0;
    }
    else
    {
      result = (__m128)LODWORD(v9);
      result.m128_f32[0] = v9 / v5;
    }
  }
  m_time_of_last_shoot = this->m_time_of_last_shoot;
  result.m128_f32[0] = result.m128_f32[0] * target_value;
  if ( m_time_of_last_shoot == -1 || current_time_in_ms <= m_time_of_last_shoot )
    v10 = 0.0;
  else
    v10 = 0.001 * (double)(current_time_in_ms - m_time_of_last_shoot);
  side_increase_speed_low = LODWORD(this->m_weapon->m_recoil_params.side_increase_speed);
  *(float *)&side_increase_speed_low = (float)(*(float *)&side_increase_speed_low * v10) + value_at_last_shoot;
  if ( result.m128_f32[0] > *(float *)&side_increase_speed_low )
    return (__m128)side_increase_speed_low;
  return result;
}
