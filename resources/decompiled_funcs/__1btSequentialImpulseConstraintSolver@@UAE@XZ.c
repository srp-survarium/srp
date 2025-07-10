void __thiscall btSequentialImpulseConstraintSolver::~btSequentialImpulseConstraintSolver(
        btSequentialImpulseConstraintSolver *this)
{
  btTypedConstraint::btConstraintInfo1 *m_data; // eax
  int *v3; // eax
  int *v4; // eax
  btSolverConstraint *v5; // eax
  btSolverConstraint *v6; // eax
  btSolverConstraint *v7; // eax

  this->__vftable = (btSequentialImpulseConstraintSolver_vtbl *)&btSequentialImpulseConstraintSolver::`vftable';
  m_data = this->m_tmpConstraintSizesPool.m_data;
  if ( m_data )
  {
    if ( this->m_tmpConstraintSizesPool.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_tmpConstraintSizesPool.m_data = 0;
  }
  this->m_tmpConstraintSizesPool.m_ownsMemory = 1;
  this->m_tmpConstraintSizesPool.m_data = 0;
  this->m_tmpConstraintSizesPool.m_size = 0;
  this->m_tmpConstraintSizesPool.m_capacity = 0;
  v3 = this->m_orderFrictionConstraintPool.m_data;
  if ( v3 )
  {
    if ( this->m_orderFrictionConstraintPool.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    this->m_orderFrictionConstraintPool.m_data = 0;
  }
  this->m_orderFrictionConstraintPool.m_ownsMemory = 1;
  this->m_orderFrictionConstraintPool.m_data = 0;
  this->m_orderFrictionConstraintPool.m_size = 0;
  this->m_orderFrictionConstraintPool.m_capacity = 0;
  v4 = this->m_orderTmpConstraintPool.m_data;
  if ( v4 )
  {
    if ( this->m_orderTmpConstraintPool.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v4);
    }
    this->m_orderTmpConstraintPool.m_data = 0;
  }
  this->m_orderTmpConstraintPool.m_ownsMemory = 1;
  this->m_orderTmpConstraintPool.m_data = 0;
  this->m_orderTmpConstraintPool.m_size = 0;
  this->m_orderTmpConstraintPool.m_capacity = 0;
  v5 = this->m_tmpSolverContactFrictionConstraintPool.m_data;
  if ( v5 )
  {
    if ( this->m_tmpSolverContactFrictionConstraintPool.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v5);
    }
    this->m_tmpSolverContactFrictionConstraintPool.m_data = 0;
  }
  this->m_tmpSolverContactFrictionConstraintPool.m_ownsMemory = 1;
  this->m_tmpSolverContactFrictionConstraintPool.m_data = 0;
  this->m_tmpSolverContactFrictionConstraintPool.m_size = 0;
  this->m_tmpSolverContactFrictionConstraintPool.m_capacity = 0;
  v6 = this->m_tmpSolverNonContactConstraintPool.m_data;
  if ( v6 )
  {
    if ( this->m_tmpSolverNonContactConstraintPool.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v6);
    }
    this->m_tmpSolverNonContactConstraintPool.m_data = 0;
  }
  this->m_tmpSolverNonContactConstraintPool.m_ownsMemory = 1;
  this->m_tmpSolverNonContactConstraintPool.m_data = 0;
  this->m_tmpSolverNonContactConstraintPool.m_size = 0;
  this->m_tmpSolverNonContactConstraintPool.m_capacity = 0;
  v7 = this->m_tmpSolverContactConstraintPool.m_data;
  if ( v7 )
  {
    if ( this->m_tmpSolverContactConstraintPool.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v7);
    }
    this->m_tmpSolverContactConstraintPool.m_data = 0;
  }
  this->m_tmpSolverContactConstraintPool.m_data = 0;
  this->m_tmpSolverContactConstraintPool.m_size = 0;
  this->m_tmpSolverContactConstraintPool.m_capacity = 0;
  this->m_tmpSolverContactConstraintPool.m_ownsMemory = 1;
  this->__vftable = (btSequentialImpulseConstraintSolver_vtbl *)&btConstraintSolver::`vftable';
}
