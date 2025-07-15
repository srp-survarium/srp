void __thiscall vostok::physics::character_up_sweep_test_callback::character_up_sweep_test_callback(
        vostok::physics::character_up_sweep_test_callback *this,
        btCollisionWorld::ClosestConvexResultCallback *self,
        const btVector3 *up_vector,
        const btVector3 *center,
        const float capsule_radius,
        float min_contact_height,
        int a7)
{
  btVector3 v7; // [esp+4h] [ebp-20h] BYREF
  btVector3 v8; // [esp+14h] [ebp-10h] BYREF

  memset(&v7, 0, sizeof(v7));
  memset(&v8, 0, sizeof(v8));
  btCollisionWorld::ClosestConvexResultCallback::ClosestConvexResultCallback(self, &v8, &v7);
  self->__vftable = (btCollisionWorld::ClosestConvexResultCallback_vtbl *)&vostok::physics::character_up_sweep_test_callback::`vftable';
  *(_QWORD *)&self[1].__vftable = center->mVec128.m128_u64[0];
  *(_QWORD *)&self[1].m_collisionFilterGroup = center->mVec128.m128_u64[1];
  self[1].m_convexFromWorld = *(btVector3 *)capsule_radius;
  self[1].m_convexToWorld.mVec128.m128_i32[0] = (int)up_vector;
  self->m_collisionFilterGroup = 4;
  self[1].m_convexToWorld.mVec128.m128_f32[1] = min_contact_height;
  self->m_collisionFilterMask = 2;
  self[1].m_convexToWorld.mVec128.m128_i32[2] = a7;
}
