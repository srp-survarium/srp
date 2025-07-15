void __thiscall btDiscreteDynamicsWorld::saveKinematicState(btDiscreteDynamicsWorld *this, float timeStep)
{
  int i; // edi
  btCollisionObject *v4; // ecx
  float v5; // eax
  btRigidBody *v6; // ecx

  for ( i = 0; i < this->m_collisionObjects.m_size; ++i )
  {
    v4 = this->m_collisionObjects.m_data[i];
    LODWORD(v5) = (v4->m_internalType & 2) != 0 ? v4 : 0;
    if ( v5 != 0.0 && *((v4->m_internalType & 2) != 0 ? &v4->m_activationState1 : (int *)228) != 2 )
    {
      v6 = (btRigidBody *)((unsigned int)*((v4->m_internalType & 2) != 0 ? &v4->m_collisionFlags : (int *)216) >> 1);
      if ( (*(_DWORD *)(LODWORD(v5) + 216) & 2) != 0 )
        btRigidBody::saveKinematicState(v6, v5, timeStep);
    }
  }
}
