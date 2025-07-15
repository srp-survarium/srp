void __thiscall vostok::physics::bullet_character_controller::step_forward_impl(
        vostok::physics::bullet_character_controller *this,
        const btVector3 *original_move_direction,
        const btVector3 *move_vector,
        unsigned int iteration_number)
{
  vostok::physics::bullet_character_controller *v4; // esi
  btVector3 *p_m_current_pos; // ebx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  bool v10; // al
  char v11; // al
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  btVector3 *wall_slide_vector; // eax
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm5_4
  float v27; // xmm7_4
  float v28; // xmm5_4
  float v29; // xmm0_4
  float v30[2]; // [esp+14h] [ebp-4Ch] BYREF
  float v31; // [esp+1Ch] [ebp-44h]
  float v32; // [esp+20h] [ebp-40h]
  float v33; // [esp+24h] [ebp-3Ch]
  float v34; // [esp+28h] [ebp-38h]
  float v35; // [esp+2Ch] [ebp-34h]
  btVector3 out_hit_point_world; // [esp+30h] [ebp-30h] BYREF
  btVector3 out_closest_hit_fraction; // [esp+40h] [ebp-20h] BYREF
  btVector3 out_hit_normal_world; // [esp+50h] [ebp-10h] BYREF

  v4 = this;
  v31 = *(float *)&this;
  p_m_current_pos = &this->m_current_pos;
  v6 = this->m_current_pos.mVec128.m128_f32[1] + move_vector->mVec128.m128_f32[1];
  v7 = this->m_current_pos.mVec128.m128_f32[0] + move_vector->mVec128.m128_f32[0];
  out_hit_point_world.mVec128.m128_f32[2] = this->m_current_pos.mVec128.m128_f32[2] + move_vector->mVec128.m128_f32[2];
  v8 = out_hit_point_world.mVec128.m128_f32[2] - this->m_current_pos.mVec128.m128_f32[2];
  out_hit_point_world.mVec128.m128_i32[3] = 0;
  out_hit_point_world.mVec128.m128_f32[1] = v6;
  v9 = v6 - this->m_current_pos.mVec128.m128_f32[1];
  out_hit_point_world.mVec128.m128_f32[0] = v7;
  v30[0] = fabs(
             (float)((float)(v8 * v8) + (float)(v9 * v9))
           + (float)((float)(v7 - this->m_current_pos.mVec128.m128_f32[0])
                   * (float)(v7 - this->m_current_pos.mVec128.m128_f32[0])));
  if ( v30[0] >= 0.0000099999997 )
  {
    if ( this->m_is_sprinting )
      goto LABEL_7;
    v10 = s_cc_crouch_move_complex_test_value;
    if ( !this->m_capsule_is_in_crouch )
      v10 = s_cc_stand_move_complex_test_value;
    if ( !v10 )
LABEL_7:
      v11 = vostok::physics::character_controller_capsule_move_step_tester::convex_sweep_test(
              (vostok::physics::character_controller_capsule_move_step_tester *)this,
              (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>::cache_predicate)move_vector,
              (const stlp_std::random_access_iterator_tag *)this,
              &this->m_capsule_move_step_tester.m_cache,
              &this->m_current_pos,
              &out_hit_point_world,
              &out_hit_normal_world,
              out_closest_hit_fraction.mVec128.m128_f32,
              v30);
    else
      v11 = vostok::physics::character_controller_move_step_tester::convex_sweep_test(
              (vostok::physics::character_controller_move_step_tester *)this,
              (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>::cache_predicate)move_vector,
              (const stlp_std::random_access_iterator_tag *)this,
              (btVector3 *)&this->m_move_step_tester,
              &this->m_current_pos,
              &out_hit_point_world,
              &out_hit_normal_world,
              out_closest_hit_fraction.mVec128.m128_f32,
              v30);
    if ( v11 )
    {
      v12 = v30[0];
      v13 = s_bm_current_air_resistance - v30[0];
      v14 = (float)(p_m_current_pos->mVec128.m128_f32[0] * (float)(s_bm_current_air_resistance - v30[0]))
          + (float)(out_hit_point_world.mVec128.m128_f32[0] * v30[0]);
      v33 = out_hit_point_world.mVec128.m128_f32[0] * v30[0];
      v15 = out_hit_point_world.mVec128.m128_f32[1] * v30[0];
      p_m_current_pos->mVec128.m128_f32[0] = v14;
      v16 = p_m_current_pos->mVec128.m128_f32[1];
      v34 = v15;
      v17 = (float)(v16 * v13) + v15;
      v18 = out_hit_point_world.mVec128.m128_f32[2] * v12;
      p_m_current_pos->mVec128.m128_f32[1] = v17;
      v19 = (float)(p_m_current_pos->mVec128.m128_f32[2] * v13) + v18;
      v32 = v13;
      v35 = v18;
      p_m_current_pos->mVec128.m128_f32[2] = v19;
      v30[0] = v13;
      wall_slide_vector = vostok::physics::get_wall_slide_vector(
                            move_vector,
                            &out_closest_hit_fraction,
                            &out_hit_normal_world);
      v21 = wall_slide_vector->mVec128.m128_f32[2] * v30[0];
      v22 = wall_slide_vector->mVec128.m128_f32[1] * v30[0];
      v23 = wall_slide_vector->mVec128.m128_f32[0] * v30[0];
      v24 = original_move_direction->mVec128.m128_f32[0];
      v25 = original_move_direction->mVec128.m128_f32[0] * v23;
      v26 = (float)((float)(original_move_direction->mVec128.m128_f32[1] * v22)
                  + (float)(original_move_direction->mVec128.m128_f32[2] * v21))
          + v25;
      out_hit_point_world.mVec128.m128_f32[0] = v23;
      out_hit_point_world.mVec128.m128_f32[1] = v22;
      out_hit_point_world.mVec128.m128_u64[1] = LODWORD(v21);
      if ( v26 < 0.0 )
      {
        v27 = original_move_direction->mVec128.m128_f32[2];
        v30[0] = original_move_direction->mVec128.m128_f32[1];
        v30[1] = v27;
        v28 = (float)((float)(v30[0] * v22) + (float)(v27 * v21)) + v25;
        out_closest_hit_fraction.mVec128.m128_i32[3] = 0;
        out_closest_hit_fraction.mVec128.m128_f32[0] = v23 - (float)(v24 * v28);
        out_closest_hit_fraction.mVec128.m128_f32[1] = v22 - (float)(v30[0] * v28);
        out_closest_hit_fraction.mVec128.m128_f32[2] = v21 - (float)(v27 * v28);
        out_hit_point_world.mVec128.m128_f32[0] = out_closest_hit_fraction.mVec128.m128_f32[0];
        out_hit_point_world.mVec128.m128_f32[1] = out_closest_hit_fraction.mVec128.m128_f32[1];
        out_hit_point_world.mVec128.m128_f32[2] = out_closest_hit_fraction.mVec128.m128_f32[2];
        out_hit_point_world.mVec128.m128_i32[3] = 0;
        v23 = out_closest_hit_fraction.mVec128.m128_f32[0];
        v4 = (vostok::physics::bullet_character_controller *)LODWORD(v31);
      }
      if ( !s_cc_wall_slide
        || iteration_number == 2
        || (v31 = fabs(
                    (float)((float)(out_hit_point_world.mVec128.m128_f32[2] * out_hit_point_world.mVec128.m128_f32[2])
                          + (float)(out_hit_point_world.mVec128.m128_f32[1] * out_hit_point_world.mVec128.m128_f32[1]))
                  + (float)(v23 * v23)),
            v31 < 0.0000099999997) )
      {
        v29 = v32;
        p_m_current_pos->mVec128.m128_f32[0] = (float)(v32 * p_m_current_pos->mVec128.m128_f32[0]) + v33;
        p_m_current_pos->mVec128.m128_f32[1] = (float)(p_m_current_pos->mVec128.m128_f32[1] * v29) + v34;
        p_m_current_pos->mVec128.m128_f32[2] = (float)(p_m_current_pos->mVec128.m128_f32[2] * v29) + v35;
      }
      else
      {
        vostok::physics::bullet_character_controller::step_forward_impl(
          v4,
          original_move_direction,
          &out_hit_point_world,
          iteration_number + 1);
      }
    }
    else
    {
      *p_m_current_pos = (btVector3)out_hit_point_world.mVec128;
    }
  }
}
