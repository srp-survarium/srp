double __thiscall vostok::animation::fermi_interpolator::interpolated_value(
        vostok::animation::fermi_interpolator *this,
        float current_transition_time)
{
  float m_epsilon; // xmm1_4
  double v4; // xmm0_8
  float v5; // xmm0_4
  long double v7; // [esp+0h] [ebp-Ch]
  long double v8; // [esp+0h] [ebp-Ch]
  float v9; // [esp+4h] [ebp-8h]
  float v10; // [esp+8h] [ebp-4h]

  m_epsilon = this->m_epsilon;
  v10 = this->m_total_transition_time * 0.5;
  *((float *)&v7 + 1) = (float)(m_epsilon * 2.0) + s_bm_current_air_resistance;
  v4 = (float)((float)(s_bm_current_air_resistance / m_epsilon) + s_bm_current_air_resistance);
  __libm_sse2_log(v7);
  *(float *)&v4 = v4;
  __libm_sse2_exp(v8);
  v5 = (float)(v9
             / (float)((float)((float)(-1.0 / (float)(v10 / *(float *)&v4)) * (float)(current_transition_time - v10))
                     + s_bm_current_air_resistance))
     - this->m_epsilon;
  if ( v5 > 0.0 )
  {
    if ( s_bm_current_air_resistance < v5 )
      return s_bm_current_air_resistance;
    else
      return v5;
  }
  else
  {
    return 0.0;
  }
}
