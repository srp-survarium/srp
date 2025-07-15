void __thiscall btDiscreteDynamicsWorld::synchronizeMotionStates(btDiscreteDynamicsWorld *this)
{
  CProfileNode *Sub_Node; // eax
  btRigidBody **RecursionCounter; // ecx
  int v4; // ebx
  btCollisionObject *v5; // esi
  btRigidBody *v6; // esi
  int m_activationState1; // eax
  bool v8; // zf
  int *p_RecursionCounter; // edi
  CProfileNode *v10; // esi
  unsigned int v11; // [esp+Ch] [ebp-4h]

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "synchronizeMotionStates" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = (btRigidBody **)Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = (int)RecursionCounter + 1;
  if ( !RecursionCounter )
  {
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
    Sub_Node = CProfileManager::CurrentNode;
  }
  v4 = 0;
  if ( this->m_synchronizeAllMotionStates )
  {
    if ( this->m_collisionObjects.m_size > 0 )
    {
      do
      {
        v5 = this->m_collisionObjects.m_data[v4];
        if ( (v5->m_internalType & 2) != 0 )
          btDiscreteDynamicsWorld::synchronizeSingleMotionState(this, (btRigidBody *)v5);
        ++v4;
      }
      while ( v4 < this->m_collisionObjects.m_size );
LABEL_16:
      Sub_Node = CProfileManager::CurrentNode;
    }
  }
  else if ( this->m_nonStaticRigidBodies.m_size > 0 )
  {
    do
    {
      RecursionCounter = this->m_nonStaticRigidBodies.m_data;
      v6 = RecursionCounter[v4];
      m_activationState1 = v6->m_activationState1;
      if ( m_activationState1 != 2 && m_activationState1 != 5 )
        btDiscreteDynamicsWorld::synchronizeSingleMotionState(this, v6);
      ++v4;
    }
    while ( v4 < this->m_nonStaticRigidBodies.m_size );
    goto LABEL_16;
  }
  v8 = Sub_Node->RecursionCounter-- == 1;
  p_RecursionCounter = &Sub_Node->RecursionCounter;
  v10 = Sub_Node;
  if ( v8 && Sub_Node->TotalCalls )
  {
    v11 = btClock::getTimeMicroseconds((btClock *)RecursionCounter) - Sub_Node->StartTime;
    Sub_Node = CProfileManager::CurrentNode;
    v10->TotalTime = (double)v11 * 0.001 + v10->TotalTime;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = Sub_Node->Parent;
}
