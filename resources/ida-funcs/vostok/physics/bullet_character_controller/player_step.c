void __thiscall vostok::physics::bullet_character_controller::player_step(
        vostok::physics::bullet_character_controller *this,
        btVector3 *dt,
        float a3)
{
  vostok::physics::bullet_character_controller *v3; // ecx
  float v4; // xmm4_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  vostok::physics::bullet_character_controller *v18; // ecx
  btVector3 *slide_acceleration; // eax
  float v20; // xmm0_4
  unsigned int v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm6_4
  float v24; // xmm3_4
  vostok::physics::bullet_character_controller *v25; // ecx
  vostok::physics::bullet_character_controller *v26; // ecx
  btVector3 *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float up_step; // [esp+28h] [ebp-6Ch] BYREF
  bool was_on_ground[4]; // [esp+2Ch] [ebp-68h]
  btVector3 *v33; // [esp+30h] [ebp-64h]
  btVector3 move_vector; // [esp+34h] [ebp-60h] BYREF
  btVector3 slide_velocity_delta; // [esp+44h] [ebp-50h] BYREF
  btVector3 v36; // [esp+54h] [ebp-40h] BYREF
  btVector3 position_after_step_up; // [esp+64h] [ebp-30h] BYREF
  btVector3 pre_step_bottom_pos; // [esp+74h] [ebp-20h] BYREF
  btVector3 v39; // [esp+84h] [ebp-10h] BYREF

  if ( dt[31].mVec128.m128_i8[1] )
  {
    if ( !dt[31].mVec128.m128_i8[3] )
      vostok::physics::bullet_character_controller::setup_crouch_state(this, (int)dt, 1);
  }
  else if ( dt[31].mVec128.m128_i8[3] && dt[31].mVec128.m128_i8[2] )
  {
    vostok::physics::bullet_character_controller::setup_crouch_state(this, (int)dt, 0);
  }
  was_on_ground[0] = vostok::physics::bullet_character_controller::on_ground(this, dt->mVec128.m128_f32);
  v36.mVec128 = dt[10].mVec128;
  dt[4] = (btVector3)dt[10].mVec128;
  v33 = dt + 10;
  vostok::physics::capsule_center_to_bottom_position(&v36, (const btCapsuleShape *)&dt[26], (int)&pre_step_bottom_pos);
  if ( dt[72].mVec128.m128_i8[12] )
  {
    v4 = s_bm_current_air_resistance / a3;
    v5 = (float)((float)((float)(dt[2].mVec128.m128_f32[1]
                               * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                       + (float)(dt[2].mVec128.m128_f32[2]
                               * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
               + (float)(dt[2].mVec128.m128_f32[0]
                       * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]))
       * (float)(s_bm_current_air_resistance / a3);
    move_vector.mVec128.m128_f32[0] = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]
                                    * v5;
    move_vector.mVec128.m128_f32[2] = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]
                                    * v5;
    move_vector.mVec128.m128_f32[1] = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]
                                    * v5;
    move_vector.mVec128.m128_i32[3] = 0;
    dt[77].mVec128.m128_f32[0] = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0] * v5;
    *(unsigned __int64 *)((char *)dt[77].mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)move_vector.mVec128.m128_u64
                                                                                     + 4);
    dt[77].mVec128.m128_i32[3] = move_vector.mVec128.m128_i32[3];
    v6 = dt[72].mVec128.m128_f32[1] * (float)(dt[3].mVec128.m128_f32[0] + (float)(dt[2].mVec128.m128_f32[0] * v4));
    v7 = dt[72].mVec128.m128_f32[1] * (float)(dt[3].mVec128.m128_f32[1] + (float)(dt[2].mVec128.m128_f32[1] * v4));
    v8 = dt[72].mVec128.m128_f32[1] * (float)(dt[3].mVec128.m128_f32[2] + (float)(dt[2].mVec128.m128_f32[2] * v4));
    v9 = (float)((float)(v7 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
               + (float)(v8 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
       + (float)(v6 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
    position_after_step_up.mVec128.m128_f32[0] = v9
                                               * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0];
    move_vector.mVec128.m128_f32[0] = v6
                                    - (float)(v9
                                            * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
    move_vector.mVec128.m128_f32[1] = v7
                                    - (float)(v9
                                            * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]);
    move_vector.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                        v8
                                      - (float)(v9
                                              * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]));
    up_step = v9;
    if ( v9 > 0.0 )
    {
      *(float *)was_on_ground = fabs(
                                  (float)((float)(v7
                                                * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                                        + (float)(v8
                                                * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
                                + (float)(v6
                                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]));
      if ( *(float *)was_on_ground >= 0.0000099999997 )
      {
        vostok::physics::bullet_character_controller::step_jump_up(v3, dt, (btVector3 *)LODWORD(up_step));
        v9 = up_step;
      }
    }
    *(float *)was_on_ground = fabs(
                                (float)((float)(move_vector.mVec128.m128_f32[0] * move_vector.mVec128.m128_f32[0])
                                      + (float)(move_vector.mVec128.m128_f32[2] * move_vector.mVec128.m128_f32[2]))
                              + (float)(move_vector.mVec128.m128_f32[1] * move_vector.mVec128.m128_f32[1]));
    if ( *(float *)was_on_ground >= 0.0000099999997 )
    {
      vostok::physics::bullet_character_controller::step_jump_forward(
        (vostok::physics::bullet_character_controller *)dt,
        &move_vector);
      v9 = up_step;
    }
    if ( v9 < 0.0 )
    {
      *(_DWORD *)was_on_ground = LODWORD(v9) & 0x7FFFFFFF;
      if ( COERCE_FLOAT(LODWORD(v9) & 0x7FFFFFFF) >= 0.0000099999997 )
        vostok::physics::bullet_character_controller::step_jump_down(v3, *(float *)&dt, (btVector3 *)LODWORD(up_step));
    }
  }
  else
  {
    v10 = dt[77].mVec128.m128_f32[2];
    v11 = dt[77].mVec128.m128_f32[0];
    v12 = dt[77].mVec128.m128_f32[1];
    v13 = (float)((float)(v11 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0])
                + (float)(v10 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
        + (float)(v12 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]);
    position_after_step_up.mVec128.m128_f32[0] = v13
                                               * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0];
    move_vector.mVec128.m128_f32[0] = v11
                                    - (float)(v13
                                            * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
    v14 = dt[2].mVec128.m128_f32[0];
    move_vector.mVec128.m128_f32[2] = v10
                                    - (float)(v13
                                            * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]);
    v15 = dt[2].mVec128.m128_f32[2];
    move_vector.mVec128.m128_f32[1] = v12
                                    - (float)(v13
                                            * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]);
    v16 = dt[2].mVec128.m128_f32[1];
    v17 = (float)((float)(v14 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0])
                + (float)(v15 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
        + (float)(v16 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]);
    slide_velocity_delta.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                                                 v15
                                               - (float)(v17
                                                       * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]));
    slide_velocity_delta.mVec128.m128_f32[0] = v14
                                             - (float)(v17
                                                     * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
    slide_velocity_delta.mVec128.m128_f32[1] = v16
                                             - (float)(v17
                                                     * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]);
    dt[2] = (btVector3)slide_velocity_delta.mVec128;
    vostok::physics::bullet_character_controller::get_corrected_walk_vector(v3, dt, &position_after_step_up);
    slide_acceleration = vostok::physics::bullet_character_controller::get_slide_acceleration(v18, dt, &v39);
    v20 = dt[72].mVec128.m128_f32[1];
    *(float *)&v21 = slide_acceleration->mVec128.m128_f32[2] * v20;
    v22 = slide_acceleration->mVec128.m128_f32[1] * v20;
    slide_velocity_delta.mVec128.m128_f32[0] = v20 * slide_acceleration->mVec128.m128_f32[0];
    slide_velocity_delta.mVec128.m128_f32[1] = v22;
    slide_velocity_delta.mVec128.m128_u64[1] = v21;
    up_step = 0.0;
    v23 = (float)((float)(v22 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                + (float)(*(float *)&v21 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
        + (float)(slide_velocity_delta.mVec128.m128_f32[0]
                * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
    v24 = dt[72].mVec128.m128_f32[1];
    move_vector.mVec128.m128_f32[0] = (float)((float)((float)(position_after_step_up.mVec128.m128_f32[0]
                                                            * (float)(s_bm_current_air_resistance / a3))
                                                    + move_vector.mVec128.m128_f32[0])
                                            + (float)(slide_velocity_delta.mVec128.m128_f32[0]
                                                    - (float)(v23
                                                            * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0])))
                                    * v24;
    move_vector.mVec128.m128_f32[1] = (float)((float)((float)(position_after_step_up.mVec128.m128_f32[1]
                                                            * (float)(s_bm_current_air_resistance / a3))
                                                    + move_vector.mVec128.m128_f32[1])
                                            + (float)(v22
                                                    - (float)(v23
                                                            * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])))
                                    * v24;
    move_vector.mVec128.m128_f32[2] = (float)((float)((float)(position_after_step_up.mVec128.m128_f32[2]
                                                            * (float)(s_bm_current_air_resistance / a3))
                                                    + move_vector.mVec128.m128_f32[2])
                                            + (float)(*(float *)&v21
                                                    - (float)(v23
                                                            * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2])))
                                    * v24;
    move_vector.mVec128.m128_i32[3] = 0;
    vostok::physics::bullet_character_controller::step_up(
      v25,
      (vostok::physics::bullet_character_controller *)dt,
      &up_step);
    position_after_step_up.mVec128 = dt[4].mVec128;
    vostok::physics::bullet_character_controller::step_forward(
      &move_vector,
      (vostok::physics::bullet_character_controller *)dt);
    vostok::physics::bullet_character_controller::step_down(
      &move_vector,
      v26,
      (vostok::physics::bullet_character_controller *)dt,
      (btVector3 *)LODWORD(up_step),
      was_on_ground[0],
      &pre_step_bottom_pos,
      &position_after_step_up,
      &slide_velocity_delta);
  }
  vostok::physics::round_up(dt[4].mVec128.m128_f32);
  vostok::physics::round_up(&dt[4].mVec128.m128_f32[1]);
  vostok::physics::round_up(&dt[4].mVec128.m128_f32[2]);
  vostok::physics::round_up(dt[73].mVec128.m128_f32);
  vostok::physics::round_up(&dt[73].mVec128.m128_f32[1]);
  vostok::physics::round_up(&dt[73].mVec128.m128_f32[2]);
  v27 = v33;
  v28 = a3 / dt[72].mVec128.m128_f32[1];
  v29 = s_bm_current_air_resistance - v28;
  v30 = v36.mVec128.m128_f32[1];
  v33->mVec128.m128_f32[0] = (float)(v28 * dt[4].mVec128.m128_f32[0])
                           + (float)((float)(s_bm_current_air_resistance - v28) * v36.mVec128.m128_f32[0]);
  v27->mVec128.m128_f32[1] = (float)(dt[4].mVec128.m128_f32[1] * v28) + (float)(v30 * v29);
  v27->mVec128.m128_f32[2] = (float)(dt[4].mVec128.m128_f32[2] * v28) + (float)(v36.mVec128.m128_f32[2] * v29);
}
