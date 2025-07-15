void __userpurge btDiscreteDynamicsWorld::updateActions(
        btDiscreteDynamicsWorld *this@<ecx>,
        int a2@<eax>,
        float timeStep)
{
  CProfileNode *Sub_Node; // eax
  btClock *RecursionCounter; // ecx
  int v6; // esi
  bool v7; // zf
  int *p_RecursionCounter; // edi
  CProfileNode *v9; // esi
  unsigned int timeStepa; // [esp+10h] [ebp+4h]

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "updateActions" )
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
  v6 = 0;
  if ( *(int *)(a2 + 252) > 0 )
  {
    do
      (*(void (__stdcall **)(int, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 260) + 4 * v6++) + 4))(a2, LODWORD(timeStep));
    while ( v6 < *(_DWORD *)(a2 + 252) );
    Sub_Node = CProfileManager::CurrentNode;
  }
  v7 = Sub_Node->RecursionCounter-- == 1;
  p_RecursionCounter = &Sub_Node->RecursionCounter;
  v9 = Sub_Node;
  if ( v7 && Sub_Node->TotalCalls )
  {
    timeStepa = btClock::getTimeMicroseconds(RecursionCounter) - Sub_Node->StartTime;
    Sub_Node = CProfileManager::CurrentNode;
    v9->TotalTime = (double)timeStepa * 0.001 + v9->TotalTime;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = Sub_Node->Parent;
}
