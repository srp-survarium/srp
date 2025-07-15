double __thiscall character_step_down_sweep_test_callback::addSingleResult(
        character_step_down_sweep_test_callback *this,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  float *m_hitCollisionObject; // eax
  btVector3 *p_m_hitNormalLocal; // esi
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  unsigned int v9; // xmm0_4
  unsigned int v10; // xmm1_4
  int *v11; // esi
  character_step_down_sweep_test_callback *m_userObjectPointer; // ecx
  btCollisionWorld::LocalConvexResult *v13; // esi
  int v14; // eax
  btVector3 *p_m_steep_hit_point_world; // edi
  int *v16; // edi
  btVector3 *normal_via_ray_test; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  btCollisionObject *v21; // eax
  const btVector3 *v22; // [esp+0h] [ebp-40h]
  btVector3 hit_normal; // [esp+10h] [ebp-30h] BYREF
  btVector3 v24; // [esp+20h] [ebp-20h] BYREF
  btVector3 result; // [esp+30h] [ebp-10h] BYREF

  m_hitCollisionObject = (float *)convexResult->m_hitCollisionObject;
  if ( convexResult->m_hitCollisionObject != this->m_self
    && convexResult->m_hitFraction <= this->m_steep_collision_closest_hit_fraction
    && (float)((float)((float)(this->m_up_vector.mVec128.m128_f32[2] * convexResult->m_hitPointLocal.mVec128.m128_f32[2])
                     + (float)(this->m_up_vector.mVec128.m128_f32[1] * convexResult->m_hitPointLocal.mVec128.m128_f32[1]))
             + (float)(this->m_up_vector.mVec128.m128_f32[0] * convexResult->m_hitPointLocal.mVec128.m128_f32[0])) <= this->m_max_contact_height )
  {
    if ( normalInWorldSpace )
    {
      p_m_hitNormalLocal = &convexResult->m_hitNormalLocal;
    }
    else
    {
      v6 = convexResult->m_hitNormalLocal.mVec128.m128_f32[2];
      v7 = convexResult->m_hitNormalLocal.mVec128.m128_f32[1];
      v8 = convexResult->m_hitNormalLocal.mVec128.m128_f32[0];
      *(float *)&v9 = (float)((float)(m_hitCollisionObject[13] * v7) + (float)(m_hitCollisionObject[14] * v6))
                    + (float)(m_hitCollisionObject[12] * v8);
      *(float *)&v10 = (float)((float)(m_hitCollisionObject[9] * v7) + (float)(m_hitCollisionObject[10] * v6))
                     + (float)(v8 * m_hitCollisionObject[8]);
      v24.mVec128.m128_f32[0] = (float)((float)(m_hitCollisionObject[5] * v7) + (float)(m_hitCollisionObject[6] * v6))
                              + (float)(m_hitCollisionObject[4] * v8);
      *(unsigned __int64 *)((char *)v24.mVec128.m128_u64 + 4) = __PAIR64__(v9, v10);
      v24.mVec128.m128_i32[3] = 0;
      p_m_hitNormalLocal = &v24;
    }
    hit_normal.mVec128.m128_i32[0] = p_m_hitNormalLocal->mVec128.m128_i32[0];
    v11 = &p_m_hitNormalLocal->mVec128.m128_i32[1];
    hit_normal.mVec128.m128_i32[1] = *v11;
    hit_normal.mVec128.m128_u64[1] = *(_QWORD *)(v11 + 1);
    if ( !character_step_down_sweep_test_callback::is_side_contact(&convexResult->m_hitPointLocal, &hit_normal, this) )
    {
      m_userObjectPointer = (character_step_down_sweep_test_callback *)convexResult->m_hitCollisionObject->m_userObjectPointer;
      v13 = convexResult;
      v14 = 0;
      if ( convexResult->m_localShapeInfo )
        v14 = ((int (__thiscall *)(character_step_down_sweep_test_callback *, int, bool))m_userObjectPointer->__vftable[1].addSingleResult)(
                m_userObjectPointer,
                convexResult->m_localShapeInfo->m_triangleIndex,
                convexResult->m_localShapeInfo->m_is_shape_index);
      if ( v14 )
      {
        if ( v14 != 1 )
        {
          hit_normal.mVec128 = character_step_down_sweep_test_callback::get_normal_for_impassable_slope(
                                 this,
                                 &v24,
                                 &hit_normal,
                                 v22)->mVec128;
LABEL_13:
          this->m_has_steep_collision = 1;
          this->m_steep_collision_closest_hit_fraction = convexResult->m_hitFraction;
          this->m_steep_hit_normal_world = (btVector3)hit_normal.mVec128;
          p_m_steep_hit_point_world = &this->m_steep_hit_point_world;
LABEL_14:
          p_m_steep_hit_point_world->mVec128.m128_i32[0] = convexResult->m_hitPointLocal.mVec128.m128_i32[0];
          v16 = &p_m_steep_hit_point_world->mVec128.m128_i32[1];
          *v16 = convexResult->m_hitPointLocal.mVec128.m128_i32[1];
          *(_QWORD *)(v16 + 1) = convexResult->m_hitPointLocal.mVec128.m128_u64[1];
          return this->m_closestHitFraction;
        }
        hit_normal.mVec128 = (__m128)this->m_up_vector;
      }
      else
      {
        if ( this->m_min_slope_dot <= (float)((float)((float)(this->m_up_vector.mVec128.m128_f32[1]
                                                            * hit_normal.mVec128.m128_f32[1])
                                                    + (float)(this->m_up_vector.mVec128.m128_f32[2]
                                                            * hit_normal.mVec128.m128_f32[2]))
                                            + (float)(this->m_up_vector.mVec128.m128_f32[0]
                                                    * hit_normal.mVec128.m128_f32[0])) )
        {
LABEL_20:
          this->m_closestHitFraction = v13->m_hitFraction;
          v21 = v13->m_hitCollisionObject;
          this->m_hitNormalWorld = (btVector3)hit_normal.mVec128;
          this->m_hitCollisionObject = v21;
          p_m_steep_hit_point_world = &this->m_hitPointWorld;
          goto LABEL_14;
        }
        normal_via_ray_test = character_step_down_sweep_test_callback::get_normal_via_ray_test(
                                m_userObjectPointer,
                                (int)this,
                                &result,
                                convexResult,
                                &hit_normal);
        v19 = this->m_up_vector.mVec128.m128_f32[1];
        v20 = this->m_up_vector.mVec128.m128_f32[2];
        hit_normal.mVec128 = normal_via_ray_test->mVec128;
        if ( this->m_min_slope_dot > (float)((float)((float)(v19 * hit_normal.mVec128.m128_f32[1])
                                                   + (float)(v20 * hit_normal.mVec128.m128_f32[2]))
                                           + (float)(this->m_up_vector.mVec128.m128_f32[0]
                                                   * hit_normal.mVec128.m128_f32[0])) )
          goto LABEL_13;
      }
      v13 = convexResult;
      goto LABEL_20;
    }
  }
  return this->m_closestHitFraction;
}
