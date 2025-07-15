void __thiscall btDiscreteDynamicsWorld::internalSingleStepSimulation(btDiscreteDynamicsWorld *this, float timeStep)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  void (__cdecl *m_internalPreTickCallback)(btDynamicsWorld *, float); // eax
  void (__thiscall *solveConstraints)(btDiscreteDynamicsWorld *, btContactSolverInfo *); // edx
  btDiscreteDynamicsWorld *v7; // ecx
  btDiscreteDynamicsWorld *v8; // ecx
  CProfileNode *v9; // ecx
  void (__cdecl *m_internalTickCallback)(btDynamicsWorld *, float); // eax

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "internalSingleStepSimulation" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  m_internalPreTickCallback = this->m_internalPreTickCallback;
  if ( m_internalPreTickCallback )
    ((void (__cdecl *)(btDiscreteDynamicsWorld *, _DWORD))m_internalPreTickCallback)(this, LODWORD(timeStep));
  ((void (__thiscall *)(btDiscreteDynamicsWorld *, _DWORD))this->predictUnconstraintMotion)(this, LODWORD(timeStep));
  *(_QWORD *)&this->m_dispatchInfo.m_timeStep = LODWORD(timeStep);
  this->m_dispatchInfo.m_debugDraw = this->getDebugDrawer(this);
  this->performDiscreteCollisionDetection(this);
  this->calculateSimulationIslands(this);
  solveConstraints = this->solveConstraints;
  this->m_solverInfo.m_timeStep = timeStep;
  solveConstraints(this, &this->m_solverInfo);
  ((void (__thiscall *)(btDiscreteDynamicsWorld *, _DWORD))this->integrateTransforms)(this, LODWORD(timeStep));
  btDiscreteDynamicsWorld::updateActions(v7, (int)this, timeStep);
  btDiscreteDynamicsWorld::updateActivationState(v8, *(float *)&this, timeStep);
  m_internalTickCallback = this->m_internalTickCallback;
  if ( m_internalTickCallback )
    ((void (__cdecl *)(btDiscreteDynamicsWorld *, _DWORD))m_internalTickCallback)(this, LODWORD(timeStep));
  if ( CProfileNode::Return(v9) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
