void __thiscall btDiscreteDynamicsWorld::addConstraint(
        btDiscreteDynamicsWorld *this,
        btTypedConstraint *constraint,
        bool disableCollisionsBetweenLinkedBodies)
{
  int m_capacity; // ecx
  int m_size; // eax
  int v6; // edi
  int v7; // edx
  int v8; // ecx
  btTypedConstraint **v9; // eax
  btTypedConstraint **m_data; // ecx
  btTypedConstraint **v11; // eax
  btRigidBody *v12; // ecx
  btTypedConstraint **v13; // [esp+8h] [ebp-4h]

  m_capacity = this->m_constraints.m_capacity;
  m_size = this->m_constraints.m_size;
  if ( m_size == m_capacity )
  {
    v6 = m_size ? 2 * m_size : 1;
    if ( m_capacity < v6 )
    {
      if ( v6 )
        v13 = (btTypedConstraint **)btAlignedAllocInternal(4 * v6);
      else
        v13 = 0;
      v7 = this->m_constraints.m_size;
      v8 = 0;
      if ( v7 > 0 )
      {
        v9 = v13;
        do
        {
          if ( v9 )
            *v9 = this->m_constraints.m_data[v8];
          ++v8;
          ++v9;
        }
        while ( v8 < v7 );
      }
      if ( this->m_constraints.m_data )
      {
        if ( this->m_constraints.m_ownsMemory )
          btAlignedFreeInternal(this->m_constraints.m_data);
        this->m_constraints.m_data = 0;
      }
      this->m_constraints.m_ownsMemory = 1;
      this->m_constraints.m_data = v13;
      this->m_constraints.m_capacity = v6;
    }
  }
  m_data = this->m_constraints.m_data;
  v11 = &m_data[this->m_constraints.m_size];
  if ( v11 )
    *v11 = constraint;
  ++this->m_constraints.m_size;
  if ( disableCollisionsBetweenLinkedBodies )
  {
    btRigidBody::addConstraintRef((btRigidBody *)m_data, (int)constraint->m_rbA, constraint);
    btRigidBody::addConstraintRef(v12, (int)constraint->m_rbB, constraint);
  }
}
