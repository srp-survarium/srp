double __thiscall vostok::physics::closest_ray_result_callback::addSingleResult(
        vostok::physics::closest_ray_result_callback *this,
        btCollisionWorld::LocalRayResult *rayResult,
        bool normalInWorldSpace)
{
  btCollisionObject *m_collisionObject; // eax
  bool v4; // zf
  signed int v5; // eax
  btVector3 *p_m_hitNormalLocal; // esi
  float *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  int *v20; // esi
  float m_hitFraction; // xmm1_4
  float v22; // xmm0_4
  _DWORD v23[4]; // [esp+10h] [ebp-10h] BYREF

  m_collisionObject = rayResult->m_collisionObject;
  if ( rayResult->m_collisionObject && (m_collisionObject->m_broadphaseHandle->m_collisionFilterGroup & 0x40) != 0 )
  {
    v5 = (int)m_collisionObject->m_collisionShape->m_userPointer & 0x80000001;
    v4 = v5 == 0;
    if ( v5 < 0 )
      v4 = (((_BYTE)v5 - 1) | 0xFFFFFFFE) == -1;
    if ( !v4 )
      return 10000.0;
  }
  if ( this->m_need_re_trace )
    return 10000.0;
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
    p_m_hitNormalLocal = &rayResult->m_hitNormalLocal;
  }
  else
  {
    v8 = (float *)this->m_collisionObject;
    v9 = rayResult->m_hitNormalLocal.mVec128.m128_f32[1];
    v10 = rayResult->m_hitNormalLocal.mVec128.m128_f32[2];
    v11 = rayResult->m_hitNormalLocal.mVec128.m128_f32[0];
    v12 = v8[5];
    v13 = v8[6];
    v8 += 4;
    v14 = (float)((float)(v12 * v9) + (float)(v13 * v10)) + (float)(v11 * *v8);
    v15 = v8[6];
    *(float *)v23 = v14;
    v16 = (float)(v8[5] * v9) + (float)(v15 * v10);
    v17 = v11 * v8[4];
    v18 = v11 * v8[8];
    *(float *)&v23[1] = v16 + v17;
    *(float *)&v23[2] = (float)((float)(v8[9] * v9) + (float)(v8[10] * v10)) + v18;
    v23[3] = 0;
    p_m_hitNormalLocal = (btVector3 *)v23;
  }
  v19 = s_bm_current_air_resistance;
  this->m_hitNormalWorld.mVec128.m128_i32[0] = p_m_hitNormalLocal->mVec128.m128_i32[0];
  v20 = &p_m_hitNormalLocal->mVec128.m128_i32[1];
  this->m_hitNormalWorld.mVec128.m128_i32[1] = *v20;
  this->m_hitNormalWorld.mVec128.m128_u64[1] = *(_QWORD *)(v20 + 1);
  m_hitFraction = rayResult->m_hitFraction;
  v22 = v19 - m_hitFraction;
  this->m_hitPointWorld.mVec128.m128_f32[0] = (float)(this->m_rayFromWorld.mVec128.m128_f32[0] * v22)
                                            + (float)(this->m_rayToWorld.mVec128.m128_f32[0] * m_hitFraction);
  this->m_hitPointWorld.mVec128.m128_f32[1] = (float)(this->m_rayFromWorld.mVec128.m128_f32[1] * v22)
                                            + (float)(this->m_rayToWorld.mVec128.m128_f32[1] * m_hitFraction);
  this->m_hitPointWorld.mVec128.m128_f32[2] = (float)(this->m_rayFromWorld.mVec128.m128_f32[2] * v22)
                                            + (float)(this->m_rayToWorld.mVec128.m128_f32[2] * m_hitFraction);
  return rayResult->m_hitFraction;
}
