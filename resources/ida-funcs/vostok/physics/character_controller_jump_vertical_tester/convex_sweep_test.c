char __thiscall vostok::physics::character_controller_jump_vertical_tester::convex_sweep_test(
        vostok::physics::character_controller_jump_vertical_tester *this,
        stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *start,
        float *vertical_offset,
        btVector3 *out_hit_point_world,
        btVector3 *out_hit_normal_world,
        btVector3 *out_closest_hit_fraction,
        float *a9)
{
  unsigned int vertical_offset_low; // eax
  stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *v10; // ecx
  int v11; // eax
  int v13; // edx
  stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *v14; // eax
  float v15; // xmm3_4
  float v16; // xmm2_4
  const btQuaternion *Identity; // eax
  const btQuaternion *v18; // eax
  btCollisionWorld *v19; // ecx
  float m_closestHitFraction; // xmm0_4
  stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *v21; // [esp-14h] [ebp-168h]
  btConvexShape *v22; // [esp-10h] [ebp-164h]
  boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > > > v23; // [esp-4h] [ebp-158h]
  float v24; // [esp+14h] [ebp-140h] BYREF
  float v25; // [esp+18h] [ebp-13Ch]
  float v26; // [esp+1Ch] [ebp-138h]
  int v27; // [esp+20h] [ebp-134h]
  vostok::physics::character_controller_jump_vertical_tester::value_type value; // [esp+24h] [ebp-130h] BYREF
  stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *v29; // [esp+54h] [ebp-100h]
  float v30; // [esp+58h] [ebp-FCh]
  float v31; // [esp+5Ch] [ebp-F8h]
  int v32; // [esp+60h] [ebp-F4h]
  vostok::physics::character_controller_jump_vertical_tester::key_type key; // [esp+64h] [ebp-F0h] BYREF
  btTransform v34; // [esp+84h] [ebp-D0h] BYREF
  jump_vertical_test_callback v35; // [esp+C4h] [ebp-90h] BYREF

  vertical_offset_low = LODWORD(start->first.vertical_offset);
  key.start.mVec128.m128_u64[0] = *(_QWORD *)vertical_offset;
  key.start.mVec128.m128_u64[1] = *((_QWORD *)vertical_offset + 1);
  LODWORD(key.vertical_offset) = out_hit_point_world;
  if ( vertical_offset_low )
    v10 = (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)start->first.start.mVec128.m128_i32[2];
  else
    v10 = 0;
  v23.m_it = (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)&key;
  v23.m_buff = 0;
  stlp_std::priv::__find_if<boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>>>,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>>>>,vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>::cache_predicate>(
    (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> **)&v24,
    start,
    (boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > > >)__PAIR64__((unsigned int)start, (unsigned int)v10),
    v23);
  if ( v25 == 0.0 )
    v11 = 0;
  else
    v11 = LODWORD(v25) + 32;
  if ( v11 )
  {
    if ( *(_BYTE *)(v11 + 36) )
    {
      *out_hit_normal_world = *(btVector3 *)v11;
      *out_closest_hit_fraction = *(btVector3 *)(v11 + 16);
      *a9 = *(float *)(v11 + 32);
    }
    return *(_BYTE *)(v11 + 36);
  }
  else
  {
    v13 = (*(_DWORD *)(start->second.hit_normal_world.mVec128.m128_i32[0] + 64) + 2) % 3;
    v14 = (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)start->second.hit_normal_world.mVec128.m128_i32[0];
    v15 = *vertical_offset + (float)(*(float *)&out_hit_point_world * start->second.hit_point_world.mVec128.m128_f32[0]);
    v16 = vertical_offset[1]
        + (float)(start->second.hit_point_world.mVec128.m128_f32[1] * *(float *)&out_hit_point_world);
    v26 = vertical_offset[2]
        + (float)(start->second.hit_point_world.mVec128.m128_f32[2] * *(float *)&out_hit_point_world);
    v24 = v15;
    v25 = v16;
    v27 = 0;
    jump_vertical_test_callback::jump_vertical_test_callback(
      (jump_vertical_test_callback *)&start->second,
      &v35,
      (btCollisionObject *)start->second.hit_normal_world.mVec128.m128_i32[1],
      &start->second.hit_point_world,
      *(const float *)&vertical_offset,
      v14->second.hit_point_world.mVec128.m128_f32[v13]);
    Identity = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(Identity, (btMatrix3x3 *)&value);
    v29 = (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)LODWORD(v24);
    v30 = v25;
    v31 = v26;
    v32 = v27;
    v18 = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(v18, &v34.m_basis);
    v34.m_origin.mVec128.m128_u64[0] = *(_QWORD *)vertical_offset;
    v22 = (btConvexShape *)start->second.hit_normal_world.mVec128.m128_i32[0];
    v34.m_origin.mVec128.m128_f32[2] = vertical_offset[2];
    v21 = (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)start->second.hit_normal_world.mVec128.m128_i32[2];
    v34.m_origin.mVec128.m128_f32[3] = vertical_offset[3];
    btCollisionWorld::convexSweepTest(
      v19,
      (const btCollisionWorld *)v21,
      v22,
      &v34,
      (btCollisionWorld::ConvexResultCallback *)&value,
      &v35,
      0.0);
    m_closestHitFraction = v35.m_closestHitFraction;
    if ( s_bm_current_air_resistance <= v35.m_closestHitFraction )
    {
      value.closest_hit_fraction = QNaN_153;
      value.has_hit = 0;
      vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>::add(
        &key,
        (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)start,
        &value);
      return 0;
    }
    else
    {
      *out_hit_normal_world = v35.m_hitPointWorld;
      *out_closest_hit_fraction = v35.m_hitNormalWorld;
      value.hit_point_world = (btVector3)out_hit_normal_world->mVec128;
      value.hit_normal_world.mVec128.m128_u64[0] = v35.m_hitNormalWorld.mVec128.m128_u64[0];
      value.hit_normal_world.mVec128.m128_i32[2] = v35.m_hitNormalWorld.mVec128.m128_i32[2];
      *a9 = m_closestHitFraction;
      value.hit_normal_world.mVec128.m128_i32[3] = v35.m_hitNormalWorld.mVec128.m128_i32[3];
      value.closest_hit_fraction = m_closestHitFraction;
      value.has_hit = 1;
      vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>::add(
        &key,
        (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)start,
        &value);
      return 1;
    }
  }
}
