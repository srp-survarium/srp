void __thiscall btDiscreteDynamicsWorld::internalSingleStepSimulation(btDiscreteDynamicsWorld *this, float timeStep)
{
  void (__cdecl *m_internalPreTickCallback)(btDynamicsWorld *, float); // eax
  btDiscreteDynamicsWorld_vtbl *v4; // eax
  btDiscreteDynamicsWorld *v5; // ecx
  btDiscreteDynamicsWorld *v6; // ecx
  void (__cdecl *m_internalTickCallback)(btDynamicsWorld *, float); // eax

  m_internalPreTickCallback = this->m_internalPreTickCallback;
  if ( m_internalPreTickCallback )
    ((void (__cdecl *)(btDiscreteDynamicsWorld *, _DWORD))m_internalPreTickCallback)(this, LODWORD(timeStep));
  ((void (__thiscall *)(btDiscreteDynamicsWorld *, _DWORD))this->predictUnconstraintMotion)(this, LODWORD(timeStep));
  *(_QWORD *)&this->m_dispatchInfo.m_timeStep = LODWORD(timeStep);
  this->m_dispatchInfo.m_debugDraw = this->getDebugDrawer(this);
  this->performDiscreteCollisionDetection(this);
  this->calculateSimulationIslands(this);
  v4 = this->__vftable;
  this->m_solverInfo.m_timeStep = timeStep;
  v4->solveConstraints(this, &this->m_solverInfo);
  ((void (__thiscall *)(btDiscreteDynamicsWorld *, _DWORD))this->integrateTransforms)(this, LODWORD(timeStep));
  btDiscreteDynamicsWorld::updateActions(v5, (int)this, timeStep);
  btDiscreteDynamicsWorld::updateActivationState(v6, *(float *)&this, timeStep);
  m_internalTickCallback = this->m_internalTickCallback;
  if ( m_internalTickCallback )
    ((void (__cdecl *)(btDiscreteDynamicsWorld *, _DWORD))m_internalTickCallback)(this, LODWORD(timeStep));
}
