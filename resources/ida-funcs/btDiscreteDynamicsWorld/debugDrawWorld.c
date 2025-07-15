void __usercall btDiscreteDynamicsWorld::debugDrawWorld(btDiscreteDynamicsWorld *this@<ecx>, double a2@<st1>)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  btIDebugDraw *v5; // eax
  int i; // esi
  btTypedConstraint *v7; // eax
  btClock *v8; // ecx
  btIDebugDraw *v9; // eax
  btIDebugDraw *v10; // eax
  int j; // esi
  btActionInterface *v12; // ecx
  CProfileNode *v13; // esi
  bool v14; // zf
  int *p_RecursionCounter; // edi

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "debugDrawWorld" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  btCollisionWorld::debugDrawWorld(this);
  if ( this->getDebugDrawer(this) )
  {
    v5 = this->getDebugDrawer(this);
    if ( (v5->getDebugMode(v5) & 0x1800) != 0 )
    {
      for ( i = this->getNumConstraints(this) - 1; i >= 0; --i )
      {
        v7 = this->getConstraint(this, i);
        btDiscreteDynamicsWorld::debugDrawConstraint(this, v7, a2);
      }
    }
  }
  if ( this->getDebugDrawer(this) )
  {
    v9 = this->getDebugDrawer(this);
    if ( (v9->getDebugMode(v9) & 3) != 0 )
    {
      if ( this->getDebugDrawer(this) )
      {
        v10 = this->getDebugDrawer(this);
        if ( v10->getDebugMode(v10) )
        {
          for ( j = 0; j < this->m_actions.m_size; ++j )
          {
            v12 = this->m_actions.m_data[j];
            v12->debugDraw(v12, this->m_debugDrawer);
          }
        }
      }
    }
  }
  v13 = CProfileManager::CurrentNode;
  v14 = CProfileManager::CurrentNode->RecursionCounter-- == 1;
  p_RecursionCounter = &v13->RecursionCounter;
  if ( v14 && v13->TotalCalls )
  {
    v13->TotalTime = (double)(btClock::getTimeMicroseconds(v8) - v13->StartTime) * 0.001 + v13->TotalTime;
    v13 = CProfileManager::CurrentNode;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = v13->Parent;
}
