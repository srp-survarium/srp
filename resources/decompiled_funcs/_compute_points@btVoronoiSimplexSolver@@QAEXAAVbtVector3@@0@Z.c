void __userpurge btVoronoiSimplexSolver::compute_points(
        btVoronoiSimplexSolver *this@<esi>,
        btVector3 *p2@<edi>,
        btVoronoiSimplexSolver *a3@<ecx>,
        btVector3 *p1)
{
  btVoronoiSimplexSolver::updateClosestVectorAndPoints(a3, this);
  *p1 = this->m_cachedP1;
  *p2 = this->m_cachedP2;
}
