char __thiscall vostok::physics::bullet_character_controller::step_down_sweep_test_impl(
        vostok::physics::bullet_character_controller *this,
        const float down_step,
        float current_step_offset,
        float pre_step_bottom_pos,
        float *horz_move_vector_len2,
        const btVector3 *position_after_step_up,
        btVector3 *hit_point,
        btVector3 *hit_normal,
        btVector3 *time_hit_fraction,
        float *a10)
{
  vostok::physics::character_controller_step_down_tester *v10; // ecx
  float v11; // xmm3_4
  float v12; // xmm1_4
  bool v13; // al
  float v14; // xmm3_4
  char v15; // al
  float v16; // xmm7_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float *v20; // eax
  float v21; // xmm4_4
  float v22; // xmm5_4
  btVector3 *p_down_stepa; // esi
  float *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm5_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float *v29; // edi
  int *v30; // esi
  char result; // al
  float v32; // xmm3_4
  char v33; // [esp+23h] [ebp-4Dh]
  float out_closest_hit_fraction; // [esp+24h] [ebp-4Ch] BYREF
  float *v35; // [esp+28h] [ebp-48h]
  btVector3 *start; // [esp+2Ch] [ebp-44h]
  float v37; // [esp+30h] [ebp-40h]
  float v38; // [esp+34h] [ebp-3Ch]
  float v39; // [esp+38h] [ebp-38h]
  float v40; // [esp+3Ch] [ebp-34h]
  float down_stepa; // [esp+40h] [ebp-30h] BYREF
  float v42; // [esp+44h] [ebp-2Ch]
  float v43; // [esp+48h] [ebp-28h]
  int v44; // [esp+4Ch] [ebp-24h]
  btVector3 v45; // [esp+50h] [ebp-20h] BYREF
  float v46; // [esp+60h] [ebp-10h] BYREF
  float v47; // [esp+64h] [ebp-Ch]
  float v48; // [esp+68h] [ebp-8h]

  v35 = (float *)(LODWORD(down_step) + 64);
  down_stepa = *(float *)(LODWORD(down_step) + 64);
  v42 = *(float *)(LODWORD(down_step) + 68);
  v43 = *(float *)(LODWORD(down_step) + 72);
  v44 = *(_DWORD *)(LODWORD(down_step) + 76);
  out_closest_hit_fraction = s_bm_current_air_resistance;
  start = (btVector3 *)(LODWORD(down_step) + 512);
  v33 = vostok::physics::character_controller_step_down_tester::convex_sweep_test(
          (vostok::physics::character_controller_step_down_tester *)&down_stepa,
          (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type>::cache_predicate)&v45,
          (const stlp_std::random_access_iterator_tag *)(LODWORD(down_step) + 80),
          (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)(LODWORD(down_step) + 512),
          &down_stepa,
          current_step_offset,
          hit_normal,
          time_hit_fraction,
          &out_closest_hit_fraction);
  if ( v33 )
  {
    v37 = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0] * current_step_offset;
    v38 = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1] * current_step_offset;
    v39 = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2] * current_step_offset;
    v40 = s_bm_current_air_resistance - out_closest_hit_fraction;
    v45.mVec128.m128_f32[0] = (float)((float)(s_bm_current_air_resistance - out_closest_hit_fraction) * down_stepa)
                            + (float)((float)((float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]
                                                    * current_step_offset)
                                            + down_stepa)
                                    * out_closest_hit_fraction);
    v45.mVec128.m128_f32[1] = (float)(v42 * (float)(s_bm_current_air_resistance - out_closest_hit_fraction))
                            + (float)((float)(v42
                                            + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]
                                                    * current_step_offset))
                                    * out_closest_hit_fraction);
    v45.mVec128.m128_f32[2] = (float)(v43 * (float)(s_bm_current_air_resistance - out_closest_hit_fraction))
                            + (float)((float)(v43
                                            + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]
                                                    * current_step_offset))
                                    * out_closest_hit_fraction);
    vostok::physics::capsule_center_to_bottom_position(
      &v45,
      (const btCapsuleShape *)(LODWORD(down_step) + 416),
      (int)&v46);
    v11 = horz_move_vector_len2[1];
    v12 = (float)((float)((float)(v48 - horz_move_vector_len2[2]) * (float)(v48 - horz_move_vector_len2[2]))
                + (float)((float)(v47 - v11) * (float)(v47 - v11)))
        + (float)((float)(v46 - *horz_move_vector_len2) * (float)(v46 - *horz_move_vector_len2));
    v13 = v47 > v11 && v12 > *(float *)&position_after_step_up;
    if ( !s_cc_prevent_slope_acceleration_value || !v13 )
    {
      v17 = out_closest_hit_fraction;
      v24 = v35;
      v25 = v42 * v40;
      v26 = (float)(v38 + v42) * out_closest_hit_fraction;
      v27 = v43 * v40;
      v28 = (float)(v39 + v43) * out_closest_hit_fraction;
      *v35 = (float)(v40 * down_stepa) + (float)((float)(v37 + down_stepa) * out_closest_hit_fraction);
      v16 = current_step_offset;
      v24[1] = v25 + v26;
      v24[2] = v27 + v28;
      goto LABEL_14;
    }
    v14 = fsqrt(*(float *)&position_after_step_up / v12);
    v45.mVec128.m128_f32[0] = (float)(hit_point->mVec128.m128_f32[0] * (float)(s_bm_current_air_resistance - v14))
                            + (float)(down_stepa * v14);
    v45.mVec128.m128_f32[1] = (float)(hit_point->mVec128.m128_f32[1] * (float)(s_bm_current_air_resistance - v14))
                            + (float)(v42 * v14);
    v45.mVec128.m128_f32[2] = (float)(hit_point->mVec128.m128_f32[2] * (float)(s_bm_current_air_resistance - v14))
                            + (float)(v43 * v14);
    out_closest_hit_fraction = s_bm_current_air_resistance;
    v15 = vostok::physics::character_controller_step_down_tester::convex_sweep_test(
            v10,
            (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type>::cache_predicate)&v45,
            (const stlp_std::random_access_iterator_tag *)(LODWORD(down_step) + 416),
            (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)start,
            &v45,
            current_step_offset,
            hit_normal,
            time_hit_fraction,
            &out_closest_hit_fraction);
    v16 = current_step_offset;
    v17 = out_closest_hit_fraction;
    v33 = v15;
    v18 = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1] * current_step_offset;
    v19 = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2] * current_step_offset;
    if ( v15 )
    {
      v20 = v35;
      v48 = v19 + v45.mVec128.m128_f32[2];
      v21 = (float)(v45.mVec128.m128_f32[1] * (float)(s_bm_current_air_resistance - out_closest_hit_fraction))
          + (float)((float)(v18 + v45.mVec128.m128_f32[1]) * out_closest_hit_fraction);
      v22 = (float)(v45.mVec128.m128_f32[2] * (float)(s_bm_current_air_resistance - out_closest_hit_fraction))
          + (float)((float)(v19 + v45.mVec128.m128_f32[2]) * out_closest_hit_fraction);
      *v35 = (float)((float)(s_bm_current_air_resistance - out_closest_hit_fraction) * v45.mVec128.m128_f32[0])
           + (float)((float)((float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]
                                   * current_step_offset)
                           + v45.mVec128.m128_f32[0])
                   * out_closest_hit_fraction);
      v20[1] = v21;
      v20[2] = v22;
      goto LABEL_14;
    }
    down_stepa = (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]
                       * current_step_offset)
               + v45.mVec128.m128_f32[0];
    v42 = v18 + v45.mVec128.m128_f32[1];
    v43 = v19 + v45.mVec128.m128_f32[2];
    v44 = 0;
    p_down_stepa = (btVector3 *)&down_stepa;
  }
  else
  {
    v16 = current_step_offset;
    v17 = out_closest_hit_fraction;
    v45.mVec128.m128_f32[0] = (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]
                                    * current_step_offset)
                            + down_stepa;
    v45.mVec128.m128_f32[1] = (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]
                                    * current_step_offset)
                            + v42;
    v45.mVec128.m128_f32[2] = (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]
                                    * current_step_offset)
                            + v43;
    v45.mVec128.m128_i32[3] = 0;
    p_down_stepa = &v45;
  }
  v29 = v35;
  *v35 = p_down_stepa->mVec128.m128_f32[0];
  v30 = &p_down_stepa->mVec128.m128_i32[1];
  *(_DWORD *)++v29 = *v30++;
  *(_DWORD *)++v29 = *v30;
  *((_DWORD *)v29 + 1) = v30[1];
LABEL_14:
  result = v33;
  if ( v33 )
  {
    if ( (float)(v17 - COERCE_FLOAT(COERCE_UNSIGNED_INT(pre_step_bottom_pos / v16) ^ _mask__NegFloat_)) <= 0.001 )
      v32 = s_bm_current_air_resistance;
    else
      v32 = (float)((float)(v17 * v16) - COERCE_FLOAT(LODWORD(pre_step_bottom_pos) ^ _mask__NegFloat_))
          / (float)(v16 - COERCE_FLOAT(LODWORD(pre_step_bottom_pos) ^ _mask__NegFloat_));
    *a10 = v32;
  }
  return result;
}
