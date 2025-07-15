void __thiscall btDiscreteDynamicsWorld::solveConstraints(
        btDiscreteDynamicsWorld *this,
        btContactSolverInfo *solverInfo)
{
  int m_size; // edi
  int i; // ecx
  btTypedConstraint **v5; // eax
  btDiscreteDynamicsWorld_vtbl *v6; // eax
  int v7; // edi
  int v8; // eax
  btDispatcher *m_dispatcher1; // ecx
  btConstraintSolver *v11; // eax
  void (__thiscall **p_prepareSolve)(btConstraintSolver *, int, int); // esi
  int v13; // eax
  btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *v14; // ecx
  btAlignedObjectArray<GrahamVector2> *v15; // ecx
  btAlignedObjectArray<GrahamVector2> *v16; // ecx
  btAlignedObjectArray<GrahamVector2> *v17; // ecx
  btAlignedObjectArray<GrahamVector2> *v18; // ecx
  btSimulationIslandManager::IslandCallback callback; // [esp+Ch] [ebp-78h] BYREF
  btContactSolverInfo *v20; // [esp+10h] [ebp-74h]
  btConstraintSolver *m_constraintSolver; // [esp+14h] [ebp-70h]
  btTypedConstraint **v22; // [esp+18h] [ebp-6Ch]
  int v23; // [esp+1Ch] [ebp-68h]
  btIDebugDraw *m_debugDrawer; // [esp+20h] [ebp-64h]
  btStackAlloc *m_stackAlloc; // [esp+24h] [ebp-60h]
  btDispatcher *v26; // [esp+28h] [ebp-5Ch]
  _BYTE v27[4]; // [esp+2Ch] [ebp-58h] BYREF
  int v28; // [esp+30h] [ebp-54h]
  int v29; // [esp+34h] [ebp-50h]
  int v30; // [esp+38h] [ebp-4Ch]
  char v31; // [esp+3Ch] [ebp-48h]
  _BYTE v32[4]; // [esp+40h] [ebp-44h] BYREF
  int v33; // [esp+44h] [ebp-40h]
  int v34; // [esp+48h] [ebp-3Ch]
  int v35; // [esp+4Ch] [ebp-38h]
  char v36; // [esp+50h] [ebp-34h]
  _BYTE v37[4]; // [esp+54h] [ebp-30h] BYREF
  int v38; // [esp+58h] [ebp-2Ch]
  int v39; // [esp+5Ch] [ebp-28h]
  int v40; // [esp+60h] [ebp-24h]
  char v41; // [esp+64h] [ebp-20h]
  btAlignedObjectArray<btTypedConstraint *> v42; // [esp+68h] [ebp-1Ch] BYREF
  btSortConstraintOnIslandPredicate CompareFunc[4]; // [esp+7Ch] [ebp-8h]
  int v44; // [esp+80h] [ebp-4h]
  int v45; // [esp+8Ch] [ebp+8h]

  m_size = this->m_constraints.m_size;
  v42.m_ownsMemory = 1;
  memset(&v42.m_size, 0, 12);
  if ( m_size >= 0 )
  {
    if ( m_size > 0 )
    {
      *(_DWORD *)CompareFunc = btAlignedAllocInternal(4 * m_size);
      v44 = v42.m_size;
      v42.m_ownsMemory = 1;
      v42.m_data = *(btTypedConstraint ***)CompareFunc;
      v42.m_capacity = m_size;
    }
    for ( i = 0; i < m_size; ++i )
    {
      v5 = &v42.m_data[i];
      if ( v5 )
        *v5 = 0;
    }
  }
  v6 = this->__vftable;
  v42.m_size = m_size;
  v7 = 0;
  if ( v6->getNumConstraints(this) > 0 )
  {
    do
    {
      v42.m_data[v7] = this->m_constraints.m_data[v7];
      ++v7;
    }
    while ( v7 < this->getNumConstraints(this) );
  }
  CompareFunc[0] = 0;
  if ( v42.m_size > 1 )
    btAlignedObjectArray<btTypedConstraint *>::quickSortInternal<btSortConstraintOnIslandPredicate>(
      &v42,
      CompareFunc[0],
      0,
      v42.m_size - 1);
  v8 = this->getNumConstraints(this);
  m_constraintSolver = this->m_constraintSolver;
  m_dispatcher1 = this->m_dispatcher1;
  v22 = v8 != 0 ? v42.m_data : 0;
  v23 = v42.m_size;
  m_debugDrawer = this->m_debugDrawer;
  m_stackAlloc = this->m_stackAlloc;
  v45 = this->m_collisionObjects.m_size;
  v11 = this->m_constraintSolver;
  v30 = 0;
  v28 = 0;
  v29 = 0;
  v35 = 0;
  v33 = 0;
  v34 = 0;
  v40 = 0;
  v38 = 0;
  v39 = 0;
  callback.__vftable = (btSimulationIslandManager::IslandCallback_vtbl *)&`btDiscreteDynamicsWorld::solveConstraints'::`2'::InplaceSolverIslandCallback::`vftable';
  v20 = solverInfo;
  v26 = m_dispatcher1;
  v31 = 1;
  v36 = 1;
  v41 = 1;
  p_prepareSolve = &v11->prepareSolve;
  v13 = m_dispatcher1->getNumManifolds(m_dispatcher1);
  (*p_prepareSolve)(this->m_constraintSolver, v45, v13);
  btSimulationIslandManager::buildAndProcessIslands(this->m_islandManager, this->m_dispatcher1, this, &callback);
  btDiscreteDynamicsWorld::solveConstraints_::_2_::InplaceSolverIslandCallback::processConstraints(v14, (int)&callback);
  this->m_constraintSolver->allSolved(this->m_constraintSolver, solverInfo, this->m_debugDrawer, this->m_stackAlloc);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v15, (int)v37);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v16, (int)v32);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v17, (int)v27);
  callback.__vftable = (btSimulationIslandManager::IslandCallback_vtbl *)&btSimulationIslandManager::IslandCallback::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v18, (int)&v42);
}
