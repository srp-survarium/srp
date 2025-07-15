double __thiscall btCollisionWorld::ClosestRayResultCallback::addSingleResult(
        btCollisionWorld::ClosestRayResultCallback *this,
        btCollisionWorld::LocalRayResult *rayResult,
        bool normalInWorldSpace)
{
  float *m_collisionObject; // eax
  btVector3 *p_m_hitNormalLocal; // esi
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  int *v10; // esi
  float m_hitFraction; // xmm1_4
  float v12; // xmm0_4
  float v14[4]; // [esp+10h] [ebp-10h] BYREF

  this->m_closestHitFraction = rayResult->m_hitFraction;
  m_collisionObject = (float *)rayResult->m_collisionObject;
  this->m_collisionObject = rayResult->m_collisionObject;
  if ( normalInWorldSpace )
  {
    p_m_hitNormalLocal = &rayResult->m_hitNormalLocal;
  }
  else
  {
    v5 = rayResult->m_hitNormalLocal.mVec128.m128_f32[2];
    v6 = rayResult->m_hitNormalLocal.mVec128.m128_f32[1];
    v7 = rayResult->m_hitNormalLocal.mVec128.m128_f32[0];
    v8 = m_collisionObject[10];
    v14[0] = (float)((float)(m_collisionObject[5] * v6) + (float)(m_collisionObject[6] * v5))
           + (float)(m_collisionObject[4] * v7);
    v14[1] = (float)((float)(m_collisionObject[9] * v6) + (float)(v8 * v5)) + (float)(m_collisionObject[8] * v7);
    v14[2] = (float)((float)(m_collisionObject[13] * v6) + (float)(m_collisionObject[14] * v5))
           + (float)(m_collisionObject[12] * v7);
    v14[3] = 0.0;
    p_m_hitNormalLocal = (btVector3 *)v14;
  }
  v9 = s_bm_current_air_resistance;
  this->m_hitNormalWorld.mVec128.m128_i32[0] = p_m_hitNormalLocal->mVec128.m128_i32[0];
  v10 = &p_m_hitNormalLocal->mVec128.m128_i32[1];
  this->m_hitNormalWorld.mVec128.m128_i32[1] = *v10;
  this->m_hitNormalWorld.mVec128.m128_u64[1] = *(_QWORD *)(v10 + 1);
  m_hitFraction = rayResult->m_hitFraction;
  v12 = v9 - m_hitFraction;
  this->m_hitPointWorld.mVec128.m128_f32[0] = (float)(this->m_rayFromWorld.mVec128.m128_f32[0] * v12)
                                            + (float)(m_hitFraction * this->m_rayToWorld.mVec128.m128_f32[0]);
  this->m_hitPointWorld.mVec128.m128_f32[1] = (float)(this->m_rayFromWorld.mVec128.m128_f32[1] * v12)
                                            + (float)(this->m_rayToWorld.mVec128.m128_f32[1] * m_hitFraction);
  this->m_hitPointWorld.mVec128.m128_f32[2] = (float)(this->m_rayFromWorld.mVec128.m128_f32[2] * v12)
                                            + (float)(this->m_rayToWorld.mVec128.m128_f32[2] * m_hitFraction);
  return rayResult->m_hitFraction;
}
