void __userpurge vostok::physics::bt_closest_convex_not_me_result_callback::bt_closest_convex_not_me_result_callback(
        vostok::physics::bt_closest_convex_not_me_result_callback *this@<ecx>,
        btCollisionWorld::ClosestConvexResultCallback *a2@<esi>,
        btCollisionWorld::ClosestConvexResultCallback_vtbl *self,
        unsigned __int16 collision_filter_group,
        unsigned __int16 collision_filter_mask)
{
  btVector3 v5; // [esp+0h] [ebp-20h] BYREF
  btVector3 v6; // [esp+10h] [ebp-10h] BYREF

  memset(&v5, 0, sizeof(v5));
  memset(&v6, 0, sizeof(v6));
  btCollisionWorld::ClosestConvexResultCallback::ClosestConvexResultCallback(a2, &v6, &v5);
  a2[1].__vftable = self;
  a2->m_collisionFilterGroup = 4;
  a2->m_collisionFilterMask = 2;
  a2->__vftable = (btCollisionWorld::ClosestConvexResultCallback_vtbl *)&vostok::physics::bt_closest_convex_not_me_result_callback::`vftable';
}
