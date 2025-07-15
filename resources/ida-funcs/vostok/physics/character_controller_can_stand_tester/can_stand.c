bool __thiscall vostok::physics::character_controller_can_stand_tester::can_stand(
        vostok::physics::character_controller_can_stand_tester *this,
        stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> *current_position,
        float *a5)
{
  int v5; // xmm0_4
  float capsule_half_height; // eax
  int v7; // ecx
  _BYTE *v8; // eax
  int v10; // eax
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  const btQuaternion *Identity; // eax
  const btQuaternion *v16; // eax
  btCollisionWorld *v17; // ecx
  const btCollisionWorld *v18; // [esp-10h] [ebp-168h]
  btConvexShape *v19; // [esp-Ch] [ebp-164h]
  boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> > > > v20; // [esp+0h] [ebp-158h]
  float v21; // [esp+18h] [ebp-140h] BYREF
  float v22; // [esp+1Ch] [ebp-13Ch]
  float v23; // [esp+20h] [ebp-138h]
  int v24; // [esp+24h] [ebp-134h]
  _DWORD v25[8]; // [esp+28h] [ebp-130h] BYREF
  btMatrix3x3 v26; // [esp+48h] [ebp-110h] BYREF
  stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> *v27; // [esp+78h] [ebp-E0h]
  float v28; // [esp+7Ch] [ebp-DCh]
  float v29; // [esp+80h] [ebp-D8h]
  int v30; // [esp+84h] [ebp-D4h]
  btTransform v31; // [esp+88h] [ebp-D0h] BYREF
  btCollisionWorld::ClosestConvexResultCallback v32; // [esp+C8h] [ebp-90h] BYREF

  v5 = *(_DWORD *)(current_position[1].first.position.mVec128.m128_i32[0]
                 + 4 * *(_DWORD *)(current_position[1].first.position.mVec128.m128_i32[0] + 64)
                 + 32);
  capsule_half_height = current_position->first.capsule_half_height;
  *(float *)v25 = *a5;
  *(float *)&v25[1] = a5[1];
  *(float *)&v25[2] = a5[2];
  *(float *)&v25[3] = a5[3];
  v25[4] = v5;
  if ( capsule_half_height == 0.0 )
    v7 = 0;
  else
    v7 = current_position->first.position.mVec128.m128_i32[2];
  v20.m_it = (stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> *)v25;
  v20.m_buff = 0;
  stlp_std::priv::__find_if<boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>>>,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>>>>,vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>::cache_predicate>(
    (stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> **)&v21,
    current_position,
    (boost::cb_details::iterator<boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> > >,boost::cb_details::nonconst_traits<stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> > > >)__PAIR64__((unsigned int)current_position, v7),
    v20);
  if ( v22 == 0.0 )
    v8 = 0;
  else
    v8 = (_BYTE *)(LODWORD(v22) + 32);
  if ( v8 )
    return *v8 == 0;
  v10 = current_position[1].first.position.mVec128.m128_i32[0];
  vostok::physics::character_up_sweep_test_callback::character_up_sweep_test_callback(
    (vostok::physics::character_up_sweep_test_callback *)3,
    &v32,
    (const btVector3 *)current_position[1].first.position.mVec128.m128_i32[1],
    (const btVector3 *)&current_position->second,
    *(const float *)&a5,
    *(float *)(v10 + 4 * ((*(_DWORD *)(v10 + 64) + 2) % 3) + 32),
    COERCE_INT(
      (float)((float)((float)(*((float *)&current_position->second + 2) * a5[2])
                    + *(float *)(v10 + 4 * *(_DWORD *)(v10 + 64) + 32))
            + (float)(*((float *)&current_position->second + 1) * a5[1]))
    + (float)(*a5 * *(float *)&current_position->second.has_hit)));
  v11 = current_position[1].first.position.mVec128.m128_f32[3];
  v12 = *((float *)&current_position->second + 1) * v11;
  v13 = *((float *)&current_position->second + 2) * v11;
  v14 = *a5 + (float)(*(float *)&current_position->second.has_hit * v11);
  v22 = a5[1] + v12;
  v23 = a5[2] + v13;
  v21 = v14;
  v24 = 0;
  Identity = btQuaternion::getIdentity();
  btMatrix3x3::setRotation(Identity, &v26);
  v27 = (stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> *)LODWORD(v21);
  v28 = v22;
  v29 = v23;
  v30 = v24;
  v16 = btQuaternion::getIdentity();
  btMatrix3x3::setRotation(v16, &v31.m_basis);
  v31.m_origin.mVec128.m128_u64[0] = *(_QWORD *)a5;
  v19 = (btConvexShape *)current_position[1].first.position.mVec128.m128_i32[0];
  v31.m_origin.mVec128.m128_f32[2] = a5[2];
  v18 = (const btCollisionWorld *)current_position[1].first.position.mVec128.m128_i32[2];
  v31.m_origin.mVec128.m128_f32[3] = a5[3];
  btCollisionWorld::convexSweepTest(v17, v18, v19, &v31, (btCollisionWorld::ConvexResultCallback *)&v26, &v32, 0.0);
  qmemcpy(&v26, v25, 0x20u);
  v26.m_el[2].mVec128.m128_i8[0] = s_bm_current_air_resistance > v32.m_closestHitFraction;
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>>>::push_back(
    0,
    current_position,
    &v26);
  return s_bm_current_air_resistance <= v32.m_closestHitFraction;
}
