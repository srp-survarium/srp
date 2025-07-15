void __thiscall btDiscreteDynamicsWorld::addConstraint(
        btDiscreteDynamicsWorld *this,
        btTypedConstraint *constraint,
        bool disableCollisionsBetweenLinkedBodies)
{
  int m_capacity; // ecx
  int m_size; // eax
  int v6; // edi
  btTypedConstraint **v7; // ebp
  int v8; // edx
  int v9; // eax
  btTypedConstraint **v10; // ecx
  btTypedConstraint **m_data; // eax
  int v12; // ecx
  btTypedConstraint **v13; // eax
  btRigidBody *v14; // ecx

  m_capacity = this->m_constraints.m_capacity;
  m_size = this->m_constraints.m_size;
  if ( m_size == m_capacity )
  {
    v6 = 2 * m_size;
    if ( !m_size )
      v6 = 1;
    if ( m_capacity < v6 )
    {
      if ( v6 )
      {
        ++gNumAlignedAllocs;
        v7 = (btTypedConstraint **)sAlignedAllocFunc(4 * v6, 16);
      }
      else
      {
        v7 = 0;
      }
      v8 = this->m_constraints.m_size;
      v9 = 0;
      if ( v8 > 0 )
      {
        v10 = v7;
        do
        {
          if ( v10 )
            *v10 = this->m_constraints.m_data[v9];
          ++v9;
          ++v10;
        }
        while ( v9 < v8 );
      }
      m_data = this->m_constraints.m_data;
      if ( m_data )
      {
        if ( this->m_constraints.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        this->m_constraints.m_data = 0;
      }
      this->m_constraints.m_data = v7;
      this->m_constraints.m_ownsMemory = 1;
      this->m_constraints.m_capacity = v6;
    }
  }
  v12 = this->m_constraints.m_size;
  v13 = &this->m_constraints.m_data[v12];
  if ( v13 )
    *v13 = constraint;
  ++this->m_constraints.m_size;
  if ( disableCollisionsBetweenLinkedBodies )
  {
    btRigidBody::addConstraintRef((btRigidBody *)v12, constraint);
    btRigidBody::addConstraintRef(v14, constraint);
  }
}
