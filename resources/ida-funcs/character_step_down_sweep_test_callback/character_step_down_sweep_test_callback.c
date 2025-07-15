character_step_down_sweep_test_callback *__thiscall character_step_down_sweep_test_callback::character_step_down_sweep_test_callback(
        character_step_down_sweep_test_callback *this,
        character_step_down_sweep_test_callback *world,
        btCollisionWorld *self,
        btCollisionObject *up_vector,
        int *min_slope_dot,
        btIDebugDraw *center,
        int *capsule_radius,
        const float max_contact_height,
        float a9)
{
  float v9; // xmm0_4
  btVector3 v11; // [esp+4h] [ebp-20h] BYREF
  btVector3 v12; // [esp+14h] [ebp-10h] BYREF

  v11.mVec128.m128_f32[0] = QNaN_149;
  v11.mVec128.m128_f32[1] = QNaN_149;
  v11.mVec128.m128_u64[1] = LODWORD(QNaN_149);
  v12.mVec128.m128_f32[0] = QNaN_149;
  v12.mVec128.m128_f32[1] = QNaN_149;
  v12.mVec128.m128_u64[1] = LODWORD(QNaN_149);
  btCollisionWorld::ClosestConvexResultCallback::ClosestConvexResultCallback(world, &v12, &v11);
  world->__vftable = (character_step_down_sweep_test_callback_vtbl *)&character_step_down_sweep_test_callback::`vftable';
  world->m_up_vector = *(const btVector3 *)min_slope_dot;
  world->m_center = *(const btVector3 *)capsule_radius;
  world->m_world = self;
  world->m_self = up_vector;
  LODWORD(world->m_min_slope_dot) = center;
  world->m_collisionFilterGroup = 4;
  world->m_capsule_radius2 = max_contact_height * max_contact_height;
  world->m_max_contact_height = a9;
  v9 = s_bm_current_air_resistance;
  world->m_collisionFilterMask = 2;
  world->m_steep_collision_closest_hit_fraction = v9;
  world->m_has_steep_collision = 0;
  return world;
}
