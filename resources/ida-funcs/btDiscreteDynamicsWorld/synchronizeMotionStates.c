void __thiscall btDiscreteDynamicsWorld::synchronizeMotionStates(btDiscreteDynamicsWorld *this)
{
  int v2; // edi
  btCollisionObject *v3; // ecx
  btCollisionObject *v4; // eax
  int v5; // ecx
  btRigidBody *v6; // eax
  int m_activationState1; // ecx
  btMotionState *m_optionalMotionState; // ecx

  v2 = 0;
  if ( this->m_synchronizeAllMotionStates )
  {
    if ( this->m_collisionObjects.m_size > 0 )
    {
      do
      {
        v3 = this->m_collisionObjects.m_data[v2];
        v4 = (v3->m_internalType & 2) != 0 ? v3 : 0;
        if ( v4 )
        {
          v5 = *((v3->m_internalType & 2) != 0 ? &v3[1].m_activationState1 : (int *)500);
          if ( v5 )
          {
            if ( (v4->m_collisionFlags & 3) == 0 )
              (*(void (__thiscall **)(int, btTransform *))(*(_DWORD *)v5 + 8))(v5, &v4->m_worldTransform);
          }
        }
        ++v2;
      }
      while ( v2 < this->m_collisionObjects.m_size );
    }
  }
  else if ( this->m_nonStaticRigidBodies.m_size > 0 )
  {
    do
    {
      v6 = this->m_nonStaticRigidBodies.m_data[v2];
      m_activationState1 = v6->m_activationState1;
      if ( m_activationState1 != 2 && m_activationState1 != 5 )
      {
        m_optionalMotionState = v6->m_optionalMotionState;
        if ( m_optionalMotionState )
        {
          if ( (v6->m_collisionFlags & 3) == 0 )
            m_optionalMotionState->setWorldTransform(m_optionalMotionState, &v6->m_worldTransform);
        }
      }
      ++v2;
    }
    while ( v2 < this->m_nonStaticRigidBodies.m_size );
  }
}
