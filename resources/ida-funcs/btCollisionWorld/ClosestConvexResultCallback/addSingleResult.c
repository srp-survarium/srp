double __thiscall btCollisionWorld::ClosestConvexResultCallback::addSingleResult(
        btCollisionWorld::ClosestConvexResultCallback *this,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  float *m_hitCollisionObject; // eax
  btVector3 *p_m_hitNormalLocal; // esi
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  int *v9; // esi
  float v11[4]; // [esp+10h] [ebp-10h] BYREF

  this->m_closestHitFraction = convexResult->m_hitFraction;
  m_hitCollisionObject = (float *)convexResult->m_hitCollisionObject;
  this->m_hitCollisionObject = convexResult->m_hitCollisionObject;
  if ( normalInWorldSpace )
  {
    p_m_hitNormalLocal = &convexResult->m_hitNormalLocal;
  }
  else
  {
    v5 = convexResult->m_hitNormalLocal.mVec128.m128_f32[2];
    v6 = convexResult->m_hitNormalLocal.mVec128.m128_f32[1];
    v7 = convexResult->m_hitNormalLocal.mVec128.m128_f32[0];
    v8 = m_hitCollisionObject[10];
    v11[0] = (float)((float)(m_hitCollisionObject[5] * v6) + (float)(m_hitCollisionObject[6] * v5))
           + (float)(m_hitCollisionObject[4] * v7);
    v11[1] = (float)((float)(m_hitCollisionObject[9] * v6) + (float)(v8 * v5)) + (float)(m_hitCollisionObject[8] * v7);
    v11[2] = (float)((float)(m_hitCollisionObject[13] * v6) + (float)(m_hitCollisionObject[14] * v5))
           + (float)(m_hitCollisionObject[12] * v7);
    v11[3] = 0.0;
    p_m_hitNormalLocal = (btVector3 *)v11;
  }
  this->m_hitNormalWorld.mVec128.m128_i32[0] = p_m_hitNormalLocal->mVec128.m128_i32[0];
  v9 = &p_m_hitNormalLocal->mVec128.m128_i32[1];
  this->m_hitNormalWorld.mVec128.m128_i32[1] = *v9;
  this->m_hitNormalWorld.mVec128.m128_u64[1] = *(_QWORD *)(v9 + 1);
  this->m_hitPointWorld = convexResult->m_hitPointLocal;
  return convexResult->m_hitFraction;
}
