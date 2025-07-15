void __thiscall btCollisionWorld::updateAabbs(btCollisionWorld *this)
{
  CProfileNode *Sub_Node; // eax
  btClock *RecursionCounter; // ecx
  int v4; // ebx
  btCollisionObject *v5; // edi
  int m_activationState1; // eax
  bool v7; // zf
  int *p_RecursionCounter; // edi
  CProfileNode *v9; // esi
  unsigned int v10; // [esp+Ch] [ebp-4h]

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "updateAabbs" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = (btClock *)Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = (int)&RecursionCounter->m_data + 1;
  if ( !RecursionCounter )
  {
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
    Sub_Node = CProfileManager::CurrentNode;
  }
  v4 = 0;
  if ( this->m_collisionObjects.m_size > 0 )
  {
    do
    {
      v5 = this->m_collisionObjects.m_data[v4];
      if ( this->m_forceUpdateAllAabbs
        || (m_activationState1 = v5->m_activationState1, m_activationState1 != 2) && m_activationState1 != 5 )
      {
        btCollisionWorld::updateSingleAabb(this, v5);
      }
      ++v4;
    }
    while ( v4 < this->m_collisionObjects.m_size );
    Sub_Node = CProfileManager::CurrentNode;
  }
  v7 = Sub_Node->RecursionCounter-- == 1;
  p_RecursionCounter = &Sub_Node->RecursionCounter;
  v9 = Sub_Node;
  if ( v7 && Sub_Node->TotalCalls )
  {
    v10 = btClock::getTimeMicroseconds(RecursionCounter) - Sub_Node->StartTime;
    Sub_Node = CProfileManager::CurrentNode;
    v9->TotalTime = (double)v10 * 0.001 + v9->TotalTime;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = Sub_Node->Parent;
}
