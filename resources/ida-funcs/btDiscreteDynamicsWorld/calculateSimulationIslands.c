void __thiscall btDiscreteDynamicsWorld::calculateSimulationIslands(btDiscreteDynamicsWorld *this)
{
  int v2; // ebx
  btTypedConstraint *v3; // eax
  btRigidBody *m_rbA; // ecx
  btRigidBody *m_rbB; // eax
  int m_activationState1; // edx
  int v7; // edx
  int m_size; // [esp+8h] [ebp-4h]

  this->m_islandManager->updateActivationState(this->m_islandManager, this, this->m_dispatcher1);
  v2 = 0;
  m_size = this->m_constraints.m_size;
  if ( m_size > 0 )
  {
    do
    {
      v3 = this->m_constraints.m_data[v2];
      m_rbA = v3->m_rbA;
      m_rbB = v3->m_rbB;
      if ( m_rbA && (m_rbA->m_collisionFlags & 3) == 0 && m_rbB && (m_rbB->m_collisionFlags & 3) == 0 )
      {
        if ( (m_activationState1 = m_rbA->m_activationState1, m_activationState1 != 2) && m_activationState1 != 5
          || (v7 = m_rbB->m_activationState1, v7 != 2) && v7 != 5 )
        {
          btUnionFind::unite(&this->m_islandManager->m_unionFind, m_rbA->m_islandTag1, m_rbB->m_islandTag1);
        }
      }
      ++v2;
    }
    while ( v2 < m_size );
  }
  this->m_islandManager->storeIslandActivationState(this->m_islandManager, this);
}
