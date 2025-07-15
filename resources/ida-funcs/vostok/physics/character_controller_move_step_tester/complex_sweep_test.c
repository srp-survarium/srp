bool __thiscall vostok::physics::character_controller_move_step_tester::complex_sweep_test(
        vostok::physics::character_controller_move_step_tester *this,
        const btVector3 *start,
        const btVector3 *finish,
        vostok::physics::character_move_sweep_callback *move_direction,
        const btVector3 *rough_test_hit_faction,
        btVector3 *out_hit_point_world,
        btVector3 *out_hit_normal_world,
        float *out_closest_hit_fraction,
        float *a9)
{
  int v10; // eax
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  const btQuaternion *Identity; // eax
  const btQuaternion *v15; // eax
  btCollisionWorld *v16; // ecx
  vostok::physics::character_move_sweep_callback *v18; // ecx
  int v19; // eax
  int v20; // edx
  float v21; // xmm5_4
  const btQuaternion *v22; // eax
  const btQuaternion *v23; // eax
  btCollisionWorld *v24; // ecx
  btCollisionWorld::ClosestConvexResultCallback *p_world; // eax
  float m_closestHitFraction; // xmm1_4
  float v27; // xmm0_4
  int v28; // [esp+18h] [ebp-1E0h]
  unsigned __int64 v29; // [esp+18h] [ebp-1E0h]
  btVector3 v30; // [esp+18h] [ebp-1E0h]
  btVector3 v31; // [esp+28h] [ebp-1D0h]
  btVector3 v32; // [esp+28h] [ebp-1D0h]
  btTransform v33; // [esp+38h] [ebp-1C0h] BYREF
  btTransform v34; // [esp+78h] [ebp-180h] BYREF
  btCollisionWorld::ClosestConvexResultCallback world; // [esp+B8h] [ebp-140h] BYREF
  btCollisionWorld::ClosestConvexResultCallback v36; // [esp+158h] [ebp-A0h] BYREF

  v28 = *(_DWORD *)(start[12].mVec128.m128_i32[0] + 4 * ((*(_DWORD *)(start[12].mVec128.m128_i32[0] + 64) + 2) % 3) + 32);
  start[9].mVec128.m128_i32[0] = v28;
  start[9].mVec128.m128_i32[1] = v28;
  start[9].mVec128.m128_i32[2] = v28;
  v10 = start[7].mVec128.m128_i32[0];
  start[9].mVec128.m128_i32[3] = 0;
  (*(void (__stdcall **)(_DWORD))(v10 + 36))(LODWORD(s_cc_move_step_margin_value));
  v11 = *(float *)(start[12].mVec128.m128_i32[0] + 4 * *(_DWORD *)(start[12].mVec128.m128_i32[0] + 64) + 32);
  v31.mVec128.m128_f32[1] = (float)(start[11].mVec128.m128_f32[1] * v11) + finish->mVec128.m128_f32[1];
  v31.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)(start[11].mVec128.m128_f32[2] * v11) + finish->mVec128.m128_f32[2]);
  v12 = start[11].mVec128.m128_f32[2] * v11;
  *((float *)&v29 + 1) = move_direction->m_closestHitFraction + (float)(start[11].mVec128.m128_f32[1] * v11);
  v13 = *(float *)&move_direction->m_collisionFilterGroup;
  v31.mVec128.m128_f32[0] = (float)(start[11].mVec128.m128_f32[0] * v11) + finish->mVec128.m128_f32[0];
  *(float *)&v29 = *(float *)&move_direction->__vftable + (float)(start[11].mVec128.m128_f32[0] * v11);
  vostok::physics::character_move_sweep_callback::character_move_sweep_callback(
    move_direction,
    &world,
    (btCollisionObject *)start[12].mVec128.m128_i32[2],
    (const btVector3 *)start[12].mVec128.m128_i32[1],
    start[11].mVec128.m128_f32,
    finish,
    rough_test_hit_faction);
  Identity = btQuaternion::getIdentity();
  btMatrix3x3::setRotation(Identity, &v33.m_basis);
  v33.m_origin.mVec128.m128_u64[0] = v29;
  v33.m_origin.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v13 + v12);
  v15 = btQuaternion::getIdentity();
  btMatrix3x3::setRotation(v15, &v34.m_basis);
  v34.m_origin = (btVector3)v31.mVec128;
  btCollisionWorld::convexSweepTest(
    v16,
    (const btCollisionWorld *)start[12].mVec128.m128_i32[2],
    (btConvexShape *)&start[7],
    &v34,
    (btCollisionWorld::ConvexResultCallback *)&v33,
    &world,
    0.0);
  if ( s_bm_current_air_resistance > world.m_closestHitFraction
    && world.m_closestHitFraction <= *(float *)&out_hit_point_world )
  {
    return 1;
  }
  v18 = (vostok::physics::character_move_sweep_callback *)start[12].mVec128.m128_i32[0];
  v19 = v18->m_hitPointWorld.mVec128.m128_i32[0] + 2;
  v32.mVec128.m128_i32[0] = v18->m_convexToWorld.mVec128.m128_i32[v19 % 3];
  v32.mVec128.m128_f32[1] = (float)(v32.mVec128.m128_f32[0] * 0.5) + v18->m_convexFromWorld.mVec128.m128_f32[v19 + 2];
  start[4].mVec128.m128_u64[0] = v32.mVec128.m128_u64[0];
  start[4].mVec128.m128_u64[1] = v32.mVec128.m128_u32[0];
  v20 = (v18->m_hitPointWorld.mVec128.m128_i32[0] + 2) % 3;
  v21 = v18->m_convexToWorld.mVec128.m128_f32[v20];
  v30.mVec128.m128_f32[1] = finish->mVec128.m128_f32[1] - (float)((float)(start[11].mVec128.m128_f32[1] * v21) * 0.5);
  v30.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(finish->mVec128.m128_f32[2] - (float)((float)(start[11].mVec128.m128_f32[2]
                                                                                            * v21)
                                                                                    * 0.5));
  v30.mVec128.m128_f32[0] = finish->mVec128.m128_f32[0] - (float)((float)(v21 * start[11].mVec128.m128_f32[0]) * 0.5);
  v32.mVec128.m128_f32[0] = *(float *)&move_direction->__vftable
                          - (float)((float)(v21 * start[11].mVec128.m128_f32[0]) * 0.5);
  v32.mVec128.m128_f32[1] = move_direction->m_closestHitFraction
                          - (float)((float)(start[11].mVec128.m128_f32[1] * v21) * 0.5);
  v32.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(
                              *(float *)&move_direction->m_collisionFilterGroup
                            - (float)((float)(start[11].mVec128.m128_f32[2] * v21) * 0.5));
  vostok::physics::character_move_sweep_callback::character_move_sweep_callback(
    v18,
    &v36,
    (btCollisionObject *)start[12].mVec128.m128_i32[2],
    (const btVector3 *)start[12].mVec128.m128_i32[1],
    start[11].mVec128.m128_f32,
    finish,
    rough_test_hit_faction);
  v22 = btQuaternion::getIdentity();
  btMatrix3x3::setRotation(v22, &v34.m_basis);
  v34.m_origin = (btVector3)v32.mVec128;
  v23 = btQuaternion::getIdentity();
  btMatrix3x3::setRotation(v23, &v33.m_basis);
  v33.m_origin = (btVector3)v30.mVec128;
  btCollisionWorld::convexSweepTest(
    v24,
    (const btCollisionWorld *)start[12].mVec128.m128_i32[2],
    (btConvexShape *)&start[2],
    &v33,
    (btCollisionWorld::ConvexResultCallback *)&v34,
    &v36,
    0.0);
  p_world = &world;
  if ( v36.m_closestHitFraction <= world.m_closestHitFraction )
    p_world = &v36;
  m_closestHitFraction = p_world->m_closestHitFraction;
  v27 = s_bm_current_air_resistance;
  if ( s_bm_current_air_resistance > m_closestHitFraction && m_closestHitFraction > *(float *)&out_hit_point_world )
  {
    *out_hit_normal_world = p_world->m_hitPointWorld;
    *out_closest_hit_fraction = p_world->m_hitNormalWorld.mVec128.m128_f32[0];
    out_closest_hit_fraction[1] = p_world->m_hitNormalWorld.mVec128.m128_f32[1];
    out_closest_hit_fraction[2] = p_world->m_hitNormalWorld.mVec128.m128_f32[2];
    out_closest_hit_fraction[3] = p_world->m_hitNormalWorld.mVec128.m128_f32[3];
    *a9 = m_closestHitFraction;
  }
  return v27 > m_closestHitFraction;
}
