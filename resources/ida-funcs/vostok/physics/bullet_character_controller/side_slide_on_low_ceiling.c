bool __fastcall vostok::physics::bullet_character_controller::side_slide_on_low_ceiling(
        int a1,
        btVector3 *ceiling_normal,
        const btVector3 *this,
        const btVector3 *move_vector,
        btVector3 *position_after_step_up,
        const btVector3 *pre_step_bottom_pos,
        float down_step,
        btVector3 *current_step_offset,
        btVector3 *in_out_floor_normal,
        float *hit_fraction)
{
  float v10; // xmm3_4
  btVector3 *v11; // ecx
  float v12; // xmm2_4
  bool v13; // cc
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  btVector3 *v19; // eax
  bool result; // al
  float v21; // xmm1_4
  vostok::physics::bullet_character_controller *v22; // [esp+Ch] [ebp-54h]
  float v23; // [esp+24h] [ebp-3Ch]
  btVector3 v24; // [esp+30h] [ebp-30h] BYREF
  btVector3 v25; // [esp+40h] [ebp-20h] BYREF
  btVector3 v26; // [esp+50h] [ebp-10h] BYREF

  if ( !s_cc_low_ceiling_slide )
    return 0;
  v10 = move_vector->mVec128.m128_f32[0];
  if ( fabs(
         (float)((float)(move_vector->mVec128.m128_f32[1] * move_vector->mVec128.m128_f32[1])
               + (float)(move_vector->mVec128.m128_f32[2] * move_vector->mVec128.m128_f32[2]))
       + (float)(v10 * v10)) < 0.0000099999997 )
    return 0;
  v23 = fabs(
          (float)((float)(ceiling_normal->mVec128.m128_f32[1]
                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                + (float)(ceiling_normal->mVec128.m128_f32[2]
                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
        + (float)(ceiling_normal->mVec128.m128_f32[0]
                * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]));
  v11 = in_out_floor_normal;
  v12 = fabs(
          (float)((float)(in_out_floor_normal->mVec128.m128_f32[1]
                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                + (float)(in_out_floor_normal->mVec128.m128_f32[2]
                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
        + (float)(in_out_floor_normal->mVec128.m128_f32[0]
                * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]));
  if ( fabs(v23 - s_bm_current_air_resistance) < 0.0000099999997
    && fabs(v12 - s_bm_current_air_resistance) < 0.0000099999997 )
  {
    return 0;
  }
  v13 = v12 <= v23;
  v14 = move_vector->mVec128.m128_f32[1];
  v15 = move_vector->mVec128.m128_f32[2];
  if ( !v13 )
    v11 = ceiling_normal;
  v24.mVec128.m128_u64[0] = v11->mVec128.m128_u64[0];
  v24.mVec128.m128_i32[2] = v11->mVec128.m128_i32[2];
  v16 = s_bm_current_air_resistance / fsqrt((float)((float)(v14 * v14) + (float)(v15 * v15)) + (float)(v10 * v10));
  v17 = move_vector->mVec128.m128_f32[2] * v16;
  v18 = (float)(move_vector->mVec128.m128_f32[1] * v16) * s_cc_low_ceiling_slide_bouncing_factor;
  v24.mVec128.m128_i32[3] = v11->mVec128.m128_i32[3];
  v25.mVec128.m128_f32[0] = v24.mVec128.m128_f32[0]
                          - (float)((float)(v10 * v16) * s_cc_low_ceiling_slide_bouncing_factor);
  v25.mVec128.m128_f32[2] = v24.mVec128.m128_f32[2] - (float)(v17 * s_cc_low_ceiling_slide_bouncing_factor);
  v25.mVec128.m128_f32[1] = v24.mVec128.m128_f32[1] - v18;
  v25.mVec128.m128_i32[3] = 0;
  v19 = vostok::physics::normalized_safe(&v25, &v26, &v24);
  v24.mVec128 = v19->mVec128;
  result = vostok::physics::bullet_character_controller::slide_in_impassable_case_impl(
             v22,
             &v25,
             v19 + 1,
             this,
             move_vector,
             position_after_step_up,
             pre_step_bottom_pos,
             down_step,
             current_step_offset,
             &v24,
             hit_fraction);
  v21 = *hit_fraction;
  *in_out_floor_normal = (btVector3)v24.mVec128;
  *hit_fraction = v21 - (float)(*(float *)&current_step_offset / down_step);
  return result;
}
