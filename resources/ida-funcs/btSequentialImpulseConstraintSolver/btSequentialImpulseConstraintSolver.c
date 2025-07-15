btSequentialImpulseConstraintSolver *__usercall btSequentialImpulseConstraintSolver::btSequentialImpulseConstraintSolver@<eax>(
        btSequentialImpulseConstraintSolver *this@<ecx>,
        btSequentialImpulseConstraintSolver *result@<eax>)
{
  result->__vftable = (btSequentialImpulseConstraintSolver_vtbl *)&btSequentialImpulseConstraintSolver::`vftable';
  result->m_tmpSolverContactConstraintPool.m_ownsMemory = 1;
  result->m_tmpSolverContactConstraintPool.m_data = 0;
  result->m_tmpSolverContactConstraintPool.m_size = 0;
  result->m_tmpSolverContactConstraintPool.m_capacity = 0;
  result->m_tmpSolverNonContactConstraintPool.m_ownsMemory = 1;
  result->m_tmpSolverNonContactConstraintPool.m_data = 0;
  result->m_tmpSolverNonContactConstraintPool.m_size = 0;
  result->m_tmpSolverNonContactConstraintPool.m_capacity = 0;
  result->m_tmpSolverContactFrictionConstraintPool.m_ownsMemory = 1;
  result->m_tmpSolverContactFrictionConstraintPool.m_data = 0;
  result->m_tmpSolverContactFrictionConstraintPool.m_size = 0;
  result->m_tmpSolverContactFrictionConstraintPool.m_capacity = 0;
  result->m_orderTmpConstraintPool.m_ownsMemory = 1;
  result->m_orderTmpConstraintPool.m_data = 0;
  result->m_orderTmpConstraintPool.m_size = 0;
  result->m_orderTmpConstraintPool.m_capacity = 0;
  result->m_orderFrictionConstraintPool.m_ownsMemory = 1;
  result->m_orderFrictionConstraintPool.m_data = 0;
  result->m_orderFrictionConstraintPool.m_size = 0;
  result->m_orderFrictionConstraintPool.m_capacity = 0;
  result->m_tmpConstraintSizesPool.m_ownsMemory = 1;
  result->m_tmpConstraintSizesPool.m_data = 0;
  result->m_tmpConstraintSizesPool.m_size = 0;
  result->m_tmpConstraintSizesPool.m_capacity = 0;
  result->m_btSeed2 = 0;
  return result;
}
