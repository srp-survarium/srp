char __thiscall vostok::physics::character_controller_move_step_tester::convex_sweep_test(
        vostok::physics::character_controller_move_step_tester *this,
        stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *start,
        const btVector3 *finish,
        btVector3 *out_hit_point_world,
        btVector3 *out_hit_normal_world,
        float *out_closest_hit_fraction,
        float *a9)
{
  boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> > > > v9; // rcx
  float v10; // xmm0_4
  int v11; // eax
  btVector3 *v12; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  int capsule_half_height_low; // eax
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  const btQuaternion *Identity; // eax
  const btQuaternion *v23; // eax
  btCollisionWorld *v24; // ecx
  float m_closestHitFraction; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  vostok::physics::character_controller_move_step_tester *v29; // ecx
  float v30; // xmm3_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  const btCollisionWorld *v33; // [esp-4h] [ebp-188h]
  btCollisionObject *v34; // [esp+0h] [ebp-184h]
  const btVector3 *out_hit_point_worlda; // [esp+4h] [ebp-180h]
  boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> > > > v36; // [esp+Ch] [ebp-178h]
  bool v37; // [esp+23h] [ebp-161h]
  btVector3 move_direction; // [esp+24h] [ebp-160h] BYREF
  vostok::physics::character_controller_capsule_move_step_tester::value_type value; // [esp+34h] [ebp-150h] BYREF
  btVector3 v40; // [esp+64h] [ebp-120h]
  vostok::physics::character_controller_capsule_move_step_tester::key_type key; // [esp+74h] [ebp-110h] BYREF
  btCollisionWorld::ClosestConvexResultCallback world; // [esp+A4h] [ebp-E0h] BYREF
  btTransform v43; // [esp+144h] [ebp-40h] BYREF

  v9.m_it = start;
  v10 = *(float *)(start[2].first.start.mVec128.m128_i32[0]
                 + 4 * *(_DWORD *)(start[2].first.start.mVec128.m128_i32[0] + 64)
                 + 32);
  key.start.mVec128.m128_u64[0] = finish->mVec128.m128_u64[0];
  v11 = start->first.finish.mVec128.m128_i32[0];
  key.start.mVec128.m128_u64[1] = finish->mVec128.m128_u64[1];
  key.finish = (btVector3)out_hit_point_world->mVec128;
  key.capsule_half_height = v10;
  if ( v11 )
    v9.m_buff = (const boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> > > *)start->first.start.mVec128.m128_i32[2];
  else
    v9.m_buff = 0;
  v36.m_it = (stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *)&key;
  v36.m_buff = 0;
  stlp_std::priv::__find_if<boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>>>,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>>>>,vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>::cache_predicate>(
    (stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> **)&move_direction,
    start,
    v9,
    v36);
  if ( move_direction.mVec128.m128_i32[1] )
    v12 = (btVector3 *)(move_direction.mVec128.m128_i32[1] + 48);
  else
    v12 = 0;
  if ( v12 )
  {
    if ( v12[2].mVec128.m128_i8[4] )
    {
      *out_hit_normal_world = (btVector3)v12->mVec128;
      *out_closest_hit_fraction = v12[1].mVec128.m128_f32[0];
      out_closest_hit_fraction[1] = v12[1].mVec128.m128_f32[1];
      out_closest_hit_fraction[2] = v12[1].mVec128.m128_f32[2];
      out_closest_hit_fraction[3] = v12[1].mVec128.m128_f32[3];
      *a9 = v12[2].mVec128.m128_f32[0];
    }
    return v12[2].mVec128.m128_i8[4];
  }
  else
  {
    v14 = start[2].first.start.mVec128.m128_i32[0];
    v15 = (*(_DWORD *)(v14 + 64) + 2) % 3;
    v16 = *(_DWORD *)(v14 + 64);
    move_direction.mVec128.m128_i32[0] = *(_DWORD *)(v14 + 4 * v15 + 32);
    v16 += 2;
    move_direction.mVec128.m128_f32[1] = *(float *)(v14 + 4 * v15 + 32) + *(float *)(v14 + 4 * v16 + 24);
    move_direction.mVec128.m128_u64[1] = *(unsigned int *)(v14 + 4 * (v16 % 3) + 32);
    start->second.hit_normal_world.mVec128.m128_u64[0] = move_direction.mVec128.m128_u64[0];
    start->second.hit_normal_world.mVec128.m128_i32[2] = move_direction.mVec128.m128_i32[2];
    capsule_half_height_low = LODWORD(start->first.capsule_half_height);
    start->second.hit_normal_world.mVec128.m128_i32[3] = move_direction.mVec128.m128_i32[3];
    (*(void (__stdcall **)(_DWORD))(capsule_half_height_low + 36))(LODWORD(s_cc_move_step_margin_value));
    v18 = out_hit_point_world->mVec128.m128_f32[1] - finish->mVec128.m128_f32[1];
    v19 = out_hit_point_world->mVec128.m128_f32[2] - finish->mVec128.m128_f32[2];
    v20 = out_hit_point_world->mVec128.m128_f32[0] - finish->mVec128.m128_f32[0];
    out_hit_point_worlda = (const btVector3 *)start[2].first.start.mVec128.m128_i32[1];
    v34 = (btCollisionObject *)start[2].first.start.mVec128.m128_i32[2];
    v21 = s_bm_current_air_resistance / fsqrt((float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v20 * v20));
    move_direction.mVec128.m128_f32[1] = v18 * v21;
    move_direction.mVec128.m128_f32[0] = v21 * v20;
    move_direction.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v19 * v21);
    vostok::physics::character_move_sweep_callback::character_move_sweep_callback(
      (vostok::physics::character_move_sweep_callback *)&start[1].second.closest_hit_fraction,
      &world,
      v34,
      out_hit_point_worlda,
      &start[1].second.closest_hit_fraction,
      finish,
      &move_direction);
    Identity = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(Identity, (btMatrix3x3 *)&value);
    v40.mVec128 = out_hit_point_world->mVec128;
    v23 = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(v23, &v43.m_basis);
    v43.m_origin.mVec128.m128_u64[0] = finish->mVec128.m128_u64[0];
    v43.m_origin.mVec128.m128_i32[2] = finish->mVec128.m128_i32[2];
    v33 = (const btCollisionWorld *)start[2].first.start.mVec128.m128_i32[2];
    v43.m_origin.mVec128.m128_i32[3] = finish->mVec128.m128_i32[3];
    btCollisionWorld::convexSweepTest(
      v24,
      v33,
      (btConvexShape *)&start->first.capsule_half_height,
      &v43,
      (btCollisionWorld::ConvexResultCallback *)&value,
      &world,
      0.0);
    m_closestHitFraction = world.m_closestHitFraction;
    if ( s_bm_current_air_resistance <= world.m_closestHitFraction )
    {
      value.closest_hit_fraction = QNaN_150;
      value.has_hit = 0;
      vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>::add(
        &key,
        (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *)start,
        &value);
      return 0;
    }
    else
    {
      *out_hit_normal_world = world.m_hitPointWorld;
      v26 = world.m_hitPointWorld.mVec128.m128_f32[2];
      v27 = world.m_hitPointWorld.mVec128.m128_f32[1];
      *(btVector3 *)out_closest_hit_fraction = world.m_hitNormalWorld;
      v28 = v27 - finish->mVec128.m128_f32[1];
      v29 = (vostok::physics::character_controller_move_step_tester *)start[2].first.start.mVec128.m128_i32[0];
      v30 = *((float *)&start[1].second.has_hit + 1) * (float)(v26 - finish->mVec128.m128_f32[2]);
      v31 = *(float *)&start[1].second.has_hit;
      *a9 = m_closestHitFraction;
      v37 = 1;
      if ( (float)((float)(v30 + (float)(v31 * v28))
                 + (float)(start[1].second.closest_hit_fraction
                         * (float)(world.m_hitPointWorld.mVec128.m128_f32[0] - finish->mVec128.m128_f32[0]))) <= *((float *)&v29->m_cylinder.__vftable + v29->m_cylinder.m_implicitShapeDimensions.mVec128.m128_i32[0])
        || (v37 = vostok::physics::character_controller_move_step_tester::complex_sweep_test(
                    v29,
                    &start->first.start,
                    finish,
                    (vostok::physics::character_move_sweep_callback *)out_hit_point_world,
                    &move_direction,
                    (btVector3 *)LODWORD(world.m_closestHitFraction),
                    out_hit_normal_world,
                    out_closest_hit_fraction,
                    a9)) )
      {
        value.hit_point_world.mVec128.m128_u64[0] = out_hit_normal_world->mVec128.m128_u64[0];
        v32 = *a9;
        value.hit_point_world.mVec128.m128_u64[1] = out_hit_normal_world->mVec128.m128_u64[1];
        value.hit_normal_world.mVec128.m128_u64[0] = *(_QWORD *)out_closest_hit_fraction;
        value.hit_normal_world.mVec128.m128_u64[1] = *((_QWORD *)out_closest_hit_fraction + 1);
        value.has_hit = 1;
      }
      else
      {
        v32 = QNaN_150;
        value.has_hit = 0;
      }
      value.closest_hit_fraction = v32;
      vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>::add(
        &key,
        (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *)start,
        &value);
      return v37;
    }
  }
}
