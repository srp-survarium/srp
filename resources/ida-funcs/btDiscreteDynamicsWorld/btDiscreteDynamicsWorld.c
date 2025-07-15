void __stdcall btDiscreteDynamicsWorld::btDiscreteDynamicsWorld(
        btDiscreteDynamicsWorld *this,
        btBroadphaseInterface *pairCache,
        btConstraintSolver *constraintSolver)
{
  btDispatcher *v3; // eax
  btCollisionConfiguration *v4; // ecx
  btSequentialImpulseConstraintSolver *v5; // eax
  btSequentialImpulseConstraintSolver *v6; // eax
  btSimulationIslandManager *v7; // eax
  btSequentialImpulseConstraintSolver *v8; // [esp-4h] [ebp-Ch]

  btDynamicsWorld::btDynamicsWorld(this, v3, v4, pairCache);
  this->m_constraintSolver = constraintSolver;
  this->__vftable = (btDiscreteDynamicsWorld_vtbl *)&btDiscreteDynamicsWorld::`vftable';
  this->m_constraints.m_ownsMemory = 1;
  this->m_constraints.m_data = 0;
  this->m_constraints.m_size = 0;
  this->m_constraints.m_capacity = 0;
  this->m_nonStaticRigidBodies.m_ownsMemory = 1;
  this->m_nonStaticRigidBodies.m_data = 0;
  this->m_nonStaticRigidBodies.m_size = 0;
  this->m_nonStaticRigidBodies.m_capacity = 0;
  this->m_gravity.mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)this->m_gravity.mVec128.m128_u64 + 4) = LODWORD(FLOAT_N10_0);
  this->m_gravity.mVec128.m128_i32[3] = 0;
  this->m_localTime = 0.0;
  this->m_synchronizeAllMotionStates = 0;
  this->m_actions.m_ownsMemory = 1;
  this->m_actions.m_data = 0;
  this->m_actions.m_size = 0;
  this->m_actions.m_capacity = 0;
  this->m_profileTimings = 0;
  if ( this->m_constraintSolver )
  {
    this->m_ownsConstraintSolver = 0;
  }
  else
  {
    v5 = (btSequentialImpulseConstraintSolver *)btAlignedAllocInternal(0x80u);
    if ( v5 )
      v6 = btSequentialImpulseConstraintSolver::btSequentialImpulseConstraintSolver(v8, v5);
    else
      v6 = 0;
    this->m_constraintSolver = v6;
    this->m_ownsConstraintSolver = 1;
  }
  v7 = (btSimulationIslandManager *)btAlignedAllocInternal(0x44u);
  if ( v7 )
  {
    v7->__vftable = (btSimulationIslandManager_vtbl *)&btSimulationIslandManager::`vftable';
    v7->m_unionFind.m_elements.m_ownsMemory = 1;
    v7->m_unionFind.m_elements.m_data = 0;
    v7->m_unionFind.m_elements.m_size = 0;
    v7->m_unionFind.m_elements.m_capacity = 0;
    v7->m_islandmanifold.m_ownsMemory = 1;
    v7->m_islandmanifold.m_data = 0;
    v7->m_islandmanifold.m_size = 0;
    v7->m_islandmanifold.m_capacity = 0;
    v7->m_islandBodies.m_ownsMemory = 1;
    v7->m_islandBodies.m_data = 0;
    v7->m_islandBodies.m_size = 0;
    v7->m_islandBodies.m_capacity = 0;
    v7->m_splitIslands = 1;
  }
  else
  {
    v7 = 0;
  }
  this->m_islandManager = v7;
  this->m_ownsIslandManager = 1;
}
