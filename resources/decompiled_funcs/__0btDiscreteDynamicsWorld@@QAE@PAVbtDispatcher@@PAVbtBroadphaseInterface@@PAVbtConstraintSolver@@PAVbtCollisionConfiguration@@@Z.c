void __stdcall btDiscreteDynamicsWorld::btDiscreteDynamicsWorld(
        btDiscreteDynamicsWorld *this,
        btConstraintSolver *constraintSolver,
        btCollisionConfiguration *collisionConfiguration)
{
  btBroadphaseInterface *pairCache; // eax
  btDispatcher *dispatcher; // ecx
  btContactSolverInfo *v5; // ecx
  btSequentialImpulseConstraintSolver *v6; // ecx
  btSimulationIslandManager *v7; // eax

  btCollisionWorld::btCollisionWorld(this, dispatcher, pairCache, collisionConfiguration);
  this->m_internalTickCallback = 0;
  this->m_internalPreTickCallback = 0;
  this->m_worldUserInfo = 0;
  btContactSolverInfo::btContactSolverInfo(v5, &this->m_solverInfo);
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
  *(unsigned __int64 *)((char *)this->m_gravity.mVec128.m128_u64 + 4) = 3240099840LL;
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
    ++gNumAlignedAllocs;
    if ( sAlignedAllocFunc(0x80u, 16) )
      this->m_constraintSolver = btSequentialImpulseConstraintSolver::btSequentialImpulseConstraintSolver(v6);
    else
      this->m_constraintSolver = 0;
    this->m_ownsConstraintSolver = 1;
  }
  ++gNumAlignedAllocs;
  v7 = (btSimulationIslandManager *)sAlignedAllocFunc(0x44u, 16);
  if ( v7 )
  {
    v7->__vftable = (btSimulationIslandManager_vtbl *)&btSimulationIslandManager::`vftable';
    v7->m_unionFind.m_elements.m_data = 0;
    v7->m_unionFind.m_elements.m_size = 0;
    v7->m_unionFind.m_elements.m_capacity = 0;
    v7->m_unionFind.m_elements.m_ownsMemory = 1;
    v7->m_islandmanifold.m_data = 0;
    v7->m_islandmanifold.m_size = 0;
    v7->m_islandmanifold.m_capacity = 0;
    v7->m_islandmanifold.m_ownsMemory = 1;
    v7->m_islandBodies.m_data = 0;
    v7->m_islandBodies.m_size = 0;
    v7->m_islandBodies.m_capacity = 0;
    v7->m_islandBodies.m_ownsMemory = 1;
    v7->m_splitIslands = 1;
    this->m_islandManager = v7;
  }
  else
  {
    this->m_islandManager = 0;
  }
  this->m_ownsIslandManager = 1;
}
