const char *__thiscall btTypedConstraint::serialize(
        btTypedConstraint *this,
        float *dataBuffer,
        btSerializer *serializer)
{
  const char *v5; // ebp
  void *v6; // eax
  int v7; // ecx
  double m_dbgDrawSize; // st7
  btRigidBody *m_rbA; // eax
  btRigidBody *m_rbB; // eax
  int i; // ecx

  *(_DWORD *)dataBuffer = serializer->getUniquePointer(serializer, this->m_rbA);
  *((_DWORD *)dataBuffer + 1) = serializer->getUniquePointer(serializer, this->m_rbB);
  v5 = serializer->findNameForPointer(serializer, this);
  v6 = serializer->getUniquePointer(serializer, v5);
  *((_DWORD *)dataBuffer + 2) = v6;
  if ( v6 )
    serializer->serializeName(serializer, v5);
  dataBuffer[3] = *(float *)&this->m_objectType;
  *((_DWORD *)dataBuffer + 6) = this->m_needsFeedback;
  dataBuffer[5] = *(float *)&this->m_userConstraintId;
  dataBuffer[4] = *(float *)&this->m_userConstraintType;
  v7 = 0;
  dataBuffer[7] = this->m_appliedImpulse;
  m_dbgDrawSize = this->m_dbgDrawSize;
  dataBuffer[9] = 0.0;
  dataBuffer[8] = m_dbgDrawSize;
  m_rbA = this->m_rbA;
  if ( m_rbA->m_constraintRefs.m_size > 0 )
  {
    do
    {
      if ( m_rbA->m_constraintRefs.m_data[v7] == this )
        *((_DWORD *)dataBuffer + 9) = 1;
      m_rbA = this->m_rbA;
      ++v7;
    }
    while ( v7 < m_rbA->m_constraintRefs.m_size );
  }
  m_rbB = this->m_rbB;
  for ( i = 0; i < m_rbB->m_constraintRefs.m_size; ++i )
  {
    if ( m_rbB->m_constraintRefs.m_data[i] == this )
      *((_DWORD *)dataBuffer + 9) = 1;
    m_rbB = this->m_rbB;
  }
  return "btTypedConstraintData";
}
