btVector3 *__thiscall vostok::physics::character_move_sweep_callback::get_normal_via_ray_test(
        btVector3 *hit_normal_world,
        vostok::physics::character_move_sweep_callback *this,
        btVector3 *convexResult,
        const btVector3 *a4)
{
  int v4; // edx
  float v5; // xmm7_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm7_4
  unsigned int v18; // xmm1_4
  unsigned int v19; // xmm2_4
  unsigned int v20; // xmm3_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  unsigned int v26; // xmm2_4
  unsigned int v27; // xmm0_4
  btVector3 *v28; // eax
  float v29; // xmm4_4
  float v30; // xmm5_4
  float v31; // xmm3_4
  unsigned int v32; // xmm1_4
  unsigned int v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm5_4
  float v37; // xmm6_4
  float v38; // xmm3_4
  float v39; // xmm1_4
  unsigned int v40; // xmm3_4
  unsigned int v41; // xmm2_4
  unsigned int v42; // xmm1_4
  btVector3 *v43; // eax
  float v44; // xmm4_4
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  float v51; // xmm1_4
  float v52; // xmm3_4
  unsigned int v53; // xmm3_4
  unsigned int v54; // xmm2_4
  unsigned int v55; // xmm1_4
  btVector3 *v56; // esi
  btVector3 *result; // eax
  int *v58; // esi
  btVector3 v59; // [esp+20h] [ebp-50h] BYREF
  btVector3 v60; // [esp+30h] [ebp-40h] BYREF
  btVector3 v61; // [esp+40h] [ebp-30h] BYREF
  btVector3 v62; // [esp+50h] [ebp-20h] BYREF
  btVector3 v63; // [esp+60h] [ebp-10h] BYREF

  v4 = *(_DWORD *)(*(_DWORD *)(a4->mVec128.m128_i32[0] + 212) + 4);
  if ( v4 == 8 || v4 == 10 || v4 == 9 )
  {
    v56 = hit_normal_world;
  }
  else
  {
    v5 = hit_normal_world->mVec128.m128_f32[0];
    LODWORD(v6) = hit_normal_world->mVec128.m128_i32[0] ^ _mask__NegFloat_;
    v7 = this->m_move_direction.mVec128.m128_f32[2]
       * COERCE_FLOAT(hit_normal_world->mVec128.m128_i32[2] ^ _mask__NegFloat_);
    v8 = this->m_move_direction.mVec128.m128_f32[1]
       * COERCE_FLOAT(hit_normal_world->mVec128.m128_i32[1] ^ _mask__NegFloat_);
    v9 = this->m_move_direction.mVec128.m128_f32[0];
    v59.mVec128.m128_i32[0] = hit_normal_world->mVec128.m128_i32[0];
    v10 = (float)(v7 + v8) + (float)(v9 * v6);
    v11 = this->m_up_vector.mVec128.m128_f32[2];
    *(unsigned __int64 *)((char *)v59.mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)hit_normal_world->mVec128.m128_u64
                                                                                  + 4);
    v59.mVec128.m128_i32[3] = hit_normal_world->mVec128.m128_i32[3];
    if ( fabs(v10 - s_bm_current_air_resistance) < 0.001 )
    {
      v29 = hit_normal_world->mVec128.m128_f32[2];
      v30 = hit_normal_world->mVec128.m128_f32[1];
      v31 = this->m_up_vector.mVec128.m128_f32[1];
      v62.mVec128.m128_f32[0] = (float)(v29 * v31) - (float)(v30 * v11);
      *(float *)&v32 = (float)(v11 * v5) - (float)(this->m_up_vector.mVec128.m128_f32[0] * v29);
      *(float *)&v33 = (float)(this->m_up_vector.mVec128.m128_f32[0] * v30) - (float)(v31 * v5);
      memset(&v61, 0, sizeof(v61));
      *(unsigned __int64 *)((char *)v62.mVec128.m128_u64 + 4) = __PAIR64__(v33, v32);
      v62.mVec128.m128_i32[3] = 0;
      vostok::physics::normalized_safe(&v62, &v60, &v61);
      v34 = a4[2].mVec128.m128_f32[1] + (float)(v60.mVec128.m128_f32[1] * s_cc_wall_normal_via_ray_offset_value);
      v35 = a4[2].mVec128.m128_f32[2];
      v36 = this->m_move_direction.mVec128.m128_f32[1] * 0.5;
      v37 = this->m_move_direction.mVec128.m128_f32[2] * 0.5;
      v38 = this->m_move_direction.mVec128.m128_f32[0];
      v61.mVec128.m128_f32[0] = (float)(a4[2].mVec128.m128_f32[0]
                                      + (float)(v60.mVec128.m128_f32[0] * s_cc_wall_normal_via_ray_offset_value))
                              - (float)(v38 * 0.5);
      v39 = v34 - v36;
      v62.mVec128.m128_f32[0] = v38 + v61.mVec128.m128_f32[0];
      *(float *)&v40 = this->m_move_direction.mVec128.m128_f32[1] + v39;
      v61.mVec128.m128_f32[1] = v39;
      *(float *)&v41 = (float)(v35 + (float)(v60.mVec128.m128_f32[2] * s_cc_wall_normal_via_ray_offset_value)) - v37;
      *(float *)&v42 = this->m_move_direction.mVec128.m128_f32[2] + *(float *)&v41;
      v61.mVec128.m128_u64[1] = v41;
      *(unsigned __int64 *)((char *)v62.mVec128.m128_u64 + 4) = __PAIR64__(v42, v40);
      v62.mVec128.m128_i32[3] = 0;
      v43 = vostok::physics::character_move_sweep_callback::perform_ray_test(
              &v62,
              (btCollisionWorld::ClosestRayResultCallback *)&v61,
              this,
              &v63,
              &v59,
              a4,
              &v61);
      v44 = this->m_move_direction.mVec128.m128_f32[0];
      v45 = this->m_move_direction.mVec128.m128_f32[1];
      v46 = this->m_move_direction.mVec128.m128_f32[2];
      v47 = a4[2].mVec128.m128_f32[0] - (float)(v60.mVec128.m128_f32[0] * s_cc_wall_normal_via_ray_offset_value);
      v48 = a4[2].mVec128.m128_f32[1] - (float)(v60.mVec128.m128_f32[1] * s_cc_wall_normal_via_ray_offset_value);
      v49 = a4[2].mVec128.m128_f32[2];
      v59.mVec128.m128_i32[0] = v43->mVec128.m128_i32[0];
      v50 = this->m_move_direction.mVec128.m128_f32[0];
      v59.mVec128.m128_i32[1] = v43->mVec128.m128_i32[1];
      v61.mVec128.m128_f32[0] = v47 - (float)(v44 * 0.5);
      v51 = v48 - (float)(v45 * 0.5);
      v62.mVec128.m128_f32[0] = v50 + v61.mVec128.m128_f32[0];
      v52 = this->m_move_direction.mVec128.m128_f32[1];
      v59.mVec128.m128_i32[2] = v43->mVec128.m128_i32[2];
      *(float *)&v53 = v52 + v51;
      v61.mVec128.m128_f32[1] = v51;
      *(float *)&v54 = (float)(v49 - (float)(v60.mVec128.m128_f32[2] * s_cc_wall_normal_via_ray_offset_value))
                     - (float)(v46 * 0.5);
      *(float *)&v55 = this->m_move_direction.mVec128.m128_f32[2] + *(float *)&v54;
      v59.mVec128.m128_i32[3] = v43->mVec128.m128_i32[3];
      v61.mVec128.m128_u64[1] = v54;
      *(unsigned __int64 *)((char *)v62.mVec128.m128_u64 + 4) = __PAIR64__(v55, v53);
      v62.mVec128.m128_i32[3] = 0;
      v28 = vostok::physics::character_move_sweep_callback::perform_ray_test(
              &v62,
              (btCollisionWorld::ClosestRayResultCallback *)&v61,
              this,
              &v63,
              &v59,
              a4,
              &v61);
    }
    else
    {
      v12 = (float)((float)(v11 * (float)(a4[2].mVec128.m128_f32[2] - this->m_start.mVec128.m128_f32[2]))
                  + (float)(this->m_up_vector.mVec128.m128_f32[1]
                          * (float)(a4[2].mVec128.m128_f32[1] - this->m_start.mVec128.m128_f32[1])))
          + (float)(this->m_up_vector.mVec128.m128_f32[0]
                  * (float)(a4[2].mVec128.m128_f32[0] - this->m_start.mVec128.m128_f32[0]));
      v13 = this->m_start.mVec128.m128_f32[1] + (float)(this->m_up_vector.mVec128.m128_f32[1] * v12);
      v14 = this->m_start.mVec128.m128_f32[2] + (float)(this->m_up_vector.mVec128.m128_f32[2] * v12);
      v15 = (float)((float)(a4[2].mVec128.m128_f32[2] - v14) * (float)(a4[2].mVec128.m128_f32[2] - v14))
          + (float)((float)(a4[2].mVec128.m128_f32[1] - v13) * (float)(a4[2].mVec128.m128_f32[1] - v13));
      v16 = this->m_move_direction.mVec128.m128_f32[1];
      v62.mVec128.m128_f32[0] = (float)(this->m_up_vector.mVec128.m128_f32[0] * v12) + this->m_start.mVec128.m128_f32[0];
      v17 = fsqrt(
              v15
            + (float)((float)(a4[2].mVec128.m128_f32[0] - v62.mVec128.m128_f32[0])
                    * (float)(a4[2].mVec128.m128_f32[0] - v62.mVec128.m128_f32[0])));
      *(float *)&v18 = (float)((float)((float)(this->m_move_direction.mVec128.m128_f32[0] * v17)
                                     * (float)(s_bm_current_air_resistance / v10))
                             + v62.mVec128.m128_f32[0])
                     - a4[2].mVec128.m128_f32[0];
      *(float *)&v19 = (float)((float)((float)(v16 * v17) * (float)(s_bm_current_air_resistance / v10)) + v13)
                     - a4[2].mVec128.m128_f32[1];
      *(float *)&v20 = (float)((float)((float)(this->m_move_direction.mVec128.m128_f32[2] * v17)
                                     * (float)(s_bm_current_air_resistance / v10))
                             + v14)
                     - a4[2].mVec128.m128_f32[2];
      memset(&v61, 0, sizeof(v61));
      v60.mVec128.m128_u64[0] = __PAIR64__(v19, v18);
      v60.mVec128.m128_u64[1] = v20;
      vostok::physics::normalized_safe(&v60, &v62, &v61);
      v21 = this->m_move_direction.mVec128.m128_f32[1];
      v22 = this->m_move_direction.mVec128.m128_f32[2];
      v23 = a4[2].mVec128.m128_f32[1] + (float)(v62.mVec128.m128_f32[1] * s_cc_wall_normal_via_ray_offset_value);
      v24 = a4[2].mVec128.m128_f32[2];
      v60.mVec128.m128_f32[0] = (float)(a4[2].mVec128.m128_f32[0]
                                      + (float)(v62.mVec128.m128_f32[0] * s_cc_wall_normal_via_ray_offset_value))
                              - (float)(this->m_move_direction.mVec128.m128_f32[0] * 0.5);
      v61.mVec128.m128_f32[0] = v60.mVec128.m128_f32[0] + this->m_move_direction.mVec128.m128_f32[0];
      v25 = this->m_move_direction.mVec128.m128_f32[1];
      v60.mVec128.m128_f32[1] = v23 - (float)(v21 * 0.5);
      v61.mVec128.m128_f32[1] = v25 + v60.mVec128.m128_f32[1];
      *(float *)&v26 = (float)(v24 + (float)(v62.mVec128.m128_f32[2] * s_cc_wall_normal_via_ray_offset_value))
                     - (float)(v22 * 0.5);
      *(float *)&v27 = this->m_move_direction.mVec128.m128_f32[2] + *(float *)&v26;
      v60.mVec128.m128_u64[1] = v26;
      v61.mVec128.m128_u64[1] = v27;
      v28 = vostok::physics::character_move_sweep_callback::perform_ray_test(
              &v61,
              (btCollisionWorld::ClosestRayResultCallback *)&v60,
              this,
              &v62,
              &v59,
              a4,
              &v60);
    }
    v59.mVec128 = v28->mVec128;
    v56 = &v59;
  }
  result = convexResult;
  convexResult->mVec128.m128_i32[0] = v56->mVec128.m128_i32[0];
  v58 = &v56->mVec128.m128_i32[1];
  convexResult->mVec128.m128_i32[1] = *v58;
  convexResult->mVec128.m128_u64[1] = *(_QWORD *)(v58 + 1);
  return result;
}
