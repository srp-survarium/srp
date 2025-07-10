void __usercall btRigidBody::btRigidBody(
        btRigidBody *this@<eax>,
        const btRigidBody::btRigidBodyConstructionInfo *constructionInfo@<edi>,
        btCollisionObject *a3@<ecx>)
{
  btCollisionObject::btCollisionObject(a3, this);
  this->__vftable = (btRigidBody_vtbl *)&btRigidBody::`vftable';
  this->m_constraintRefs.m_ownsMemory = 1;
  this->m_constraintRefs.m_data = 0;
  this->m_constraintRefs.m_size = 0;
  this->m_constraintRefs.m_capacity = 0;
  btRigidBody::setupRigidBody(this, constructionInfo);
}
