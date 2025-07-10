btRigidBody *__userpurge btRigidBody::btRigidBody@<eax>(
        btRigidBody *this@<ecx>,
        btRigidBody::btRigidBodyConstructionInfo *mass,
        btMotionState *motionState,
        btCollisionShape *collisionShape,
        const btVector3 *localInertia)
{
  btRigidBody::btRigidBodyConstructionInfo constructionInfo; // [esp+B0h] [ebp-A0h] BYREF

  btCollisionObject::btCollisionObject(this, &s_fixed);
  s_fixed.m_constraintRefs.m_data = 0;
  s_fixed.m_constraintRefs.m_size = 0;
  s_fixed.m_constraintRefs.m_capacity = 0;
  s_fixed.__vftable = (btRigidBody_vtbl *)&btRigidBody::`vftable';
  s_fixed.m_constraintRefs.m_ownsMemory = 1;
  btRigidBody::btRigidBodyConstructionInfo::btRigidBodyConstructionInfo(mass, (int)&constructionInfo, 0, 0);
  btRigidBody::setupRigidBody(&s_fixed, &constructionInfo);
  return &s_fixed;
}
