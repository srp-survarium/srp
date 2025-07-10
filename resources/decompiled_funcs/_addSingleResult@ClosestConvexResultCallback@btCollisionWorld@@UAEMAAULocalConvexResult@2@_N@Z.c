double __thiscall btCollisionWorld::ClosestConvexResultCallback::addSingleResult(
        btCollisionWorld::ClosestConvexResultCallback *this,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  float *m_hitCollisionObject; // eax
  unsigned __int64 v4; // xmm0_8
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  unsigned __int64 v9; // [esp+0h] [ebp-10h]
  unsigned __int64 v10; // [esp+8h] [ebp-8h]

  this->m_closestHitFraction = convexResult->m_hitFraction;
  m_hitCollisionObject = (float *)convexResult->m_hitCollisionObject;
  this->m_hitCollisionObject = convexResult->m_hitCollisionObject;
  if ( normalInWorldSpace )
  {
    this->m_hitNormalWorld.mVec128.m128_u64[0] = convexResult->m_hitNormalLocal.mVec128.m128_u64[0];
    v4 = convexResult->m_hitNormalLocal.mVec128.m128_u64[1];
  }
  else
  {
    v5 = convexResult->m_hitNormalLocal.mVec128.m128_f32[2];
    v6 = convexResult->m_hitNormalLocal.mVec128.m128_f32[1];
    v7 = convexResult->m_hitNormalLocal.mVec128.m128_f32[0];
    *(float *)&v9 = (float)((float)(m_hitCollisionObject[5] * v6) + (float)(m_hitCollisionObject[6] * v5))
                  + (float)(m_hitCollisionObject[4] * v7);
    *((float *)&v9 + 1) = (float)((float)(m_hitCollisionObject[9] * v6) + (float)(m_hitCollisionObject[10] * v5))
                        + (float)(m_hitCollisionObject[8] * v7);
    v10 = COERCE_UNSIGNED_INT(
            (float)((float)(m_hitCollisionObject[13] * v6) + (float)(m_hitCollisionObject[14] * v5))
          + (float)(m_hitCollisionObject[12] * v7));
    this->m_hitNormalWorld.mVec128.m128_u64[0] = v9;
    v4 = v10;
  }
  this->m_hitNormalWorld.mVec128.m128_u64[1] = v4;
  this->m_hitPointWorld = convexResult->m_hitPointLocal;
  return convexResult->m_hitFraction;
}
