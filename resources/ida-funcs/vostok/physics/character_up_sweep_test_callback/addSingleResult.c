double __thiscall vostok::physics::character_up_sweep_test_callback::addSingleResult(
        vostok::physics::character_up_sweep_test_callback *this,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  float *m_hitCollisionObject; // eax
  btVector3 *p_m_hitPointLocal; // ebx
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float m_capsule_radius; // xmm0_4
  float v14; // xmm1_4
  btVector3 *p_m_hitNormalLocal; // esi
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  double m_hitFraction; // st7
  int *v21; // esi
  btCollisionObject *v22; // eax
  float v23[4]; // [esp+10h] [ebp-20h] BYREF
  btVector3 v24; // [esp+20h] [ebp-10h]

  m_hitCollisionObject = (float *)convexResult->m_hitCollisionObject;
  if ( convexResult->m_hitCollisionObject == this->m_self )
    return 1.0;
  p_m_hitPointLocal = &convexResult->m_hitPointLocal;
  if ( this->m_min_contact_height > (float)((float)((float)(convexResult->m_hitPointLocal.mVec128.m128_f32[2]
                                                          * this->m_up_vector.mVec128.m128_f32[2])
                                                  + (float)(convexResult->m_hitPointLocal.mVec128.m128_f32[1]
                                                          * this->m_up_vector.mVec128.m128_f32[1]))
                                          + (float)(convexResult->m_hitPointLocal.mVec128.m128_f32[0]
                                                  * this->m_up_vector.mVec128.m128_f32[0])) )
    return 1.0;
  v6 = p_m_hitPointLocal->mVec128.m128_f32[0] - this->m_center.mVec128.m128_f32[0];
  v7 = convexResult->m_hitPointLocal.mVec128.m128_f32[2] - this->m_center.mVec128.m128_f32[2];
  v8 = convexResult->m_hitPointLocal.mVec128.m128_f32[1] - this->m_center.mVec128.m128_f32[1];
  v9 = (float)((float)(this->m_up_vector.mVec128.m128_f32[2] * v7) + (float)(this->m_up_vector.mVec128.m128_f32[0] * v6))
     + (float)(this->m_up_vector.mVec128.m128_f32[1] * v8);
  v10 = v6 - (float)(this->m_up_vector.mVec128.m128_f32[0] * v9);
  v11 = (float)((float)(v7 - (float)(this->m_up_vector.mVec128.m128_f32[2] * v9))
              * (float)(v7 - (float)(this->m_up_vector.mVec128.m128_f32[2] * v9)))
      + (float)((float)(v8 - (float)(this->m_up_vector.mVec128.m128_f32[1] * v9))
              * (float)(v8 - (float)(this->m_up_vector.mVec128.m128_f32[1] * v9)));
  v12 = v10 * v10;
  m_capsule_radius = this->m_capsule_radius;
  v14 = fsqrt(v11 + v12);
  if ( fabs(v14 - m_capsule_radius) >= 0.0000099999997 && m_capsule_radius > v14 )
  {
    if ( normalInWorldSpace )
    {
      p_m_hitNormalLocal = &convexResult->m_hitNormalLocal;
    }
    else
    {
      v16 = convexResult->m_hitNormalLocal.mVec128.m128_f32[2];
      v17 = convexResult->m_hitNormalLocal.mVec128.m128_f32[1];
      v18 = convexResult->m_hitNormalLocal.mVec128.m128_f32[0];
      v19 = m_hitCollisionObject[10];
      v23[0] = (float)((float)(m_hitCollisionObject[5] * v17) + (float)(m_hitCollisionObject[6] * v16))
             + (float)(m_hitCollisionObject[4] * v18);
      v23[1] = (float)((float)(m_hitCollisionObject[9] * v17) + (float)(v19 * v16))
             + (float)(m_hitCollisionObject[8] * v18);
      v23[2] = (float)((float)(m_hitCollisionObject[13] * v17) + (float)(m_hitCollisionObject[14] * v16))
             + (float)(m_hitCollisionObject[12] * v18);
      v23[3] = 0.0;
      p_m_hitNormalLocal = (btVector3 *)v23;
    }
    m_hitFraction = convexResult->m_hitFraction;
    v24.mVec128.m128_i32[0] = p_m_hitNormalLocal->mVec128.m128_i32[0];
    v21 = &p_m_hitNormalLocal->mVec128.m128_i32[1];
    v24.mVec128.m128_i32[1] = *v21;
    v24.mVec128.m128_u64[1] = *(_QWORD *)(v21 + 1);
    this->m_closestHitFraction = m_hitFraction;
    v22 = convexResult->m_hitCollisionObject;
    this->m_hitNormalWorld = (btVector3)v24.mVec128;
    this->m_hitCollisionObject = v22;
    this->m_hitPointWorld.mVec128.m128_i32[0] = p_m_hitPointLocal->mVec128.m128_i32[0];
    *(unsigned __int64 *)((char *)this->m_hitPointWorld.mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)convexResult->m_hitPointLocal.mVec128.m128_u64 + 4);
    this->m_hitPointWorld.mVec128.m128_i32[3] = convexResult->m_hitPointLocal.mVec128.m128_i32[3];
  }
  return this->m_closestHitFraction;
}
