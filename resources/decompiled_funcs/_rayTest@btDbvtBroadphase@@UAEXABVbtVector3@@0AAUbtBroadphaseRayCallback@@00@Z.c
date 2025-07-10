void __thiscall btDbvtBroadphase::rayTest(
        btDbvtBroadphase *this,
        const btDbvtNode *rayFrom,
        const btVector3 *rayTo,
        btBroadphaseRayCallback *rayCallback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  CProfileNode *Sub_Node; // eax
  bool v7; // zf
  CProfileNode *RecursionCounter; // ecx
  btDbvtNode *m_root; // eax
  const btDbvtNode *v11; // eax
  BroadphaseRayTester callback; // [esp+20h] [ebp-8h] BYREF
  btDbvtBroadphase *v13; // [esp+24h] [ebp-4h]

  Sub_Node = CProfileManager::CurrentNode;
  v7 = CProfileManager::CurrentNode->Name == "btDbvtBroadphase::rayTest";
  v13 = this;
  if ( !v7 )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = (CProfileNode *)Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = (int)&RecursionCounter->Name + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  m_root = this->m_sets[0].m_root;
  callback.m_rayCallback = rayCallback;
  if ( m_root )
    btDbvt::rayTestInternal<BroadphaseRayTester>(
      (const btDbvtNode *)&rayCallback->m_rayDirectionInverse,
      m_root,
      &rayFrom->volume.mi,
      &rayCallback->m_rayDirectionInverse,
      rayCallback->m_signs,
      rayCallback->m_lambda_max,
      aabbMin,
      aabbMax,
      &callback);
  v11 = v13->m_sets[1].m_root;
  if ( v11 )
    btDbvt::rayTestInternal<BroadphaseRayTester>(
      rayFrom,
      v11,
      &rayFrom->volume.mi,
      &rayCallback->m_rayDirectionInverse,
      rayCallback->m_signs,
      rayCallback->m_lambda_max,
      aabbMin,
      aabbMax,
      &callback);
  if ( CProfileNode::Return(RecursionCounter) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
