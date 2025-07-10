char __usercall btVoronoiSimplexSolver::closest@<al>(
        btVoronoiSimplexSolver *this@<esi>,
        btVector3 *v@<edi>,
        btVoronoiSimplexSolver *a3@<ecx>)
{
  char result; // al

  result = btVoronoiSimplexSolver::updateClosestVectorAndPoints(a3, this);
  *v = this->m_cachedV;
  return result;
}
