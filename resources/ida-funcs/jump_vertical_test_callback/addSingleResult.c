double __thiscall jump_vertical_test_callback::addSingleResult(
        jump_vertical_test_callback *this,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  float *m_hitCollisionObject; // eax
  btVector3 *p_m_hitNormalLocal; // esi
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  int *v16; // esi
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float m_capsule_radius2; // xmm0_4
  float v23; // xmm2_4
  btCollisionObject *v24; // edx
  char v25; // [esp+Ah] [ebp-26h]
  bool v26; // [esp+Bh] [ebp-25h]
  btVector3 v27; // [esp+10h] [ebp-20h]
  float v28[4]; // [esp+20h] [ebp-10h] BYREF

  m_hitCollisionObject = (float *)convexResult->m_hitCollisionObject;
  if ( convexResult->m_hitCollisionObject == this->m_self )
    return 1.0;
  if ( normalInWorldSpace )
  {
    p_m_hitNormalLocal = &convexResult->m_hitNormalLocal;
  }
  else
  {
    v6 = convexResult->m_hitNormalLocal.mVec128.m128_f32[2];
    v7 = convexResult->m_hitNormalLocal.mVec128.m128_f32[1];
    v8 = convexResult->m_hitNormalLocal.mVec128.m128_f32[0];
    v9 = m_hitCollisionObject[10];
    v28[0] = (float)((float)(m_hitCollisionObject[5] * v7) + (float)(m_hitCollisionObject[6] * v6))
           + (float)(m_hitCollisionObject[4] * v8);
    v28[1] = (float)((float)(m_hitCollisionObject[9] * v7) + (float)(v9 * v6)) + (float)(m_hitCollisionObject[8] * v8);
    v28[2] = (float)((float)(m_hitCollisionObject[13] * v7) + (float)(m_hitCollisionObject[14] * v6))
           + (float)(m_hitCollisionObject[12] * v8);
    v28[3] = 0.0;
    p_m_hitNormalLocal = (btVector3 *)v28;
  }
  v10 = this->m_up_vector.mVec128.m128_f32[2];
  v11 = this->m_up_vector.mVec128.m128_f32[1];
  v12 = this->m_up_vector.mVec128.m128_f32[0];
  v13 = convexResult->m_hitPointLocal.mVec128.m128_f32[1] - this->m_center.mVec128.m128_f32[1];
  v14 = convexResult->m_hitPointLocal.mVec128.m128_f32[2] - this->m_center.mVec128.m128_f32[2];
  v15 = convexResult->m_hitPointLocal.mVec128.m128_f32[0] - this->m_center.mVec128.m128_f32[0];
  v27.mVec128.m128_i32[0] = p_m_hitNormalLocal->mVec128.m128_i32[0];
  v16 = &p_m_hitNormalLocal->mVec128.m128_i32[1];
  v27.mVec128.m128_i32[1] = *v16;
  v17 = (float)((float)(v11 * v13) + (float)(v10 * v14)) + (float)(v12 * v15);
  v18 = v10 * v17;
  v27.mVec128.m128_u64[1] = *(_QWORD *)(v16 + 1);
  v19 = v15 - (float)(v12 * v17);
  v20 = (float)(v13 - (float)(v11 * v17)) * (float)(v13 - (float)(v11 * v17));
  v21 = v19 * v19;
  m_capsule_radius2 = this->m_capsule_radius2;
  v23 = (float)((float)((float)(v14 - v18) * (float)(v14 - v18)) + v20) + v21;
  if ( m_capsule_radius2 <= v23 || (v25 = 1, fabs(v23 - m_capsule_radius2) < 0.0000099999997) )
    v25 = 0;
  v26 = fabs(
          (float)((float)(this->m_up_vector.mVec128.m128_f32[1] * v27.mVec128.m128_f32[1])
                + (float)(this->m_up_vector.mVec128.m128_f32[2] * v27.mVec128.m128_f32[2]))
        + (float)(this->m_up_vector.mVec128.m128_f32[0] * v27.mVec128.m128_f32[0])) < 0.001;
  if ( v25 || !v26 )
  {
    this->m_closestHitFraction = convexResult->m_hitFraction;
    v24 = convexResult->m_hitCollisionObject;
    this->m_hitNormalWorld = (btVector3)v27.mVec128;
    this->m_hitCollisionObject = v24;
    this->m_hitPointWorld = convexResult->m_hitPointLocal;
  }
  return this->m_closestHitFraction;
}
