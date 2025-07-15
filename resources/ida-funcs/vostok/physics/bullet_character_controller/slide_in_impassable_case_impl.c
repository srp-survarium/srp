bool __userpurge vostok::physics::bullet_character_controller::slide_in_impassable_case_impl@<al>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        const btVector3 *a2@<edi>,
        const btVector3 *a3@<esi>,
        const btVector3 *move_vector,
        const btVector3 *position_after_step_up,
        btVector3 *pre_step_bottom_pos,
        const btVector3 *down_step,
        float current_step_offset,
        btVector3 *in_out_normal,
        btVector3 *hit_fraction,
        float *a11)
{
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  bool result; // al
  float v17; // xmm4_4
  float v18; // xmm6_4
  float v19; // xmm5_4
  const btVector3 *v20; // edi
  float v21; // xmm1_4
  float v22; // ecx
  bool v23; // al
  char v24; // al
  float v25; // xmm1_4
  float v26; // xmm2_4
  btVector3 *v27; // eax
  float v28; // xmm3_4
  float v29; // xmm0_4
  vostok::physics::bullet_character_controller *v30; // ecx
  bool v31; // al
  float v33; // [esp+3Ch] [ebp-24h]
  btVector3 out_hit_normal_world; // [esp+40h] [ebp-20h] BYREF
  btVector3 out_hit_point_world; // [esp+50h] [ebp-10h] BYREF

  v11 = (float)((float)(hit_fraction->mVec128.m128_f32[0]
                      * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0])
              + (float)(hit_fraction->mVec128.m128_f32[2]
                      * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
      + (float)(hit_fraction->mVec128.m128_f32[1]
              * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]);
  v12 = hit_fraction->mVec128.m128_f32[1]
      - (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1] * v11);
  v13 = hit_fraction->mVec128.m128_f32[2]
      - (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2] * v11);
  v14 = hit_fraction->mVec128.m128_f32[0]
      - (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0] * v11);
  v15 = s_bm_current_air_resistance / fsqrt((float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v14 * v14));
  out_hit_point_world.mVec128.m128_f32[0] = v14 * v15;
  out_hit_point_world.mVec128.m128_f32[1] = v12 * v15;
  out_hit_point_world.mVec128.m128_f32[2] = v13 * v15;
  out_hit_point_world.mVec128.m128_i32[3] = 0;
  vostok::physics::get_wall_slide_vector(position_after_step_up, &out_hit_point_world, &out_hit_normal_world);
  v33 = (float)((float)(out_hit_normal_world.mVec128.m128_f32[0] * out_hit_normal_world.mVec128.m128_f32[0])
              + (float)(out_hit_normal_world.mVec128.m128_f32[1] * out_hit_normal_world.mVec128.m128_f32[1]))
      + (float)(out_hit_normal_world.mVec128.m128_f32[2] * out_hit_normal_world.mVec128.m128_f32[2]);
  if ( fabs(v33) < 0.0000099999997 )
    return 0;
  v17 = pre_step_bottom_pos->mVec128.m128_f32[0];
  v18 = pre_step_bottom_pos->mVec128.m128_f32[2];
  v19 = pre_step_bottom_pos->mVec128.m128_f32[1];
  v20 = move_vector;
  v21 = pre_step_bottom_pos->mVec128.m128_f32[0];
  out_hit_point_world.mVec128.m128_f32[2] = v18 + out_hit_normal_world.mVec128.m128_f32[2];
  out_hit_point_world.mVec128.m128_f32[0] = v21 + out_hit_normal_world.mVec128.m128_f32[0];
  out_hit_point_world.mVec128.m128_f32[1] = v19 + out_hit_normal_world.mVec128.m128_f32[1];
  v22 = fabs(
          (float)((float)((float)(out_hit_point_world.mVec128.m128_f32[2] - v18)
                        * (float)(out_hit_point_world.mVec128.m128_f32[2] - v18))
                + (float)((float)((float)(v19 + out_hit_normal_world.mVec128.m128_f32[1]) - v19)
                        * (float)((float)(v19 + out_hit_normal_world.mVec128.m128_f32[1]) - v19)))
        + (float)((float)((float)(v21 + out_hit_normal_world.mVec128.m128_f32[0]) - v17)
                * (float)((float)(v21 + out_hit_normal_world.mVec128.m128_f32[0]) - v17)));
  out_hit_point_world.mVec128.m128_i32[3] = 0;
  if ( v22 < 0.0000099999997 )
  {
    move_vector[4] = (const btVector3)pre_step_bottom_pos->mVec128;
    return 0;
  }
  v23 = s_cc_crouch_move_complex_test_value;
  if ( !move_vector[31].mVec128.m128_i8[3] )
    v23 = s_cc_stand_move_complex_test_value;
  if ( v23 )
    v24 = vostok::physics::character_controller_move_step_tester::convex_sweep_test(
            (vostok::physics::character_controller_move_step_tester *)LODWORD(v22),
            (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>::cache_predicate)move_vector,
            (const stlp_std::random_access_iterator_tag *)pre_step_bottom_pos,
            (btVector3 *)&move_vector[36],
            pre_step_bottom_pos,
            &out_hit_point_world,
            &out_hit_normal_world,
            hit_fraction->mVec128.m128_f32,
            a11);
  else
    v24 = vostok::physics::character_controller_capsule_move_step_tester::convex_sweep_test(
            (vostok::physics::character_controller_capsule_move_step_tester *)LODWORD(v22),
            (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>::cache_predicate)move_vector,
            (const stlp_std::random_access_iterator_tag *)pre_step_bottom_pos,
            (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *)&move_vector[49],
            pre_step_bottom_pos,
            &out_hit_point_world,
            &out_hit_normal_world,
            hit_fraction->mVec128.m128_f32,
            a11);
  if ( v24 )
  {
    v25 = *a11;
    v26 = s_bm_current_air_resistance - *a11;
    v27 = pre_step_bottom_pos;
    v28 = pre_step_bottom_pos->mVec128.m128_f32[1];
    move_vector[4].mVec128.m128_f32[0] = (float)(out_hit_point_world.mVec128.m128_f32[0] * *a11)
                                       + (float)(pre_step_bottom_pos->mVec128.m128_f32[0] * v26);
    v29 = out_hit_point_world.mVec128.m128_f32[2];
    move_vector[4].mVec128.m128_f32[1] = (float)(v28 * v26) + (float)(out_hit_point_world.mVec128.m128_f32[1] * v25);
    move_vector[4].mVec128.m128_f32[2] = (float)(pre_step_bottom_pos->mVec128.m128_f32[2] * v26) + (float)(v29 * v25);
  }
  else
  {
    v27 = pre_step_bottom_pos;
    move_vector[4] = (const btVector3)out_hit_point_world.mVec128;
    v20 = move_vector;
  }
  result = 1;
  if ( vostok::physics::bullet_character_controller::step_down_sweep_test_impl(
         (vostok::physics::bullet_character_controller *)&out_hit_normal_world,
         *(const float *)&v20,
         current_step_offset,
         *(float *)&in_out_normal,
         down_step->mVec128.m128_f32,
         (const btVector3 *)LODWORD(v33),
         v27,
         &out_hit_normal_world,
         hit_fraction,
         a11) )
  {
    v31 = vostok::physics::bullet_character_controller::ms_max_slope_normal_dot > (float)((float)((float)(hit_fraction->mVec128.m128_f32[0] * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0])
                                                                                                + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1] * hit_fraction->mVec128.m128_f32[1]))
                                                                                        + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]
                                                                                                * hit_fraction->mVec128.m128_f32[2]))
       && vostok::physics::bullet_character_controller::impassable_slope(v30, (int)v20, down_step, a2, a3);
    if ( v31
      || !vostok::physics::bullet_character_controller::can_straighten(
            v30,
            v20,
            v20 + 4,
            in_out_normal,
            &out_hit_point_world) )
    {
      return 0;
    }
  }
  return result;
}
