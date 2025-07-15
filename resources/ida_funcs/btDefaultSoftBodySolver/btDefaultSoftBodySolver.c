btDefaultSoftBodySolver *__usercall btDefaultSoftBodySolver::btDefaultSoftBodySolver@<eax>(
        btDefaultSoftBodySolver *this@<ecx>,
        btDefaultSoftBodySolver *result@<eax>)
{
  LODWORD(result->m_timeScale) = clear_value;
  result->m_numberOfVelocityIterations = 0;
  result->m_numberOfPositionIterations = 5;
  result->__vftable = (btDefaultSoftBodySolver_vtbl *)&btDefaultSoftBodySolver::`vftable';
  result->m_softBodySet.m_ownsMemory = 1;
  result->m_softBodySet.m_data = 0;
  result->m_softBodySet.m_size = 0;
  result->m_softBodySet.m_capacity = 0;
  result->m_updateSolverConstants = 1;
  return result;
}
