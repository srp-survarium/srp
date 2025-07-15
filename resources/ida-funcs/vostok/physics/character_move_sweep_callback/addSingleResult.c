double __thiscall vostok::physics::character_move_sweep_callback::addSingleResult(
        vostok::physics::character_move_sweep_callback *this,
        const btVector3 *convexResult,
        bool normalInWorldSpace)
{
  float *v4; // eax
  btVector3 *v6; // esi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm5_4
  float v11; // xmm1_4
  int *v12; // esi
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  btCollisionObject *v17; // ecx
  btVector3 hit_normal_world; // [esp+10h] [ebp-40h] BYREF
  btVector3 v19; // [esp+20h] [ebp-30h] BYREF
  btVector3 v20; // [esp+30h] [ebp-20h] BYREF
  btVector3 v21; // [esp+40h] [ebp-10h] BYREF

  v4 = (float *)convexResult->mVec128.m128_i32[0];
  if ( (btCollisionObject *)convexResult->mVec128.m128_i32[0] == this->m_self )
    return 1.0;
  if ( normalInWorldSpace )
  {
    v6 = (btVector3 *)&convexResult[1];
  }
  else
  {
    v7 = convexResult[1].mVec128.m128_f32[2];
    v8 = convexResult[1].mVec128.m128_f32[1];
    v9 = convexResult[1].mVec128.m128_f32[0];
    v10 = v4[10];
    v19.mVec128.m128_f32[0] = (float)((float)(v4[5] * v8) + (float)(v4[6] * v7)) + (float)(v4[4] * v9);
    v19.mVec128.m128_f32[1] = (float)((float)(v4[9] * v8) + (float)(v10 * v7)) + (float)(v4[8] * v9);
    v19.mVec128.m128_f32[2] = (float)((float)(v4[13] * v8) + (float)(v4[14] * v7)) + (float)(v4[12] * v9);
    v19.mVec128.m128_i32[3] = 0;
    v6 = &v19;
  }
  v11 = convexResult[3].mVec128.m128_f32[0];
  hit_normal_world.mVec128.m128_i32[0] = v6->mVec128.m128_i32[0];
  v12 = &v6->mVec128.m128_i32[1];
  hit_normal_world.mVec128.m128_i32[1] = *v12;
  hit_normal_world.mVec128.m128_u64[1] = *(_QWORD *)(v12 + 1);
  if ( v11 != 0.0
    || (float)((float)((float)(this->m_move_direction.mVec128.m128_f32[2]
                             * (float)(convexResult[2].mVec128.m128_f32[2] - this->m_start.mVec128.m128_f32[2]))
                     + (float)(this->m_move_direction.mVec128.m128_f32[1]
                             * (float)(convexResult[2].mVec128.m128_f32[1] - this->m_start.mVec128.m128_f32[1])))
             + (float)((float)(convexResult[2].mVec128.m128_f32[0] - this->m_start.mVec128.m128_f32[0])
                     * this->m_move_direction.mVec128.m128_f32[0])) > 0.0 )
  {
    v19.mVec128.m128_i32[0] = this->m_move_direction.mVec128.m128_i32[0] ^ _mask__NegFloat_;
    v19.mVec128.m128_i32[1] = this->m_move_direction.mVec128.m128_i32[1] ^ _mask__NegFloat_;
    v13 = this->m_up_vector.mVec128.m128_f32[2];
    v14 = this->m_up_vector.mVec128.m128_f32[0];
    v19.mVec128.m128_u64[1] = this->m_move_direction.mVec128.m128_u32[2]
                            ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
    v15 = (float)((float)(v13 * hit_normal_world.mVec128.m128_f32[2])
                + (float)(this->m_up_vector.mVec128.m128_f32[1] * hit_normal_world.mVec128.m128_f32[1]))
        + (float)(v14 * hit_normal_world.mVec128.m128_f32[0]);
    v16 = this->m_up_vector.mVec128.m128_f32[1] * v15;
    v20.mVec128.m128_f32[0] = hit_normal_world.mVec128.m128_f32[0] - (float)(v14 * v15);
    v20.mVec128.m128_f32[1] = hit_normal_world.mVec128.m128_f32[1] - v16;
    v20.mVec128.m128_f32[2] = hit_normal_world.mVec128.m128_f32[2] - (float)(v13 * v15);
    v20.mVec128.m128_i32[3] = 0;
    hit_normal_world.mVec128 = vostok::physics::normalized_safe(&v20, &v21, &v19)->mVec128;
    if ( s_cc_wall_normal_via_ray_value
      && (float)((float)((float)(this->m_move_direction.mVec128.m128_f32[2]
                               * COERCE_FLOAT(hit_normal_world.mVec128.m128_i32[2] ^ _mask__NegFloat_))
                       + (float)(this->m_move_direction.mVec128.m128_f32[1]
                               * COERCE_FLOAT(hit_normal_world.mVec128.m128_i32[1] ^ _mask__NegFloat_)))
               + (float)(this->m_move_direction.mVec128.m128_f32[0]
                       * COERCE_FLOAT(hit_normal_world.mVec128.m128_i32[0] ^ _mask__NegFloat_))) > this->m_wall_full_slide_dot )
    {
      hit_normal_world.mVec128 = vostok::physics::character_move_sweep_callback::get_normal_via_ray_test(
                                   &hit_normal_world,
                                   this,
                                   &v21,
                                   convexResult)->mVec128;
    }
    this->m_closestHitFraction = convexResult[3].mVec128.m128_f32[0];
    v17 = (btCollisionObject *)convexResult->mVec128.m128_i32[0];
    this->m_hitNormalWorld = (btVector3)hit_normal_world.mVec128;
    this->m_hitCollisionObject = v17;
    this->m_hitPointWorld = (btVector3)convexResult[2].mVec128;
  }
  return this->m_closestHitFraction;
}
