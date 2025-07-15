btVector3 *__userpurge character_step_down_sweep_test_callback::get_normal_for_impassable_slope@<eax>(
        character_step_down_sweep_test_callback *this@<ecx>,
        btVector3 *a2@<eax>,
        btVector3 *result,
        const btVector3 *hit_normal_world)
{
  btVector3 *v4; // esi
  float v5; // xmm6_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm6_4
  float v18; // xmm2_4
  int *v19; // esi
  float v20; // [esp+4h] [ebp-14h]
  float v21[4]; // [esp+8h] [ebp-10h] BYREF

  v4 = result;
  v5 = result->mVec128.m128_f32[0];
  if ( fabs(
         (float)((float)((float)(this->m_up_vector.mVec128.m128_f32[1] * result->mVec128.m128_f32[1])
                       + (float)(this->m_up_vector.mVec128.m128_f32[2] * result->mVec128.m128_f32[2]))
               + (float)(result->mVec128.m128_f32[0] * this->m_up_vector.mVec128.m128_f32[0]))
       - s_bm_current_air_resistance) >= 0.0000099999997 )
  {
    v6 = result->mVec128.m128_f32[2];
    v7 = result->mVec128.m128_f32[1];
    v8 = this->m_up_vector.mVec128.m128_f32[2];
    v9 = this->m_up_vector.mVec128.m128_f32[1];
    v20 = this->m_up_vector.mVec128.m128_f32[0];
    v10 = (float)((float)(v7 * v9) + (float)(v6 * v8)) + (float)(v20 * v5);
    v11 = v7 - (float)(v9 * v10);
    v12 = v6 - (float)(v8 * v10);
    v13 = (float)this->m_min_slope_dot - 0.001;
    v14 = v5 - (float)(v20 * v10);
    v15 = fsqrt(
            (float)(s_bm_current_air_resistance - (float)(v13 * v13))
          / (float)((float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v14 * v14)));
    v16 = v14 * v15;
    v17 = v12 * v15;
    v18 = this->m_up_vector.mVec128.m128_f32[2];
    v21[0] = (float)(v20 * v13) + v16;
    v21[1] = (float)(v9 * v13) + (float)(v11 * v15);
    v21[2] = (float)(v18 * v13) + v17;
    v21[3] = 0.0;
    v4 = (btVector3 *)v21;
  }
  a2->mVec128.m128_i32[0] = v4->mVec128.m128_i32[0];
  v19 = &v4->mVec128.m128_i32[1];
  a2->mVec128.m128_i32[1] = *v19;
  a2->mVec128.m128_u64[1] = *(_QWORD *)(v19 + 1);
  return a2;
}
