void __thiscall btSoftRigidDynamicsWorld::predictUnconstraintMotion(btSoftRigidDynamicsWorld *this, float timeStep)
{
  const char *v3; // ecx
  CProfileNode *v4; // eax
  int RecursionCounter; // ecx
  CProfileNode *v6; // ecx

  btDiscreteDynamicsWorld::predictUnconstraintMotion(this, timeStep);
  v4 = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "predictUnconstraintMotionSoftBody" )
  {
    CProfileNode::Get_Sub_Node(v3, "predictUnconstraintMotionSoftBody");
    CProfileManager::CurrentNode = v4;
  }
  RecursionCounter = v4->RecursionCounter;
  ++v4->TotalCalls;
  v4->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    v4->StartTime = btClock::getTimeMicroseconds(0);
  ((void (__stdcall *)(_DWORD))this->m_softBodySolver->predictMotion)(LODWORD(timeStep));
  if ( CProfileNode::Return(v6) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
