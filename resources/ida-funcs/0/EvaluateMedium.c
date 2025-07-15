void __fastcall EvaluateMedium(btSoftBody::sMedium *medium, const btVector3 *x, const btSoftBodyWorldInfo *wfi)
{
  float water_density; // xmm2_4
  float v4; // xmm1_4

  medium->m_velocity.mVec128.m128_u64[0] = 0;
  medium->m_velocity.mVec128.m128_u64[1] = 0;
  medium->m_pressure = 0.0;
  medium->m_density = wfi->air_density;
  water_density = wfi->water_density;
  if ( water_density > 0.0 )
  {
    LODWORD(v4) = COERCE_UNSIGNED_INT(
                    (float)((float)((float)(wfi->water_normal.mVec128.m128_f32[2] * x->mVec128.m128_f32[2])
                                  + (float)(wfi->water_normal.mVec128.m128_f32[1] * x->mVec128.m128_f32[1]))
                          + (float)(x->mVec128.m128_f32[0] * wfi->water_normal.mVec128.m128_f32[0]))
                  + wfi->water_offset)
                ^ _mask__NegFloat_;
    if ( v4 > 0.0 )
    {
      medium->m_density = water_density;
      medium->m_pressure = (float)(fsqrt(
                                     (float)((float)(wfi->m_gravity.mVec128.m128_f32[0]
                                                   * wfi->m_gravity.mVec128.m128_f32[0])
                                           + (float)(wfi->m_gravity.mVec128.m128_f32[1]
                                                   * wfi->m_gravity.mVec128.m128_f32[1]))
                                   + (float)(wfi->m_gravity.mVec128.m128_f32[2] * wfi->m_gravity.mVec128.m128_f32[2]))
                                 * wfi->water_density)
                         * v4;
    }
  }
}
