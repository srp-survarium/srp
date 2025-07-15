char __thiscall vostok::physics::character_controller_jump_tester::convex_sweep_test(
        vostok::physics::character_controller_jump_tester *this,
        stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *start,
        const btVector3 *finish,
        btVector3 *out_hit_point_world,
        btVector3 *out_hit_normal_world,
        btVector3 *out_closest_hit_fraction,
        float *a7)
{
  unsigned int vertical_offset_low; // eax
  stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *v8; // ecx
  vostok::physics::bt_closest_convex_not_me_result_callback *v9; // ecx
  int v10; // eax
  const btQuaternion *Identity; // eax
  const btQuaternion *v13; // eax
  btCollisionWorld *v14; // ecx
  float m_closestHitFraction; // xmm0_4
  stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *v16; // [esp-14h] [ebp-148h]
  btConvexShape *v17; // [esp-10h] [ebp-144h]
  boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > > > v18; // [esp-4h] [ebp-138h]
  unsigned __int16 v19; // [esp+4h] [ebp-130h]
  unsigned __int16 v20; // [esp+8h] [ebp-12Ch]
  stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *v21; // [esp+1Ch] [ebp-118h] BYREF
  int v22; // [esp+20h] [ebp-114h]
  vostok::physics::character_controller_jump_vertical_tester::value_type value; // [esp+24h] [ebp-110h] BYREF
  btVector3 v24; // [esp+54h] [ebp-E0h]
  vostok::physics::character_controller_jump_vertical_tester::key_type key; // [esp+64h] [ebp-D0h] BYREF
  btCollisionWorld::ClosestConvexResultCallback v26; // [esp+84h] [ebp-B0h] BYREF
  btTransform v27; // [esp+F4h] [ebp-40h] BYREF

  key.start.mVec128.m128_u64[0] = finish->mVec128.m128_u64[0];
  vertical_offset_low = LODWORD(start->first.vertical_offset);
  key.start.mVec128.m128_u64[1] = finish->mVec128.m128_u64[1];
  *(btVector3 *)&key.vertical_offset = (btVector3)out_hit_point_world->mVec128;
  if ( vertical_offset_low )
    v8 = (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)start->first.start.mVec128.m128_i32[2];
  else
    v8 = 0;
  v18.m_it = (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)&key;
  v18.m_buff = 0;
  stlp_std::priv::__find_if<boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>>>,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>>>>,vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>::cache_predicate>(
    &v21,
    start,
    (boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> > > >)__PAIR64__((unsigned int)start, (unsigned int)v8),
    v18);
  if ( v22 )
    v10 = v22 + 32;
  else
    v10 = 0;
  if ( v10 )
  {
    if ( *(_BYTE *)(v10 + 36) )
    {
      *out_hit_normal_world = *(btVector3 *)v10;
      *out_closest_hit_fraction = *(btVector3 *)(v10 + 16);
      *a7 = *(float *)(v10 + 32);
    }
    return *(_BYTE *)(v10 + 36);
  }
  else
  {
    vostok::physics::bt_closest_convex_not_me_result_callback::bt_closest_convex_not_me_result_callback(
      v9,
      &v26,
      *((btCollisionWorld::ClosestConvexResultCallback_vtbl **)&start->first.vertical_offset + 3),
      v19,
      v20);
    Identity = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(Identity, (btMatrix3x3 *)&value);
    v24.mVec128 = out_hit_point_world->mVec128;
    v13 = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(v13, &v27.m_basis);
    v27.m_origin.mVec128.m128_u64[0] = finish->mVec128.m128_u64[0];
    v17 = (btConvexShape *)*((_DWORD *)&start->first.vertical_offset + 2);
    v27.m_origin.mVec128.m128_i32[2] = finish->mVec128.m128_i32[2];
    v16 = (stlp_std::pair<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)start->second.hit_point_world.mVec128.m128_i32[0];
    v27.m_origin.mVec128.m128_i32[3] = finish->mVec128.m128_i32[3];
    btCollisionWorld::convexSweepTest(
      v14,
      (const btCollisionWorld *)v16,
      v17,
      &v27,
      (btCollisionWorld::ConvexResultCallback *)&value,
      &v26,
      0.0);
    m_closestHitFraction = v26.m_closestHitFraction;
    if ( s_bm_current_air_resistance <= v26.m_closestHitFraction )
    {
      value.closest_hit_fraction = QNaN_152;
      value.has_hit = 0;
      vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>::add(
        &key,
        (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_jump_vertical_tester::key_type,vostok::physics::character_controller_jump_vertical_tester::value_type> *)start,
        &value);
      return 0;
    }
    else
    {
      *out_hit_normal_world = v26.m_hitPointWorld;
      *out_closest_hit_fraction = v26.m_hitNormalWorld;
      value.hit_point_world = (btVector3)out_hit_normal_world->mVec128;
      value.hit_normal_world.mVec128.m128_u64[0] = v26.m_hitNormalWorld.mVec128.m128_u64[0];
      value.hit_normal_world.mVec128.m128_i32[2] = v26.m_hitNormalWorld.mVec128.m128_i32[2];
      *a7 = m_closestHitFraction;
      value.hit_normal_world.mVec128.m128_i32[3] = v26.m_hitNormalWorld.mVec128.m128_i32[3];
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
