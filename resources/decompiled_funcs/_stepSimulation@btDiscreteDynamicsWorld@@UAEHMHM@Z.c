int __thiscall btDiscreteDynamicsWorld::stepSimulation(
        btDiscreteDynamicsWorld *this,
        float timeStep,
        int maxSubSteps,
        float fixedTimeStep)
{
  const char *v5; // ecx
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  int v8; // edi
  int v9; // ebx
  float v10; // xmm0_4
  btIDebugDraw *v11; // eax
  btClock *v12; // ecx
  CProfileNode *v13; // eax
  bool v14; // zf
  int *p_RecursionCounter; // esi
  CProfileNode *v16; // edi
  unsigned int fixedTimeStepa; // [esp+20h] [ebp+Ch]

  CProfileManager::Reset();
  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "stepSimulation" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node(v5);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  v8 = maxSubSteps;
  v9 = 0;
  if ( maxSubSteps )
  {
    v10 = this->m_localTime + timeStep;
    this->m_localTime = v10;
    if ( v10 >= fixedTimeStep )
    {
      v9 = (int)(float)(v10 / fixedTimeStep);
      this->m_localTime = v10 - (float)((float)v9 * fixedTimeStep);
    }
  }
  else
  {
    fixedTimeStep = timeStep;
    this->m_localTime = timeStep;
    if ( fabsf(timeStep) >= 0.00000011920929 )
    {
      v9 = 1;
      v8 = 1;
    }
    else
    {
      v9 = 0;
      v8 = 0;
    }
  }
  if ( this->getDebugDrawer(this) )
  {
    v11 = this->getDebugDrawer(this);
    gDisableDeactivation = (v11->getDebugMode(v11) & 0x10) != 0;
  }
  if ( v9 )
  {
    if ( v9 <= v8 )
      v8 = v9;
    ((void (__thiscall *)(btDiscreteDynamicsWorld *, _DWORD))this->saveKinematicState)(this, (float)v8 * fixedTimeStep);
    this->applyGravity(this);
    if ( v8 > 0 )
    {
      do
      {
        ((void (__thiscall *)(btDiscreteDynamicsWorld *, _DWORD))this->internalSingleStepSimulation)(
          this,
          LODWORD(fixedTimeStep));
        this->synchronizeMotionStates(this);
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    this->synchronizeMotionStates(this);
  }
  this->clearForces(this);
  v13 = CProfileManager::CurrentNode;
  ++CProfileManager::FrameCounter;
  v14 = CProfileManager::CurrentNode->RecursionCounter-- == 1;
  p_RecursionCounter = &v13->RecursionCounter;
  v16 = v13;
  if ( v14 && v13->TotalCalls )
  {
    fixedTimeStepa = btClock::getTimeMicroseconds(v12) - v13->StartTime;
    v13 = CProfileManager::CurrentNode;
    v16->TotalTime = (double)fixedTimeStepa * 0.001 + v16->TotalTime;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = v13->Parent;
  return v9;
}
