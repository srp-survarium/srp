double __thiscall vostok::physics::character_move_test_callback::addSingleResult(
        vostok::physics::character_move_test_callback *this,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  float *m_hitCollisionObject; // eax
  double result; // st7
  btVector3 *p_m_hitNormalLocal; // esi
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  int *v10; // esi
  btCollisionObject *v11; // eax
  btVector3 v12; // [esp+10h] [ebp-20h]
  float v13[4]; // [esp+20h] [ebp-10h] BYREF

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
    v13[0] = (float)((float)(m_hitCollisionObject[5] * v7) + (float)(m_hitCollisionObject[6] * v6))
           + (float)(m_hitCollisionObject[4] * v8);
    v13[1] = (float)((float)(m_hitCollisionObject[9] * v7) + (float)(v9 * v6)) + (float)(v8 * m_hitCollisionObject[8]);
    v13[2] = (float)((float)(m_hitCollisionObject[13] * v7) + (float)(m_hitCollisionObject[14] * v6))
           + (float)(m_hitCollisionObject[12] * v8);
    v13[3] = 0.0;
    p_m_hitNormalLocal = (btVector3 *)v13;
  }
  v12.mVec128.m128_i32[0] = p_m_hitNormalLocal->mVec128.m128_i32[0];
  v10 = &p_m_hitNormalLocal->mVec128.m128_i32[1];
  v12.mVec128.m128_i32[1] = *v10++;
  v12.mVec128.m128_u64[1] = *(_QWORD *)v10;
  if ( this->m_minSlopeDot > (float)((float)((float)(this->m_up_vector.mVec128.m128_f32[1] * v12.mVec128.m128_f32[1])
                                           + (float)(this->m_up_vector.mVec128.m128_f32[2] * *(float *)v10))
                                   + (float)(this->m_up_vector.mVec128.m128_f32[0] * v12.mVec128.m128_f32[0])) )
    return 0.0;
  this->m_closestHitFraction = convexResult->m_hitFraction;
  v11 = convexResult->m_hitCollisionObject;
  result = this->m_closestHitFraction;
  this->m_hitNormalWorld = (btVector3)v12.mVec128;
  this->m_hitCollisionObject = v11;
  this->m_hitPointWorld = convexResult->m_hitPointLocal;
  return result;
}
