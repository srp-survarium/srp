void __usercall btVoronoiSimplexSolver::reduceVertices(
        btVoronoiSimplexSolver *this@<eax>,
        const btUsageBitfield *usedVerts@<esi>)
{
  int v2; // ecx

  if ( this->m_numVertices >= 4 && (*(_BYTE *)usedVerts & 8) == 0 )
    btVoronoiSimplexSolver::removeVertex((btVoronoiSimplexSolver *)3, this);
  v2 = 2;
  if ( this->m_numVertices >= 3 && (*(_BYTE *)usedVerts & 4) == 0 )
    btVoronoiSimplexSolver::removeVertex((btVoronoiSimplexSolver *)2, this);
  if ( this->m_numVertices >= v2 && ((unsigned __int8)v2 & *(_BYTE *)usedVerts) == 0 )
    btVoronoiSimplexSolver::removeVertex((btVoronoiSimplexSolver *)1, this);
  if ( this->m_numVertices >= 1 && (*(_BYTE *)usedVerts & 1) == 0 )
    btVoronoiSimplexSolver::removeVertex(0, this);
}
