void __userpurge btDiscreteDynamicsWorld::solveConstraints(
        btDiscreteDynamicsWorld *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<esi>,
        btContactSolverInfo *solverInfo,
        int a6,
        int a7,
        const btContactSolverInfo *a8)
{
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  int m_size; // esi
  int i; // ecx
  btTypedConstraint **v13; // eax
  int v14; // esi
  int v15; // eax
  btStackAlloc *m_stackAlloc; // ecx
  btIDebugDraw *m_debugDrawer; // eax
  int v18; // edx
  btDispatcher *m_dispatcher1; // ecx
  btConstraintSolver *m_constraintSolver; // eax
  void (__thiscall **p_prepareSolve)(btConstraintSolver *, int, int); // esi
  int v22; // eax
  btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *v23; // ecx
  btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *v24; // ecx
  btClock *v25; // ecx
  CProfileNode *v26; // edi
  int *p_RecursionCounter; // esi
  bool v28; // zf
  btAlignedObjectArray<btTypedConstraint *> sortedConstraints; // [esp+18h] [ebp-70h] BYREF
  btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback solverCallback; // [esp+2Ch] [ebp-5Ch] BYREF
  _UNKNOWN *retaddr; // [esp+88h] [ebp+0h]

  Sub_Node = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "solveConstraints" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  m_size = this->m_constraints.m_size;
  sortedConstraints.m_ownsMemory = 1;
  sortedConstraints.m_data = 0;
  if ( m_size >= 0 )
  {
    if ( m_size > 0 )
    {
      ++gNumAlignedAllocs;
      sortedConstraints.m_ownsMemory = 1;
      sortedConstraints.m_data = (btTypedConstraint **)sAlignedAllocFunc(4 * m_size, 16);
    }
    for ( i = 0; i < m_size; ++i )
    {
      v13 = &sortedConstraints.m_data[i];
      if ( v13 )
        *v13 = 0;
    }
  }
  v14 = 0;
  if ( ((int (__thiscall *)(btDiscreteDynamicsWorld *, int, int, int))this->getNumConstraints)(this, a4, a3, a2) > 0 )
  {
    do
    {
      *((_DWORD *)&solverCallback.m_solverInfo->m_tau + v14) = this->m_constraints.m_data[v14];
      ++v14;
    }
    while ( v14 < this->getNumConstraints(this) );
  }
  if ( *(int *)&sortedConstraints.m_ownsMemory > 1 )
    btAlignedObjectArray<btTypedConstraint *>::quickSortInternal<btSortConstraintOnIslandPredicate>(
      (btAlignedObjectArray<btTypedConstraint *> *)&sortedConstraints.m_data,
      0,
      0,
      *(_DWORD *)&sortedConstraints.m_ownsMemory - 1);
  v15 = this->getNumConstraints(this);
  solverCallback.m_debugDrawer = (btIDebugDraw *)this->m_constraintSolver;
  m_stackAlloc = this->m_stackAlloc;
  solverCallback.m_stackAlloc = v15 != 0 ? (btStackAlloc *)solverCallback.m_solverInfo : 0;
  m_debugDrawer = this->m_debugDrawer;
  solverCallback.m_dispatcher = *(btDispatcher **)&sortedConstraints.m_ownsMemory;
  v18 = this->m_collisionObjects.m_size;
  solverCallback.m_bodies.m_size = (int)m_stackAlloc;
  m_dispatcher1 = this->m_dispatcher1;
  *(_DWORD *)&solverCallback.m_bodies.m_allocator = m_debugDrawer;
  m_constraintSolver = this->m_constraintSolver;
  solverCallback.m_sortedConstraints = (btTypedConstraint **)&`btDiscreteDynamicsWorld::solveConstraints'::`2'::InplaceSolverIslandCallback::`vftable';
  solverCallback.m_numConstraints = (int)a8;
  solverCallback.m_bodies.m_capacity = (int)m_dispatcher1;
  LOBYTE(solverCallback.m_manifolds.m_capacity) = 1;
  memset(&solverCallback.m_bodies.m_ownsMemory, 0, 12);
  LOBYTE(solverCallback.m_constraints.m_capacity) = 1;
  memset(&solverCallback.m_manifolds.m_ownsMemory, 0, 12);
  *(_DWORD *)&solverCallback.m_constraints.m_ownsMemory = 0;
  retaddr = 0;
  sortedConstraints.m_capacity = v18;
  p_prepareSolve = &m_constraintSolver->prepareSolve;
  v22 = m_dispatcher1->getNumManifolds(m_dispatcher1);
  (*p_prepareSolve)(this->m_constraintSolver, sortedConstraints.m_capacity, v22);
  btSimulationIslandManager::buildAndProcessIslands(
    (btSimulationIslandManager *)this->m_dispatcher1,
    this->m_dispatcher1,
    this,
    (btSimulationIslandManager::IslandCallback *)&solverCallback.m_sortedConstraints);
  btDiscreteDynamicsWorld::solveConstraints_::_2_::InplaceSolverIslandCallback::processConstraints(
    v23,
    (int)&solverCallback.m_sortedConstraints);
  this->m_constraintSolver->allSolved(this->m_constraintSolver, a8, this->m_debugDrawer, this->m_stackAlloc);
  `btDiscreteDynamicsWorld::solveConstraints'::`2'::InplaceSolverIslandCallback::~InplaceSolverIslandCallback(
    v24,
    (int)&solverCallback.m_sortedConstraints);
  if ( sortedConstraints.m_data && sortedConstraints.m_ownsMemory )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(sortedConstraints.m_data);
  }
  v26 = CProfileManager::CurrentNode;
  p_RecursionCounter = &CProfileManager::CurrentNode->RecursionCounter;
  sortedConstraints.m_ownsMemory = 1;
  sortedConstraints.m_data = 0;
  v28 = CProfileManager::CurrentNode->RecursionCounter-- == 1;
  if ( v28 && v26->TotalCalls )
  {
    v26->TotalTime = (double)(btClock::getTimeMicroseconds(v25) - v26->StartTime) * 0.001 + v26->TotalTime;
    v26 = CProfileManager::CurrentNode;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = v26->Parent;
}
