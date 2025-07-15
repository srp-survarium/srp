__m128 __usercall survarium::weapon_recoil_calculator::get_back_value@<xmm0>(
        survarium::weapon_recoil_calculator *this@<edi>,
        const unsigned int current_time_in_ms@<eax>)
{
  unsigned int m_time_to_start_back_compensation; // edx
  __m128 result; // xmm0
  __m128 v4; // xmm1
  float v5; // [esp+4h] [ebp-4h]
  float v6; // [esp+4h] [ebp-4h]

  m_time_to_start_back_compensation = this->m_time_to_start_back_compensation;
  result = 0;
  if ( current_time_in_ms <= m_time_to_start_back_compensation || this->m_back_target == 0.0 )
  {
    if ( m_time_to_start_back_compensation == -1 )
      v6 = 0.0;
    else
      v6 = (double)(m_time_to_start_back_compensation - current_time_in_ms) * 0.001;
    result = (__m128)LODWORD(this->m_back_target);
    v4 = result;
    result.m128_f32[0] = result.m128_f32[0] - (float)(this->m_weapon->m_recoil_params.back_increase_speed * v6);
    if ( result.m128_f32[0] > v4.m128_f32[0] )
      return v4;
  }
  else
  {
    v5 = this->m_back_target
       - (double)(current_time_in_ms - m_time_to_start_back_compensation)
       * 0.001
       * this->m_weapon->m_recoil_params.back_compensation_speed;
    if ( v5 >= 0.0 )
      return (__m128)LODWORD(v5);
  }
  return result;
}
