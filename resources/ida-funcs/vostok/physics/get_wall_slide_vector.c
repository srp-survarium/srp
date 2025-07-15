btVector3 *__usercall vostok::physics::get_wall_slide_vector@<eax>(
        const btVector3 *move_vector@<eax>,
        const btVector3 *wall_normal@<ecx>,
        btVector3 *a3)
{
  float v3; // xmm5_4
  float v4; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm6_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  btVector3 *result; // eax
  float v20; // xmm5_4
  float v21; // [esp+8h] [ebp-28h]
  float v22; // [esp+8h] [ebp-28h]
  float v23; // [esp+Ch] [ebp-24h]
  float v24; // [esp+28h] [ebp-8h]

  v3 = wall_normal->mVec128.m128_f32[2];
  v23 = move_vector->mVec128.m128_f32[0] * move_vector->mVec128.m128_f32[0];
  v4 = wall_normal->mVec128.m128_f32[1];
  v5 = s_bm_current_air_resistance
     / fsqrt(
         (float)((float)(move_vector->mVec128.m128_f32[1] * move_vector->mVec128.m128_f32[1])
               + (float)(move_vector->mVec128.m128_f32[2] * move_vector->mVec128.m128_f32[2]))
       + v23);
  v6 = move_vector->mVec128.m128_f32[0] * v5;
  v7 = v5 * move_vector->mVec128.m128_f32[1];
  v24 = v5 * move_vector->mVec128.m128_f32[2];
  v21 = wall_normal->mVec128.m128_f32[0] * v6;
  v8 = (float)((float)(v3 * v24) + (float)(v4 * v7)) + v21;
  v9 = (float)(v6 - (float)(wall_normal->mVec128.m128_f32[0] * v8))
     + (float)(wall_normal->mVec128.m128_f32[0] * s_cc_wall_slide_bouncing_factor);
  v10 = (float)(v7 - (float)(v4 * v8)) + (float)(v4 * s_cc_wall_slide_bouncing_factor);
  v11 = (float)(v24 - (float)(v3 * v8)) + (float)(v3 * s_cc_wall_slide_bouncing_factor);
  v12 = s_bm_current_air_resistance / fsqrt((float)((float)(v11 * v11) + (float)(v10 * v10)) + (float)(v9 * v9));
  v13 = v12 * v9;
  v14 = v10 * v12;
  v15 = v11 * v12;
  v22 = fabs((float)((float)(v3 * v24) + (float)(wall_normal->mVec128.m128_f32[1] * v7)) + v21);
  v16 = s_bm_current_air_resistance;
  if ( vostok::physics::bullet_character_controller::ms_wall_full_slide_dot <= v22 )
    v16 = (float)(s_bm_current_air_resistance - v22)
        / (float)(s_bm_current_air_resistance - vostok::physics::bullet_character_controller::ms_wall_full_slide_dot);
  v17 = move_vector->mVec128.m128_f32[1];
  v18 = move_vector->mVec128.m128_f32[2];
  result = a3;
  v20 = fsqrt((float)((float)(v17 * v17) + (float)(v18 * v18)) + v23);
  a3->mVec128.m128_f32[0] = (float)(v13 * v20) * v16;
  a3->mVec128.m128_f32[1] = (float)(v14 * v20) * v16;
  a3->mVec128.m128_f32[2] = (float)(v15 * v20) * v16;
  a3->mVec128.m128_i32[3] = 0;
  return result;
}
