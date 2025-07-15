void __thiscall btVoronoiSimplexSolver::compute_points(
        btVoronoiSimplexSolver *this,
        btVoronoiSimplexSolver *p1,
        btVector3 *p2,
        btVector3 *a4)
{
  btVoronoiSimplexSolver::updateClosestVectorAndPoints(this, p1);
  *p2 = p1->m_cachedP1;
  *a4 = p1->m_cachedP2;
}
