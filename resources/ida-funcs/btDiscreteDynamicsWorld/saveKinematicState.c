void __thiscall btDiscreteDynamicsWorld::saveKinematicState(btDiscreteDynamicsWorld *this, float timeStep)
{
  int i; // esi
  btCollisionObject *v4; // edi

  for ( i = 0; i < this->m_collisionObjects.m_size; ++i )
  {
    v4 = this->m_collisionObjects.m_data[i];
    if ( (v4->m_internalType & 2) != 0 && v4->m_activationState1 != 2 && (v4->m_collisionFlags & 2) != 0 )
      btRigidBody::saveKinematicState((btRigidBody *)((unsigned int)v4->m_collisionFlags >> 1), timeStep);
  }
}
