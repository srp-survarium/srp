void __thiscall btRigidBody::~btRigidBody(btRigidBody *this)
{
  btTypedConstraint **m_data; // eax

  this->__vftable = (btRigidBody_vtbl *)&btRigidBody::`vftable';
  m_data = this->m_constraintRefs.m_data;
  if ( m_data )
  {
    if ( this->m_constraintRefs.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_constraintRefs.m_data = 0;
  }
  this->m_constraintRefs.m_data = 0;
  this->m_constraintRefs.m_size = 0;
  this->m_constraintRefs.m_capacity = 0;
  this->m_constraintRefs.m_ownsMemory = 1;
  this->__vftable = (btRigidBody_vtbl *)&btCollisionObject::`vftable';
}
