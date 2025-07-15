char __thiscall vostok::physics::character_controller_step_down_tester::convex_sweep_test(
        vostok::physics::character_controller_step_down_tester *this,
        stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *start,
        float *down_step,
        float max_slope_angle_cos,
        btVector3 *out_hit_point_world,
        btVector3 *out_hit_normal_world,
        float *out_closest_hit_fraction)
{
  boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > > > v9; // rcx
  int v10; // xmm1_4
  float vertical_offset; // eax
  int v12; // eax
  int v14; // esi
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  int v21; // eax
  const btQuaternion *Identity; // eax
  const btQuaternion *v23; // eax
  btCollisionWorld *v24; // ecx
  float m_closestHitFraction; // xmm0_4
  float m_steep_collision_closest_hit_fraction; // xmm1_4
  int v27; // xmm0_4
  boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > > > v28; // [esp+8h] [ebp-1B8h]
  float v29; // [esp+Ch] [ebp-1B4h]
  char v30; // [esp+2Bh] [ebp-195h]
  btIDebugDraw *v31; // [esp+2Ch] [ebp-194h]
  float v32; // [esp+30h] [ebp-190h] BYREF
  float v33; // [esp+34h] [ebp-18Ch]
  float v34; // [esp+38h] [ebp-188h]
  int v35; // [esp+3Ch] [ebp-184h]
  _DWORD v36[8]; // [esp+40h] [ebp-180h] BYREF
  btMatrix3x3 v37; // [esp+60h] [ebp-160h] BYREF
  stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *v38; // [esp+90h] [ebp-130h]
  float v39; // [esp+94h] [ebp-12Ch]
  float v40; // [esp+98h] [ebp-128h]
  int v41; // [esp+9Ch] [ebp-124h]
  _BYTE v42[80]; // [esp+A0h] [ebp-120h] BYREF
  character_step_down_sweep_test_callback v43; // [esp+F0h] [ebp-D0h] BYREF

  v9.m_it = start;
  v10 = *(_DWORD *)(start->second.hit_normal_world.mVec128.m128_i32[0]
                  + 4 * *(_DWORD *)(start->second.hit_normal_world.mVec128.m128_i32[0] + 64)
                  + 32);
  vertical_offset = start->first.vertical_offset;
  *(float *)v36 = *down_step;
  *(float *)&v36[1] = down_step[1];
  *(float *)&v36[2] = down_step[2];
  *(float *)&v36[3] = down_step[3];
  v31 = (btIDebugDraw *)LODWORD(vostok::physics::bullet_character_controller::ms_max_slope_normal_dot);
  *(float *)&v36[4] = max_slope_angle_cos;
  v36[5] = v10;
  *(float *)&v36[6] = vostok::physics::bullet_character_controller::ms_max_slope_normal_dot;
  if ( vertical_offset == 0.0 )
    v9.m_buff = 0;
  else
    v9.m_buff = (const boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > > *)start->first.start.mVec128.m128_i32[2];
  v28.m_it = (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)v36;
  v28.m_buff = 0;
  stlp_std::priv::__find_if<boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type>>>,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type>>>>,vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type>::cache_predicate>(
    (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> **)&v32,
    start,
    v9,
    v28);
  if ( v33 == 0.0 )
    v12 = 0;
  else
    v12 = LODWORD(v33) + 32;
  if ( v12 )
  {
    if ( *(_BYTE *)(v12 + 36) )
    {
      *out_hit_point_world = *(btVector3 *)v12;
      *out_hit_normal_world = *(btVector3 *)(v12 + 16);
      *out_closest_hit_fraction = *(float *)(v12 + 32);
    }
    return *(_BYTE *)(v12 + 36);
  }
  else
  {
    v14 = start->second.hit_normal_world.mVec128.m128_i32[0];
    v15 = start->second.hit_point_world.mVec128.m128_f32[1] * max_slope_angle_cos;
    v16 = start->second.hit_point_world.mVec128.m128_f32[2] * max_slope_angle_cos;
    v17 = *down_step * start->second.hit_point_world.mVec128.m128_f32[0];
    v18 = down_step[1];
    v32 = *down_step + (float)(start->second.hit_point_world.mVec128.m128_f32[0] * max_slope_angle_cos);
    v19 = v18 + v15;
    v20 = down_step[2];
    v21 = *(_DWORD *)(v14 + 64);
    v33 = v19;
    v35 = 0;
    ++v21;
    v29 = (float)((float)((float)(start->second.hit_point_world.mVec128.m128_f32[2] * v20)
                        + (float)(start->second.hit_point_world.mVec128.m128_f32[1] * v18))
                + v17)
        - *(float *)(v14 + 4 * v21 + 28);
    v34 = v20 + v16;
    character_step_down_sweep_test_callback::character_step_down_sweep_test_callback(
      (character_step_down_sweep_test_callback *)&start->second,
      &v43,
      (btCollisionWorld *)start->second.hit_normal_world.mVec128.m128_i32[2],
      (btCollisionObject *)start->second.hit_normal_world.mVec128.m128_i32[1],
      (int *)&start->second,
      v31,
      (int *)down_step,
      *(float *)(v14 + 4 * ((v21 + 1) % 3) + 32),
      v29);
    Identity = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(Identity, &v37);
    v38 = (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)LODWORD(v32);
    v39 = v33;
    v40 = v34;
    v41 = v35;
    v23 = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(v23, (btMatrix3x3 *)v42);
    *(float *)&v42[48] = *down_step;
    *(float *)&v42[52] = down_step[1];
    *(float *)&v42[56] = down_step[2];
    *(float *)&v42[60] = down_step[3];
    btCollisionWorld::convexSweepTest(
      v24,
      (const btCollisionWorld *)start->second.hit_normal_world.mVec128.m128_i32[2],
      (btConvexShape *)start->second.hit_normal_world.mVec128.m128_i32[0],
      (const btTransform *)v42,
      (btCollisionWorld::ConvexResultCallback *)&v37,
      &v43,
      0.0);
    m_closestHitFraction = v43.m_closestHitFraction;
    v30 = 0;
    if ( s_bm_current_air_resistance > v43.m_closestHitFraction )
    {
      *out_hit_point_world = v43.m_hitPointWorld;
      out_hit_normal_world->mVec128.m128_u64[0] = v43.m_hitNormalWorld.mVec128.m128_u64[0];
      out_hit_normal_world->mVec128.m128_i32[2] = v43.m_hitNormalWorld.mVec128.m128_i32[2];
      *out_closest_hit_fraction = m_closestHitFraction;
      out_hit_normal_world->mVec128.m128_i32[3] = v43.m_hitNormalWorld.mVec128.m128_i32[3];
      v30 = 1;
    }
    if ( v43.m_has_steep_collision )
    {
      m_steep_collision_closest_hit_fraction = v43.m_steep_collision_closest_hit_fraction;
      if ( m_closestHitFraction >= v43.m_steep_collision_closest_hit_fraction )
      {
        *out_hit_normal_world = v43.m_steep_hit_normal_world;
        out_hit_point_world->mVec128.m128_u64[0] = v43.m_steep_hit_point_world.mVec128.m128_u64[0];
        out_hit_point_world->mVec128.m128_i32[2] = v43.m_steep_hit_point_world.mVec128.m128_i32[2];
        *out_closest_hit_fraction = m_steep_collision_closest_hit_fraction;
        out_hit_point_world->mVec128.m128_i32[3] = v43.m_steep_hit_point_world.mVec128.m128_i32[3];
        v30 = 1;
      }
    }
    if ( v30 )
    {
      v37.m_el[0].mVec128.m128_u64[0] = out_hit_point_world->mVec128.m128_u64[0];
      v27 = *(_DWORD *)out_closest_hit_fraction;
      v37.m_el[0].mVec128.m128_u64[1] = out_hit_point_world->mVec128.m128_u64[1];
      v37.m_el[1] = (btVector3)out_hit_normal_world->mVec128;
      v37.m_el[2].mVec128.m128_i8[4] = 1;
    }
    else
    {
      v27 = LODWORD(QNaN_149);
      v37.m_el[2].mVec128.m128_i8[4] = 0;
    }
    qmemcpy(v42, v36, 0x20u);
    v37.m_el[2].mVec128.m128_i32[0] = v27;
    qmemcpy(&v42[32], &v37, 0x30u);
    boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>>>::push_back(
      0,
      start,
      (int)v42);
    return v30;
  }
}
