void __thiscall btDiscreteDynamicsWorld::~btDiscreteDynamicsWorld(btDiscreteDynamicsWorld *this)
{
  btDiscreteDynamicsWorld *v1; // edi
  bool v2; // zf
  void **p_m_islandManager; // esi
  btAlignedObjectArray<GrahamVector2> *v4; // ecx
  btAlignedObjectArray<GrahamVector2> *v5; // ecx
  btDiscreteDynamicsWorld *v6; // [esp-4h] [ebp-Ch]
  btDiscreteDynamicsWorld *v7; // [esp-4h] [ebp-Ch]

  v1 = this;
  v2 = !this->m_ownsIslandManager;
  this->__vftable = (btDiscreteDynamicsWorld_vtbl *)&btDiscreteDynamicsWorld::`vftable';
  if ( !v2 )
  {
    p_m_islandManager = (void **)&this->m_islandManager;
    ((void (__thiscall *)(btSimulationIslandManager *, _DWORD))this->m_islandManager->~btSimulationIslandManager)(
      this->m_islandManager,
      0);
    btAlignedFreeInternal(*p_m_islandManager);
    this = v6;
  }
  if ( v1->m_ownsConstraintSolver )
  {
    ((void (__thiscall *)(btConstraintSolver *, _DWORD))v1->m_constraintSolver->~btConstraintSolver)(
      v1->m_constraintSolver,
      0);
    btAlignedFreeInternal(v1->m_constraintSolver);
    this = v7;
  }
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&v1->m_actions);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v4, (int)&v1->m_nonStaticRigidBodies);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v5, (int)&v1->m_constraints);
  v1->__vftable = (btDiscreteDynamicsWorld_vtbl *)&btDynamicsWorld::`vftable';
  btCollisionWorld::~btCollisionWorld(v1);
}
