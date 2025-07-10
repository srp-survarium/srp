void __thiscall btDiscreteDynamicsWorld::~btDiscreteDynamicsWorld(btDiscreteDynamicsWorld *this)
{
  btSimulationIslandManager *m_islandManager; // eax
  btConstraintSolver *m_constraintSolver; // eax
  btActionInterface **m_data; // eax
  btRigidBody **v5; // eax
  btTypedConstraint **v6; // eax

  this->__vftable = (btDiscreteDynamicsWorld_vtbl *)&btDiscreteDynamicsWorld::`vftable';
  if ( this->m_ownsIslandManager )
  {
    ((void (__thiscall *)(btSimulationIslandManager *, _DWORD))this->m_islandManager->~btSimulationIslandManager)(
      this->m_islandManager,
      0);
    m_islandManager = this->m_islandManager;
    if ( m_islandManager )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_islandManager);
    }
  }
  if ( this->m_ownsConstraintSolver )
  {
    ((void (__thiscall *)(btConstraintSolver *, _DWORD))this->m_constraintSolver->~btConstraintSolver)(
      this->m_constraintSolver,
      0);
    m_constraintSolver = this->m_constraintSolver;
    if ( m_constraintSolver )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_constraintSolver);
    }
  }
  m_data = this->m_actions.m_data;
  if ( m_data )
  {
    if ( this->m_actions.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_actions.m_data = 0;
  }
  this->m_actions.m_ownsMemory = 1;
  this->m_actions.m_data = 0;
  this->m_actions.m_size = 0;
  this->m_actions.m_capacity = 0;
  v5 = this->m_nonStaticRigidBodies.m_data;
  if ( v5 )
  {
    if ( this->m_nonStaticRigidBodies.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v5);
    }
    this->m_nonStaticRigidBodies.m_data = 0;
  }
  this->m_nonStaticRigidBodies.m_ownsMemory = 1;
  this->m_nonStaticRigidBodies.m_data = 0;
  this->m_nonStaticRigidBodies.m_size = 0;
  this->m_nonStaticRigidBodies.m_capacity = 0;
  v6 = this->m_constraints.m_data;
  if ( v6 )
  {
    if ( this->m_constraints.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v6);
    }
    this->m_constraints.m_data = 0;
  }
  this->m_constraints.m_data = 0;
  this->m_constraints.m_size = 0;
  this->m_constraints.m_capacity = 0;
  this->m_constraints.m_ownsMemory = 1;
  this->__vftable = (btDiscreteDynamicsWorld_vtbl *)&btDynamicsWorld::`vftable';
  btCollisionWorld::~btCollisionWorld(this);
}
