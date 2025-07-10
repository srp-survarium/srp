void __usercall btCollisionWorld::performDiscreteCollisionDetection(btCollisionWorld *this@<ecx>, int a2@<edi>)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  const char *v5; // ecx
  CProfileNode *v6; // eax
  int v7; // ecx
  CProfileNode *v8; // ecx
  const char *v9; // ecx
  CProfileNode *Parent; // eax
  btDispatcher *m_dispatcher1; // edi
  CProfileNode *v12; // ecx
  btDispatcher_vtbl *v13; // ebx
  int v14; // eax
  CProfileNode *v15; // ecx

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "performDiscreteCollisionDetection" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  ((void (__thiscall *)(btCollisionWorld *, int))this->updateAabbs)(this, a2);
  v6 = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "calculateOverlappingPairs" )
  {
    v6 = CProfileNode::Get_Sub_Node(v5);
    CProfileManager::CurrentNode = v6;
  }
  v7 = v6->RecursionCounter;
  ++v6->TotalCalls;
  v6->RecursionCounter = v7 + 1;
  if ( !v7 )
    v6->StartTime = btClock::getTimeMicroseconds(0);
  this->m_broadphasePairCache->calculateOverlappingPairs(this->m_broadphasePairCache, this->m_dispatcher1);
  if ( CProfileNode::Return(v8) )
  {
    v9 = (const char *)CProfileManager::CurrentNode;
    Parent = CProfileManager::CurrentNode->Parent;
    CProfileManager::CurrentNode = Parent;
  }
  else
  {
    Parent = CProfileManager::CurrentNode;
  }
  m_dispatcher1 = this->m_dispatcher1;
  if ( Parent->Name != "dispatchAllCollisionPairs" )
  {
    Parent = CProfileNode::Get_Sub_Node(v9);
    CProfileManager::CurrentNode = Parent;
  }
  v12 = (CProfileNode *)Parent->RecursionCounter;
  ++Parent->TotalCalls;
  Parent->RecursionCounter = (int)&v12->Name + 1;
  if ( !v12 )
    Parent->StartTime = btClock::getTimeMicroseconds(0);
  if ( m_dispatcher1 )
  {
    v13 = m_dispatcher1->__vftable;
    v14 = ((int (__thiscall *)(btBroadphaseInterface *, btDispatcherInfo *, btDispatcher *))this->m_broadphasePairCache->getOverlappingPairCache)(
            this->m_broadphasePairCache,
            &this->m_dispatchInfo,
            this->m_dispatcher1);
    ((void (__thiscall *)(btDispatcher *, int))v13->dispatchAllCollisionPairs)(m_dispatcher1, v14);
  }
  if ( CProfileNode::Return(v12) )
  {
    v15 = CProfileManager::CurrentNode;
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
  }
  if ( CProfileNode::Return(v15) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
