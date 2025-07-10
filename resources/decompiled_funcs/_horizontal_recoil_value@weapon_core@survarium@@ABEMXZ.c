double __thiscall survarium::weapon_core::horizontal_recoil_value(survarium::weapon_core *this)
{
  __m128 v1; // xmm0
  float horizontal_coeff; // [esp+4h] [ebp-18h]
  float m_horizontal_value; // [esp+10h] [ebp-Ch]

  if ( survarium::weapon_core::is_aimed(this, (int)this) )
  {
    m_horizontal_value = this->m_breath_vibration_calculator.m_horizontal_value;
    horizontal_coeff = survarium::recoil_calculator::get_horizontal_coeff(&this->m_recoil_calculator)
                     + m_horizontal_value;
  }
  else
  {
    horizontal_coeff = survarium::recoil_calculator::get_horizontal_coeff(&this->m_recoil_calculator);
  }
  v1 = _mm_xor_ps((__m128)LODWORD(c_anim_center), *(__m128 *)&stru_984D24.m_working_macro_list.m_buffer[7].m_store[508]);
  v1.m128_f32[0] = v1.m128_f32[0] + epsilon;
  return (float)(0.5 - vostok::math::clamp_r<float>(v1, LODWORD(horizontal_coeff), 0.5 - epsilon).m128_f32[0]);
}
