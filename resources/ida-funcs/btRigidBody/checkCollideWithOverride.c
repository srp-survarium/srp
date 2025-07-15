char __thiscall btRigidBody::checkCollideWithOverride(btRigidBody *this, btCollisionObject *co)
{
  btCollisionObject *v2; // eax
  int m_size; // esi
  int v5; // edi
  btTypedConstraint **i; // edx

  v2 = (co->m_internalType & 2) != 0 ? co : 0;
  if ( !v2 )
    return 1;
  m_size = this->m_constraintRefs.m_size;
  v5 = 0;
  if ( m_size <= 0 )
    return 1;
  for ( i = this->m_constraintRefs.m_data; (*i)->m_rbA != v2 && (*i)->m_rbB != v2; ++i )
  {
    if ( ++v5 >= m_size )
      return 1;
  }
  return 0;
}
