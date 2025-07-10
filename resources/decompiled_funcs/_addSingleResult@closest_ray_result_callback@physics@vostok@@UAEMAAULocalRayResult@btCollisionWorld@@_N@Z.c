double __thiscall vostok::physics::closest_ray_result_callback::addSingleResult(
        vostok::physics::closest_ray_result_callback *this,
        btCollisionWorld::LocalRayResult *rayResult,
        bool normalInWorldSpace)
{
  unsigned __int64 v3; // xmm0_8
  float v4; // xmm0_4
  float *m_collisionObject; // eax
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float m_hitFraction; // xmm1_4
  float v11; // xmm0_4
  unsigned __int64 v13; // [esp+0h] [ebp-10h]
  unsigned __int64 v14; // [esp+8h] [ebp-8h]

  this->m_closestHitFraction = rayResult->m_hitFraction;
  this->m_collisionObject = rayResult->m_collisionObject;
  if ( rayResult->m_localShapeInfo )
  {
    this->m_triangleIndex = rayResult->m_localShapeInfo->m_triangleIndex;
    this->m_is_shape_index = rayResult->m_localShapeInfo->m_is_shape_index;
  }
  else
  {
    this->m_triangleIndex = -1;
    this->m_is_shape_index = 0;
  }
  if ( normalInWorldSpace )
  {
    this->m_hitNormalWorld.mVec128.m128_u64[0] = rayResult->m_hitNormalLocal.mVec128.m128_u64[0];
    v3 = rayResult->m_hitNormalLocal.mVec128.m128_u64[1];
  }
  else
  {
    v4 = rayResult->m_hitNormalLocal.mVec128.m128_f32[2];
    m_collisionObject = (float *)this->m_collisionObject;
    v6 = rayResult->m_hitNormalLocal.mVec128.m128_f32[1];
    v7 = m_collisionObject[5];
    v8 = m_collisionObject[6];
    v9 = rayResult->m_hitNormalLocal.mVec128.m128_f32[0];
    m_collisionObject += 4;
    *(float *)&v13 = (float)((float)(v7 * v6) + (float)(v8 * v4)) + (float)(*m_collisionObject * v9);
    *((float *)&v13 + 1) = (float)((float)(m_collisionObject[5] * v6) + (float)(m_collisionObject[6] * v4))
                         + (float)(m_collisionObject[4] * v9);
    v14 = COERCE_UNSIGNED_INT(
            (float)((float)(m_collisionObject[9] * v6) + (float)(m_collisionObject[10] * v4))
          + (float)(m_collisionObject[8] * v9));
    this->m_hitNormalWorld.mVec128.m128_u64[0] = v13;
    v3 = v14;
  }
  this->m_hitNormalWorld.mVec128.m128_u64[1] = v3;
  m_hitFraction = rayResult->m_hitFraction;
  v11 = *(float *)&clear_value - m_hitFraction;
  this->m_hitPointWorld.mVec128.m128_f32[0] = (float)(this->m_rayFromWorld.mVec128.m128_f32[0]
                                                    * (float)(*(float *)&clear_value - m_hitFraction))
                                            + (float)(m_hitFraction * this->m_rayToWorld.mVec128.m128_f32[0]);
  this->m_hitPointWorld.mVec128.m128_f32[1] = (float)(this->m_rayFromWorld.mVec128.m128_f32[1] * v11)
                                            + (float)(this->m_rayToWorld.mVec128.m128_f32[1] * m_hitFraction);
  this->m_hitPointWorld.mVec128.m128_f32[2] = (float)(this->m_rayFromWorld.mVec128.m128_f32[2] * v11)
                                            + (float)(this->m_rayToWorld.mVec128.m128_f32[2] * m_hitFraction);
  return rayResult->m_hitFraction;
}
