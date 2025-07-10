double __thiscall vostok::physics::character_move_test_callback::addSingleResult(
        vostok::physics::character_move_test_callback *this,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  float *m_hitCollisionObject; // eax
  unsigned __int64 v5; // xmm0_8
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  unsigned __int64 v9; // [esp+30h] [ebp-20h]
  unsigned __int64 v10; // [esp+40h] [ebp-10h]

  m_hitCollisionObject = (float *)convexResult->m_hitCollisionObject;
  if ( convexResult->m_hitCollisionObject == this->m_self )
    return 2.0;
  if ( normalInWorldSpace )
  {
    v9 = convexResult->m_hitNormalLocal.mVec128.m128_u64[0];
    v5 = convexResult->m_hitNormalLocal.mVec128.m128_u64[1];
  }
  else
  {
    v6 = convexResult->m_hitNormalLocal.mVec128.m128_f32[2];
    v7 = convexResult->m_hitNormalLocal.mVec128.m128_f32[1];
    v8 = convexResult->m_hitNormalLocal.mVec128.m128_f32[0];
    *(float *)&v10 = (float)((float)(m_hitCollisionObject[5] * v7) + (float)(m_hitCollisionObject[6] * v6))
                   + (float)(m_hitCollisionObject[4] * v8);
    *((float *)&v10 + 1) = (float)((float)(m_hitCollisionObject[9] * v7) + (float)(m_hitCollisionObject[10] * v6))
                         + (float)(v8 * m_hitCollisionObject[8]);
    v9 = v10;
    *(float *)&v5 = (float)((float)(m_hitCollisionObject[13] * v7) + (float)(m_hitCollisionObject[14] * v6))
                  + (float)(m_hitCollisionObject[12] * v8);
  }
  if ( this->m_minSlopeDot <= (float)((float)((float)(this->m_up_vector.mVec128.m128_f32[1] * *((float *)&v9 + 1))
                                            + (float)(this->m_up_vector.mVec128.m128_f32[2] * *(float *)&v5))
                                    + (float)(this->m_up_vector.mVec128.m128_f32[0] * *(float *)&v9)) )
    return btCollisionWorld::ClosestConvexResultCallback::addSingleResult(this, convexResult, normalInWorldSpace);
  else
    return 0.0;
}
