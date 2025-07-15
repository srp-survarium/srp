void __thiscall vostok::physics::character_move_test_callback::character_move_test_callback(
        vostok::physics::character_move_test_callback *this,
        btCollisionWorld::ClosestConvexResultCallback *self,
        const btVector3 *up_vector,
        btCollisionWorld::ClosestConvexResultCallback_vtbl **minSlopeDot,
        int a5)
{
  btVector3 v5; // [esp+4h] [ebp-20h] BYREF
  btVector3 v6; // [esp+14h] [ebp-10h] BYREF

  memset(&v5, 0, sizeof(v5));
  memset(&v6, 0, sizeof(v6));
  btCollisionWorld::ClosestConvexResultCallback::ClosestConvexResultCallback(self, &v6, &v5);
  self->__vftable = (btCollisionWorld::ClosestConvexResultCallback_vtbl *)&vostok::physics::character_move_test_callback::`vftable';
  self[1].__vftable = *minSlopeDot;
  LODWORD(self[1].m_closestHitFraction) = minSlopeDot[1];
  *(_DWORD *)&self[1].m_collisionFilterGroup = minSlopeDot[2];
  *((_DWORD *)&self[1].btCollisionWorld::ConvexResultCallback + 3) = minSlopeDot[3];
  self[1].m_convexFromWorld.mVec128.m128_i32[0] = (int)up_vector;
  self->m_collisionFilterGroup = 4;
  self->m_collisionFilterMask = 2;
  self[1].m_convexFromWorld.mVec128.m128_i32[1] = a5;
}
