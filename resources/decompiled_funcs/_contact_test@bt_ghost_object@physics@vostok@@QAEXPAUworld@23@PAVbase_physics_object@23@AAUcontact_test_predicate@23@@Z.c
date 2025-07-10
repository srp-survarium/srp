void __thiscall vostok::physics::bt_ghost_object::contact_test(
        vostok::physics::base_physics_object *object,
        vostok::physics::bt_ghost_object *this,
        vostok::physics::world *world,
        vostok::physics::contact_test_predicate *predicate)
{
  btCollisionObject *v4; // eax
  vostok::physics::world_vtbl *v5; // [esp-Ch] [ebp-1Ch]
  btPairCachingGhostObject *m_bt_object; // [esp-8h] [ebp-18h]
  btCollisionWorld::ContactResultCallback resultCallback; // [esp+4h] [ebp-Ch] BYREF
  vostok::physics::contact_test_predicate *v8; // [esp+Ch] [ebp-4h]

  v4 = object->get_bt_collision_obect(object);
  resultCallback.m_collisionFilterGroup = 1;
  resultCallback.m_collisionFilterMask = -1;
  v8 = predicate;
  m_bt_object = this->m_bt_object;
  v5 = world[13].__vftable;
  resultCallback.__vftable = (btCollisionWorld::ContactResultCallback_vtbl *)&vostok::physics::contact_result_callback::`vftable';
  btCollisionWorld::contactPairTest((btCollisionWorld *)v5, m_bt_object, v4, &resultCallback);
}
