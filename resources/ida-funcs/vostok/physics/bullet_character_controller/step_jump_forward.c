void __thiscall vostok::physics::bullet_character_controller::step_jump_forward(
        vostok::physics::bullet_character_controller *this,
        btVector3 *move_vector)
{
  btVector3 *p_m_current_pos; // ebx
  float v3; // xmm3_4
  float v4; // xmm6_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm7_4
  int v9; // eax
  float v10; // xmm3_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  btVector3 *wall_slide_vector; // eax
  btVector3 *v16; // edx
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int *p_out_hit_point_world; // esi
  float v26; // xmm0_4
  stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type> *m_end; // xmm1_4
  int *v28; // esi
  vostok::physics::character_controller_jump_tester *v29; // [esp-10h] [ebp-74h]
  float v30; // [esp+8h] [ebp-5Ch] BYREF
  float v31; // [esp+Ch] [ebp-58h]
  btVector3 *start; // [esp+10h] [ebp-54h]
  btVector3 v33; // [esp+14h] [ebp-50h] BYREF
  vostok::physics::character_controller_jump_tester out_hit_point_world; // [esp+24h] [ebp-40h] BYREF
  int v35; // [esp+48h] [ebp-1Ch]
  int v36; // [esp+4Ch] [ebp-18h]
  int v37; // [esp+50h] [ebp-14h]
  btVector3 out_hit_normal_world; // [esp+54h] [ebp-10h] BYREF

  p_m_current_pos = &this->m_current_pos;
  *(float *)&out_hit_point_world.m_cache.m_buffer.m_buff = move_vector->mVec128.m128_f32[0]
                                                         + this->m_current_pos.mVec128.m128_f32[0];
  *(float *)&out_hit_point_world.m_cache.m_buffer.m_end = this->m_current_pos.mVec128.m128_f32[1]
                                                        + move_vector->mVec128.m128_f32[1];
  *(_QWORD *)&out_hit_point_world.m_cache.m_buffer.m_first = COERCE_UNSIGNED_INT(
                                                               this->m_current_pos.mVec128.m128_f32[2]
                                                             + move_vector->mVec128.m128_f32[2]);
  v30 = s_bm_current_air_resistance;
  start = (btVector3 *)&this->m_jump_horizontal_tester;
  if ( !vostok::physics::character_controller_jump_tester::convex_sweep_test(
          &out_hit_point_world,
          (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)&this->m_jump_horizontal_tester,
          &this->m_current_pos,
          (btVector3 *)&out_hit_point_world,
          &out_hit_normal_world,
          (btVector3 *)&out_hit_point_world.m_cache.m_buffer.m_size,
          &v30) )
  {
    p_out_hit_point_world = (int *)&out_hit_point_world;
    goto LABEL_19;
  }
  v3 = (float)((float)(*(float *)&out_hit_point_world.m_cache.m_buffer.m_alloc.stlp_std::__stlport_class<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type> > >
                     * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
             + (float)(*(float *)&out_hit_point_world.m_shape
                     * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
     + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]
             * *(float *)&out_hit_point_world.m_cache.m_buffer.m_size);
  v4 = *(float *)&out_hit_point_world.m_cache.m_buffer.m_size
     - (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0] * v3);
  v5 = *(float *)&out_hit_point_world.m_cache.m_buffer.m_alloc.stlp_std::__stlport_class<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type> > >
     - (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1] * v3);
  v6 = *(float *)&out_hit_point_world.m_shape
     - (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2] * v3);
  v7 = 0.0;
  LODWORD(v8) = LODWORD(v6) & _mask__AbsFloat_;
  v33.mVec128.m128_i32[3] = 0;
  out_hit_point_world.m_world = (btCollisionWorld *)(LODWORD(v4) & _mask__AbsFloat_);
  v35 = LODWORD(v5) & _mask__AbsFloat_;
  v36 = LODWORD(v6) & _mask__AbsFloat_;
  v37 = 0;
  if ( COERCE_FLOAT(LODWORD(v5) & _mask__AbsFloat_) <= COERCE_FLOAT(LODWORD(v4) & _mask__AbsFloat_) )
  {
    if ( v8 <= COERCE_FLOAT(LODWORD(v4) & _mask__AbsFloat_) )
    {
      v9 = 0;
      goto LABEL_8;
    }
    goto LABEL_6;
  }
  if ( v8 > COERCE_FLOAT(LODWORD(v5) & _mask__AbsFloat_) )
  {
LABEL_6:
    v9 = 2;
    goto LABEL_8;
  }
  v9 = 1;
LABEL_8:
  v10 = *((float *)&out_hit_point_world.m_world + v9);
  if ( v10 <= 0.0 )
  {
    v33.mVec128.m128_f32[0] = s_bm_current_air_resistance;
    v33.mVec128.m128_u64[1] = 0;
  }
  else
  {
    v11 = v6 * (float)(s_bm_current_air_resistance / v10);
    v12 = v5 * (float)(s_bm_current_air_resistance / v10);
    v13 = (float)(s_bm_current_air_resistance / v10) * v4;
    v14 = s_bm_current_air_resistance / fsqrt((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13));
    v33.mVec128.m128_f32[0] = v14 * v13;
    v7 = v12 * v14;
    v33.mVec128.m128_f32[2] = v11 * v14;
  }
  v33.mVec128.m128_f32[1] = v7;
  out_hit_point_world.m_cache.m_buffer.m_size = v33.mVec128.m128_i32[0];
  *(_QWORD *)&out_hit_point_world.m_cache.m_buffer.m_alloc.stlp_std::__stlport_class<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type> > > = __PAIR64__(v33.mVec128.m128_u32[2], LODWORD(v7));
  out_hit_point_world.m_object = (btCollisionObject *)v33.mVec128.m128_i32[3];
  if ( !s_cc_wall_slide )
  {
    v20 = v30;
    v26 = s_bm_current_air_resistance - v30;
    m_end = out_hit_point_world.m_cache.m_buffer.m_end;
    p_m_current_pos->mVec128.m128_f32[0] = (float)(p_m_current_pos->mVec128.m128_f32[0]
                                                 * (float)(s_bm_current_air_resistance - v30))
                                         + (float)(*(float *)&out_hit_point_world.m_cache.m_buffer.m_buff * v30);
    p_m_current_pos->mVec128.m128_f32[1] = (float)(p_m_current_pos->mVec128.m128_f32[1] * v26)
                                         + (float)(*(float *)&m_end * v20);
    v23 = p_m_current_pos->mVec128.m128_f32[2] * v26;
    v24 = *(float *)&out_hit_point_world.m_cache.m_buffer.m_first;
    goto LABEL_17;
  }
  wall_slide_vector = vostok::physics::get_wall_slide_vector(
                        move_vector,
                        (const btVector3 *)&out_hit_point_world.m_cache.m_buffer.m_size,
                        (btVector3 *)&out_hit_point_world.m_world);
  *v16 = (btVector3)wall_slide_vector->mVec128;
  v17 = v16->mVec128.m128_f32[2];
  v18 = v16->mVec128.m128_f32[1];
  v19 = v16->mVec128.m128_f32[0];
  v31 = fabs((float)((float)(v17 * v17) + (float)(v18 * v18)) + (float)(v19 * v19));
  if ( v31 < 0.0000099999997 )
    return;
  v33.mVec128.m128_f32[0] = p_m_current_pos->mVec128.m128_f32[0] + v19;
  v33.mVec128.m128_f32[1] = p_m_current_pos->mVec128.m128_f32[1] + v18;
  v33.mVec128.m128_f32[2] = p_m_current_pos->mVec128.m128_f32[2] + v17;
  v33.mVec128.m128_i32[3] = 0;
  if ( vostok::physics::character_controller_jump_tester::convex_sweep_test(
         v29,
         (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)start,
         p_m_current_pos,
         &v33,
         &out_hit_normal_world,
         (btVector3 *)&out_hit_point_world.m_cache.m_buffer.m_size,
         &v30) )
  {
    v20 = v30;
    v21 = s_bm_current_air_resistance - v30;
    v22 = v33.mVec128.m128_f32[1];
    p_m_current_pos->mVec128.m128_f32[0] = (float)(p_m_current_pos->mVec128.m128_f32[0]
                                                 * (float)(s_bm_current_air_resistance - v30))
                                         + (float)(v33.mVec128.m128_f32[0] * v30);
    p_m_current_pos->mVec128.m128_f32[1] = (float)(p_m_current_pos->mVec128.m128_f32[1] * v21) + (float)(v22 * v20);
    v23 = p_m_current_pos->mVec128.m128_f32[2] * v21;
    v24 = v33.mVec128.m128_f32[2];
LABEL_17:
    p_m_current_pos->mVec128.m128_f32[2] = v23 + (float)(v24 * v20);
    return;
  }
  p_out_hit_point_world = (int *)&v33;
LABEL_19:
  p_m_current_pos->mVec128.m128_i32[0] = *p_out_hit_point_world;
  v28 = p_out_hit_point_world + 1;
  p_m_current_pos->mVec128.m128_i32[1] = *v28++;
  p_m_current_pos->mVec128.m128_i32[2] = *v28;
  p_m_current_pos->mVec128.m128_i32[3] = v28[1];
}
