void __userpurge vostok::physics::bullet_physics_world::contact_pair_test(
        vostok::physics::contact_test_predicate *predicate@<edx>,
        btCollisionObject *second_object@<edi>,
        vostok::physics::bullet_physics_world *this,
        btCollisionObject *first_object)
{
  btSoftRigidDynamicsWorld *m_dynamicsWorld; // [esp-Ch] [ebp-18h]
  vostok::physics::contact_result_callback cb; // [esp+0h] [ebp-Ch] BYREF

  cb.m_collisionFilterGroup = 1;
  cb.m_collisionFilterMask = -1;
  cb.m_predicate = predicate;
  m_dynamicsWorld = this->m_dynamicsWorld;
  cb.__vftable = (vostok::physics::contact_result_callback_vtbl *)&vostok::physics::contact_result_callback::`vftable';
  btCollisionWorld::contactPairTest(second_object, m_dynamicsWorld, first_object, &cb);
}
