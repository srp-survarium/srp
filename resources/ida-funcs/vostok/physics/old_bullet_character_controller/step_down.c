void __thiscall vostok::physics::old_bullet_character_controller::step_down(
        vostok::physics::old_bullet_character_controller *this,
        vostok::physics::old_bullet_character_controller *dt,
        float change_size_only,
        const btVector3 *pos_up_correction,
        bool was_on_ground,
        const btVector3 *pre_step_position,
        float walk_vector_length_squared)
{
  btMatrix3x3 *v7; // ecx
  float v8; // xmm0_4
  float *m128_f32; // ebx
  float v10; // xmm0_4
  btTransform *v11; // ecx
  vostok::physics::old_bullet_character_controller *v12; // edi
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  __m128 *p_mVec128; // edi
  float v29; // [esp+20h] [ebp-C4h] BYREF
  unsigned __int64 v30; // [esp+24h] [ebp-C0h]
  float v31; // [esp+2Ch] [ebp-B8h]
  int v32; // [esp+30h] [ebp-B4h]
  float v33; // [esp+40h] [ebp-A4h]
  btVector3 out_hit_normal_world; // [esp+44h] [ebp-A0h] BYREF
  btTransform up_vector; // [esp+54h] [ebp-90h] BYREF
  btTransform finish; // [esp+94h] [ebp-50h] BYREF
  float out_closest_hit_fraction[4]; // [esp+D4h] [ebp-10h] BYREF

  btMatrix3x3::setIdentity((btMatrix3x3 *)this, (int)&finish);
  v8 = dt->m_fall_and_slide_velocity.mVec128.m128_f32[1];
  m128_f32 = dt->m_current_pos.mVec128.m128_f32;
  finish.m_origin = dt->m_current_pos;
  if ( v8 >= 0.0 )
    v29 = 0.0;
  else
    LODWORD(v29) = COERCE_UNSIGNED_INT(v8 * change_size_only) ^ _mask__NegFloat_;
  if ( (float)(s_cc_max_allowed_penetration_value * 2.0) > v29 && was_on_ground )
    v29 = s_cc_max_allowed_penetration_value * 2.0;
  btMatrix3x3::setIdentity(v7, (int)&up_vector);
  v10 = (float)(dt->m_current_step_offset * 2.0) + v29;
  *(float *)&v30 = *m128_f32
                 - (float)(vostok::physics::old_bullet_character_controller::m_up_vector.mVec128.m128_f32[0] * v10);
  *((float *)&v30 + 1) = dt->m_current_pos.mVec128.m128_f32[1]
                       - (float)(vostok::physics::old_bullet_character_controller::m_up_vector.mVec128.m128_f32[1] * v10);
  v31 = dt->m_current_pos.mVec128.m128_f32[2]
      - (float)(vostok::physics::old_bullet_character_controller::m_up_vector.mVec128.m128_f32[2] * v10);
  v32 = 0;
  up_vector.m_origin.mVec128.m128_u64[0] = v30;
  up_vector.m_origin.mVec128.m128_u64[1] = LODWORD(v31);
  v33 = 0.0;
  if ( vostok::physics::old_bullet_character_controller::convex_sweep_test(
         (vostok::physics::old_bullet_character_controller *)&finish,
         (const btTransform *)dt,
         &finish,
         (btCollisionWorld::ConvexResultCallback *)&up_vector,
         (unsigned __int64 *)&vostok::physics::old_bullet_character_controller::m_up_vector,
         SLODWORD(vostok::physics::bullet_character_controller::ms_max_slope_normal_dot),
         COERCE_BTVECTOR3_(0.0),
         &out_hit_normal_world,
         out_closest_hit_fraction,
         &v29) )
  {
    v12 = dt;
    btTransform::inverse(v11, (int)&dt->m_ghost_object.m_worldTransform, &up_vector);
    if ( s_step_height >= (float)((float)((float)((float)((float)((float)((float)(up_vector.m_basis.m_el[1].mVec128.m128_f32[0]
                                                                                * out_hit_normal_world.mVec128.m128_f32[0])
                                                                        + (float)(up_vector.m_basis.m_el[1].mVec128.m128_f32[1]
                                                                                * out_hit_normal_world.mVec128.m128_f32[1]))
                                                                + (float)(up_vector.m_basis.m_el[1].mVec128.m128_f32[2]
                                                                        * out_hit_normal_world.mVec128.m128_f32[2]))
                                                        + up_vector.m_origin.mVec128.m128_f32[1])
                                                * vostok::physics::old_bullet_character_controller::m_up_vector.mVec128.m128_f32[1])
                                        + (float)((float)((float)((float)((float)(up_vector.m_basis.m_el[2].mVec128.m128_f32[0]
                                                                                * out_hit_normal_world.mVec128.m128_f32[0])
                                                                        + (float)(up_vector.m_basis.m_el[2].mVec128.m128_f32[1]
                                                                                * out_hit_normal_world.mVec128.m128_f32[1]))
                                                                + (float)(up_vector.m_basis.m_el[2].mVec128.m128_f32[2]
                                                                        * out_hit_normal_world.mVec128.m128_f32[2]))
                                                        + up_vector.m_origin.mVec128.m128_f32[2])
                                                * vostok::physics::old_bullet_character_controller::m_up_vector.mVec128.m128_f32[2]))
                                + (float)((float)((float)((float)((float)(up_vector.m_basis.m_el[0].mVec128.m128_f32[0]
                                                                        * out_hit_normal_world.mVec128.m128_f32[0])
                                                                + (float)(up_vector.m_basis.m_el[0].mVec128.m128_f32[1]
                                                                        * out_hit_normal_world.mVec128.m128_f32[1]))
                                                        + (float)(up_vector.m_basis.m_el[0].mVec128.m128_f32[2]
                                                                * out_hit_normal_world.mVec128.m128_f32[2]))
                                                + up_vector.m_origin.mVec128.m128_f32[0])
                                        * vostok::physics::old_bullet_character_controller::m_up_vector.mVec128.m128_f32[0])) )
    {
      v13 = v29;
      v14 = s_bm_current_air_resistance - v29;
      v15 = *((float *)&v30 + 1);
      *m128_f32 = (float)(finish.m_origin.mVec128.m128_f32[0] * (float)(s_bm_current_air_resistance - v29))
                + (float)(*(float *)&v30 * v29);
      v16 = (float)(finish.m_origin.mVec128.m128_f32[1] * v14) + (float)(v15 * v13);
      v17 = finish.m_origin.mVec128.m128_f32[2] * v14;
      v18 = v31;
      dt->m_current_pos.mVec128.m128_f32[1] = v16;
      dt->m_current_pos.mVec128.m128_f32[2] = v17 + (float)(v18 * v13);
      v33 = dt->m_fall_and_slide_velocity.mVec128.m128_f32[1];
      dt->m_fall_and_slide_velocity.mVec128.m128_i32[0] = 0;
      dt->m_fall_and_slide_velocity.mVec128.m128_i32[1] = 0;
      dt->m_fall_and_slide_velocity.mVec128.m128_i32[2] = 0;
      dt->m_fall_and_slide_velocity.mVec128.m128_i32[3] = 0;
    }
  }
  else
  {
    *(_DWORD *)m128_f32 = v30;
    dt->m_current_pos.mVec128.m128_i32[1] = HIDWORD(v30);
    dt->m_current_pos.mVec128.m128_f32[2] = v31;
    dt->m_current_pos.mVec128.m128_i32[3] = v32;
    v12 = dt;
  }
  *m128_f32 = *m128_f32 + pos_up_correction->mVec128.m128_f32[0];
  dt->m_current_pos.mVec128.m128_f32[1] = pos_up_correction->mVec128.m128_f32[1] + dt->m_current_pos.mVec128.m128_f32[1];
  dt->m_current_pos.mVec128.m128_f32[2] = pos_up_correction->mVec128.m128_f32[2] + dt->m_current_pos.mVec128.m128_f32[2];
  vostok::physics::old_bullet_character_controller::setup_crouch_state(v12->m_in_crouch, v12, 1);
  v19 = pre_step_position->mVec128.m128_f32[1];
  v20 = pre_step_position->mVec128.m128_f32[0];
  v21 = pre_step_position->mVec128.m128_f32[2];
  if ( v12->m_current_pos.mVec128.m128_f32[1] > v19
    && (float)((float)((float)((float)(m128_f32[2] - v21) * (float)(m128_f32[2] - v21))
                     + (float)((float)(m128_f32[1] - v19) * (float)(m128_f32[1] - v19)))
             + (float)((float)(*m128_f32 - pre_step_position->mVec128.m128_f32[0])
                     * (float)(*m128_f32 - pre_step_position->mVec128.m128_f32[0]))) > walk_vector_length_squared )
  {
    v22 = dt->m_current_pos.mVec128.m128_f32[2];
    v23 = *m128_f32;
    v29 = fsqrt(walk_vector_length_squared);
    v24 = dt->m_current_pos.mVec128.m128_f32[1] - v19;
    v25 = v22 - v21;
    v26 = v23 - v20;
    v27 = s_bm_current_air_resistance / fsqrt((float)((float)(v25 * v25) + (float)(v24 * v24)) + (float)(v26 * v26));
    *((float *)&v30 + 1) = v19 + (float)((float)(v24 * v27) * v29);
    v32 = 0;
    *(float *)&v30 = v20 + (float)((float)(v27 * v26) * v29);
    v31 = v21 + (float)((float)(v25 * v27) * v29);
    *(_DWORD *)m128_f32 = v30;
    dt->m_current_pos.mVec128.m128_i32[1] = HIDWORD(v30);
    dt->m_current_pos.mVec128.m128_f32[2] = v31;
    dt->m_current_pos.mVec128.m128_i32[3] = v32;
    v12 = dt;
  }
  vostok::physics::round_up(m128_f32);
  vostok::physics::round_up(&v12->m_current_pos.mVec128.m128_f32[1]);
  vostok::physics::round_up(&v12->m_current_pos.mVec128.m128_f32[2]);
  p_mVec128 = &v12->m_ghost_object.m_worldTransform.m_origin.mVec128;
  p_mVec128->m128_f32[0] = *m128_f32;
  p_mVec128 = (__m128 *)((char *)p_mVec128 + 4);
  p_mVec128->m128_i32[0] = dt->m_current_pos.mVec128.m128_i32[1];
  p_mVec128 = (__m128 *)((char *)p_mVec128 + 4);
  p_mVec128->m128_i32[0] = dt->m_current_pos.mVec128.m128_i32[2];
  p_mVec128->m128_i32[1] = dt->m_current_pos.mVec128.m128_i32[3];
  if ( !was_on_ground
    && (dt->m_landing_callback.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0
    && dt->m_harmless_fall_speed > v33 )
  {
    boost::function1<void,float>::operator()(
      (boost::function1<void,float> *)dt,
      &dt->m_landing_callback.vtable,
      COERCE_FLOAT(LODWORD(v33) ^ _mask__NegFloat_));
  }
}
