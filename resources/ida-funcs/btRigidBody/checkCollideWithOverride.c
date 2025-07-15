char __thiscall btRigidBody::checkCollideWithOverride(btRigidBody *this, btRigidBody *co)
{
  int m_size; // esi
  int v4; // eax
  btTypedConstraint **i; // edx

  if ( (co->m_internalType & 2) == 0 )
    return 1;
  m_size = this->m_constraintRefs.m_size;
  v4 = 0;
  if ( m_size <= 0 )
    return 1;
  for ( i = this->m_constraintRefs.m_data; (*i)->m_rbA != co && (*i)->m_rbB != co; ++i )
  {
    if ( ++v4 >= m_size )
      return 1;
  }
  return 0;
}
