__m128 __userpurge survarium::bullet::get_check_time_in_vacuum@<xmm0>(
        survarium::bullet *this@<eax>,
        const vostok::math::float3 *gravity@<edx>,
        float start_low,
        float high)
{
  float y; // xmm7_4
  survarium::bullet *m_weapon_ammunition; // ecx
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  __m128 result; // xmm0
  vostok::math::float3 *v14; // eax
  __m128 x_low; // xmm1
  __int128 v16; // xmm1
  vostok::math::float3 v17; // [esp+8h] [ebp-14h] BYREF
  float v18; // [esp+14h] [ebp-8h]
  float v19; // [esp+18h] [ebp-4h]

  y = this->m_start_velocity.y;
  m_weapon_ammunition = (survarium::bullet *)this->m_weapon_ammunition;
  v6 = m_weapon_ammunition[2].m_position.y - this->m_flown_distance;
  v7 = (float)((float)(high - start_low) * (float)(high - start_low)) * 0.5;
  v8 = gravity->x * v7;
  v9 = (float)(this->m_start_velocity.z * (float)(high - start_low)) + (float)(gravity->z * v7);
  v19 = gravity->y;
  v10 = v19 * v7;
  v11 = (float)(this->m_start_velocity.x * (float)(high - start_low)) + v8;
  v12 = fsqrt(
          (float)((float)(v9 * v9)
                + (float)((float)(v10 + (float)(y * (float)(high - start_low)))
                        * (float)(v10 + (float)(y * (float)(high - start_low)))))
        + (float)(v11 * v11));
  v18 = v6;
  if ( v6 < v12 )
  {
    v14 = survarium::bullet::compute_trajectory_velocity(this, m_weapon_ammunition, &v17, v12, start_low);
    x_low = (__m128)LODWORD(v14->x);
    x_low.m128_f32[0] = fsqrt(
                          (float)((float)(v14->y * v14->y) + (float)(v14->z * v14->z))
                        + (float)(x_low.m128_f32[0] * x_low.m128_f32[0]));
    result = x_low;
    result.m128_f32[0] = fsqrt(
                           (float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                         + (float)((float)(COERCE_FLOAT(LODWORD(v19) ^ _mask__NegFloat_) * v18) * 2.0))
                       - x_low.m128_f32[0];
    v16 = LODWORD(start_low);
    result.m128_f32[0] = (float)(result.m128_f32[0] / COERCE_FLOAT(LODWORD(v19) ^ _mask__NegFloat_)) + start_low;
    if ( start_low >= result.m128_f32[0] )
      return (__m128)v16;
    v16 = LODWORD(high);
    if ( high < result.m128_f32[0] )
      return (__m128)v16;
  }
  else
  {
    return (__m128)LODWORD(high);
  }
  return result;
}
