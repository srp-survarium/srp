btCollisionAlgorithm *__thiscall btConvexConvexAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btConvexConvexAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btCollisionAlgorithm *result; // eax
  btCollisionAlgorithm_vtbl *m_minimumPointsPerturbationThreshold; // ecx
  btDispatcher *m_numPerturbationIterations; // edx
  btDispatcher *m_manifold; // ebx
  btDispatcher *m_pdSolver; // ebp
  btCollisionAlgorithm_vtbl *m_simplexSolver; // esi
  btDispatcher *m_dispatcher1; // edi

  result = (btCollisionAlgorithm *)ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 36);
  if ( !result )
    return 0;
  m_minimumPointsPerturbationThreshold = (btCollisionAlgorithm_vtbl *)this->m_minimumPointsPerturbationThreshold;
  m_numPerturbationIterations = (btDispatcher *)this->m_numPerturbationIterations;
  m_manifold = (btDispatcher *)ci->m_manifold;
  m_pdSolver = (btDispatcher *)this->m_pdSolver;
  m_simplexSolver = (btCollisionAlgorithm_vtbl *)this->m_simplexSolver;
  result->__vftable = (btCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  m_dispatcher1 = ci->m_dispatcher1;
  result[1].m_dispatcher = m_pdSolver;
  result[2].m_dispatcher = m_manifold;
  result->m_dispatcher = m_dispatcher1;
  result[1].__vftable = m_simplexSolver;
  result->__vftable = (btCollisionAlgorithm_vtbl *)&btConvexConvexAlgorithm::`vftable';
  LOBYTE(result[2].__vftable) = 0;
  LOBYTE(result[3].__vftable) = 0;
  result[3].m_dispatcher = m_numPerturbationIterations;
  result[4].__vftable = m_minimumPointsPerturbationThreshold;
  return result;
}
