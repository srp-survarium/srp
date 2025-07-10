void __userpurge btSoftRigidDynamicsWorld::solveSoftBodiesConstraints(
        btSoftRigidDynamicsWorld *this@<ecx>,
        int a2@<edi>,
        float timeStep)
{
  CProfileNode *v3; // eax
  int RecursionCounter; // ecx
  CProfileNode *v5; // ecx

  v3 = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "solveSoftConstraints" )
  {
    CProfileNode::Get_Sub_Node((const char *)this, "solveSoftConstraints");
    CProfileManager::CurrentNode = v3;
  }
  RecursionCounter = v3->RecursionCounter;
  ++v3->TotalCalls;
  v3->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    v3->StartTime = btClock::getTimeMicroseconds(0);
  if ( *(_DWORD *)(a2 + 276) )
    btSoftBody::solveClusters((const btAlignedObjectArray<btSoftBody *> *)(a2 + 272));
  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(a2 + 416) + 24))(*(float *)(*(_DWORD *)(a2 + 416) + 12) * timeStep);
  if ( CProfileNode::Return(v5) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
