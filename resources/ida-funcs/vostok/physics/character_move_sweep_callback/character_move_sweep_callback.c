void __thiscall vostok::physics::character_move_sweep_callback::character_move_sweep_callback(
        vostok::physics::character_move_sweep_callback *this,
        btCollisionWorld::ClosestConvexResultCallback *world,
        btCollisionObject *self,
        const btVector3 *up_vector,
        float *wall_full_slide_dot,
        const btVector3 *start,
        const btVector3 *move_direction)
{
  int v7; // [esp+0h] [ebp-24h]
  btVector3 v8; // [esp+4h] [ebp-20h] BYREF
  btVector3 v9; // [esp+14h] [ebp-10h] BYREF

  v7 = LODWORD(vostok::physics::bullet_character_controller::ms_wall_full_slide_dot);
  v8.mVec128.m128_f32[0] = QNaN_154;
  v8.mVec128.m128_f32[1] = QNaN_154;
  v8.mVec128.m128_u64[1] = LODWORD(QNaN_154);
  v9.mVec128.m128_f32[0] = QNaN_154;
  v9.mVec128.m128_f32[1] = QNaN_154;
  v9.mVec128.m128_u64[1] = LODWORD(QNaN_154);
  btCollisionWorld::ClosestConvexResultCallback::ClosestConvexResultCallback(world, &v9, &v8);
  world->__vftable = (btCollisionWorld::ClosestConvexResultCallback_vtbl *)&vostok::physics::character_move_sweep_callback::`vftable';
  *(_QWORD *)&world[1].__vftable = move_direction->mVec128.m128_u64[0];
  *(_QWORD *)&world[1].m_collisionFilterGroup = move_direction->mVec128.m128_u64[1];
  world[1].m_convexFromWorld = (btVector3)start->mVec128;
  world[1].m_convexToWorld = *(btVector3 *)wall_full_slide_dot;
  world[1].m_hitNormalWorld.mVec128.m128_i32[0] = (int)up_vector;
  world[1].m_hitNormalWorld.mVec128.m128_i32[1] = (int)self;
  world->m_collisionFilterGroup = 4;
  world->m_collisionFilterMask = 2;
  world[1].m_hitNormalWorld.mVec128.m128_i32[2] = v7;
}
