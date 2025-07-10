void __usercall EvaluateMedium(
        const btSoftBodyWorldInfo *wfi@<esi>,
        const btVector3 *x@<eax>,
        btSoftBody::sMedium *medium@<edi>)
{
  float water_density; // xmm2_4
  float v4; // [esp+20h] [ebp-14h]

  medium->m_velocity.mVec128.m128_u64[0] = 0;
  medium->m_velocity.mVec128.m128_u64[1] = 0;
  medium->m_pressure = 0.0;
  medium->m_density = wfi->air_density;
  water_density = wfi->water_density;
  if ( water_density > 0.0 )
  {
    v4 = -(float)((float)((float)((float)(wfi->water_normal.mVec128.m128_f32[2] * x->mVec128.m128_f32[2])
                                + (float)(wfi->water_normal.mVec128.m128_f32[1] * x->mVec128.m128_f32[1]))
                        + (float)(x->mVec128.m128_f32[0] * wfi->water_normal.mVec128.m128_f32[0]))
                + wfi->water_offset);
    if ( v4 > 0.0 )
    {
      medium->m_density = water_density;
      medium->m_pressure = sqrtf(
                             (float)((float)(wfi->m_gravity.mVec128.m128_f32[0] * wfi->m_gravity.mVec128.m128_f32[0])
                                   + (float)(wfi->m_gravity.mVec128.m128_f32[1] * wfi->m_gravity.mVec128.m128_f32[1]))
                           + (float)(wfi->m_gravity.mVec128.m128_f32[2] * wfi->m_gravity.mVec128.m128_f32[2]))
                         * wfi->water_density
                         * v4;
    }
  }
}
