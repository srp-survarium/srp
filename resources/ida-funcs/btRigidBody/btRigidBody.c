btRigidBody *__userpurge btRigidBody::btRigidBody@<eax>(
        btRigidBody *this@<ecx>,
        btRigidBody *a2@<eax>,
        float a3@<xmm4>,
        const btRigidBody::btRigidBodyConstructionInfo *constructionInfo)
{
  btCollisionObject::btCollisionObject(this, (int)a2);
  a2->__vftable = (btRigidBody_vtbl *)&btRigidBody::`vftable';
  a2->m_constraintRefs.m_ownsMemory = 1;
  a2->m_constraintRefs.m_data = 0;
  a2->m_constraintRefs.m_size = 0;
  a2->m_constraintRefs.m_capacity = 0;
  btRigidBody::setupRigidBody(0, a3, a2, (int)constructionInfo);
  return a2;
}


btRigidBody *__userpurge btRigidBody::btRigidBody@<eax>(
        btRigidBody *this@<ecx>,
        float a2@<xmm4>,
        btRigidBody::btRigidBodyConstructionInfo *mass,
        btMotionState *motionState,
        btCollisionShape *collisionShape,
        const btVector3 *localInertia)
{
  btRigidBody *v6; // ecx
  struct btMotionState *v8; // [esp+0h] [ebp-B0h]
  struct btCollisionShape *v9; // [esp+4h] [ebp-ACh]
  const struct btVector3 *v10; // [esp+8h] [ebp-A8h]
  _DWORD v11[40]; // [esp+10h] [ebp-A0h] BYREF

  btCollisionObject::btCollisionObject(this, (int)&s_fixed);
  s_fixed.m_constraintRefs.m_data = 0;
  s_fixed.m_constraintRefs.m_size = 0;
  s_fixed.m_constraintRefs.m_capacity = 0;
  s_fixed.__vftable = (btRigidBody_vtbl *)&btRigidBody::`vftable';
  s_fixed.m_constraintRefs.m_ownsMemory = 1;
  btRigidBody::btRigidBodyConstructionInfo::btRigidBodyConstructionInfo(mass, 0, 0, v11, v8, v9, v10);
  btRigidBody::setupRigidBody(v6, a2, &s_fixed, (int)v11);
  return &s_fixed;
}
