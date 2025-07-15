bool __thiscall vostok::physics::old_bullet_character_controller::convex_sweep_test(
        vostok::physics::old_bullet_character_controller *this,
        const btTransform *start,
        const btTransform *finish,
        btCollisionWorld::ConvexResultCallback *up_vector,
        unsigned __int64 *max_slope_angle_cos,
        int max_allowed_penetration,
        btVector3 *out_hit_point_world,
        btVector3 *out_hit_normal_world,
        float *out_closest_hit_fraction,
        float *a10)
{
  vostok::physics::old_bullet_character_controller::sweep_test_cache_item **v10; // esi
  vostok::physics::old_bullet_character_controller::sweep_test_cache_item **v11; // eax
  vostok::physics::old_bullet_character_controller::sweep_test_cache_item *v12; // eax
  int *p_m_hit_point_world; // esi
  btCollisionWorld *v14; // ecx
  float v15; // xmm1_4
  btVector3 *p_m_hitNormalWorld; // esi
  int *v17; // esi
  btVector3 *p_m_hitPointWorld; // esi
  int *v19; // esi
  int *v20; // esi
  vostok::physics::character_move_test_callback *v22; // [esp+0h] [ebp-F4h]
  bool v23; // [esp+13h] [ebp-E1h]
  int v24; // [esp+14h] [ebp-E0h] BYREF
  float v25; // [esp+18h] [ebp-DCh]
  int v26; // [esp+1Ch] [ebp-D8h]
  int v27; // [esp+20h] [ebp-D4h]
  btVector3 __pred[5]; // [esp+24h] [ebp-D0h] BYREF
  btCollisionWorld::ClosestConvexResultCallback v29; // [esp+74h] [ebp-80h] BYREF

  ++start[77].m_basis.m_el[2].mVec128.m128_i32[0];
  __pred[0] = finish->m_origin;
  __pred[1].mVec128.m128_u64[0] = *(_QWORD *)&up_vector[4].__vftable;
  __pred[1].mVec128.m128_u64[1] = *(_QWORD *)&up_vector[4].m_collisionFilterGroup;
  __pred[2].mVec128.m128_u64[0] = *max_slope_angle_cos;
  __pred[2].mVec128.m128_u64[1] = max_slope_angle_cos[1];
  __pred[4].mVec128.m128_i32[0] = max_allowed_penetration;
  __pred[4].mVec128.m128_i32[1] = start[8].m_basis.m_el[0].mVec128.m128_i32[start[8].m_basis.m_el[2].mVec128.m128_i32[0]];
  __pred[3] = start[8].m_basis.m_el[0];
  v10 = (vostok::physics::old_bullet_character_controller::sweep_test_cache_item **)start[74].m_basis.m_el[1].mVec128.m128_i32[1];
  v11 = stlp_std::priv::__find_if<vostok::physics::old_bullet_character_controller::sweep_test_cache_item * *,vostok::physics::sweep_test_cache_predicate>(
          (vostok::physics::old_bullet_character_controller::sweep_test_cache_item **)start[74].m_basis.m_el[1].mVec128.m128_i32[0],
          v10,
          (vostok::physics::sweep_test_cache_predicate)__pred);
  if ( v11 == v10 )
  {
    vostok::physics::character_move_test_callback::character_move_test_callback(
      v22,
      &v29,
      &start[2].m_basis.m_el[2],
      (btCollisionWorld::ClosestConvexResultCallback_vtbl **)&__pred[2],
      max_allowed_penetration);
    btCollisionWorld::convexSweepTest(
      v14,
      (const btCollisionWorld *)start->m_basis.m_el[1].mVec128.m128_i32[1],
      (btConvexShape *)&start[7].m_basis.m_el[2],
      finish,
      up_vector,
      &v29,
      *(float *)&out_hit_point_world);
    v15 = s_bm_current_air_resistance;
    v23 = s_bm_current_air_resistance > v29.m_closestHitFraction;
    v12 = *(vostok::physics::old_bullet_character_controller::sweep_test_cache_item **)(start[74].m_basis.m_el[1].mVec128.m128_i32[0]
                                                                                      + 4
                                                                                      * start[77].m_basis.m_el[2].mVec128.m128_i32[2]);
    qmemcpy(v12, __pred, 0x50u);
    v12->m_closest_hit_fraction = v29.m_closestHitFraction;
    v12->m_has_hit = v15 > v29.m_closestHitFraction;
    if ( v23 )
    {
      p_m_hitNormalWorld = &v29.m_hitNormalWorld;
    }
    else
    {
      v24 = 0;
      v25 = v15;
      v26 = 0;
      v27 = 0;
      p_m_hitNormalWorld = (btVector3 *)&v24;
    }
    v12->m_hit_normal_world.mVec128.m128_i32[0] = p_m_hitNormalWorld->mVec128.m128_i32[0];
    v17 = &p_m_hitNormalWorld->mVec128.m128_i32[1];
    v12->m_hit_normal_world.mVec128.m128_i32[1] = *v17++;
    v12->m_hit_normal_world.mVec128.m128_i32[2] = *v17;
    v12->m_hit_normal_world.mVec128.m128_i32[3] = v17[1];
    if ( v23 )
    {
      p_m_hitPointWorld = &v29.m_hitPointWorld;
    }
    else
    {
      v24 = 0;
      v25 = v15;
      v26 = 0;
      v27 = 0;
      p_m_hitPointWorld = (btVector3 *)&v24;
    }
    v12->m_hit_point_world.mVec128.m128_i32[0] = p_m_hitPointWorld->mVec128.m128_i32[0];
    v19 = &p_m_hitPointWorld->mVec128.m128_i32[1];
    v12->m_hit_point_world.mVec128.m128_i32[1] = *v19++;
    v12->m_hit_point_world.mVec128.m128_i32[2] = *v19;
    v12->m_hit_point_world.mVec128.m128_i32[3] = v19[1];
    v12->m_valid = 1;
    start[77].m_basis.m_el[2].mVec128.m128_i32[2] = ((unsigned __int8)start[77].m_basis.m_el[2].mVec128.m128_i32[2] + 1)
                                                  & 0x1F;
    *a10 = v12->m_closest_hit_fraction;
    *out_closest_hit_fraction = v12->m_hit_normal_world.mVec128.m128_f32[0];
    out_closest_hit_fraction[1] = v12->m_hit_normal_world.mVec128.m128_f32[1];
    out_closest_hit_fraction[2] = v12->m_hit_normal_world.mVec128.m128_f32[2];
    out_closest_hit_fraction[3] = v12->m_hit_normal_world.mVec128.m128_f32[3];
    p_m_hit_point_world = (int *)&v12->m_hit_point_world;
  }
  else
  {
    ++start[77].m_basis.m_el[2].mVec128.m128_i32[1];
    v12 = *v11;
    *a10 = v12->m_closest_hit_fraction;
    *out_closest_hit_fraction = v12->m_hit_normal_world.mVec128.m128_f32[0];
    out_closest_hit_fraction[1] = v12->m_hit_normal_world.mVec128.m128_f32[1];
    out_closest_hit_fraction[2] = v12->m_hit_normal_world.mVec128.m128_f32[2];
    out_closest_hit_fraction[3] = v12->m_hit_normal_world.mVec128.m128_f32[3];
    p_m_hit_point_world = (int *)&v12->m_hit_point_world;
  }
  out_hit_normal_world->mVec128.m128_i32[0] = *p_m_hit_point_world;
  v20 = p_m_hit_point_world + 1;
  out_hit_normal_world->mVec128.m128_i32[1] = *v20;
  out_hit_normal_world->mVec128.m128_u64[1] = *(_QWORD *)(v20 + 1);
  return v12->m_has_hit;
}
