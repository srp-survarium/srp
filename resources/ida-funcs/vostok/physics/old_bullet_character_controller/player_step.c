void __thiscall vostok::physics::old_bullet_character_controller::player_step(
        vostok::physics::old_bullet_character_controller *this,
        vostok::physics::old_bullet_character_controller *dt,
        const btVector3 *pre_step_position,
        btVector3 *pre_step_positiona)
{
  btMatrix3x3 *v4; // ecx
  bool m_jumping; // al
  float v6; // xmm0_4
  unsigned int v7; // xmm0_4
  unsigned int v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  btVector3 *v11; // esi
  float v12; // xmm0_4
  float walk_vector_length_squared; // [esp+2Ch] [ebp-38h]
  bool was_on_ground; // [esp+30h] [ebp-34h]
  btVector3 walkMove; // [esp+34h] [ebp-30h] BYREF
  btVector3 pos_up_correction; // [esp+44h] [ebp-20h] BYREF
  btVector3 v17; // [esp+54h] [ebp-10h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF

  dt->m_has_updates = 1;
  was_on_ground = vostok::physics::old_bullet_character_controller::on_ground(this, (int)dt);
  m_jumping = dt->m_jumping;
  if ( !s_cc_old_use_fixed_time_step_value )
  {
    if ( !m_jumping )
    {
      v6 = dt->m_gravity * *(float *)&pre_step_position;
      goto LABEL_7;
    }
LABEL_5:
    dt->m_fall_and_slide_velocity.mVec128.m128_f32[1] = dt->m_walk_vector.mVec128.m128_f32[1]
                                                      / *(float *)&pre_step_position;
    goto LABEL_8;
  }
  if ( m_jumping )
    goto LABEL_5;
  v6 = dt->m_gravity * 0.050000001;
LABEL_7:
  v4 = (btMatrix3x3 *)&dt->m_fall_and_slide_velocity.m_floats[1];
  dt->m_fall_and_slide_velocity.mVec128.m128_f32[1] = dt->m_fall_and_slide_velocity.mVec128.m128_f32[1] - v6;
LABEL_8:
  memset(&pos_up_correction, 0, sizeof(pos_up_correction));
  if ( !m_jumping )
    vostok::physics::old_bullet_character_controller::step_up(dt);
  walk_vector_length_squared = 0.0;
  if ( !dt->m_walk_vector_applied )
  {
    v17.mVec128.m128_i32[3] = 0;
    if ( s_cc_old_use_fixed_time_step_value )
    {
      *(float *)&v7 = (float)(dt->m_air_control_vector.mVec128.m128_f32[1]
                            + (float)(dt->m_walk_vector.mVec128.m128_f32[1]
                                    * (float)(s_bm_current_air_resistance / *(float *)&pre_step_position)))
                    * 0.050000001;
      *(float *)&v8 = (float)(dt->m_air_control_vector.mVec128.m128_f32[2]
                            + (float)(dt->m_walk_vector.mVec128.m128_f32[2]
                                    * (float)(s_bm_current_air_resistance / *(float *)&pre_step_position)))
                    * 0.050000001;
      v17.mVec128.m128_f32[0] = (float)((float)((float)(s_bm_current_air_resistance / *(float *)&pre_step_position)
                                              * dt->m_walk_vector.mVec128.m128_f32[0])
                                      + dt->m_air_control_vector.mVec128.m128_f32[0])
                              * 0.050000001;
      *(unsigned __int64 *)((char *)v17.mVec128.m128_u64 + 4) = __PAIR64__(v8, v7);
    }
    else
    {
      v9 = dt->m_air_control_vector.mVec128.m128_f32[1] * *(float *)&pre_step_position;
      v10 = dt->m_air_control_vector.mVec128.m128_f32[2] * *(float *)&pre_step_position;
      v17.mVec128.m128_f32[0] = (float)(*(float *)&pre_step_position * dt->m_air_control_vector.mVec128.m128_f32[0])
                              + dt->m_walk_vector.mVec128.m128_f32[0];
      v17.mVec128.m128_f32[1] = dt->m_walk_vector.mVec128.m128_f32[1] + v9;
      v17.mVec128.m128_f32[2] = dt->m_walk_vector.mVec128.m128_f32[2] + v10;
    }
    walkMove.mVec128 = v17.mVec128;
    walk_vector_length_squared = (float)((float)(v17.mVec128.m128_f32[1] * v17.mVec128.m128_f32[1])
                                       + (float)(walkMove.mVec128.m128_f32[2] * walkMove.mVec128.m128_f32[2]))
                               + (float)(v17.mVec128.m128_f32[0] * v17.mVec128.m128_f32[0]);
    vostok::physics::old_bullet_character_controller::step_forward_and_strafe(
      &walkMove,
      v4,
      COERCE_FLOAT(&pos_up_correction),
      COERCE_FLOAT(&savedregs),
      dt);
    dt->m_walk_vector_applied = 1;
  }
  if ( dt->m_jumping )
  {
    vostok::physics::round_up(dt->m_current_pos.mVec128.m128_f32);
    vostok::physics::round_up(&dt->m_current_pos.mVec128.m128_f32[1]);
    vostok::physics::round_up(&dt->m_current_pos.mVec128.m128_f32[2]);
    v11 = pre_step_positiona;
  }
  else
  {
    v11 = pre_step_positiona;
    vostok::physics::old_bullet_character_controller::step_down(
      (vostok::physics::old_bullet_character_controller *)v4,
      (const btTransform *)dt,
      *(float *)&pre_step_position,
      &pos_up_correction,
      was_on_ground,
      pre_step_positiona,
      walk_vector_length_squared);
  }
  if ( s_cc_old_use_fixed_time_step_value )
  {
    v12 = s_bm_current_air_resistance - (float)(*(float *)&pre_step_position * 20.0);
    dt->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[0] = (float)(dt->m_current_pos.mVec128.m128_f32[0]
                                                                             * (float)(*(float *)&pre_step_position
                                                                                     * 20.0))
                                                                     + (float)(v11->mVec128.m128_f32[0] * v12);
    dt->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[1] = (float)(dt->m_current_pos.mVec128.m128_f32[1]
                                                                             * (float)(*(float *)&pre_step_position
                                                                                     * 20.0))
                                                                     + (float)(v11->mVec128.m128_f32[1] * v12);
    dt->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[2] = (float)(dt->m_current_pos.mVec128.m128_f32[2]
                                                                             * (float)(*(float *)&pre_step_position
                                                                                     * 20.0))
                                                                     + (float)(v11->mVec128.m128_f32[2] * v12);
  }
  else
  {
    dt->m_ghost_object.m_worldTransform.m_origin = dt->m_current_pos;
  }
}
