bool __fastcall btDiscreteDynamicsWorld::solveConstraints_::_2_::InplaceSolverIslandCallback::btManifoldIndexSortPredicate::operator()(
        btPersistentManifold *rhs,
        btPersistentManifold *lhs,
        btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback::btManifoldIndexSortPredicate *this)
{
  int m_cachedPoints; // eax

  m_cachedPoints = lhs->m_cachedPoints;
  if ( m_cachedPoints && rhs->m_cachedPoints )
    return rhs->m_pointCache[0].m_distance1 > lhs->m_pointCache[0].m_distance1;
  else
    return m_cachedPoints < rhs->m_cachedPoints;
}
