void __userpurge vostok::physics::bullet_character_controller::step_down(
        const btVector3 *move_vector@<eax>,
        vostok::physics::bullet_character_controller *a2@<ecx>,
        btVector3 *this,
        btVector3 *current_step_offset,
        bool was_on_ground,
        const btVector3 *pre_step_bottom_pos,
        btVector3 *position_after_step_up,
        const btVector3 *slide_velocity_delta)
{
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  vostok::physics::bullet_character_controller *v12; // ecx
  btVector3 *p_time_hit_fraction; // esi
  btVector3 *v14; // edi
  float v15; // xmm0_4
  bool v16; // al
  int *v17; // edi
  int *v18; // esi
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  btCapsuleShape *v24; // esi
  const vostok::math::float2 *v25; // eax
  btVector3 *v26; // eax
  vostok::physics::character_controller_can_stand_tester *v27; // ecx
  bool v28; // zf
  bool v29; // al
  int v30; // ecx
  const btVector3 *v31; // [esp+20h] [ebp-40h]
  const btVector3 *v32; // [esp+24h] [ebp-3Ch]
  float v33; // [esp+30h] [ebp-30h] BYREF
  float v34; // [esp+34h] [ebp-2Ch]
  float v35; // [esp+38h] [ebp-28h]
  float v36; // [esp+3Ch] [ebp-24h]
  btVector3 time_hit_fraction; // [esp+40h] [ebp-20h] BYREF
  btVector3 hit_normal; // [esp+50h] [ebp-10h] BYREF

  if ( was_on_ground )
    LODWORD(v35) = LODWORD(s_cc_additional_down_speed_value) ^ _mask__NegFloat_;
  else
    v35 = (float)((float)((float)((float)((float)((float)(this[77].mVec128.m128_f32[1]
                                                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                                                + (float)(this[77].mVec128.m128_f32[2]
                                                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
                                        + (float)(slide_velocity_delta->mVec128.m128_f32[1]
                                                * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]))
                                + (float)(slide_velocity_delta->mVec128.m128_f32[2]
                                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
                        + (float)(this[77].mVec128.m128_f32[0]
                                * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]))
                + (float)(slide_velocity_delta->mVec128.m128_f32[0]
                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]))
        * this[72].mVec128.m128_f32[1];
  v9 = move_vector->mVec128.m128_f32[0];
  v10 = move_vector->mVec128.m128_f32[1];
  v11 = move_vector->mVec128.m128_f32[2];
  v35 = v35 - *(float *)&current_step_offset;
  v36 = (float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v11 * v11);
  v33 = 0.0;
  v34 = 0.0;
  if ( vostok::physics::bullet_character_controller::step_down_sweep_test_impl(
         a2,
         *(const float *)&this,
         v35,
         *(float *)&current_step_offset,
         pre_step_bottom_pos->mVec128.m128_f32,
         (const btVector3 *)LODWORD(v36),
         position_after_step_up,
         &hit_normal,
         &time_hit_fraction,
         &v33) )
  {
    if ( !vostok::physics::bullet_character_controller::can_straighten(
            (vostok::physics::bullet_character_controller *)&hit_normal,
            this,
            this + 4,
            current_step_offset,
            &hit_normal)
      && !vostok::physics::bullet_character_controller::side_slide_on_low_ceiling(
            (int)v12,
            &hit_normal,
            this,
            move_vector,
            position_after_step_up,
            pre_step_bottom_pos,
            v35,
            current_step_offset,
            &time_hit_fraction,
            &v33) )
    {
      p_time_hit_fraction = vostok::physics::capsule_bottom_to_center_position(
                              pre_step_bottom_pos,
                              (const btCapsuleShape *)&this[26],
                              (int)&hit_normal);
      v14 = this + 4;
LABEL_17:
      v14->mVec128.m128_i32[0] = p_time_hit_fraction->mVec128.m128_i32[0];
      v18 = &p_time_hit_fraction->mVec128.m128_i32[1];
      v17 = &v14->mVec128.m128_i32[1];
      *v17 = *v18++;
      *++v17 = *v18;
      v17[1] = v18[1];
      goto LABEL_23;
    }
    v15 = time_hit_fraction.mVec128.m128_f32[1];
    if ( vostok::physics::bullet_character_controller::ms_max_slope_normal_dot <= (float)((float)((float)(time_hit_fraction.mVec128.m128_f32[1] * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                                                                                                + (float)(time_hit_fraction.mVec128.m128_f32[2] * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
                                                                                        + (float)(time_hit_fraction.mVec128.m128_f32[0]
                                                                                                * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0])) )
    {
      v16 = 0;
    }
    else
    {
      v16 = vostok::physics::bullet_character_controller::impassable_slope(
              v12,
              (int)this,
              pre_step_bottom_pos,
              v31,
              v32);
      v15 = time_hit_fraction.mVec128.m128_f32[1];
    }
    if ( v16 )
    {
      if ( !vostok::physics::bullet_character_controller::side_slide_on_slope(
              move_vector,
              pre_step_bottom_pos,
              move_vector,
              this,
              position_after_step_up,
              pre_step_bottom_pos,
              v35,
              current_step_offset,
              &time_hit_fraction,
              &v33) )
      {
        this[4] = (btVector3)vostok::physics::capsule_bottom_to_center_position(
                               pre_step_bottom_pos,
                               (const btCapsuleShape *)&this[26],
                               (int)&hit_normal)->mVec128;
        v34 = (float)((float)(this[77].mVec128.m128_f32[1]
                            * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                    + (float)(this[77].mVec128.m128_f32[2]
                            * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
            + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]
                    * this[77].mVec128.m128_f32[0]);
LABEL_21:
        this[77].mVec128.m128_u64[0] = 0;
        this[77].mVec128.m128_u64[1] = 0;
        goto LABEL_23;
      }
      v15 = time_hit_fraction.mVec128.m128_f32[1];
    }
    v14 = this + 73;
    p_time_hit_fraction = &time_hit_fraction;
    if ( (float)((float)((float)(v15 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                       + (float)(time_hit_fraction.mVec128.m128_f32[2]
                               * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
               + (float)(time_hit_fraction.mVec128.m128_f32[0]
                       * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0])) > vostok::physics::bullet_character_controller::ms_max_slope_normal_dot )
    {
      v34 = (float)((float)(this[77].mVec128.m128_f32[1]
                          * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                  + (float)(this[77].mVec128.m128_f32[2]
                          * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
          + (float)(this[77].mVec128.m128_f32[0]
                  * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
      this[77].mVec128.m128_u64[0] = 0;
      this[77].mVec128.m128_u64[1] = 0;
      goto LABEL_17;
    }
    v19 = v33;
    v14->mVec128.m128_i32[0] = time_hit_fraction.mVec128.m128_i32[0];
    *(unsigned __int64 *)((char *)this[73].mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)time_hit_fraction.mVec128.m128_u64
                                                                                       + 4);
    this[73].mVec128.m128_i32[3] = time_hit_fraction.mVec128.m128_i32[3];
    if ( v19 != 0.0 )
    {
      vostok::physics::bullet_character_controller::update_slide_velocity(
        v12,
        this,
        slide_velocity_delta,
        pre_step_bottom_pos->mVec128.m128_f32,
        v33);
      v34 = 0.0;
      goto LABEL_23;
    }
    v34 = (float)((float)(this[77].mVec128.m128_f32[1]
                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                + (float)(this[77].mVec128.m128_f32[2]
                        * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
        + (float)(this[77].mVec128.m128_f32[0]
                * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
    goto LABEL_21;
  }
  v20 = this[72].mVec128.m128_f32[2];
  v21 = v20 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2];
  v22 = v20 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1];
  v23 = this[72].mVec128.m128_f32[1];
  this[77].mVec128.m128_f32[0] = this[77].mVec128.m128_f32[0]
                               - (float)(v23
                                       * (float)(this[72].mVec128.m128_f32[2]
                                               * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]));
  this[77].mVec128.m128_f32[1] = this[77].mVec128.m128_f32[1] - (float)(v23 * v22);
  this[77].mVec128.m128_f32[2] = this[77].mVec128.m128_f32[2] - (float)(v23 * v21);
LABEL_23:
  v24 = (btCapsuleShape *)&this[26];
  vostok::physics::capsule_center_to_bottom_position(this + 4, (const btCapsuleShape *)&this[26], (int)&hit_normal);
  v25 = (const vostok::math::float2 *)&this[5].m_floats[2];
  if ( !this[31].mVec128.m128_i8[3] )
    v25 = (const vostok::math::float2 *)&this[5];
  vostok::physics::bullet_character_controller::setup_shape_dim(
    v25,
    (int)this,
    (int)&this[4],
    (int)v24,
    (vostok::physics::bullet_character_controller *)this);
  v26 = vostok::physics::capsule_bottom_to_center_position(&hit_normal, v24, (int)&time_hit_fraction);
  v28 = this[31].mVec128.m128_i8[3] == 0;
  this[4] = (btVector3)v26->mVec128;
  if ( !v28 && !this[31].mVec128.m128_i8[0] )
  {
    v29 = !this[1].mVec128.m128_i32[1]
       || vostok::physics::character_controller_can_stand_tester::can_stand(
            v27,
            (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>::cache_predicate)&this[5],
            (const stlp_std::random_access_iterator_tag *)&v26[1],
            (stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> *)&this[57],
            this[10].mVec128.m128_f32);
    this[31].mVec128.m128_i8[2] = v29;
  }
  if ( !was_on_ground )
  {
    v30 = -(this[74].mVec128.m128_i32[2] != 0);
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v30) != 0
      && this[74].mVec128.m128_f32[0] > v34 )
    {
      boost::function1<void,float>::operator()(
        (boost::function1<void,float> *)v30,
        &this[74].mVec128.m128_i32[2],
        COERCE_FLOAT(LODWORD(v34) ^ _mask__NegFloat_));
    }
  }
}
