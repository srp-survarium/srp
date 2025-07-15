char __thiscall vostok::physics::character_controller_capsule_move_step_tester::convex_sweep_test(
        vostok::physics::character_controller_capsule_move_step_tester *this,
        stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *start,
        const btVector3 *finish,
        btVector3 *hit_point,
        btVector3 *hit_normal,
        btVector3 *hit_fraction,
        float *a9)
{
  int v9; // xmm0_4
  unsigned int v10; // eax
  stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *v11; // ecx
  btVector3 *v12; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  const btQuaternion *Identity; // eax
  const btQuaternion *v19; // eax
  btCollisionWorld *v20; // ecx
  float m_closestHitFraction; // xmm0_4
  stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *v22; // [esp-14h] [ebp-188h]
  btCollisionObject *v23; // [esp-10h] [ebp-184h]
  btConvexShape *v24; // [esp-10h] [ebp-184h]
  stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *v25; // [esp-Ch] [ebp-180h]
  boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> > > > v26; // [esp-4h] [ebp-178h]
  vostok::physics::character_move_sweep_callback move_direction; // [esp+14h] [ebp-160h] BYREF
  unsigned __int64 v28; // [esp+C4h] [ebp-B0h]
  int v29; // [esp+CCh] [ebp-A8h]
  int v30; // [esp+D0h] [ebp-A4h]
  btCollisionWorld::ClosestConvexResultCallback world; // [esp+D4h] [ebp-A0h] BYREF

  v9 = *(_DWORD *)(start->second.hit_point_world.mVec128.m128_i32[0]
                 + 4 * *(_DWORD *)(start->second.hit_point_world.mVec128.m128_i32[0] + 64)
                 + 32);
  *(_QWORD *)&move_direction.m_hitCollisionObject = finish->mVec128.m128_u64[0];
  v10 = start->first.finish.mVec128.m128_u32[0];
  *((_QWORD *)&move_direction.m_hitCollisionObject + 1) = finish->mVec128.m128_u64[1];
  move_direction.m_move_direction = (const btVector3)hit_point->mVec128;
  move_direction.m_start.mVec128.m128_i32[0] = v9;
  if ( v10 )
    v11 = (stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *)start->first.start.mVec128.m128_i32[2];
  else
    v11 = 0;
  v26.m_it = (stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *)&move_direction.m_hitCollisionObject;
  v26.m_buff = 0;
  stlp_std::priv::__find_if<boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>>>,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>>>>,vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>::cache_predicate>(
    (stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> **)&move_direction,
    start,
    (boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> > > >)__PAIR64__((unsigned int)start, (unsigned int)v11),
    v26);
  if ( LODWORD(move_direction.m_closestHitFraction) )
    v12 = (btVector3 *)(LODWORD(move_direction.m_closestHitFraction) + 48);
  else
    v12 = 0;
  if ( v12 )
  {
    if ( v12[2].mVec128.m128_i8[4] )
    {
      *hit_normal = (btVector3)v12->mVec128;
      hit_fraction->mVec128.m128_i32[0] = v12[1].mVec128.m128_i32[0];
      hit_fraction->mVec128.m128_i32[1] = v12[1].mVec128.m128_i32[1];
      hit_fraction->mVec128.m128_i32[2] = v12[1].mVec128.m128_i32[2];
      hit_fraction->mVec128.m128_i32[3] = v12[1].mVec128.m128_i32[3];
      *a9 = v12[2].mVec128.m128_f32[0];
    }
    return v12[2].mVec128.m128_i8[4];
  }
  else
  {
    v14 = hit_point->mVec128.m128_f32[1] - finish->mVec128.m128_f32[1];
    v15 = hit_point->mVec128.m128_f32[2] - finish->mVec128.m128_f32[2];
    v16 = hit_point->mVec128.m128_f32[0] - finish->mVec128.m128_f32[0];
    v25 = (stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *)start->second.hit_point_world.mVec128.m128_i32[1];
    v23 = (btCollisionObject *)start->second.hit_point_world.mVec128.m128_i32[2];
    v17 = s_bm_current_air_resistance / fsqrt((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v16 * v16));
    move_direction.m_closestHitFraction = v14 * v17;
    *(float *)&move_direction.__vftable = v17 * v16;
    *(_QWORD *)&move_direction.m_collisionFilterGroup = COERCE_UNSIGNED_INT(v15 * v17);
    vostok::physics::character_move_sweep_callback::character_move_sweep_callback(
      &move_direction,
      &world,
      v23,
      &v25->first.start,
      &start->first.capsule_half_height,
      finish,
      (const btVector3 *)&move_direction);
    Identity = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(Identity, (btMatrix3x3 *)&move_direction.m_convexFromWorld);
    move_direction.m_hitPointWorld = (btVector3)hit_point->mVec128;
    v19 = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(v19, (btMatrix3x3 *)&move_direction.m_up_vector);
    v28 = finish->mVec128.m128_u64[0];
    v24 = (btConvexShape *)start->second.hit_point_world.mVec128.m128_i32[0];
    v29 = finish->mVec128.m128_i32[2];
    v22 = (stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *)start->second.hit_point_world.mVec128.m128_i32[2];
    v30 = finish->mVec128.m128_i32[3];
    btCollisionWorld::convexSweepTest(
      v20,
      (const btCollisionWorld *)v22,
      v24,
      (const btTransform *)&move_direction.m_up_vector,
      (btCollisionWorld::ConvexResultCallback *)&move_direction.m_convexFromWorld,
      &world,
      0.0);
    m_closestHitFraction = world.m_closestHitFraction;
    if ( s_bm_current_air_resistance <= world.m_closestHitFraction )
    {
      move_direction.m_hitNormalWorld.mVec128.m128_f32[0] = QNaN_151;
      move_direction.m_hitNormalWorld.mVec128.m128_i8[4] = 0;
      vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>::add(
        (const vostok::physics::character_controller_capsule_move_step_tester::key_type *)&move_direction.m_hitCollisionObject,
        (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *)start,
        (const vostok::physics::character_controller_capsule_move_step_tester::value_type *)&move_direction.m_convexFromWorld);
      return 0;
    }
    else
    {
      *hit_normal = world.m_hitPointWorld;
      *hit_fraction = world.m_hitNormalWorld;
      move_direction.m_convexFromWorld = (btVector3)hit_normal->mVec128;
      move_direction.m_convexToWorld.mVec128.m128_u64[0] = world.m_hitNormalWorld.mVec128.m128_u64[0];
      move_direction.m_convexToWorld.mVec128.m128_i32[2] = world.m_hitNormalWorld.mVec128.m128_i32[2];
      *a9 = m_closestHitFraction;
      move_direction.m_convexToWorld.mVec128.m128_i32[3] = world.m_hitNormalWorld.mVec128.m128_i32[3];
      move_direction.m_hitNormalWorld.mVec128.m128_f32[0] = m_closestHitFraction;
      move_direction.m_hitNormalWorld.mVec128.m128_i8[4] = 1;
      vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>::add(
        (const vostok::physics::character_controller_capsule_move_step_tester::key_type *)&move_direction.m_hitCollisionObject,
        (vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type> *)start,
        (const vostok::physics::character_controller_capsule_move_step_tester::value_type *)&move_direction.m_convexFromWorld);
      return 1;
    }
  }
}
