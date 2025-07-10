void __thiscall btDiscreteDynamicsWorld::calculateSimulationIslands(btDiscreteDynamicsWorld *this)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  int v4; // eax
  btTypedConstraint *v5; // ecx
  btRigidBody *m_rbA; // eax
  btRigidBody *m_rbB; // ecx
  int m_activationState1; // edx
  int v9; // edx
  int m_islandTag1; // ebp
  btUnionFind *p_m_unionFind; // esi
  int v12; // edi
  int v13; // eax
  btClock *v14; // ecx
  CProfileNode *v15; // edi
  bool v16; // zf
  int *p_RecursionCounter; // esi
  int i; // [esp+Ch] [ebp-8h]
  int numConstraints; // [esp+10h] [ebp-4h]

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "calculateSimulationIslands" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  this->m_islandManager->updateActivationState(this->m_islandManager, this, this->m_dispatcher1);
  v4 = 0;
  numConstraints = this->m_constraints.m_size;
  for ( i = 0; i < numConstraints; ++i )
  {
    v5 = this->m_constraints.m_data[v4];
    m_rbA = v5->m_rbA;
    m_rbB = v5->m_rbB;
    if ( m_rbA && (m_rbA->m_collisionFlags & 3) == 0 && m_rbB && (m_rbB->m_collisionFlags & 3) == 0 )
    {
      if ( (m_activationState1 = m_rbA->m_activationState1, m_activationState1 != 2) && m_activationState1 != 5
        || (v9 = m_rbB->m_activationState1, v9 != 2) && v9 != 5 )
      {
        m_islandTag1 = m_rbB->m_islandTag1;
        p_m_unionFind = &this->m_islandManager->m_unionFind;
        v12 = btUnionFind::find(p_m_unionFind, m_rbA->m_islandTag1);
        v13 = btUnionFind::find(p_m_unionFind, m_islandTag1);
        if ( v12 != v13 )
        {
          p_m_unionFind->m_elements.m_data[v12].m_id = v13;
          p_m_unionFind->m_elements.m_data[v13].m_sz += p_m_unionFind->m_elements.m_data[v12].m_sz;
        }
      }
    }
    v4 = i + 1;
  }
  this->m_islandManager->storeIslandActivationState(this->m_islandManager, this);
  v15 = CProfileManager::CurrentNode;
  v16 = CProfileManager::CurrentNode->RecursionCounter-- == 1;
  p_RecursionCounter = &v15->RecursionCounter;
  if ( v16 && v15->TotalCalls )
  {
    v15->TotalTime = (double)(btClock::getTimeMicroseconds(v14) - v15->StartTime) * 0.001 + v15->TotalTime;
    v15 = CProfileManager::CurrentNode;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = v15->Parent;
}
