bool __thiscall vostok::physics::character_controller_straighten_tester::convex_sweep_test(
        vostok::physics::character_controller_straighten_tester *this,
        stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type> *start,
        float *up_offset,
        btVector3 *ceiling_normal,
        _DWORD *a7)
{
  int v7; // xmm0_4
  float v8; // eax
  int v9; // ecx
  float *v10; // ecx
  int v12; // eax
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  const btQuaternion *Identity; // eax
  const btQuaternion *v17; // eax
  btCollisionWorld *v18; // ecx
  btVector3 *p_m_hitNormalWorld; // eax
  const btCollisionWorld *v20; // [esp-10h] [ebp-168h]
  btConvexShape *v21; // [esp-Ch] [ebp-164h]
  boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> > > > v22; // [esp+0h] [ebp-158h]
  float v23; // [esp+18h] [ebp-140h] BYREF
  float v24; // [esp+1Ch] [ebp-13Ch]
  float v25; // [esp+20h] [ebp-138h]
  int v26; // [esp+24h] [ebp-134h]
  _DWORD v27[8]; // [esp+28h] [ebp-130h] BYREF
  btMatrix3x3 v28; // [esp+48h] [ebp-110h] BYREF
  float v29; // [esp+78h] [ebp-E0h]
  float v30; // [esp+7Ch] [ebp-DCh]
  float v31; // [esp+80h] [ebp-D8h]
  int v32; // [esp+84h] [ebp-D4h]
  btTransform v33; // [esp+88h] [ebp-D0h] BYREF
  btCollisionWorld::ClosestConvexResultCallback v34; // [esp+C8h] [ebp-90h] BYREF

  v7 = *(_DWORD *)(start[1].first.start.mVec128.m128_i32[0]
                 + 4 * *(_DWORD *)(start[1].first.start.mVec128.m128_i32[0] + 64)
                 + 32);
  v8 = start->first.up_offset;
  *(float *)v27 = *up_offset;
  *(float *)&v27[1] = up_offset[1];
  *(float *)&v27[2] = up_offset[2];
  *(float *)&v27[3] = up_offset[3];
  v27[4] = ceiling_normal;
  v27[5] = v7;
  if ( v8 == 0.0 )
    v9 = 0;
  else
    v9 = start->first.start.mVec128.m128_i32[2];
  v22.m_it = (stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> *)v27;
  v22.m_buff = 0;
  stlp_std::priv::__find_if<boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>>>,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>>>>,vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>::cache_predicate>(
    (stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> **)&v23,
    (stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> *)start,
    (boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> > > >)__PAIR64__((unsigned int)start, v9),
    v22);
  if ( v24 == 0.0 )
    v10 = 0;
  else
    v10 = (float *)(LODWORD(v24) + 32);
  if ( v10 )
  {
    *a7 = *(_DWORD *)v10;
    a7[1] = *((_DWORD *)v10 + 1);
    a7[2] = *((_DWORD *)v10 + 2);
    a7[3] = *((_DWORD *)v10 + 3);
    return *v10 != 0.0 || v10[1] != 0.0 || v10[2] != 0.0;
  }
  else
  {
    v12 = start[1].first.start.mVec128.m128_i32[0];
    vostok::physics::character_up_sweep_test_callback::character_up_sweep_test_callback(
      (vostok::physics::character_up_sweep_test_callback *)3,
      &v34,
      (const btVector3 *)start[1].first.start.mVec128.m128_i32[1],
      &start->second.ceiling_normal,
      *(const float *)&up_offset,
      *(float *)(v12 + 4 * ((*(_DWORD *)(v12 + 64) + 2) % 3) + 32),
      COERCE_INT(
        (float)((float)((float)(start->second.ceiling_normal.mVec128.m128_f32[2] * up_offset[2])
                      + *(float *)(v12 + 4 * *(_DWORD *)(v12 + 64) + 32))
              + (float)(start->second.ceiling_normal.mVec128.m128_f32[1] * up_offset[1]))
      + (float)(*up_offset * start->second.ceiling_normal.mVec128.m128_f32[0])));
    v13 = start->second.ceiling_normal.mVec128.m128_f32[2] * *(float *)&ceiling_normal;
    v14 = start->second.ceiling_normal.mVec128.m128_f32[0] * *(float *)&ceiling_normal;
    v15 = *up_offset;
    v24 = (float)(start->second.ceiling_normal.mVec128.m128_f32[1] * *(float *)&ceiling_normal) + up_offset[1];
    v25 = up_offset[2] + v13;
    v23 = v15 + v14;
    v26 = 0;
    Identity = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(Identity, &v28);
    v29 = v23;
    v30 = v24;
    v31 = v25;
    v32 = v26;
    v17 = btQuaternion::getIdentity();
    btMatrix3x3::setRotation(v17, &v33.m_basis);
    v33.m_origin.mVec128.m128_u64[0] = *(_QWORD *)up_offset;
    v21 = (btConvexShape *)start[1].first.start.mVec128.m128_i32[0];
    v33.m_origin.mVec128.m128_f32[2] = up_offset[2];
    v20 = (const btCollisionWorld *)start[1].first.start.mVec128.m128_i32[2];
    v33.m_origin.mVec128.m128_f32[3] = up_offset[3];
    btCollisionWorld::convexSweepTest(v18, v20, v21, &v33, (btCollisionWorld::ConvexResultCallback *)&v28, &v34, 0.0);
    if ( s_bm_current_air_resistance <= v34.m_closestHitFraction )
    {
      v23 = 0.0;
      v24 = 0.0;
      v25 = 0.0;
      v26 = 0;
      p_m_hitNormalWorld = (btVector3 *)&v23;
    }
    else
    {
      p_m_hitNormalWorld = &v34.m_hitNormalWorld;
    }
    *a7 = p_m_hitNormalWorld->mVec128.m128_i32[0];
    a7[1] = p_m_hitNormalWorld->mVec128.m128_i32[1];
    a7[2] = p_m_hitNormalWorld->mVec128.m128_i32[2];
    a7[3] = p_m_hitNormalWorld->mVec128.m128_i32[3];
    qmemcpy(&v28, v27, 0x20u);
    v28.m_el[2] = (btVector3)p_m_hitNormalWorld->mVec128;
    boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>>>::push_back(
      0,
      start,
      &v28);
    return s_bm_current_air_resistance > v34.m_closestHitFraction;
  }
}
